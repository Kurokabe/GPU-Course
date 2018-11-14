#include <iostream>
#include <thread>
#include <chrono>


using std::cout;
using std::endl;

using std::thread;
using std::chrono::milliseconds;
using std::this_thread::sleep_for;

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Imported	 	*|
 \*-------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

void helloStdThread_ProcedureArgs(void);

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

static void runnable(float x);

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

void helloStdThread_ProcedureArgs(void)
    {
    cout << "\nthread : procedure args : start" << endl;

    float x = 3.14;
   thread threadRunnable(runnable, x); // x sera passer � runnable

    cout << "Waiting for thread ..." << endl;

    threadRunnable.join();

    cout << "thread : procedure args : end" << endl;
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

void runnable(float x)
    {
    cout << "runnable : start" << endl;
    cout << "x = " << x << endl;

    // Pretend to do something useful...
	{
	sleep_for(milliseconds(2000));
	}

    cout << "runnable: end" << endl;
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

