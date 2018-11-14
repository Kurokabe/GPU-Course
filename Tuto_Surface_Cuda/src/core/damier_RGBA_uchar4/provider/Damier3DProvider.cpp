#include <iostream>

#include "Grid.h"
#include "Device.h"
#include "MathTools.h"

#include "Damier3D_RGBA.h"
#include "Damier3DProvider.h"

#include "DomainMath3D_GPU.h"

using gpu::DomainMath3D;

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Constructor		*|
 \*-------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

/**
 * static
 */
SurfaceStrip_I* Damier3DProvider::createSurfaceStrip()
    {
    // Dimension "Image" en noeud
    uint w = 100;
    uint h = w;	// contrainte temporaire

    // Animation
    float dt = 2 * PI / 1000; // animation

    // Para de math
    int k = 2;

    // Domaine init
    double x1 = 0;
    double x2 = 2 * PI;

    double y1 = 0;
    double y2 = 2 * PI;

    double z1 = -1;
    double z2 = 1;

    DomainMath3D domaineMath(x1, x2, y1, y2, z1, z2); // Attention ordre, pas idem DomainMath2D, ici x1,x2, ...

    // Grid Cuda
    int mp = Device::getMPCount();
    int coreMP = Device::getCoreCountMP();

    dim3 dg = dim3(mp, 2, 1);  		// disons, a optimiser selon le gpu, peut drastiqument ameliorer ou baisser les performances
    dim3 db = dim3(coreMP, 2, 1);   	// disons, a optimiser selon le gpu, peut drastiqument ameliorer ou baisser les performances
    Grid grid(dg, db);

    return new Damier3D_RGBA(grid, w, h, domaineMath, dt, k); // Model
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

