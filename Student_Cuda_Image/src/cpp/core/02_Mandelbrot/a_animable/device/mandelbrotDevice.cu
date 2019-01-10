#include "Indice2D.h"
#include "cudaTools.h"
#include "Device.h"

#include "MandelbrotMath.h"

#include "DomaineMath_GPU.h"
#include "IndiceTools_GPU.h"
using namespace gpu;

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public		 	*|
 \*-------------------------------------*/

__global__ void mandelbrot(uchar4* ptrDevPixels, uint w, uint h, DomaineMath domaineMath, int n);

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

__global__ void mandelbrot(uchar4* ptrDevPixels, uint w, uint h, DomaineMath domaineMath, int n)
    {
    MandelbrotMath mandelbrotMath; // warning syntaxe juste !
    //MandelbrotMath mandelbrotMath();// warning syntaxe fausse !

    const int TID = Indice2D::tid();
        const int NB_THREAD = Indice2D::nbThread();
        const int WH = w * h;

        int i;
        int j;
        float x;
        float y;
        int s = TID;
        while (s < WH)
    	{
            IndiceTools::toIJ(s, w, &i, &j);
            domaineMath.toXY(i, j, &x, &y);
            mandelbrotMath.colorXY(&ptrDevPixels[s], x, y, n);
	    s += NB_THREAD;
    	}
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

