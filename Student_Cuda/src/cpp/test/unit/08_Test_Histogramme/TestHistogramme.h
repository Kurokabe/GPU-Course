#pragma once
#include "cpptest.h"

 /*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

class TestHistogramme: public Test::Suite
    {

	/*--------------------------------------*\
        |*		Constructor		*|
	 \*--------------------------------------*/
    public:
	TestHistogramme();

	/*--------------------------------------*\
	|*		Methode			*|
	 \*--------------------------------------*/
    private:
	void testHistogrammeSum(void);
	void testHistogrammeValues(void);
    };

 /*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
