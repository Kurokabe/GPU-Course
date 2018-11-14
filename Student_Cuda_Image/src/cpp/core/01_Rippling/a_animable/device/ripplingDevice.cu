#include "Indice2D.h"
#include "cudaTools.h"
#include "Device.h"

#include "IndiceTools_GPU.h"

#include "RipplingMath.h"
using namespace gpu;

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

__global__ void rippling(uchar4* ptrDevPixels, uint w, uint h, float t);

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

__global__ void rippling(uchar4* ptrDevPixels, uint w, uint h, float t)
    {
    // TODO instacier RipplingMath

    const int TID = Indice2D::tid();
    const int NB_THREAD = Indice2D::nbThread();
    const int WH = w * h;

    // TODO Rippling GPU  pattern entrelacement
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

