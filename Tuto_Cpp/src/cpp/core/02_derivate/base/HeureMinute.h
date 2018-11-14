#pragma once

#include <iostream>

using std::cout;
using std::endl;
using std::string;

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

class HeureMinute
    {

	/*--------------------------------------*\
	|*		Constructeur		*|
	 \*-------------------------------------*/

    public:

	HeureMinute(string titre, int heure, int minute);

	HeureMinute(string titre);

	virtual ~HeureMinute();

	/*--------------------------------------*\
	|*		Methode			*|
	 \*-------------------------------------*/

    public:

	/**
	 * virtual permet de la redefinir dans la classe deriver
	 */
	virtual void print();

	/**
	 * ne peut pas etre redefini dans classe deriver
	 */
	void set(int heure, int minute);

	/*--------------------------------------*\
	|*		Attribut		*|
	 \*-------------------------------------*/

    private:

	// Inputs
	string title;
	int heure;
	int minute;

    };

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
