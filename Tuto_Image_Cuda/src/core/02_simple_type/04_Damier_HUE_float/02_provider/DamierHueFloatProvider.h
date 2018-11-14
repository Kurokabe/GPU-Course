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
 * Plus performant en rendu que la version rgba_uchar4
 * Plus performant en rendu que la version hsba_float4
 */
class DamierHueFloatProvider: public Provider_I<float>
    {
    public:

	virtual ~DamierHueFloatProvider()
	    {
	    // Rien
	    }

	/*--------------------------------------*\
	 |*		Override		*|
	 \*-------------------------------------*/

	virtual Animable_I<float>* createAnimable(void);

	virtual Image_I* createImageGL(void);

    };

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

