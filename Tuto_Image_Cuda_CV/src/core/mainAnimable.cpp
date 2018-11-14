#include <iostream>
#include <stdlib.h>

#include "ImageVideoProvider.h"

#include "Animateur_GPU.h"
#include "Settings_GPU.h"
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

static void imageVideo();

// Tools
template<typename T>
static void animer(Provider_I<T>* ptrProvider, int nbIteration=1000);

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

int mainAnimable(Settings& settings)
    {
    cout << "\n[Animable] mode" << endl;

    // Attention : Un a la fois seulement!

    imageVideo();

    cout << "\n[Animable] end" << endl;

    return EXIT_SUCCESS;
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

void imageVideo()
    {
    const int NB_ITERATION = 5000;

    ImageVideoProvider provider;
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

