#include <iostream>
#include <omp.h>
#include <assert.h>
#include "OmpTools.h"

#include "MandelbrotMath.h"
#include "Mandelbrot.h"

#include "IndiceTools_CPU.h"
using cpu::IndiceTools;

using std::cout;
using std::endl;

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Constructeur		*|
 \*-------------------------------------*/

Mandelbrot::Mandelbrot(uint w, uint h, const DomaineMath& domaineMath, int nMin, int nMax) :
	Animable_I<uchar4>(w, h, "MandelbrotOMP_rgba_uchar4", domaineMath), variateurAnimation(Interval<int>(nMin, nMax), 1)
    {
    // Animation
    this->t = nMin;					// protected dans super classe Animable

    // Tools
    this->parallelPatern = ParallelPatern::OMP_MIXTE;   // protected dans super classe Animable

    // OMP
    cout << "\n[Mandelbrot] : OMP : nbThread = " << this->nbThread << endl; // protected dans super classe Animable
    }

Mandelbrot::~Mandelbrot(void)
    {
    // rien
    }

/*--------------------------------------*\
 |*		Methode			*|
 \*-------------------------------------*/

/**
 * Override
 * Call periodicly by the api
 */
void Mandelbrot::animationStep()
    {
    this->t = variateurAnimation.varierAndGet();
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/**
 * Call periodicly by the api
 * Override
 * code naturel omp
 * domaineMath use car image zoomable
 */
void Mandelbrot::processForAutoOMP(uchar4* ptrTabPixels, uint w, uint h, const DomaineMath& domaineMath)
    {
    int n = t;

    MandelbrotMath mandelbrotMath; // warning syntaxe juste !
    //MandelbrotMath mandelbrotMath();// warning syntaxe fausse !

    // TODO Mandelbrot CPU

    // (i,j) -> s
    // (i,j) -> (x,y)

    assert(false);       // to delete once implement
    }

/**
 * Call periodicly by the api
 * Override
 * code entrainement cuda
 * domaineMath use car image zoomable
 */
void Mandelbrot::processEntrelacementOMP(uchar4* ptrTabPixels, uint w, uint h, const DomaineMath& domaineMath)
    {
    int n = t;

    MandelbrotMath mandelbrotMath; // warning syntaxe juste !
    //MandelbrotMath mandelbrotMath();// warning syntaxe fausse !

    // TODO Mandelbrot CPU
    // Entrelacement
    // s -> (i,j) -> (x,y)
    // appeler colorXY
    assert(false);         // to delete once implement
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

