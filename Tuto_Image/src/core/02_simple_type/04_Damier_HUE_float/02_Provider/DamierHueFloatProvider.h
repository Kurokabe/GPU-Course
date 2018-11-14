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

	Animable_I<float>* createAnimable(void);

	Image_I* createImageGL(void);

    };



/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

