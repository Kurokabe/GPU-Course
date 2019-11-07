#pragma once

#include "cudaTools.h"
#include "Provider_I_GPU.h"
#include "Mandelbrot.h"

using namespace gpu;

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/



class MandelbrotProvider: public Provider_I<uchar4>
    {
    public:

	virtual ~MandelbrotProvider()
	    {
	    // Rien
	    }

	/*--------------------------------------*\
	 |*		Override		*|
	 \*-------------------------------------*/

	virtual Animable_I<uchar4>* createAnimable(void);

	virtual Image_I* createImageGL(void);
	Image_I* createImageGL(float x1, float x2, float y1, float y2);

	void setNMinNMax(int nMin, int nMax);

	double x1;
	double x2;
	double y1;
	double y2;

	int nMin = 20;
	int nMax = 120;

    private:
	Mandelbrot *mandelbrot;

    };

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

