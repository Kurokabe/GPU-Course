#include <iostream>

#include "ReductionAddToolsLock.h"
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
__host__ bool isReductionAddToolsLock_I_Ok(const Grid& grid); // __host__ facultatif

/*---------------------*\
|*	private		*|
 \*----------------------*/

static __global__ void fillOne(long* ptrDevResultGM);
static __device__ void reductionIntraThread(long* tabSM);

/*----------------------------------------------------------------------*\
|*			Host	 					*|
 \*---------------------------------------------------------------------*/

/**
 * contrainte : db puissance de 2
 */
__host__ bool isReductionAddToolsLock_I_Ok(const Grid& grid)
    {
    // TODO
    // MM pour ptrDevResultGM (oubliez pas initialisation)
    // appeler kernel
    // MM recuprer resultat
    // cheker resultat
    long* ptrRes = new long[sizeof(long)];
    long* ptrResGM;
    *ptrRes = 0;
    Device::malloc(&ptrResGM, sizeof(long));
    Device::memcpyHToD(ptrResGM, ptrRes, sizeof(long));
    fillOne<<<grid.dg, grid.db,sizeof(long)*grid.db.x>>>(ptrResGM);
    Device::memcpyDToH(ptrRes, ptrResGM, sizeof(long));
    return * ptrRes == grid.db.x * grid.dg.x;
    }

/*----------------------------------------------------------------------*\
|*			Device	 					*|
 \*---------------------------------------------------------------------*/

/**
 * protocole :	1 partout en tabSM
 * resultat:	NB_THREAD_GLOBAL
 */
__global__ void fillOne(long* ptrDevResultGM)
    {
    // TODO declaration tabSM
    // reductionIntraThread
    // ReductionAddToolsLock
    extern __shared__ long tabSM[];
    reductionIntraThread(tabSM);
    __syncthreads();
    ReductionAddToolsLock::reductionADD(tabSM, ptrDevResultGM);
    // __syncthreads(); // des threads de meme block!// utile? ou?
    }

__device__ void reductionIntraThread(long* tabSM)
    {
    // TODO entrelacement et remplissage tabSM
    // rappel : |tabSM|=|threadByBlock|
    tabSM[threadIdx.x] = 1;
    }

/*----------------------------------------------------------------------*\
|*			End	 					*|
 \*---------------------------------------------------------------------*/
