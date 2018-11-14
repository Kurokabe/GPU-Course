#pragma once

#include "DamierHSBAFloatMath.h"

#include "cudaType_CPU.h"
#include "Variateur_CPU.h"
#include "Animable_I_CPU.h"
using namespace cpu;

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class DamierHSBAFloat: public Animable_I<float4>
    {

	/*--------------------------------------*\
	 |*		Constructeur		*|
	 \*-------------------------------------*/

    public:

	DamierHSBAFloat(uint w, uint h, float dt, uint n, const DomaineMath& domaineMath);

	virtual ~DamierHSBAFloat(void);

	/*--------------------------------------*\
	 |*		Methode			*|
	 \*-------------------------------------*/

    public:

	/*-------------------------*\
	|*   Override Animable_I   *|
	 \*------------------------*/

	/**
	 * Call periodicly by the api
	 */
	virtual void processEntrelacementOMP(float4* ptrTabPixels, uint w, uint h, const DomaineMath& domaineMath);

	/**
	 * Call periodicly by the api
	 */
	virtual void processForAutoOMP(float4* ptrTabPixels, uint w, uint h, const DomaineMath& domaineMath);

	/**
	 * Call periodicly by the api
	 */
	virtual void animationStep();

    private:

	/**
	 * i in [0,h[
	 * j in [0,w[
	 *
	 * code commun a:
	 * 	- entrelacementOMP
	 * 	- forAutoOMP
	 */
	void workPixel(float4* ptrColorIJ, int i, int j, const DomaineMath& domaineMath, DamierHSBAFloatMath* ptrDamierMath);

	/*--------------------------------------*\
	|*		Attribut		*|
	 \*-------------------------------------*/

    private:

	// Inputs
	uint n;

	// Tools
	Variateur<float> variateurAnimation;

    };

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 /*----------------------------------------------------------------------*/
