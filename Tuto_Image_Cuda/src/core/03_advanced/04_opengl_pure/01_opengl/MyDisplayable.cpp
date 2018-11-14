#include "MyDisplayable.h"

#include <iostream>
#include <GL/glew.h>

using std::cout;
using std::endl;

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

/*----------------------*\
|*	Constructeur	*|
 \*---------------------*/

MyDisplayable::MyDisplayable() :
	variateur(Interval<float>(0, 1), 0.01)
    {
    // rien
    }

MyDisplayable::~MyDisplayable()
    {
    // rien
    }

/*----------------------*\
|*	Methodes	*|
 \*---------------------*/

/*-----------*\
|* Override  *|
 \*----------*/

/**
 * Override
 */
void MyDisplayable::reshape(Panel_A &panel, int w, int h)
    {
    glViewport(0, 0, w, h);

    //Projection
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity();
    double fovy = 45;
    if (h <= 0)
	{
	h = 1;
	}
    double ratio = w / h;

    gluPerspective(fovy, ratio, 1, 10);

    //Camera
    glMatrixMode (GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0, 0, 3, 0, 0, 0, 0, 1, 0);
    }

/**
 * Override
 *
 * Animation:
 * 	Pour une animation, en fenetrage glut, il faut deriver de
 *
 * 		GLUTWindow
 *
 * 	Puis red�finir IdlFunc, et faire un repaint dedans
 */
void MyDisplayable::display(Panel_A &panel)
    {
    glEnable (GL_DEPTH_TEST);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glPushMatrix();

    drawScene3D();

    glPopMatrix();
    glFinish();
    }

/**
 * Override
 */
void MyDisplayable::init(Panel_A &panel)
    {
    // Create OpenGL resources here (Textures,VBO,PBO,Shaders...)
    }

/**
 * Override
 */
void MyDisplayable::release(Panel_A &panel)
    {
    //Freen OpenGL resources here!
    }

/**
 * Override
 */
void MyDisplayable::animationStep(Panel_A &panel, bool &isNeedUpdate)
    {
    isNeedUpdate = true;

    py = variateur.varierAndGet();

    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

void MyDisplayable::drawScene3D()
    {
    glBegin (GL_TRIANGLES);

    glColor3f(1, 0, 0);
    glVertex3f(-1, -1, 0);
    glColor3f(0, 1, 0);
    glVertex3f(1, -1, 0);
    glColor3f(0, 0, 1);
    glVertex3f(0, py, 0);

    glEnd();
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

