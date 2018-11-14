# Version 	: 0.0.4
#
# Attention
#
#	(A1)	Dans les d�finitions de variables ci-dessous, m�fiez-vous des espaces � la fin!
#	(A2)	Laisser espace  apr�s le += de surcharge : exemple : xxx+= yyyy
#

ifndef __CUDA_GCC_PUBLIC_OPTION_MK__
__CUDA_GCC_PUBLIC_OPTION_MK__=true

###############################################
#  			Cuda GCC Linux					  #
###############################################

include ${ROOT_MAKEFILE_PUBLIC_COMMON}/common.mk

##################################
#   		public			     #
##################################

########################
# 		gcc	   	  	   #
########################

#Option de compilation 
#	Version minimale : vide
#	Surcharger automatiquement (par exemple en fonction du type de la target)

#################
# 	Warning     #
#################

#override CXXFLAGS+= -w 					# Disable
#override CXXFLAGS+= -W 					# Print extra warning messages
#override CXXFLAGS+= -Wall  				# Enable all
#override CXXFLAGS+= -Wunused-variable 		# show unused-variable
#override CXXFLAGS+= -Wunused-function		# show unused-function
#override CXXFLAGS+= -Wunused-parameter 	# show unused-parameter

#################
# Optimisation  #
#################

# Common X86 et ARM
override CXX_OPTIMISATION+= -O3 #

#######
# x86 #
#######

override X86_CXX_OPTIMISATION+= -frerun-loop-opt#
#override X86_CXX_OPTIMISATION+= --fgcse#
override X86_CXX_OPTIMISATION+= -fomit-frame-pointer#

# CPU specific

#override X86_CXX_OPTIMISATION+= -march=core2
#override X86_CXX_OPTIMISATION+= -march=corei7				# cuda1
#override X86_CXX_OPTIMISATION+= -march=corei7-avx 			# cuda2, mieux?
#override X86_CXX_OPTIMISATION+= -march=sandybridge			# i7 work
#override X86_CXX_OPTIMISATION+= -march=ivybridge			# i7 home
#override X86_CXX_OPTIMISATION+= -march=haswell		

override X86_CXXFLAGS+= -march=native # Detection automatique arch

# tip: cat /proc/cpuinfo 

#######
# ARM #
#######

override ARM_CXXFLAGS+=#

#################
# linkage       #
#################

#	Version minimale : vide (sera surcharg�e)
#	Surcharger automatiquement (par exemple en fonction du type de la target)

override CXXLDFLAGS+=#

########################
# 		nvcc	   	   #
########################

#################
# Target       #
#################

# NVCCFLAGS
# https://developer.nvidia.com/cuda-gpus
#
########
# sm_1X		FERMI
########
#
# Quadro Fx4600 : 				sm_10 
# Quadro nvs140M : 				sm_11 
# GTX_295 : 					sm_13
#
########
# sm_2X		TESSLA
########
#  
# GTX 580					 	sm_20
# Tesla m2090					sm_20
# Quadro6000					sm_20
# Quadroplex 7000				sm_20
#
########
# SM_3X		 KEPPLER
########
#
# GTX 680						sm_30
# k5000							sm_30
# tk1							sm_32
# Tesla k20c					sm_35
# Gforce titan					sm_35
# k6000							sm_35
#
########
# SM_5X 	MAXWELL
########
#
# GeForce GTX 980				sm_52
# M6000							sm_52
# tx1							sm_53
#
########
# SM_6X		PASCAL
########
#
# tx2							sm_62					
#
########
# SM_7X 	VOLTA
#########
#

# NVCCFLAGS possibilities:
#
#	-arch=<compute_xy> 				Generate PTX for capability x.y
#	-code=<sm_xy> 					Generate binary for capability x.y, by default same as -arch
#	-gencode arch=...,code=... 		Same as -arch and -code, but may be repeated (executable is bigger, and compilation time longer)
#
# Target : Syntaxe light (shorcut)
#		 : Avantage 	: short,easy, quick
#		 : Incovenient  : only one target can be specify!
#
override NVCCFLAGS+= -arch=sm_52
override NVCCLDFLAGS+= -arch=sm_52
#
# Target : Syntaxe full
#		 : Avantage 	: many target can be specify! 
#		 :				: Allow jit compilation at runtime, for deploying in a gpu with higher arch than arch use for developpement. 
#
#		 : Option : -arch : Virtual architecture
#						  : generate PTX (ptx code is the same as byte code in java) 
#						  : Like java,  a jit compilation at runtime is performed.
#						  : Jit compilatioonce is performed only once, fortunately a cache is used to persist a final binary image.
#
#		 : Option : -code : Real architecture
#						  : nvcc embeded a compiled code image in the executable for each specified architecture -arch,
#						  : Code image is a true binary load image for each real architecture (present at compilation time?), and ptx code for earch virtual architecture (not present at compilation time?)
#		                
#		 : Attention	  : Doit se mettre sur la flag de compilation et linkage!    		         
#
# Enable or disable all following lignes

#override NVCCFLAGS+= -gencode arch=compute_20,code=sm_20 #idem NVCCFLAGS+= -arch=sm_20
#override NVCCLDFLAGS+= -gencode arch=compute_20,code=sm_20 
#override NVCCFLAGS+= -gencode arch=compute_30,code=sm_30 
#override NVCCLDFLAGS+= -gencode arch=compute_30,code=sm_30 
#override NVCCFLAGS+= -gencode arch=compute_35,code=sm_35 
#override NVCCLDFLAGS+= -gencode arch=compute_35,code=sm_35
#override NVCCFLAGS+= -gencode arch=compute_50,code=sm_50 
#override NVCCLDFLAGS+= -gencode arch=compute_50,code=sm_50 
#override NVCCFLAGS+= -gencode arch=compute_52,code=sm_52 
#override NVCCLDFLAGS+= -gencode arch=compute_52,code=sm_52 

#################
# Architecture  #
#################

override NVCCFLAGS+= -m64 #

#################
# Optimisation  #
#################

override NVCCFLAGS+= -use_fast_math	#idem -ftz=true -prec_div=false -prec_sqrt=false
override NVCCFLAGS+= --fmad=true #
 
#################
# linkage       #
#################

#	Version minimale : vide (sera surcharg�e)
#	Surcharger automatiquement (par exemple en fonction du type de la target)

override NVCCLDFLAGS+=# 


#################
# debug         #
#################

#decommneter la ligne pour 
#	(1) empecher l'optimisation
#	(2) activer les flag de debug

#DEBUG=true

#override NVCCFLAGS+= -dryrun
#verbosity
#override NVCCFLAGS+= -v
#override NVCCLDFLAGS+= -v

#${info "CXXFLAGS    = "${CXXFLAGS}}#print immediately
#${info "CXXLDFLAGS  = "${CXXLDFLAGS}}#print immediatel
#${info "NVCCFLAGS   = "${NVCCFLAGS}}#print immediatel
#${info "NVCCLDFLAGS = "${NVCCLDFLAGS}}#print immediatel

#################
# extension     #
#################

#Injection de variable dans le code 
#	same as #define XXX YYY
#	same as -DXXX
#Attention, pas mettre -D, ni #define, que XXX

override CODE_DEFINE_VARIABLES+=#

# Injection automatique de lib windows standard
#		true (ou n'importe quoi) pour activer!
#		rien pour desactiver
#		Version minimale : vide (avec # pour le montrer)

override EXCLUDE_LIBRARY_FILES+=#
override ADD_LIBRARY_FILES+=#

###############################################
#  					End						  #
###############################################

endif#__CUDA_GCC_PUBLIC_OPTION_MK__
