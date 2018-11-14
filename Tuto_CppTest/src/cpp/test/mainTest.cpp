#include <stdlib.h>
#include <fstream>
#include <string>

#include "cppTest+.h"

#include "TestCalculatriceFloat.h"
#include "TestCalculatriceInt.h"

using std::cout;
using std::endl;
using std::string;
using std::ofstream;
using std::auto_ptr;

using Test::Suite;

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Imported	 	*|
 \*-------------------------------------*/

// Already in cppTest+.h
//extern bool runTestConsole(string titre, Test::Suite& test);
//extern bool runTestHtml(string titre, Test::Suite& test);

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

static bool testInteger_console(void);
static bool testALL_console(void);
static bool testALL_html(void);

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

int mainTest(void)
    {
    cout<<"mainTest"<<endl;
    bool isOk = true;

    isOk &= testInteger_console();

    isOk &= testALL_console();
    isOk &= testALL_html();

    cout << "\nisOK = " << isOk << endl;

    return isOk ? EXIT_SUCCESS : EXIT_FAILURE;
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

bool testInteger_console(void)
    {
    TestCalculatriceInt testCaluclatriceInt;
    //return runTestHtml("TestCalculatriceInt", testCaluclatriceInt);
    return runTestConsole("TestCalculatriceInt", testCaluclatriceInt);
    }

bool testALL_console()
    {
    Suite testSuite;

    testSuite.add(auto_ptr < Suite > (new TestCalculatriceFloat()));
    testSuite.add(auto_ptr < Suite > (new TestCalculatriceInt()));

    //return runTestHtml("TestALL_HTML", testSuite);
    return runTestConsole("TestALL_Console", testSuite);
    }

bool testALL_html()
    {
    Suite testSuite;

    testSuite.add(auto_ptr < Suite > (new TestCalculatriceFloat()));
    testSuite.add(auto_ptr < Suite > (new TestCalculatriceInt()));

    return runTestHtml("out/TestALL_HTML", testSuite);
    //return runTestConsole("TestALL_Console", testSuite);
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

