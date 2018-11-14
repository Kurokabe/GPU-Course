#include "Calculatrice.h"

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
 * constructeur dominant
 */
Calculatrice::Calculatrice(string marque) :
	marque(marque) // syntaxe c++ n'est pas celle du java, piqure de rappel. dans () : c'est l'input
    {
    // rien de plus
    }

/**
 * appelle le constructeur dominant
 */
Calculatrice::Calculatrice() :
	Calculatrice("no marque")
    {
    // rien de plus
    }

Calculatrice::~Calculatrice()
    {
    // rien, car pas de new dans constructeur
    }

/*--------------------------------------*\
 |*		Methode			*|
 \*-------------------------------------*/

string Calculatrice::getMarque()
    {
    return this->marque;
    }

double Calculatrice::add(double x, double y)
    {
    return x + y;
    }

void Calculatrice::mult(double x, double y, double* ptrResult)
    {
    *ptrResult = x * y; // use * devant ptr pour changer son contenu
    }

/**
 * static
 */
double Calculatrice::sub(double x, double y)
    {
    return x - y;
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

