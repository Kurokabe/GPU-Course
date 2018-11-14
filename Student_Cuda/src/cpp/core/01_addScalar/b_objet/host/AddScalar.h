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
 * On passse la grille à AddScalar pour pouvoir facilement la faire varier de l'extérieur pour trouver l'optimum, ou faire des tests avec des grilles différentes
 */
class AddScalar
    {
	/*--------------------------------------*\
	|*		Constructor		*|
	 \*-------------------------------------*/

    public:

	/**
	 * resultat dans c
	 * c=a+b
	 */
	AddScalar(float a, float b, float* ptrC);

	virtual ~AddScalar(void);

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
	float a;
	float b;

	// Inputs/Outputs
	float* ptrC;

	// Tools
	float* ptrDevC;
	size_t sizeFloat;

    };

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
