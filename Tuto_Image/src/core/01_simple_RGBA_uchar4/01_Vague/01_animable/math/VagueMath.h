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
class VagueMath
    {

	/*--------------------------------------*\
	 |*		Constructeur		*|
	 \*-------------------------------------*/

    public:

	VagueMath(int w, int h)
	    {
	    this->factor = 4.0f * PI_FLOAT / (float) w;
	    }

	// constructeur copie automatique car pas pointeur dans VagueMath


	virtual ~VagueMath(void)
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
	    uchar levelGris;

	    f(&levelGris, i, j, t); // update levelGris

	    ptrColor->x = levelGris;
	    ptrColor->y = levelGris;
	    ptrColor->z = levelGris;

	    ptrColor->w = 255; // opaque
	    }

    private:

	void f(uchar* ptrLevelGris, int i, int j, float t)
	    {
	    *ptrLevelGris = 255.0f * fabs(sinf(i * factor + t));
	    //*ptrLevelGris=255.0f*( 1+sinf(i * factor + t));
	    }

	/*--------------------------------------*\
	|*		Attribut		*|
	 \*-------------------------------------*/

    private:

	// Inputs
	float factor;

    };

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 /*----------------------------------------------------------------------*/
