#pragma once

#include <iostream>

using std::ostream;
using std::string;

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

class Personne
    {

	/*--------------------------------------*\
	|*		Constructeur		*|
	 \*-------------------------------------*/

    public:

	Personne(string name, int taille);

	/**
	 * constructeur vide
	 * usefull for Personne tab=new Personne[n];
	 */
	Personne();

	virtual ~Personne();

	/*--------------------------------------*\
	|*		Methode			*|
	 \*-------------------------------------*/

    public:

	static int getCompteurIntance();

    private:

	/**
	 * surcharge <<
	 */
	friend ostream& operator <<(ostream& stream, const Personne& personne);

	/*--------------------------------------*\
	|*		Attribut		*|
	 \*-------------------------------------*/

    private:

	// Inputs
	string name;
	int taille;

	/*--------------*\
	|*   static	*|
	 \*-------------*/

    private:

	static int compteurIntance;

    };

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
