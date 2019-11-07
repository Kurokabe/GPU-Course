#include "HelloBinding.h"
#include "ScenarioManager.h"


/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

static HelloBinding* getBinding(int canvasNativeID);

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

int createImageHello(int w, int h, int dt, int type)
    {
    HelloBinding* ptr = new HelloBinding(w, h, dt, type);

    ptr->registry(); // Important!

    return ptr->getCanvasNativeID();
    }

void setDt(int panelID, int dt)
    {
    getBinding(panelID)->setDt(dt);
    }

void setNMinNMax(int panelID, int nMin, int nMax)
    {
    getBinding(panelID)->setNMinNMax(nMin, nMax);
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

HelloBinding* getBinding(int canvasNativeID)
    {
    return (HelloBinding*) ScenarioManager::getInstance()->getScenario(canvasNativeID);
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

