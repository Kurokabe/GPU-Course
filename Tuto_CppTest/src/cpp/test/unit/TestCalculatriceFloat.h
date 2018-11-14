#pragma once

#include "cpptest.h"
#include "CalculatriceFloat.h"

class TestCalculatriceFloat: public Test::Suite
    {
    public:

	TestCalculatriceFloat(void)
	    {
	    TEST_ADD(TestCalculatriceFloat::testAddition);
	    TEST_ADD(TestCalculatriceFloat::testFois);
	    }

    private:

	void testAddition(void)
	    {
	    TEST_ASSERT(CalculatriceFloat::sum(2, 3) == 5);
	    TEST_ASSERT(CalculatriceFloat::sum(-2, 3) == 1.0);
	    }

	void testFois(void)
	    {
	    TEST_ASSERT(CalculatriceFloat::fois(2, 3) == 6);
	    TEST_ASSERT(CalculatriceFloat::fois(-2, 3) == -6);
	    }
    };

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

