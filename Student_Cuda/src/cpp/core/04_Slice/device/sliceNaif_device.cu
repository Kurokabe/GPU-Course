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

__global__ void reductionIntraThread(float* tabGM, int nbSlice);
__global__ void ecrasementGM(float* tabGM, int moitier);

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

/**
 * Chaque thread effecteur une reduction avec le patern d'entrelacement,
 * puis stocke son résultat dans SA case dans tabGM
 * tabGM est un tableau promu, qui a autant de case que de thread
 */
__global__ void reductionIntraThread(float* tabGM, int nbSlice)
    {
    const int TID=threadIdx.x+(blockIdx.x*blockDim.x) ; //global à la grille
    const int NB_THREAD= blockDim.x*gridDim.x; //nbThreadTotal

    const float DX = 1/(float)nbSlice;
    int s=TID;
    float sum = 0;
    while(s<nbSlice)
	{
	float xs = s*DX;
	sum+=f(xs);
	s+=NB_THREAD;
	}
    tabGM[TID]=sum;
    }

/**
 * Pour version NaivePLus
 *
 * Ramene la semantique du tableau pour une reduction, dans la premiere moitier, par ecraseemt
 * Doit etre appeler plusieurs fois coter host, pour tout ramener dans tabGM[0]
 */
__global__ void ecrasementGM(float* tabGM, int moitier)
    {
    const int TID=threadIdx.x+(blockIdx.x*blockDim.x);
    tabGM[TID] += tabGM[TID + moitier];
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

__device__ float f(float x)
    {
    return 4/(1+x*x);
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

