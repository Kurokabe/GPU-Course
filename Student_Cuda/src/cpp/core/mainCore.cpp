#include <iostream>
#include <stdlib.h>


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

extern bool helloCuda(void);
extern bool isAddScalarGPU_proceduraleOk(void);
extern bool isAddScalarGPU_ObjetOk(void);
extern bool isAddVecteurOk(int n);
extern bool isSliceOK();
extern bool isReductionAddTools_I_Ok(const Grid&);

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

int mainCore();

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

int mainCore()
    {
    bool isOk = true;
    isOk &= helloCuda();
    isOk &= isAddScalarGPU_proceduraleOk();
    isOk &= isAddScalarGPU_ObjetOk();
    isOk &= isAddVecteurOk(9);
    isOk &= isSliceOK();
    dim3 dg = dim3(124, 1, 1);  		// disons, a optimiser selon le gpu, peut drastiqument ameliorer ou baisser les performances
    dim3 db = dim3(124, 1, 1);   		// disons, a optimiser selon le gpu, peut drastiqument ameliorer ou baisser les performances
    Grid grid(dg, db);
    isOk &= isReductionAddTools_I_Ok(grid);

    cout << "\nisOK = " << isOk << endl;
    cout << "\nEnd : mainCore" << endl;

    return isOk ? EXIT_SUCCESS : EXIT_FAILURE;
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

