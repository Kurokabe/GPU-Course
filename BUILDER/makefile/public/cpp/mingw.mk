# Version 	: 0.0.3
#
# Attention
#
#	(A1)	Dans les d�finitions de variables ci-dessous, m�fiez-vous des espaces � la fin!
#	(A2)	Laisser espace  apr�s le += de surcharge : exemple : xxx+= yyyy
#

ifndef __MINGW_PUBLIC_OPTION_MK__
__MINGW_PUBLIC_OPTION_MK__=true


###############################################
#  			MinGW							  #
###############################################

include ${ROOT_MAKEFILE_PUBLIC_COMMON}/common.mk

########################
#   	public		   #
########################

#Option de compilation 
#	Version minimale : vide
#	Surcharger automatiquement (par exemple en fonction du type de la target)

#override CXXFLAGS+=#

#################
# 	Warning     #
#################

#override CXXFLAGS+= -w 					# disable warning
#override CXXFLAGS+= -W 					# Print extra warning messages
#override CXXFLAGS+= -Wall 				# enable all warning
#override CXXFLAGS+= -Wunused-variable 	# show unused-variable
#override CXXFLAGS+= -Wunused-function	# show unused-function
#override CXXFLAGS+= -Wunused-parameter 	# show unused-parameter

#################
# Optimisation  #
#################

# General
override CXX_OPTIMISATION+= -O3

override CXX_OPTIMISATION+= -frerun-loop-opt 
override CXX_OPTIMISATION+= -fgcse 
override CXX_OPTIMISATION+= -fomit-frame-pointer

# CPU specific

#override X86_CXX_OPTIMISATION+= -march=core2 				# xeon x4 home,portable
#override X86_CXX_OPTIMISATION+= -march=corei7			 	# cuda1
#override X86_CXX_OPTIMISATION+= -march=corei7-avx  			# cuda2, mieux?
#override X86_CXX_OPTIMISATION+= -march=sandybridge			# i7 work
#override X86_CXX_OPTIMISATION+= -march=ivybridge			# i7 home
#override X86_CXX_OPTIMISATION+= -march=haswell	

override X86_CXX_OPTIMISATION+= -march=native 				# Detection automatique arch

#################
# debug         #
#################

#decommneter la ligne pour 
#	(1) empecher l'optimisation
#	(2) activer les flag de debug

#DEBUG=true

#################
# linkage       #
#################

# Static Lib
#	Version minimale : vide
#	Surcharger automatiquement (par exemple en fonction du type de la target)

override ARFLAGS+=#
 
 
# Shared lib
#	Version minimale : vide (sera surcharg�e)
#	Surcharger automatiquement (par exemple en fonction du type de la target)

override LDFLAGS+=#

#################
# extension     #
#################

#Injection de variable dans le code 
#	same as #define XXX YYY
#	same as -DXXX
#Attention, pas mettre -D, ni #define, que XXX

override CODE_DEFINE_VARIABLES+=#

# Attention :
#	separateur est espac
#	sans extension .lib
#	sans prefixe lib

override ADD_LIBRARY_FILES+=#
override EXCLUDE_LIBRARY_FILES+=#

###############################################
#  					End						  #
###############################################

endif#__MINGW_PUBLIC_OPTION_MK__

