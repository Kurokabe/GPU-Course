#pragma once

#include "KeyListener_I.h"

#include "Image_GPU.h"
#include "DomaineMath_GPU.h"
using namespace gpu;


/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class DomaineKeyListener: public KeyListener_I
    {
    public:

	/*--------------------------------------*\
	|*		Constructor		*|
	 \*-------------------------------------*/

	DomaineKeyListener(Image_RGBA_uchar4* ptrImage);

	virtual ~DomaineKeyListener();

	/*--------------------------------------*\
	 |*		Methodes		*|
	 \*-------------------------------------*/

    public:

	/**
	 * Override
	 */
	virtual void onKeyPressed(const KeyEvent& event);

	/**
	 * Override
	 */
	void onKeyReleased(const KeyEvent& event);


	/*--------------------------------------*\
	 |*		Attributs		*|
	 \*-------------------------------------*/

    private:
	// Inputs
	Image_RGBA_uchar4* ptrImage;

	// Tools
	DomaineMath domaine1;
    };

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
