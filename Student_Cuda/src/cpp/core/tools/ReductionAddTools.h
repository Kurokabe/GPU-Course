#pragma once

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

class ReductionAddTools
    {
    public:

	/**
	 * Hypothese:
	 *
	 * 	(H1) 	On suppose que T est un type simple sur lequel atomicAdd existe
	 *
	 * Exemple :
	 * 		ReductionAddTools.add<int>(tabSm,ptrDevResultatGM);
	 *
	 * Contraintes :
	 *
	 * 	(C1) 	|tabSM| puissance de 2, comme 32,64,128,256,512,1024
	 * 	(C2)	|ThreadByBlock|=|tabSM|
	 * 	(C3)	Reduction intra-thread laisser a l'utilsiateur
	 *
	 * Warning :
	 *
	 * 	(W1)	ptrDevResultatGM n'est pas un tableau
	 * 	(W2)	Oubliez pas le MM pour  ptrDevResultatGM
	 * 	(W3)	Oubliez pas l'initialisation de ptrDevResultatGM ( a 0 pour de l'addiction)
	 */
	template <typename T>
	static __device__ void reductionADD(T* tabSM, T* ptrDevResultatGM)
	    {
	    // Rappel :
	    // 		|ThreadByBlock|=|tabSM| .
	    // 		Il y autant de case en SM que de thread par block.
	    //		Chaque thread possede son armoire en SM
	    //		1 thread <---> 1 armoire

	    reductionIntraBlock(tabSM);
	    __syncthreads();
	    reductionInterblock(tabSM, ptrDevResultatGM);

	    // __syncthreads();// pour touts les threads d'un meme block, necessaires? ou?
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
	    while(middle>=1) {
		ecrasement(tabSM, middle);
		__syncthreads();
		middle/=2;
	    }

	    // __syncthreads();// pour touts les threads d'un meme block, necessaires? ou?
	    }

	/*--------------------------------------*\
	|*	reductionInterblock		*|
	 \*-------------------------------------*/

	template <typename T>
	static __device__ void reductionInterblock(T* tabSM, T* ptrDevResultatGM)
	    {
	    // utiliser atomicAdd(pointeurDestination, valeurSource);
	    // warning : atomicAdd existe pas forcement pour tous les types simples!!

	    // Hyp : grid et block 1d
	    // Contrainte : Interdit d'utiliser le helper Indice1D
	    if(threadIdx.x == 0)
		{
		atomicAdd(ptrDevResultatGM, tabSM[0]);
		}
	    }

    };

/*----------------------------------------------------------------------*\
|*			End	 					*|
 \*---------------------------------------------------------------------*/
