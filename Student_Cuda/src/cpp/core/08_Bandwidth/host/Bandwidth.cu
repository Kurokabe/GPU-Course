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
	    Device::hostMalloc(&tabDataGM, sizeTabDataGM, HostMemoryType::MAPPED_MULTIGPU);
	    break;
	case TransferType::DeviceToDevice:
	    Device::malloc(&tabDataGM, sizeTabDataGM);
	    Device::malloc(&tabDataGMCopy, sizeTabDataGM);

	    Device::memcpyHToD(tabDataGM, tabData, sizeTabDataGM);
	    break;
	case TransferType::DeviceToDeviceMultiGPUEntrelacement:
	case TransferType::DeviceToDeviceMultiGPUOneOne:
	case TransferType::DeviceToDeviceMultiGPU:
	    Device::setDevice(0);
	    Device::malloc(&tabDataGM, sizeTabDataGM);
	    Device::setDevice(1);
	    Device::malloc(&tabDataGMCopy, sizeTabDataGM);
	    Device::setDevice(0);
	    Device::memcpyHToD(tabDataGM, tabData, sizeTabDataGM);
	    break;
	case TransferType::DeviceToDeviceEntrelacement:
	case TransferType::DeviceToDeviceOneOne:
	    Device::malloc(&tabDataGM, sizeTabDataGM);
	    Device::malloc(&tabDataGMCopy, sizeTabDataGM);
	    break;
	}

    int mp = Device::getMPCount();
    int coreMP = Device::getCoreCountMP();
    dim3 dg = dim3(mp*12, 1, 1);
    dim3 db = dim3(coreMP, 1, 1);
    Chrono chrono;
    switch (type)
	{
	case TransferType::HostToDevice:
	case TransferType::HostToDeviceDMA:
	    Device::memcpyHToD(tabDataGM, tabData, sizeTabDataGM);
	    break;
	case TransferType::DeviceToDeviceMultiGPU:
	case TransferType::DeviceToDevice:
	    Device::memcpyDToD(tabDataGMCopy, tabDataGM, sizeTabDataGM);
	    Device::synchronize();
	    break;
	case TransferType::DeviceToDeviceMultiGPUEntrelacement:
	case TransferType::DeviceToDeviceEntrelacement:
	    kernelBandwidthEntrelacement<<<dg,db>>>(tabDataGM,tabDataGMCopy,n);
	    Device::synchronize();
	    break;
	case TransferType::DeviceToDeviceMultiGPUOneOne:
	case TransferType::DeviceToDeviceOneOne:
//	    dim3 dg = dim3(n/1024, 1, 1);
//	    dim3 db = dim3(1024, 1, 1);
//	    kernelBandwidthOneOne<<<dg,db>>>(tabDataGM,tabDataGMCopy,n);
	    Device::synchronize();
	    break;

	}

    chrono.stop();

    elapsedTime = chrono.getElapseTimeS();
    cout << elapsedTime<< endl;

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
	case TransferType::DeviceToDeviceEntrelacement:
	case TransferType::DeviceToDeviceOneOne:
	    Device::free(tabDataGM);
	    Device::free(tabDataGMCopy);
	    break;
	case TransferType::DeviceToDeviceMultiGPUEntrelacement:
	case TransferType::DeviceToDeviceMultiGPUOneOne:
	case TransferType::DeviceToDeviceMultiGPU:
	    Device::free(tabDataGM);
	    Device::setDevice(1);
	    Device::free(tabDataGMCopy);
	    Device::setDevice(0);
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
