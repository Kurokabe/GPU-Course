#include "Mandelbrot.h"

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

extern __global__ void mandelbrot(uchar4* ptrDevPixels, uint w, uint h,DomaineMath domaineMath, int n);

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*-------------------------*\
 |*	Constructeur	    *|
 \*-------------------------*/

Mandelbrot::Mandelbrot(const Grid& grid, uint w, uint h, const DomaineMath& domaineMath, int nMin, int nMax) :
	Animable_I<uchar4>(grid, w, h, "Mandelbrot_Cuda_RGBA_uchar4", domaineMath), variateurT(Interval<int>(nMin, nMax), 1)
    {
    // Inputs/animation
    this->nMin = nMin;
    this->nMax = nMax;

    // Tools
    this->t = nMin;
    }

Mandelbrot::~Mandelbrot()
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
void Mandelbrot::process(uchar4* ptrDevPixels, uint w, uint h, const DomaineMath& domaineMath)
    {
    int n = t;
    mandelbrot<<<dg, db>>>(ptrDevPixels, w, h, domaineMath, n);
    }

/**
 * Override
 * Call periodicly by the API
 */
void Mandelbrot::animationStep()
    {
    this->t = variateurT.varierAndGet();
    }

void Mandelbrot::setNMinNMax(int nMin, int nMax)
    {
    this->nMin = nMin;
    this->nMax = nMax;
    this->variateurT = Variateur<int> (Interval<int>(this->nMin, this->nMax), 1);
    }
/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

