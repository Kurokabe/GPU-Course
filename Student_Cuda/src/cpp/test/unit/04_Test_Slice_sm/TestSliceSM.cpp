#include "TestSliceSM.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
|*		Imported	 	*|
 \*-------------------------------------*/
extern bool isSliceSMOK();

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/


/*--------------------------------------*\
 |*		Constructor		*|
 \*-------------------------------------*/
TestSliceSM::TestSliceSM()
    {
    TEST_ADD(TestSliceSM::testSliceSM);
    }

/*--------------------------------------*\
|*		Methodes		*|
 \*-------------------------------------*/
void TestSliceSM::testSliceSM(void)
    {
    TEST_ASSERT(isSliceSMOK());
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

