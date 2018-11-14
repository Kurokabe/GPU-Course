#pragma once

#include <iostream>
#include <assert.h>

using std::cout;
using std::endl;

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/**
 * for number (type simple) or class with operator + override
 */
template<class T>
class Interval
    {

	/*--------------------------------------*\
	|*		Constructeur		*|
	 \*-------------------------------------*/

    public:

	/**
	 * a<=b
	 */
	Interval(T a, T b) :
		a(a), b(b)
	    {
	    assert(a <= b);
	    }

	virtual ~Interval()
	    {
	    // rien car pas de de new dans constructeur
	    }

	/*--------------------------------------*\
	|*		Methode			*|
	 \*-------------------------------------*/

    public:

	/**
	 * sur place
	 */
	void translate(T translation)
	    {
	    a += translation;
	    b += translation;
	    }

	void print()
	    {
	    cout << "[" << a << "," << b << "]" << endl;
	    }

	/**
	 * marcherait aussi pour methode static
	 */
	static T max(T u, T v)
	    {
	    return u >= v ? u : v;
	    }

	/*--------------------------------------*\
	|*		Attribut		*|
	 \*-------------------------------------*/

    private:

	// Inputs
	T a;
	T b;

    };

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
