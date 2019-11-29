#pragma once

#include "cudaTools.h"

#include "Provider_I_GPU.h"
#include "HeatTransfer.h"
using namespace gpu;

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

class HeatTransferProvider: public Provider_I<uchar4>
    {
    public:

	virtual ~HeatTransferProvider()
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
	HeatTransfer* ptrHeatTransfer;
    };

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

