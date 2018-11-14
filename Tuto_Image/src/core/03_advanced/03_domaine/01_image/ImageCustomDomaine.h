#pragma once

#include "DomaineKeyListener.h"

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
class ImageCustomDomaine: public ImageAnimable_RGBA_uchar4
    {

	/*--------------------------------------*\
	|*		Constructor		*|
	 \*-------------------------------------*/

    public:

	ImageCustomDomaine(Animable_I<uchar4>* ptrAnimable,ColorRGB_01 titleColor);

	virtual ~ImageCustomDomaine();

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
	virtual void paintPrimitives(Graphic2D& graphic2D); // override

    private:

	void controle();

	/*--------------------------------------*\
	|*		Attributs		*|
	 \*-------------------------------------*/
    private:

	// Tools
	DomaineKeyListener* ptrKeyListener;
    };

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
