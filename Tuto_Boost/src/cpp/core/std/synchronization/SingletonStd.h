#pragma once

#include <mutex>

using std::mutex;

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class SingletonStd
    {
    private:

	SingletonStd();

    public:

	static SingletonStd* getInstance();

	void print_tid();

    private:

	static int compteur;

	static mutex mutexInstance;

	static SingletonStd* instance;

    };

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
