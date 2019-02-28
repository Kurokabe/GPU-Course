# Version 	: 0.0.1
# Author 	: Cedric.Bilat@he-arc.ch
#
# Notes
#
#	(N1)	Les options de compilation sont souvent les memes d'un projet � l'autre.
#			Ces options communes � tout le workspace se trouve daan la partie public du projet BUILDER.
#			
#	(N2)	Vous pouvez redefinir ou surcharger ces options dans ce present .mk pour customizer un projet sp�cifique.
#
#	(N3)	Pour modifier la configuration de tous vos projets, modifier directement les .mk generiques dans le BUILDER
#

###############################################
#  					Cuda Visual				  #
###############################################

########################
#   	public		   #
########################

#########
# visual#
#########

override CXXFLAGS+=#
override CXXLDFLAGS+=#

#########
# nvcc  #
#########

override NVCCFLAGS+= --ptxas-options=-v
override NVCCLDFLAGS+=
 
#########
# plus  #
#########

override CODE_DEFINE_VARIABLES+=#

###############################################
#  					End						  #
###############################################

