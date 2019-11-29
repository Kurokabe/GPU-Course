#include <assert.h>

#include "MathTools.h"
#include "Grid.h"
#include "HeatTransferProvider.h"

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Override		*|
 \*-------------------------------------*/

/**
 * Override
 */
Animable_I<uchar4>* HeatTransferProvider::createAnimable()
    {
    // Animation;
    float dt = 2 * PI / 10;

    // Dimension
    int w = 16 * 60;
    int h = 16 * 60;

    // Grid Cuda
    int mp = Device::getMPCount();
    int coreMP = Device::getCoreCountMP();


    dim3 dg = dim3(48, 1, 1);
    dim3 db = dim3(896, 1, 1);
    Grid grid(dg, db);

    ptrHeatTransfer = new HeatTransfer(grid, w, h, dt);
    return ptrHeatTransfer;
    }

/**
 * Override
 */
Image_I* HeatTransferProvider::createImageGL(void)
    {
    ColorRGB_01 colorTexte(0, 1, 0); // Green
    return new ImageAnimable_RGBA_uchar4(createAnimable(), colorTexte);
    }

void HeatTransferProvider::setDT(int dt)
    {
    if (ptrHeatTransfer != nullptr)
	{
	ptrHeatTransfer->setDT(dt);
	}
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
