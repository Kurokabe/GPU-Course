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

class VagueGrayMath
    {

	/*--------------------------------------*\
	|*		Constructor		*|
	 \*-------------------------------------*/

    public:

	__device__ VagueGrayMath(int w, int h)
	    {
	    this->factor = 4.0f * PI_FLOAT / (float) w;
	    }

	// constructeur copie automatique car pas pointeur dans VagueMath

	__device__
	 virtual ~VagueGrayMath()
	    {
	    // rien
	    }

	/*--------------------------------------*\
	|*		Methodes		*|
	 \*-------------------------------------*/

    public:

	__device__
	void colorIJ(uchar* ptrColor, int i, int j, float t)
	    {
	    *ptrColor = 255.0f * fabs(sinf(i * factor + t));
	    }

    private:


	/*--------------------------------------*\
	|*		Attributs		*|
	 \*-------------------------------------*/

    private:

	float factor;

    };

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
