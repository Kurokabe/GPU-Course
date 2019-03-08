#include <iostream>

#include "ReductionAddToolsLock.h"
#include "Grid.h"

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

    // __syncthreads(); // des threads de meme block!// utile? ou?
    }

__device__ void reductionIntraThread(long* tabSM)
    {
    // TODO entrelacement et remplissage tabSM
    // rappel : |tabSM|=|threadByBlock|
    }

/*----------------------------------------------------------------------*\
|*			End	 					*|
 \*---------------------------------------------------------------------*/
