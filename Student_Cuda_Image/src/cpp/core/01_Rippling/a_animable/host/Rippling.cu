#include "Rippling.h"

#include <iostream>
#include <assert.h>

#include "Device.h"
#include <assert.h>

using std::cout;
using std::endl;

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Imported	 	*|
 \*-------------------------------------*/

extern __global__ void rippling(uchar4* ptrDevPixels,uint w, uint h,float t);

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

/*-------------------------*\
 |*	Constructeur	    *|
 \*-------------------------*/

Rippling::Rippling(const Grid& grid, uint w, uint h, float dt) :
	Animable_I<uchar4>(grid, w, h, "Rippling_Cuda_RGBA_uchar4")
    {
    assert(w == h); // specific rippling

    // Animation
    this->dt = dt;
    this->t = 0; // protected dans Animable
    }

Rippling::~Rippling()
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
 * Note : domaineMath pas use car image pas zoomable
 */
void Rippling::process(uchar4* ptrDevPixels, uint w, uint h, const DomaineMath& domaineMath)
    {
    // TODO Rippling GPU
    // lancer le kernel avec <<<dg,db>>>
    // le kernel est importer ci-dessus (ligne 19)
    rippling<<<dg, db>>>(ptrDevPixels, w, h, t);
    }

/**
 * Override
 * Call periodicly by the API
 */
void Rippling::animationStep()
    {
    t += dt;
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

