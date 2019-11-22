#include "Bandwidth.h"

#include <iostream>
#include <assert.h>

#include "Device.h"
#include "Chrono.h"

using std::cout;
using std::endl;

/*---------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Imported	 	*|
 \*-------------------------------------*/

extern __global__ void kernelBandwidthEntrelacement(int* tabDataGM, int* tabDataGMCopy, int n);
extern __global__ void kernelBandwidthOneOne(int *tabDataGM,int*tabDataGMCopy, int n );

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*-------------------------------------*\
 |*		Constructeur		*|
 \*-------------------------------------*/

Bandwidth::Bandwidth(const Grid &grid, int *tabData, int n, TransferType type) :
	n(n), type(type)
    {

    this->dg = grid.dg;
    this->db = grid.db;

    this->sizeTabDataGM = sizeof(int) * n; // [octet]

    switch (type)
	{
	case TransferType::HostToDevice:
	    Device::malloc(&tabDataGM, sizeTabDataGM);
	    break;
	case TransferType::HostToDeviceDMA:
	    Device::hostMalloc(&tabDataGM, sizeTabDataGM, HostMemoryType::PRIORITYDEVICE);
	    break;
	case TransferType::DeviceToDevice:
	    Device::malloc(&tabDataGM, sizeTabDataGM);
	    Device::malloc(&tabDataGMCopy, sizeTabDataGM);

	    Device::memcpyHToD(tabDataGM, tabData, sizeTabDataGM);
	    break;
	case TransferType::DeviceToDeviceEntrelacement:
	case TransferType::DeviceToDeviceOneOne:
	    Device::malloc(&tabDataGM, sizeTabDataGM);
	    Device::malloc(&tabDataGMCopy, sizeTabDataGM);
	    break;
	}

    Chrono chrono;
    switch (type)
	{
	case TransferType::HostToDevice:
	case TransferType::HostToDeviceDMA:
	    Device::memcpyHToD(tabDataGM, tabData, sizeTabDataGM);
	    break;
	case TransferType::DeviceToDevice:
	    Device::memcpyDToD(tabDataGMCopy, tabDataGM, sizeTabDataGM);
	    Device::synchronize();
	    break;
	case TransferType::DeviceToDeviceEntrelacement:
	    kernelBandwidthEntrelacement<<<dg,db>>>(tabDataGM,tabDataGMCopy,n);
	    Device::synchronize();
	    break;
	case TransferType::DeviceToDeviceOneOne:
	    dim3 dg = dim3(n/1024, 1, 1);
	    dim3 db = dim3(1024, 1, 1);
	    kernelBandwidthOneOne<<<dg,db>>>(tabDataGM,tabDataGMCopy,n);
	    Device::synchronize();
	    break;

	}

    chrono.stop();

    elapsedTime = chrono.getElapseTimeS();
    cout << "Elapsed time : " << elapsedTime << " (s)" << endl;

    }

Bandwidth::~Bandwidth(void)
    {

    switch (type)
	{
	case TransferType::HostToDevice:
	    Device::free(tabDataGM);
	    break;
	case TransferType::HostToDeviceDMA:
	    Device::hostFree(tabDataGM);
	    break;
	case TransferType::DeviceToDevice:
	    Device::free(tabDataGM);
	    Device::free(tabDataGMCopy);
	    break;
	case TransferType::DeviceToDeviceEntrelacement:
	    Device::free(tabDataGM);
	    Device::free(tabDataGMCopy);

	    break;
	case TransferType::DeviceToDeviceOneOne:
	    Device::free(tabDataGM);
	    Device::free(tabDataGMCopy);
	    break;
	}
    }

double Bandwidth::getElapsedTime()
    {
    return elapsedTime;
    }

/*-------------------------------------*\
 |*		Methode			*|
 \*-------------------------------------*/

void Bandwidth::run()
    {
    //kernelHistogramme<<<dg,db>>>(tabDataGM);
    //Device::memcpyDToH(tabData, tabDataGM);
    }

/*---------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
