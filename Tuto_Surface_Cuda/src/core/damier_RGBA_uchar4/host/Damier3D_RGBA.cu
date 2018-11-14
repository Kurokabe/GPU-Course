#include "Damier3D_RGBA.h"

#include <assert.h>

#include "Device.h"
#include "MathTools.h"
#include "StringTools.h"
#include "cudaTools.h"

using gpu::DomainMath3D;
using gpu::SurfaceStrip_RGBA_uchar4;

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Imported	 	*|
 \*-------------------------------------*/

extern __global__ void damier3DCuda(float3* ptrDevVerticesCoord, uchar4* ptrDevVerticesColor, int w, int h, DomainMath3D domaineMath, int n, float t);

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

/*-------------------------*\
 |*	Constructeur	    *|
 \*-------------------------*/

Damier3D_RGBA::Damier3D_RGBA(const Grid& grid, int w, int h, const DomainMath3D& domaineMath, float dt, int n) :
	SurfaceStrip_RGBA_uchar4(w,h,domaineMath ), variateurAnimation(cpu::Interval<float>(0, 2 * PI), dt)
    {
    // Inputs
    this->n = n;
    this->dg = grid.dg;
    this->db = grid.db;

    // Tools
    this->title = "Damier3D_RGBA_uchar4";
    this->t = 0;
    }

Damier3D_RGBA::~Damier3D_RGBA()
    {
    // rien
    }

/*-------------------------*\
 |*	Surcharge	   *|
 \*------------------------*/

/**
 * Override
 * Call periodicly by the api
 */
void Damier3D_RGBA::fillVertex(float3* ptrDevVerticesCoord, uchar4* ptrDevVerticesColor, unsigned int w, unsigned int h, const gpu::DomainMath3D& domaineMath)
    {
    damier3DCuda<<<dg,db>>>(ptrDevVerticesCoord,ptrDevVerticesColor,w,h,domaineMath,n,t);
    }

/**
 * Override
 * Call periodicly by the api
 */
void Damier3D_RGBA::animationStep(bool& isNeedUpdate)
    {
    this->t = variateurAnimation.varierAndGet(); // in [0,2pi]
    }

/**
 * Override
 * Call periodicly by the api
 */
void Damier3D_RGBA::paintPrimitives(Graphic2D& graphic2D)
    {
    graphic2D.setFont(TIMES_ROMAN_24);

    float r = 0.5f;
    float g = 0.5f;
    float b = 0.5f;

    graphic2D.setColorRGB(r, g, b);

    // TOP : Para Animation
	{
	string message = "t = " + StringTools::toString(t);
	graphic2D.drawTitleTop(message);
	}

    // BOTTOM : Title
	{
	graphic2D.drawTitleBottom(title);
	}
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

