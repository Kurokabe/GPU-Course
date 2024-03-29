#include <stdlib.h>
#include <iostream>
#include <string>

#include "cppTest+.h"
#include "Device.h"
#include "StringTools.h"
#include "cudaTools.h"

#include "TestHello.h"
#include "TestVector.h"
#include "TestScalar.h"
#include "TestSlice.h"
#include "TestSliceSM.h"
#include "TestMonteCarlo.h"
#include "TestReduction.h"
#include "TestMonteCarloLong.h"
#include "TestMonteCarloMultiGPU.h"
#include "TestHistogramme.h"

using std::string;
using std::cout;
using std::endl;

using Test::Suite;

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Imported	 	*|
 \*-------------------------------------*/

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

static bool testALL();

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

int mainTest();

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

int mainTest()
    {
    bool isOk = testALL();

    cout << "\nisOK = " << isOk << endl;

    return isOk ? EXIT_SUCCESS : EXIT_FAILURE;
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

bool testALL()
    {
    Suite testSuite;

//    testSuite.add(std::unique_ptr < Suite > (new TestHello()));
//    testSuite.add(std::unique_ptr < Suite > (new TestScalar()));
//    testSuite.add(std::unique_ptr < Suite > (new TestVector()));
//    testSuite.add(std::unique_ptr < Suite > (new TestSlice()));
//    testSuite.add(std::unique_ptr < Suite > (new TestSliceSM()));
//    testSuite.add(std::unique_ptr < Suite > (new TestReduction()));
//    testSuite.add(std::unique_ptr < Suite > (new TestMonteCarlo()));
//    testSuite.add(std::unique_ptr < Suite > (new TestMonteCarloLong()));
//    testSuite.add(std::unique_ptr < Suite > (new TestMonteCarloMultiGPU()));
    testSuite.add(std::unique_ptr < Suite > (new TestHistogramme()));

    string output = "out/test";
    return runTestHtml(output, testSuite); // Attention: html create in ./workingDirectory/out
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

