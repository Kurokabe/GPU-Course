#pragma once

#include <iostream>
#include <vector>

#include "Forme_A.h"

using std::string;
using std::vector;

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

class Dessin
    {

	/*--------------------------------------*\
	|*		Constructeur		*|
	 \*-------------------------------------*/

    public:

	Dessin(string name);

	virtual ~Dessin();

	/*--------------------------------------*\
	|*		Methode			*|
	 \*-------------------------------------*/

    public:

	/**
	 * celui qui crée la forme la détruit
	 * Dessin ne détruit rien
	 */
	void add(Forme_A* ptrForme);

	/**
	 * somme aire de toutes les formes
	 */
	double aire(void);

	/**
	 * somme perimetre de toutes les formes
	 */
	double perimetre();

	string getName();

	int size();

	/*--------------------------------------*\
	|*		Attribut		*|
	 \*-------------------------------------*/

    private:

	// Inputs
	string name;

	// Tools
	vector<Forme_A*> listForme; // listForme est deja instancier ici avec cette syntaxe! A a; // instancie a avec constructeur vide de A

    };

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
