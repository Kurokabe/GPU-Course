#pragma once

#include "cudaTools.h"

#include "Provider_I_GPU.h"
using namespace gpu;

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

/**
 * Moins performant en rendu que la version rgba_uchar4
 * Version sans interet mais qui contre la flexibilite de l'api
 */
class DamierRGBAFloatProvider: public Provider_I<float4>
    {
    public:

	virtual ~DamierRGBAFloatProvider()
	    {
	    // Rien
	    }

	/*--------------------------------------*\
	 |*		Override		*|
	 \*-------------------------------------*/

	virtual Animable_I<float4>* createAnimable(void);

	virtual Image_I* createImageGL(void);

    };

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

