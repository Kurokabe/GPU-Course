#pragma once

#include <iostream>
#include "cudaTools.h"
#include "MathTools.h"

#include "CVCaptureVideo.h"

#include "Animable_I_GPU.h"
using namespace gpu;

using cv::Mat;
using std::string;

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class ImageVideo: public Animable_I<uchar4>
    {
	/*--------------------------------------*\
	|*		Constructor		*|
	 \*-------------------------------------*/

    public:

	ImageVideo(const Grid& grid, uint w, uint h,  string nameVideo);
	virtual ~ImageVideo(void);

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

	/*--------------------------------------*\
	 |*		Attributs		*|
	 \*-------------------------------------*/

    private:

	// Inputs
	string nameVideo;

	// Tools
	size_t sizeImage;
	CVCaptureVideo capture;
	Mat matRGBA;
	uchar4* ptrTabPixelVideo;

    };

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
