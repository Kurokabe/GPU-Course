#pragma once

#include <iostream>
#include <vector>

using std::string;
using std::ostream;
using std::vector;

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

class ListInt
    {

	/*--------------------------------------*\
	|*		Constructeur		*|
	 \*-------------------------------------*/

    public:

	ListInt();

	virtual ~ListInt();

	/*--------------------------------------*\
	|*		Methode			*|
	 \*-------------------------------------*/

    public:

	void add(int x);

	int pop();

	int size();

	/**
	 * surcharge []
	 */
	int operator[](int i);

	/**
	 * surcharge <<
	 */
	friend ostream& operator <<(ostream& stream, const ListInt& listInt);

	/*--------------------------------------*\
	|*		Attribut		*|
	 \*-------------------------------------*/

    private:

	// Tools
	vector<int> list; // list est deja instancier ici avec cette syntaxe! A a; // instancie a avec constructeur vide de A

    };

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
