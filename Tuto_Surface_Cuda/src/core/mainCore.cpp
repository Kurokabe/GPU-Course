#include <stdlib.h>
#include <iostream>

#include "GLUTWindowScene.h"
#include "GLUTWindowManagers.h"

#include "SurfaceSceneStrip.h"
#include "Damier3DProvider.h"

using std::cout;
using std::endl;

using namespace gpu;

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

void mainCore();

/*--------------------------------------*\
 |*		Imported	 	*|
 \*-------------------------------------*/

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

void mainCore()
    {
    SurfaceStrip_I* ptrSurfaceStrip = Damier3DProvider::createSurfaceStrip();

    SurfaceSceneStrip* ptrScene = new SurfaceSceneStrip(ptrSurfaceStrip);
    ptrScene->setAppearance(RenderMode::RENDER_MODE_FILL);

    GLUTWindowScene windowDamierRGBA(ptrScene, "SurfaceSceneStrip damier", 1024, 768, 10, 10);

    GLUTWindowManagers::getInstance()->runALL(); // bloquant

    delete ptrScene;
    delete ptrSurfaceStrip;
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
