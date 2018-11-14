#include "../../02_derivate/deriver/HeureMinuteSeconde.h"

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

/**
 * constructeur principal
 */
HeureMinuteSeconde::HeureMinuteSeconde(string title, int heure, int minute, int seconde) :
	HeureMinute(title, heure, minute), seconde(seconde)
    {
    // rien
    }

/**
 * call constructeur dominant
 */
HeureMinuteSeconde::HeureMinuteSeconde(string title) :
	HeureMinuteSeconde(title, 0, 0,0)
    {
    // rien de plus
    }

/**
 * constructeur classe parente appeler automatiquement
 */
HeureMinuteSeconde::~HeureMinuteSeconde()
    {
    // rien, car aucun new dans le constructeur
    }

/*--------------------------------------*\
 |*		Methode			*|
 \*-------------------------------------*/

/**
 * override
 */
void HeureMinuteSeconde::print()
    {
    HeureMinute::print();
    cout << seconde << "(s) ";
    }

void HeureMinuteSeconde::set(int heure, int minute, int seconde)
    {
    //set(heure, minute);// compile pas
    HeureMinute::set(heure, minute);

    this->seconde = seconde;
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

