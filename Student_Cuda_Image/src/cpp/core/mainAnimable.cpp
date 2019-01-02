#include <iostream>
#include <stdlib.h>

#include "RipplingProvider.h"
#include "Animateur_GPU.h"
#include "Settings_GPU.h"

#include "MandelbrotProvider.h"
#include "RaytracingProvider.h"
using namespace gpu;

using std::cout;
using std::endl;

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Imported	 	*|
 \*-------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

int mainAnimable(Settings& settings);

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

static void rippling();
static void mandelbrot();
static void raytracing();

// Tools
template<typename T>
static void animer(Provider_I<T>* ptrProvider, int nbIteration);

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

int mainAnimable(Settings& settings)
    {
    cout << "\n[Animable] mode" << endl;

    // Please, un a la fois!
    rippling();
//    mandelbrot(); // Conseil : use nFixe (by example nMin=nMax=80)
//    raytracing();

    cout << "\n[Animable] end" << endl;

    return EXIT_SUCCESS;
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

void rippling()
    {
    //const int NB_ITERATION = 50000;
    const int NB_ITERATION = 500;

    RipplingProvider provider;
    animer<uchar4>(&provider, NB_ITERATION);
    }

void mandelbrot()
    {
    const int NB_ITERATION = 500;

    MandelbrotProvider provider;
    animer<uchar4>(&provider, NB_ITERATION);
    }

void raytracing()
    {
    const int NB_ITERATION = 500;

    RaytracingProvider provider;
    animer<uchar4>(&provider, NB_ITERATION);
    }

/*-----------------------------------*\
 |*		Tools	        	*|
 \*-----------------------------------*/

template<typename T>
void animer(Provider_I<T>* ptrProvider, int nbIteration)
    {
    Animateur<T> animateur(ptrProvider, nbIteration);
    animateur.run();
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

