#include "Dessin.h"

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

Dessin::Dessin(string name) :
	name(name)//,listForme(vector<Forme_A*>()) // pas necessaire (see comment in .h)

    {
    // rien de plus
    }

Dessin::~Dessin()
    {
    // rien, car aucun new dans constructeur

    // debug pedagogique
	{
	cout << "\n[Dessin] : destructeur : " << name<<endl;;
	}
    }

/*--------------------------------------*\
 |*		Methode			*|
 \*-------------------------------------*/

void Dessin::add(Forme_A* ptrForme)
    {
    listForme.push_back(ptrForme);
    }

/**
 * polymorphisme en passant par les pointeurs
 */
double Dessin::aire(void)
    {
    double aire = 0;

    for (Forme_A* ptrForme : listForme) // foreach comme en java
	{
	aire += ptrForme->aire();
	}

    return aire;
    }

/**
 * polymorphisme en passant par les pointeurs
 */
double Dessin::perimetre()
    {
    double perimetre = 0;

    for (Forme_A* ptrForme : listForme)  // foreach comme en java
	{
	perimetre += ptrForme->perimetre();
	}

    return perimetre;
    }

string Dessin::getName()
    {
    return name;
    }

int Dessin::size()
    {
    return listForme.size();
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

