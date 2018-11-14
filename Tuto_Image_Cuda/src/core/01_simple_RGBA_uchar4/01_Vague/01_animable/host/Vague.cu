#include "Vague.h"

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

extern __global__ void vague(uchar4* ptrDevPixels,uint w, uint h,float t);

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

Vague::Vague(const Grid& grid, uint w, uint h, float dt) :
	Animable_I<uchar4>(grid, w, h, "Vague_Cuda_RGBA_uchar4")
    {
    // Inputs
    this->dt = dt;

    // Tools
    this->t = 0; // protected dans Animable
    }

Vague::~Vague()
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
void Vague::process(uchar4* ptrDevPixels, uint w, uint h, const DomaineMath& domaineMath)
    {
    vague<<<dg,db>>>(ptrDevPixels,w,h,t);
    }

/**
 * Override
 * Call periodicly by the API
 */
void Vague::animationStep()
    {
    t += dt;
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

