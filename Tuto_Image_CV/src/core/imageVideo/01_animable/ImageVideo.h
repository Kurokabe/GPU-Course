#pragma once

#include "CVCaptureVideo.h"

#include "cudaType_CPU.h"
#include "Animable_I_CPU.h"
using namespace cpu;
using cv::Mat;

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class ImageVideo: public Animable_I<uchar4>
    {

	/*--------------------------------------*\
	 |*		Constructeur		*|
	 \*-------------------------------------*/

    public:

	ImageVideo(uint w, uint h,string nameVideo);

	virtual ~ImageVideo(void);

	/*--------------------------------------*\
	 |*		Methode			*|
	 \*-------------------------------------*/

    public:

	/*-------------------------*\
	|*   Override Animable_I   *|
	 \*------------------------*/


	/**
	 * Call periodicly by the api
	 * Image non zoomable : domaineMath pas use ici
	 */
	virtual void processEntrelacementOMP(uchar4* ptrTabPixels, uint w, uint h, const DomaineMath& domaineMath);

	/**
	 * Call periodicly by the api
	 * Image non zoomable : domaineMath pas use ici
	 */
	virtual void processForAutoOMP(uchar4* ptrTabPixels, uint w, uint h, const DomaineMath& domaineMath);

	/**
	 * Call periodicly by the api
	 */
	virtual void animationStep();

	/*--------------------------------------*\
	|*		Attribut		*|
	 \*-------------------------------------*/

    private:

	// Inputs
	string nameVideo;

	// Tools
	CVCaptureVideo capture;
	Mat matRGBA;
	uchar4* ptrTabPixelVideo;

	size_t sizeImage;

    };

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 /*----------------------------------------------------------------------*/
