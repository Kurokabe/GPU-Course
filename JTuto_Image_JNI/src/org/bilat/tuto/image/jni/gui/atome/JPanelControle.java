
package org.bilat.tuto.image.jni.gui.atome;

import java.awt.Color;
import java.awt.FlowLayout;
import java.awt.Font;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.List;

import javax.swing.BoxLayout;
import javax.swing.JButton;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JSlider;
import javax.swing.event.ChangeEvent;
import javax.swing.event.ChangeListener;

public class JPanelControle extends JPanel
	{

	/*------------------------------------------------------------------*\
	|*							Constructeurs							*|
	\*------------------------------------------------------------------*/

	public JPanelControle(List<CanvasImage> canvasImages)
		{
		this.canvasImages = canvasImages;

		geometry();
		controle();
		apparance();
		}

	/*------------------------------------------------------------------*\
	|*							Methodes Public							*|
	\*------------------------------------------------------------------*/

	/*------------------------------------------------------------------*\
	|*							Methodes Private						*|
	\*------------------------------------------------------------------*/

	private void geometry()
		{
		labelJava = new JLabel();
		labelDt = new JLabel("Dt");
		sliderDt = new JSlider(SLIDER_MIN, SLIDER_MAX);
		lblnMin = new JLabel("nMin");
		lblnMax = new JLabel("nMax");
		sliderNMin = new JSlider(NMIN_MIN, NMIN_MAX);
		sliderNMax = new JSlider(NMAX_MIN, NMAX_MAX);

		boutonStart = new JButton("Start");
		boutonStop = new JButton("Stop");

		setLayout(new FlowLayout());

		JPanel p = new JPanel();
		p.setLayout(new BoxLayout(p, BoxLayout.Y_AXIS));

		p.add(lblnMin);
		p.add(sliderNMin);
		p.add(lblnMax);
		p.add(sliderNMax);

		add(labelJava);
		add(labelDt);
		add(sliderDt);
		add(p);
		add(boutonStart);
		add(boutonStop);
		}

	private void apparance()
		{
		int size=labelJava.getFont().getSize()*2;
		Font font = labelJava.getFont().deriveFont((float)size);

		labelJava.setFont(font);
		labelJava.setForeground(Color.GREEN);
		labelJava.setText("Java GUI ");
		}

	private void controle()
		{
		sliderDt.setValue(SLIDER_START);
		initStateBouton();
		applyDT(); // Ecrase valeur native qui existe forcement et est differente

		boutonStart.addActionListener(new ActionListener()
			{

			@Override
			public void actionPerformed(ActionEvent event)
				{
				for(CanvasImage canvasImage : canvasImages)
					{
					canvasImage.setAnimationEnable(true); // un thread java s'occupe d'appeler repaint du CanvasImageNative, qui lui s'occupe d'appeler animationStep cote natif
					}
				inverserStateBouton();
				}
			});

		boutonStop.addActionListener(new ActionListener()
			{

			@Override
			public void actionPerformed(ActionEvent event)
				{
				for(CanvasImage canvasImage : canvasImages)
					{
					canvasImage.setAnimationEnable(false);
					}
				inverserStateBouton();
				}
			});

		sliderDt.addChangeListener(new ChangeListener()
			{

			@Override
			public void stateChanged(ChangeEvent event)
				{
				applyDT();
				}
			});

		sliderNMin.addChangeListener(new ChangeListener()
			{

			@Override
			public void stateChanged(ChangeEvent event)
				{
				updateNMinNMax();
				}
			});

		sliderNMax.addChangeListener(new ChangeListener()
			{

			@Override
			public void stateChanged(ChangeEvent event)
				{
				updateNMinNMax();
				}
			});

		}

	private void updateNMinNMax() {
		int nMin = sliderNMin.getValue();
		int nMax = sliderNMax.getValue();

	    for(CanvasImage canvasImage : canvasImages)
			{
			canvasImage.setNMinNMax(nMin, nMax);
			}

	 }

	private void applyDT()
		{
		int value = sliderDt.getValue();
		for(CanvasImage canvasImage : canvasImages)
			{
			canvasImage.setDt(value);
			}
		}

	private void inverserStateBouton()
		{
		inverserStateBouton(boutonStart);
		inverserStateBouton(boutonStop);
		}

	private void initStateBouton()
		{
		boolean isAnimationEnable = canvasImages.get(0).isAnimationEnable();

		boutonStart.setEnabled(!isAnimationEnable);
		boutonStop.setEnabled(isAnimationEnable);
		}

	/*------------------------------*\
	|*			  Static			*|
	\*------------------------------*/

	private static void inverserStateBouton(JButton bouton)
		{
		bouton.setEnabled(!bouton.isEnabled());
		}

	/*------------------------------------------------------------------*\
	|*							Attributs Private						*|
	\*------------------------------------------------------------------*/

	//Inputs
	private List<CanvasImage> canvasImages;

	//Tools
	private JLabel labelJava;
	private JSlider sliderDt;
	private JLabel labelDt;
	private JButton boutonStart;
	private JButton boutonStop;


	private JLabel lblnMin;
	private JSlider sliderNMin;
	private JLabel lblnMax;
	private JSlider sliderNMax;

	/*------------------------------*\
	|*			  Static			*|
	\*------------------------------*/

	private static final int SLIDER_MAX = 10;
	private static final int SLIDER_MIN = 1;
	private static final int SLIDER_START = 1;
	private static final int NMIN_MIN= 10;
	private static final int NMIN_MAX = 50;
	private static final int NMAX_MIN = 70;
	private static final int NMAX_MAX = 120;
	protected static final int DT_START = 1;
	}