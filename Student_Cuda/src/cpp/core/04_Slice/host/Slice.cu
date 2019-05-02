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

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
