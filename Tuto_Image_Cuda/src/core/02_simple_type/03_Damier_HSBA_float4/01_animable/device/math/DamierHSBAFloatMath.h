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

class DamierHSBAFloatMath
    {

	/*--------------------------------------*\
	|*		Constructor		*|
	 \*-------------------------------------*/

    public:

	__device__ DamierHSBAFloatMath(int n) :
		calibreur(Interval<float>(-1, 1), Interval<float>(0, 1))
	    {
	    this->n = n;
	    }

	// constructeur copie automatique car pas pointeur dans
	//	DamierMath
	// 	calibreur
	// 	IntervalF

	__device__
		  virtual ~DamierHSBAFloatMath()
	    {
	    // rien
	    }

	/*--------------------------------------*\
	|*		Methodes		*|
	 \*-------------------------------------*/

    public:

	__device__
	void colorXY(float4* ptrColor, float x, float y, float t)
	    {
	    float z = f(x, y, t);

	    float hue01 = z;
	    calibreur.calibrer(&hue01);


	    ptrColor->x = hue01; // g
	    ptrColor->y = 1.0f; // s
	    ptrColor->z = 1.0f; //b
	    ptrColor->w = 1.0f; // opaque
	    }

    private:

	__device__
	float f(float x, float y, float t)
	    {
	    return sinf(x * n + t) * cosf(y * n + t);
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
