#include "HelloBinding.h"

#include "RipplingProvider.h"
using gpu::CanvasImageViewers;

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Constructor		*|
 \*-------------------------------------*/

HelloBinding::HelloBinding(int w, int h, int dt, int type) :
	ImageScenario(w, h)
    {
    const bool USE_ANIMATION = true;
    const bool USE_SELECTION = false;
    const bool SHOW_OVERLAY_DOMAINE = false;

    this->type = type;

    ptrHello = new Hello(w, h, dt);
    ptrRippling = new RipplingProvider();
    ptrMandelbrot = new MandelbrotProvider();
    ptrRaytracing = new RaytracingProvider();

    option = ImageOption(USE_SELECTION,USE_ANIMATION ,SHOW_OVERLAY_DOMAINE);

    switch(type)
	{
	case 0:
	    ptrImage = ptrRippling->createImageGL();
	    break;
	case 1:
	    ptrImage = ptrMandelbrot->createImageGL();
	    break;
	case 2:
	    ptrImage = ptrRaytracing->createImageGL();
	    break;
	}

    ptrImageViewer = new CanvasImageViewers(ptrImage, option);
    }

HelloBinding::~HelloBinding()
    {
    delete ptrHello;
    delete ptrImageViewer;
    }

/*--------------------------------------*\
|*		Methode			*|
 \*-------------------------------------*/

/*----------------*\
|*  	get	  *|
 \*---------------*/

/**
 * Override
 */
int HelloBinding::getCanvasNativeID()
    {
    return ptrImageViewer->getCanvasNativeID();
    }

/*----------------*\
|*  	set	  *|
 \*---------------*/

/**
 * Animation
 */
void HelloBinding::setDt(int dt)
    {
    ptrHello->setDt(dt);
    ptrMandelbrot->setDT(dt);
    ptrRippling->setDT(dt);
    ptrRaytracing->setDT(dt);
    }

void HelloBinding::setNMinNMax(int nMin, int nMax)
    {
    if (type == 1)
	{
	    ptrMandelbrot->setNMinNMax(nMin, nMax);
	}
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

