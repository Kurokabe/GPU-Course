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

	    // TODO idem version sans lock (presque)
	    }

    private:

	/*--------------------------------------*\
	|*	reductionIntraBlock		*|
	 \*-------------------------------------*/

	/**
	 * used in reductionIntraBlock
	 */
	template <typename T>
	static __device__ void ecrasement(T* tabSM, int middle,Lock* ptrLock)
	    {
	    // TODO idem version sans lock (presque)
	    }

	/**
	 * Sur place, le resultat est dans tabSM[0]
	 */
	template <typename T>
	static __device__ void reductionIntraBlock(T* tabSM,Lock* ptrLock)
	    {
	    // TODO idem version sans lock (presque)
	    }

	/*--------------------------------------*\
	|*	reductionInterblock		*|
	 \*-------------------------------------*/

	template <typename T>
	static __device__ void reductionInterblock(T* tabSM, T* ptrDevResultatGM,Lock* ptrLock)
	    {
	    // TODO

	    ptrLock->lock();
	    // warning : atomicAdd n'existe pas dans cette version, on utlise le lock pour s'en sortir
	    // TODO
	    ptrLock->unlock();
	    }

    };

/*----------------------------------------------------------------------*\
|*			End	 					*|
 \*---------------------------------------------------------------------*/
