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
class VagueGrayMath
    {

	/*--------------------------------------*\
	 |*		Constructeur		*|
	 \*-------------------------------------*/

    public:

	VagueGrayMath(int w, int h)
	    {
	    this->factor = 4.0f * PI_FLOAT / (float) w;
	    }

	// constructeur copie automatique car pas pointeur dans VagueMath


	virtual ~VagueGrayMath(void)
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
	void colorIJ(uchar* ptrColor, int i, int j, float t)
	    {
	    *ptrColor = 255.0f * fabs(sinf(i * factor + t));
	    }

    private:

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
