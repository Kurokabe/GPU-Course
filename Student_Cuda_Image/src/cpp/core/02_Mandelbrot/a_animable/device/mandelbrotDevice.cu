#include "Indice2D.h"
#include "cudaTools.h"
#include "Device.h"

#include "MandelbrotMath.h"

#include "DomaineMath_GPU.h"
#include "IndiceTools_GPU.h"
using namespace gpu;

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public		 	*|
 \*-------------------------------------*/

__global__ void mandelbrot(uchar4* ptrDevPixels, uint w, uint h, DomaineMath domaineMath, int n);

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

__global__ void mandelbrot(uchar4* ptrDevPixels, uint w, uint h, DomaineMath domaineMath, int n)
    {
    MandelbrotMath mandelbrotMath; // warning syntaxe juste !
    //MandelbrotMath mandelbrotMath();// warning syntaxe fausse !

    // TODO Mandelbrot GPU :
    // entrelacement
    // s -> (i,j) -> (x,y)
    // appeler colorXY

    // Choix a faire:
    //		- Travailler en float pour plus de performance?
    //		- Travailler en double pour pouvoir zoomer plus loin dans le fractale?
    // 		Note : domaineMath.toXY travaille lui toujours en double pour vous permettre les deux possibilites ci-dessus
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

