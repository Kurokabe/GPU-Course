#pragma once

#include <iostream>

#include "../../02_derivate/base/HeureMinute.h"

using std::cout;
using std::endl;
using std::string;

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

class HeureMinuteSeconde: public HeureMinute
    {

	/*--------------------------------------*\
	|*		Constructeur		*|
	 \*-------------------------------------*/

    public:

	HeureMinuteSeconde(string titre, int heure, int minute, int seconde);

	HeureMinuteSeconde(string titre);

	virtual ~HeureMinuteSeconde();

	/*--------------------------------------*\
	|*		Methode			*|
	 \*-------------------------------------*/

    public:

	/**
	 * Override
	 */
	virtual void print();

	void set(int heure, int minute, int seconde);

	/*--------------------------------------*\
	|*		Attribut		*|
	 \*-------------------------------------*/

    private:

	// Inputs
	int seconde;

    };

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
