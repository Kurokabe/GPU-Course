#include <iostream>
#include <stdlib.h>

#include "Indice2D.h"
#include "IndiceTools_GPU.h"
#include "cudaTools.h"
#include "Device.h"

#include "HelloMath.h"

using std::cout;
using std::endl;



/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Imported	 	*|
 \*-------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

 void launchKernelFillImageHello(uchar4* ptrDevPixels, int w, int h, int t);

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

static __global__ void kernelHello(uchar4* ptrDevPixels,int w, int h,int t);

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

void launchKernelFillImageHello(uchar4* ptrDevPixels, int w, int h, int t)
    {
    const int MP=Device::getMPCount();
    const int dgx=Device::getMaxThreadPerBlock();

    // Disons a optimiser
    dim3 dg(MP*4,1, 1);
    dim3 db(dgx, 1, 1);

    //Device::print(dg, db);
   //  Device::checkDimError(dg,db);

    kernelHello<<<dg,db>>>(ptrDevPixels,w,h,t);
    Device::lastCudaError("kernelHello");
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

__global__ void kernelHello(uchar4* ptrDevPixels, int w, int h, int t)
    {
    HelloMath helloMath = HelloMath(w, h);

    const int TID = Indice2D::tid();
    const int NB_THREAD = Indice2D::nbThread();

    const int WH=w*h;

    uchar4 colorIJ;
    int pixelI;
    int pixelJ;

    int s = TID;
    while (s < WH)
	{
	gpu::IndiceTools::toIJ(s, w, &pixelI, &pixelJ);	 // update (pixelI, pixelJ)

	helloMath.color(&colorIJ,pixelI, pixelJ, t); 	// update color
	ptrDevPixels[s] = colorIJ;

	s += NB_THREAD;
	}

    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

