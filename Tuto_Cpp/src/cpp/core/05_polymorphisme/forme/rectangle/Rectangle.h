#pragma once

#include <iostream>

#include "Forme_A.h"

using std::string;

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

class Rectangle : public Forme_A
    {

	/*--------------------------------------*\
	|*		Constructeur		*|
	 \*-------------------------------------*/

    public:

	Rectangle(string name,double longueur,double largeur);

	virtual ~Rectangle();

	/*--------------------------------------*\
	|*		Methode			*|
	 \*-------------------------------------*/

    public:

	/**
	 * Override
	 */
	virtual double aire(void);


	/**
	 * Override
	 */
	double perimetre();

	/*--------------------------------------*\
	|*		Attribut		*|
	 \*-------------------------------------*/

    private:

	// Inputs
	double longueur;
	double largeur;

    };

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
