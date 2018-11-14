// Attention : Extension .cu

#include <iostream>
#include <stdio.h>
#include "cudaTools.h"
#include "Device.h"

using std::cout;
using std::endl;

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Imported	 	*|
 \*-------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

__host__ int addScalarGPU(int a, int b); 			// __host__ facultatif

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

__global__ static void addScalar(int a, int b, int* ptrDevC);

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

__host__ int addScalarGPU(int a, int b) // __host__ facultatif
    {
    int c;
    int* ptrC = &c;	// on host (CPU)
    int* ptrDevC; 	// on device (GPU)

    // Specifier nb thread : ici 1 thread au total !
    dim3 dg = dim3(1, 1, 1);
    dim3 db = dim3(1, 1, 1);

    //Device::gridHeuristic(dg, db);

    size_t size = sizeof(int); // [octet]
    Device::malloc(&ptrDevC, size); // Device memory allocation (*)

    addScalar<<<dg,db>>>(a,b,ptrDevC); // asynchrone !!

    //v1
    Device::synchronize(); // Debug : necessaire only pour printf sur device

    //v2
    // cudaDeviceSynchronize(); // Debug : necessaire only pour printf sur device

    // memoryManagement => barrier de synchronisation
    Device::memcpyDToH(ptrC, ptrDevC, size);   // Device -> Host
    Device::free(ptrDevC); //  dispose memory create in (*)

    return c;
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/**
 * Hyp : 1 seul thread, ie dg(1,1,1) et db (1,1,1)
 */
__global__ void addScalar(int a, int b, int* ptrDevC)
    {
    *ptrDevC = a + b; // Hyp: 1 seul thread

    // debug
    printf("[GPU] %d + %d = %d", a, b, *ptrDevC);
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

