
package org.bilat.tuto.image.jni.natif;

import com.bilat.canvas.jni.tools.LibraryLoader;
import com.bilat.image.jni.ui.CanvasImageNative;

public class Native
	{

	/*------------------------------*\
	|*			  Animation			*|
	\*------------------------------*/

	/**
	 * <pre>
	 * Warning:
	 *
	 * 		(W1)	Le thread d'animation se trouve cote java
	 * 				Celui-ci appelle rapaint du Canvas
	 *
	 * 		(W2)	Le repaint du canvas appelle le display opengl Natif
	 *
	 * 		(W3)	Le thread d'animation est le meme pour toutes les canvas si il y en a plusieurs!
	 *
	 * 		(W4)	Un sleep  trop petit (ci-dessous) n'apporte pas forcement de performance,
	 * 				au contraire le thread d'animation pourrait meme bourrer inutilement le awt-queue-event de repaint
	 * 				qui ne seront pas forcement tous honorer. On ne pas aller plus vite que la music.
	 * 				Il faut attendre que le display natif soit fini, ie un ancien repaint soit fini, avant que le systeme n'en lance un nouveau.
	 *
	 * 				A tuner en fonction de la vitesse de traitement du display natif.
	 * </pre>
	 */
	static
		{
		LibraryLoader.loadSmart();
		//System.loadLibrary("Tuto_Image_JNI_Cuda_cuda_101_x86_64");

		CanvasImageNative.setAnimationSleepDelayMS(1); // pour toute les fenetres le meme,see warning ci-dessus
		}

	/*------------------------------------------------------------------*\
	|*							Methodes Native							*|
	\*------------------------------------------------------------------*/

	/*------------------------------*\
	|*			Creation			*|
	\*------------------------------*/

	/**
	 * return canvasNativeID
	 */
	public static native int createImage(int w, int h, int dt, int type);

	/*------------------------------*\
	|*	Depend from canvasNativeID	*|
	\*------------------------------*/

	public static native void setDt(int canvasNativeID, int dt);


	public static native void setNMinNMax(int canvasNativeID, int nMin, int nMax);

	}
