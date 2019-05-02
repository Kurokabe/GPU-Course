#include "MandelbrotProvider.h"

#include <assert.h>
#include "MathTools.h"
#include "Grid.h"
#include "Mandelbrot.h"

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Override		*|
 \*-------------------------------------*/

/**
 * Override
 */
Animable_I<uchar4>* MandelbrotProvider::createAnimable()
    {
    // Animation;
    int nMin = 20;
    int nMax = 120;

    DomaineMath domaineMath(this->x1, this->y1, this->x2, this->y2);

    // Dimension
    int w = 16 * 80;
    int h = 16 * 60;

    // grid cuda
    int mp = Device::getMPCount();
    int coreMP = Device::getCoreCountMP();

    dim3 dg = dim3(48, 1, 1);
    dim3 db = dim3(384, 1, 1);
    Grid grid(dg, db);

    return new Mandelbrot(grid, w, h, domaineMath, nMin, nMax);
    }

/**
 * Override
 */
Image_I* MandelbrotProvider::createImageGL(void)
    {
    this->x1 = -2.1;
    this->y1 = -1.3;
    this->x2 = 0.8;
    this->y2 = 1.3;
    ColorRGB_01 colorTexte(0, 1, 0); // Green
    return new ImageAnimable_RGBA_uchar4(createAnimable(), colorTexte);
    }

Image_I* MandelbrotProvider::createImageGL(float x1, float x2, float y1, float y2)
    {
    this->x1 = x1;
    this->y1 = y1;
    this->x2 = x2;
    this->y2 = y2;
    ColorRGB_01 colorTexte(0, 1, 0); // Green
    return new ImageAnimable_RGBA_uchar4(createAnimable(), colorTexte);
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
