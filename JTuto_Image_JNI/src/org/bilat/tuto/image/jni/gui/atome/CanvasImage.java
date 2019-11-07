
package org.bilat.tuto.image.jni.gui.atome;

import org.bilat.tuto.image.jni.natif.Native;

import com.bilat.image.jni.ui.CanvasImageNative;

public class CanvasImage extends CanvasImageNative
	{



	/*------------------------------------------------------------------*\
	|*							Constructeurs							*|
	\*------------------------------------------------------------------*/

	public CanvasImage(int w, int h, int dt, int type)
		{
		super(Native.createImage(w, h, dt, type));

		System.out.println("[java] canvasNativeID = " + this.getNativeID());

		control();
		geometry();
		apparence();
		}

	/*------------------------------------------------------------------*\
	|*							Methodes Public							*|
	\*------------------------------------------------------------------*/

	/*------------------------------*\
	|*				Set				*|
	\*------------------------------*/

	public void setDt(int dt)
		{
		Native.setDt(getNativeID(), dt);

		repaint();
		}

	public void setNMinNMax(int nMin, int nMax)
		{
		Native.setNMinNMax(getNativeID(), nMin, nMax);

		repaint();
		}

	/*------------------------------------------------------------------*\
	|*							Methodes Private						*|
	\*------------------------------------------------------------------*/

	private void apparence()
		{
		// rien
		}

	private void geometry()
		{
		// rien
		}

	private void control()
		{
		// rien
		}

	/*------------------------------------------------------------------*\
	|*							Attributs Private						*|
	\*------------------------------------------------------------------*/
	}
