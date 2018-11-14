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

__global__ void addVector(float* ptrDevV1, float* ptrDevV2, float* ptrDevW, int n);
__global__ void addVector11(float* ptrDevV1, float* ptrDevV2, float* ptrDevW, int n);

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

/**
 * output : void required !!
 * pattern entrelacement
 */
__global__ void addVector(float* ptrDevV1, float* ptrDevV2, float* ptrDevW, int n)
    {
    const int NB_THREAD = Indice2D::nbThread();
    const int TID = Indice2D::tid();

    // Debug, facultatif
//    if (TID == 0)
//	{
//	printf("Coucou from device tid = %d", TID); //required   Device::synchronize(); after the call of kernel
//	}

    //TODO addVector pattern entrelacement
    }

/**
 * pattern 1<-->1
 * hyp: #thread=#caseVecteur=n
 */
__global__ void addVector11(float* ptrDevV1, float* ptrDevV2, float* ptrDevW, int n)
    {
    // TODO addVector pattern  1<-->1
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

