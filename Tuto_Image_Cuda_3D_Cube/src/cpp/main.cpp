#include <stdlib.h>
#include <iostream>
#include <assert.h>

#include "GLUTWindowManagers.h"
#include "Device.h"

using std::cout;
using std::endl;

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

extern void mainCore();

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

int main(int argc, char **argv)
    {
    GLUTWindowManagers::init(argc, argv);

    // Server Cuda2: in [0,3]	(4 Devices)
    // Server Cuda3: in [0,2]	(2 Devices)
    int deviceId = 0;
    Device::setDevice(deviceId);
    assert(Device::isCuda());

    Device::loadCudaDriver(deviceId);
    // Device::loadCudaDriverAll();

    // print
	{
	//Device::printAll();
	Device::printAllSimple();
	//Device::printCurrent();
	}

    mainCore();

    Device::reset(); //cudaDeviceReset causes the driver to clean up all state. While not mandatory in normal operation, it is good practice.

    return EXIT_SUCCESS;
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

