#pragma once

#include <math.h>
#include "MathTools.h"

#include "DomaineMath_CPU.h"
#include "ColorTools_CPU.h"
using namespace cpu;

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

	MandelbrotMath()
	    {
	    //
	    }

	// constructeur copie: pas besoin car pas attribut ptr

	virtual ~MandelbrotMath(void)
	    {
	    // rien
	    }

	/*--------------------------------------*\
	|*		Methode			*|
	 \*-------------------------------------*/

    public:

	void colorXY(uchar4* ptrColorIJ, double x, double y, int n)
	    {
	    // TODO Mandelbrot CPU
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

	int suite(double x, double y, int n)
	    {
	    // TODO Mandelbrot CPU

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
