#include "TestCalculatrice.h"
#include "Calculatrice.h"

using std::string;

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

TestCalculatrice::TestCalculatrice()
    {
    TEST_ADD(TestCalculatrice::testAdd);
    TEST_ADD(TestCalculatrice::testMult);
    TEST_ADD(TestCalculatrice::testSub);
    TEST_ADD(TestCalculatrice::testGet);
    }

TestCalculatrice::~TestCalculatrice()
    {
    // rien
    }

/*--------------------------------------*\
 |*		Methode			*|
 \*-------------------------------------*/

void TestCalculatrice::testAdd()
    {
    Calculatrice calculatrice("hp");

    TEST_ASSERT(calculatrice.add(1, 10) == 11);
    TEST_ASSERT(calculatrice.add(2, 20) == 22);
    }

void TestCalculatrice::testMult()
    {
    Calculatrice calculatrice("hp");

    double result;
    calculatrice.mult(2, 20, &result);
    TEST_ASSERT(result == 40);
    }

void TestCalculatrice::testSub()
    {
    TEST_ASSERT(Calculatrice::sub(100, 1) == 99);
    TEST_ASSERT(Calculatrice::sub(100, 2) == 98);
    }

void TestCalculatrice::testGet()
    {
    string marque="hp";
    Calculatrice calculatrice(marque);

    TEST_ASSERT(calculatrice.getMarque() == marque);
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

