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
    const double dx = 1 / (double)n;
        const int NB_THREAD = OmpTools::setAndGetNaturalGranularity();
        double tabSumThread[NB_THREAD];

        //Reduction intraThread
#pragma omp parallel for
        for (int i = 0; i <= n; ++i)
    	{
    	double xi = i * dx;
    	tabSumThread[OmpTools::getTid()] += fpi(xi);
    	}
        //Reduction Séquentiel InterThread
        double sum = 0;
	for(int i=0;i<=NB_THREAD;i++)
	    {
	    sum+=tabSumThread[i];
	    }
        return sum / n;
    }



/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

