#include "Damier3DMath_RGBA.h"
#include "Indice2D.h"
#include "IndiceTools_GPU.h"
#include "DomainMath3D_GPU.h"
#include "cudaTools.h"
#include "Device.h"

using namespace gpu;

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

__global__ void damier3DCuda(float3* ptrDevVerticesCoord, uchar4* ptrDevVerticesColor, int w, int h, DomainMath3D domaineMath, int n, float t);

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

/**
 * w nbPoint en x
 * h nbPoint en y
 */
__global__ void damier3DCuda(float3* ptrDevVerticesCoord, uchar4* ptrDevVerticesColor, int w, int h, DomainMath3D domaineMath, int n, float t)
    {
    Damier3DMath_RGBA damierMath(n);

    const int TID = Indice2D::tid();
    const int NB_THREAD = Indice2D::nbThread();

    const int WH = w * h;

    uchar4 color;
    float3 sommet;

    float x;
    float y;
    float DX;
    float DY;

    int vertexI;
    int vertexJ;

    domaineMath.delta(w,h,&DX,&DY);

    int s = TID;
    while (s < WH)
	{
	IndiceTools::toIJ(s, w, &vertexI, &vertexJ); // update (vertexI, vertexJ)

	domaineMath.toXY(DX,DY,vertexI,vertexJ,&x,&y);

	damierMath.sommetXY(&sommet,x,y,t); // update sommet
	damierMath.colorZ(&color, sommet.z); // update color

	ptrDevVerticesColor[s] = color;
	ptrDevVerticesCoord[s] = sommet;

	s += NB_THREAD;
	}

    }


/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

