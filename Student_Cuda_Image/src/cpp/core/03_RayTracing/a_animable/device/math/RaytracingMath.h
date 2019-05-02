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

	    ptrColorIJ->w = 255; // opacity facultatif
	    ptrColorIJ->x = 0;
	    ptrColorIJ->y = 0;
	    ptrColorIJ->z = 0;

	    color(xySol, t, ptrColorIJ); // update colorij
	    }

    private:

	__device__
	void color(const float2& xySol, float t, uchar4* ptrColorXY)
	    {
	    float minDistance = 9999999999999;
	    int indexClosestSphere = -1;
	    float closestSphereDz;
	    for(int i = 0; i<nbSpheres; ++i)
		{
		Sphere sphere = ptrDevTabSpheres[i];
		float hcarre = sphere.hCarre(xySol);
		if(sphere.isEnDessous(hcarre))
		    {
		    float dz = sphere.dz(hcarre);
		    float distance = sphere.distance(dz);
		    if(distance<minDistance)
			{
			indexClosestSphere = i;
			closestSphereDz = dz;
			}
		    }
		}
	        if(indexClosestSphere>=0)
		    {
		    Sphere closestSphere = ptrDevTabSpheres[indexClosestSphere];
		    float hue = closestSphere.hue(t);
		    float brightness= closestSphere.brightness(closestSphereDz);
		    ColorTools::HSB_TO_RVB(hue, 1, brightness, ptrColorXY);
		    }
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
