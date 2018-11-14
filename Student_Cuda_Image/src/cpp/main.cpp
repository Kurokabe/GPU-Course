#include <stdlib.h>
#include <assert.h>
#include <iostream>

#include "cudaTools.h"
#include "Device.h"

#include "Settings_GPU.h"
using namespace gpu;

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Imported	 	*|
 \*-------------------------------------*/

extern int mainImage(Settings& settings);
extern int mainAnimable(Settings& settings);
extern int mainBrutForce(Settings& settings);
extern int mainBarivox(Settings& settings);

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

int main(int argc, char** argv);

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

static int use(Settings& option);
static int start(Settings& option);
static void initCuda(Settings& option);

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

int main(int argc, char** argv)
    {
    // Server Cuda2: in [0,3]	(4 Devices)
    // Server Cuda3: in [0,2]	(2 Devices)
    int DEVICE_ID = 0;

    LaunchMode launchMode = LaunchMode::IMAGE; // IMAGE  ANIMABLE  BARIVOX FORCEBRUT
    Settings settings(launchMode, DEVICE_ID, argc, argv);

    return use(settings);
    }

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

int use(Settings& settings)
    {
    initCuda(settings);
    int isOk = start(settings);

    Device::reset(); //cudaDeviceReset causes the driver to clean up all state. While not mandatory in normal operation, it is good practice.

    return isOk;
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

void initCuda(Settings& settings)
    {
    int deviceId = settings.getDeviceId();

// Choose current device  (state of host-thread)
    Device::setDevice(deviceId);
    assert(Device::isCuda());

// It can be usefull to preload driver, by example to practice benchmarking! (sometimes slow under linux)
    Device::loadCudaDriver(deviceId);
// Device::loadCudaDriverAll();// Force driver to be load for all GPU
    }

int start(Settings& settings)
    {
// print
	{
	// Device::printAll();
	Device::printAllSimple();
	Device::printCurrent();
	//Device::print(option.getDeviceId());
	}

    switch (settings.getLauchMode())
	{
	case IMAGE:
	    return mainImage(settings);
	case ANIMABLE:
	    return mainAnimable(settings);
	case FORCEBRUT:
	    return mainBrutForce(settings);
	case BARIVOX:
	    return mainBarivox(settings);
	default:
	    return mainImage(settings);
	}
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

