#pragma once

#include "ImageScenario.h"
#include "Hello.h"
#include "CanvasImageViewers_GPU.h"
#include "RipplingProvider.h"
#include "MandelbrotProvider.h"
#include "RaytracingProvider.h"
/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class HelloBinding: public ImageScenario
    {
	/*--------------------------------------*\
	|*		Constructor		*|
	 \*-------------------------------------*/

    public:

	HelloBinding(int w, int h, int dt, int type);

	virtual ~HelloBinding();

	/*--------------------------------------*\
	|*		Methode			*|
	 \*-------------------------------------*/

    public:

	/**
	 * Override
	 */
	virtual int getCanvasNativeID();

	/**
	 * Animation
	 */
	void setDt(int dt);

	void setNMinNMax(int nMin, int nMax);


	/*--------------------------------------*\
	|*		Attribut		*|
	 \*-------------------------------------*/

    private:

	// Tools
	Hello* ptrHello;
	RipplingProvider* ptrRippling;
	MandelbrotProvider* ptrMandelbrot;
	RaytracingProvider* ptrRaytracing;
	gpu::CanvasImageViewers* ptrImageViewer;

	Image_I* ptrImage;

	int type;
	ImageOption option;
    };


/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
