#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <assert.h>

using std::cout;
using std::endl;

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Imported	 	*|
 \*-------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

void usePassage(void);

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

static void use1(void);

/*------------------*\
 |*  valeur/copy     *|
 \*------------------*/

static int add1(int x, int y);
static int add2(int* ptrx, int* ptry);

/*------------------*\
 |*  reference      *|
 \*------------------*/

static int add3(int& x, int& y);
static int add4(const int& x, const int& y);
static int add5(int*& ptrx, int*& ptry);
static int add6(const int*& ptrx, const int*& ptry);

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

void usePassage(void)
    {
    cout << "\nadd : usePassage" << endl;

    use1();
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/**
 * Passage
 */
void use1(void)
    {
    int x = 1;
    int y = 10;

    // valeur/copy
	{
	cout << add1(x, y) << endl;
	cout << add2(&x, &y) << endl;
	}

    // refernece
	{
	cout << add3(x, y) << endl;
	cout << add4(x, y) << endl;

	// reference pointeur
	    {
	    int* ptrx = &x;
	    int* ptry = &y;

	    cout << add5(ptrx, ptry) << endl;
	    }

	// reference pointeur cosntant
	    {
	    const int* ptrx = &x;
	    const int* ptry = &y;

	    cout << add6(ptrx, ptry) << endl;
	    }
	}
    }

/*------------------*\
 |*  valeur/copy     *|
 \*------------------*/

int add1(int x, int y)
    {
    return x + y;
    }

/**
 * passage pointeur par valeur!
 * une copie de l'adresse est passée
 */
int add2(int* ptrx, int* ptry)
    {
    return *ptrx + *ptry;
    }

/*------------------*\
 |*  reference      *|
 \*------------------*/

int add3(int& x, int& y)
    {
    return x + y;
    }

int add4(const int& x, const int& y)
    {
    return x + y;
    }

/**
 * passage du pointeur par reference
 */
int add5(int*& ptrx, int*& ptry)
    {
    return *ptrx + *ptry;
    }

/**
 * passage du pointeur par reference cosntante
 */
int add6(const int*& ptrx, const int*& ptry)
    {
    return *ptrx + *ptry;
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

