#include <iostream>
#include <stdlib.h>

#include "BruteForce.h"
#include "ProviderGridMaillage1D.h"
#include "ProviderGridMaillage2D.h"

#include "RipplingProvider.h"
#include "Animateur_GPU.h"
#include "Settings_GPU.h"

#include "MandelbrotProvider.h"
#include "RaytracingProvider.h"
using namespace gpu;

using std::cout;
using std::endl;

/*----------------------------------------------------------------------*\
 |* Declaration *|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Imported	 	*|
 \*-------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

int mainBrutForce(Settings& settings);

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

static void rippling();
static void mandelbrot();
static void raytracing();

// tools
template<typename T>
static void bruteForce(Provider_I<T>* ptrProvider, string titre,int nbIteration);

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

int mainBrutForce(Settings& settings)
    {
    cout << "\n[BruteForce] mode" << endl;

    // Please, un a la fois!
    //rippling();
    mandelbrot(); // Conseil : use nFixe (by example nMin=nMax=80)
//    raytracing();

    cout << "\n[BruteForce] end" << endl;

    return EXIT_SUCCESS;
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

void rippling()
    {
    const int NB_ITERATION = 1000;

    RipplingProvider provider;
    bruteForce<uchar4>(&provider, "Rippling_RGBA_uchar4",NB_ITERATION);
    }

void mandelbrot()
    {
    const int NB_ITERATION = 1000;

    MandelbrotProvider provider;
    bruteForce<uchar4>(&provider, "mandelbrot_RGBA_uchar4",NB_ITERATION);
    }

void raytracing()
    {
    const int NB_ITERATION = 20;

    RaytracingProvider provider;
    bruteForce<uchar4>(&provider, "Raytracing_RGBA_uchar4",NB_ITERATION);
    }

/*--------------------------------------*\
 |*		Tools			*|
 \*-------------------------------------*/

template<typename T>
void bruteForce(Provider_I<T>* ptrProvider, string titre, int nbIteration)
    {
    cout << "\n[BruteForce] : " << titre << endl;

    const bool IS_ANIMATOR_VERBOSITY = false;
    const bool IS_FORCE_BRUT_VERBOSITY = true;

    // Define Grid
    int mp = Device::getMPCount();
    int coreMp = Device::getCoreCountMP();
    int nbThreadBlockMax = Device::getMaxThreadPerBlock();
    int warpSize = Device::getWarpSize();

    VariateurData variateurDg(mp, 8 * mp, mp); 				// (min,max,step) 	Attention : A definir intelligement selon le GPU !
    VariateurData variateurDb(coreMp, nbThreadBlockMax, warpSize); 	// (min,max,step) 	Attention : A definir intelligement selon le GPU !

    // Run
    BruteForce<T> bruteForce(ptrProvider, variateurDg, variateurDb, nbIteration, IS_FORCE_BRUT_VERBOSITY, IS_ANIMATOR_VERBOSITY);
    ForceBrutOutput output = bruteForce.run();

    // Save
    output.save("out/bruteforce/" + titre);

    // Print
    cout << output << endl;
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
