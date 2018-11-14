#include "DamierHueFloat.h"

#include <iostream>
#include <assert.h>

#include "Device.h"



/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Imported	 	*|
 \*-------------------------------------*/

__global__ void damierHueFloat(float* ptrDevPixels, uint w, uint h, DomaineMath domaineMath, uint n, float t);

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

DamierHueFloat::DamierHueFloat(const Grid& grid,uint w, uint h, float dt, uint n, const DomaineMath& domaineMath) :
	Animable_I<float>(grid, w, h, "Damier_Cuda_Hue_float", domaineMath), variateurAnimation(Interval<float>(0, 2 * PI), dt)
    {
    // Inputs
    this->n = n;

    // Tools
    this->t = 0;  // protected dans Animable
    }

DamierHueFloat::~DamierHueFloat()
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
void DamierHueFloat::process(float* ptrDevPixels, uint w, uint h, const DomaineMath& domaineMath)
    {
    damierHueFloat<<<dg,db>>>(ptrDevPixels,w,h,domaineMath,n,t);
    }

/**
 * Override
 * Call periodicly by the API
 */
void DamierHueFloat::animationStep()
    {
    this->t = variateurAnimation.varierAndGet(); // in [0,2pi]
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

