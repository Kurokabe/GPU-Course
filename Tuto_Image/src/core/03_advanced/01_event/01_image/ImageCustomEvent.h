#pragma once

#include "SimpleKeyListener.h"
#include "SimpleMouseListener.h"

#include "ImageAnimable_CPU.h"
using namespace cpu;

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

/**
 * see ImageAnimable_GPU.h
 *
 * 	ImageAnimable_RGBA_uchar4
 * 	ImageAnimable_HSBA_uchar4
 * 	...
 */
class ImageCustomEvent: public ImageAnimable_RGBA_uchar4
    {
	/*--------------------------------------*\
	|*		Constructor		*|
	 \*-------------------------------------*/

    public:

	ImageCustomEvent(Animable_I<uchar4>* ptrAnimable, ColorRGB_01 titleColor);

	virtual ~ImageCustomEvent(void);

	/*--------------------------------------*\
	|*		Methodes		*|
	 \*-------------------------------------*/

    public:

	/*-------------------------*\
	|*   Override Animable_I   *|
	 \*------------------------*/

	/**
	 * Call periodicly by the api
	 * Override
	 */
	virtual void paintPrimitives(Graphic2D& graphic2D);

    private:

	void listener(void);

	/*--------------------------------------*\
	|*		Attributs		*|
	 \*-------------------------------------*/

    private:

	// Inputs

	// Tools
	SimpleKeyListener* ptrKeyListener;
	SimpleMouseListener* ptrMouseListener;
    };

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
