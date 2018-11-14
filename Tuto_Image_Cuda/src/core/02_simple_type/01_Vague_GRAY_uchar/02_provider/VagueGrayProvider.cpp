#include "VagueGrayProvider.h"
#include "VagueGray.h"

#include "MathTools.h"
#include "Grid.h"

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
Animable_I<uchar>* VagueGrayProvider::createAnimable()
    {
    // Animation;
    float dt = 2 * PI / 1000;

    // Dimension
    int w = 16 * 32 * 2;
    int h = 16 * 32;

    // Grid Cuda
    int mp = Device::getMPCount();
    int coreMP = Device::getCoreCountMP();

    dim3 dg = dim3(mp, 2, 1);  		// disons, a optimiser selon le gpu, peut drastiqument ameliorer ou baisser les performances
    dim3 db = dim3(coreMP , 2, 1);   	// disons, a optimiser selon le gpu, peut drastiqument ameliorer ou baisser les performances
    Grid grid(dg, db);

    return new VagueGray(grid, w, h, dt);
    }

/**
 * Override
 */
Image_I* VagueGrayProvider::createImageGL(void)
    {
    ColorRGB_01 colorTexte(1, 0, 0); // red
    return new ImageAnimable_GRAY_uchar(createAnimable(), colorTexte);

    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
