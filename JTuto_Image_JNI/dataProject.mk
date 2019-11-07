
#################################################
#						builderapi		 		#
#################################################

include ${API_CBI_TOOLS}/bilat_tools_infographie_java.mk

#override CLASSPATH+= XXX YYY#

# TargetName du projet natif cpp/cuda frabricant la shared lib
#
# Contraintes:
#		(C1) Sans extension
#		(C2) Sans version
#		(C3) Sans compilateur
#		(C4) Sans Cuda si projet cuda
#
SHARED_LIB_NAME_SIMPLE:=Tuto_Image_JNI

#Nom du jar creer par ce projet (sans .jar)
NAME_JAR:="${SHARED_LIB_NAME_SIMPLE}_${CBI_INFOGRAPHIE_VERSION}"#sans .jar

IS_CUDA:=true

##################
#	Install	 	 #
##################

INSTALL_PATH:=../RELEASE/bin

#################################################
#						End	 			 		#
#################################################