
#include "SliceSM.h"

#include <iostream>
#include <assert.h>

#include "Device.h"


 /*---------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Imported	 	*|
 \*-------------------------------------*/

extern __global__ void kernelSliceSM(float* ptrDevResultat,int nbSlice);

 /*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

 /*-------------------------------------*\
 |*		Constructeur		*|
 \*-------------------------------------*/

SliceSM::SliceSM(const Grid& grid, int nbSlice, float* ptrPiHat) : ptrPiHat(ptrPiHat), nbSlice(nbSlice)
    {
    this->sizeTabGM = sizeof(float); // [octet]

    Device::malloc(&ptrDevResultat, sizeTabGM);
    Device::memclear(ptrDevResultat, sizeTabGM);

    this->dg = grid.dg;
    this->db = grid.db;

    }

SliceSM::~SliceSM(void)
    {
    Device::free (ptrDevResultat);
    }

 /*-------------------------------------*\
 |*		Methode			*|
 \*-------------------------------------*/

void SliceSM::run()
    {
    kernelSliceSM<<<dg,db,sizeof(float)*db.x>>>(ptrDevResultat,nbSlice);
    Device::memcpyDToH(ptrPiHat, ptrDevResultat, sizeof(float));
    }

 /*---------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/