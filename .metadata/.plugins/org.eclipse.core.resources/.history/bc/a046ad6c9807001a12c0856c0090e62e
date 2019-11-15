
#include <iostream>
#include "Grid.h"
#include "Device.h"
#include "LimitsTools.h"
#include "MathTools.h"

#include "host/Histogramme.h"
#include "host/DataCreator.h"

using std::cout;
using std::endl;

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

__host__ bool isHistogrammeOKSum();
__host__ bool isHistogrammeOKValues();
__host__ bool isHistogrammeOKSum(const Grid& grid);
__host__ bool isHistogrammeOKValues(const Grid& grid);


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
bool isHistogrammeOKSum(const Grid& grid)
    {

    int dataMax=255 ;
    DataCreator dataCreator(dataMax) ;
    int* tabData = dataCreator.getTabData();
    int n = dataCreator.getLength();

    int tabFrequence[dataMax + 1];

    Histogramme histogramme(grid, n, tabData, tabFrequence, dataMax);
    histogramme.run();

    int sumHisto = 0;
    for (int i = 0; i < dataMax; i++)
	{
	sumHisto += tabFrequence[i];
	}
    int sumCalculated = ((dataMax + 1) * dataMax) / 2;
    cout << "Sum histogramme : " << sumHisto << endl;
    cout << "Sum calculated : " << sumCalculated << endl;

    return sumHisto == sumCalculated;
    }

bool isHistogrammeOKValues(const Grid& grid)
    {

    int dataMax=255 ;
    DataCreator dataCreator(dataMax) ;
    int* tabData = dataCreator.getTabData();
    int n = dataCreator.getLength();

    int tabFrequence[dataMax + 1];

    Histogramme histogramme(grid, n, tabData, tabFrequence, dataMax);
    histogramme.run();

    bool isOK = true;
    for (int i = 0; i < dataMax; i++)
	{
	isOK &= (tabFrequence[i] == i + 1);
	}
    cout << endl;

    return isOK;
    }

bool isHistogrammeOKSum()
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
	    isOk &= isHistogrammeOKSum(grid);
	    }
	}
    return isOk;
    }

bool isHistogrammeOKValues()
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
	    isOk &= isHistogrammeOKValues(grid);
	    }
	}
    return isOk;
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
