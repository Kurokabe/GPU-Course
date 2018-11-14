#pragma once

#include <boost/thread.hpp>

using boost::mutex;

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class SingletonBoost
    {
    private:

	SingletonBoost();

    public:

	static SingletonBoost* getInstance();

	void print_tid();

    private:

	static int compteur;

	static mutex mutexInstance;

	static SingletonBoost* instance;

    };

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
