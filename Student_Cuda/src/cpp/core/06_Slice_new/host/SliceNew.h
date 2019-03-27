#pragma once

#include "cudaTools.h"
#include "Grid.h"


/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

/**
 * On passse la grille à SliceNaif pour pouvoir facilement la faire varier de l'extérieur pour trouver l'optimum, ou faire des tests avec des grilles différentes
 */
class SliceNew
    {
	/*--------------------------------------*\
	|*		Constructor		*|
	 \*-------------------------------------*/

    public:

	/**
	 * update piHat
	 * Hyp : nbThread est une puissance de 2
	 */
	SliceNew(const Grid& grid,int nbSlice, float* ptrPiHat);
	virtual ~SliceNew(void);

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
	int nbSlice;

	// Inputs/Outputs
	float* ptrPiHat;

	// Tools
	float* ptrDevResultat; // promotion de tabeau en GM
	size_t sizeTabGM;// [octet]
    };

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
