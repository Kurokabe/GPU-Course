#pragma once

#include <iostream>

using std::string;

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

class Calculatrice
    {

	/*--------------------------------------*\
	|*		Constructeur		*|
	 \*-------------------------------------*/

    public:

	Calculatrice(string marque);

	Calculatrice();

	virtual ~Calculatrice();

	/*--------------------------------------*\
	|*		Methode			*|
	 \*-------------------------------------*/

    public:

	double add(double a, double b);

	void mult(double a, double b, double* ptrResultat);

	string getMarque();

	/*-----------------*\
	|*	static	   *|
	 \*----------------*/

    public:

	static double sub(double a, double b);

	/*--------------------------------------*\
	|*		Attribut		*|
	 \*-------------------------------------*/

    private:

	// Inputs
	string marque;

    };

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
