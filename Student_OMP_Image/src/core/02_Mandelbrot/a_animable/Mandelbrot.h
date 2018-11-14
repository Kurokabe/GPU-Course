#pragma once


#include "DomaineMath_CPU.h"
#include "cudaType_CPU.h"
#include "Animable_I_CPU.h"
#include "Variateur_CPU.h"
using namespace cpu;

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class Mandelbrot: public Animable_I<uchar4>
    {

	/*--------------------------------------*\
	 |*		Constructeur		*|
	 \*-------------------------------------*/

    public:

	Mandelbrot(uint w, uint h,const DomaineMath& domaineMath, int nMin, int nMax);

	virtual ~Mandelbrot(void);

	/*--------------------------------------*\
	 |*		Methode			*|
	 \*-------------------------------------*/

    public:

	/*-------------------------*\
	|*   Override Animable_I   *|
	 \*------------------------*/


	/**
	 * Call periodicly by the api
	 * Override
	 * code naturel omp
	 * domaineMath use car image zoomable
	 */
	virtual void processEntrelacementOMP(uchar4* ptrTabPixels, uint w, uint h, const DomaineMath& domaineMath);

	/**
	 * Call periodicly by the api
	 * Override
	 * code entrainement cuda
	 * domaineMath use car image zoomable
	 */
	virtual void processForAutoOMP(uchar4* ptrTabPixels, uint w, uint h, const DomaineMath& domaineMath);

	/**
	 * Call periodicly by the api
	 */
	virtual void animationStep();

	/*--------------------------------------*\
	|*		Attribut		*|
	 \*-------------------------------------*/

    private:

	// Inputs
	int nMin;
	int nMax;

	// Tools
	Variateur<int> variateurAnimation;

    };

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 /*----------------------------------------------------------------------*/
