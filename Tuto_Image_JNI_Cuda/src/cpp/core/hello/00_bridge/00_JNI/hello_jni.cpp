#include <jni.h>
#include "hello_registry.h"


/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/


/**
 * see doc projet Tuto_Canvas_JNI
 */

/*-------------------------------------*\
 |*	Creation canvasNatif	       *|
 \*------------------------------------*/

/**
 * return :	canvasNatifID
 */
extern "C"
JNIEXPORT jint JNICALL Java_org_bilat_tuto_image_jni_natif_Native_createImage(JNIEnv* ptrEnv,jclass jclasse,jint w,jint h,jint dt, jint type)
    {
    return createImageHello(w,h,dt, type);
    }

/*-------------------------------------*\
 |*  canvasNatifID(Scenario) Dependant    *|
 \*------------------------------------*/

// setDt
extern "C"
JNIEXPORT void JNICALL Java_org_bilat_tuto_image_jni_natif_Native_setDt(JNIEnv *ptrEnv,jobject jcanva,jint panelID,jint dt)
    {
    setDt(panelID,dt);
    }

extern "C"
JNIEXPORT void JNICALL Java_org_bilat_tuto_image_jni_natif_Native_setNMinNMax(JNIEnv *ptrEnv,jobject jcanva,jint panelID,jint nMin, jint nMax)
    {
    setNMinNMax(panelID, nMin, nMax);
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

