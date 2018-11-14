#include "Indice2D.h"
#include "cudaTools.h"
#include "Device.h"

#include "IndiceTools_GPU.h"

#include "VagueGrayMath.h"
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

__global__ void vagueGray(uchar* ptrDevPixels,uint w, uint h,float t);

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

__global__ void vagueGray(uchar* ptrDevPixels, uint w, uint h, float t)
    {
    VagueGrayMath vagueGrayMath = VagueGrayMath(w, h);

    const int TID = Indice2D::tid();
    const int NB_THREAD = Indice2D::nbThread();
    const int WH=w*h;

    int i; // in [0,h[
    int j; // in [0,w[

    int s = TID;
    while (s < WH)
	{
	IndiceTools::toIJ(s, w, &i, &j); 	// update (i, j)

	vagueGrayMath.colorIJ(&ptrDevPixels[s],i, j, t); 	// update ptrDevPixels[s]

	s += NB_THREAD;
	}
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

