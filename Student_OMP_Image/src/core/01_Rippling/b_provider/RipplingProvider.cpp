#include "RipplingProvider.h"
#include "Rippling.h"

#include "ImageAnimable_CPU.h"
using namespace cpu;

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Override		*|
 \*-------------------------------------*/

/**
 * Override
 */
Animable_I<uchar4>* RipplingProvider::createAnimable(void)
    {
    // Animation
    float dt = 1;

    // Dimension
    int w = 16 * 60;
    int h = 16 * 60;

    return new Rippling(w, h, dt);
    }

/**
 * Override
 */
Image_I* RipplingProvider::createImageGL(void)
    {
    ColorRGB_01 colorTexte(0, 1, 0); // green
    return new ImageAnimable_RGBA_uchar4(createAnimable(), colorTexte);
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
