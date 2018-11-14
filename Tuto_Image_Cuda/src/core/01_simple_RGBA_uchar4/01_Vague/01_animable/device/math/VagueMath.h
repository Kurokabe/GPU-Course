#pragma once

#include <math.h>
#include "MathTools.h"

#include "ColorTools_GPU.h"
using namespace gpu;

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class VagueMath
    {

	/*--------------------------------------*\
	|*		Constructor		*|
	 \*-------------------------------------*/

    public:

	__device__ VagueMath(int w, int h)
	    {
	    this->factor = 4.0f * PI_FLOAT / (float) w;
	    }

	// constructeur copie automatique car pas pointeur dans VagueMath

	__device__
	 virtual ~VagueMath()
	    {
	    // rien
	    }

	/*--------------------------------------*\
	|*		Methodes		*|
	 \*-------------------------------------*/

    public:

	__device__
	void colorIJ(uchar4* ptrColor, int i, int j, float t)
	    {
	    uchar levelGris;

	    f(&levelGris, i, j, t); // update levelGris

	    ptrColor->x = levelGris;
	    ptrColor->y = levelGris;
	    ptrColor->z = levelGris;

	    ptrColor->w = 255; // opaque
	    }

    private:

	__device__
	void f(uchar* ptrLevelGris, int i, int j, float t)
	    {
	    *ptrLevelGris = 255.0f * fabs(sinf(i * factor + t));
	    //*ptrLevelGris=255.0f*( 1+sinf(i * factor + t));
	    }

	/*--------------------------------------*\
	|*		Attributs		*|
	 \*-------------------------------------*/

    private:

	// Tools
	float factor;

    };

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
