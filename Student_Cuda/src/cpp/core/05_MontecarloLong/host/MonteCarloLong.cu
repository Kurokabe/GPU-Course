#include <iostream>
#include <assert.h>
#include "Device.h"
#include "MonteCarloLong.h"

using std::cout;
using std::endl;

/*----------------------------------------------------------------------*\
|*			Declaration 					*|
\*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Imported	 	*|
 \*-------------------------------------*/

extern __global__ void createGenerator(curandState* tabDevGeneratorGM, int deviceId);
extern __global__ void monteCarloLong(curandState* tabDevGeneratorGM, long nbFleche, long* ptrDevResultat);

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Constructeur		*|
 \*-------------------------------------*/

MonteCarloLong::MonteCarloLong(const Grid& grid, long nbFlechette, float* ptrPiHat) : ptrPiHat(ptrPiHat), nbFlechette(nbFlechette)
    {
    this->ptrResultat = new long[sizeof(long)];
    this->sizeResGM = sizeof(long);
    this->sizeTabGenerator = grid.threadCounts()*sizeof(curandState);

    this->nbFlechetteThread = nbFlechette/(long)grid.threadCounts();
    this->nbFlechette = nbFlechetteThread*(long)grid.threadCounts();
    Device::malloc(&ptrDevResultat, sizeResGM);
    Device::memclear(ptrDevResultat, sizeResGM);
    Device::malloc(&ptrDevtabGenerator, sizeTabGenerator);
    Device::memclear(ptrDevtabGenerator, sizeTabGenerator);

    this->dg = grid.dg;
    this->db = grid.db;
    }

MonteCarloLong::~MonteCarloLong(void)
    {
    Device::free(ptrDevResultat);
    Device::free(ptrDevtabGenerator);
    }


/*--------------------------------------*\
 |*		Methode			*|
 \*-------------------------------------*/

void MonteCarloLong::run()
    {
    createGenerator<<<dg, db>>>(ptrDevtabGenerator, 0);
    monteCarloLong<<<dg, db, sizeof(long)*db.x>>>(ptrDevtabGenerator, nbFlechetteThread, ptrDevResultat);
    Device::memcpyDToH(ptrResultat, ptrDevResultat, sizeof(long));
    *ptrPiHat = 4* *ptrResultat / (double)nbFlechette; //Utilisation de m à 4 semble plus précis.
    }

long MonteCarloLong::getFlecheSousCourbe()
    {
    return *ptrResultat;
    }

long MonteCarloLong::getFlecheTiree()
    {
    return nbFlechette;
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

