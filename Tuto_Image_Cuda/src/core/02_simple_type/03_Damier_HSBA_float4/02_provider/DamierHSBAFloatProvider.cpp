#include "DamierHSBAFloatProvider.h"
#include "DamierHSBAFloat.h"

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
Animable_I<float4>* DamierHSBAFloatProvider::createAnimable()
    {
    DomaineMath domaineMath=DomaineMath(0,0,2*PI,2*PI);

    // Animation;
    float dt =  2 * PI / 2000;
    int n=2;

    // Dimension
    int w = 16 * 32 * 2;
    int h = 16 * 32;

    // Grid Cuda
    int mp = Device::getMPCount();
    int coreMP = Device::getCoreCountMP();

    dim3 dg = dim3(mp, 2, 1);  		// disons, a optimiser selon le gpu, peut drastiqument ameliorer ou baisser les performances
    dim3 db = dim3(coreMP, 2, 1);  	// disons, a optimiser selon le gpu, peut drastiqument ameliorer ou baisser les performances
    Grid grid(dg, db);

    return new DamierHSBAFloat(grid,w, h, dt,n,domaineMath);
    }

/**
 * Override
 */
Image_I* DamierHSBAFloatProvider::createImageGL(void)
    {
    ColorRGB_01 colorTexte(0, 0, 0); // black
    return new ImageAnimable_HSBA_float4(createAnimable(), colorTexte);
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
