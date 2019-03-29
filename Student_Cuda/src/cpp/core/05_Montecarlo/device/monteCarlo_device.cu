#include "Indice1D.h"
#include "cudaTools.h"
#include <stdio.h>
#include <curand_kernel.h>
#include <limits.h>
#include "ReductionAddTools.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

__global__ void createGenerator(curandState* tabDevGeneratorGM, int deviceId);
__global__ void monteCarlo(curandState* tabDevGeneratorGM, int nbFleche, int* ptrDevResultat);

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

__device__ void intraThread(curandState* tabDevGeneratorGM, int nbFleche, int* tabSM);
__device__ float f(float x);

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

__global__ void createGenerator(curandState* tabDevGeneratorGM, int deviceId)
    {
    const int TID = Indice1D::tid();
    int deltaSeed = deviceId * INT_MAX / 10000;
    int deltaSequence = deviceId * 100;
    int deltaOffset = deviceId * 100;
    int seed = 1234 + deltaSeed;
    int sequenceNumber = TID + deltaSequence;
    int offset = deltaOffset;

    curand_init(seed, sequenceNumber, offset, &tabDevGeneratorGM[TID]);
    }

__global__ void monteCarlo(curandState* tabDevGeneratorGM, int nbFleche, int* ptrDevResultat)
    {
    extern __shared__ int tabSM[];
    intraThread(tabDevGeneratorGM, nbFleche, tabSM);
    __syncthreads();
    ReductionAddTools::reductionADD(tabSM, ptrDevResultat);
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/
__device__ void intraThread(curandState* tabDevGeneratorGM, int nbFleche, int* tabSM)
    {
    const int TID = Indice1D::tid();
    curandState localGenerator = tabDevGeneratorGM[TID];
    float xAlea;
    float yAlea;
    int nbFlecheIn = 0;
    for (int i = 0; i < nbFleche; ++i)
	{
	xAlea = curand_uniform(&localGenerator);
	yAlea = 4 * curand_uniform(&localGenerator);

//	    { //Variante 1
//	    if (yAlea < f(xAlea))
//		{
//		nbFlecheIn++;
//		}
//	    }

	    { //Variante 2
	    nbFlecheIn += yAlea < f(xAlea);
	    }
	}
    tabSM[Indice1D::tidLocal()] = nbFlecheIn;
    tabDevGeneratorGM[TID] = localGenerator;
    }

__device__ float f(float x)
    {
    return 4 / (1 + x * x);
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

