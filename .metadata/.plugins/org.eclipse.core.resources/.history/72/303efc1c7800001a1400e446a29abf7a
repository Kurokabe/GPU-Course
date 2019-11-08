#pragma once

#include <assert.h>

#include "Interval_GPU.h"

//using namespace cpu; //surtout pas de using namespace!! Si use dans partie gpu, il va y avoir conflit!
namespace gpu
    {
    template<typename T>
    class Variateur
	{
	public:

	    /*--------------------------------------*\
	|*		Constructor		*|
	     \*-------------------------------------*/

	    __BOTH__
	    Variateur(const Interval<T>& range, T dt)
		{
		// Input
		this->dt = dt;
		this->tMin = range.a;
		this->tMax = range.b;

		// Tools
		this->isCroisssantPhase = true;
		this->t = range.a;

		assert(tMin <= tMax);
		}

	    __BOTH__
	    virtual ~Variateur()
		{
		// rien
		}

	    /*--------------------------------------*\
	|*		Methodes		*|
	     \*-------------------------------------*/

	public:

	    __BOTH__
	    T varierAndGet()
		{
		if (tMin!=tMax)
		    {
		    if (isCroisssantPhase)
			{
			if (t >= tMax)
			    {
			    isCroisssantPhase = false;
			    t -= dt;
			    }
			else
			    {
			    t += dt;
			    }
			}
		    else
			{
			if (t <= tMin)
			    {
			    isCroisssantPhase = true;
			    t += dt;
			    }
			else
			    {
			    t -= dt;
			    }
			}
		    }

		return t;
		}

	    T get()
		{
		return t;
		}

	    /*--------------------------------------*\
	    |*		Attributs		*|
	     \*-------------------------------------*/

	private:

	    // Input
	    T tMin;
	    T tMax;
	    T dt;

	    // tools
	    T t;
	    bool isCroisssantPhase;

	};
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
