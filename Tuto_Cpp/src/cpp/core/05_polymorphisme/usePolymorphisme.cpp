#include <stdlib.h>
#include <iostream>

#include "Dessin.h"
#include "Carrer.h"
#include "Cercle.h"
#include "Rectangle.h"

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

void usePolymorphisme(void);

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

static void use1(void);

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

void usePolymorphisme(void)
    {
    cout << "\nPolymorphisme : useForme" << endl;

    use1();
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

void use1(void)
    {
    // scoop
	{
	Rectangle rectangle("myRectangle", 3, 6);
	Carrer carrer("myCarrer", 2);
	Cercle cercle("myCercle", 10);

	Dessin dessin("myDessin");
	dessin.add(&rectangle);
	dessin.add(&carrer);
	dessin.add(&cercle);

	cout << "aire(Dessin)      = " << dessin.aire() << endl;
	cout << "perimetre(Dessin) = " << dessin.perimetre() << endl;
	cout << "size(Dessin)      = " << dessin.size();
	} // rectangle, carrer, cercle et dessin detruit

    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

