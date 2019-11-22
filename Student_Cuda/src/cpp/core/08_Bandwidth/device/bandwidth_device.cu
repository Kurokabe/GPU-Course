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

__global__ void kernelBandwidthEntrelacement(int *tabDataGM,int*tabDataGMCopy, int n );
__global__ void kernelBandwidthOneOne(int *tabDataGM,int*tabDataGMCopy, int n );

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

__global__ void kernelBandwidthEntrelacement(int *tabDataGM,int*tabDataGMCopy, int n )
    {
    const int NB_THREAD = Indice2D::nbThread();
        const int TID = Indice2D::tid();

        int s = TID;
        while (s < n)
    	{
    	tabDataGMCopy[s]=tabDataGM[s];
    	s += NB_THREAD;
    	}
    }

__global__ void kernelBandwidthOneOne(int *tabDataGM,int*tabDataGMCopy, int n )
    {
        const int TID = Indice2D::tid();


    	tabDataGMCopy[TID]=tabDataGM[TID];


    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
