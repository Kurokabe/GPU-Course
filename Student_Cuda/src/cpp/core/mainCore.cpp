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
extern bool isSliceSMOK(const Grid& grid);
extern bool isReductionAddTools_I_Ok(const Grid& grid);
extern bool isReductionAddTools_II_Ok(const Grid& grid);
extern bool isReductionAddToolsLock_I_Ok(const Grid& grid);
extern bool isReductionAddToolsLock_II_Ok(const Grid& grid);
extern bool isMonteCarloOK(const Grid& grid);
extern bool isMonteCarloLongOK(const Grid& grid);
extern bool isMonteCarloMultiGPUOK(const Grid& grid);
extern bool isHistogrammeOKSum();
extern bool isHistogrammeOKValues();
extern bool isBandwidthOK();

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
    dim3 dg = dim3(64, 1, 1);  		// disons, a optimiser selon le gpu, peut drastiqument ameliorer ou baisser les performances
    dim3 db = dim3(1024, 1, 1);   		// disons, a optimiser selon le gpu, peut drastiqument ameliorer ou baisser les performances
    Grid grid(dg, db);

    bool isOk = true;
//    isOk &= helloCuda();
//    isOk &= isAddScalarGPU_proceduraleOk();
//    isOk &= isAddScalarGPU_ObjetOk();
//    isOk &= isAddVecteurOk(9);
//    isOk &= isSliceOK();
//    isOk &= isSliceSMOK(grid);
//    isOk &= isReductionAddTools_I_Ok(grid);
//    isOk &= isReductionAddTools_II_Ok(grid);
//    isOk &= isReductionAddToolsLock_I_Ok(grid);
//    isOk &= isReductionAddToolsLock_II_Ok(grid);
//    isOk &= isMonteCarloOK(grid);
//    isOk &= isMonteCarloLongOK(grid);
//    isOk &= isMonteCarloMultiGPUOK(grid);
//    isOk &= isHistogrammeOKSum();
//    isOk &= isHistogrammeOKValues();
    isOk &= isBandwidthOK();


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

