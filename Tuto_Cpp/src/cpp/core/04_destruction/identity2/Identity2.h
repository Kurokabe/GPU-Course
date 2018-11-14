#pragma once

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/**
 * matrice carrer nxn avec des 1 sur la diagonale
 */
class Identity2
    {

	/*--------------------------------------*\
	|*		Constructeur		*|
	 \*-------------------------------------*/

    public:

	/**
	 * matrice nxn, row major
	 */
	Identity2(int n, double* ptrTab);

	virtual ~Identity2();

	/*--------------------------------------*\
	|*		Methode			*|
	 \*-------------------------------------*/

    public:

	/**
	 * row major, same ptr que dans constructeur
	 */
	double* get();

	int getN();

	void print();

    private:

	void init(double value);

	void fill();

	/*--------------------------------------*\
	|*		Attribut		*|
	 \*-------------------------------------*/

    private:

	// Inputs
	int n;
	double* ptrTab;

    };

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
