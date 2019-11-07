#include "../../mandebrot3d_RGBA_uchar4/provider/Mandelbrot3DProvider.h"

#include <iostream>

#include "Grid.h"
#include "Device.h"
#include "MathTools.h"

#include "DomainMath3D_GPU.h"

#include "../../mandebrot3d_RGBA_uchar4/host/Mandelbrot3D_RGBA.h"

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
SurfaceStrip_I* Mandelbrot3dProvider::createSurfaceStrip()
    {
    // Animation;
    int nMin = 10;
    int nMax = 100;

    // Dimension "Image" en noeud
    uint w = 16 * 80;
    uint h = w;	// contrainte temporaire

    // Animation
    float dt = 1; // animation

    // Para de math
    int k = 2;

    // Domaine init
    double x1 = -2.1;
    double x2 = 0.8;

    double y1 = -1.3;
    double y2 = 1.3;

    double z1 = -1;
    double z2 = 1;

    DomainMath3D domaineMath(x1, x2, y1, y2, z1, z2); // Attention ordre, pas idem DomainMath2D, ici x1,x2, ...

    // Grid Cuda
    int mp = Device::getMPCount();
    int coreMP = Device::getCoreCountMP();

    dim3 dg = dim3(mp, 2, 1);  		// disons, a optimiser selon le gpu, peut drastiqument ameliorer ou baisser les performances
    dim3 db = dim3(coreMP, 2, 1);   	// disons, a optimiser selon le gpu, peut drastiqument ameliorer ou baisser les performances
    Grid grid(dg, db);

    return new Mandelbrot3D_RGBA(grid, w, h, domaineMath, dt, nMin, nMax); // Model
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

