#include <stdlib.h>
#include <iostream>

#include "point.h"

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

void useStructure(void);

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

static void use1(void);
static void use2(void);
static void use3(void);
static void use4(void);
static void usecppp11(void);

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

void useStructure(void)
    {
    cout << "\nuseStructure" << endl;

    // cpp
	{
	use1();
	use2();
	use3();
	use4();
	}

    usecppp11();
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

void use1(void)
    {
    double2 position;
    position.x = 2.0;
    position.y = 3.0;

    cout << position.x << endl;
    cout << position.y << endl;
    }

void use2(void)
    {
    double2 position = double2(20.0, 30.0); // ok ssi constructeur dans double2

    cout << position.x << endl;
    cout << position.y << endl;
    }

/**
 * best, simplier
 */
void use3(void)
    {
    double2 position(20, 30); // ok ssi constructeur dans double2

    cout << position.x << endl;
    cout << position.y << endl;
    }

void use4(void)
    {
    double2 position(20, 30);
    point paris(position, "paris");

    cout << endl;
    cout << paris.label << endl;
    cout << paris.position.x << endl;
    cout << paris.position.y << endl;
    cout << endl;
    }

void use5(void)
    {
    point paris(20, 30, "paris");

    cout << endl;
    cout << paris.label << endl;
    cout << paris.position.x << endl;
    cout << paris.position.y << endl;
    cout << endl;
    }

void usecppp11()
    {
    // v1
	{
	double2 position = double2{20.0, 30.0}; // ok sans constructeur dans double2

	cout << position.x << endl;
	cout << position.y << endl;
	}

    // v2
	{
	double2 position ={200.0, 300.0}; // ok sans constructeur dans double2

	cout << position.x << endl;
	cout << position.y << endl;
	}
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

