#include <iostream>
#include <assert.h>

#include "Device.h"
#include <assert.h>
#include "IndiceTools_GPU.h"
#include "HeatTransfer.h"

using std::cout;
using std::endl;

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Imported	 	*|
 \*-------------------------------------*/
extern __global__ void createHeater(float *ptrDevImageHeater, int* positions, int nPositions, uint w, uint h);
extern __global__ void diffusion(float *ptrDevImageA, float *ptrDevImageB, int flag, uint w, uint h);
extern __global__ void ecrasement(float *ptrDevImageHeater, float *ptrImage, uint w, uint h);
extern __global__ void toScreenImageHSB(uchar4 *ptrDevPixels, float* ptrDevImage, Calibreur<float> calibreur, uint w, uint h);
/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

/*-------------------------*\
 |*	Constructeur	    *|
 \*-------------------------*/

HeatTransfer::HeatTransfer(const Grid &grid, uint w, uint h, float dt) :
	Animable_I<uchar4>(grid, w, h, "HeatTransfer_Cuda_RGBA_uchar4"), flag(0), nbIter(0)
    {
    assert(w == h); // specific HeatTransfer

    Interval<float> start(0, 1); // chaleur min,nax
    Interval<float> stop(0.7, 1); // hue min,max
    calibreur = new Calibreur<float>(start, stop);

    Device::malloc(&ptrDevImageA, sizeof(float) * w * h);
    Device::malloc(&ptrDevImageB, sizeof(float) * w * h);
    Device::malloc(&ptrDevImageHeater, sizeof(float) * w * h);
    Device::malloc(&ptrDevImageInit, sizeof(float) * w * h);

    Device::memclear(ptrDevImageA, sizeof(float) * w * h);
    Device::memclear(ptrDevImageB, sizeof(float) * w * h);
    //Device::memclear(ptrDevImageHeater, sizeof(float) * w * h);
    Device::memclear(ptrDevImageInit, sizeof(float) * w * h);

    int positions[]= { IndiceTools::toS(w, 400, 400) };
    createHeater<<<dg, db>>>(ptrDevImageHeater, positions, 1, w, h);


    // Animation
    this->dt = dt;
    this->t = 0; // protected dans Animable
    }

HeatTransfer::~HeatTransfer()
    {
    Device::free(ptrDevImageA);
    Device::free(ptrDevImageB);
    Device::free(ptrDevImageHeater);
    Device::free(ptrDevImageInit);
    }

/*-------------------------*\
 |*	Methode		    *|
 \*-------------------------*/

/**
 * Override
 * Call periodicly by the API
 *
 * Note : domaineMath pas use car image pas zoomable
 */
void HeatTransfer::process(uchar4 *ptrDevPixels, uint w, uint h, const DomaineMath &domaineMath)
    {
    float *ptrDevImage = flag == 0 ? ptrDevImageA : ptrDevImageB;

    diffusion<<<dg, db>>>(ptrDevImageA, ptrDevImageB, flag, w, h);
    Device::synchronize();
    ecrasement<<<dg, db>>>(ptrDevImageHeater, ptrDevImage, w, h);
    Device::synchronize();
    if (nbIter >= NB_ITER_AVEUGLE)
	{
	toScreenImageHSB<<<dg, db>>>(ptrDevPixels, ptrDevImage, *calibreur, w, h);
	nbIter = 0;
	}

    }

/**
 * Override
 * Call periodicly by the API
 */
void HeatTransfer::animationStep()
    {
    t += dt;
    nbIter++;
    flag = (flag + 1) % 2;

    }

void HeatTransfer::setDT(int dt)
    {
    this->dt = dt;
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

