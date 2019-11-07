#pragma once

#include <math.h>
#include "MathTools.h"

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

	__host__  __device__
	HelloMath(int w , int h) :
		h(h), w(w)
	    {
	    // rien
	    }

	__host__  __device__
	HelloMath(const HelloMath& source) :
		HelloMath(source.h, source.w)
	    {
	    // rien
	    }

	/*--------------------------------------*\
	|*		Methodes		*|
	 \*-------------------------------------*/

    public:

	__host__  __device__
	void color(uchar4* ptrColorIJ , int i , int j , int t)
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
	int h;
	int w;

    };

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
