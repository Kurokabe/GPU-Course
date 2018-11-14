#include "Array.h"

#include <iostream>
#include <assert.h>

using std::cout;
using std::endl;

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Imported		*|
 \*-------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Constructeur		*|
 \*-------------------------------------*/

Array::Array(int n, int value) :
	n(n)
    {
    // debug pedagogique
	{
	cout << "\n[Array] : use constructeur" << endl;
	}

    this->tab = new double[n];
    init(value);
    }

/**
 * constructeur copie
 * necessaire car attribut pointeur dans  Array
 */
Array::Array(const Array& source) :
	Array(source.n)
    {
    // debug pedagogique
	{
	cout << "\n[Array] : use constructeur copie" << endl;
	}

    // copie du contenu de tab
    for (int i = 0; i < n; i++)
	{
	this->tab[i] = source.tab[i];
	}
    }

Array::Array() :
	Array(0)
    {
    // debug pedagogique
    	{
    	cout << "\n[Array] : use constructeur vide" << endl;
    	}
    }

Array::~Array()
    {
    // debug pedaggique
	{
	init(-1);
	cout << "[Array] : destructeur : " << tab << endl;
	}

    delete[] tab;
    }

/*--------------------------------------*\
 |*		Methode			*|
 \*-------------------------------------*/

void Array::init(double value)
    {
    for (int i = 0; i < n; i++)
	{
	tab[i] = value;
	}
    }

double* Array::getPtr()
    {
    return tab;
    }

int Array::size()
    {
    return n;
    }

/**
 * necessaire car attribut pointeur dans Array
 */
Array& Array::operator=(const Array& source)
    {
    // debug pedagogique
	{
	cout << "\n[Array] :  use surcharge =" << endl;
	}

    if (n != source.n)
	{
	delete[] this->tab;

	this->tab = new double[source.n];
	this->n = source.n;
	}

    //  transferer contenu tab
	{
	for (int i = 0; i < n; i++)
	    {
	    this->tab[i] = source.tab[i];
	    }
	}

    return *this;
    }

/**
 * friend
 */
ostream& operator <<(ostream& stream, const Array& array)
    {
    stream << " n = " << array.n << " : ";

    for (int i = 0; i < array.n; i++)
	{
	stream << array.tab[i] << "\t";
	}

    stream << endl;

    return stream;
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

