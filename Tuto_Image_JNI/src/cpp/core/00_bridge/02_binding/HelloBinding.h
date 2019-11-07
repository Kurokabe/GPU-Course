#pragma once

#include "ImageScenario.h"
#include "Hello.h"
#include "CanvasImageViewers_CPU.h"

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

	HelloBinding(int w, int h, int dt);

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


	/*--------------------------------------*\
	|*		Attribut		*|
	 \*-------------------------------------*/

    private:

	// Tools
	Hello* ptrHello;
	cpu::CanvasImageViewers* ptrImageViewer;
    };


/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
