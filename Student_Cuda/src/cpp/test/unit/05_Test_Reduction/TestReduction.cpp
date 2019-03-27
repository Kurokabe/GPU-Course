#include "TestReduction.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
|*		Imported	 	*|
 \*-------------------------------------*/
extern bool isReductionAddTools_I_Ok();
extern bool isReductionAddTools_II_Ok();
extern bool isReductionAddToolsLock_I_Ok();
extern bool isReductionAddToolsLock_II_Ok();

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Constructor		*|
 \*-------------------------------------*/
TestReduction::TestReduction()
    {
    TEST_ADD(TestReduction::testReductionAtomicI);
    TEST_ADD(TestReduction::testReductionAtomicII);
    TEST_ADD(TestReduction::testReductionLockI);
    TEST_ADD(TestReduction::testReductionLockII);
    }

/*--------------------------------------*\
|*		Methodes		*|
 \*-------------------------------------*/
void TestReduction::testReductionAtomicI(void)
    {
    TEST_ASSERT(isReductionAddTools_I_Ok());
    }

void TestReduction::testReductionAtomicII(void)
    {
    TEST_ASSERT(isReductionAddTools_II_Ok());
    }

void TestReduction::testReductionLockI(void)
    {
    TEST_ASSERT(isReductionAddToolsLock_I_Ok());
    }

void TestReduction::testReductionLockII(void)
    {
    TEST_ASSERT(isReductionAddToolsLock_II_Ok());
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

