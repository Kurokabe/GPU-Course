#include <iostream>
#include <assert.h>
#include "Device.h"
#include "MonteCarloMultiGPU.h"
#include "MonteCarlo.h"

using std::cout;
using std::endl;

/*----------------------------------------------------------------------*\
|*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Imported	 	*|
 \*-------------------------------------*/

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Constructeur		*|
 \*-------------------------------------*/

MonteCarloMultiGPU::MonteCarloMultiGPU(const Grid& grid, int nbFlechette, float* ptrPiHat) :
	ptrPiHat(ptrPiHat), nbFlechette(nbFlechette), grid(grid)
    {
    }

MonteCarloMultiGPU::~MonteCarloMultiGPU(void)
    {

    }

/*--------------------------------------*\
 |*		Methode			*|
 \*-------------------------------------*/

void MonteCarloMultiGPU::run()
    {
    int nGPU = Device::getDeviceCount();
    long sum = 0;
    int nbFlechetteReel = 0;
    int nbFlechetteGPU = nbFlechette / nGPU; //Perte des virgules

//#pragma omp parallel for reduction(+:sum)
#pragma omp parallel for
    for (int deviceId = 0; deviceId < nGPU; ++deviceId)
	{
	Device::setDevice(deviceId);
	float piHat = 0;
	MonteCarlo monteCarlo(grid, nbFlechetteGPU, &piHat);
	monteCarlo.run();
#pragma omp critical(idSectionCritique)
	    {
	    sum += monteCarlo.getFlecheSousCourbe();
	    nbFlechetteReel += monteCarlo.getFlecheTiree();
	    }
	}
    *ptrPiHat = 4 * sum / (double) nbFlechetteReel;
    }


/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

