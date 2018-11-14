#include "Indice2D.h"
#include "cudaTools.h"
#include "Device.h"

#include "DamierHSBAFloatMath.h"

#include "IndiceTools_GPU.h"
#include "DomaineMath_GPU.h"
using namespace gpu;

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Imported	 	*|
 \*-------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

__global__ void damierHSBAFloat(float4* ptrDevPixels, uint w, uint h, DomaineMath domaineMath, uint n, float t);

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

__global__ void damierHSBAFloat(float4* ptrDevPixels, uint w, uint h, DomaineMath domaineMath, uint n, float t)
    {
    DamierHSBAFloatMath damierHSBAFloatMath = DamierHSBAFloatMath(n);

    const int TID = Indice2D::tid();
    const int NB_THREAD = Indice2D::nbThread();
    const int WH = w * h;

    double x;
    double y;

    int i; // in [0,h[
    int j; // in [0,w[

    int s = TID;
    while (s < WH)
	{
	IndiceTools::toIJ(s, w, &i, &j); // update (i, j)

	// (i,j) domaine ecran
	// (x,y) domaine math
	domaineMath.toXY(i, j, &x, &y); //  (i,j) -> (x,y)

	damierHSBAFloatMath.colorXY(&ptrDevPixels[s], x, y, t); // update ptrDevPixels[s]

	s += NB_THREAD;
	}

    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

