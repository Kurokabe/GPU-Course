#pragma once

#include <iostream>

using std::ostream;

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/**
 * Warning : Classe avec attribut de type pointeur, pour les besoins de ce tuto
 */
class Banane
    {

	/*--------------------------------------*\
	|*		Constructeur		*|
	 \*-------------------------------------*/

    public:

	Banane(int poids, int prix);

	/**
	 * required for by example:
	 *
	 * 	- Banane tab[n]
	 * 	- Banane* ptr=new Banane[n];
	 */
	Banane();

	/**
	 * constructeur copie (CC)
	 */
	Banane(const Banane& source);

	virtual ~Banane();

	/*--------------------------------------*\
	|*		Methode			*|
	 \*-------------------------------------*/

    public:

	void setPrix(int prix);

	int getPrix();

	/**
	 * necessaire car attribut pointeur
	 */
	Banane& operator=(const Banane& source);

	static int getCompteurIntance();

	static void resetCompteurInstance();

    private:

	/**
	 * surcharge <<
	 */
	friend ostream& operator <<(ostream& stream, const Banane& banane);

	/*--------------------------------------*\
	|*		Attribut		*|
	 \*-------------------------------------*/

    private:

	// Inputs
	int poids;
	int* ptrPrix; // pointeur inutile dans l'absolu ici, juste pour les besoins techniques de l'exemple

	/*--------------*\
	|*   static	*|
	 \*-------------*/

    private:

	static int compteurIntance;

    };

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
