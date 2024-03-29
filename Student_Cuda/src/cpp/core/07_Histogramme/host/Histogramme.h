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
class Histogramme
    {
	/*--------------------------------------*\
	|*		Constructor		*|
	 \*-------------------------------------*/

    public:

	/**
	 * update piHat
	 * Hyp : nbThread est une puissance de 2
	 */
	Histogramme(const Grid& grid, int n, int* tabData, int* tabFrequence, int dataMax);
	virtual ~Histogramme(void);

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
	int n;
	int dataMax;

	// Inputs/Outputs

	int* tabFrequence;
	int* tabDataGM;
	int* tabFrequenceGM;

	// Tools
	size_t sizeTabDataGM;// [octet]
	size_t sizeTabFrequenceGM;// [octet]
    };

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
