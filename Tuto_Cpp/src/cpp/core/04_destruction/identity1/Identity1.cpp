#include "Identity1.h"

#include <iostream>

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

Identity1::Identity1(int n) :
	n(n)
    {
    this->ptrTab = new double[n * n];

    fill();
    }

Identity1::~Identity1()
    {
    // debug pedagogique
	{
	init(-1);

	cout << "\n[Identity1] : destucteur" << endl;
	}

    delete[] ptrTab; // celui qui emploie new, doit employer delete! (dans meme scoop ou dans meme classe)
    }

/*--------------------------------------*\
 |*		public			*|
 \*-------------------------------------*/

double* Identity1::get()
    {
    return ptrTab;
    }

int Identity1::getN()
    {
    return n;
    }

void Identity1::print()
    {
    for (int s = 1; s <= n * n; s++)
	{
	cout << ptrTab[s - 1] << "\t";

	if (s % n == 0)
	    {
	    cout << endl;
	    }
	}

    cout << endl;
    }

/**
 * static
 */
void Identity1::print(double* ptrTab, int n)
    {
    for (int s = 1; s <= n * n; s++)
	{
	cout << *ptrTab << "\t";

	if (s % n == 0)
	    {
	    cout << endl;
	    }

	ptrTab++; // ptrTab passer par valeur, donc par copy à print, on modifie pas l'originale, mais la copie!
	}

    cout << endl;
    }

/*--------------------------------------*\
 |*		private			*|
 \*-------------------------------------*/

void Identity1::fill()
    {
    init(0);

    const int JUMP = n + 1;
    for (int s = 0; s < n * n; s += JUMP)
	{
	ptrTab[s] = 1;
	}
    }

void Identity1::init(double value)
    {
    for (int s = 0; s < n * n; s++)
	{
	ptrTab[s] = value;
	}
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

