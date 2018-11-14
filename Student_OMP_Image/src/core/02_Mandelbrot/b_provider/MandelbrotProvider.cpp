#include "MandelbrotProvider.h"
#include "Mandelbrot.h"

#include "ImageAnimable_CPU.h"
using namespace cpu;

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Surcharge		*|
 \*-------------------------------------*/

/**
 * Override
 */
Animable_I<uchar4>* MandelbrotProvider::createAnimable(void)
    {
    // animation
    int nMin = 20;
    int nMax = 100;

    // Dimension
    int w = 16 * 80;
    int h = 16 * 60;

    // Domaine
    double x1 = -2.1;
    double y1 = -1.3;
    double x2 = 0.8;
    double y2 = 1.3;
    DomaineMath domaineMath(x1, y1, x2, y2);

    return new Mandelbrot(w, h, domaineMath, nMin, nMax);
    }

/**
 * Override
 */
Image_I* MandelbrotProvider::createImageGL(void)
    {
    ColorRGB_01 colorTexte(0, 1, 0); // green
    return new ImageAnimable_RGBA_uchar4(createAnimable(), colorTexte);
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
