#include <iostream>
#include "Grid.h"
#include "Device.h"
#include "MonteCarlo.h"
#include "LimitsTools.h"
#include "MathTools.h"

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

bool isMonteCarloOK();
bool isMonteCarloOK(const Grid& grid);

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
bool isMonteCarloOK(const Grid& grid)
    {
    int nbFlechette = LimitsTools::MAX_INT / 10;

    float piHat;

    MonteCarlo monteCarlo(grid, nbFlechette, &piHat);
    monteCarlo.run();

    bool isOk = MathTools::isEquals((double) piHat, PI, 1e-4);
    cout << "valeur de pi : " << piHat << " , isok? : " << isOk << endl;
    return isOk;
    }

bool isMonteCarloOK()
    {
    bool isOk = true;
    dim3 dg = dim3(1,1,1);
    dim3 db = dim3(2, 1, 1);
    Grid grid(dg, db);
    for(int i = 16; i<=64; ++i) //Démarrage à 16 afin d'avoir des tests assez rapides
	{
	dg.x = i;
	grid.dg = dg;
	for(int j = 2; j<=1024; j*=2)
	    {
	    db.x = j;
	    grid.db = db;
	    cout << grid << endl;
	    isOk &= isMonteCarloOK(grid);
	    }
	}
    return isOk;

    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
