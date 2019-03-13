#include <iostream>

#include "ReductionAddTools.h"
#include "Grid.h"

#include "Device.h"


using std::cout;
using std::endl;

/*----------------------------------------------------------------------*\
|*			Declaration					*|
 \*---------------------------------------------------------------------*/

/*---------------------*\
|*	public		*|
 \*----------------------*/

/**
 * contrainte : db puissance de 2
 */
__host__ bool isReductionAddTools_I_Ok(const Grid& grid); // __host__ facultatif

/*---------------------*\
|*	private		*|
 \*----------------------*/

static __global__ void fillOne(int* ptrDevResultGM);
static __device__ void reductionIntraThread(int* tabSM);

/*----------------------------------------------------------------------*\
|*			Host	 					*|
 \*---------------------------------------------------------------------*/

/**
 * contrainte : db puissance de 2
 */
__host__ bool isReductionAddTools_I_Ok(const Grid& grid)
    {
    // TODO
    // MM pour ptrDevResultGM (oubliez pas initialisation)
    // appeler kernel
    // MM recuprer resultat
    // cheker resultat
    int* ptrRes = new int[sizeof(int)];
    int* ptrResGM;
    *ptrRes = 0;
    Device::malloc(&ptrResGM, sizeof(int));

    Device::memcpyHToD(ptrResGM, ptrRes, sizeof(int));
    fillOne<<<grid.dg, grid.db, sizeof(int)*grid.db.x>>>(ptrResGM);
    Device::memcpyDToH(ptrRes, ptrResGM, sizeof(int));
    return *ptrRes == grid.db.x * grid.dg.x;
    }

/*----------------------------------------------------------------------*\
|*			Device	 					*|
 \*---------------------------------------------------------------------*/

/**
 * protocole :	1 partout en tabSM
 * resultat:	NB_THREAD_GLOBAL
 */
__global__ void fillOne(int* ptrDevResultGM)
    {
    // reductionIntraThread
    // ReductionAddTools

    extern __shared__ int tabSM[];
    reductionIntraThread(tabSM);
    __syncthreads();
    ReductionAddTools::reductionADD(tabSM, ptrDevResultGM);
    }

__device__ void reductionIntraThread(int* tabSM)
    {
    // rappel : |tabSM|=|threadByBlock|const int tid = blockDim.x * blockIdx threadIdx.x
    tabSM[threadIdx.x] = 1;
    }

/*----------------------------------------------------------------------*\
|*			End	 					*|
 \*---------------------------------------------------------------------*/
