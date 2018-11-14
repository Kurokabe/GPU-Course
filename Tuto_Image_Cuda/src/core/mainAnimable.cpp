#include <iostream>
#include <stdlib.h>

#include "VagueProvider.h"
#include "DamierProvider.h"
#include "VagueGrayProvider.h"
#include "DamierRGBAFloatProvider.h"
#include "DamierHSBAFloatProvider.h"
#include "DamierHueFloatProvider.h"

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

static void vague();
static void damier();
static void vagueGray();
static void damierRGBAFloat();
static void damierHSBAFloat();
static void damierHueFloat();

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

    vague();
    damier();
    vagueGray();
    damierRGBAFloat();
    damierHSBAFloat();
    damierHueFloat();

    cout << "\n[Animable] end" << endl;

    return EXIT_SUCCESS;
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

void vague()
    {
    const int NB_ITERATION = 20000;

    VagueProvider provider;
    animer<uchar4>(&provider,NB_ITERATION);
    }

void damier()
    {
    const int NB_ITERATION = 20000;

    DamierProvider provider;
    animer<uchar4>(&provider,NB_ITERATION);
    }

void vagueGray()
    {
    const int NB_ITERATION = 20000;

    VagueGrayProvider provider;
    animer<uchar>(&provider,NB_ITERATION);
    }

void damierRGBAFloat()
    {
    const int NB_ITERATION = 20000;

    DamierRGBAFloatProvider provider;
    animer<float4>(&provider,NB_ITERATION);
    }

void damierHSBAFloat()
    {
    const int NB_ITERATION = 20000;

    DamierHSBAFloatProvider provider;
    animer<float4>(&provider,NB_ITERATION);

    // Attention (interpretation result):
    // Ici shader ne travaille plus,
    // donc par rapport � une version rgba sans shader,
    // le travaille � faire ici est plus petit
    }

void damierHueFloat()
    {
    const int NB_ITERATION = 20000;

    DamierHueFloatProvider provider;
    animer<float>(&provider,NB_ITERATION);

    // Attention (interpretation result):
    // Ici shader ne travaille plus,
    // donc par rapport � une version rgba sans shader,
    // le travaille � faire ici est plus petit
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

