#include "TestSlice.h"
#include "Device.h"
/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
|*		Imported	 	*|
\*-------------------------------------*/

extern bool isSliceOK();
extern bool isSliceOK(const Grid& grid);

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Constructor		*|
 \*-------------------------------------*/
TestSlice::TestSlice()
    {
    TEST_ADD(TestSlice::testSlice);
    TEST_ADD(TestSlice::testSlice64);
    TEST_ADD(TestSlice::testSlice128);
    TEST_ADD(TestSlice::testSlice256);
    TEST_ADD(TestSlice::testSlice512);
    TEST_ADD(TestSlice::testSlice1024);
    }


/*--------------------------------------*\
|*		Methodes		*|
\*-------------------------------------*/

void TestSlice::testSlice(void)
    {
    TEST_ASSERT(isSliceOK());
    }


void TestSlice::testSlice64(void) {
    dim3 dg=dim3(64,1,1);
    dim3 db=dim3(64,1,1);
    Grid grid(dg, db);
    TEST_ASSERT(isSliceOK(grid));
}

void TestSlice::testSlice128(void) {
    dim3 dg=dim3(64,1,1);
    dim3 db=dim3(128,1,1);
    Grid grid(dg, db);
    TEST_ASSERT(isSliceOK(grid));
}

void TestSlice::testSlice256(void) {
    dim3 dg=dim3(64,1,1);
    dim3 db=dim3(256,1,1);
    Grid grid(dg, db);
    TEST_ASSERT(isSliceOK(grid));
}

void TestSlice::testSlice512(void) {
    dim3 dg=dim3(64,1,1);
    dim3 db=dim3(512,1,1);
    Grid grid(dg, db);
    TEST_ASSERT(isSliceOK(grid));
}

void TestSlice::testSlice1024(void) {
    dim3 dg=dim3(64,1,1);
    dim3 db=dim3(1024,1,1);
    Grid grid(dg, db);
    TEST_ASSERT(isSliceOK(grid));
}
/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

