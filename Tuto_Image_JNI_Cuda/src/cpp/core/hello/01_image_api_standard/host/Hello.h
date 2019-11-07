#pragma once

#include "Image_GPU.h"
#include "MathTools.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class Hello: public gpu::Image_RGBA_uchar4
    {
	/*--------------------------------------*\
	|*		Constructeur		*|
	\*-------------------------------------*/

    public:

	Hello(unsigned int w, unsigned int h,int dt);

	virtual ~Hello(void);

	/*--------------------------------------*\
	|*		Methode			*|
	\*-------------------------------------*/

    public:

	void setDt(int dt);


	/*----------------*\
	|*  override	  *|
	 \*---------------*/

	virtual void fillImage(uchar4* ptrTabPixels,int w,int h,const gpu::DomaineMath& domaineMath);
	virtual void animationStep(bool& isNeedUpdateView);// override
	virtual void paintPrimitives(Graphic2D& graphic2D);// override

	/*--------------------------------------*\
	|*		Attribut		*|
	\*-------------------------------------*/

    private:

	// input
	int dt;

	// Tools
	int t;

    };


/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
