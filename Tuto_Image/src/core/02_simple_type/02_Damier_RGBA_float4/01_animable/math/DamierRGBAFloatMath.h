#pragma once

#include <math.h>
#include "MathTools.h"

#include "Calibreur_CPU.h"
#include "ColorTools_CPU.h"
using namespace cpu;

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class DamierRGBAFloatMath
    {

	/*--------------------------------------*\
	|*		Constructor		*|
	 \*-------------------------------------*/

    public:

	DamierRGBAFloatMath(uint n) :
		calibreur(Interval<float>(-1, 1), Interval<float>(0, 1))
	    {
	    this->n = n;
	    }

	// constructeur copie automatique car pas pointeur dans
	//	DamierMath
	// 	calibreur
	// 	IntervalF

	virtual ~DamierRGBAFloatMath()
	    {
	    // rien
	    }

	/*--------------------------------------*\
	|*		Methodes		*|
	 \*-------------------------------------*/

    public:

	void colorXY(float4* ptrColor, float x, float y, float t)
	    {
	    float z = f(x, y, t);

	    float hue01 = z;
	    calibreur.calibrer(&hue01);


	    ColorTools::HSB_TO_RVB(hue01, ptrColor); // update color

	    ptrColor->w = 255; // opaque
	    }

    private:

	float f(float x, float y, float t)
	    {
	    return sinf(x * n + t) * cosf(y * n + t);
	    }

	/*--------------------------------------*\
	|*		Attributs		*|
	 \*-------------------------------------*/

    private:

	// Input
	uint n;

	// Tools
	Calibreur<float> calibreur;

    };

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
