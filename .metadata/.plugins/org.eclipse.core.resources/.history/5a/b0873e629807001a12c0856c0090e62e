#include "DataCreator.h"
#include <iostream>
#include <assert.h>
#include "AleaTools.h"
using std::cout;
using std::endl;
/*----------------------------------------------------------------------*\
|*
 Implementation
 *|
 \*---------------------------------------------------------------------*/
/*--------------------------------------*\
|*
 Constructeur
 *|
 \*-------------------------------------*/
DataCreator::DataCreator(int dataMax)
    {
    assert(dataMax >= 2);
// Input
    this->dataMax = dataMax;
// Tools
    this->n = dataMax * (dataMax + 1) / 2;
    this->nbMelange = n * 10; // disons
    this->tabData = new int[n];
    createDataTriangulaire();
    melangerData();
    }
DataCreator::~DataCreator()
    {
    delete[] tabData;
    }
/*--------------------------------------*\|*

 Methode
 *|
 \*-------------------------------------*/
int* DataCreator::getTabData()
    {
    return tabData;
    }
int DataCreator::getLength()
    {
    return n;
    }
void DataCreator::print()
    {
    for (int i = 0; i < n; i++)
	{
	cout << tabData[i] << " ";
	}
    }
/*--------------------------------------*\
|*
 Private
 *|
 \*-------------------------------------*/
void DataCreator::createDataTriangulaire(void)
    {
    int s = 0;
    for (int i = 0; i < dataMax; i++)
	{
	for (int j = 1; j <= i + 1; j++)
	    {
	    assert(i >= 0 && i <= dataMax);
	    assert(s < n);
	    tabData[s] = i;
	    s++;
	    }
	}
    assert(s == n);
    }
void DataCreator::melangerData()
    {
    AleaTools aleaTools = AleaTools();
    for (int i = 1; i <= nbMelange; i++)
	{
	int i0n = aleaTools.uniformeAB(0, n - 1);
	int j0n = aleaTools.uniformeAB(0, n - 1);
	swap(i0n, j0n);
	}
    }
void DataCreator::swap(int i, int j)
    {
    assert(i >= 0 && i < n);
    assert(j >= 0 && j < n);
// si j==i ne sert a rien, mais gene pas
    int icopy = tabData[i];
    tabData[i] = tabData[j];
    tabData[j] = icopy;
    }
/*----------------------------------------------------------------------*\
|*
 End
 *|
 \*---------------------------------------------------------------------*/
