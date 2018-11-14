#!/bin/bash


set -e
set -u

#------------------------------------------------------------------------------------
#		input
#------------------------------------------------------------------------------------

#rien

#------------------------------------------------------------------------------------
#		tools
#------------------------------------------------------------------------------------

source ./makefile/private/script/install/toARM_ssh.sh

# -----------------------
#infographie
# -----------------------

function infographie_transfert()
	{
	local readonly USER="$1"
	local readonly IP="$2"
	local readonly VERSION="$3"
	
	local readonly FOLDER=infographie
	local readonly TITLE=$FOLDER

	local readonly SOURCE=/opt/api/cbi/$FOLDER
	local readonly DESTINATION=/opt/api/cbi/${FOLDER}/$VERSION/lib
	
	toARM $TITLE $USER $IP $SOURCE $DESTINATION $VERSION
	}

# -----------------------
# tools
# -----------------------

function tools_transfert()
	{
	local readonly USER="$1"
	local readonly IP="$2"
	local readonly VERSION="$3"

	local readonly FOLDER=tools
	local readonly TITLE=$FOLDER

	local readonly SOURCE=/opt/api/cbi/$FOLDER
	local readonly DESTINATION=/opt/api/cbi/${FOLDER}/$VERSION/lib
	
	toARM $TITLE $USER $IP $SOURCE $DESTINATION $VERSION
	}

# -----------------------
# capteur
# -----------------------

function capteur_transfert()
	{
	local readonly USER="$1"
	local readonly IP="$2"
	local readonly VERSION="$3"

	local readonly FOLDER=capteur
	local readonly TITLE=$FOLDER

	local readonly SOURCE=/opt/api/cbi/$FOLDER
	local readonly DESTINATION=/opt/api/cbi/${FOLDER}/$VERSION/lib
	
	toARM $TITLE $USER $IP $SOURCE $DESTINATION $VERSION
	}

# -----------------------
# pipe
# -----------------------

# pas utile, car deploy dans meme folder que capteur
# deploy capteur => deploy pipe
function pipe_transfert()
	{
	local readonly USER="$1"
	local readonly IP="$2"
	local readonly VERSION="$3"

	local readonly FOLDER=pipe
	local readonly TITLE=$FOLDER

	local readonly SOURCE=/opt/api/cbi/$FOLDER
	local readonly DESTINATION=/opt/api/cbi/${FOLDER}/$VERSION/lib
	
	toARM $TITLE $USER $IP $SOURCE $DESTINATION $VERSION
	}


# -----------------------
# main
# -----------------------

function main()
	{
	local readonly  TIME_START_S=$(date +%s)

	local readonly IP_JETSON3=157.26.103.7
	local readonly IP_JETSON6=157.26.103.142
	
	local readonly IP_TX2_a=157.26.103.174
	local readonly IP_TX2_b=157.26.103.143
	local readonly IP_TX2_c=157.26.103.144
	local readonly IP_TX2_d=157.26.103.168

	local readonly USER_JETSON=ubuntu
	local readonly IP_JETSON=${IP_TX2_c}

	local readonly VERSION_INFOGRAPHIE=303
	local readonly VERSION_TOOLS=${VERSION_INFOGRAPHIE}_006
	local readonly VERSION_CAPTEUR=005
	#local readonly VERSION_PIPE=005

	infographie_transfert $USER_JETSON $IP_JETSON $VERSION_INFOGRAPHIE
	tools_transfert $USER_JETSON $IP_JETSON $VERSION_TOOLS
	capteur_transfert $USER_JETSON $IP_JETSON $VERSION_CAPTEUR

	#pas utile car deploye dans meme folder  que capteur, deploy capteur => deploy pipe
	#pipe_transfert $USER_JETSON $IP_JETSON $VERSION_PIPE
	}

#------------------------------------------------------------------------------------
#		main
#------------------------------------------------------------------------------------

#-------------
# Warning
#-------------
#
#	(W1)	Update version in xxx_transfert above function
#
#	(W2) 	Update IP and USER in main function
#
#	(W3)	Don't run this script in sudo

time main
echo ""

#------------------------------------------------------------------------------------
#		end
#------------------------------------------------------------------------------------

