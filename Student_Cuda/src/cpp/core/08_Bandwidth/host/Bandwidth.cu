
#include "Bandwidth.h"

#include <iostream>
#include <assert.h>

#include "Device.h"
#include "Chrono.h"


using std::cout;
using std::endl;

 /*---------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Imported	 	*|
 \*-------------------------------------*/

extern __global__ void kernelBandwidth(int* tabDataGM, int* tabFrequenceGM, int n, int dataMax);

 /*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

 /*-------------------------------------*\
 |*		Constructeur		*|
 \*-------------------------------------*/

Bandwidth::Bandwidth(const Grid& grid, int* tabData, int n) : n(n)
    {

    this->dg = grid.dg;
    this->db = grid.db;

    this->sizeTabDataGM = sizeof(int) * n; // [octet]

    Device::malloc(&tabDataGM, sizeTabDataGM);

    Chrono chrono;
    Device::memcpyHToD(tabDataGM, tabData, sizeTabDataGM);
    chrono.stop();
    elapsedTime = chrono.getElapseTimeS();
    cout << "Elapsed time : " << elapsedTime << " (s)" << endl;

    }

Bandwidth::~Bandwidth(void)
    {
    Device::free (tabDataGM);
    }

double Bandwidth::getElapsedTime()
    {
    return elapsedTime;
    }

 /*-------------------------------------*\
 |*		Methode			*|
 \*-------------------------------------*/

void Bandwidth::run()
    {
    //kernelHistogramme<<<dg,db>>>(tabDataGM);
    //Device::memcpyDToH(tabData, tabDataGM);
    }

 /*---------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
