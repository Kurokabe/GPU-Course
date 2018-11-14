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
 * On passse la grille à AddVector pour pouvoir facilement la faire varier de l'extérieur pour trouver l'optimum, ou faire des tests avec des grilles différentes
 */
class AddVector
    {
	/*--------------------------------------*\
	|*		Constructor		*|
	 \*-------------------------------------*/

    public:

	/**
	 * update w by v1+v2
	 */
	AddVector(const Grid& grid, float* ptrV1, float* ptrV2, float* ptrW, int n);

	virtual ~AddVector(void);

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
	float* ptrV1;
	float* ptrV2;
	int n;

	// Inputs/Outputs
	float* ptrW;

	// Tools
	float* ptrDevV1;
	float* ptrDevV2;
	float* ptrDevW;
	size_t sizeVector; //[octet]

    };

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
