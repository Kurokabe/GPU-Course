#pragma once

#include <math.h>
#include "MathTools.h"

#include "ColorTools_CPU.h"
using namespace cpu;

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class RipplingMath
    {
	/*--------------------------------------*\
	|*		Constructeur		*|
	 \*-------------------------------------*/

    public:

	RipplingMath(uint w, uint h)
	    {
	    this->dim2 = w / 2.f;
	    }

	// constructeur copie: pas besoin car pas attribut ptr

	virtual ~RipplingMath(void)
	    {
	    // rien
	    }

	/*--------------------------------------*\
	|*		Methode			*|
	 \*-------------------------------------*/

    public:

	void colorIJ(uchar4* ptrColorIJ, int i, int j, float t)
	    {
	    uchar levelGris;

	    f(j, i, t, &levelGris); // update levelgray

	    ptrColorIJ->x = levelGris;
	    ptrColorIJ->y = levelGris;
	    ptrColorIJ->z = levelGris;

	    ptrColorIJ->w = 255; //opaque

	    // Conseil:
	    // 		Etape 1 : 	Commencer par afficher une image uniforme grise (128 par exemple)
	    // 				pour valider tout le pipeline en amont
	    //
	    // 		Etape 2:	Puis une fois que l'image grise est valider, attaquer rippling

	    // debug temp
	    //		{
	    //		ptrColorIJ->x = 128;
	    //		ptrColorIJ->y = 128;
	    //		ptrColorIJ->z = 128;
	    //		ptrColorIJ->w = 255; // opacity facultatif
	    //		}
	    }

    private:

	void f(int i, int j, float t, uchar* ptrlevelGris)
	    {
	    float result;
	    dij(i, j, &result); // warning : dij return void. Ne peut pas etre "imbriquer dans une fonction"

	    result = result / 10;
	    // TODO Rippling CPU : cf formules math rippling.pdf
	    }

	void dij(int i, int j, float* ptrResult)
	    {
	    //TODO Rippling CPU cf fonction math pdf

	    // Ne pas utiliser la fonction pow pour elever au carrer !
	    // Utiliser l'opérateur *
	    }

	/*--------------------------------------*\
	|*		Attribut			*|
	 \*-------------------------------------*/

    private:

// Tools
	float dim2;

    };

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
