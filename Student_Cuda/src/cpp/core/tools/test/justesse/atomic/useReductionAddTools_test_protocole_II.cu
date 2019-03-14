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
__host__ bool isReductionAddTools_II_Ok(const Grid& grid); // __host__ facultatif

/*---------------------*\
|*	private		*|
 \*----------------------*/

static __global__ void fillTidGlobal(int* ptrDevResultGM);
static __device__ void reductionIntraThread(int* tabSM);

/*----------------------------------------------------------------------*\
|*			Host	 					*|
 \*---------------------------------------------------------------------*/

/**
 * contrainte : db puissance de 2
 */
__host__ bool isReductionAddTools_II_Ok(const Grid& grid)
    {
    // MM pour ptrDevResultGM (oubliez pas initialisation)
    // appeler kernel
    // MM recuprer resultat
    // cheker resultat
    int* ptrRes = new int[sizeof(int)];
    int* ptrResGM;
    *ptrRes = 0;
    Device::malloc(&ptrResGM, sizeof(int));

    Device::memcpyHToD(ptrResGM, ptrRes, sizeof(int));
    fillTidGlobal<<<grid.dg, grid.db, sizeof(int)*grid.db.x>>>(ptrResGM);
    Device::memcpyDToH(ptrRes, ptrResGM, sizeof(int));
    long n = grid.db.x * grid.dg.x;
    return *ptrRes == n/2*(n-1);
    }

/*----------------------------------------------------------------------*\
|*			Device	 					*|
 \*---------------------------------------------------------------------*/

/**
 * protocole :	TID_GLOBAL partout en tabSM
 * resultat:	 (n-1)n/2 ou n=NB_THREAD_GLOBAL
 */
__global__ void fillTidGlobal(int* ptrDevResultGM)
    {
    // TODO declaration tabSM
    // reductionIntraThread
    // ReductionAddTools
    extern __shared__ int tabSM[];
    reductionIntraThread(tabSM);
    __syncthreads();
    ReductionAddTools::reductionADD(tabSM, ptrDevResultGM);

    // __syncthreads(); // des threads de meme block!// utile? ou?
    }

__device__ void reductionIntraThread(int* tabSM)
    {
    // TODO entrelacement et remplissage tabSM
    // rappel : |tabSM|=|threadByBlock|
    tabSM[threadIdx.x] = blockDim.x * blockIdx.x + threadIdx.x;
    }

/*----------------------------------------------------------------------*\
|*			End	 					*|
 \*---------------------------------------------------------------------*/
