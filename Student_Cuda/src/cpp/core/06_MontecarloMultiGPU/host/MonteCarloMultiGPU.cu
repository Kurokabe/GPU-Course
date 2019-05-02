#include "../../06_MontecarloMultiGPU/host/MonteCarloMultiGPU.h"

#include <iostream>
#include <assert.h>
#include "Device.h"
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
    //null
    }

MonteCarloMultiGPU::~MonteCarloMultiGPU(void)
    {
    //null
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

