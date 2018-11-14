#include "ImageCustomDomaine.h"
/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

ImageCustomDomaine::ImageCustomDomaine(Animable_I<uchar4>* ptrAnimable,ColorRGB_01 colorTexte)
    :ImageAnimable_RGBA_uchar4(ptrAnimable,colorTexte)
    {
    controle();
    }

ImageCustomDomaine::~ImageCustomDomaine()
    {
    delete ptrKeyListener;
    }

/*--------------------------------------*\
 |*		Methode 		*|
 \*-------------------------------------*/

void ImageCustomDomaine::paintPrimitives(Graphic2D& graphic2D)
    {
    ImageAnimable_RGBA_uchar4::paintPrimitives(graphic2D);

    float r = 0;
    float g = 0;
    float b = 0;
    graphic2D.setColorRGB(r, g, b);
    graphic2D.setFont(TIMES_ROMAN_24);

    int fontHeight = graphic2D.getFont()->height;
    int y0 = 100;

    // Key '1'
	{
	string message = "1 go to initial Domaine";
	graphic2D.drawText(0, y0 + fontHeight, message);
	}

    // Key '2'
	{
	string message = "2 go to previous Domaine";
	graphic2D.drawText(0, y0 + 2 * fontHeight, message);
	}

    // Key '3'
	{
	string message = "3 set predefined domaine";
	graphic2D.drawText(0, y0 + 3 * fontHeight, message);
	}
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

void ImageCustomDomaine::controle()
    {
    this->ptrKeyListener = new DomaineKeyListener(this);
   // this->ptrDomaineListener = new DomaineListener();

    setKeyListener(ptrKeyListener);
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

