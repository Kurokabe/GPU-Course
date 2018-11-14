#include <iostream>
#include <omp.h>
#include <assert.h>
#include "OmpTools.h"

#include "RipplingMath.h"
#include "Rippling.h"

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

Rippling::Rippling(uint w, uint h, float dt) :
	Animable_I<uchar4>(w, h, "Rippling_OMP_rgba_uchar4")
    {
    // Input
    this->dt = dt;  // animation

    // Animation
    this->t = 0;					// protected dans super classe Animable

    // Tools
    this->parallelPatern = ParallelPatern::OMP_MIXTE;   // protected dans super classe Animable

    // OMP
    cout << "\n[Rippling] : OMP : nbThread = " << this->nbThread << endl; // protected dans super classe Animable
    }

Rippling::~Rippling(void)
    {
    // rien
    }

/*--------------------------------------*\
 |*		Methodes		*|
 \*-------------------------------------*/

/**
 * Override
 * Call periodicly by the api
 */
void Rippling::animationStep()
    {
    t += dt;
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/**
 * Override (code naturel omp)
 * Image non zoomable : domaineMath pas use ici
 */
void Rippling::processForAutoOMP(uchar4* ptrTabPixels, uint w, uint h, const DomaineMath& domaineMath)
    {
    // TODO Rippling CPU
    assert(false);// to delete once implement
    }

/**
 * Override (code entrainement cuda)
 * Image non zoomable : domaineMath pas use ici
 */
void Rippling::processEntrelacementOMP(uchar4* ptrTabPixels, uint w, uint h, const DomaineMath& domaineMath)
    {
    // TODO Rippling CPU
    assert(false);// to delete once implement
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

