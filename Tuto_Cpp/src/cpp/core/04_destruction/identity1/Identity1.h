#pragma once

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/**
 * matrice carrer nxn avec des 1 sur la diagonale
 */
class Identity1
    {

	/*--------------------------------------*\
	|*		Constructeur		*|
	 \*-------------------------------------*/

    public:

	Identity1(int n);

	virtual ~Identity1();

	/*--------------------------------------*\
	|*		Methode			*|
	 \*-------------------------------------*/

    public:

	/**
	 * matrice utilisable tant que Identity pas detruit.
	 * destruction de Identity entraine destruction de la matrice
	 *
	 * row major
	 */
	double* get();

	int getN();

	void print();

	/*-----------------*\
	|*	static	   *|
	 \*----------------*/

	/**
	 * matrice carrer row major
	 */
	static void print(double* ptrTab, int n);

    private:

	void init(double value);

	void fill();

	/*--------------------------------------*\
	|*		Attribut		*|
	 \*-------------------------------------*/

    private:

	// Inputs
	int n;

	// Outputs
	double* ptrTab;

    };

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
