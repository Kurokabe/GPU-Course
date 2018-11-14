#include "TestVector.h"

#include "Device.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Imported	 	*|
 \*-------------------------------------*/

extern bool isAddVecteurOk(int n);
extern bool isAddVecteurOk(const Grid& grid, int n);

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Constructor		*|
 \*-------------------------------------*/

TestVector::TestVector()
    {
    TEST_ADD(TestVector::testAddition);
    TEST_ADD(TestVector::testAddition64);
    TEST_ADD(TestVector::testAddition128);
    TEST_ADD(TestVector::testAdditionGrid);
    }

/*--------------------------------------*\
 |*		Methodes		*|
 \*-------------------------------------*/

void TestVector::testAddition(void)
    {
    int n=9;

    for(int i=2;i<=n;i++)
	{
	 TEST_ASSERT(isAddVecteurOk(i));
	}
    }

void TestVector::testAddition64(void)
    {
    int n=9;

    dim3 dg = dim3(48, 1, 1);
    dim3 db = dim3(64, 1, 1);
    Grid grid(dg, db);

    TEST_ASSERT(isAddVecteurOk(grid,n));
    }

void TestVector::testAddition128(void)
    {
    int n=9;

    dim3 dg = dim3(48, 1, 1);
    dim3 db = dim3(128, 1, 1);
    Grid grid(dg, db);

    TEST_ASSERT(isAddVecteurOk(grid,n));
    }

void TestVector::testAddition256(void)
    {
    int n=9;

    dim3 dg = dim3(48, 1, 1);
    dim3 db = dim3(256, 1, 1);
    Grid grid(dg, db);

    TEST_ASSERT(isAddVecteurOk(grid,n));
    }

void TestVector::testAddition512(void)
    {
    int n=9;

    dim3 dg = dim3(48, 1, 1);
    dim3 db = dim3(512, 1, 1);
    Grid grid(dg, db);

    TEST_ASSERT(isAddVecteurOk(grid,n));
    }

void TestVector::testAddition1024(void)
    {
    int n=9;

    dim3 dg = dim3(48, 1, 1);
    dim3 db = dim3(1024, 1, 1);
    Grid grid(dg, db);

    TEST_ASSERT(isAddVecteurOk(grid,n));
    }

void TestVector::testAdditionGrid(void)
    {
    int n=9;

    const int NB_DEVICE = Device::getDeviceCount();

    //#pragma omp paralle for
    for (int deviceId = 0; deviceId < NB_DEVICE; deviceId++)
	{
	Device::setDevice(deviceId);

	// Dépend du device
	int MP = Device::getDeviceCount(); // 24 M6000
	int MAX_THEAD_BLOCK = Device::getMaxThreadPerBlock(); // 1024
	int MP_MAX = 96; // disons

	for (int g = MP; g <= MP_MAX; g = g * 2)
	    {
	    for (int b = 64; b <= MAX_THEAD_BLOCK; b = b * 2)
		{
		dim3 dg = dim3(g, 1, 1); // 1D
		dim3 db = dim3(b, 1, 1); // 1D
		Grid grid(dg, db);

		TEST_ASSERT(isAddVecteurOk(grid,n));
		}
	    }
	}

    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

