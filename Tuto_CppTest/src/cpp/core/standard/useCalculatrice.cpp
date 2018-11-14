#include <iostream>

#include "CalculatriceFloat.h"
#include "CalculatriceInt.h"

using std::cout;
using std::endl;

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

void useCalculatrice(void)
    {
    cout << "useCalculatrice" << endl;

    cout<<CalculatriceInt::fois(3, 4)<<endl;
    cout<<CalculatriceFloat::sum(3, 4)<<endl;
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

