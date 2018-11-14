#include "DamierHueFloatProvider.h"
#include "DamierHueFloat.h"

#include "MathTools.h"
#include "Grid.h"

#include "DomaineMath_GPU.h"
using namespace gpu;

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

/**
 * Override
 */
Animable_I<float>* DamierHueFloatProvider::createAnimable()
    {
    DomaineMath domaineMath = DomaineMath(0, 0, 2 * PI, 2 * PI);

    // Animation;
    float dt = 2 * PI / 2000;
    int n = 2;

    // Dimension
    int w = 16 * 32 * 2;
    int h = 16 * 32;

    // Grid Cuda
    int mp = Device::getMPCount();
    int coreMP = Device::getCoreCountMP();

    dim3 dg = dim3(mp, 2, 1);  		// disons, a optimiser selon le gpu, peut drastiqument ameliorer ou baisser les performances
    dim3 db = dim3(coreMP, 2, 1);  	// disons, a optimiser selon le gpu, peut drastiqument ameliorer ou baisser les performances
    Grid grid(dg, db);

    return new DamierHueFloat(grid, w, w, dt, n, domaineMath);
    }

/**
 * Override
 */
Image_I* DamierHueFloatProvider::createImageGL(void)
    {
    ColorRGB_01 colorTexte(0, 0, 0); // black
    return new ImageAnimable_HUE_float(createAnimable(), colorTexte);
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
