#include "Raytracing.h"

#include <iostream>

#include "Device.h"
#include <assert.h>
#include "SphereCreator.h"

using std::cout;
using std::endl;

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/


/*--------------------------------------*\
 |*		Imported	 	*|
 \*-------------------------------------*/

__global__ void kernelRaytacingGM(uchar4* ptrDevPixels, uint w, uint h, float t, Sphere* ptrTabSpheresGM, int nbSpheres);
__global__ void kernelRaytacingSM(uchar4* ptrDevPixels, uint w, uint h, float t, Sphere* ptrTabSpheresGM, int nbSpheres);
__global__ void kernelRaytacingCM(uchar4* ptrDevPixels, uint w, uint h, float t, int nbSpheres);

__host__ void uploadToCM(Sphere* ptrTabSpheres, int nbSpheres);

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Constructeur		*|
 \*-------------------------------------*/

Raytracing::Raytracing(const Grid& grid, uint w, uint h, float dt, int nbSpheres,const MemoryType& memoryType) :
	Animable_I<uchar4>(grid, w, h, "Raytracing_Cuda_RGBA_uchar4"), memoryType(memoryType)
    {
    // Inputs
    this->dt = dt;
    this->nbSpheres = nbSpheres;

    // Tools
    this->sizeSpheres = nbSpheres * sizeof(Sphere);
    this->t = 0;

    // spheres
    SphereCreator sphereCreator(nbSpheres, w, h);
    uploadToDevice(sphereCreator.getTabSphere());

    cout << "[Raytracing] : memoryType : " << memoryType;
    }

Raytracing::~Raytracing()
    {
    switch (memoryType)
	{
	case GM:
	    {
	    Device::free(ptrDevTabSpheres);
	    break;
	    }
	case CM:
	    {
	    //null
	    break;
	    }
	case SM:
	    {
	    Device::free(ptrDevTabSpheres);
	    break;
	    }
	}
    }

/*--------------------------------------*\
 |*		Methode			*|
 \*-------------------------------------*/

/**
 * Override
 */
void Raytracing::process(uchar4* ptrDevPixels, uint w, uint h, const DomaineMath& domaineMath)
    {
    // TODO Raytracing GPU lauch kernel

    switch (memoryType)
	{
	case GM:
	    {
	    //assert(false);// to delete once implement
	    // Call the kernel kernelRaytacingGM (line 25)
	    kernelRaytacingGM<<<dg,db>>>(ptrDevPixels, w, h, t, ptrDevTabSpheres, nbSpheres);
	    break;
	    }
	case CM:
	    {
	    kernelRaytacingCM<<<dg, db>>>(ptrDevPixels, w, h, t, nbSpheres);
	    break;
	    }
	case SM:
	    {
	    // Call the kernel kernelRaytacingSM (line 27)
	    kernelRaytacingSM<<<dg, db, sizeSpheres>>>(ptrDevPixels, w, h, t, ptrDevTabSpheres, nbSpheres);
	    break;
	    }
	}
    }

/**
 * Override
 */
void Raytracing::animationStep()
    {
    t += dt;
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

void Raytracing::uploadToDevice(Sphere* ptrTabSpheres)
    {
    // TODO Raytracing GPU MemoryManagement
    switch (memoryType)
	{
	case GM:
	    {
	    Device::malloc(&ptrDevTabSpheres, sizeSpheres);
	    Device::memcpyHToD(ptrDevTabSpheres, ptrTabSpheres, sizeSpheres);
	    break;
	    }
	case CM:
	    {
	    uploadToCM(ptrTabSpheres, nbSpheres);
	    break;
	    }
	case SM:
	    {
	    Device::malloc(&ptrDevTabSpheres, sizeSpheres);
	    Device::memcpyHToD(ptrDevTabSpheres, ptrTabSpheres, sizeSpheres);
	    break;
	    }
	}
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

