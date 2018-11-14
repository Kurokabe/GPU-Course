#include "SingletonStd.h"

#include <iostream>
#include <assert.h>
#include <thread>

using std::mutex;
using std::cout;
using std::endl;

using std::this_thread::get_id;

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		constructeur		*|
 \*-------------------------------------*/

SingletonStd::SingletonStd()
    {
    cout << "[SingletonStd] :: create" << endl;

    SingletonStd::compteur++;
    assert(SingletonStd::compteur == 1);
    }

/*--------------------------------------*\
|*		methode			*|
 \*-------------------------------------*/

/**
 * static
 */
SingletonStd* SingletonStd::getInstance()
    {
    mutexInstance.lock();
    if (instance == NULL)
	{
	instance = new SingletonStd();
	}
    mutexInstance.unlock();

    return instance;
    }

void SingletonStd::print_tid()
    {
    cout << get_id() << endl;
    }

/*--------------------------------------*\
|*		attribut		*|
 \*-------------------------------------*/

/**
 * static
 */
mutex SingletonStd::mutexInstance;

/**
 * static
 */
SingletonStd* SingletonStd::instance = NULL;

/**
 * static
 */
int SingletonStd::compteur = 0;

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
