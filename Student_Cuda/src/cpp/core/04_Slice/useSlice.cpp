#include <iostream>
#include "Grid.h"
#include "Device.h"
#include "LimitsTools.h"
#include "MathTools.h"
#include "../04_Slice/host/Slice.h"

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

bool isSliceOK();
bool isSliceOK(const Grid& grid);

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
 * On passse la grille à useAddVecteur pour pouvoir facilement la faire varier de l'extérieur pour trouver l'optimum, ou faire des tests avec des grilles différentes
 * Contrainte : grid :  puissance de 2 pour etre compatible avec la version naivePlus
 */
bool isSliceOK(const Grid& grid)
    {
    int nbSlice = LimitsTools::MAX_INT / 100;
    // pas trop de slice sinon on atteind les limtes du type float (les bases des rectangles et les aires deviennent trop petite!

    float piHat;

    Slice slice(grid, nbSlice, &piHat);
    slice.run();
    piHat/=nbSlice;

    bool isOk = MathTools::isEquals((double) piHat, PI, 1e-4);
    cout << "valeur de pi : " << piHat << " , isok? : " << isOk << endl;
    return isOk;
    }

bool isSliceOK()
    {
    //int mp = Device::getMPCount();
    int coreMP = Device::getCoreCountMP();

    dim3 dg = dim3(64, 1, 1);
    dim3 db = dim3(coreMP * 4, 1, 1);
    Grid grid(dg, db);

    return isSliceOK(grid);
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

