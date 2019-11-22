#include <iostream>
#include "Grid.h"
#include "Device.h"
#include "LimitsTools.h"
#include "MathTools.h"
#include <algorithm>
#include <vector>

#include "host/Bandwidth.h"

using std::cout;
using std::qsort;
using std::endl;

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

__host__ bool isBandwidthOK();
__host__ bool isBandwidthOK(const Grid &grid);
__host__ void printResults(std::vector<double> times, int n,float GO);

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

bool isBandwidthOK(const Grid &grid)
    {
    //Device::p2pEnableALL();
    int nbrIter = 5;

    int nbrIntFor1MB = 1000000 / sizeof(int);
    int nbrIntFor1GB = nbrIntFor1MB * 1000;
    for (int n = nbrIntFor1GB * 5; n <= nbrIntFor1GB*8; n += nbrIntFor1MB * 250)
	{
	std::vector<double> times;
	for (int i = 0; i < nbrIter; i++)
	    {

	    int *tabData = (int*) malloc(sizeof(int) * n);

	    Bandwidth bandwidth(grid, tabData, n, TransferType::DeviceToDeviceEntrelacement);
	    times.push_back(bandwidth.getElapsedTime());
	    free(tabData);
	    }

	printResults(times, nbrIter, n*sizeof(int)/(float)1000000000);
	}
    //bandwidth.run();

    return true;
    }


void printResults(std::vector<double> times, int n, float GO)
    {
    double sum = 0;
    for (std::vector<double>::iterator it = times.begin(); it != times.end(); ++it)
	{
	sum += *it;
	}
    std::sort(times.begin(), times.end());
    cout << "Min : " << times[0] << endl;
    cout << "Max : " << times[n - 1] << endl;
    cout << "Median : " << times[n / 2] << endl;
    cout << "Mean : " << sum / n << endl;
    cout << "GB : " << GO << endl;
    }

bool isBandwidthOK()
    {
    bool isOk = true;
    int mp = Device::getMPCount();
    int coreMP = Device::getCoreCountMP();
    dim3 dg = dim3(mp*1000, 1, 1);
    dim3 db = dim3(1024, 1, 1);
    Grid grid(dg, db);
//    for(int i = 16; i<=64; ++i) //Démarrage à 16 afin d'avoir des tests assez rapides
//	{
//	dg.x = i;
//	grid.dg = dg;
//	for(int j = 4; j<=1024; j*=2)
//	    {
//	    db.x = j;
//	    grid.db = db;
//	    cout << grid << endl;
    isOk &= isBandwidthOK(grid);
//	    }
//	}
    return isOk;
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
