#pragma once

#include <iostream>

using std::string;

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

class  Forme_A
    {

	/*--------------------------------------*\
	|*		Constructeur		*|
	 \*-------------------------------------*/

    public:

	Forme_A(string name);

	virtual ~Forme_A();

	/*--------------------------------------*\
	|*		virtuelle pure		*|
	 \*-------------------------------------*/

    public:

	virtual double aire(void)=0;// = 0 : virtuel pure, override obligatoire, idem abstract java

	virtual double perimetre()=0;// = 0:  virtuel pure, override obligatoire, idem abstract java

	/*--------------------------------------*\
	|*		Methode			*|
	 \*-------------------------------------*/

    public:

	string getName();

	/*--------------------------------------*\
	|*		Attribut		*|
	 \*-------------------------------------*/

    private:

	// Inputs
	string name;

    };

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
