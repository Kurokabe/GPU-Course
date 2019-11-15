#include "../08_Test_Histogramme/TestHistogramme.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
|*		Imported	 	*|
 \*-------------------------------------*/
extern bool isHistogrammeOKSum();
extern bool isHistogrammeOKValues();

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Constructor		*|
 \*-------------------------------------*/
TestHistogramme::TestHistogramme()
    {
    TEST_ADD(TestHistogramme::testHistogrammeSum);
    TEST_ADD(TestHistogramme::testHistogrammeValues);
    }

/*--------------------------------------*\
|*		Methodes		*|
 \*-------------------------------------*/
void TestHistogramme::testHistogrammeSum(void)
    {
    TEST_ASSERT(isHistogrammeOKSum());
    }

void TestHistogramme::testHistogrammeValues(void)
    {
    TEST_ASSERT(isHistogrammeOKValues());
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

