#pragma once

#include <iostream>
#include <chrono>
#include <thread>

using std::cout;
using std::endl;

using std::chrono::seconds;
using std::this_thread::sleep_for;

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class Runnable_SDT
    {
    public:

	Runnable_SDT(int a, int b)
	    {
	    // inputs
	    this->a = a;
	    this->b = b;

	    // ouputs
	    this->result = -1;
	    }

	virtual ~Runnable_SDT(void)
	    {
	    // rien
	    }

	/**
	 * Foncteur
	 */
	void operator()()
	    {
	    cout << "runnable : foncteur : start" << endl;
	    work();
	    cout << "runnable : foncteur : end" << endl;
	    }

	void run(void)
	    {
	    cout << "runnable : methode : start" << endl;
	    work();
	    cout << "runnable : methode : end" << endl;
	    }

	int getResult(void)
	    {
	    return this->result;
	    }

    private:

	/**
	 * common to work and operator()
	 */
	void work(void)
	    {

	    this->result = a + b;
	    cout << "[inside thread] : " << a << " + " << b << " = " << result << endl;
	    // Pretend to do something useful...
		{
		seconds workTime(3);
		sleep_for(workTime);
		}
	    }

    private:

	int a;
	int b;
	int result;
    };



/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
