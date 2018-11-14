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
	    // TODO Mandelbrot GPU

	    // Calculer la suite en (x,y) jusqu'à n, à moins que critere arret soit atteint avant
	    // return le nombre d'element de la suite calculer
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
