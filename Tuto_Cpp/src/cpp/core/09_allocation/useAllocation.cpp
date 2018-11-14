#include <stdlib.h>
#include <iostream>
#include <assert.h>

#include "Personne.h"

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

void useAllocation(void);

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

static void use1(void);
static void use2(void);
static void use3(void);
static void use4(void);

static void add(int x, int y, int* ptrResultat);
static void work(double* ptrTab, int n);

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

void useAllocation(void)
    {
    cout << "\nTab : useAllocation" << endl;

    use1();
    use2();
    use3();

    // Tableau de personne
	{
	use4();
	}
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/**
 * heap, size en GO
 */
void use1(void)
    {
    // sur le le tas, c++
	{
	int n = 3;
	double* ptrTab = new double[n];

	work(ptrTab, n);

	delete[] ptrTab; // 1 new <--> 1 delete dans le meme scoop, par le meme developpeur
	}

    // sur le tas, C
	{
	int n = 3;

	size_t sizeOctet = n * sizeof(double); //unit size_t  is octet, as  sizeof
	double* ptrTab = (double*) malloc(sizeOctet);

	work(ptrTab, n);

	free(ptrTab); // 1 malloc <--> 1 free dans le meme scoop, par le meme developpeur
	}
    }

/**
 * stack, size en KO
 */
void use2(void)
    {
    // sur la pile, possible si tab petit, sinon deconseiller
	{
	int n = 3; // const : plus necessaire!
	double tab[n];

	work(tab, n);
	} // tab depiler et detruit
    }

/**
 * Piege
 */
void use3(void)
    {
    int x = 10;
    int y = 101;

    // musee des horeurs
	{
//	int* ptrResultat=NULL; // Catastrophe! Compile mais aucune allocation pour placer le résultat! segmentation fault a l'execution de add
//
//    	add(x, y, ptrResultat); // segmentation fault car aucune place allouer pour l'adresse pointer par ptrResultat
//
//    	assert(*ptrResultat == x+y);
	}

    // good:
	{
	int resultat; // allocation

	add(x, y, &resultat); // on passe l'adresse, le contenu de l'adresse sera modifier

	assert(resultat == x + y);
	}
    }

void add(int x, int y, int* ptrResultat)
    {
    *ptrResultat = x + y;
    }

/**
 * by example
 */
void work(double* ptrTab, int n)
    {
    // fill
	{
	for (int i = 0; i < n; i++)
	    {
	    ptrTab[i] = i + 1;
	    }
	}

    // print
	{
	for (int i = 0; i < n; i++)
	    {
	    cout << ptrTab[i] << "\t";
	    }
	cout << endl << endl;
	}
    }

/**
 * Java:
 *
 * 	Personne[] tab=new Personne[n];	// tabeleau contient des referrence de personnes, pour l'instant ces referrence songt null
 * 	Warning : la ligne ci-dessus instancie un unique objet : le tableau
 *
 * c++ : v1 : best
 *
 * 	Personne** tab=new Personne*[n]; // tabeleau contient des pointeurs de personnes, pour l'instant ces pointeurs pointent sur rien
 * 	Warning : la ligne ci-dessus instancie un unique objet : le tableau
 *
 * c++ : v2 : casse guele
 *
 * 	Personne* tab=new Personne[n]; // tabeleau contient des personnes, il en contient déjà!
 * 	Warning : la ligne ci-dessus instancie n+1 objet : le tableau et n personnes. Les personnes sont instancier avec le constructeur vide. Celui-ci est necessaire pour que sa compile
 */
void use4()
    {
    int n = 3;

    // v1
	{
	Personne** tab = new Personne*[n]; // instancie 1 objet, le tableau

	cout << "#instance Personne = " << Personne::getCompteurIntance() << endl;
	assert(Personne::getCompteurIntance() == 0);
	}

    // v2
	{
	Personne* tab = new Personne[n]; // instancie n+1 objet, requiert constructeur vide pour compiler

	cout << "#instance Personne = " << Personne::getCompteurIntance() << endl;
	assert(Personne::getCompteurIntance() == 3);

	// print tab, on voit les n personnes deja, elles existent!
	for (int i = 0; i < n; i++)
	    {
	    cout << tab[i] << endl;
	    }

	// voir chapitre advanced pour stratégie de peuplement d'un tel tableau!
	// Conseil : utiliser plutot la version v1 en pratique, moins casse gueule: Personne** tab = new Personne*[n];
	}
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

