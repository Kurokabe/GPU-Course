#pragma once

#include "cpptest.h"
#include "CalculatriceInt.h"

class TestCalculatriceInt: public Test::Suite
    {
    public:

	TestCalculatriceInt(void)
	    {
	    TEST_ADD(TestCalculatriceInt::testAddition);
	    TEST_ADD(TestCalculatriceInt::testFois);
	    }

    private:

	void testAddition(void)
	    {
	    int a = 2;
	    int b = 3;

	    TEST_ASSERT(CalculatriceInt::plus(a, b) == 5);
	    TEST_ASSERT(CalculatriceInt::plus(-a, b) == 1);
	    }

	void testFois(void)
	    {
	    int a = 2;
	    int b = 3;

	    TEST_ASSERT(CalculatriceInt::fois(a, b) == 6);
	    TEST_ASSERT(CalculatriceInt::fois(-a, b) == -6);
	    }
    };

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

