
package org.bilat.tuto.image.jni.gui;

import java.awt.BorderLayout;
import java.util.List;

import javax.swing.JFrame;
import javax.swing.UIManager;
import javax.swing.WindowConstants;

import org.bilat.tuto.image.jni.gui.atome.CanvasImage;
import org.bilat.tuto.image.jni.gui.atome.JPanelImage;

import com.bilat.canvas.jni.ui.CanvasNativeListener_I;

public class JFrameMain extends JFrame
	{

	/*------------------------------------------------------------------*\
	|*							Constructeurs							*|
	\*------------------------------------------------------------------*/

	public JFrameMain(int w, int h)
		{
		this(w, h, 1);
		}

	public JFrameMain(int w, int h, int nbrImage)
		{
		this.w = w;
		this.h = h;
		this.nbrImage = nbrImage;

		geometry();
		controle();
		apparence();
		}

	/*------------------------------------------------------------------*\
	|*							Methodes Public							*|
	\*------------------------------------------------------------------*/

	/*------------------------------------------------------------------*\
	|*							Methodes Private						*|
	\*------------------------------------------------------------------*/

	private void geometry()
		{
		panelImage = new JPanelImage(w, h, nbrImage);

		setLayout(new BorderLayout());
		add(panelImage, BorderLayout.CENTER);
		}

	private void apparence()
		{

		try {
		UIManager.setLookAndFeel("javax.swing.plaf.nimbus.NimbusLookAndFeel");
		}
		catch(Exception e)
			{
			e.printStackTrace();
			}
		setTitle(TITLE);
		setSize(w, h);
		setLocationRelativeTo(null);

		setVisible(true);
		}

	private void controle()
		{
		setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);

		//Facultatitif,Example
			{
			final List<CanvasImage> canvasImages = panelImage.getCanvasImages();
			for(CanvasImage canvasImage : canvasImages)
				{
					canvasImage.addCanvasNativeListener(new CanvasNativeListener_I()
					{

					@Override
					public void onPaintPerformed()
						{
						int fps = canvasImage.getFPS();
						StringBuilder str = new StringBuilder();
						str.append(TITLE);
						str.append(AT);
						str.append(fps);
						str.append(FPS);
						str.append(sizeCanvasGL(canvasImage));
						str.append(SPACE);
						str.append(sizeImage(canvasImage));
						String title = str.toString();

						setTitle(title);
						}
					});
				}

			}
		}

	private String sizeCanvasGL(final CanvasImage canvasImage)
		{
		StringBuilder str = new StringBuilder();
		str.append("Pannel(");
		str.append(canvasImage.getWidth());
		str.append(" x ");
		str.append(canvasImage.getHeight());
		str.append(")");

		return str.toString();
		}

	private String sizeImage(final CanvasImage canvasImage)
		{
		StringBuilder str = new StringBuilder();
		str.append("Image(");
		str.append(canvasImage.getImageWidth());
		str.append(" x ");
		str.append(canvasImage.getImageHeight());
		str.append(")");

		return str.toString();
		}

	/*------------------------------------------------------------------*\
	|*							Attributs Private						*|
	\*------------------------------------------------------------------*/

	//Inputs
	private int w;
	private int h;
	private int nbrImage;

	// Tools
	private JPanelImage panelImage;

	/*------------------------------*\
	|*			  Static			*|
	\*------------------------------*/

	private static final String TITLE = "Java GUI with Native Canvas using OpenGL";
	private static final String AT = " @ ";
	private static final String FPS = "fps : ";
	private static final String SPACE = " ";

	}