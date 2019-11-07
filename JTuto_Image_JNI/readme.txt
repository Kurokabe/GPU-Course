--------------------------------------------------------------------------
Projet java /jni
--------------------------------------------------------------------------
	
	linux clean  depuis eclipse
	
	-----------	
	c++ side
	-----------	
		
			cbicc cuda clean jall
		
			or
		
			cbicc gcc clean jall
		
			or
		
			cbicc intel clean jall (si version intel deployed, ask prof)

	-----------	
	java side
	-----------	
	
		Once cuda or gcc : Specifier si le code natif est cuda ou pas dans
		
				dataProject.mk		
				IS_CUDA:=true
			
		Make jar:
	
			cbicc java build
			
		run:
		
			./run.sh cuda
			
			or
			
			./run.sh gcc
			
			or
			
			./run.sh intel (si version intel deployed, ask prof)
			

	-----------	
	ou java side
	-----------	
	
	./build_run.sh
	
	qui fait tout pour vous! Warning: Commenter la fin du script selon si vous voulez cuda ou gcc ou intel
	
--------------------------------------------------------------------------
Attention
--------------------------------------------------------------------------

	-----------	
	c++ side
	-----------
	
	La shared lib doit etre compiler avant de lancer le code java se trouver dans ./RELEASE/BIN
	
	-----------	
	java side
	-----------	
	
	Le code java doit etre compiler, par eclipse ca suffit! (pas besoin de cbicc java build, qui est utile pour faire du deployment)
	Warning : eclipse buildpath use jar in ./INC_SYMLINK/EXT_JAR
	
	Protocole sans cbicc java build (utile en phase de developpement et debug)
	
		c++ side : comme d'habitude, par exemple
		
						cbicc cuda jall
						
		java side:  Travailler dans eclipse comme d'habitude
			        
			        compiler : 	CTRL SHIF S pour sauver 
					executer :  ./run.sh cuda
					
		Tip:
		
				(T1) 	Ouvrer une console dans eclipse
						Selection du projet, puis barre d'outil ...
				
				(T2)	Pour le dev java, basculer en perspective java dans eclipse (eh haut à droite du GUI)
	
	-----------	
	Dependances
	-----------	

	Exemples:
	
			Bilat_Fenetrage_Canvas_JNI_XXX.jar	qui utilise libBilat_Fenetrage_Canvas_JNI_yyy_XXX.so
			Bilat_Image_JNI_XXX.jar				qui utilise	libBilat_Image_JNI_yyy_XXX.so
			
			ou yyy = gcc or intel

	-----------	
	symlink jar local
	-----------

	Si plusieurs versions, effacer à la main ./INC_SYMLINK/EXT_JAR et regenerer

	-----------	
	intel
	-----------	

	Conseil : 	Utiliser soit gcc soit intel et ne croiser pas les compilateurs entre le use et les dependances.
				Pour les dependances, le choix se fait pendant le deploiment (choix gcc done)
				On peut changer ce choix après cout en editant le file properties inclus dans le jar.

	-----------	
	Si Probleme
	-----------	
	
	(P1) Regenerer les jar ext	
	
			opt/symlink 				sudo cbicc gcc symlinkExtBinAll
			
			local symlink au projet : 	linux_workspace_symlink_ext
			
										cbicc gcc symlinkExtJar
			
	(P2) Clean all (pour pas mixer du gcc avec de l'intel)
	
			cbicc gcc cleanAll

	-----------	
	animator
	-----------	

	animator java call
		
		animation step natif (incremente dt par exemple)
		repaint java
		
	puis le repaint java par le awt-queue-event appelle la methode native qui remplit la zone memoire de l'image (ex kernel cuda)
	
	En cuda il faut donc setter le device dans le awt-queue-event (etat de thread)
	Exemple : SwingUtilities.invokeAndWait  et appeler une methode native init qui set le device
	(a faire avant le premier repaint, par exemple avant l'instanciation de la premiere fenetre)	

--------------------------------------------------------------------------
java cpp vs cuda
--------------------------------------------------------------------------

Un code java peut utiliser une shared lib de type

	-cpp
	-cuda
	
le code java est le meme, seule la shared lib linker n'est pas la meme!
Pour cette raison, pour un projet java

	PJXXX_Java
	
on peut retrouver deux projets natifs


	PXXX_OMP_JNI
	
	PXXX_Cuda_JNI
	
--------------------------------------------------------------------------
compilateur
--------------------------------------------------------------------------

	Win		visual / intel 		(pas mingw, car dll jre pas mingw compatible)
	Linux	gcc / intel			(warning toute la chaine en intel, ou toute la chaine en gcc, le serveur est en gcc)
	
--------------------------------------------------------------------------
end
--------------------------------------------------------------------------
