#include <iostream>

#include "SceneCubeCreator.h"

#include "RipplingProvider.h"
#include "MandelbrotProvider.h"
#include "RaytracingProvider.h"


/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Constructor		*|
 \*-------------------------------------*/

SceneCubeCreator::SceneCubeCreator()
    {
    createImages();
    createScene();
    }

SceneCubeCreator::~SceneCubeCreator()
    {
    delete ptrImage1;
    delete ptrImage2;
    delete ptrImage3;
    delete ptrImage4;
    delete ptrImage5;
    delete ptrImage6;

    delete ptrScene;
    }

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

SceneCube* SceneCubeCreator::getScene()
    {
    return ptrScene;
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

void SceneCubeCreator::createImages()
    {
    ptrImage1 = RaytracingProvider().createImageGL();
    ptrImage2 = RipplingProvider().createImageGL();

    ptrImage3 = MandelbrotProvider().createImageGL(-1.24693, -1.24681, -0.377491, -0.37739);
    ptrImage4 = MandelbrotProvider().createImageGL(-1.26751, -1.23104, -0.393991, -0.361493);
    ptrImage5 = MandelbrotProvider().createImageGL(-1.36149, -1.07329, -0.486157, -0.228306);
    ptrImage6 = MandelbrotProvider().createImageGL();
    }

void SceneCubeCreator::createScene()
    {
    ptrScene = new SceneCube(ptrImage1, ptrImage2, ptrImage3, ptrImage4, ptrImage5, ptrImage6);
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

