#include "SingletonBoost.h"
#include <iostream>

using std::cout;
using std::endl;

#include <boost/thread.hpp>
#include <boost/date_time.hpp>

using boost::thread;
using boost::posix_time::seconds;
using boost::this_thread::sleep;
using boost::this_thread::get_id;
/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Imported	 	*|
 \*-------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

bool useSynchronization(void);

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

static void runnable(void);
static bool useSimple(void);

static bool useStress(void);
static bool useStress1(int n);
static bool useStress2(int n);

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

bool useSynchronization(void)
    {
    cout << endl << "[Use Boost Synchronization] : " << endl << endl;

    bool isOk = true;

    isOk &= useSimple();
    isOk &= useStress();

    return isOk;
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

bool useSimple(void)
    {
    thread threadRunnable1(runnable);
    thread threadRunnable2(runnable);

    threadRunnable1.join();
    threadRunnable2.join();

    return true;
    }

bool useStress(void)
    {
    const int N = 100;

    bool isOk = true;

    isOk &= useStress1(N);
    isOk &= useStress2(N);

    return isOk;
    }

bool useStress1(int n)
    {
    cout << endl << "[Use Boost Synchronization stress1] : n = " << n << endl << endl;

#pragma omp parallel for
    for (int i = 0; i <= n; i++)
	{
	thread threadi = thread(runnable);
	threadi.join(); // pas necessaire
	} // barriere de synchronisation explicite

    return true;
    }

bool useStress2(int n)
    {
    cout << endl << "[Use Boost Synchronization stress2] : n = " << n << endl << endl;

    thread* tabThread = new thread[n];

    // launch
	{
	for (int i = 0; i < n; i++)
	    {
	    tabThread[i] = thread(runnable);
	    }
	}

    // join
	{
	for (int i = 0; i < n; i++)
	    {
	    tabThread[i].join();
	    }
	}

    delete[] tabThread;

    return true;
    }

/*----------------*\
 |*	common   *|
 \*---------------*/

void runnable(void)
    {
    // seconds workTime(1);
    // sleep(workTime);

    cout << "[SingletonBoost] ::getInstance from thread : id  : ";

    SingletonBoost::getInstance()->print_tid();
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

