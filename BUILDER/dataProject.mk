# Usefull for
#
#		builder_api
#
# et accessoirement
#
#		linux clean
#		linux_workspace_all
#		

#################################################
#						builderapi		 		#
#################################################


###############
#	CPP  	  #
###############

#list ordonner des projest a builder

LIST_PROJECTS:=
 
override LIST_PROJECTS+= CppTest

override LIST_PROJECTS+= BilatTools_CPP
override LIST_PROJECTS+= BilatTools_OMP
override LIST_PROJECTS+= BilatTools_OpenCV
override LIST_PROJECTS+= BilatTools_V4L_Linux
override LIST_PROJECTS+= BilatTools_Cuda

override LIST_PROJECTS+= BilatTools_Image
override LIST_PROJECTS+= BilatTools_Image_CV
override LIST_PROJECTS+= BilatTools_Cuda_Image
override LIST_PROJECTS+= BilatTools_Cuda_Image_CV
override LIST_PROJECTS+= BilatTools_Cuda_3D

override LIST_PROJECTS+= BilatTools_Intel_MKL

override LIST_PROJECTS+= BilatTools_JNI


###############
#	JAVA	  #
###############

LIST_PROJECTS_JAVA:=

#Ici aucun projet ne se deploie en java, et le build ne pourrait fonctionner 
# que si la shared-lib associé serait dans la liste des projets cpp ci-dessus, ce qui n'est pas le cas.

#override LIST_PROJECTS_JAVA+= JTuto_Canvas_JNI
#override LIST_PROJECTS_JAVA+= JTuto_Graphe_JNI
#override LIST_PROJECTS_JAVA+= JTuto_Image_JNI

#################################################
#						End	 			 		#
#################################################
