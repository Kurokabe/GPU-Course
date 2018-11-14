#include "Damier.h"

#include <iostream>
#include <assert.h>

#include "Device.h"



/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Imported	 	*|
 \*-------------------------------------*/

__global__ void damier(uchar4* ptrDevPixels, uint w, uint h, DomaineMath domaineMath, uint n, float t);

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

Damier::Damier(const Grid& grid,uint w, uint h, float dt, uint n, const DomaineMath& domaineMath) :
	Animable_I<uchar4>(grid, w, h, "Damier_Cuda_RGBA_uchar4", domaineMath), variateurAnimation(Interval<float>(0, 2 * PI), dt)
    {
    // Inputs
    this->n = n;

    // Tools
    this->t = 0;  // protected dans Animable
    }

Damier::~Damier()
    {
   // rien
    }

/*-------------------------*\
 |*	Methode		    *|
 \*-------------------------*/

/**
 * Override
 * Call periodicly by the API
 */
void Damier::process(uchar4* ptrDevPixels, uint w, uint h, const DomaineMath& domaineMath)
    {
    damier<<<dg,db>>>(ptrDevPixels,w,h,domaineMath,n,t);
    }

/**
 * Override
 * Call periodicly by the API
 */
void Damier::animationStep()
    {
    this->t = variateurAnimation.varierAndGet(); // in [0,2pi]
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

