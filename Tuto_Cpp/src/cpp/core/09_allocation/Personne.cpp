#include "Personne.h"

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

/**
 * static
 */
int Personne::compteurIntance = 0;

/*--------------------------------------*\
 |*		Constructeur		*|
 \*-------------------------------------*/

/**
 * constructeur dominant
 */
Personne::Personne(string name, int taille) :
	name(name), taille(taille)
    {
    Personne::compteurIntance++;
    }

/**
 * call constructeur dominant
 *
 * constructeur vide
 * usefull for Personne tab=new Personne[n];
 */
Personne::Personne():Personne("no_name",-1)
    {
    // rien
    }

Personne::~Personne()
    {
    // rien
    }

/*--------------------------------------*\
 |*		Methode			*|
 \*-------------------------------------*/

/**
 * friend, surcharge <<
 */
ostream& operator <<(ostream& stream, const Personne& personne)
    {
    stream << "[Personne : name = " << personne.name << " , taille = " << personne.taille << " ]" << endl;

    return stream;
    }

/**
 * static
 */
int Personne::getCompteurIntance()
    {
    return Personne::compteurIntance;
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

