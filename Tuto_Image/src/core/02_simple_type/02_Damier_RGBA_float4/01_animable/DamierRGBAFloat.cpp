#include "DamierRGBAFloat.h"
#include "DamierRGBAFloatMath.h"

#include <iostream>
#include <omp.h>
#include "OmpTools.h"

#include "IndiceTools_CPU.h"
using cpu::IndiceTools;

using std::cout;
using std::endl;

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

DamierRGBAFloat::DamierRGBAFloat(uint w, uint h, float dt, uint n, const DomaineMath& domaineMath) :
	Animable_I<float4>(w, h, "Damier_OMP_rgba_float4",domaineMath), variateurAnimation(Interval<float>(0, 2 * PI), dt)
    {
    // Input
    this->n = n;

    // Tools
    this->t = 0;					// protected dans super classe Animable
    this->parallelPatern = ParallelPatern::OMP_MIXTE;   // protected dans super classe Animable

    // OMP
    cout << "\n[Damier] : OMP : nbThread = " << this->nbThread << endl; // protected dans super classe Animable
    }

DamierRGBAFloat::~DamierRGBAFloat(void)
    {
    // rien
    }

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

/**
 * Override
 */
void DamierRGBAFloat::animationStep()
    {
    this->t = variateurAnimation.varierAndGet(); // in [0,2pi]
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/**
 * Override (code naturel omp)
 */
void DamierRGBAFloat::processForAutoOMP(float4* ptrTabPixels, uint w, uint h, const DomaineMath& domaineMath)
    {
    DamierRGBAFloatMath damierMath(n); // ici pour preparer cuda

#pragma omp parallel for
    for (int i = 0; i < h; i++)
	{
	for (int j = 0; j < w; j++)
	    {
	    // int s = i * W + j;
	    int s = IndiceTools::toS(w, i, j);    // i[0,H[ j[0,W[  --> s[0,W*H[

	    workPixel(&ptrTabPixels[s],i,j,domaineMath,&damierMath);
	    }
	}
    }

/**
 * Override (code entrainement cuda)
 */
void DamierRGBAFloat::processEntrelacementOMP(float4* ptrTabPixels, uint w, uint h, const DomaineMath& domaineMath)
    {
    DamierRGBAFloatMath damierMath(n); // ici pour preparer cuda

    const int WH = w * h;

#pragma omp parallel
	{
	const int NB_THREAD = OmpTools::getNbThread(); // dans region parallel
	const int TID = OmpTools::getTid();

	int i;
	int j;

	int s = TID; // in [0,...
	while (s < WH)
	    {
	    IndiceTools::toIJ(s, w, &i, &j); // s[0,W*H[ --> i[0,H[ j[0,W[

	    workPixel(&ptrTabPixels[s],i,j,domaineMath,&damierMath);

	    s += NB_THREAD;
	    }
	}
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/**
 * i in [0,h[
 * j in [0,w[
 *
 * code commun a:
 * 	- entrelacementOMP
 * 	- forAutoOMP
 */
void DamierRGBAFloat::workPixel(float4* ptrColorIJ,int i, int j,const DomaineMath& domaineMath,DamierRGBAFloatMath* ptrDamierMath)
    {
    // (i,j) domaine ecran dans N2
    // (x,y) domaine math dans R2

    double x;
    double y;
    domaineMath.toXY(i, j, &x, &y); // fill (x,y) from (i,j)

   // float t=variateurAnimation.get();

    ptrDamierMath->colorXY(ptrColorIJ,x, y, t); // in [01]
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

