#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <assert.h>

#include "Array.h"

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

void useAdvanced(void);

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

static void use1(void);
static void use2(void);
static void use3(void);
static void use4(void);

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

void useAdvanced(void)
    {
    cout << "\nArray : useAdvanced" << endl;

    use1();
    use2();

    // tableau de Array
	{
	use3();
	use4();
	}
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

void use1(void)
    {
    cout << "\nArrays : use1" << endl;

    // scoop
	{
	int n = 3;
	Array array(n);
	array.init(33);

	assert(n == array.size());

	cout << array; //use surcharge de <<
	} // Fin du scoop : destruction de array et de l'attribut tab de double*
    cout << "array shoud be deleted now" << endl;
    }

/**
 * preuve de la necessite de constructeur de copie dans une classe possédant un attribut de type pointeur
 *
 * Mettez dans la classe Array en commentaire le constructeur de copie (.h et .cpp) pour voir la différence de l'execution du code ci-dessous:
 * crash, car il y a une copie superficielle de la zone memoire allouer avec new, et qu'une seule destruction de cette zone peut etre realiser.
 * Le crash se produit lors de la tentative de delete de la deuxieme instance.
 */
void use2(void)
    {
    cout << "\nArrays : use2" << endl;

    // scoop
	{
	int n = 4;
	Array array(n, 44);

	Array arrayCopy = array; // Superficiel ou profond?
	// Warning:
	//	si constructeur copie existe pas
	//		- copy superficielle
	//		- copy octet par octet des attributs, donc le ptr tab est copier, mais pas son contenu
	//	si constructeur copie existe
	//		- copy profonde
	//		- ptr comme son contenu sont cloner

	// on modifie la source et la copy
	array.getPtr()[0] = -44;
	arrayCopy.getPtr()[1] = -44;

	// on regarde les conséquences des modifications
	cout << array;
	cout << arrayCopy;
	} // fin du scoop : array et arrayCopy detruit

    // Analyse du probelem de destruction a la fin du scoop:
    //
    // Destruction des deuy instances de array:
    //		- array
    //		- arrayCopy
    //
    // Warning:
    //		si constructeur copie existe pas:
    //			- la premiere destruction reussi
    //			- la seconde destruction crash car, tab partager dans les deux instances, est deja detruite dans la premiere instance et ne peut plus etre detruite dans la deuxieme
    // 		siconstructeur copie existe:
    //			- tout marche comme sur des roulettes, car deux instances de l'attribut tab existent, et les deux destructions sont possibles
    }

/**
 * tableau de Array, ou on met des Array* dans le tableau
 * conseiller!
 * Pas trop de soucis!
 */
void use3(void)
    {
    cout << "\nArrays : use3" << endl;

    // scoop
	{
	int n = 4;
	Array array1(n, 66);
	Array array2(n, 77);

	Array** tab = new Array*[2];
	tab[0] = &array1;
	tab[1] = &array2;

	// on modifie les originaux
	array1.getPtr()[0] = -66;
	array2.getPtr()[0] = -77;

	// on affiche ceux dans tab, les mêmes, avec -66 et -77 : ok, naturelle!
	cout << *tab[0];
	cout << *tab[1];

	delete[] tab; // 1 new <--> 1 delete dans meme scoop, par meme developpeur
	} // apelle 2x destructeur de Array, car 2 instances
    }

/**
 * tableau de Array, ou on met des Array dans le tableau, et non plus des Array* comme ci-dessus
 * Deconseiller!
 *
 * requiert constructeur vide dans Array
 * requiert surcharge de =
 *
 * Mettez dans la classe Array en commentaire la surcharge de = (.h et .cpp) pour voir la différence de l'execution du code ci-dessous
 */
void use4(void)
    {
    cout << "\nArrays : use4" << endl;

    // scoop
	{
	int n = 4;
	Array array1(n, 66);
	Array array2(n, 77);

	Array* tab = new Array[2]; // cree 3 objets: le tab, et deux array a ranger dans la case 0 et la case 1. requiert un constructeur vide dans Array
	tab[0] = array1; // Ecrasement? transfert du contenu? clone? copie superficielle?
	tab[1] = array2; // Ecrasement? transfert du contenu? clone? copie superficielle?
	// Warning:
	//	si operator = pas surcharger
	//		- copy superficielle
	//		- copy octet par octet des attributs, donc l'adresse du ptr tab est copier, mais pas son contenu
	//		- deux instances différentes, mais tab pointe vers la même adresse memoire
	//	si operator =  surcharger
	//		- adaptation size et transfert du contenu
	//		- deux instances différente, soure et clone
	//
	// Attention : Constructeur de copie pas utiliser ici, car destination existe deja! preuve : aucune apparition dans la console
	//		Il n'intervient que quand le destination existe pas.
	//		Ici la destination existe! tab[0] contient une instance de Array à 0 case

	// on modifie les originaux
	array1.getPtr()[0] = -66;
	array2.getPtr()[0] = -77;
	cout << array1;
	cout << array2;

	// on affiche ceux dans tab
	cout << tab[0];
	cout << tab[1];
	// Warning:
	//	si operator = pas surcharger
	//		- -66 et -77
	//		-  2 instances, mais copie superficielle
	//	si operator =  surcharger
	//		- 66 et 77 car pas meme instance, et clone

	delete[] tab; // 1 new <--> 1 delete dans meme scoop, par meme developpeur

	cout<<"Fin scoop"<<endl;
	} // Fin du scoop
	  // apelle 4x destructeur de Array, car 4 instances.
	  // si operator = pas surcharger, delete[] de Array.tab: apeller pour l'originale et pour la copie superficielle.
	  // Si la zone memoire allouer est partager: un crash a lieu losque la deuxime instance essaye de la detruire: elle ne peut etre deleter qu'une seule fois.

    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

