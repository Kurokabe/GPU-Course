#include <omp.h>
#include <OmpTools.h>

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

bool isPiOMPEntrelacerPromotionTab_Ok(int n);

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

static double piOMPEntrelacerPromotionTab(int n);

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

bool isPiOMPEntrelacerPromotionTab_Ok(int n)
    {
    return isAlgoPI_OK(piOMPEntrelacerPromotionTab, n, "Pi OMP Entrelacer promotionTab");
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/**
 * pattern cuda : excellent!
 */
double piOMPEntrelacerPromotionTab(int n)
    {
    const int NB_THREAD = OmpTools::setAndGetNaturalGranularity(); //Ligne de configuration pour utiliser autant de threads disponibles que possible

    double tabSumThread [NB_THREAD];
    const double DX = 1 / (double) n;

    //Réduction intra-thread parallèle
#pragma omp parallel
	{
	const int TID = OmpTools::getTid();

	int s = TID;
	double sumThread = 0;
	while (s < n)
	    {
	    double xs = s * DX;
	    sumThread += fpi(xs);
	    s += NB_THREAD;
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

