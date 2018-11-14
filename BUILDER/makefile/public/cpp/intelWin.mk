# Version 	: 0.0.3
#
# Attention
#
#	(A1)	Dans les d�finitions de variables ci-dessous, m�fiez-vous des espaces � la fin!
#	(A2)	Laisser espace  apr�s le += de surcharge : exemple : xxx+= yyyy
#

ifndef __INTEL_WIN_PUBLIC_OPTION_MK__
__INTEL_WIN_PUBLIC_OPTION_MK__=true

###############################################
#  			Intel Win						  #
###############################################

include ${ROOT_MAKEFILE_PUBLIC_COMMON}/common.mk

########################
#   	public		   #
########################

# Option de compilation 
#	Version minimale : vide
#	Surcharger automatiquement (par exemple en fonction du type de la target)

#################
# 	Warning     #
#################

#override CXXFLAGS+= /w 		#Suppres warning messages

#################
# 	Divers     #
#################

#exception
override CXXFLAGS+= /EHsc

#linkage dll
override CXXFLAGS+= /MD 

#################
# Optimisation  #
#################

# General
override CXX_OPTIMISATION+= /O3
override CXX_OPTIMISATION+= /fast
override CXX_OPTIMISATION+= /Qparallel
override CXX_OPTIMISATION+= /Qpar-threshold100

# CPU specific
#override X86_CXX_OPTIMISATION+= /QxSSSE3  
#override X86_CXX_OPTIMISATION+= /QxSSE4.1 		# xeon x8 home
#override X86_CXX_OPTIMISATION+= /QxSSE4.2		# cuda1
override X86_CXX_OPTIMISATION+= /QxAVX 			# i7 work
#override X86_CXX_OPTIMISATION+= /QxCORE-AVX2 	# cuda2,i7 home

#override X86_CXX_OPTIMISATION+= /QxHost 		#generate instructions for the highest instruction set and processor available on the compilation host machine
#override X86_CXX_OPTIMISATION+= /xHost 		#generate instructions for the highest instruction set and processor available on the compilation host machine

#https://software.intel.com/en-us/articles/performance-tools-for-software-developers-intel-compiler-options-for-sse-generation-and-processor-specific-optimizations

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

override LDFLAGS_AUX+=#

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

#################
# deprecated    #
#################

# Injection automatique de lib windows standard
#		true (ou n'importe quoi) pour activer!
#		rien pour desactiver
#		Version minimale : vide (avec # pour le montrer)

#override IS_DEFAULT_SYS_LIBRARY_ENABLE+=#
#override IS_ADVANCED_SYS_LIBRARY_ENABLE+=#


###############################################
#  					End						  #
###############################################

endif#__INTEL_WIN_PUBLIC_OPTION_MK__
