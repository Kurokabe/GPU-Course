#include <iostream>
#include <assert.h>
#include <omp.h>
#include <math.h>

#include "MathTools.h"
#include "Hello.h"
#include "StringTools.h"
#include "OmpTools.h"
#include "IndiceTools_CPU.h"

using std::cout;
using std::endl;
using std::string;

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Constructeur		*|
 \*-------------------------------------*/

Hello::Hello(unsigned int w, unsigned int h, int dt) :
	Image_RGBA_uchar4(w, h), helloMath(w, h)
    {
    // Input
    this->t = 0;

    // Tools
    this->dt = dt;
    this->isEntrelacement = isEntrelacement;

    // OMP (facultatif)
    const int NB_THREAD = OmpTools::setAndGetNaturalGranularity();
    cout << "\n[NATIF] nbThread = " << NB_THREAD << endl;
    }

Hello::~Hello(void)
    {
    // rien
    }

/*--------------------------------------*\
 |*		Methode			*|
 \*-------------------------------------*/

/*--------------------------------------*\
 |*		Override		*|
 \*-------------------------------------*/

/**
 * Override
 * Call automaticly by the api
 */
void Hello::fillImage(uchar4* ptrTabPixels, int w, int h,const DomaineMath& domaineMath)
    {
    launch_OMP(ptrTabPixels, w, h);
    }

/**
 * Override
 * Call automaticly by the api
 */
void Hello::animationStep(bool& isNeedUpdateView)
    {
    this->t += dt;
    }

/**
 * Override
 * Call automaticly by the api
 */
void Hello::paintPrimitives(Graphic2D& graphic2D)
    {
    float r = 1;
    float g = 0;
    float b = 0;

    graphic2D.setColorRGB(r, g, b);

    // Top
	{
	graphic2D.setFont(BITMAP_15);
	//string message = "t= " + StringTools::toString(t) + " dt=" + StringTools::toString(dt);
	string message = " dt=" + StringTools::toString(dt);
	graphic2D.drawTitleTop(message);
	}

    // Bottom
	{
	graphic2D.setFont(TIMES_ROMAN_24);
	graphic2D.drawTitleBottom("OMP/OpenGL");
	}
    }

/*--------------------------------------*\
 |*		Set			*|
 \*-------------------------------------*/

void Hello::setDt(int dt)
    {
    this->dt = dt;
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

void Hello::launch_OMP(uchar4* ptrTabPixels, int w, int h)
    {
    if (isEntrelacement)
	{
	entrelacementOMP(ptrTabPixels, w, h); // Plus lent
	}
    else
	{
	forAutoOMP(ptrTabPixels, w, h);  // Plus rapide
	}

    isEntrelacement = !isEntrelacement; // Pour tester que les deux implementations fonctionnent
    }

/**
 * Code naturel et direct OMP
 */
void Hello::forAutoOMP(uchar4* ptrTabPixels, int w, int h)
    {
    //const int W = getW();
    //const int H = getH();

    const int WH = w * h;

#pragma omp parallel for
    for (int i = 0; i < h; i++)
	{
	uchar4 color;
	int s;
	for (int j = 0; j < w; j++)
	    {
	    s = IndiceTools::toS(w, i, j);
	    helloMath.color(&color,i, j, t);

	    ptrTabPixels[s] = color;
	    }
	}
    }

/**
 * Code entrainement Cuda
 */
void Hello::entrelacementOMP(uchar4* ptrTabPixels, int w, int h)
    {
    const int NB_THREAD = OmpTools::setAndGetNaturalGranularity();
    const int WH = w * h;

#pragma omp parallel
	{
	int tid = OmpTools::getTid();
	int s = tid; // in [0,...

	uchar4 color;
	int i;
	int j;

	while (s < WH)
	    {
	    IndiceTools::toIJ(s, w, &i, &j); // update (i,j)
	    helloMath.color(&color, i, j, t); 	// update color

	    ptrTabPixels[s] = color;

	    s += NB_THREAD;
	    }
	}
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

