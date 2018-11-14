#include <iostream>
#include <thread>
#include <chrono>
#include "Runnable_SDT.h"


using std::cout;
using std::endl;

using std::thread;

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Imported	 	*|
 \*-------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

void helloStdThread_Methode(void);

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

void helloStdThread_Methode(void)
    {
    int x = 10;
    int y = 100;
    Runnable_SDT runnable(x, y);

    cout << "\nthread : methode : start" << endl;

    // arg1 : adresse de la methode run de la classe Runnable
    // arg2 : adresse de l'objet sur lequel aller chercher la metode run
   thread threadRunnable(&Runnable_SDT::run, &runnable);

    cout << "Waiting for thread ..." << endl;

    threadRunnable.join();
    cout << "thread : methode : end" << endl;

    cout << "[outside thread] : " << x << " + " << y << " = " << runnable.getResult() << endl; // give bad result cause runnable instance is passed by value to  std::thread
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

