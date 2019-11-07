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

class Mandelbrot3DMath_RGBA
    {

	/*--------------------------------------*\
	|*		Constructor		*|
	 \*-------------------------------------*/

    public:

	__device__ Mandelbrot3DMath_RGBA(int n) :
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
	float z(float h01)
	    {
	    const int M = 8;//1 ou 8 (ici fixe)
	    return logs(h01, M) + 0.5f;
	    }

	__device__
	float logs(float h01, const int M)
	    {
	    float z = h01;
	    for (int i = 0; i <= M; i++)
		{
		z = log(z + 1.0f);
		}
	    return z;
	    }

	__device__
	void sommetXY(float3* ptrSommet, float x, float y, float t)
	    {
	    float z = f(x, y, t);

	    ptrSommet->x = x;
	    ptrSommet->y = y;
	    ptrSommet->z = z;
	    }

	__device__
	void colorXY(uchar4* ptrColorRGBA, float x, float y, float* h, float t)
	    {
	    /*calibreur.calibrer(&z);
	    float hue01 = z;
	    ColorTools::HSB_TO_RVB(hue01, ptrColorRGBA);*/
	    float n = t;
	    int k = suite(x, y, n);
	    if(k>=n)
		{
		ptrColorRGBA->x = 0;
		ptrColorRGBA->y = 0;
		ptrColorRGBA->z = 0;
		ptrColorRGBA->w = 255;
		}
	    else
		{
		*h = k/(float)n;
		ColorTools::HSB_TO_RVB(*h, ptrColorRGBA);
		}
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


    private:

	__device__
	int suite(float x, float y, int n)
	    {
	int i = 0;
	float a = 0;
	float b = 0;
	float aCopy = a;
	while(i<=n && converge(a, b))
	    {
	    aCopy = a;
	    a = a*a-b*b+x;
	    b = 2*aCopy*b+y;
	    ++i;
	    }
	return i;
	    }

	__device__
	bool converge(float x, float y)
	    {
	    return x*x + y*y <= 4;
	    }

    };

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
