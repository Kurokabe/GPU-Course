#pragma once

#include "cpptest.h"

class TestCalculatrice: public Test::Suite
    {

	/*--------------------------------------*\
	 |*		Constructeur		*|
	 \*-------------------------------------*/

    public:

	TestCalculatrice();

	virtual ~TestCalculatrice();

	/*--------------------------------------*\
	 |*		Methode			*|
	 \*-------------------------------------*/

    private:

	void testAdd();

	void testMult();

	void testSub();

	void testGet();

    };

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

