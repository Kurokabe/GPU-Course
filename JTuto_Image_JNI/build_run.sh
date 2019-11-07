#!/bin/bash
#

set -e
set -u

# ---------------------------------------
#                input
#----------------------------------------

# rien

# ---------------------------------------
#               private
#----------------------------------------

pushd . >/dev/null

cd ../Tuto_Image_JNI
cbicc gcc clean jall

popd > /dev/null
pushd . >/dev/null

cd ../Tuto_Image_JNI_Cuda
cbicc cuda clean jall

popd > /dev/null

cbicc java build
#./runGcc.sh

./runCuda.sh

# ---------------------------------------
#               end
#----------------------------------------
