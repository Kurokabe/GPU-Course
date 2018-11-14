#include "SliceNaif.h"

#include <iostream>
#include <assert.h>

#include "Device.h"

using std::cout;
using std::endl;

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Imported	 	*|
 \*-------------------------------------*/

extern __global__ void reductionIntraThread(float* tabGM,int nbSlice);
extern __global__ void ecrasementGM(float* tabGM, int moitier);

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Constructeur			*|
 \*-------------------------------------*/

SliceNaif::SliceNaif(const Grid& grid, int nbSlice, float* ptrPiHat) :
	ptrPiHat(ptrPiHat), nbSlice(nbSlice)
    {
    this->nTabGM = grid.threadCounts();
    this->sizeTabGM = nTabGM * sizeof(float); // [octet]

    // MM
	{
	// TODO SliceNaif
	}

    // Grid
	{
	this->dg = grid.dg;
	this->db = grid.db;
	}
    }

SliceNaif::~SliceNaif(void)
    {
    //MM (device free)
	{
	// TODO SliceNaif
	}
    }

/*--------------------------------------*\
 |*		Methode			*|
 \*-------------------------------------*/

void SliceNaif::run()
    {
    // v1 : promotion tab, reduction coter host
	{
	// emploi uniquemnet du kernel : reductionIntraThread

	// TODO SliceNaif

	// Reduction paralle sur cpu du tableau promu ramener coter host
	    {
	    // TODO SliceNaif
	    }
	}

    // v2 : promotion tab, reduction coter device en GM
	{
	// emploi de deux kernels:
	//	reductionIntraThread
	//	ecrasementGM
	//
	// Warning:
	//	(W1) ecrasementGM doit etre lancer dans une boucle coter host
	//	(W2) On serait tenter de realiser cette boucle coter device, c'est techniquement possible, mais pose de gros problème de synchronisation!
	//
	// Note:
	//	Attendez la version de slice en SM pour un code 100% parallel sur GPU, sans boucle sur CPU.


	// TODO SliceNaif+
	}
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
