#include "AddVector.h"

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

extern __global__ void addVector(float* ptrDevV1, float* ptrDevV2, float* ptrDevW,int n);
extern __global__ void addVector11(float* ptrDevV1, float* ptrDevV2, float* ptrDevW, int n);

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Constructeur			*|
 \*-------------------------------------*/

AddVector::AddVector(const Grid& grid, float* ptrV1, float* ptrV2, float* ptrW, int n) :
	ptrV1(ptrV1), ptrV2(ptrV2), ptrW(ptrW), n(n)
    {
    this->sizeVector= n * sizeof(float); // octet

    // MM
	{

	// MM (malloc Device)
	    {
	    Device::malloc(&ptrDevV1, sizeVector);
	    Device::malloc(&ptrDevV2, sizeVector);
	    Device::malloc(&ptrDevW, sizeVector);
	    }

	// MM (copy Host->Device)
	    {
	    Device::memcpyHToD(ptrDevV1, ptrV1, sizeVector);
	    Device::memcpyHToD(ptrDevV2, ptrV2, sizeVector);
	    }

	}

    // Grid
	{
	this->dg = grid.dg;
	this->db = grid.db;
	}
    }

AddVector::~AddVector(void)
    {
    //MM (device free)
	{
	Device::free(ptrDevV1);
	Device::free(ptrDevV2);
	Device::free(ptrDevW);
	}
    }

/*--------------------------------------*\
 |*		Methode			*|
 \*-------------------------------------*/

void AddVector::run()
    {
    //v1 pattern entrelacement
    addVector<<<dg,db>>>(ptrDevV1, ptrDevV2, ptrDevW, n);// assynchrone

    //v2 pattern 1<-->1
	{
	//assert(db.x*db.y*db.z*dg.x*dg.y*dg.z==n);
	//addVector11<<<dg,db>>>(ptrDevV1, ptrDevV2, ptrDevW, n); // assynchrone
	}

    //Device::synchronize(); // Temp,debug, only for printf in  GPU, sinon pas necessaire

    // MM (Device -> Host)
	{
	Device::memcpyDToH(ptrW, ptrDevW, sizeVector);
	}
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
