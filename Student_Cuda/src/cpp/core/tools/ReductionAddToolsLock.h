#pragma once

#include "Lock.h"

__device__ int mutex = 0;	//variable global au .cu,  Attention a l'initialisation a zero

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

class ReductionAddToolsLock
    {
    public:
	template <typename T>
	static __device__ void reductionADD(T* tabSM, T* ptrDevResultatGM)
	    {
	    Lock lock=Lock(&mutex);//le meme lock pour tous les threads, mutex declarer comme va globale ci-dessus
	    reductionIntraBlock(tabSM);
	    __syncthreads();
	    reductionInterblock(tabSM, ptrDevResultatGM, &lock);
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
