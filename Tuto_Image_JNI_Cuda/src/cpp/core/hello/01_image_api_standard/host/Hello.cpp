#include <iostream>
#include <assert.h>

#include "Hello.h"


using namespace gpu;
using std::cout;
using std::endl;
using std::to_string;

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Imported	 	*|
 \*-------------------------------------*/

extern void launchKernelFillImageHello(uchar4* ptrDevPixels, int w, int h, int t);

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Constructor		*|
 \*-------------------------------------*/

Hello::Hello(unsigned int w, unsigned int h, int dt) :
	Image_A(w, h)
    {
    // Input
    this->dt = dt;

    // Tools
    this->t = 0;
    }

Hello::~Hello(void)
    {
    // rien
    }

/*--------------------------------------*\
|*		Methode			*|
 \*-------------------------------------*/

void Hello::setDt(int dt)
    {
    this->dt = dt;
    }

/*--------------------------------------*\
 |*		Override		*|
 \*-------------------------------------*/

/**
 * Override
 * Call automaticly by the api
 */
void Hello::animationStep(bool& isNeedUpdateView)
    {
    this->t += dt;
    isNeedUpdateView = true; // true par default
    }

/**
 * Override
 * Call automaticly by the api
 */
void Hello::fillImage(uchar4* ptrDevImageGL,int w,int h,const DomaineMath& domaineMath)
    {
    launchKernelFillImageHello(ptrDevImageGL, w, h, t);
    }

/**
 * Override
 * Call automaticly by the api
 */
void Hello::paintPrimitives(Graphic2D& graphic2D)
    {
    float r = 1;
    float g = 0;
    float b = 0;

    graphic2D.setColorRGB(r, g, b);

    // top
	{
	graphic2D.setFont(BITMAP_15);
	//string message = "t= " + StringTools::toString(t) + " dt=" + StringTools::toString(dt);
	string message = " dt=" + to_string(dt);
	graphic2D.drawTitleTop(message);
	}

    // bottom
	{
	graphic2D.setFont(TIMES_ROMAN_24);
	graphic2D.drawTitleBottom("CUDA/OpenGL");
	}
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
