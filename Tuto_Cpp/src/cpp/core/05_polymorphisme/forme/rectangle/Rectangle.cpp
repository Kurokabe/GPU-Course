#include "Rectangle.h"


#include <iostream>
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

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Constructeur		*|
 \*-------------------------------------*/

Rectangle::Rectangle(string name, double longueur, double largeur) :
	Forme_A(name), longueur(longueur)
    {
    this->largeur = largeur; // possible aussi
    }

/**
 * destructeur classe parente appeler automatiquement
 */
Rectangle::~Rectangle()
    {
    // rien, car aucun new dans constructeur

    // debug pedagogique
    	{
    	cout << "[Rectangle] : destructeur : " << getName()<<" : ";
    	}
    }

/*--------------------------------------*\
 |*		Methode			*|
 \*-------------------------------------*/

/**
 * Override
 */
double Rectangle::aire(void)
    {
    return longueur * largeur;
    }

/**
 * Override
 */
double Rectangle::perimetre()
    {
    return 2 * (longueur + largeur);
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

