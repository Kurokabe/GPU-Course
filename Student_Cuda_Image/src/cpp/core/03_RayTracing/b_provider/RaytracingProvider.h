#pragma once

#include "cudaTools.h"

#include "Provider_I_GPU.h"
#include "Raytracing.h"
using namespace gpu;

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

class RaytracingProvider: public Provider_I<uchar4>
    {
    public:

	virtual ~RaytracingProvider()
	    {
	    // Rien
	    }

	/*--------------------------------------*\
	 |*		Override		*|
	 \*-------------------------------------*/

	virtual Animable_I<uchar4>* createAnimable(void);

	virtual Image_I* createImageGL(void);
	void setDT(int dt);
    private:
	Raytracing* ptrRaytracing;
    };

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

