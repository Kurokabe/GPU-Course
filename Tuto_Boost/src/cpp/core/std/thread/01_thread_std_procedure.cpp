#include <iostream>
//#include <thread> // include with c++11 (#CXXFLAGS+= -std=c++0x)

using std::cout;
using std::endl;

#include <thread>
#include <chrono>

using std::thread;
using std::chrono::seconds;
using std::this_thread::sleep_for;
using std::this_thread::get_id;


/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Imported	 	*|
 \*-------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

void helloStdThread_Procedure(void);

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

static void runnable(void);

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

// http://www.cplusplus.com/reference/thread/thread/

void helloStdThread_Procedure(void)
    {
    cout << "\nthread : procedure : start" << endl;

   thread threadRunnable(runnable);

    cout << "Waiting for thread ..." << endl;

    threadRunnable.join();

    cout << "thread : procedure : end " << endl;
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

void runnable(void)
    {
    cout << "runnable : start" << endl;
    cout<<"Hello from thread : id  : "<<get_id() << endl;

    // Pretend to do something useful...
	{
	seconds workTime(3);
	sleep_for(workTime);
	}

    cout << "runnable: end" << endl;
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

