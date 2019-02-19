#include "RaytracingProvider.h"

#include "Grid.h"
#include <assert.h>

#include "memoryType.h"

#include "Raytracing.h"
#include "nbSphere.h"

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Override		*|
 \*-------------------------------------*/

/**
 * Override
 */
Animable_I<uchar4>* RaytracingProvider::createAnimable()
    {
    // Animation;
    float dt = 2 * PI / 10;

    // Dimension
    int w = 16 * 80;
    int h = 16 * 60;

    // Grid Cuda
    int mp = Device::getMPCount();
    int coreMP = Device::getCoreCountMP();

    // TODO Raytracing GPU grid
    dim3 dg = dim3(48, 1, 1);
    dim3 db = dim3(800, 1, 1);
    Grid grid(dg, db);
    //assert(false);// to delete once implement

    // Essayer les trois!
    MemoryType memoryType=GM;
//    MemoryType memoryType=CM;
//    MemoryType memoryType=SM;

    return new Raytracing(grid, w, h, dt, NB_SPHERE,memoryType); // NB_SPHERE define "nbSphere.h"
    }

/**
 * Override
 */
Image_I* RaytracingProvider::createImageGL(void)
    {
    ColorRGB_01 colorTexte(0, 1, 0); // Green
    return new ImageAnimable_RGBA_uchar4(createAnimable(), colorTexte);
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
