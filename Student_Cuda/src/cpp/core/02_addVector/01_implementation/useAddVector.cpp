#include <iostream>
#include "Grid.h"
#include "Device.h"
#include "VectorTools.h"
#include "AddVector.h"

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

bool isAddVecteurOk(int n);
bool isAddVecteurOk(const Grid& grid, int n);

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
 */
bool isAddVecteurOk(const Grid& grid, int n)
    {
    float* ptrV1 = VectorTools::createV1(n);
    float* ptrV2 = VectorTools::createV2(n);
    float* ptrW = new float[n];

    // Partie interessante GPGPU
	{
	AddVector addVector(grid, ptrV1, ptrV2, ptrW, n);
	addVector.run();

	}

    // check
	{
	VectorTools::print(ptrV1, n);
	VectorTools::print(ptrV2, n);
	cout << "--------------------------------------------------------------------" << endl;
	VectorTools::print(ptrW, n);
	}

    bool isOk = VectorTools::isAddVector_Ok(ptrV1, ptrV2, ptrW, n);

    delete[] ptrV1;
    delete[] ptrV2;
    delete[] ptrW;

    return isOk;
    }

/**
 * n utile only pour le pattern 1 <--> 1
 */
bool isAddVecteurOk(int n)
    {
    // Essayser pluisieurs combinaisons pour le pattern d'entrelacement, notamment:
    //		(V1) 	1 seul thread
    //		(V2)	Beuacoup, beaucoup plus de thread que n

    // exemnple ( a optimiser dans le futur)
    dim3 dg = dim3(24, 2, 1); // contrainte : max(dg.x*dg.y*dg.z)<=1024
    dim3 db = dim3(96, 2, 1);
    Grid grid(dg, db);

    return isAddVecteurOk(grid,n);
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

