#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <assert.h>

#include "Calculatrice.h"

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

void useHello(void);

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

static void use0(void);
static void use1(void);
static void use2(void);
static void use3(void);

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

/**
 * see too unit test
 * /src/cpp/test
 */
void useHello(void)
    {
    cout << "\nHello : useCalculatrice" << endl;

    use0();
    use1();
    use2();
    use3();
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/**
 * instanciation
 */
void use0(void)
    {
    // v1
	{
	Calculatrice calculatrice("hp");

	cout << calculatrice.getMarque() << endl;
	}

    // v2
	{
	Calculatrice calculatrice = Calculatrice("hp");

	cout << calculatrice.getMarque() << endl;
	}

    // v3
	{
	Calculatrice calculatrice;

	cout << calculatrice.getMarque() << endl;
	}

    // v4
	{
	Calculatrice* ptrCalculatrice = new Calculatrice("hp");

	cout << ptrCalculatrice->getMarque() << endl;

	delete ptrCalculatrice; // le developeur qui utilise new, doit utiliser delete, dans le même scoop, ou dans la même classe
	}
    }

/**
 * methode d'instance (non static)
 */
void use1(void)
    {
    int x = 1;
    int y = 10;

    Calculatrice calculatrice;

    // usea
	{
	int result = calculatrice.add(x, y);

	cout << result << endl;
	assert(result == x + y);
	}

    // useb
	{
	//double* resultat; // serait faux, car aucune allocation pour mettre le resultat quelque part
	double resultat;// allocation
	calculatrice.mult(x, y, &resultat);// on passe l'adresse de l'allocation

	cout << resultat << endl;
	assert(resultat == x * y);
	}
    }

/**
 * sur le tas, pointeur
 *
 * cout
 * printf
 */
void use2(void)
    {
    Calculatrice* ptrCalculatrice = new Calculatrice("hp");

    // use a
	{
	int x = 1;
	int y = 10;
	int result = ptrCalculatrice->add(x, y);

	printf("%d + %d = %d\n", x, y, result);
	cout << x << " + " << y << " = " << result << endl;

	// check
	assert(result == x + y);
	}

    delete ptrCalculatrice;
    }

/**
 * methode de classe (methode static)
 */
void use3(void)
    {
    cout << Calculatrice::sub(100, 1) << endl;

    assert(Calculatrice::sub(88, 8) == 80);
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

