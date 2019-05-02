#include "TestMonteCarloLong.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
|*		Imported	 	*|
 \*-------------------------------------*/
extern bool isMonteCarloLongOK();

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Constructor		*|
 \*-------------------------------------*/
TestMonteCarloLong::TestMonteCarloLong()
    {
    TEST_ADD(TestMonteCarloLong::testMonteCarloLong);
    }


/*--------------------------------------*\
|*		Methodes		*|
 \*-------------------------------------*/
void TestMonteCarloLong::testMonteCarloLong(void)
    {
    TEST_ASSERT(isMonteCarloLongOK());
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
