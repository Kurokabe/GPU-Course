#include "AddScalar.h"

#include <iostream>
#include <assert.h>

#include "Device.h"

using std::cout;
using std::endl;

 /*---------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

 /*-------------------------------------*\
 |*		Imported	 	*|
 \*-------------------------------------*/

extern __global__ void addScalar(float a, float b, float* ptrDevC);

 /*---------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

 /*-------------------------------------*\
 |*		Constructeur		*|
 \*-------------------------------------*/

AddScalar::AddScalar(float a, float b, float* ptrC) :
	a(a), b(b), ptrC(ptrC)
    {
    this->sizeFloat = sizeof(float); // [octet]

    // MM
	{
	Device::malloc(&ptrDevC, sizeFloat);
	}
    }

AddScalar::~AddScalar(void)
    {
    //MM
	{
	Device::free (ptrDevC);
	}
    }

 /*-------------------------------------*\
 |*		Methode			*|
 \*-------------------------------------*/

void AddScalar::run()
    {
    // 1 seul thread suffit
    dim3 dg(1,1,1);
    dim3 db(1,1,1);
    assert(dg.x*dg.y*dg.z*db.x*db.y*db.z==1);

    addScalar<<<dg,db>>>(a, b, ptrDevC);// assynchrone

    //Device::synchronize(); // Debug : necessaire only pour printf sur device

    // MM (Device -> Host)
	{
	Device::memcpyDToH(ptrC, ptrDevC, sizeFloat); // barriere synchronisation implicite
	}
    }

 /*-------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

 /*---------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
