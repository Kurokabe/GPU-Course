#pragma once

#include "cudaTools.h"
#include "Animable_I_GPU.h"

#include "Sphere.h"
#include "memoryType.h"
using namespace gpu;

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class Raytracing : public Animable_I<uchar4>
    {
	/*--------------------------------------*\
	|*		Constructor		*|
	 \*-------------------------------------*/

    public:

	Raytracing(const Grid& grid,uint w, uint h, float dt,int nbSpheres,const MemoryType& memoryType);
	virtual ~Raytracing(void);

	/*--------------------------------------*\
	 |*		Methodes		*|
	 \*-------------------------------------*/

    public:

	/*-------------------------*\
	|*   Override Animable_I   *|
	 \*------------------------*/

	/**
	 * Call periodicly by the api
	 */
	virtual void process(uchar4* ptrDevPixels, uint w, uint h, const DomaineMath& domaineMath);

	/**
	 * Call periodicly by the api
	 */
	virtual void animationStep();

    private:

	/*--------------------------------------*\
	 |*		Attributs		*|
	 \*-------------------------------------*/

	void uploadToDevice(Sphere* ptrTabSpheres);

    private:

	// Inputs
	int nbSpheres;
	float dt; // animation

	// Tools
	size_t sizeSpheres;
	Sphere* ptrDevTabSpheres;
	MemoryType memoryType;
    };


/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
