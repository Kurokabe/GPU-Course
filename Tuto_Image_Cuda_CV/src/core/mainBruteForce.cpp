#include <iostream>
#include <stdlib.h>

#include "ImageVideoProvider.h"

#include "BruteForce.h"
#include "ProviderGridMaillage1D.h"
#include "ProviderGridMaillage2D.h"

#include "Animateur_GPU.h"
#include "Settings_GPU.h"
using namespace gpu;

using std::cout;
using std::endl;
using std::string;

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

static void imageVideo();

// tools
template<typename T>
static void bruteForce(Provider_I<T>* ptrProvider, string titre, int nbIteration=1000);

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

int mainBrutForce(Settings& settings)
    {
    cout << "\n[BruteForce] mode" << endl;

    // Attention : Un a la fois seulement!

    imageVideo();

    cout << "\n[BruteForce] end" << endl;

    return EXIT_SUCCESS;
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

void imageVideo()
    {
    const int NB_ITERATION= 1000;

    ImageVideoProvider provider;
    bruteForce<uchar4>(&provider, "ImageVideo_RGBA_uchar4",NB_ITERATION);
    }

/*--------------------------------------*\
 |*		Tools			*|
 \*-------------------------------------*/

template<typename T>
void bruteForce(Provider_I<T>* ptrProvider, string titre,int nbIteration)
    {
    cout << "\n[BruteForce] : " << titre << endl;

    // Define Grid
    int mp = Device::getMPCount();
    int coreMp = Device::getCoreCountMP();
    int nbThreadBlockMax = Device::getMaxThreadPerBlock();
    int warpSize = Device::getWarpSize();

    VariateurData variateurDg(mp, 8 * mp, mp); 				// (min,max,step) 	Attention : A definir intelligement selon le GPU !
    VariateurData variateurDb(coreMp, nbThreadBlockMax, warpSize); 	// (min,max,step) 	Attention : A definir intelligement selon le GPU !

    // Run
    const bool IS_ANIMATOR_VERBOSITY = false;
    const bool IS_FORCE_BRUT_VERBOSITY = true;

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
