#pragma once

#include "SceneCube.h"
#include "Image_I.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class SceneCubeCreator
    {

	/*--------------------------------------*\
	 |*		Constructor		*|
	 \*-------------------------------------*/

    public:

	SceneCubeCreator();

	virtual ~SceneCubeCreator();

	/*--------------------------------------*\
	 |*		Surcharge		*|
	 \*-------------------------------------*/

    public:

	SceneCube* getScene();

	/*--------------------------------------*\
 |*		Methodes		*|
	 \*-------------------------------------*/

    private:

	void createImages();
	void createScene();

	/*--------------------------------------*\
	 |*		Attributs		*|
	 \*-------------------------------------*/

    private:

	// Outputs
	SceneCube* ptrScene;

	// Tools
	Image_I* ptrImage1;
	Image_I* ptrImage2;
	Image_I* ptrImage3;
	Image_I* ptrImage4;
	Image_I* ptrImage5;
	Image_I* ptrImage6;

    };

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
