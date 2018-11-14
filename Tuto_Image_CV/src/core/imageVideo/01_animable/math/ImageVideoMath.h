#pragma once

#include <math.h>
#include "MathTools.h"

#include "cudaType_CPU.h"
#include "ColorTools_CPU.h"
using namespace cpu;
/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

/**
 * Dans un header only pour preparer la version cuda
 */
class ImageVideoMath
    {

	/*--------------------------------------*\
	 |*		Constructeur		*|
	 \*-------------------------------------*/

    public:

	ImageVideoMath(int w, int h)
	    {
	    this->POIDS = 1 / (double) 3;
	    }

	// constructeur copie automatique car pas pointeur dans VagueMath

	virtual ~ImageVideoMath(void)
	    {
	    //rien
	    }

	/*--------------------------------------*\
	 |*		Methode			*|
	 \*-------------------------------------*/

    public:

	/**
	 * i in [0,h[
	 * j in [0,w[
	 */
	void colorIJ(uchar4* ptrColor, int i, int j, float t)
	    {
	    uchar r = ptrColor->x;
	    uchar g = ptrColor->y;
	    uchar b = ptrColor->z;

	    uchar levelGris = r * POIDS + g * POIDS + b * POIDS;

	    ptrColor->x = levelGris;
	    ptrColor->y = levelGris;
	    ptrColor->z = levelGris;

	    ptrColor->w = 255; // opaque
	    }

    private:

	/*--------------------------------------*\
	|*		Attribut		*|
	 \*-------------------------------------*/

    private:

	// Tools
	float POIDS;

    };

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 /*----------------------------------------------------------------------*/
