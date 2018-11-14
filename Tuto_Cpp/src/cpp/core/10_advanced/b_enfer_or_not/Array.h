#pragma once

#include <iostream>

using std::string;
using std::ostream;

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/**
 * wrapper de tab 1d, avec en plus la size
 */
class Array
    {

	/*--------------------------------------*\
	|*		Constructeur		*|
	 \*-------------------------------------*/

    public:

	Array(int n, int value=0);

	/**
	 * constructeur copy
	 * necessaire car attribut pointeur
	 */
	Array(const Array& source);

	/**
	 * required for
	 * 	Arrays* ptr=new Array[n];
	 * but not for
	 * 	Arrays** ptr=new Array*[n];
	 */
	Array();

	virtual ~Array();

	/*--------------------------------------*\
	|*		Methode			*|
	 \*-------------------------------------*/

    public:

	void init(double value);

	double* getPtr();

	int size();

	/**
	 * necessaire car attribut pointeur
	 *
	 * surcharge =
	 */
	Array& operator=(const Array& source);

    private:



	/*--------------------------------------*\
	|*		surcharge 		*|
	 \*-------------------------------------*/

	/**
	 * surcharge <<
	 */
	friend ostream& operator <<(ostream& stream, const Array& array);

	/*--------------------------------------*\
	|*		Attribut		*|
	 \*-------------------------------------*/

    private:

	// Inputs
	int n;

	// Tools
	double* tab;

    };

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
