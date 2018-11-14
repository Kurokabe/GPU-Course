#include <iostream>
#include <stdlib.h>

#include "VagueProvider.h"
#include "DamierProvider.h"
#include "VagueGrayProvider.h"
#include "DamierRGBAFloatProvider.h"
#include "DamierHSBAFloatProvider.h"
#include "DamierHueFloatProvider.h"

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

static void vague();
static void damier();
static void vagueGray();
static void damierRGBAfloat();
static void damierHSBAfloat();
static void damierHUEfloat();

// tools
template<typename T>
static void bruteForce(Provider_I<T>* ptrProvider, string titre,int nbIteration=1000);

// advanced
static void advanced();
static void advanced_example1();
static void advanced_example2();
static void advanced_example3();
static void advanced_useOutputCustom(ForceBrutOutput* ptrOutput);

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

    vague();
//    damier();
//    vagueGray();
//    damierRGBAfloat();
//    damierHSBAfloat();
//    damierHUEfloat();

// advanced();

    cout << "\n[BruteForce] end" << endl;

    return EXIT_SUCCESS;
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

void vague()
    {
    const int NB_ITERATION= 1000;

    VagueProvider provider;
    bruteForce<uchar4>(&provider, "Vague_RGBA_uchar4",NB_ITERATION);
    }

void damier()
    {
    const int NB_ITERATION= 1000;

    DamierProvider provider;
    bruteForce<uchar4>(&provider, "Damier_RGBA_uchar4",NB_ITERATION);
    }

void vagueGray()
    {
    const int NB_ITERATION= 1000;

    VagueGrayProvider provider;
    bruteForce<uchar>(&provider, "Vague_GRAY_uchar",NB_ITERATION);
    }

void damierRGBAfloat()
    {
    const int NB_ITERATION= 1000;

    DamierRGBAFloatProvider provider;
    bruteForce<float4>(&provider, "Damier_RGBA_float4",NB_ITERATION);
    }

void damierHSBAfloat()
    {
    const int NB_ITERATION= 1000;

    DamierHSBAFloatProvider provider;
    bruteForce<float4>(&provider, "Damier_HSBA_float4",NB_ITERATION);
    }

void damierHUEfloat()
    {
    const int NB_ITERATION= 1000;

    DamierHueFloatProvider provider;
    bruteForce<float>(&provider, "Damier_HUE_float",NB_ITERATION);
    }

/*--------------------------------------*\
 |*		Tools			*|
 \*-------------------------------------*/

template<typename T>
void bruteForce(Provider_I<T>* ptrProvider, string titre, int nbIteration)
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

/*--------------------------------------*\
 |*		Advanced		*|
 \*-------------------------------------*/

void advanced()
    {
    // Exemple1 : grid 1D predefini (conseiller)
	{
	advanced_example1();
	}

    // Exemple2 : grid 2D predefini (deconseiller suf si votre code requiert explicitement une grid2d)
	{
	advanced_example2();
	}

    // Exemple3 : grid 1D-2D-3D custom (deconseiller, sauf cas special)
	{
	advanced_example3();
	}
    }

/*---------------------*\
 |* grid 1D predefini  *|
 \*--------------------*/

/**
 * grid 1D predefini
 */
void advanced_example1()
    {
    cout << "\n[BruteForce] : Vague : grid 1D predefini :" << endl;

    const bool IS_ANIMATOR_VERBOSITY = false;
    const bool IS_FORCE_BRUT_VERBOSITY = true;
    const int NB_ITERATION_ANIMATOR = 1000;

    // Define Grid
    VariateurData variateurDg(16, 5 * 16, 16); // (min,max,step)	Attention : A definir intelligement selon le GPU !
    VariateurData variateurDb(32, 8 * 32, 32); // (min,max,step)	Attention : A definir intelligement selon le GPU !

    //Run
    VagueProvider provider;
    BruteForce < uchar4 > bruteForce(&provider, variateurDg, variateurDb, NB_ITERATION_ANIMATOR, IS_FORCE_BRUT_VERBOSITY, IS_ANIMATOR_VERBOSITY);
    ForceBrutOutput output = bruteForce.run();

    // Result
    cout << output << endl;

    // save
    output.save("out/bruteforce/advanced");

    // Use custom output
    advanced_useOutputCustom(&output);
    }

void advanced_useOutputCustom(ForceBrutOutput* ptrOutput)
    {
    cout << "\n[BruteForce] : : Vague : grid 1D predefini : use ForceBrutOutput custom :" << endl << endl;

    const GridMaillage* ptrGridMaillage = ptrOutput->getGridMaillage();
    int n = ptrGridMaillage->getN(); // dg
    int m = ptrGridMaillage->getM(); // db

    // Affiche result
	{
	vector < GridFps > tabMax = ptrOutput->getMax();
	// Print
	    {
	    cout << "Output brutforce (#Threads Total) = " << endl << ptrOutput->toStringThreadTotal() << endl;
	    cout << "Output brutforce (#Blocks) = " << endl << ptrOutput->toStringNbBlocks() << endl;
	    cout << "Output brutforce (#Threads ByBlock) = " << endl << ptrOutput->toStringThreadByBlock() << endl;
	    cout << "Output brutforce (grid)" << (*ptrGridMaillage) << endl;
	    cout << "Output brutforce (fps) = " << endl << ptrOutput->toStringFps() << endl;
	    cout << "Output brutforce (max) = " << endl << ForceBrutOutput::toString(tabMax) << endl;
	    }
	}

    // Affichage custom : maillage
	{
	cout << "\nAffichage Custom maillage:" << endl;
	Grid* ptrTabGrid = ptrGridMaillage->getTabGrid();
	cout << "dg x db :" << endl;
	for (int i = 1; i <= n * m; i++)
	    {
	    cout << "(" << ptrTabGrid[i - 1].dg.x << "," << ptrTabGrid[i - 1].dg.y << "," << ptrTabGrid[i - 1].dg.z << ")";
	    cout << "x";
	    cout << "(" << ptrTabGrid[i - 1].db.x << "," << ptrTabGrid[i - 1].db.y << "," << ptrTabGrid[i - 1].db.z << ")";
	    cout << "\t";
	    if (i % m == 0)
		{
		cout << endl;
		}
	    }
	}

    // Affichage custom : fps
	{
	cout << "\nAffichage Custom fps:" << endl;
	int* tabFps = ptrOutput->getTabFps();
	for (int i = 1; i <= n * m; i++)
	    {
	    cout << tabFps[i - 1] << "\t";
	    if (i % m == 0)
		{
		cout << endl;
		}
	    }
	}
    }

/*---------------------*\
 |* grid 2D predefini  *|
 \*--------------------*/

/**
 * grid 2D predefini
 */
void advanced_example2()
    {
    cout << "\n[BruteForce] : : Vague : grid 2D predefini :" << endl;

    const bool IS_ANIMATOR_VERBOSITY = false; //TODO cbi optionBarivox
    const bool IS_FORCE_BRUT_VERBOSITY = true;
    const int NB_ITERATION_ANIMATOR = 1000;

    // Define grid : Attention : A definir intelligement selon le GPU !
    // Grid
    VariateurData variateurDgX(16, 4 * 16, 16); // (min,max,step)
    VariateurData variateurDgY(1, 4, 1); // (min,max,step
    //Block : Attention #threadPerBlock max = 1024 ie 32x32!
    VariateurData variateurDbX(8, 4 * 8, 8); // (min,max,step)
    VariateurData variateurDbY(8, 4 * 8, 8); // (min,max,step)

    // run
    VagueProvider provider;
    BruteForce < uchar4
	    > bruteForce(&provider, variateurDgX, variateurDgY, variateurDbX, variateurDbY, NB_ITERATION_ANIMATOR, IS_FORCE_BRUT_VERBOSITY,
		    IS_ANIMATOR_VERBOSITY);
    ForceBrutOutput output = bruteForce.run();

    // Result
    cout << output << endl;
    }

/*---------------------*\
 |* grid 1D-2D-3D custom  *|
 \*--------------------*/

/**
 * grid 1D-2D-3D custom
 */
void advanced_example3()
    {
    cout << "\n[BruteForce] : : Vague : grid 1D-2D-3D custom :" << endl;

    const bool IS_ANIMATOR_VERBOSITY = false;
    const bool IS_FORCE_BRUT_VERBOSITY = true;
    const int NB_ITERATION_ANIMATOR = 1000;

    // Define grid : Attention : A definir intelligement selon le GPU !
    int n = 2;
    int m = 3;
    Grid tabGrid[6];
    tabGrid[0] = Grid(dim3(1, 1, 1), dim3(32, 1, 1)); // Grid(dg,db)
    tabGrid[1] = Grid(dim3(1, 1, 1), dim3(64, 1, 1)); // Grid(dg,db)
    tabGrid[2] = Grid(dim3(1, 1, 1), dim3(128, 1, 1)); // Grid(dg,db)
    tabGrid[3] = Grid(dim3(16, 1, 1), dim3(32, 1, 1)); // Grid(dg,db)
    tabGrid[4] = Grid(dim3(16, 1, 1), dim3(64, 1, 1)); // Grid(dg,db)
    tabGrid[5] = Grid(dim3(16, 1, 1), dim3(128, 1, 1)); // Grid(dg,db)

    // Run
    VagueProvider provider;
    BruteForce < uchar4 > bruteForce(&provider, tabGrid, n, m, NB_ITERATION_ANIMATOR, IS_FORCE_BRUT_VERBOSITY, IS_ANIMATOR_VERBOSITY);
    ForceBrutOutput output = bruteForce.run();

    // Result
    cout << output << endl;
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
