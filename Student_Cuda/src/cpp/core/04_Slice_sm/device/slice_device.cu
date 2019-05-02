
#include "Indice2D.h"
#include "Indice1D.h"
#include "cudaTools.h"
#include "ReductionAddTools.h"
#include <stdio.h>

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Imported	 	*|
 \*-------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

__global__ void kernelSliceSM(float* ptrDevResultat, int nbSlice);
__device__ void reductionIntraThreadSM(float* tabSM, int nbSlice);

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

static __device__ float f(float x);

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

__global__ void kernelSliceSM(float* ptrDevResultat, int nbSlice)
    {
    extern __shared__ float tabSM[];
    reductionIntraThreadSM(tabSM, nbSlice);
    __syncthreads();
    ReductionAddTools::reductionADD(tabSM, ptrDevResultat);
    }
/**
 * Chaque thread effecteur une reduction avec le patern d'entrelacement,
 * puis stocke son résultat dans SA case dans tabGM
 * tabGM est un tableau promu, qui a autant de case que de thread
 */

__device__ void reductionIntraThreadSM(float* tabSM, int nbSlice)
    {
    const int TID = threadIdx.x + (blockIdx.x * blockDim.x); //global à la grille
    const int TID_LOCAL = threadIdx.x;
    const int NB_THREAD = blockDim.x * gridDim.x; //nbThreadTotal

    const float dx = 1 / (float) nbSlice;
    int s = TID;
    float sum = 0;
    while (s < nbSlice)
	{
	float xs = s * dx;
	sum += f(xs);
	s += NB_THREAD;
	}
    tabSM[TID_LOCAL] = sum;
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

__device__ float f(float x)
    {
    return 4 / (1 + x * x);
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
