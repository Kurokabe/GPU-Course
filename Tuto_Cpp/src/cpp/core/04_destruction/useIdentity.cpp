#include <stdlib.h>
#include <iostream>

#include "Identity1.h"
#include "Identity2.h"


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

void useDestruction(void);

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

void useDestruction(void)
    {
    cout << "\nDestruction : useIdentity" << endl;

    use1();
    cout << endl;
    use2();
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

void use1(void)
    {
    int n = 3;
    double* ptrTab= NULL;

    // scoop
	{
	Identity1 identity(n);

	identity.print();

	ptrTab = identity.get();
	} // fin de vie de l'objet identity

    cout << "Warning : object identity delete, et donc ptrTab aussi!" << endl;

    Identity1::print(ptrTab, n); // faux car ptrTab delete, espace memoire liberer par l'OS et potentiellement reutilisable!
    }

void use2(void)
    {
    int n = 3;
    double* ptrTab = new double[n * n];

    Identity2 identity(n, ptrTab);

    identity.print();

    delete[] ptrTab; // celui qui crée détruit
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

