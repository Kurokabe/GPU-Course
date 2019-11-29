#pragma once

#include <math.h>
#include "MathTools.h"

#include "ColorTools_GPU.h"
#include "Calibreur_GPU.h"
using namespace gpu;

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class HeatTransferMath
    {
	/*--------------------------------------*\
	|*		Constructeur		*|
	 \*-------------------------------------*/

    public:

	__device__ HeatTransferMath(uint w, uint h)
	    {
	    this->dim2 = w / 2.f;
	    }

	// constructeur copie: pas besoin car pas attribut ptr

	__device__
	       virtual ~HeatTransferMath(void)
	    {
	    // rien
	    }

	/*--------------------------------------*\
	|*		Methode			*|
	 \*-------------------------------------*/

    public:

	__device__
	float model1(float T, float n, float e, float s, float w)
	    {

	    return T + k * (n + e + s + w - 4 * T);
	    }

	__device__
	void ecrasement(float *ptrDevHeater, float *ptrDevImage, int s)
	    {
	    if (ptrDevHeater[s] != 0)
		{
		ptrDevImage[s] = ptrDevHeater[s];
		}
	    }

	__device__
	void temperatureToRVB(float T, Calibreur<float> &calibreur, uchar4 *color)
	    {
	    float hue = T;
	    calibreur.calibrer(&hue);

	    ColorTools::HSB_TO_RVB(hue, color); //modifie color
	    }
	/*--------------------------------------*\
	|*		Attribut			*|
	 \*-------------------------------------*/

    private:

	// Tools
	float dim2;
	float k = 0.1;

    };

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
