#pragma once

#include "Sphere.h"

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class SphereCreator
    {
	/*--------------------------------------*\
	|*		Constructor		*|
	 \*-------------------------------------*/

    public:

	SphereCreator(int nbSpheres, int w, int h, int bord = 200);
	virtual ~SphereCreator(void);

	/*--------------------------------------*\
	 |*		Methodes		*|
	 \*-------------------------------------*/

    public:

	/**
	 * Warning : tabSphere delete when SphereCreator is delete
	 */
	Sphere* getTabSphere();

    private:

	void createSphereAll(void);
	void createSphereBack();
	void createSphereFront();
	void createSphereAleatoire();

	int rayonMax();

	/*--------------------------------------*\
	 |*		Attributs		*|
	 \*-------------------------------------*/

    private:

	// Inputs
	int nbSpheres;
	int w;
	int h;
	int bord;

	// Tools
	Sphere* tabSphere;

	static const int ZMIN=2000;
	static const int ZMAX=3000;

    };

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
