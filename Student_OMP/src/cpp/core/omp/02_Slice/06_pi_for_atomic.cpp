#include <omp.h>
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

bool isPiOMPforAtomic_Ok(int n);

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

static double piOMPforAtomic(int n);

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

bool isPiOMPforAtomic_Ok(int n)
    {
    return isAlgoPI_OK(piOMPforAtomic, n, "Pi OMP for atomic");
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/**
 * synchronisation couteuse!
 */
double piOMPforAtomic(int n)
    {
    const int NB_THREAD = OmpTools::setAndGetNaturalGranularity(); //Ligne de configuration pour utiliser autant de threads disponibles que possible

    double sum = 0;

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
#pragma omp atomic
	sum += sumThread;

	}

    return sum / n;
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

