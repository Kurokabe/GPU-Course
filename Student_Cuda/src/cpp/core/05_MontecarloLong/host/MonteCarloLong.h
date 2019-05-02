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

class MonteCarloLong
    {
	/*--------------------------------------*\
	|*		Constructor		*|
	 \*-------------------------------------*/
    public:
	MonteCarloLong(const Grid&, long nbFlechette, float*ptrPiHat);
	virtual ~MonteCarloLong(void);
	/*--------------------------------------*\
	|*		Methodes		*|
	 \*-------------------------------------*/

	public:

	    void run();
	    long getFlecheSousCourbe();
	    long getFlecheTiree();

	    /*--------------------------------------*\
	    |*		Attributs		*|
	     \*-------------------------------------*/

	private:

	    // Inputs
	    dim3 dg;
	    dim3 db;
	    long nbFlechette;
	    long nbFlechetteThread;

	    // Inputs/Outputs
	    float* ptrPiHat;
	    long* ptrResultat;

	    // Tools
	    long* ptrDevResultat; // promotion de tabeau en GM
	    curandState* ptrDevtabGenerator;
	    size_t sizeResGM;// [octet]
	    size_t sizeTabGenerator;
    };


/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
