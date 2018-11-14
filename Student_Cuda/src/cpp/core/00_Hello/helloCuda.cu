// Attention : Extension .cu

#include <iostream>
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

__host__ bool helloCuda(void); //__host__ facultatif

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

__global__ static void kernelHello(void);
__device__ static void doSomethingHello(void);

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

/**
 * http://www.icl.utk.edu/~mgates3/docs/cuda.html
 */
__host__ bool helloCuda(void) //__host__ facultatif
    {
    cout << endl << "[Hello Cuda] : kernel empty" << endl;

    // Specifier nb thread : ici 1 thread au total !
    dim3 dg = dim3(1, 1, 1);
    dim3 db = dim3(1, 1, 1);

    //Device::gridHeuristic(dg, db);

    kernelHello<<<dg,db>>>();  // asynchrone !!

    return true;
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/**
 * output : void
 */
__global__ void kernelHello(void)
    {
    doSomethingHello();
    }

/**
 * Can be call only by device
 * inliner by nvcc (nvidia compiler)
 */
__device__ void doSomethingHello(void)
    {
    // rien
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

