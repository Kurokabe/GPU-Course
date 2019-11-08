#include "HelloBinding.h"

using cpu::CanvasImageViewers;

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Constructor		*|
 \*-------------------------------------*/

HelloBinding::HelloBinding(int w, int h, int dt) :
	ImageScenario(w, h)
    {
    const bool USE_ANIMATION = true;
    const bool USE_SELECTION = false;
    const bool SHOW_OVERLAY_DOMAINE = false;

    ptrHello = new Hello(w, h, dt);

    ImageOption option(USE_SELECTION,USE_ANIMATION ,SHOW_OVERLAY_DOMAINE);

    ptrImageViewer = new CanvasImageViewers(ptrHello, option);
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
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

