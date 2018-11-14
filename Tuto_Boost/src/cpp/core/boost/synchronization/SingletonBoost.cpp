#include "SingletonBoost.h"

#include <iostream>
#include <assert.h>

using boost::mutex;
using std::cout;
using std::endl;

using boost::this_thread::get_id;

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		constructeur		*|
 \*-------------------------------------*/

SingletonBoost::SingletonBoost()
    {
    cout << "[SingletonBoost] :: create" << endl;

    SingletonBoost::compteur++;
    assert(SingletonBoost::compteur == 1);
    }

/*--------------------------------------*\
|*		methode			*|
 \*-------------------------------------*/

/**
 * static
 */
SingletonBoost* SingletonBoost::getInstance()
    {
    mutexInstance.lock();
    if (instance == NULL)
	{
	instance = new SingletonBoost();
	}
    mutexInstance.unlock();

    return instance;
    }

void SingletonBoost::print_tid()
    {
    cout << get_id() << endl;
    }

/*--------------------------------------*\
|*		attribut		*|
 \*-------------------------------------*/

/**
 * static
 */
mutex SingletonBoost::mutexInstance;

/**
 * static
 */
SingletonBoost* SingletonBoost::instance = NULL;

/**
 * static
 */
int SingletonBoost::compteur = 0;

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
