#include <iostream>
#include <stdlib.h>

#include "Settings_CPU.h"
using namespace cpu;

using std::cout;
using std::endl;

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Imported	 	*|
 \*-------------------------------------*/

extern int mainImage(Settings& settings);
extern int mainAnimable(Settings& settings);

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

static int use(Settings& settings);

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

int main(int argc, char** argv)
    {
    LaunchMode launchMode = LaunchMode::IMAGE; // IMAGE ANIMABLE
    Settings settings(launchMode, argc, argv);

    return use(settings);
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

int use(Settings& settings)
    {
    switch (settings.getLaunchMode())
	{
	case IMAGE:
	    return mainImage(settings); // Bloquant, Tant qu'une fenetre est ouverte
	case ANIMABLE:
	    return mainAnimable(settings); // FreeGL
	default:
	    return mainImage(settings); // Bloquant, Tant qu'une fenetre est ouverte
	}
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

