#pragma once

#include "MouseListener_I.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class SimpleMouseListener: public MouseListener_I
    {
    public:
	/*--------------------------------------*\
	|*		Constructor		*|
	 \*-------------------------------------*/

	SimpleMouseListener();
	virtual ~SimpleMouseListener();



	/*--------------------------------------*\
	 |*		Methodes		*|
	 \*-------------------------------------*/

    public:

	/**
	 * Override
	 */
	virtual void onMouseMoved(const MouseEvent& event);

	/**
	 * Override
	 */
	virtual void onMousePressed(const MouseEvent& event);

	/**
	 * Override
	 */
	virtual void onMouseReleased(const MouseEvent& event);

	/**
	 * Override
	 */
	virtual void onMouseWheel(const MouseWheelEvent& event);

    private:

	void printXY(const MouseEvent& event);

	/*--------------------------------------*\
	 |*		Attributs		*|
	 \*-------------------------------------*/

    private:

    };

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
