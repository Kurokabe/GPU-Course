#include "ListInt.h"

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

ListInt::ListInt()
//:ListInt(vector<int>()) // pas necessaire (see comment in .h)

    {
    // rien de plus
    }

ListInt::~ListInt()
    {
    // rien, car pas de new dans constructeur
    }

/*--------------------------------------*\
 |*		Methode			*|
 \*-------------------------------------*/

void ListInt::add(int x)
    {
    list.push_back(x);
    }

int ListInt::pop()
    {
    int last = list.back();
    list.pop_back();

    return last;
    }

int ListInt::size()
    {
    return this->list.size();
    }

int ListInt::operator[](int i)
    {
    return this->list[i];
    }

/**
 * friend
 */
ostream& operator <<(ostream& stream, const ListInt& listInt)
    {
    for (int element : listInt.list)
	{
	stream << element << "\t";
	}

    return stream;
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

