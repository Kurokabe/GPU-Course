#pragma once

#include "Animable_I_CPU.h"
#include "Provider_I_CPU.h"

using namespace cpu;

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class DamierHSBAFloatProvider: public Provider_I<float4>
    {
    public:

	virtual ~DamierHSBAFloatProvider()
	    {
	    // Rien
	    }

	/*--------------------------------------*\
	 |*		Override		*|
	 \*-------------------------------------*/

	Animable_I<float4>* createAnimable(void);

	Image_I* createImageGL(void);

    };



/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

