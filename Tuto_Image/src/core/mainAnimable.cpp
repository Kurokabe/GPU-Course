#include <iostream>
#include <stdlib.h>

#include "DamierProvider.h"
#include "VagueProvider.h"
#include "VagueGrayProvider.h"
#include "DamierRGBAFloatProvider.h"
#include "DamierHSBAFloatProvider.h"
#include "DamierHueFloatProvider.h"

#include "Animateur_CPU.h"
#include "Settings_CPU.h"
using namespace cpu;

using std::cout;
using std::endl;
using std::string;

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
static void damierRGBAFloat4();
static void damierHSBAFloat4();
static void damierHueFloat();

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

    vague();
    damier();

    vagueGray();
    damierRGBAFloat4();
    damierHSBAFloat4();
    damierHueFloat();

    cout << "\n[Animable] end" << endl;

    return EXIT_SUCCESS;
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

void vague()
    {
    const int NB_ITERATION = 1000;

    VagueProvider provider;
    animer<uchar4>(&provider,NB_ITERATION);
    }

void damier()
    {
    const int NB_ITERATION = 1000;

    DamierProvider provider;
    animer<uchar4>(&provider,NB_ITERATION);
    }

void vagueGray()
    {
    const int NB_ITERATION = 1000;

    VagueGrayProvider provider;
    animer<uchar>(&provider,NB_ITERATION);
    }

void damierRGBAFloat4()
    {
    const int NB_ITERATION = 1000;

    DamierRGBAFloatProvider provider;
    animer<float4>(&provider,NB_ITERATION);
    }

void damierHSBAFloat4()
    {
    const int NB_ITERATION = 1000;

    DamierHSBAFloatProvider provider;
    animer<float4>(&provider,NB_ITERATION);
    }

void damierHueFloat()
    {
    const int NB_ITERATION = 1000;

    DamierHueFloatProvider provider;
    animer<float>(&provider,NB_ITERATION);
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

