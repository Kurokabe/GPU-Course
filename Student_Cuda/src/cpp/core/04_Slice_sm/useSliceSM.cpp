
#include <iostream>
#include "Grid.h"
#include "Device.h"
#include "LimitsTools.h"
#include "MathTools.h"

#include "SliceSM.h"

using std::cout;
using std::endl;

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

__host__ bool isSliceNewOK();
__host__ bool isSliceNewOK(const Grid& grid);


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
bool isSliceSMOK(const Grid& grid)
    {
    int nbSlice = LimitsTools::MAX_INT / 100;

    float piHat=12;

    SliceSM sliceSM(grid,nbSlice,&piHat);
    sliceSM.run();
    piHat = piHat/nbSlice;
    bool isOk = MathTools::isEquals((double) piHat, PI, 1e-4);
    cout << "Valeur de PI: " << piHat << " , isok?: " << isOk << endl;
    return isOk;
    }

bool isSliceSMOK()
    {
    bool isOk = true;
    dim3 dg = dim3(1,1,1);
    dim3 db = dim3(2, 1, 1);
    Grid grid(dg, db);
    for(int i = 16; i<=64; ++i) //Démarrage à 16 afin d'avoir des tests assez rapides
	{
	dg.x = i;
	grid.dg = dg;
	for(int j = 4; j<=1024; j*=2)
	    {
	    db.x = j;
	    grid.db = db;
	    cout << grid << endl;
	    isOk &= isSliceSMOK(grid);
	    }
	}
    return isOk;
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/