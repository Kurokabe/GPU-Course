#include "ImageVideo.h"
#include "ImageVideoMath.h"

#include <iostream>
#include <stdlib.h>
#include <assert.h>
#include <omp.h>
#include "OmpTools.h"

#include "IndiceTools_CPU.h"
#include "OpencvTools_CPU.h"
using cpu::IndiceTools;

using std::cout;
using std::endl;
using std::cerr;
using cv::Mat;

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

ImageVideo::ImageVideo(uint w, uint h, string nameVideo) :
	Animable_I<uchar4>(w, h, "ImageVideo_OMP_rgba_uchar4"), nameVideo(nameVideo), capture(nameVideo), matRGBA(h, w, CV_8UC1)
    {
    // Tools
    this->t = 0;					// protected dans super classe Animable
    this->parallelPatern = ParallelPatern::OMP_MIXTE;   // protected dans super classe Animable
    this->sizeImage = sizeof(uchar4) * w * h;

    //video
	{
	bool isOk = capture.start();
	if (!isOk)
	    {
	    cerr << "[ImageVideo] : failed to open : " << nameVideo << endl;
	    exit (EXIT_FAILURE);
	    }
	assert(capture.getW() == w && capture.getH() == h);
	animationStep(); // pour forcer la premiere capture et remplissage ptrTabPixelVideo
	}
    }

ImageVideo::~ImageVideo(void)
    {
    // rien
    }

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

/**
 * Override
 */
void ImageVideo::animationStep()
    {
    t++;

    //video
	{
	Mat matBGR = capture.provideBGR();

	OpencvTools_CPU::switchRB(this->matRGBA, matBGR);
	this->ptrTabPixelVideo = OpencvTools_CPU::castToUchar4(matRGBA);
	}
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/**
 * Override (code naturel omp)
 * Image non zoomable : domaineMath pas use ici
 */
void ImageVideo::processForAutoOMP(uchar4* ptrTabPixels, uint w, uint h, const DomaineMath& domaineMath)
    {
    memcpy(ptrTabPixels, this->ptrTabPixelVideo, sizeImage);

// to gray (sur place)
	{
	ImageVideoMath math(w, h); // ici pour preparer cuda

#pragma omp parallel for
	for (int i = 0; i < h; i++)
	    {
	    for (int j = 0; j < w; j++)
		{
		// int s = i * W + j;
		int s = IndiceTools::toS(w, i, j);    // i[0,H[ j[0,W[  --> s[0,W*H[

		math.colorIJ(&ptrTabPixels[s], i, j, t);
		}
	    }
	}

    // Optimisation:
    //	enlever memcopy
    //	passer en NB pendant une copie manuelle
    //	On laisse comme ca pour passer a cuda facilement
    }

/**
 * Override (code entrainement cuda)
 * Image non zoomable : domaineMath pas use ici
 */
void ImageVideo::processEntrelacementOMP(uchar4* ptrTabPixels, uint w, uint h, const DomaineMath& domaineMath)
    {
    memcpy(ptrTabPixels, this->ptrTabPixelVideo, sizeImage);

    // to gray (sur place)
	{
	ImageVideoMath math(w, h); // ici pour preparer cuda

	const int WH = w * h;

#pragma omp parallel
	    {
	    const int NB_THREAD = OmpTools::getNbThread(); // dans region parallel

	    const int TID = OmpTools::getTid();
	    int s = TID; // in [0,...

	    int i;
	    int j;
	    while (s < WH)
		{
		IndiceTools::toIJ(s, w, &i, &j); // s[0,W*H[ --> i[0,H[ j[0,W[

		math.colorIJ(&ptrTabPixels[s], i, j, t); // ici pas besoin de i, j (et t) optimisation possible

		s += NB_THREAD;
		}
	    }
	}

    // Optimisation:
    //	enlever memcopy
    //	passer en NB pendant une copie manuelle
    //	On laisse comme ca pour passer a cuda facilement
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

