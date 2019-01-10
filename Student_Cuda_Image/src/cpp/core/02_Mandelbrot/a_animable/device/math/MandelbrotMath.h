#pragma once

#include <math.h>
#include "MathTools.h"

#include "DomaineMath_GPU.h"
#include "ColorTools_GPU.h"
using namespace gpu;

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class MandelbrotMath
    {
	/*--------------------------------------*\
	|*		Constructeur		*|
	 \*-------------------------------------*/

    public:

	__device__ MandelbrotMath()
	    {
	    //
	    }

	// constructeur copie: pas besoin car pas attribut ptr

	__device__
	 virtual ~MandelbrotMath(void)
	    {
	    // rien
	    }

	/*--------------------------------------*\
	|*		Methode			*|
	 \*-------------------------------------*/

    public:

	__device__
	void colorXY(uchar4* ptrColorIJ, float x, float y, int n)
	    {
	    int k = suite(x, y, n);
	    if(k>=n) {
		ptrColorIJ->x = 0;
		ptrColorIJ->y = 0;
		ptrColorIJ->z = 0;
		ptrColorIJ->w = 255;
	    } else {
		float h = k/(float)n;
		ColorTools::HSB_TO_RVB(h, ptrColorIJ);
	    }

	    // TODO Mandelbrot GPU
	    // Calculer la suite en (x,y)
	    // Colorier

	    // Conseil:
	    // 		Etape 1 : 	Commencer par afficher une image uniforme grise (128 par exemple)
	    // 				pour valider tout le pipeline en amont
	    //
	    // 		Etape 2:	Puis une fois que l'image grise est valider, attaquer montecarlo

	    // debug temp
	    //		{
	    //		ptrColorIJ->x = 128;
	    //		ptrColorIJ->y = 128;
	    //		ptrColorIJ->z = 128;
	    //		ptrColorIJ->w = 255; // opacity facultatif
	    //		}

	    }

    private:

	__device__
	int suite(float x, float y, int n)
	    {
	    int i = 0;
	    float z = 0;
	    float a = 0;
	    float b = 0;
	    float aCopy = a;
	    while(i<=n && converge(a, b)) {
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

	/*--------------------------------------*\
	|*		Attribut		*|
	 \*-------------------------------------*/

    private:

	// rien

    };

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
