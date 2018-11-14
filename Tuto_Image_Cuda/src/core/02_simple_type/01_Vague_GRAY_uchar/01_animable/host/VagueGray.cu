#include "VagueGray.h"

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

extern __global__ void vagueGray(uchar* ptrDevPixels,uint w, uint h,float t);

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

/*-------------------------*\
 |*	Constructeur	    *|
 \*-------------------------*/

VagueGray::VagueGray(const Grid& grid, uint w, uint h, float dt) :
	Animable_I<uchar>(grid, w, h, "Vague_Cuda_GRAY_uchar")
    {
    // Inputs
    this->dt = dt;

    // Tools
    this->t = 0; // protected dans Animable
    }

VagueGray::~VagueGray()
    {
    // rien
    }

/*-------------------------*\
 |*	Methode		    *|
 \*-------------------------*/

/**
 * Override
 * Call periodicly by the API
 *
 * Note : domaineMath pas use car pas zoomable
 */
void VagueGray::process(uchar* ptrDevPixels, uint w, uint h, const DomaineMath& domaineMath)
    {
    vagueGray<<<dg,db>>>(ptrDevPixels,w,h,t);
    }

/**
 * Override
 * Call periodicly by the API
 */
void VagueGray::animationStep()
    {
    t += dt;
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

