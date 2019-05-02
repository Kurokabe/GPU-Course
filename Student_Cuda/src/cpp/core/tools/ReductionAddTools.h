#pragma once

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

class ReductionAddTools
    {
    public:
	template <typename T>
	static __device__ void reductionADD(T* tabSM, T* ptrDevResultatGM)
	    {
	    reductionIntraBlock(tabSM);
	    __syncthreads();
	    reductionInterblock(tabSM, ptrDevResultatGM);
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
	    // Indication : je suis un thread, je dois faire quoi
	    const int TIDLocal = threadIdx.x;
	    if(TIDLocal < middle)
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
	    // Ecrasement sucessifs dans une boucle (utiliser methode ecrasement ci-dessus)

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
	static __device__ void reductionInterblock(T* tabSM, T* ptrDevResultatGM)
	    {
	    if(threadIdx.x == 0)
		{
		atomicAdd(ptrDevResultatGM, tabSM[0]);
		}
	    }

    };

/*----------------------------------------------------------------------*\
|*			End	 					*|
 \*---------------------------------------------------------------------*/
