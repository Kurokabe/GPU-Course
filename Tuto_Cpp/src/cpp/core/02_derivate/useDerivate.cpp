#include <stdlib.h>
#include <iostream>

#include "HeureMinuteSeconde.h"

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

void useDerivate(void);

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

void useDerivate(void)
    {
    cout << "\nDerivate : useTime" << endl;

    //HeureMinute
	{
	use1();
	use2();
	use3();
	}

    use4();
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

void use1(void)
    {
    HeureMinute heureMinute("Tissot", 23, 59);
    heureMinute.print();
    cout << endl;
    }

void use2(void)
    {
    HeureMinute heureMinute = HeureMinute("Tissot", 23, 59);
    heureMinute.print();
    cout << endl;
    }

void use3(void)
    {
    HeureMinute* ptrHeureMinute = new HeureMinute("Tissot", 23, 59);
    ptrHeureMinute->print();
    cout << endl;

    delete ptrHeureMinute;
    }

void use4(void)
    {
    HeureMinuteSeconde heureMinuteSeconde("Tissot", 23, 59, 30);
    heureMinuteSeconde.print();
    cout << endl;

    heureMinuteSeconde.set(22, 58, 29);
    heureMinuteSeconde.print();
    cout << endl;

    //heureMinuteSeconde.set(21, 57); // compile pas
    heureMinuteSeconde.HeureMinute::set(21, 57); // compile
    heureMinuteSeconde.print();
    cout << endl;

    HeureMinuteSeconde heureMinuteSeconde000("Tissot");
    heureMinuteSeconde000.print();
    cout << endl;
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

