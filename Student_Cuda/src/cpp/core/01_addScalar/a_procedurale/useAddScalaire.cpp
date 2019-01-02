#include <iostream>
#include <assert.h>

#include "Grid.h"
#include "Device.h"

using std::cout;
using std::endl;

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Imported	 	*|
 \*-------------------------------------*/

extern int addScalarGPU(int a, int b);

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

bool isAddScalarGPU_proceduraleOk(void);

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

bool isAddScalarGPU_proceduraleOk(void)
    {
    int a = 2;
    int b = 7;

    int sumGPU = addScalarGPU(a, b);
    int sumTheorique = a + b;

    cout << "\n[addScalarGPU procedurale] " << a << " + " << b << " = " << sumGPU << endl;

    return sumGPU == sumTheorique;
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
