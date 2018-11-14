#include <iostream>

#include "DamierProvider.h"
#include "VagueProvider.h"
#include "VagueGrayProvider.h"
#include "DamierRGBAFloatProvider.h"
#include "DamierHSBAFloatProvider.h"
#include "DamierHueFloatProvider.h"

#include "EventProvider.h"
#include "OverlayProvider.h"
#include "DomaineProvider.h"

#include "MyDisplayableProvider.h"

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
    ImageOption zoomable(true, true, true, true);
    ImageOption nozoomable(false, true, true, true);

    Viewer<VagueProvider> vague(nozoomable, 0, 0); //  imageOption px py
    Viewer<DamierProvider> damier(zoomable);

    Viewer<VagueGrayProvider> vagueGrayUchar(nozoomable);
    Viewer<DamierRGBAFloatProvider> damierRGBAfloat4(zoomable);
    Viewer<DamierHSBAFloatProvider> damierHSBAfloat4(zoomable);
    Viewer<DamierHueFloatProvider> damierHuefloat(zoomable);

    Viewer<EventProvider> event(zoomable);
    Viewer<OverlayProvider> overlay(zoomable);
    Viewer<DomaineProvider> domaine(zoomable);

    int w = 512;
    int h = 256;

    // Facultatif : par default:
    // 	- size viewer = size image (une texture prend le relais en cas de taille différente)
    //  - positon (0,0) ou celle du constructeur du viewer
	{
	// size (size of image  don't change, a texture work for you to adapt the image to the size of the frame)
	    {
	    // Ligne1
	    vague.setViewerSize(w, h);
	    damier.setViewerSize(w, h);

	    // Ligne2
	    vagueGrayUchar.setViewerSize(w, h);
	    damierRGBAfloat4.setViewerSize(w, h);
	    damierHSBAfloat4.setViewerSize(w, h);
	    damierHuefloat.setViewerSize(w, h);

	    // Ligne3
	    event.setViewerSize(w, h);
	    overlay.setViewerSize(w, h);
	    domaine.setViewerSize(w, h);
	    }

	// position
	    {
	    // ligne1
	    vague.setViewerPosition(0, 0);
	    damier.setViewerPosition(w, 0);

	    // Ligne2 // problem  en y
	    vagueGrayUchar.setViewerPosition(0, h);
	    damierRGBAfloat4.setViewerPosition(w, h);
	    damierHSBAfloat4.setViewerPosition(2 * w, h);
	    damierHuefloat.setViewerPosition(3 * w, h);

	    // Ligne3 // problem  en y
	    event.setViewerPosition(0, 2 * h);
	    overlay.setViewerPosition(w, 2 * h);
	    domaine.setViewerPosition(2 * w, 2 * h);
	    }
	}

    // Custom : Advanced
    Displayable_A* ptrMyDisplayable = MyDisplayableProvider::createGL();
    GLUTWindow glutWindow(ptrMyDisplayable, "Triangle OpenGL Custom Displayable", w, h, 0, 3 * h); // scene OpenGL // (w,h,px,py)

    GLUTImageViewers::runALL();  // Bloquant, Tant qu'une fenetre est ouverte

    delete ptrMyDisplayable;

    cout << "\n[Image] end" << endl;

    return EXIT_SUCCESS;
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

