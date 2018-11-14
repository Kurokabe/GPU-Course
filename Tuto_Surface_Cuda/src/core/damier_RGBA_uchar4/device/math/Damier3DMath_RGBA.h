#pragma once

#include <math.h>

#include "Calibreur_GPU.h"
#include "ColorTools_GPU.h"

using namespace gpu;

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class Damier3DMath_RGBA
    {

	/*--------------------------------------*\
	|*		Constructor		*|
	 \*-------------------------------------*/

    public:

	__device__ Damier3DMath_RGBA(int n) :
		calibreur(Interval<float>(-1, 1), Interval<float>(0, 0.9))
	    {
	    this->n = n;
	    }

	// constructeur copie automatique car pas pointeur dans
	//	DamierMath
	// 	calibreur
	// 	IntervalF

	/*--------------------------------------*\
	|*		Methodes		*|
	 \*-------------------------------------*/

    public:

	__device__
	void sommetXY(float3* ptrSommet, float x, float y, float t)
	    {
	    float z = f(x, y, t);

	    ptrSommet->x = x;
	    ptrSommet->y = y;
	    ptrSommet->z = z;
	    }

	__device__
	void colorZ(uchar4* ptrColorRGBA, float z)
	    {
	    calibreur.calibrer(&z);
	    float hue01 = z;
	    ColorTools::HSB_TO_RVB(hue01, ptrColorRGBA);
	    }

    private:

	__device__
	float f(float x, float y, float t)
	    {
	    return sin(x * n + t) * cos(y * n + t);
	    }

	/*--------------------------------------*\
	|*		Attributs		*|
	 \*-------------------------------------*/

    private:

	// Input
	int n;

	// Tools
	Calibreur<float> calibreur;

    };

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
