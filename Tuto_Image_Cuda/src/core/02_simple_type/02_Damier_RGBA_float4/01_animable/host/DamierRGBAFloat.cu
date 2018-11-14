#include "DamierRGBAFloat.h"

#include <iostream>
#include <assert.h>

#include "Device.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Imported	 	*|
 \*-------------------------------------*/

__global__ void damierRGBAFloat(float4* ptrDevPixels, uint w, uint h, DomaineMath domaineMath, uint n, float t);

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

DamierRGBAFloat::DamierRGBAFloat(const Grid& grid,uint w, uint h, float dt, uint n, const DomaineMath& domaineMath) :
	Animable_I<float4>(grid, w, h, "Damier_Cuda_RGBA_float4", domaineMath), variateurAnimation(Interval<float>(0, 2 * PI), dt)
    {
    // Inputs
    this->n = n;

    // Tools
    this->t = 0;  // protected dans Animable
    }

DamierRGBAFloat::~DamierRGBAFloat()
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
void DamierRGBAFloat::process(float4* ptrDevPixels, uint w, uint h, const DomaineMath& domaineMath)
    {
    damierRGBAFloat<<<dg,db>>>(ptrDevPixels,w,h,domaineMath,n,t);
    }

/**
 * Override
 * Call periodicly by the API
 */
void DamierRGBAFloat::animationStep()
    {
    this->t = variateurAnimation.varierAndGet(); // in [0,2pi]
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

