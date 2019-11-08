#include "RaytracingProvider.h"

#include "Grid.h"
#include <assert.h>

#include "memoryType.h"

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

    dim3 dg = dim3(48, 1, 1);
    dim3 db = dim3(896, 1, 1);
    Grid grid(dg, db);

    // Essayer les trois!
    //MemoryType memoryType=GM;
    //MemoryType memoryType=CM;
    MemoryType memoryType=SM;
    ptrRaytracing = new Raytracing(grid, w, h, dt, NB_SPHERE,memoryType);
    return ptrRaytracing; // NB_SPHERE define "nbSphere.h"
    }

/**
 * Override
 */
Image_I* RaytracingProvider::createImageGL(void)
    {
    ColorRGB_01 colorTexte(0, 1, 0); // Green
    return new ImageAnimable_RGBA_uchar4(createAnimable(), colorTexte);
    }

void RaytracingProvider::setDT(int dt)
    {
    if (ptrRaytracing != nullptr)
	{
	ptrRaytracing->setDT(dt);
	}
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
