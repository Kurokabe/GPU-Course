#pragma once

#include "Image_CPU.h"

#include "HelloMath.h"

using namespace cpu;

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class Hello:  public Image_RGBA_uchar4
    {

	/*--------------------------------------*\
	 |*		Constructeur		*|
	 \*-------------------------------------*/

    public:

	Hello(unsigned int w, unsigned int h, int dt);

	virtual ~Hello(void);

	/*--------------------------------------*\
	 |*		Methode			*|
	 \*-------------------------------------*/

    public:

	void setDt(int dt);

	/*----------------*\
	|*  Override	  *|
	 \*---------------*/

	/**
	 * Override, call periodicly by the api
	 */
	virtual void fillImage(uchar4* ptrTabPixels, int w, int h,const DomaineMath& domaineMath);

	/**
	 * Override, call periodicly by the api
	 */
	virtual void animationStep(bool& isNeedUpdateView);

	/**
	 * Override, call periodicly by the api
	 */
	virtual void paintPrimitives(Graphic2D& graphic2D);

	/*----------------*\
	|*  private	  *|
	\*---------------*/

    private:

	void launch_OMP(uchar4* ptrTabPixels, int w, int h);

	void entrelacementOMP(uchar4* ptrImageGL,int w, int h);
	void forAutoOMP(uchar4* ptrImageGL,int w, int h);

	void dxy(int x, int y, float& result);
	void f(int x, int y, float t, unsigned char& levelGris);

	/*--------------------------------------*\
	|*		Attribut		*|
	 \*-------------------------------------*/

    private:

	// Inputs
	int dt;

	// Tools
	int t;
	HelloMath helloMath;
	bool isEntrelacement;
    };



/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*----------------------------------------------------------------------*/
