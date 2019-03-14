#pragma once

#include "Lock.h"

__device__ int mutex = 0;	//variable global au .cu,  Attention a l'initialisation a zero

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

class ReductionAddToolsLock
    {
    public:

	/**
	 * Hypothese:
	 *
	 * 	(H1) 	On suppose que T est un type simple sur lequel atomicAdd n'existe pas
	 *
	 * Doc :
	 * 		see ReductionAddTools.h
	 */
	template <typename T>
	static __device__ void reductionADD(T* tabSM, T* ptrDevResultatGM)
	    {
	    Lock lock=Lock(&mutex);//le meme lock pour tous les threads, mutex declarer comme va globale ci-dessus
	    reductionIntraBlock(tabSM);
	    __syncthreads();
	    reductionInterblock(tabSM, ptrDevResultatGM, &lock);
	    // TODO idem version sans lock (presque)
	    }

    private:

	/*--------------------------------------*\
	|*	reductionIntraBlock		*|
	 \*-------------------------------------*/

	/**
	 * used dans une boucle in reductionIntraBlock
	 */
	template <typename T>
	static __device__ void ecrasement(T* tabSM, int middle)
	    {
	    // TODO idem version sans lock (presque)
	    const int TIDLocal = threadIdx.x;
	    if(TIDLocal<middle)
		{
		tabSM[TIDLocal] += tabSM[TIDLocal+middle];
		}
	    }

	/**
	 * Sur place, le resultat est dans tabSM[0]
	 */
	template <typename T>
	static __device__ void reductionIntraBlock(T* tabSM)
	    {
	    // TODO idem version sans lock (presque)
	    int middle = blockDim.x/2;
	    while(middle>=1)
		{
		ecrasement(tabSM, middle);
		__syncthreads();
		middle/=2;
		}
	    }

	/*--------------------------------------*\
	|*	reductionInterblock		*|
	 \*-------------------------------------*/

	template <typename T>
	static __device__ void reductionInterblock(T* tabSM, T* ptrDevResultatGM,Lock* ptrLock)
	    {
	    // TODO

	    // warning : atomicAdd n'existe pas dans cette version, on utlise le lock pour s'en sortir
	    // TODO
	    if(threadIdx.x==0)
		{
		ptrLock->lock();
		*ptrDevResultatGM += tabSM[0];
		ptrLock->unlock();
		}
	    }

    };

/*----------------------------------------------------------------------*\
|*			End	 					*|
 \*---------------------------------------------------------------------*/
