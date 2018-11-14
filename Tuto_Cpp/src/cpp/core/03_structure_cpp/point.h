#pragma once

#include <iostream>

#include "../03_structure_cpp/double2.h"

using std::string;

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/**
 * structure moderne c++
 */
struct point
    {

	/*--------------------------------------*\
	|*		Constructor		*|
	 \*-------------------------------------*/

    public:

	/**
	 * constructeur principal
	 */
	point(double2 position, string label)
	    {
	    this->position = position;
	    this->label = label;
	    }

	/**
	 * call constructeur principal
	 */
	point(double x, double y, string label) :
		point(double2(x, x), label)
	    {
	    // rien de plus
	    }

	/**
	 * call constructeur ci-dessus
	 */
	point() :
		point(0, 0, "")
	    {
	    // rien de plus
	    }

	/*--------------------------------------*\
	|*		attribut		*|
	 \*-------------------------------------*/

    public:

	double2 position;
	string label;
    };

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
