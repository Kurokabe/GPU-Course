#pragma once

#include "cudaTools.h"
#include "MathTools.h"
#include "Calibreur_GPU.h"

#include "Animable_I_GPU.h"
using namespace gpu;

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class HeatTransfer: public Animable_I<uchar4>
    {
	/*--------------------------------------*\
	|*		Constructor		*|
	 \*-------------------------------------*/

    public:

	HeatTransfer(const Grid& grid, uint w, uint h, float dt);
	virtual ~HeatTransfer(void);

	/*--------------------------------------*\
	 |*		Methodes		*|
	 \*-------------------------------------*/

    public:

	/*-------------------------*\
	|*   Override Animable_I   *|
	 \*------------------------*/

	/**
	 * Call periodicly by the api
	 */
	virtual void process(uchar4* ptrDevPixels, uint w, uint h, const DomaineMath& domaineMath);

	/**
	 * Call periodicly by the api
	 */
	virtual void animationStep();

	void setDT(int dt);

	/*--------------------------------------*\
	 |*		Attributs		*|
	 \*-------------------------------------*/

    private:

	// Inputs
	dim3 dg, db;
	float dt;
	int flag;
	int nbIter;
	const int NB_ITER_AVEUGLE = 50;

	Calibreur<float> *calibreur;
	float* ptrDevImageHeater;
	float* ptrDevImageInit;
	float* ptrDevImageA;
	float* ptrDevImageB;

    };

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/