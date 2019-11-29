#include <assert.h>

#include "RipplingProvider.h"
#include "MathTools.h"
#include "Grid.h"

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Override		*|
 \*-------------------------------------*/

/**
 * Override
 */
Animable_I<uchar4>* RipplingProvider::createAnimable()
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

    ptrRippling = new Rippling(grid, w, h, dt);
    return ptrRippling;
    }

/**
 * Override
 */
Image_I* RipplingProvider::createImageGL(void)
    {
    ColorRGB_01 colorTexte(0, 1, 0); // Green
    return new ImageAnimable_RGBA_uchar4(createAnimable(), colorTexte);
    }

void RipplingProvider::setDT(int dt)
    {
    if (ptrRippling != nullptr)
	{
	ptrRippling->setDT(dt);
	}
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
