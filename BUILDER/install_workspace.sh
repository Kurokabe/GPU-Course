#!/bin/bash

set -e
set -u

#-----------------------------------------------
#		Input
#-----------------------------------------------

#rien
#list project is define in DataProject.mk

#usage debug
#sudo ./install_workspace.sh > debug.txt
#cat ./debug.txt | grep find

#------------------------------------------------------------------------------------
#		main
#------------------------------------------------------------------------------------

pushd .

if [[ "$(uname)" == "Linux" ]]
then
		if [[ $USER != "root" ]]
		then
			echo ""
			echo "Error : this script must be launch in sudo "
			echo ""
			exit 1
			
		fi
		
		#gcc & intel
		cbicc gcc installworkspace
		cbicc java installworkspace
		
else
		#visual & intel & mingw
		cbicc visual installworkspace
		cbicc java installworkspace
		#echo ""
fi

popd

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
