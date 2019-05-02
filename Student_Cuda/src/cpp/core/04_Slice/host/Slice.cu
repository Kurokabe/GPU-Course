#include "../../04_Slice/host/Slice.h"

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

Slice::Slice(const Grid& grid, int nbSlice, float* ptrPiHat) :
	ptrPiHat(ptrPiHat), nbSlice(nbSlice)
    {
    this->nTabGM = grid.threadCounts();
    this->sizeTabGM = nTabGM * sizeof(float); // [octet]

    // MM
	{
	//MM(malloc Device)
	    {
	    Device::malloc(&tabGM, sizeTabGM);
	    }
	}

    // Grid
	{
	this->dg = grid.dg;
	this->db = grid.db;
	}
    }

Slice::~Slice(void)
    {
    //MM (device free)
	{
	Device::free(tabGM);
	}
    }

/*--------------------------------------*\
 |*		Methode			*|
 \*-------------------------------------*/

void Slice::run()
    {
    // v1 : promotion tab, reduction coter host
	{
	// emploi uniquemnet du kernel : reductionIntraThread

	reductionIntraThread<<<dg, db>>>(tabGM, nbSlice);

	// Reduction paralle sur cpu du tableau promu ramener coter host
	    {

	    int moitier = nTabGM/2;
	    dg.x = moitier;
	    db.x = 1;
	    while(moitier>=1)
		{
		ecrasementGM<<<dg, db>>>(tabGM, moitier);
		moitier/=2;
		dg.x=moitier;
		}
	    }
	    //MM (Device -> Host)
	    {
	    Device::memcpyDToH(ptrPiHat, tabGM,sizeof(float));
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

	// TODO Slice+
	}
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
