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
    float dt = 2 * PI / 1000;

    // Dimension
    int w = 16 * 80;
    int h = 16 * 60;

    // Grid Cuda
    int mp = Device::getMPCount();
    int coreMP = Device::getCoreCountMP();

    // TODO Raytracing GPU grid
    Grid grid;
    assert(false);// to delete once implement

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
