#include "DomaineKeyListener.h"

#include <iostream>

#include "MathTools.h"

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

DomaineKeyListener::DomaineKeyListener(Image_RGBA_uchar4* ptrImage) :
	domaine1(PI / 2, PI / 2, 2 * PI, 2 * PI)
    {
    this->ptrImage = ptrImage;
    }

DomaineKeyListener::~DomaineKeyListener()
    {
    //rien
    }

/*-----------------------*\
|*	Methode  	*|
 \*----------------------*/

/**
 * Override
 */
void DomaineKeyListener::onKeyPressed(const KeyEvent &event)
    {
    //rien
    }

/**
 * Override
 */
void DomaineKeyListener::onKeyReleased(const KeyEvent &event)
    {
    // Les domaines sont stocker dans une pile
      // goToDomaineInit pop tout jsuqu'à atteindre le premier element
      // goToPreviousDomaine pop le dernier élment
      // une pile est employer, pas un mememto
      cout<<"\n[DomaineKeyListener] : onKeyReleased : "<<event.getKey()<<endl;

      switch (event.getKey())
  	{
  	case '1' :
  	    ptrImage->goToDomaineInit();
  	    break;
  	case '2':
  	    ptrImage->goToPreviousDomaine();
  	    break;
  	case '3':
  	    ptrImage->setCurrentDomaine(domaine1);
  	    break;
  	}

      DomaineMath currentDomaine=ptrImage->getCurrentDomaine();
      cout << "[DomaineKeyListener] : Current Domaine is : \n"<< currentDomaine<<endl;
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

