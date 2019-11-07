
package org.bilat.tuto.image.jni;

import org.bilat.tuto.image.jni.gui.JFrameMain;

/**
 * Linux
 *
 * 		x86:	cbirt java -Xmx2048m -Xms1024m  -classpath .:./*:../API_Bilat_Canvas_JNI/JAR/*:./bin -Djava.library.path=../API_Bilat_Canvas_JNI/BIN/gcc:../RELEASE/bin     com.bilat.tuto.image.jni.hello.UseHello
 * 		arm:	cbirt java -Xmx2048m -Xms1024m  -classpath .:./*:../API_Bilat_Canvas_JNI/JAR/*:./bin -Djava.library.path=../API_Bilat_Canvas_JNI/BIN/gcc_arm:../RELEASE/bin com.bilat.tuto.image.jni.hello.UseHello
 *
 * Linux (RemoteDesktop)
 *
 * 		Idem ci-dessus, mais prefixe by gl
 *
 * 			gl cbirt ...
 *
 * Hyp:
 * 		(H1)	.so du .jar dans folder courant,ie
 *
 *				Canvas:
 *
 * 					x86		../API_Bilat_Canvas_JNI/BIN/gcc
 * 					arm		../API_Bilat_Canvas_JNI/BIN/gcc_arm
 *
 * 				Image:
 *
 * 					x86		../API_Bilat_Image_JNI/BIN/gcc
 * 							../API_Bilat_Image_JNI_Cuda/BIN/gcc
 *
 * 					arm		../API_Bilat_Image_JNI/BIN/gcc_arm
 * 							../API_Bilat_Image_JNI_Cuda/BIN/gcc_arm
 *
  * 			Projet specific:
 *
 * 						Le path de votre shared_lib, par exemple
 *
 * 							../RELEASE/bin
 *
 *		(H2)	.jar dans classpath, ie
 *
 *				Canvas:
 *
 *					../API_Bilat_Canvas_JNI/JAR/*
 *
 *				Image:
 *
 *					../API_Bilat_Image_JNI/JAR/*
 *
 * 				Projet specific:
 *
 *					classe de votre project
 *
 * Note:
 *
 * 		Tuner memoire selon vos besoin
 */
public class UseImageGL
	{

	/*------------------------------------------------------------------*\
	|*							Methodes Public							*|
	\*------------------------------------------------------------------*/

	/**
	 * <pre>
	 * Utilise code natif en cuda, sauf si
	 *
	 * 		-DOMP=true
	 *
	 * Selon cette propriete system, le .so charge ne sera pas le meme.
	 * See classe LoaderLibrary de ce projet
	 * </pre>
	 */
	public static void main(String[] args)
		{
		//main();
		//main2Images();
		main3Images();
		}

	/*------------------------------------------------------------------*\
	|*							Methodes Private						*|
	\*------------------------------------------------------------------*/


	private static void main()
		{
		int w = 1000;
		int h = 800;
		new JFrameMain(w, h);
		}

	private static void main2Images()
		{
		int w = 1000;
		int h = 800;
		new JFrameMain(w, h, 2);
		}

	private static void main3Images()
		{
		int w = 1000;
		int h = 800;
		new JFrameMain(w, h, 3);
		}

	}
