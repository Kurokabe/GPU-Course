#include "ImageCustomEvent.h"

#include <iostream>

#include "SimpleKeyListener.h"
#include "SimpleMouseListener.h"

using std::cout;
using std::endl;
using std::string;

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Constructeur		*|
 \*-------------------------------------*/

ImageCustomEvent::ImageCustomEvent(Animable_I<uchar4>* ptrAnimable,ColorRGB_01 colorTexte)
    :ImageAnimable_RGBA_uchar4(ptrAnimable,colorTexte)
    {
    // Tools
    listener();
    }

ImageCustomEvent::~ImageCustomEvent(void)
    {
    delete ptrKeyListener;
    delete ptrMouseListener;
    }

/*--------------------------------------*\
 |*		Methode 		*|
 \*-------------------------------------*/

/**
 * Override
 * call periodicly by the api
 */
void ImageCustomEvent::paintPrimitives(Graphic2D& graphic2D)
    {
    ImageAnimable_RGBA_uchar4::paintPrimitives( graphic2D);

    float r = 0;
    float g = 0;
    float b = 1;
    graphic2D.setColorRGB(r, g, b);
    graphic2D.setFont(TIMES_ROMAN_24);

    // Top
	{
	float t = getAnimable()->getAnimationPara();

	string title =getAnimable()->getTitle();

	graphic2D.drawTitleBottom(title);

	// Bottom
	    {
	    graphic2D.drawTitleTop("Advanced : Click on the windows, and look message in the console");
	    }
	}
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

void ImageCustomEvent::listener(void)
    {
    this->ptrKeyListener = new SimpleKeyListener();
    this->ptrMouseListener = new SimpleMouseListener();

    setKeyListener(ptrKeyListener);
    setMouseListener(ptrMouseListener);
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

