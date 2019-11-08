
package org.bilat.tuto.image.jni.gui.atome;

import java.awt.BorderLayout;
import java.util.ArrayList;
import java.util.List;

import javax.swing.BoxLayout;
import javax.swing.JPanel;

public class JPanelImage extends JPanel
	{

	/*------------------------------------------------------------------*\
	|*							Constructeurs							*|
	\*------------------------------------------------------------------*/

	public JPanelImage(int w, int h, int nbrImage)
		{
		this.w = w;
		this.h = h;
		this.nbrImage = nbrImage;
		canvasImages = new ArrayList<>();

		geometry();
		controle();
		apparance();
		}

	/*------------------------------------------------------------------*\
	|*							Methodes Public							*|
	\*------------------------------------------------------------------*/

	/*------------------------------*\
	|*				Get				*|
	\*------------------------------*/

	public List<CanvasImage> getCanvasImages()
		{
		return this.canvasImages;
		}

	public int getW()
		{
		return this.w;
		}

	public int getH()
		{
		return this.h;
		}

	/*------------------------------------------------------------------*\
	|*							Methodes Private						*|
	\*------------------------------------------------------------------*/

	private void geometry()
		{
		bilatImageAPI();

		swingPure();
		}

	private void bilatImageAPI()
		{
		int dt = JPanelControle.DT_START;
			for (int i = 0; i < nbrImage; i++)
				{
				canvasImages.add(new CanvasImage(w, h, dt, i));
				}
		}

	private void swingPure()
		{
		panelControle = new JPanelControle(canvasImages);

		setLayout(new BorderLayout());

		JPanel imagePane = new JPanel();
		imagePane.setLayout(new BoxLayout(imagePane, BoxLayout.LINE_AXIS));

		/*switch(nbrImage)
		{
		case 1 :
			//imagePane.add(canvasImages.get(0));

			add(canvasImages.get(0), BorderLayout.CENTER);
			break;
		case 2:
			JSplitPane split = new JSplitPane(SwingConstants.VERTICAL, canvasImages.get(0), canvasImages.get(1));
			//imagePane.add(split);

			add(split, BorderLayout.CENTER);
			break;
		case 3:
		// Doesn't work
			JSplitPane split1 = new JSplitPane(SwingConstants.VERTICAL, canvasImages.get(0), canvasImages.get(1));
			JSplitPane split2 = new JSplitPane(SwingConstants.VERTICAL, split1, canvasImages.get(2));


			canvasImages.get(0).setMinimumSize(new Dimension(w/3, h));
			split1.setMinimumSize(new Dimension(w/3, h));
			//imagePane.add(split2);

			add(split2, BorderLayout.CENTER);
			break;
		}*/

		for(CanvasImage canvasImage : canvasImages)
			{
			imagePane.add(canvasImage);
			}
		add(imagePane, BorderLayout.CENTER);
		add(panelControle, BorderLayout.SOUTH);
		}

	private void controle()
		{
		// rien
		}

	private void apparance()
		{
		// rien
		}

	/*------------------------------------------------------------------*\
	|*							Attributs Private						*|
	\*------------------------------------------------------------------*/

	// Inputs
	private int w;
	private int h;
	private int nbrImage;


	// Tools
	private List<CanvasImage> canvasImages;
	private JPanelControle panelControle;
	}