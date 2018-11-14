#include "Banane.h"

using std::endl;
using std::cout;

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
int Banane::compteurIntance = 0;

/*--------------------------------------*\
 |*		Constructeur		*|
 \*-------------------------------------*/

/**
 * constructeur dominant
 */
Banane::Banane(int poids, int prix) :
	poids(poids), ptrPrix(NULL)
    {
    this->ptrPrix = new int;
    *ptrPrix = prix;

    Banane::compteurIntance++;
    }

/**
 * call constructeur dominant
 */
Banane::Banane() :
	Banane(-1, -1)
    {
    // rien de plus
    }

/**
 * constructeur copie
 * necessaire car attribut pointeur
 */
Banane::Banane(const Banane& source) :
	Banane(source.poids, *source.ptrPrix)
    {
    // rien de plus
    }

/**
 * destructeur
 */
Banane::~Banane()
    {
    // debug pedagogique
	{
	*ptrPrix = -1;
	cout << "[Banane] : destruction : " << ptrPrix << endl;
	}

    delete ptrPrix;
    }

/*--------------------------------------*\
 |*		Methode			*|
 \*-------------------------------------*/

void Banane::setPrix(int prix)
    {
    *(this->ptrPrix) = prix;
    }

int Banane::getPrix()
    {
    return *(this->ptrPrix);
    }

/**
 * static
 */
int Banane::getCompteurIntance()
    {
    return Banane::compteurIntance;
    }
/**
 * static
 */
void Banane::resetCompteurInstance()
    {
    Banane::compteurIntance = 0;
    }

/**
 * necessaire car attribut pointeur
 */
Banane& Banane::operator=(const Banane& source)
    {
    this->poids = source.poids;
    *(this->ptrPrix) = *(source.ptrPrix); // copie du contenu du pointeur, par defaut copie de l'adresse uniquement et menerait a un copie superficielle

    return *this; // pas oublier!
    }

/**
 * friend, surcharge <<
 */
ostream& operator <<(ostream& stream, const Banane& banane)
    {
    stream << "[Banane : poids = " << banane.poids << " , prix = " << *banane.ptrPrix << " ]" << endl;

    return stream;
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

