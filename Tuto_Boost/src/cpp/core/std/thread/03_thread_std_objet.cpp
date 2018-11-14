#include <iostream>
#include <thread>
#include <chrono>

#include "Runnable_SDT.h"


using std::cout;
using std::endl;

using std::thread;
using std::ref;

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Imported	 	*|
 \*-------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

void helloStdThread_Objet(void);

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

void helloStdThread_Objet(void)
    {
    int x = 10;
    int y = 100;
    Runnable_SDT runnable(x, y);

    cout << "\nthread : objet : start" << endl;

    // A very important consideration when using functors with boost threads is that the thread constructor takes the functor parameter by value !!
   // boost::thread threadRunnable(runnable);

    // Solution: Here runnable is passed by reference (not a copy)
   thread threadRunnable(ref(runnable)); // use foncteur runnable() of Runnable

    cout << "Waiting for thread ..." << endl;

    threadRunnable.join();
    cout << "[outside thread] : " << x << " + " << y << " = " << runnable.getResult() << endl; // give bad result if  runnable  is passed by value to  std::thread

    cout << "thread : objet : end" << endl;
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

