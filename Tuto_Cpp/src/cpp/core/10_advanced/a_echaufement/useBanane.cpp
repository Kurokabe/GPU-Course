#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <assert.h>

#include "Banane.h"

using std::cout;
using std::endl;

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Imported	 	*|
 \*-------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

void useAdvancedSimple(void);

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

static void use1(void);
static void use2(void);

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

/**
 * Rappel C++
 *
 * 	Banane b1(...);
 * 	Banane b2(...);
 *
 * 	Banane bCopy1=b1; 	// Utilise le constructeur de copie (CC) de Banane
 * 	Banane b2=b1;		// Utilise la surcharge de l'operateur =
 *
 * 	Banane tab[N]; 		// N+1 objet creer, le tableau et N Banane avec le constructeur sans parametre.
 * 	tab[0]=b1; 		// Utilise la surcharge de l'operateur = car tab[0] contient deja une banane!
 *
 * Important:
 *
 * 	La surcharge de l'operateur = est utilisez quand l'objet de destination existe deja.
 * 	Si l'objet de destination doit etre crer, c'est le CC qui est utiliser.
 *
 * Note:
 *
 * 	Par defaut toute classe possede:
 *
 * 		- un cc
 * 		- un operateur =
 *
 * 	Dans les deux cas, les attributs sont copiers bit a bit!
 * 	sauf si un cc ou une surcharge de = existe.
 *
 * Consequence:
 *
 * 	Si une classe possede un attribut de type ptr, lors d'une copie par CC ou =, l'adresse sera copie bit a bit.
 * 	On se retrouvera non pas avec un clone mais avec une adresse partager dans deux instances!
 * 	Le deuxieme objet detruit ne pourra plus detruire sont attributs de type ptr, qui a deja ete detruit par la premiere instance.
 *
 * 	Toute classe possedant un attribut de type ptr devrait
 *
 * 		- soit interdire toute copie (ni cc, ni surcharge =). Il suffit de les mettre private avec un corps vide!
 * 		- soit implementer explicitement (cc et surcharge =) pour effectuer des copies profondes des attributs de type ptr
 *
 *      et ceci de maniere recursive sur les objets inclus dans l'element pointer par ptr!
 *
 * Resumer :
 *
 * 	Si T contient un prt, il est conseiller:
 *
 * 	soit, avec une semantique : En public:
 *
 * 		- de surcharger = pour T
 * 		- d'implementer un CC pour T
 *
 * 	soit, sans semantique: En private:
 *
 * 		- de surcharger = pour T		(implementation vide)
 * 		- d'implementer un CC pour T		(implementation vide)
 **/
void useAdvancedSimple(void)
    {
    cout << "\nBanane : useAdvancedSimple" << endl;

    use1();
    use2();
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/**
 * Mettez en commentaire dans la classe Banane (.h et .cpp):
 * 	- la surcherge de =
 * 	- le constructeur de copie (CC)
 *
 * Les résutats du codes ci-dessous seront different,les assertions ne reussisent plus, et le code va meme planter!
 */
void use1(void)
    {
    cout << "\nBanane : use1:" << endl;

    Banane::resetCompteurInstance();

    Banane b1(10, 1);
    Banane b2(20, 2);
    Banane b(100, 100);

    assert(Banane::getCompteurIntance() == 3);

    b = b2;	// utilise surcharge de =, car b existe deja

    assert(Banane::getCompteurIntance() == 3);

    Banane b1Clone = b1;	// utilise CC, car b1Clone n'existe pas encore

    assert(Banane::getCompteurIntance() == 4);

    // check 1
	{
	b1.setPrix(99);

	cout << b1 << endl;
	cout << b1Clone << endl;

	assert(b1Clone.getPrix() == 1);
	assert(b1.getPrix() == 99);
	}

    // check 2
	{
	assert(b.getPrix() == 2);
	b2.setPrix(88);
	assert(b.getPrix() == 2);
	assert(b2.getPrix() == 88);
	}
    }

/**
 * Mettez en commentaire dans la classe Banane (.h et .cpp):
 * 	- la surcherge de =
 * 	- le constructeur de copie (CC)
 *
 * Les résutats du codes ci-dessous seront different et les assertions ne reussisent plus!
 */
void use2(void)
    {
    cout << "\nBanane : use2:" << endl;

    Banane::resetCompteurInstance();

    int n = 2;
    Banane b1(10, 1);
    Banane b2(20, 2);

    assert(Banane::getCompteurIntance() == 2);

    Banane tab[n]; // n bananes creer avec constructeur vide

    assert(Banane::getCompteurIntance() == 2 + n);

    // Affiche bien des bananes existantes, avec contenu -1 du constructeur sans parametre
	{
	cout << tab[0];
	cout << tab[1] << endl;
	}

    tab[0] = b1;	// utilise surcharge de =, car  tab[0] contient deja une banane
    tab[1] = b2; 	// utilise surcharge de =, car  tab[0] contient deja une banane

    assert(Banane::getCompteurIntance() == 2 + n); // aucune banane recreer. Juste ci-dessus : transfert du contenu avec surcharge de =

    // Affiche bien des bananes existantes, avec cette fois-ci le contenu de b1 et b2
	{
	cout << tab[0];
	cout << tab[1] << endl;
	}

    // check
	{
	b1.setPrix(88);
	b2.setPrix(99);

	// Toujours 1 et 2
	cout << tab[0];
	cout << tab[1] << endl;
	assert(tab[0].getPrix() == 1);
	assert(tab[1].getPrix() == 2);

	// 88 et 99
	cout << b1;
	cout << b2 << endl;
	assert(b1.getPrix() == 88);
	assert(b2.getPrix() == 99);
	}
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

