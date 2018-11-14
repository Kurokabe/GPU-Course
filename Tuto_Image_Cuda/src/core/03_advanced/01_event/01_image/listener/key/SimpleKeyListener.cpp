#include "../../../../../../core/03_advanced/01_event/01_image/listener/key/SimpleKeyListener.h"

#include <iostream>


using std::cout;
using std::endl;

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

/*-----------------------*\
|*	Constructor  	*|
 \*----------------------*/

SimpleKeyListener::SimpleKeyListener()
    {
    //rien
    }

SimpleKeyListener::~SimpleKeyListener()
    {
    //rien
    }

/*-----------------------*\
|*	Methode  	*|
 \*----------------------*/

void SimpleKeyListener::onKeyPressed(const KeyEvent &event)
    {
    if (event.isSpecial())
	{
	cout << "Special Key Pressed " << event.getSpecialKey() << endl;
	}
    else
	{
	cout << "KeyPressed = " << event.getKey() << endl;
	}

    }

void SimpleKeyListener::onKeyReleased(const KeyEvent& event)
    {
    if (event.isSpecial())
   	{
   	cout << "Special Key Released " << event.getSpecialKey() << endl;
   	}
       else
   	{
   	cout << "KeyReleased = " << event.getKey() << endl;
   	}
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

