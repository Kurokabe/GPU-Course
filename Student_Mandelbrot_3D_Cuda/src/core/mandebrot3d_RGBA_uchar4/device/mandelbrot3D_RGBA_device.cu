#include "Indice2D.h"
#include "IndiceTools_GPU.h"
#include "DomainMath3D_GPU.h"
#include "cudaTools.h"
#include "Device.h"

#include "../../mandebrot3d_RGBA_uchar4/device/math/Mandelbrot3DMath_RGBA.h"

using namespace gpu;

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

__global__ void mandelbrot3DCuda(float3* ptrDevVerticesCoord, uchar4* ptrDevVerticesColor, int w, int h, DomainMath3D domaineMath, int n);

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
__global__ void mandelbrot3DCuda(float3* ptrDevVerticesCoord, uchar4* ptrDevVerticesColor, int w, int h, DomainMath3D domaineMath, int n)
    {
    Mandelbrot3DMath_RGBA mandelbrotMath(n);

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
	float h;
	//mandelbrotMath.sommetXY(&sommet,x,y,t); // update sommet
	mandelbrotMath.colorXY(&color, x, y, &h, n); // update color

	sommet.x = x;
	sommet.y = y;
	sommet.z = mandelbrotMath.z(h);



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

