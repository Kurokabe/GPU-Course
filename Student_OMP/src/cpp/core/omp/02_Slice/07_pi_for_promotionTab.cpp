#include <omp.h>
#include "MathTools.h"
#include "OmpTools.h"
#include "00_pi_tools.h"


/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Imported	 	*|
 \*-------------------------------------*/



/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

bool isPiOMPforPromotionTab_Ok(int n);

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

static double piOMPforPromotionTab(int n);
static void syntaxeSimplifier(double* tabSumThread,int n);
static void syntaxeFull(double* tabSumThread,int n);

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

bool isPiOMPforPromotionTab_Ok(int n)
    {
    return isAlgoPI_OK(piOMPforPromotionTab, n, "Pi OMP for promotion tab");
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/**
 * De-synchronisation avec PromotionTab
 */
double piOMPforPromotionTab(int n)
    {
    const int NB_THREAD = OmpTools::setAndGetNaturalGranularity(); //Ligne de configuration pour utiliser autant de threads disponibles que possible

        double tabSumThread [NB_THREAD];
        const double DX = 1 / (double) n;

        //Réduction intra-thread parallèle
    #pragma omp parallel
    	{
    	const int TID = OmpTools::getTid();

    	double sumThread = 0;
#pragma omp parallel for
	for (int s = TID; s < n; s += NB_THREAD)
    	    {
    	    double xs = s * DX;
    	    sumThread += fpi(xs);
    	    }
    	tabSumThread[TID] = sumThread;
    	}
    	//Reduction inter-thread séquentiel
    	double sum = 0;
    	for(int i=0;i<=NB_THREAD;i++)
    	    {
    	    sum+=tabSumThread[i];
    	    }
        return sum/n;
    }



/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

