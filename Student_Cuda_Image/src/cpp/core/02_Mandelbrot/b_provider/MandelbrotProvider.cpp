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

    // Domaine init
    double x1 = -2.1;
    double y1 = -1.3;
    double x2 = 0.8;
    double y2 = 1.3;
    DomaineMath domaineMath(x1, y1, x2, y2);

    // Dimension
    int w = 16 * 80;
    int h = 16 * 60;

    // grid cuda
    int mp = Device::getMPCount();
    int coreMP = Device::getCoreCountMP();

    Grid grid;  // TODO Rippling GPU grid:  definissez une grille cuda (dg, db)
    assert(false);// to delete once implement

    return new Mandelbrot(grid, w, h, domaineMath, nMin, nMax);
    }

/**
 * Override
 */
Image_I* MandelbrotProvider::createImageGL(void)
    {
    ColorRGB_01 colorTexte(0, 1, 0); // Green
    return new ImageAnimable_RGBA_uchar4(createAnimable(), colorTexte);
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
