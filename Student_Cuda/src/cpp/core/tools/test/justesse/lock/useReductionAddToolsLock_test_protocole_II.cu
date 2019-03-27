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
__host__ bool isReductionAddToolsLock_II_Ok(const Grid& grid); // __host__ facultatif
__host__ bool isReductionAddToolsLock_II_Ok(); // __host__ facultatif

/*---------------------*\
|*	private		*|
 \*----------------------*/

static __global__ void fillTidGlobal(long* ptrDevResultGM);
static __device__ void reductionIntraThread(long* tabSM);

/*----------------------------------------------------------------------*\
|*			Host	 					*|
 \*---------------------------------------------------------------------*/

/**
 * contrainte : db puissance de 2
 */
__host__ bool isReductionAddToolsLock_II_Ok(const Grid& grid)
    {
    // MM pour ptrDevResultGM (oubliez pas initialisation)
    // appeler kernel
    // MM recuprer resultat
    // cheker resultat
    long* ptrRes = new long[sizeof(long)];
    long* ptrResGM;
    *ptrRes = 0;
    Device::malloc(&ptrResGM, sizeof(long));
    Device::memcpyHToD(ptrResGM, ptrRes, sizeof(long));
    fillTidGlobal<<<grid.dg, grid.db,sizeof(long)*grid.db.x>>>(ptrResGM);
    Device::memcpyDToH(ptrRes, ptrResGM, sizeof(long));
    long n = grid.db.x * grid.dg.x;
    return * ptrRes == n/2*(n-1);
    }


__host__ bool isReductionAddToolsLock_II_Ok()
    {
    bool isOk = true;
    dim3 dg = dim3(1,1,1);
    dim3 db = dim3(2, 1, 1);
    Grid grid(dg, db);
    for(int i = 1; i<=64; ++i)
    	{
    	dg.x = i;
    	grid.dg = dg;
    	for(int j = 2; j<=1024; j*=2)
    	    {
    	    db.x = j;
    	    grid.db = db;
    	    cout << grid << endl;
    	    isOk &= isReductionAddToolsLock_II_Ok(grid);
    	    }
    	}
    return isOk;
    }
/*----------------------------------------------------------------------*\
|*			Device	 					*|
 \*---------------------------------------------------------------------*/

/**
 * protocole :	TID_GLOBAL partout en tabSM
 * resultat:	 (n-1)n/2 ou n=NB_THREAD_GLOBAL
 */
__global__ void fillTidGlobal(long* ptrDevResultGM)
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
    tabSM[threadIdx.x] = blockDim.x * blockIdx.x + threadIdx.x;
    }

/*----------------------------------------------------------------------*\
|*			End	 					*|
 \*---------------------------------------------------------------------*/
