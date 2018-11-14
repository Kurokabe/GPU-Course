#include <assert.h>

#include "Indice2D.h"
#include "cudaTools.h"
#include "Device.h"

#include "Sphere.h"
#include "IndiceTools_GPU.h"

#include "RaytracingMath.h"
#include "nbSphere.h"
using namespace gpu;

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

__constant__ Sphere TAB_SPHERES_CM[NB_SPHERE]; // NB_SPHERE define in nbSphere.h

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

__global__ void kernelRaytacingGM(uchar4* ptrDevPixels, uint w, uint h, float t, Sphere* ptrTabSpheresGM, int nbSpheres);
__global__ void kernelRaytacingSM(uchar4* ptrDevPixels, uint w, uint h, float t, Sphere* ptrTabSpheresGM, int nbSpheres);
__global__ void kernelRaytacingCM(uchar4* ptrDevPixels, uint w, uint h, float t, int nbSpheres);

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

static __device__ void work(uchar4* ptrDevPixels, uint w, uint h, float t, Sphere* ptrDevTabSpheres, int nbSpheres);

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		host			*|
 \*-------------------------------------*/

/**
 * must be called by host
 * ptrTabSpheres est un tableau de sphere cote host
 */
__host__ void uploadToCM(Sphere* ptrTabSpheres, int nbSpheres)
    {
    assert(nbSpheres == NB_SPHERE);

    assert(false);// to delete once implement

    // TODO Raytracing GPU CM
    // mettre ptrTabSpheres dans TAB_SPHERES_CM (line 16)
    }

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

__global__ void kernelRaytacingGM(uchar4* ptrDevPixels, uint w, uint h, float t, Sphere* ptrTabSpheresGM, int nbSpheres)
    {
    // TODO Raytracing GPU GM
    // call work with good input
    }

__global__ void kernelRaytacingSM(uchar4* ptrDevPixels, uint w, uint h, float t, Sphere* ptrTabSpheresGM, int nbSpheres)
    {
    // TODO Raytracing GPU SM
    // call work with good input
    }

__global__ void kernelRaytacingCM(uchar4* ptrDevPixels, uint w, uint h, float t, int nbSpheres)
    {
    // TODO Raytracing GPU CM
    // call work with good input
    }

/*--------------------------------------*\
 |*		private			*|
 \*-------------------------------------*/

/**
 * Methode commune au 3 kernel ci-dessus.
 * Ici on ne sait pas si derriere ptrDevTabSpheres, c'est
 * 	- de la GM?
 * 	- de la SM?
 * 	- de la CM?
 * Pas d'importance, c'est un pointeur et on travail avec!
 */
__device__ void work(uchar4* ptrDevPixels, uint w, uint h, float t, Sphere* ptrDevTabSpheres, int nbSpheres)
    {
    // TODO Raytracing GPU device side
    // create RaytracingMath
    // entrelacement
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

