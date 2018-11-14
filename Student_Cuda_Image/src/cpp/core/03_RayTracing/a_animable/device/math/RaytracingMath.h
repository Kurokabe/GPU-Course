#pragma once

#include <math.h>
#include "MathTools.h"

#include "Sphere.h"
#define FLOAT_MAX 1e+6

#include "ColorTools_GPU.h"
using namespace gpu;

class RaytracingMath
    {
    public:

	/*--------------------------------------*\
	|*		Constructor		*|
	 \*-------------------------------------*/

	__device__ RaytracingMath(Sphere* ptrDevTabSpheres, int nbSpheres)
	    {
	    this->ptrDevTabSpheres = ptrDevTabSpheres;
	    this->nbSpheres = nbSpheres;
	    }

	// constructeur copie automatique car pas pointeur dans RaytracingMath

	__device__
		             virtual ~RaytracingMath()
	    {
	    // rien
	    }

	/*--------------------------------------*\
	|*		Methodes		*|
	 \*-------------------------------------*/

    public:

	__device__
	void color(uchar4* ptrColorIJ, int i, int j, float t)
	    {
	    float2 xySol;
	    xySol.x = i;
	    xySol.y = j;

	    color(xySol, t, ptrColorIJ); // update colorij

	    ptrColorIJ->w = 255; // opacity facultatif

	    // Conseil:
	    // 		Etape 1 : 	Commencer par afficher une image uniforme grise (128 par exemple)
	    // 				pour valider tout le pipeline en amont
	    //
	    // 		Etape 2:	Puis une fois que l'image grise est valider, attaquer raytracing

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
	void color(const float2& xySol, float t, uchar4* ptrColorXY)
	    {
	    // TODO Raytracing GPU math
	    // process a color for the pixel (x,y)
	    // use methode of classe Sphere
	    }

	/*--------------------------------------*\
	|*		Attributs		*|
	 \*-------------------------------------*/

    private:

	// Input
	Sphere* ptrDevTabSpheres;
	int nbSpheres;

    };

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
