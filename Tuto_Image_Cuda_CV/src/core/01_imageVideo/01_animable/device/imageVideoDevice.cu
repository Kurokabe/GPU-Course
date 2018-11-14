#include "Indice2D.h"
#include "cudaTools.h"
#include "Device.h"

#include "ImageVideoMath.h"

#include "IndiceTools_GPU.h"
using namespace gpu;

// Attention : 	Choix du nom est impotant!
//		VagueDevice.cu et non Vague.cu
// 		Dans ce dernier cas, problème de linkage, car le nom du .cu est le meme que le nom d'un .cpp (host)
//		On a donc ajouter Device (ou n'importequoi) pour que les noms soient différents!

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Imported	 	*|
 \*-------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

__global__ void toGray(uchar4* ptrDevPixels,uint w, uint h,float t);

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

__global__ void toGray(uchar4* ptrDevPixels, uint w, uint h, float t)
    {
    ImageVideoMath math = ImageVideoMath(w, h);

    const int TID = Indice2D::tid();
    const int NB_THREAD = Indice2D::nbThread();
    const int WH=w*h;

    int pixelI;	// in [0,h[
    int pixelJ; // in [0,w[

    int s = TID;
    while (s < WH)
	{
	IndiceTools::toIJ(s, w, &pixelI, &pixelJ); 	// update (pixelI, pixelJ)

	math.colorIJ(&ptrDevPixels[s],pixelI, pixelJ, t); 	//update color  // ici pas besoin de i, j,t, optimisation possible

	s += NB_THREAD;
	}
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/


/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

