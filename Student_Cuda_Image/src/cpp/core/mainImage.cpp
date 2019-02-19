#include <iostream>
#include <stdlib.h>
#include <string.h>

#include "Device.h"
#include "cudaTools.h"

#include "RipplingProvider.h"
#include "Settings_GPU.h"
#include "Viewer_GPU.h"

#include "MandelbrotProvider.h"
#include "RaytracingProvider.h"
using namespace gpu;

using std::cout;
using std::endl;
using std::string;

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Imported	 	*|
 \*-------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

int mainImage(Settings& settings);

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

int mainImage(Settings& settings)
    {
    cout << "\n[Image] mode" << endl;

    GLUTImageViewers::init(settings.getArgc(), settings.getArgv()); //only once

    // ImageOption : (boolean,boolean) : (isSelection ,isAnimation,isOverlay,isShowHelp)
    ImageOption zoomable(true, true, true, true);
    ImageOption nozoomable(false, true, false, false);

    //Viewer<RipplingProvider> vague(nozoomable, 0, 0); // imageOption px py
    //Viewer<MandelbrotProvider> mandelbrot(zoomable, 0, 0); // imageOption px py
    Viewer<RaytracingProvider> raytracing(nozoomable, 0, 0); // imageOption px py

    // Common
    GLUTImageViewers::runALL(); // Bloquant, Tant qu'une fenetre est ouverte

    cout << "\n[Image] end" << endl;

    return EXIT_SUCCESS;
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

