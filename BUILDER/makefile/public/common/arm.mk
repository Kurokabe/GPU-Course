#

ifndef __ARM_COMMON_MK_PUBLIC__
__ARM_COMMON_MK_PUBLIC__=true

##############################################
#   			 Variables     				 #
##############################################


########
#arm #
########

ifeq (${ARCH},arm)	

	#Deploment data
	JETSON_3_IP:=157.26.103.7
	JETSON_6_IP:=157.26.103.142
	
	JETSON_TX2_a:=157.26.103.174
	JETSON_TX2_b:=157.26.103.143
	JETSON_TX2_c:=157.26.103.144
	JETSON_TX2_d:=157.26.103.168

	JETSON_IP:=${JETSON_TX2_c}
	
	JETSON_USER:=ubuntu
	JETSON_BIN:=/home/ubuntu/HEARC/bin

	#ifeq ($(PLATFORME),jetson) 
		PLATFORME_IP:=${JETSON_IP}
		PLATFORME_BIN:=${JETSON_BIN}
		PLATFORME_USER:=${JETSON_USER}
	#endif

endif


endif#__GCC_ARM_MK_PUBLIC__

