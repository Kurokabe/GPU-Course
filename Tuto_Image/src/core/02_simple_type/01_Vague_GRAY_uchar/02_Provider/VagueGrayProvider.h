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

class VagueGrayProvider: public Provider_I<uchar>
    {
    public:

	virtual ~VagueGrayProvider()
	    {
	    // Rien
	    }

	/*--------------------------------------*\
	 |*		Override		*|
	 \*-------------------------------------*/

	Animable_I<uchar>* createAnimable(void);

	Image_I* createImageGL(void);

    };



/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

