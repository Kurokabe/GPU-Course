# Version 	: 0.0.1

###############################################
#  					Intel					  #
###############################################

# Optimisation:
#	CXXFLAGS+= -parallel #: auto paralelisation sequentiel code
# Strategie:
#	-parallel est activer par default, car gain enorme de performance!
# Bug:
#	Pour projet "trop simple" pose problleme au linkage : "undefined reference to `__kmpc_begin'"
#	Observer avec (par exemple) : icc 14.0.1 20131008
# Solution:

override CXXFLAGS_EXCLUDE+= -parallel

###############################################
#  					End						  #
###############################################
