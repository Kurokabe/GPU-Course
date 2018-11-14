#include "DamierRGBAFloatProvider.h"
#include "DamierRGBAFloat.h"

#include "MathTools.h"

#include "ImageAnimable_CPU.h"
#include "DomaineMath_CPU.h"
using namespace cpu;


/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Imported	 	*|
 \*-------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

/*--------------------------------------*\
 |*		Surcharge		*|
 \*-------------------------------------*/

/**
 * Override
 */
Animable_I<float4>* DamierRGBAFloatProvider::createAnimable(void)
    {
    DomaineMath domaineMath = DomaineMath(0, 0, 2 * PI, 2 * PI);

    // Animation;
    float dt = 2 * PI / 800;
    int n = 2;

    // Dimension
    int w = 16 * 32 * 2;
    int h = 16 * 32;

    return new DamierRGBAFloat(w, h, dt, n, domaineMath);
    }

/**
 * Override
 */
Image_I* DamierRGBAFloatProvider::createImageGL(void)
    {
    ColorRGB_01 colorTexte(0, 0, 0); // black
    return new ImageAnimable_RGBA_float4(createAnimable(),colorTexte);
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
