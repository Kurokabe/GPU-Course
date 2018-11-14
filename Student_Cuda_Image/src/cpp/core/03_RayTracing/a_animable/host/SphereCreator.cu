#include "SphereCreator.h"

#include <iostream>
#include <assert.h>

#include "AleaTools.h"
#include "MathTools.h"

using std::cout;
using std::endl;

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Constructeur		*|
 \*-------------------------------------*/

SphereCreator::SphereCreator(int nbSpheres, int w, int h, int bord)
    {
    assert(nbSpheres >= 4);
    
    // Inputs
    this->nbSpheres = nbSpheres;
    this->w = w;
    this->h = h;
    this->bord = bord;

    // Tools
    this->tabSphere = new Sphere[nbSpheres]; // required default constructeur of type : sphere(void)

    createSphereAll();
    }

SphereCreator::~SphereCreator()
    {
    delete[] tabSphere;
    }

/*--------------------------------------*\
 |*		Methode			*|
 \*-------------------------------------*/

Sphere* SphereCreator::getTabSphere()
    {
    return tabSphere;
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

void SphereCreator::createSphereAll(void)
    {
    createSphereBack();
    createSphereFront();
    createSphereAleatoire();
    }

/**
 * La premiere, centrée, très grande, au fond
 */
void SphereCreator::createSphereBack(void)
    {
    float3 centre;

    centre.x = h / 2;
    centre.y = w / 2;
    centre.z = ZMAX * 2; // plus grand que ZMAX

    float rayon = std::min(w / 2, h / 2);
    float hue01 = 1;

    tabSphere[0] = Sphere(centre, rayon, hue01);
    }

/**
 * Les dernieres, centrées, très petite, très proche
 */
void SphereCreator::createSphereFront(void)
    {
    float hue01 = 1;
    float rayon = std::min(w / 10, h / 10); // disons
    float z = ZMIN - (rayon + rayonMax());

    float dhue = 0.2;
    float dz = 40;
    float drayon = dz / 2;

    for (int i = nbSpheres - 3; i < nbSpheres; i++)
	{
	float3 centre;

	z -= dz;
	rayon -= drayon;
	hue01 -= dhue;

	centre.x = h / 2;
	centre.y = w / 2;
	centre.z = z;

	tabSphere[i] = Sphere(centre, rayon, hue01); // Warning : sphere stack copier dans sphere heap, ok car pas ptr dans Sphere
	}
    }

/**
 * Toute sauf la premiere
 */
void SphereCreator::createSphereAleatoire(void)
    {
    AleaTools aleaTools = AleaTools();

    for (int i = 1; i < nbSpheres - 3; i++)
	{
	float3 centre;

	centre.x = aleaTools.uniformeAB(0 + bord, h - bord);
	centre.y = aleaTools.uniformeAB(0 + bord, w - bord);
	centre.z = aleaTools.uniformeAB(ZMIN, ZMAX);

	float rayon = aleaTools.uniformeAB(20, rayonMax());
	float hue01 = aleaTools.uniforme01();

	tabSphere[i] = Sphere(centre, rayon, hue01); // Warning : sphere stack copier dans sphere heap, ok car pas ptr dans Sphere
	}
    }

int SphereCreator::rayonMax()
    {
    return w / 10;
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

