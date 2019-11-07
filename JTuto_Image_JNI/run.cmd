echo off

rem -------------
rem   para
rem --------------

rem ---------------------------------------
rem               private
rem ----------------------------------------

rem -------------
rem   path
rem --------------

set JAVA_PATH=C:\Soft\java64\jre\bin
set SYMLINK_JAR_PATH=C:\Soft_API\SYMLINK\JAR
set API_BIN_PATH=C:\Soft_API\SYMLINK\BIN

set CLASS_PATH=.
set CLASS_PATH=%CLASS_PATH%;./*
set CLASS_PATH=%CLASS_PATH%;%SYMLINK_JAR_PATH%/*
set CLASS_PATH=%CLASS_PATH%;./bin

set APPLICATIF_BIN_PATH=.
set APPLICATIF_BIN_PATH=%APPLICATIF_BIN_PATH%;../RELEASE/bin

set PATH=.;%PATH%
set PATH=%PATH%;%APPLICATIF_BIN_PATH%
set PATH=%PATH%;%API_BIN_PATH%
set PATH=%PATH%;%JAVA_PATH%

rem -------------
rem   jvm
rem --------------

set MAIN_CLASS=org.bilat.tuto.image.jni.UseImageGL
set MEMORY=-Xms1024m -Xmx2048m 

set JAVA_LIBRARY_PATH=.
set JAVA_LIBRARY_PATH=%JAVA_LIBRARY_PATH%;%APPLICATIF_BIN_PATH%
set JAVA_LIBRARY_PATH=%JAVA_LIBRARY_PATH%;%API_BIN_PATH%

rem see run.sh for more information!
set SIMPLE_NAME_SHARED_LIB_JNI_OMP=Tuto_Image_JNI
set SIMPLE_NAME_SHARED_LIB_JNI_CUDA=Tuto_Image_Cuda_JNI
set PATH_SHARED_LIB_JNI=../RELEASE/bin
set CXX=visual

rem -------------
rem   info
rem --------------

echo.
echo ---------------------------------------------------------------------------------------------------
echo.
echo MAIN_CLASS         : %MAIN_CLASS%
echo.
echo MEMORY             : %MEMORY%
echo.
echo CLASS_PATH         : %CLASS_PATH%
echo.
echo JAVA_LIBRARY_PATH  : %JAVA_LIBRARY_PATH%
echo.
echo PATH               : %PATH%
echo.
echo ----------------------------------------------------------------------------------------------------
echo.
java -version
echo.

rem -------------
rem   run
rem --------------

rem version OMP
java %MEMORY% -classpath %CLASS_PATH% -Djava.library.path=%JAVA_LIBRARY_PATH% -DSIMPLE_NAME_SHARED_LIB_JNI=%SIMPLE_NAME_SHARED_LIB_JNI_OMP% -DCXX=%CXX% -DPATH_SHARED_LIB_JNI=%PATH_SHARED_LIB_JNI% %MAIN_CLASS%
java %MEMORY% -classpath %CLASS_PATH% -Djava.library.path=%JAVA_LIBRARY_PATH% -DSIMPLE_NAME_SHARED_LIB_JNI=%SIMPLE_NAME_SHARED_LIB_JNI_CUDA% -DPATH_SHARED_LIB_JNI=%PATH_SHARED_LIB_JNI% %MAIN_CLASS%

pause

rem ----------------------------------------
rem               end
rem ----------------------------------------