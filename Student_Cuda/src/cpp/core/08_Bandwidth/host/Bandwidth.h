#pragma once

#include "cudaTools.h"
#include "Grid.h"


/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

enum TransferType
    {
    HostToDevice,
    HostToDeviceDMA,
    DeviceToDevice,
    DeviceToDeviceMultiGPU,
    DeviceToDeviceMultiGPUEntrelacement,
    DeviceToDeviceMultiGPUOneOne,
    DeviceToDeviceEntrelacement,
    DeviceToDeviceOneOne,
    };

/**
 * On passse la grille à SliceNaif pour pouvoir facilement la faire varier de l'extérieur pour trouver l'optimum, ou faire des tests avec des grilles différentes
 */
class Bandwidth
    {
	/*--------------------------------------*\
	|*		Constructor		*|
	 \*-------------------------------------*/

    public:

	/**
	 * update piHat
	 * Hyp : nbThread est une puissance de 2
	 */
	Bandwidth(const Grid& grid, int* tabData, int n, TransferType type);
	virtual ~Bandwidth(void);

	/*--------------------------------------*\
	|*		Methodes		*|
	 \*-------------------------------------*/

    public:
	void run();

	double getElapsedTime();
	/*--------------------------------------*\
	|*		Attributs		*|
	 \*-------------------------------------*/

    private:
	// Inputs
	dim3 dg;
	dim3 db;
	int n;
	double elapsedTime;

	// Inputs/Outputs
	int* tabDataGM;
	int* tabDataGMCopy;
	TransferType type;

	// Tools
	size_t sizeTabDataGM;// [octet]
    };

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
