# Version 	: 0.0.2
#
# Attention
#
#	(A1)	Dans les d�finitions de variables ci-dessous, m�fiez-vous des espaces � la fin!
#	(A2)	Laisser espace  apr�s le += de surcharge : exemple : xxx+= yyyy
#

ifndef __VISUAL_PUBLIC_OPTION_MK__
__VISUAL_PUBLIC_OPTION_MK__=true

###############################################
#  			Visual							  #
###############################################

include ${ROOT_MAKEFILE_PUBLIC_COMMON}/common.mk

########################
#   	public		   #
########################

#Option de compilation 
#	Version minimale : vide
#	Surcharger automatiquement (par exemple en fonction du type de la target)

#override CXXFLAGS+=

#################
# 	Warning     #
#################

#override CXXFLAGS+= /w 		# Suppres warning messages 
#override CXXFLAGS+= /Wall	# Enables all warning 
#override CXXFLAGS+= /W3		# Warning level

#################
# 	divers     #
#################

#exception
override CXXFLAGS+= /EHsc 

#linkage dll
override CXXFLAGS+= /MD
#override CXXFLAGS+= /MT

#################
# Optimisation  #
#################

# General
override CXX_OPTIMISATION+= /Ox 			# All optimisation

# CPU specific
#override X86_CXX_OPTIMISATION+= /arch:SSE 	# By default with 64bits processor
#override X86_CXX_OPTIMISATION+= /arch:SSE2 	# By default with 64bits processor , xeon x4 home
override X86_CXX_OPTIMISATION+= /arch:AVX	# ko home, i7 work
#override X86_CXX_OPTIMISATION+= /arch:AVX2	# cuda2,i7 home

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

endif#__VISUAL_PUBLIC_OPTION_MK__
