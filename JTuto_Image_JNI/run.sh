#!/bin/bash
#

set -e
set -u

# ---------------------------------------
#                Definition
#----------------------------------------

SIMPLE_NAME_SHARED_LIB_JNI_GCC=Tuto_Image_JNI
SIMPLE_NAME_SHARED_LIB_JNI_CUDA=${SIMPLE_NAME_SHARED_LIB_JNI_GCC}_Cuda

IS_DEBUG=false

# ---------------------------------------
#                input
#----------------------------------------

if [[ "$1" == "gcc" ]]
then
	SIMPLE_NAME_SHARED_LIB_JNI=$SIMPLE_NAME_SHARED_LIB_JNI_GCC
    CXX=gcc
    FILTER=gcc
elif  [[ "$1" == "cuda" ]]
then
	SIMPLE_NAME_SHARED_LIB_JNI=$SIMPLE_NAME_SHARED_LIB_JNI_CUDA
    CXX=gcc
    FILTER=cuda
elif  [[ "$1" == "intel" ]]
then
	SIMPLE_NAME_SHARED_LIB_JNI=$SIMPLE_NAME_SHARED_LIB_JNI_GCC
    CXX=intel
    FILTER=intel
else
    echo ""
    echo "Warning : wrong usage! Examples:"
    echo ""
    echo "./run.sh gcc"
    echo "./run.sh intel"
    echo "./run.sh cuda"
    echo ""
    echo "./run.sh gcc arm"
    echo "./run.sh cuda arm"
    echo ""
fi

set +u
if [[ "$2" == "arm" ]]
then
   #pas de run a distance
	GL="" 
    FILTER="arm"
else
	GL=gl
fi
set -u

# ---------------------------------------
#               main
#----------------------------------------

# -------------
#   class path
#--------------

CLASS_PATH=.
CLASS_PATH=${CLASS_PATH}:./*
CLASS_PATH=${CLASS_PATH}:./bin
CLASS_PATH=${CLASS_PATH}:./INC_SYMLINK/EXT_JAR/*
CLASS_PATH=${CLASS_PATH}:../RELEASE/bin/*

# -------------
#   jvm
#--------------

MAIN_CLASS=org.bilat.tuto.image.jni.UseImageGL
MEMORY='-Xms1024m -Xmx2048m'

# -------------
#   bin path
#--------------

PATH_SHARED_LIB_JNI=../RELEASE/bin

BIN_PATH=.
BIN_PATH+=:
BIN_PATH+=${PATH_SHARED_LIB_JNI}
BIN_PATH+=:
BIN_PATH+=/opt/api/SYMLINK/BIN

set +u
if [[ "$LD_LIBRARY_PATH" == "" ]]
then
	export LD_LIBRARY_PATH=${BIN_PATH}
else	
	export LD_LIBRARY_PATH=${LD_LIBRARY_PATH}:${BIN_PATH}
fi
set -u

JAVA_LIBRARY_PATH=${BIN_PATH}

PATH=${PATH}:${BIN_PATH}

# -------------
#   debug
#--------------

if $IS_DEBUG
then
	echo ""
	echo "MAIN_CLASS			=$MAIN_CLASS"
	echo "MEMORY				=$MEMORY"
	echo ""
	echo "SIMPLE_NAME_SHARED_LIB_JNI	=$SIMPLE_NAME_SHARED_LIB_JNI"
	echo ""
	echo "JAVA_LIBRARY_PATH=		=$JAVA_LIBRARY_PATH"
	echo "CLASS_PATH=			=$CLASS_PATH"

    echo "FILTER lib=			=$FILTER"
	echo ""
	echo "sleep 4"
    sleep 4
	echo ""
fi

# ---------------------------------------
#   run
# ---------------------------------------

# Croisement compilateur
# 	Attention, la shared lib des jar ext utilises doivent etre compiler avec le meme compilateur		

${GL} cbirt ${CXX}  java ${MEMORY} -classpath ${CLASS_PATH} -DSIMPLE_NAME_SHARED_LIB_JNI=${SIMPLE_NAME_SHARED_LIB_JNI} -DPATH_SHARED_LIB_JNI=${PATH_SHARED_LIB_JNI} -DCXX=$FILTER -Djava.library.path=${JAVA_LIBRARY_PATH} ${MAIN_CLASS}

# ---------------------------------------
#               end
#----------------------------------------
