#include "Indice1D.h"
#include "cudaTools.h"
#include <stdio.h>
#include <curand_kernel.h>
#include <limits.h>
#include "ReductionAddToolsLock.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

extern __global__ void createGeneratorLong(curandState* tabDevGeneratorGM, int deviceId);
__global__ void monteCarloLong(curandState* tabDevGeneratorGM, long nbFleche, long* ptrDevResultat);

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

__device__ void intraThread(curandState* tabDevGeneratorGM, long nbFleche, long* tabSM);
extern __device__ float fLong(float x);

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/



__global__ void monteCarloLong(curandState* tabDevGeneratorGM, long nbFleche, long* ptrDevResultat)
    {
    extern __shared__ long tabSM[];
    intraThread(tabDevGeneratorGM, nbFleche, tabSM);
    __syncthreads();
    ReductionAddToolsLock::reductionADD(tabSM, ptrDevResultat);
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/
__device__ void intraThread(curandState* tabDevGeneratorGM, long nbFleche, long* tabSM)
    {
    const int TID = Indice1D::tid();
    curandState localGenerator = tabDevGeneratorGM[TID];
    float xAlea;
    float yAlea;
    long nbFlecheIn = 0;
    for (long i = 0; i < nbFleche; ++i)
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
	    nbFlecheIn += yAlea < fLong(xAlea);
	    }
	}
    tabSM[Indice1D::tidLocal()] = nbFlecheIn;
    tabDevGeneratorGM[TID] = localGenerator;
    }

__device__ float fLong(float x)
    {
    return 4 / (1 + x * x);
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

