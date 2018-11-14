#!/bin/bash

set -e
set -u

#-----------------------------------------------
#		Input
#-----------------------------------------------

#rien
#list project is define in DataProject.mk

#------------------------------------------------------------------------------------
#		main
#------------------------------------------------------------------------------------

if [[ $USER != "root" ]]
then
	echo ""
	echo "Error : this script must be launch in sudo "
	echo ""
	exit 1
	
fi
		
cbicc gcc installworkspaceARM
cbicc java installworkspace

#--------------------------------------
#		symlink ext bin all
#--------------------------------------

pushd .

cbicc gcc symlinkExtBinAll

popd

#--------------------------------------
#		workspace symlink ext
#--------------------------------------

pushd .

cd ..
WORKSPACE_ROOT=$(pwd)

cd ./BUILDER/makefile/private/script/workspace_auto

./workspace_symlink_ext.sh ${WORKSPACE_ROOT}

popd

#------------------------------------------------------------------------------------
#		end
#------------------------------------------------------------------------------------
