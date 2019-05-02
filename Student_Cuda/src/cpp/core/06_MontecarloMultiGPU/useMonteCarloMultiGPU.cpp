#include <iostream>
#include "Grid.h"
#include "Device.h"
#include "LimitsTools.h"
#include "MathTools.h"
#include "../06_MontecarloMultiGPU/host/MonteCarloMultiGPU.h"

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

bool isMonteCarloMultiGPUOK();
bool isMonteCarloMultiGPUOK(const Grid& grid);

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

/**
 * On passse la grille ? useAddVecteur pour pouvoir facilement la faire varier de l'ext?rieur pour trouver l'optimum, ou faire des tests avec des grilles diff?rentes
 * Contrainte : grid :  puissance de 2 pour etre compatible avec la version naivePlus
 */
bool isMonteCarloMultiGPUOK(const Grid& grid)
    {
    int nbFlechette = LimitsTools::MAX_INT / 10;

    float piHat=0;

    MonteCarloMultiGPU monteCarloMultiGPU(grid, nbFlechette, &piHat);
    monteCarloMultiGPU.run();

    bool isOk = MathTools::isEquals((double) piHat, PI, 1e-4);
    cout << "valeur de pi : " << piHat << " , isok? : " << isOk << endl;
    return isOk;
    }

bool isMonteCarloMultiGPUOK()
    {
    dim3 dg = dim3(64,1,1);
    dim3 db = dim3(128, 1, 1);
    Grid grid(dg, db);
    return isMonteCarloMultiGPUOK(grid);

    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

