# Version 	: 0.0.4
#
# Attention
#
#	(A1)	Dans les definitions de variables ci-dessous, mefiez-vous des espaces � la fin!
#	(A2)	Laisser espace  apres le += de surcharge : exemple : xxx+= yyyy
#

ifndef __GCC_PUBLIC_OPTION_MK__
__GCC_PUBLIC_OPTION_MK__=true

###############################################
#  					GCC						  #
###############################################

include ${ROOT_MAKEFILE_PUBLIC_COMMON}/common.mk

########################
#   	public		   #
########################

# Option de compilation 
#	Version minimale : vide
#	Surcharger automatiquement (par exemple en fonction du type de la target)

#override CXXFLAGS+=

#################
# 	Warning     #
#################

#override CXXFLAGS+= -w 					# Disable warning
#override CXXFLAGS+= -W 					# Print extra warning messages
#override CXXFLAGS+= -Wall 				# Enable all
#override CXXFLAGS+= -Wunused-variable 	# show unused-variable
#override CXXFLAGS+= -Wunused-function	# show unused-function
#override CXXFLAGS+= -Wunused-parameter 	# show unused-parameter

#################
# Optimisation  #
#################

# Common X86 et ARM
override CXX_OPTIMISATION+= -O3 

#######
# x86 #
#######

#https://gcc.gnu.org/onlinedocs/gcc/x86-Options.html#x86-Options

# General
override X86_CXX_OPTIMISATION+= -frerun-loop-opt 
#override X86_CXX_OPTIMISATION+= -fgcse 
override X86_CXX_OPTIMISATION+= -fomit-frame-pointer

# CPU specific
#override X86_CXX_OPTIMISATION+= -march=core2 
#override X86_CXX_OPTIMISATION+= -march=corei7 				# cuda1
#override X86_CXX_OPTIMISATION+= -march=corei7-avx 			# cuda2,i7
#override X86_CXX_OPTIMISATION+= -march=sandybridge			# i7 work
#override X86_CXX_OPTIMISATION+= -march=ivybridge			# i7 home
#override X86_CXX_OPTIMISATION+= -march=haswell		
#override X86_CXX_OPTIMISATION+= -march=broadwell
#override X86_CXX_OPTIMISATION+= -march=skylake		
override X86_CXX_OPTIMISATION+= -march=native 							# Detection automatique arch		

# tip: cat /proc/cpuinfo 

#######
# ARM #
#######

override ARM_CXXFLAGS+=#

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

override EXCLUDE_LIBRARY_FILES+=#
override ADD_LIBRARY_FILES+=#

###############################################
#  					End						  #
###############################################

endif#__GCC_PUBLIC_OPTION_MK__
