#include "TestSliceSM.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
|*		Imported	 	*|
 \*-------------------------------------*/
extern bool isSliceNewOK();

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
    TEST_ASSERT(isSliceNewOK());
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
