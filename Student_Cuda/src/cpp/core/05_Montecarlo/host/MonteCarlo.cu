#include "MonteCarlo.h"

#include <iostream>
#include <assert.h>
#include "Device.h"

using std::cout;
using std::endl;

/*----------------------------------------------------------------------*\
|*			Declaration 					*|
\*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Imported	 	*|
 \*-------------------------------------*/

extern __global__ void createGenerator(curandState* tabDevGeneratorGM, int deviceId);
extern __global__ void monteCarlo(curandState* tabDevGeneratorGM, int nbFleche, int* ptrDevResultat);

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Constructeur		*|
 \*-------------------------------------*/

MonteCarlo::MonteCarlo(const Grid& grid, int nbFlechette, float* ptrPiHat) : ptrPiHat(ptrPiHat), nbFlechette(nbFlechette)
    {
    this->ptrResultat = new int[sizeof(int)];
    this->sizeResGM = sizeof(int);
    this->sizeTabGenerator = grid.threadCounts()*sizeof(curandState);

    this->nbFlechetteThread = nbFlechette/grid.threadCounts();
    this->nbFlechette = nbFlechetteThread*grid.threadCounts();
    Device::malloc(&ptrDevResultat, sizeResGM);
    Device::memclear(ptrDevResultat, sizeResGM);
    Device::malloc(&ptrDevtabGenerator, sizeTabGenerator);
    Device::memclear(ptrDevtabGenerator, sizeTabGenerator);

    this->dg = grid.dg;
    this->db = grid.db;
    }

MonteCarlo::~MonteCarlo(void)
    {
    Device::free(ptrDevResultat);
    Device::free(ptrDevtabGenerator);
    }


/*--------------------------------------*\
 |*		Methode			*|
 \*-------------------------------------*/

void MonteCarlo::run()
    {
    createGenerator<<<dg, db>>>(ptrDevtabGenerator, 0);
    monteCarlo<<<dg, db, sizeof(int)*db.x>>>(ptrDevtabGenerator, nbFlechetteThread, ptrDevResultat);
    Device::memcpyDToH(ptrResultat, ptrDevResultat, sizeof(int));
    *ptrPiHat = 4* *ptrResultat / (double)nbFlechette; //Utilisation de m à 4 semble plus précis.
    }

int MonteCarlo::getFlecheSousCourbe()
    {
    return *ptrResultat;
    }

int MonteCarlo::getFlecheTiree()
    {
    return nbFlechette;
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

