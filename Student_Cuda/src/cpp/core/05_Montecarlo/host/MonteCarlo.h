#pragma once

#include "cudaTools.h"
#include "Grid.h"
#include <curand_kernel.h>

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class MonteCarlo
    {
	/*--------------------------------------*\
	|*		Constructor		*|
	 \*-------------------------------------*/
    public:
	MonteCarlo(const Grid&, int nbFlechette, float*ptrPiHat);
	virtual ~MonteCarlo(void);
	/*--------------------------------------*\
	|*		Methodes		*|
	 \*-------------------------------------*/

	public:

	    void run();

	    /*--------------------------------------*\
	    |*		Attributs		*|
	     \*-------------------------------------*/

	private:

	    // Inputs
	    dim3 dg;
	    dim3 db;
	    int nbFlechette;
	    int nbFlechetteThread;

	    // Inputs/Outputs
	    float* ptrPiHat;
	    int* ptrResultat;

	    // Tools
	    int* ptrDevResultat; // promotion de tabeau en GM
	    curandState* ptrDevtabGenerator;
	    size_t sizeResGM;// [octet]
	    size_t sizeTabGenerator;
    };


/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
