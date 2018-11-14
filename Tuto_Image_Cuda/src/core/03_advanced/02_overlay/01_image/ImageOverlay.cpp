#include "ImageOverlay.h"

#include <iostream>

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

ImageOverlay::ImageOverlay(Animable_I<uchar4>* ptrAnimable, ColorRGB_01 colorTexte) :
	ImageAnimable_RGBA_uchar4(ptrAnimable, colorTexte)
    {
    // Tools
    this->ptrExampleDrawer2D= new ExampleDrawer2D(ptrAnimable->getW(), ptrAnimable->getH());
    }

ImageOverlay::~ImageOverlay(void)
    {
    delete ptrExampleDrawer2D;
    }

/*--------------------------------------*\
 |*		Methode 		*|
 \*-------------------------------------*/

/**
 * Override
 * call periodicly by the api
 */
void ImageOverlay::paintPrimitives(Graphic2D& graphic2D)
    {
    // call methode parente, important!
    ImageAnimable_RGBA_uchar4::paintPrimitives(graphic2D);

    exampleDirecte(graphic2D);
    exampleIndirecte(graphic2D);
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

void ImageOverlay::exampleDirecte(Graphic2D& graphic2D)
    {
    // etat
	{
	float r = 0;
	float g = 0;
	float b = 1;
	graphic2D.setColorRGB(r, g, b);
	graphic2D.setFont(TIMES_ROMAN_24);
	}

    // Title
	{
	// Top
	    {
	    string title = getAnimable()->getTitle();

	    graphic2D.drawTitleBottom(title);
	    }

	// Bottom
	    {
	    graphic2D.drawTitleTop("You can add geometric primitive in top of the image");
	    }
	}

    // Line
	{
	graphic2D.drawHorizontalLigne(10, 10, 100); // x y l
	graphic2D.drawVerticalLigne(20, 20, 100); // x y l
	graphic2D.drawLigne(50, 50, 100, 100); 	// x1 y1 x2 y2
	}
    }

void ImageOverlay::exampleIndirecte(Graphic2D& graphic2D)
    {
    // un objet dedier local pour plus d'examples, instancier once in the constructeur

    ptrExampleDrawer2D->drawObjet(graphic2D);
    ptrExampleDrawer2D->drawNonObjet(graphic2D);
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

