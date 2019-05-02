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
static __device__ void copyGMToSM(Sphere* tabGM, Sphere* tabSM, int n);

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
    HANDLE_ERROR(cudaMemcpyToSymbol(TAB_SPHERES_CM, ptrTabSpheres, nbSpheres*sizeof(Sphere), 0, cudaMemcpyHostToDevice));
    }

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

__global__ void kernelRaytacingGM(uchar4* ptrDevPixels, uint w, uint h, float t, Sphere* ptrTabSpheresGM, int nbSpheres)
    {
    work(ptrDevPixels, w, h, t, ptrTabSpheresGM, nbSpheres);
    }

__global__ void kernelRaytacingSM(uchar4* ptrDevPixels, uint w, uint h, float t, Sphere* ptrTabSpheresGM, int nbSpheres)
    {
    extern __shared__ Sphere tabSM[];
    copyGMToSM(ptrTabSpheresGM, tabSM, nbSpheres);
    __syncthreads(); // Barrière de synchronisation des threads du block
    work(ptrDevPixels, w, h, t, tabSM, nbSpheres);
    }

__global__ void kernelRaytacingCM(uchar4* ptrDevPixels, uint w, uint h, float t, int nbSpheres)
    {
    work(ptrDevPixels, w, h, t, TAB_SPHERES_CM, nbSpheres);
    }

/*--------------------------------------*\
 |*		private			*|
 \*-------------------------------------*/

/**
 * Methode commune au 3 kernel ci-dessus.
 */
__device__ void work(uchar4* ptrDevPixels, uint w, uint h, float t, Sphere* ptrDevTabSpheres, int nbSpheres)
    {
    RaytracingMath raytracingMath = RaytracingMath(ptrDevTabSpheres, nbSpheres);
    const int NB_THREAD = Indice2D::nbThread();
    const int WH = w * h;

    int i;	// in [0,h[
    int j; 	// in [0,w[


    int s =  Indice2D::tid();  // in [0,...
    while (s < WH)
	{
	IndiceTools::toIJ(s, w, &i, &j); 	// update (i, j)

	raytracingMath.color(&ptrDevPixels[s], i, j, t);
	s += NB_THREAD;
	}
    // create RaytracingMath
    // entrelacement
    }

__device__ void copyGMToSM(Sphere* tabGM, Sphere* tabSM, int n)
    {
//    int tidLocal = Indice2D::tidLocal();
    int nbThreadLocal = Indice2D::nbThreadLocal();
    int s = Indice2D::tidLocal();
    while(s<n)
	{
	tabSM[s] = tabGM[s];
	s+=nbThreadLocal;
	}
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

