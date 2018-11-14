#include "../../02_derivate/base/HeureMinute.h"

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
 *
 * 2 possibilities pour l'attribut
 */
HeureMinute::HeureMinute(string titre, int heure, int minute) :
	title(titre), heure(heure)
    {
    this->minute = minute;
    }

/**
 * call constructeur principal
 */
HeureMinute::HeureMinute(string titre): HeureMinute(titre,0,0)
    {
    // rien de plus
    }

HeureMinute::~HeureMinute()
    {
    // rien, car aucun new dans le constructeur
    }

/*--------------------------------------*\
 |*		Methode			*|
 \*-------------------------------------*/

void HeureMinute::print()
    {
    cout <<title<<" : "<< heure << "(h) " << minute << "(m) ";
    }

void HeureMinute::set(int heure, int minute)
    {
    this->heure = heure;
    this->minute = minute;
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

