#include "TestScalar.h"

#include "Device.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Imported	 	*|
 \*-------------------------------------*/

extern bool isAddScalarGPU_proceduraleOk(void);
extern bool isAddScalarGPU_ObjetOk();

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Constructor		*|
 \*-------------------------------------*/

TestScalar::TestScalar()
    {
    TEST_ADD(TestScalar::testProcedurale);
    TEST_ADD(TestScalar::testObjet);
    }

/*--------------------------------------*\
 |*		Methodes		*|
 \*-------------------------------------*/

void TestScalar::testProcedurale(void)
    {
    TEST_ASSERT(isAddScalarGPU_proceduraleOk());
    }

void TestScalar::testObjet(void)
    {
    TEST_ASSERT(isAddScalarGPU_ObjetOk());
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

