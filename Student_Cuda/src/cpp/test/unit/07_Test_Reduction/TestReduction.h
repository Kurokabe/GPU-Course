#pragma once
#include "cpptest.h"

 /*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

class TestReduction: public Test::Suite
    {

	/*--------------------------------------*\
        |*		Constructor		*|
	 \*--------------------------------------*/
    public:
	TestReduction();

	/*--------------------------------------*\
	|*		Methode			*|
	 \*--------------------------------------*/
    private:
	void testReductionAtomicI(void);
	void testReductionAtomicII(void);
	void testReductionLockI(void);
	void testReductionLockII(void);
    };

 /*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
