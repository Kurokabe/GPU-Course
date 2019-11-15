
#include "Histogramme.h"

#include <iostream>
#include <assert.h>

#include "Device.h"


 /*---------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Imported	 	*|
 \*-------------------------------------*/

extern __global__ void kernelHistogramme(int* tabDataGM, int* tabFrequenceGM, int n, int dataMax);

 /*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

 /*-------------------------------------*\
 |*		Constructeur		*|
 \*-------------------------------------*/

Histogramme::Histogramme(const Grid& grid, int n, int* tabData, int* tabFrequence, int dataMax) : tabFrequence(tabFrequence), n(n), dataMax(dataMax)
    {
    this->sizeTabDataGM = sizeof(int) * n; // [octet]
    this->sizeTabFrequenceGM = sizeof(int) * (dataMax + 1); // [octet]

    Device::malloc(&tabDataGM, sizeTabDataGM);
    Device::memcpyHToD(tabDataGM, tabData, sizeTabDataGM);

    Device::malloc(&tabFrequenceGM, sizeTabFrequenceGM);
    Device::memclear(tabFrequenceGM, sizeTabFrequenceGM);

    this->dg = grid.dg;
    this->db = grid.db;

    }

Histogramme::~Histogramme(void)
    {
    Device::free (tabDataGM);
    Device::free (tabFrequenceGM);
    }

 /*-------------------------------------*\
 |*		Methode			*|
 \*-------------------------------------*/

void Histogramme::run()
    {
    kernelHistogramme<<<dg,db, this->sizeTabFrequenceGM>>>(tabDataGM, tabFrequenceGM, n, dataMax);
    Device::memcpyDToH(tabFrequence, tabFrequenceGM, sizeof(int) * 256);
    }

 /*---------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
