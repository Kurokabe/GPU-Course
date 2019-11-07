#pragma once

#include <math.h>
#include "MathTools.h"
#include "cudaType_CPU.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class HelloMath
    {

	/*--------------------------------------*\
	|*		Constructor		*|
	 \*-------------------------------------*/

    public:

	HelloMath(int w , int h) :
		h(h), w(w)
	    {
	    // rien
	    }

	HelloMath(const HelloMath& source) :
		HelloMath(source.h, source.w)
	    {
	    // rien
	    }

	/*--------------------------------------*\
	|*		Methodes		*|
	 \*-------------------------------------*/

    public:

	void color(cpu::uchar4* ptrColorIJ , int i , int j , int t)
	    {
	    uchar levelGris = 255 * (i + t) / (float)h;

	    ptrColorIJ->x = levelGris;
	    ptrColorIJ->y = levelGris;
	    ptrColorIJ->z = levelGris;

	    ptrColorIJ->w = 255; // opaque
	    }

    private:

	/*--------------------------------------*\
	|*		Attributs		*|
	 \*-------------------------------------*/

    private:

	// Input
	int w;
	int h;

    };


/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
