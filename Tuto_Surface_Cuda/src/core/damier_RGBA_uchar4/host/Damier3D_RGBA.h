#pragma once

#include "Grid.h"
#include "SurfaceStrip_GPU.h"
#include "Variateur_CPU.h"
#include "DomainMath3D_GPU.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

/**
 * Concept:
 *
 * 	La couleur d'une surface est defini par
 * 		- nombre de cannaux couleurs
 * 		- type des cannaux couleurs
 *
 *      Dans cet api, on peut choisir ces deux propri�t�s
 *      	- #cannaux couleurs
 *      	- #type des cannaux
 *
 * Type pr�d�finis:
 *
 * 		SurfaceStrip_RGBA_uchar4
 * 		SurfaceStrip_RGB_uchar3
 *
 *		SurfaceStrip_RGBA_float4
 * 		SurfaceStrip_RGB_float3
 *
 * 		SurfaceStrip_HSBA_float4
 * 		SurfaceStrip_HSB_float3
 * 		SurfaceStrip_HA_float2
 * 		SurfaceStrip_HUE_float
 *
 * Contraintes:
 *
 * 		Le choix du type des cannaux couleurs influence le type de l'image apparaissant dans la methode fillVertex.
 * 		Il faut etre coherent! En cas de mauvais matching, une erreur de compilation surviendra (attention elle est pas forcement tr�s explicite).
 *
 * 		Exemples:
 *
 * 			SurfaceStrip_RGBA_float4	virtual void fillImage(float4* ptrTabColors,...)
 * 			SurfaceStrip_RGB_uchar3		virtual void fillImage(uchar3* ptrTabColors,...) // ou unsigned char si uchar non disponible
 * 			SurfaceStrip_HUE_float		virtual void fillImage(float* ptrTabColors,...)
 *
 * Types predefinis naturel:
 *
 * 	SurfaceStrip_RGBA_uchar4
 * 	SurfaceStrip_HSBA_float4
 * 	SurfaceStrip_HUE_float
 *
 * 	Les versions a 3 cannaux (uchar3 et float3) ne sont a priori pas super en terme de performance en cuda pour l'utilisation du tiling en sm.
 *
 *
 * Notes:
 *
 * 	(N1)	Implementation:
 * 			Les types prededinis se trouve dans
 * 				- SurfaceStrip_CPU.h
 * 				- SurfaceStrip_GPU.h
 *
 * 	(N2)	Extension:
 * 			On pourrait ajouter d'autres types predefinis!
 *
 */
class Damier3D_RGBA: public gpu::SurfaceStrip_RGBA_uchar4
    {
	/*--------------------------------------*\
	|*		Constructor		*|
	 \*-------------------------------------*/

    public:

	Damier3D_RGBA(const Grid& grid, int w, int h, const gpu::DomainMath3D& domaineMath,float dt, int n);

	virtual ~Damier3D_RGBA(void);

	/*--------------------------------------*\
	 |*		Methodes		*|
	 \*-------------------------------------*/

    public:

	/*-------------------------*\
	|*   Override Surface   *|
	 \*------------------------*/

	/**
	 * Call periodicly by the api
	 */
	virtual void fillVertex(float3* ptrDevVerticesXYZ, uchar4* ptrDevVerticesColor, unsigned int w, unsigned int h, const gpu::DomainMath3D& domaineMath);

	/**
	 * Call periodicly by the api
	 */
	virtual void animationStep(bool& isNeedUpdate);

	/**
	 * Call periodicly by the api
	 */
	virtual void paintPrimitives(Graphic2D& graphic2D);

	/*--------------------------------------*\
	 |*		Attributs		*|
	 \*-------------------------------------*/

    private:

	// Inputs
	int n;
	dim3 dg;
	dim3 db;

	// Tools
	string title;
	float t; // para animation
	cpu::Variateur<float> variateurAnimation; // varier t
    };

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
