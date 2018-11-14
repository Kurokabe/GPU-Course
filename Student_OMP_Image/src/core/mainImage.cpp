#include <iostream>

#include "RipplingProvider.h"
#include "MandelbrotProvider.h"

#include "Viewer_CPU.h"
#include "Settings_CPU.h"
using namespace cpu;

using std::cout;
using std::endl;

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Imported		*|
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

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

int mainImage(Settings& settings)
    {
    cout << "\n[Image] mode" << endl;

    GLUTImageViewers::init(settings.getArgc(), settings.getArgv()); // only once

    // ImageOption : (boolean,boolean) : (isSelection ,isAnimation,isOverlay,isShowHelp)
    ImageOption zoomable(true,true,true,true);
    ImageOption nozoomable(false,true,false,false);

    Viewer<RipplingProvider> rippling(nozoomable, 0, 0); //  imageOption px py
   // Viewer<MandelbrotProvider> mandelbrot(zoomable, 0, 0); //  imageOption px py

    GLUTImageViewers::runALL();  // Bloquant, Tant qu'une fenetre est ouverte

    cout << "\n[Image] end" << endl;

    return EXIT_SUCCESS;
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

