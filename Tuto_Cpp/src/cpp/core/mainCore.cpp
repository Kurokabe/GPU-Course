#include <stdlib.h>
#include <iostream>

using std::cout;
using std::endl;

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Imported	 	*|
 \*-------------------------------------*/

extern void useHello();
extern void useDerivate();
extern void useStructure();
extern void useDestruction();
extern void usePolymorphisme();
extern void useTemplate();
extern void useSurchargeCout();
extern void useSurchargeAdd();
extern void useSurchargeCrochet();
extern void usePassage();
extern void useAllocation();
extern void useAdvancedSimple();
extern void useAdvanced();

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

int mainCore();

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

int mainCore()
    {
    useHello();
    useDerivate();
    useStructure();
    useDestruction();
    usePolymorphisme();
    useTemplate();
    useSurchargeCout();
    useSurchargeAdd();
    useSurchargeCrochet();
    usePassage();
    useAllocation();
    useAdvancedSimple();
    useAdvanced();

    cout<<"\nend"<<endl;

    return EXIT_SUCCESS;
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

