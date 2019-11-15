#include "Indice2D.h"
#include "Indice1D.h"
#include "cudaTools.h"
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

__global__ void kernelHistogramme(int *tabDataGM, int *tabFrequenceGM, int n, int dataMax);
__device__ void clearTabSM(int *tabSM, int dataMax);
__device__ void reductionIntraThreadSM(int *tabSM, int *tabDataGM, int n);
__device__ void reductionInterBlock(int *tabSM, int *tabFrequenceGM, int dataMax);

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

__global__ void kernelHistogramme(int *tabDataGM, int *tabFrequenceGM, int n, int dataMax)
    {
    extern __shared__ int tabSM[];
    clearTabSM(tabSM, dataMax);
    __syncthreads();
    reductionIntraThreadSM(tabSM, tabDataGM, n);
    __syncthreads();
    reductionInterBlock(tabSM, tabFrequenceGM, dataMax);
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/
__device__ void clearTabSM(int *tabSM, int dataMax)
    {
    const int TID_LOCAL = threadIdx.x;
    const int NB_THREAD = blockDim.x;

    int s = TID_LOCAL;
    while (s < dataMax + 1)
	{
	tabSM[s] = 0;
	s += NB_THREAD;
	}
    }

__device__ void reductionIntraThreadSM(int *tabSM, int *tabDataGM, int n)
    {
    const int TID = threadIdx.x + (blockIdx.x * blockDim.x); //global à la grille
    const int NB_THREAD = blockDim.x * gridDim.x; //nbThreadTotal

    int s = TID;
    while (s < n)
	{
	atomicAdd(&tabSM[tabDataGM[s]], 1);
	s += NB_THREAD;
	}
    }

__device__ void reductionInterBlock(int *tabSM, int *tabFrequenceGM, int dataMax)
    {

    const int TID_LOCAL = threadIdx.x;
    const int NB_THREAD = blockDim.x; //nbThreadTotal

    int s = TID_LOCAL;
    while (s < dataMax + 1)
	{
	atomicAdd(&tabFrequenceGM[s], tabSM[s]);
	s += NB_THREAD;
	}

    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
