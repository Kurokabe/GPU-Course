#pragma once

#include "cpptest.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

class TestVector: public Test::Suite
    {
	/*--------------------------------------*\
	|*		Constructor		*|
	 \*-------------------------------------*/

    public:

	TestVector();

	/*--------------------------------------*\
	|*		Methode			*|
	 \*-------------------------------------*/

    private:

	void testAddition(void);

	void testAddition64(void);

	void testAddition128(void);

	void testAddition256(void);

	void testAddition512(void);

	void testAddition1024(void);

	/**
	 * multiple
	 */
	void testAdditionGrid(void);

	/*--------------------------------------*\
	|*		Attribut		*|
	 \*-------------------------------------*/

    private:

	// rien

    };

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

