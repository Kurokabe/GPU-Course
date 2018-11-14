#include <iostream>
#include <stdlib.h>

using std::cout;
using std::endl;

/**
 * More info at : http://www.cplusplus.com/reference/multithreading/
 */

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Imported	 	*|
 \*-------------------------------------*/

extern void helloStdThread_Procedure(void);
extern void helloStdThread_ProcedureArgs(void);
extern void helloStdThread_Objet(void);
extern void helloStdThread_Methode(void);

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

bool useStdThread(void);

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

bool useStdThread(void)
    {
    cout<<endl<<"[Use Std Thread] : "<<endl;

    helloStdThread_Procedure();
    helloStdThread_ProcedureArgs();
    helloStdThread_Objet();
    helloStdThread_Methode();

    return true;
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

