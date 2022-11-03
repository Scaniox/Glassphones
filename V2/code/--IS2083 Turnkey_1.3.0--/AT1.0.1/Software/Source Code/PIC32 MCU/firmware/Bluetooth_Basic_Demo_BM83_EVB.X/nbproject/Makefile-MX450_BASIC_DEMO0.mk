#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-MX450_BASIC_DEMO0.mk)" "nbproject/Makefile-local-MX450_BASIC_DEMO0.mk"
include nbproject/Makefile-local-MX450_BASIC_DEMO0.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=MX450_BASIC_DEMO0
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/Bluetooth_Basic_Demo_BM83_EVB.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/Bluetooth_Basic_Demo_BM83_EVB.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=../src/system_config/MX450_BASIC_DEMO0/framework/driver/i2c/src/drv_i2c_static_buffer_model.c ../src/system_config/MX450_BASIC_DEMO0/framework/driver/i2c/src/drv_i2c_mapping.c ../src/system_config/MX450_BASIC_DEMO0/framework/driver/tmr/src/drv_tmr_static.c ../src/system_config/MX450_BASIC_DEMO0/framework/driver/tmr/src/drv_tmr_mapping.c ../src/system_config/MX450_BASIC_DEMO0/framework/driver/usart/src/drv_usart_mapping.c ../src/system_config/MX450_BASIC_DEMO0/framework/driver/usart/src/drv_usart_static.c ../src/system_config/MX450_BASIC_DEMO0/framework/driver/usart/src/drv_usart_static_byte_model.c ../src/system_config/MX450_BASIC_DEMO0/framework/system/clk/src/sys_clk_static.c ../src/system_config/MX450_BASIC_DEMO0/framework/system/ports/src/sys_ports_static.c ../src/system_config/MX450_BASIC_DEMO0/system_init.c ../src/system_config/MX450_BASIC_DEMO0/system_interrupt.c ../src/system_config/MX450_BASIC_DEMO0/system_exceptions.c ../src/system_config/MX450_BASIC_DEMO0/system_tasks.c ../src/app.c ../src/main.c ../bt_application/bt_app.c ../bt_application/bt_data.c ../bt_application/bt_hardware_profile.c ../bt_application/key.c ../bt_application/key_handler.c ../bt_application/led.c ../bt_application/timer.c "../BT Common/bt_a2dp.c" "../BT Common/bt_command_decode.c" "../BT Common/bt_command_send.c" "../BT Common/bt_hfp.c" "../BT Common/bt_line_in.c" "../BT Common/bt_multi_spk.c" "../BT Common/bt_volume.c" ../Codec/sta369bwdsp_handler.c ../../../../../../framework/system/devcon/src/sys_devcon.c ../../../../../../framework/system/devcon/src/sys_devcon_pic32mx.c ../../../../../../framework/system/int/src/sys_int_pic32.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/_ext/823550626/drv_i2c_static_buffer_model.o ${OBJECTDIR}/_ext/823550626/drv_i2c_mapping.o ${OBJECTDIR}/_ext/2052027997/drv_tmr_static.o ${OBJECTDIR}/_ext/2052027997/drv_tmr_mapping.o ${OBJECTDIR}/_ext/382828169/drv_usart_mapping.o ${OBJECTDIR}/_ext/382828169/drv_usart_static.o ${OBJECTDIR}/_ext/382828169/drv_usart_static_byte_model.o ${OBJECTDIR}/_ext/195891987/sys_clk_static.o ${OBJECTDIR}/_ext/766220707/sys_ports_static.o ${OBJECTDIR}/_ext/1823359670/system_init.o ${OBJECTDIR}/_ext/1823359670/system_interrupt.o ${OBJECTDIR}/_ext/1823359670/system_exceptions.o ${OBJECTDIR}/_ext/1823359670/system_tasks.o ${OBJECTDIR}/_ext/1360937237/app.o ${OBJECTDIR}/_ext/1360937237/main.o ${OBJECTDIR}/_ext/1205520658/bt_app.o ${OBJECTDIR}/_ext/1205520658/bt_data.o ${OBJECTDIR}/_ext/1205520658/bt_hardware_profile.o ${OBJECTDIR}/_ext/1205520658/key.o ${OBJECTDIR}/_ext/1205520658/key_handler.o ${OBJECTDIR}/_ext/1205520658/led.o ${OBJECTDIR}/_ext/1205520658/timer.o ${OBJECTDIR}/_ext/1634889738/bt_a2dp.o ${OBJECTDIR}/_ext/1634889738/bt_command_decode.o ${OBJECTDIR}/_ext/1634889738/bt_command_send.o ${OBJECTDIR}/_ext/1634889738/bt_hfp.o ${OBJECTDIR}/_ext/1634889738/bt_line_in.o ${OBJECTDIR}/_ext/1634889738/bt_multi_spk.o ${OBJECTDIR}/_ext/1634889738/bt_volume.o ${OBJECTDIR}/_ext/2146212583/sta369bwdsp_handler.o ${OBJECTDIR}/_ext/912498863/sys_devcon.o ${OBJECTDIR}/_ext/912498863/sys_devcon_pic32mx.o ${OBJECTDIR}/_ext/711155467/sys_int_pic32.o
POSSIBLE_DEPFILES=${OBJECTDIR}/_ext/823550626/drv_i2c_static_buffer_model.o.d ${OBJECTDIR}/_ext/823550626/drv_i2c_mapping.o.d ${OBJECTDIR}/_ext/2052027997/drv_tmr_static.o.d ${OBJECTDIR}/_ext/2052027997/drv_tmr_mapping.o.d ${OBJECTDIR}/_ext/382828169/drv_usart_mapping.o.d ${OBJECTDIR}/_ext/382828169/drv_usart_static.o.d ${OBJECTDIR}/_ext/382828169/drv_usart_static_byte_model.o.d ${OBJECTDIR}/_ext/195891987/sys_clk_static.o.d ${OBJECTDIR}/_ext/766220707/sys_ports_static.o.d ${OBJECTDIR}/_ext/1823359670/system_init.o.d ${OBJECTDIR}/_ext/1823359670/system_interrupt.o.d ${OBJECTDIR}/_ext/1823359670/system_exceptions.o.d ${OBJECTDIR}/_ext/1823359670/system_tasks.o.d ${OBJECTDIR}/_ext/1360937237/app.o.d ${OBJECTDIR}/_ext/1360937237/main.o.d ${OBJECTDIR}/_ext/1205520658/bt_app.o.d ${OBJECTDIR}/_ext/1205520658/bt_data.o.d ${OBJECTDIR}/_ext/1205520658/bt_hardware_profile.o.d ${OBJECTDIR}/_ext/1205520658/key.o.d ${OBJECTDIR}/_ext/1205520658/key_handler.o.d ${OBJECTDIR}/_ext/1205520658/led.o.d ${OBJECTDIR}/_ext/1205520658/timer.o.d ${OBJECTDIR}/_ext/1634889738/bt_a2dp.o.d ${OBJECTDIR}/_ext/1634889738/bt_command_decode.o.d ${OBJECTDIR}/_ext/1634889738/bt_command_send.o.d ${OBJECTDIR}/_ext/1634889738/bt_hfp.o.d ${OBJECTDIR}/_ext/1634889738/bt_line_in.o.d ${OBJECTDIR}/_ext/1634889738/bt_multi_spk.o.d ${OBJECTDIR}/_ext/1634889738/bt_volume.o.d ${OBJECTDIR}/_ext/2146212583/sta369bwdsp_handler.o.d ${OBJECTDIR}/_ext/912498863/sys_devcon.o.d ${OBJECTDIR}/_ext/912498863/sys_devcon_pic32mx.o.d ${OBJECTDIR}/_ext/711155467/sys_int_pic32.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/_ext/823550626/drv_i2c_static_buffer_model.o ${OBJECTDIR}/_ext/823550626/drv_i2c_mapping.o ${OBJECTDIR}/_ext/2052027997/drv_tmr_static.o ${OBJECTDIR}/_ext/2052027997/drv_tmr_mapping.o ${OBJECTDIR}/_ext/382828169/drv_usart_mapping.o ${OBJECTDIR}/_ext/382828169/drv_usart_static.o ${OBJECTDIR}/_ext/382828169/drv_usart_static_byte_model.o ${OBJECTDIR}/_ext/195891987/sys_clk_static.o ${OBJECTDIR}/_ext/766220707/sys_ports_static.o ${OBJECTDIR}/_ext/1823359670/system_init.o ${OBJECTDIR}/_ext/1823359670/system_interrupt.o ${OBJECTDIR}/_ext/1823359670/system_exceptions.o ${OBJECTDIR}/_ext/1823359670/system_tasks.o ${OBJECTDIR}/_ext/1360937237/app.o ${OBJECTDIR}/_ext/1360937237/main.o ${OBJECTDIR}/_ext/1205520658/bt_app.o ${OBJECTDIR}/_ext/1205520658/bt_data.o ${OBJECTDIR}/_ext/1205520658/bt_hardware_profile.o ${OBJECTDIR}/_ext/1205520658/key.o ${OBJECTDIR}/_ext/1205520658/key_handler.o ${OBJECTDIR}/_ext/1205520658/led.o ${OBJECTDIR}/_ext/1205520658/timer.o ${OBJECTDIR}/_ext/1634889738/bt_a2dp.o ${OBJECTDIR}/_ext/1634889738/bt_command_decode.o ${OBJECTDIR}/_ext/1634889738/bt_command_send.o ${OBJECTDIR}/_ext/1634889738/bt_hfp.o ${OBJECTDIR}/_ext/1634889738/bt_line_in.o ${OBJECTDIR}/_ext/1634889738/bt_multi_spk.o ${OBJECTDIR}/_ext/1634889738/bt_volume.o ${OBJECTDIR}/_ext/2146212583/sta369bwdsp_handler.o ${OBJECTDIR}/_ext/912498863/sys_devcon.o ${OBJECTDIR}/_ext/912498863/sys_devcon_pic32mx.o ${OBJECTDIR}/_ext/711155467/sys_int_pic32.o

# Source Files
SOURCEFILES=../src/system_config/MX450_BASIC_DEMO0/framework/driver/i2c/src/drv_i2c_static_buffer_model.c ../src/system_config/MX450_BASIC_DEMO0/framework/driver/i2c/src/drv_i2c_mapping.c ../src/system_config/MX450_BASIC_DEMO0/framework/driver/tmr/src/drv_tmr_static.c ../src/system_config/MX450_BASIC_DEMO0/framework/driver/tmr/src/drv_tmr_mapping.c ../src/system_config/MX450_BASIC_DEMO0/framework/driver/usart/src/drv_usart_mapping.c ../src/system_config/MX450_BASIC_DEMO0/framework/driver/usart/src/drv_usart_static.c ../src/system_config/MX450_BASIC_DEMO0/framework/driver/usart/src/drv_usart_static_byte_model.c ../src/system_config/MX450_BASIC_DEMO0/framework/system/clk/src/sys_clk_static.c ../src/system_config/MX450_BASIC_DEMO0/framework/system/ports/src/sys_ports_static.c ../src/system_config/MX450_BASIC_DEMO0/system_init.c ../src/system_config/MX450_BASIC_DEMO0/system_interrupt.c ../src/system_config/MX450_BASIC_DEMO0/system_exceptions.c ../src/system_config/MX450_BASIC_DEMO0/system_tasks.c ../src/app.c ../src/main.c ../bt_application/bt_app.c ../bt_application/bt_data.c ../bt_application/bt_hardware_profile.c ../bt_application/key.c ../bt_application/key_handler.c ../bt_application/led.c ../bt_application/timer.c ../BT Common/bt_a2dp.c ../BT Common/bt_command_decode.c ../BT Common/bt_command_send.c ../BT Common/bt_hfp.c ../BT Common/bt_line_in.c ../BT Common/bt_multi_spk.c ../BT Common/bt_volume.c ../Codec/sta369bwdsp_handler.c ../../../../../../framework/system/devcon/src/sys_devcon.c ../../../../../../framework/system/devcon/src/sys_devcon_pic32mx.c ../../../../../../framework/system/int/src/sys_int_pic32.c


CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-MX450_BASIC_DEMO0.mk dist/${CND_CONF}/${IMAGE_TYPE}/Bluetooth_Basic_Demo_BM83_EVB.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=32MX450F256L
MP_LINKER_FILE_OPTION=
# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_ext/823550626/drv_i2c_static_buffer_model.o: ../src/system_config/MX450_BASIC_DEMO0/framework/driver/i2c/src/drv_i2c_static_buffer_model.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/823550626" 
	@${RM} ${OBJECTDIR}/_ext/823550626/drv_i2c_static_buffer_model.o.d 
	@${RM} ${OBJECTDIR}/_ext/823550626/drv_i2c_static_buffer_model.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/823550626/drv_i2c_static_buffer_model.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../Codec" -ffunction-sections -Os -I"../bt_application" -I"../BT Common" -I"../../../codec" -I"../../../../../framework" -I"../src" -I"../src/system_config/MX450_BASIC_DEMO0" -I"../src/MX450_BASIC_DEMO0" -I"../../../../../../framework" -I"../src/system_config/MX450_BASIC_DEMO0/framework" -MMD -MF "${OBJECTDIR}/_ext/823550626/drv_i2c_static_buffer_model.o.d" -o ${OBJECTDIR}/_ext/823550626/drv_i2c_static_buffer_model.o ../src/system_config/MX450_BASIC_DEMO0/framework/driver/i2c/src/drv_i2c_static_buffer_model.c   
	
${OBJECTDIR}/_ext/823550626/drv_i2c_mapping.o: ../src/system_config/MX450_BASIC_DEMO0/framework/driver/i2c/src/drv_i2c_mapping.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/823550626" 
	@${RM} ${OBJECTDIR}/_ext/823550626/drv_i2c_mapping.o.d 
	@${RM} ${OBJECTDIR}/_ext/823550626/drv_i2c_mapping.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/823550626/drv_i2c_mapping.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../Codec" -ffunction-sections -Os -I"../bt_application" -I"../BT Common" -I"../../../codec" -I"../../../../../framework" -I"../src" -I"../src/system_config/MX450_BASIC_DEMO0" -I"../src/MX450_BASIC_DEMO0" -I"../../../../../../framework" -I"../src/system_config/MX450_BASIC_DEMO0/framework" -MMD -MF "${OBJECTDIR}/_ext/823550626/drv_i2c_mapping.o.d" -o ${OBJECTDIR}/_ext/823550626/drv_i2c_mapping.o ../src/system_config/MX450_BASIC_DEMO0/framework/driver/i2c/src/drv_i2c_mapping.c   
	
${OBJECTDIR}/_ext/2052027997/drv_tmr_static.o: ../src/system_config/MX450_BASIC_DEMO0/framework/driver/tmr/src/drv_tmr_static.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/2052027997" 
	@${RM} ${OBJECTDIR}/_ext/2052027997/drv_tmr_static.o.d 
	@${RM} ${OBJECTDIR}/_ext/2052027997/drv_tmr_static.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/2052027997/drv_tmr_static.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../Codec" -ffunction-sections -Os -I"../bt_application" -I"../BT Common" -I"../../../codec" -I"../../../../../framework" -I"../src" -I"../src/system_config/MX450_BASIC_DEMO0" -I"../src/MX450_BASIC_DEMO0" -I"../../../../../../framework" -I"../src/system_config/MX450_BASIC_DEMO0/framework" -MMD -MF "${OBJECTDIR}/_ext/2052027997/drv_tmr_static.o.d" -o ${OBJECTDIR}/_ext/2052027997/drv_tmr_static.o ../src/system_config/MX450_BASIC_DEMO0/framework/driver/tmr/src/drv_tmr_static.c   
	
${OBJECTDIR}/_ext/2052027997/drv_tmr_mapping.o: ../src/system_config/MX450_BASIC_DEMO0/framework/driver/tmr/src/drv_tmr_mapping.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/2052027997" 
	@${RM} ${OBJECTDIR}/_ext/2052027997/drv_tmr_mapping.o.d 
	@${RM} ${OBJECTDIR}/_ext/2052027997/drv_tmr_mapping.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/2052027997/drv_tmr_mapping.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../Codec" -ffunction-sections -Os -I"../bt_application" -I"../BT Common" -I"../../../codec" -I"../../../../../framework" -I"../src" -I"../src/system_config/MX450_BASIC_DEMO0" -I"../src/MX450_BASIC_DEMO0" -I"../../../../../../framework" -I"../src/system_config/MX450_BASIC_DEMO0/framework" -MMD -MF "${OBJECTDIR}/_ext/2052027997/drv_tmr_mapping.o.d" -o ${OBJECTDIR}/_ext/2052027997/drv_tmr_mapping.o ../src/system_config/MX450_BASIC_DEMO0/framework/driver/tmr/src/drv_tmr_mapping.c   
	
${OBJECTDIR}/_ext/382828169/drv_usart_mapping.o: ../src/system_config/MX450_BASIC_DEMO0/framework/driver/usart/src/drv_usart_mapping.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/382828169" 
	@${RM} ${OBJECTDIR}/_ext/382828169/drv_usart_mapping.o.d 
	@${RM} ${OBJECTDIR}/_ext/382828169/drv_usart_mapping.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/382828169/drv_usart_mapping.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../Codec" -ffunction-sections -Os -I"../bt_application" -I"../BT Common" -I"../../../codec" -I"../../../../../framework" -I"../src" -I"../src/system_config/MX450_BASIC_DEMO0" -I"../src/MX450_BASIC_DEMO0" -I"../../../../../../framework" -I"../src/system_config/MX450_BASIC_DEMO0/framework" -MMD -MF "${OBJECTDIR}/_ext/382828169/drv_usart_mapping.o.d" -o ${OBJECTDIR}/_ext/382828169/drv_usart_mapping.o ../src/system_config/MX450_BASIC_DEMO0/framework/driver/usart/src/drv_usart_mapping.c   
	
${OBJECTDIR}/_ext/382828169/drv_usart_static.o: ../src/system_config/MX450_BASIC_DEMO0/framework/driver/usart/src/drv_usart_static.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/382828169" 
	@${RM} ${OBJECTDIR}/_ext/382828169/drv_usart_static.o.d 
	@${RM} ${OBJECTDIR}/_ext/382828169/drv_usart_static.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/382828169/drv_usart_static.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../Codec" -ffunction-sections -Os -I"../bt_application" -I"../BT Common" -I"../../../codec" -I"../../../../../framework" -I"../src" -I"../src/system_config/MX450_BASIC_DEMO0" -I"../src/MX450_BASIC_DEMO0" -I"../../../../../../framework" -I"../src/system_config/MX450_BASIC_DEMO0/framework" -MMD -MF "${OBJECTDIR}/_ext/382828169/drv_usart_static.o.d" -o ${OBJECTDIR}/_ext/382828169/drv_usart_static.o ../src/system_config/MX450_BASIC_DEMO0/framework/driver/usart/src/drv_usart_static.c   
	
${OBJECTDIR}/_ext/382828169/drv_usart_static_byte_model.o: ../src/system_config/MX450_BASIC_DEMO0/framework/driver/usart/src/drv_usart_static_byte_model.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/382828169" 
	@${RM} ${OBJECTDIR}/_ext/382828169/drv_usart_static_byte_model.o.d 
	@${RM} ${OBJECTDIR}/_ext/382828169/drv_usart_static_byte_model.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/382828169/drv_usart_static_byte_model.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../Codec" -ffunction-sections -Os -I"../bt_application" -I"../BT Common" -I"../../../codec" -I"../../../../../framework" -I"../src" -I"../src/system_config/MX450_BASIC_DEMO0" -I"../src/MX450_BASIC_DEMO0" -I"../../../../../../framework" -I"../src/system_config/MX450_BASIC_DEMO0/framework" -MMD -MF "${OBJECTDIR}/_ext/382828169/drv_usart_static_byte_model.o.d" -o ${OBJECTDIR}/_ext/382828169/drv_usart_static_byte_model.o ../src/system_config/MX450_BASIC_DEMO0/framework/driver/usart/src/drv_usart_static_byte_model.c   
	
${OBJECTDIR}/_ext/195891987/sys_clk_static.o: ../src/system_config/MX450_BASIC_DEMO0/framework/system/clk/src/sys_clk_static.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/195891987" 
	@${RM} ${OBJECTDIR}/_ext/195891987/sys_clk_static.o.d 
	@${RM} ${OBJECTDIR}/_ext/195891987/sys_clk_static.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/195891987/sys_clk_static.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../Codec" -ffunction-sections -Os -I"../bt_application" -I"../BT Common" -I"../../../codec" -I"../../../../../framework" -I"../src" -I"../src/system_config/MX450_BASIC_DEMO0" -I"../src/MX450_BASIC_DEMO0" -I"../../../../../../framework" -I"../src/system_config/MX450_BASIC_DEMO0/framework" -MMD -MF "${OBJECTDIR}/_ext/195891987/sys_clk_static.o.d" -o ${OBJECTDIR}/_ext/195891987/sys_clk_static.o ../src/system_config/MX450_BASIC_DEMO0/framework/system/clk/src/sys_clk_static.c   
	
${OBJECTDIR}/_ext/766220707/sys_ports_static.o: ../src/system_config/MX450_BASIC_DEMO0/framework/system/ports/src/sys_ports_static.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/766220707" 
	@${RM} ${OBJECTDIR}/_ext/766220707/sys_ports_static.o.d 
	@${RM} ${OBJECTDIR}/_ext/766220707/sys_ports_static.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/766220707/sys_ports_static.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../Codec" -ffunction-sections -Os -I"../bt_application" -I"../BT Common" -I"../../../codec" -I"../../../../../framework" -I"../src" -I"../src/system_config/MX450_BASIC_DEMO0" -I"../src/MX450_BASIC_DEMO0" -I"../../../../../../framework" -I"../src/system_config/MX450_BASIC_DEMO0/framework" -MMD -MF "${OBJECTDIR}/_ext/766220707/sys_ports_static.o.d" -o ${OBJECTDIR}/_ext/766220707/sys_ports_static.o ../src/system_config/MX450_BASIC_DEMO0/framework/system/ports/src/sys_ports_static.c   
	
${OBJECTDIR}/_ext/1823359670/system_init.o: ../src/system_config/MX450_BASIC_DEMO0/system_init.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1823359670" 
	@${RM} ${OBJECTDIR}/_ext/1823359670/system_init.o.d 
	@${RM} ${OBJECTDIR}/_ext/1823359670/system_init.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1823359670/system_init.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../Codec" -ffunction-sections -Os -I"../bt_application" -I"../BT Common" -I"../../../codec" -I"../../../../../framework" -I"../src" -I"../src/system_config/MX450_BASIC_DEMO0" -I"../src/MX450_BASIC_DEMO0" -I"../../../../../../framework" -I"../src/system_config/MX450_BASIC_DEMO0/framework" -MMD -MF "${OBJECTDIR}/_ext/1823359670/system_init.o.d" -o ${OBJECTDIR}/_ext/1823359670/system_init.o ../src/system_config/MX450_BASIC_DEMO0/system_init.c   
	
${OBJECTDIR}/_ext/1823359670/system_interrupt.o: ../src/system_config/MX450_BASIC_DEMO0/system_interrupt.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1823359670" 
	@${RM} ${OBJECTDIR}/_ext/1823359670/system_interrupt.o.d 
	@${RM} ${OBJECTDIR}/_ext/1823359670/system_interrupt.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1823359670/system_interrupt.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../Codec" -ffunction-sections -Os -I"../bt_application" -I"../BT Common" -I"../../../codec" -I"../../../../../framework" -I"../src" -I"../src/system_config/MX450_BASIC_DEMO0" -I"../src/MX450_BASIC_DEMO0" -I"../../../../../../framework" -I"../src/system_config/MX450_BASIC_DEMO0/framework" -MMD -MF "${OBJECTDIR}/_ext/1823359670/system_interrupt.o.d" -o ${OBJECTDIR}/_ext/1823359670/system_interrupt.o ../src/system_config/MX450_BASIC_DEMO0/system_interrupt.c   
	
${OBJECTDIR}/_ext/1823359670/system_exceptions.o: ../src/system_config/MX450_BASIC_DEMO0/system_exceptions.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1823359670" 
	@${RM} ${OBJECTDIR}/_ext/1823359670/system_exceptions.o.d 
	@${RM} ${OBJECTDIR}/_ext/1823359670/system_exceptions.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1823359670/system_exceptions.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../Codec" -ffunction-sections -Os -I"../bt_application" -I"../BT Common" -I"../../../codec" -I"../../../../../framework" -I"../src" -I"../src/system_config/MX450_BASIC_DEMO0" -I"../src/MX450_BASIC_DEMO0" -I"../../../../../../framework" -I"../src/system_config/MX450_BASIC_DEMO0/framework" -MMD -MF "${OBJECTDIR}/_ext/1823359670/system_exceptions.o.d" -o ${OBJECTDIR}/_ext/1823359670/system_exceptions.o ../src/system_config/MX450_BASIC_DEMO0/system_exceptions.c   
	
${OBJECTDIR}/_ext/1823359670/system_tasks.o: ../src/system_config/MX450_BASIC_DEMO0/system_tasks.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1823359670" 
	@${RM} ${OBJECTDIR}/_ext/1823359670/system_tasks.o.d 
	@${RM} ${OBJECTDIR}/_ext/1823359670/system_tasks.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1823359670/system_tasks.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../Codec" -ffunction-sections -Os -I"../bt_application" -I"../BT Common" -I"../../../codec" -I"../../../../../framework" -I"../src" -I"../src/system_config/MX450_BASIC_DEMO0" -I"../src/MX450_BASIC_DEMO0" -I"../../../../../../framework" -I"../src/system_config/MX450_BASIC_DEMO0/framework" -MMD -MF "${OBJECTDIR}/_ext/1823359670/system_tasks.o.d" -o ${OBJECTDIR}/_ext/1823359670/system_tasks.o ../src/system_config/MX450_BASIC_DEMO0/system_tasks.c   
	
${OBJECTDIR}/_ext/1360937237/app.o: ../src/app.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/app.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/app.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/app.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../Codec" -ffunction-sections -Os -I"../bt_application" -I"../BT Common" -I"../../../codec" -I"../../../../../framework" -I"../src" -I"../src/system_config/MX450_BASIC_DEMO0" -I"../src/MX450_BASIC_DEMO0" -I"../../../../../../framework" -I"../src/system_config/MX450_BASIC_DEMO0/framework" -MMD -MF "${OBJECTDIR}/_ext/1360937237/app.o.d" -o ${OBJECTDIR}/_ext/1360937237/app.o ../src/app.c   
	
${OBJECTDIR}/_ext/1360937237/main.o: ../src/main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/main.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../Codec" -ffunction-sections -Os -I"../bt_application" -I"../BT Common" -I"../../../codec" -I"../../../../../framework" -I"../src" -I"../src/system_config/MX450_BASIC_DEMO0" -I"../src/MX450_BASIC_DEMO0" -I"../../../../../../framework" -I"../src/system_config/MX450_BASIC_DEMO0/framework" -MMD -MF "${OBJECTDIR}/_ext/1360937237/main.o.d" -o ${OBJECTDIR}/_ext/1360937237/main.o ../src/main.c   
	
${OBJECTDIR}/_ext/1205520658/bt_app.o: ../bt_application/bt_app.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1205520658" 
	@${RM} ${OBJECTDIR}/_ext/1205520658/bt_app.o.d 
	@${RM} ${OBJECTDIR}/_ext/1205520658/bt_app.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1205520658/bt_app.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../Codec" -ffunction-sections -Os -I"../bt_application" -I"../BT Common" -I"../../../codec" -I"../../../../../framework" -I"../src" -I"../src/system_config/MX450_BASIC_DEMO0" -I"../src/MX450_BASIC_DEMO0" -I"../../../../../../framework" -I"../src/system_config/MX450_BASIC_DEMO0/framework" -MMD -MF "${OBJECTDIR}/_ext/1205520658/bt_app.o.d" -o ${OBJECTDIR}/_ext/1205520658/bt_app.o ../bt_application/bt_app.c   
	
${OBJECTDIR}/_ext/1205520658/bt_data.o: ../bt_application/bt_data.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1205520658" 
	@${RM} ${OBJECTDIR}/_ext/1205520658/bt_data.o.d 
	@${RM} ${OBJECTDIR}/_ext/1205520658/bt_data.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1205520658/bt_data.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../Codec" -ffunction-sections -Os -I"../bt_application" -I"../BT Common" -I"../../../codec" -I"../../../../../framework" -I"../src" -I"../src/system_config/MX450_BASIC_DEMO0" -I"../src/MX450_BASIC_DEMO0" -I"../../../../../../framework" -I"../src/system_config/MX450_BASIC_DEMO0/framework" -MMD -MF "${OBJECTDIR}/_ext/1205520658/bt_data.o.d" -o ${OBJECTDIR}/_ext/1205520658/bt_data.o ../bt_application/bt_data.c   
	
${OBJECTDIR}/_ext/1205520658/bt_hardware_profile.o: ../bt_application/bt_hardware_profile.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1205520658" 
	@${RM} ${OBJECTDIR}/_ext/1205520658/bt_hardware_profile.o.d 
	@${RM} ${OBJECTDIR}/_ext/1205520658/bt_hardware_profile.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1205520658/bt_hardware_profile.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../Codec" -ffunction-sections -Os -I"../bt_application" -I"../BT Common" -I"../../../codec" -I"../../../../../framework" -I"../src" -I"../src/system_config/MX450_BASIC_DEMO0" -I"../src/MX450_BASIC_DEMO0" -I"../../../../../../framework" -I"../src/system_config/MX450_BASIC_DEMO0/framework" -MMD -MF "${OBJECTDIR}/_ext/1205520658/bt_hardware_profile.o.d" -o ${OBJECTDIR}/_ext/1205520658/bt_hardware_profile.o ../bt_application/bt_hardware_profile.c   
	
${OBJECTDIR}/_ext/1205520658/key.o: ../bt_application/key.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1205520658" 
	@${RM} ${OBJECTDIR}/_ext/1205520658/key.o.d 
	@${RM} ${OBJECTDIR}/_ext/1205520658/key.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1205520658/key.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../Codec" -ffunction-sections -Os -I"../bt_application" -I"../BT Common" -I"../../../codec" -I"../../../../../framework" -I"../src" -I"../src/system_config/MX450_BASIC_DEMO0" -I"../src/MX450_BASIC_DEMO0" -I"../../../../../../framework" -I"../src/system_config/MX450_BASIC_DEMO0/framework" -MMD -MF "${OBJECTDIR}/_ext/1205520658/key.o.d" -o ${OBJECTDIR}/_ext/1205520658/key.o ../bt_application/key.c   
	
${OBJECTDIR}/_ext/1205520658/key_handler.o: ../bt_application/key_handler.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1205520658" 
	@${RM} ${OBJECTDIR}/_ext/1205520658/key_handler.o.d 
	@${RM} ${OBJECTDIR}/_ext/1205520658/key_handler.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1205520658/key_handler.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../Codec" -ffunction-sections -Os -I"../bt_application" -I"../BT Common" -I"../../../codec" -I"../../../../../framework" -I"../src" -I"../src/system_config/MX450_BASIC_DEMO0" -I"../src/MX450_BASIC_DEMO0" -I"../../../../../../framework" -I"../src/system_config/MX450_BASIC_DEMO0/framework" -MMD -MF "${OBJECTDIR}/_ext/1205520658/key_handler.o.d" -o ${OBJECTDIR}/_ext/1205520658/key_handler.o ../bt_application/key_handler.c   
	
${OBJECTDIR}/_ext/1205520658/led.o: ../bt_application/led.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1205520658" 
	@${RM} ${OBJECTDIR}/_ext/1205520658/led.o.d 
	@${RM} ${OBJECTDIR}/_ext/1205520658/led.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1205520658/led.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../Codec" -ffunction-sections -Os -I"../bt_application" -I"../BT Common" -I"../../../codec" -I"../../../../../framework" -I"../src" -I"../src/system_config/MX450_BASIC_DEMO0" -I"../src/MX450_BASIC_DEMO0" -I"../../../../../../framework" -I"../src/system_config/MX450_BASIC_DEMO0/framework" -MMD -MF "${OBJECTDIR}/_ext/1205520658/led.o.d" -o ${OBJECTDIR}/_ext/1205520658/led.o ../bt_application/led.c   
	
${OBJECTDIR}/_ext/1205520658/timer.o: ../bt_application/timer.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1205520658" 
	@${RM} ${OBJECTDIR}/_ext/1205520658/timer.o.d 
	@${RM} ${OBJECTDIR}/_ext/1205520658/timer.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1205520658/timer.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../Codec" -ffunction-sections -Os -I"../bt_application" -I"../BT Common" -I"../../../codec" -I"../../../../../framework" -I"../src" -I"../src/system_config/MX450_BASIC_DEMO0" -I"../src/MX450_BASIC_DEMO0" -I"../../../../../../framework" -I"../src/system_config/MX450_BASIC_DEMO0/framework" -MMD -MF "${OBJECTDIR}/_ext/1205520658/timer.o.d" -o ${OBJECTDIR}/_ext/1205520658/timer.o ../bt_application/timer.c   
	
${OBJECTDIR}/_ext/1634889738/bt_a2dp.o: ../BT\ Common/bt_a2dp.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1634889738" 
	@${RM} ${OBJECTDIR}/_ext/1634889738/bt_a2dp.o.d 
	@${RM} ${OBJECTDIR}/_ext/1634889738/bt_a2dp.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1634889738/bt_a2dp.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../Codec" -ffunction-sections -Os -I"../bt_application" -I"../BT Common" -I"../../../codec" -I"../../../../../framework" -I"../src" -I"../src/system_config/MX450_BASIC_DEMO0" -I"../src/MX450_BASIC_DEMO0" -I"../../../../../../framework" -I"../src/system_config/MX450_BASIC_DEMO0/framework" -MMD -MF "${OBJECTDIR}/_ext/1634889738/bt_a2dp.o.d" -o ${OBJECTDIR}/_ext/1634889738/bt_a2dp.o "../BT Common/bt_a2dp.c"   
	
${OBJECTDIR}/_ext/1634889738/bt_command_decode.o: ../BT\ Common/bt_command_decode.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1634889738" 
	@${RM} ${OBJECTDIR}/_ext/1634889738/bt_command_decode.o.d 
	@${RM} ${OBJECTDIR}/_ext/1634889738/bt_command_decode.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1634889738/bt_command_decode.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../Codec" -ffunction-sections -Os -I"../bt_application" -I"../BT Common" -I"../../../codec" -I"../../../../../framework" -I"../src" -I"../src/system_config/MX450_BASIC_DEMO0" -I"../src/MX450_BASIC_DEMO0" -I"../../../../../../framework" -I"../src/system_config/MX450_BASIC_DEMO0/framework" -MMD -MF "${OBJECTDIR}/_ext/1634889738/bt_command_decode.o.d" -o ${OBJECTDIR}/_ext/1634889738/bt_command_decode.o "../BT Common/bt_command_decode.c"   
	
${OBJECTDIR}/_ext/1634889738/bt_command_send.o: ../BT\ Common/bt_command_send.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1634889738" 
	@${RM} ${OBJECTDIR}/_ext/1634889738/bt_command_send.o.d 
	@${RM} ${OBJECTDIR}/_ext/1634889738/bt_command_send.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1634889738/bt_command_send.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../Codec" -ffunction-sections -Os -I"../bt_application" -I"../BT Common" -I"../../../codec" -I"../../../../../framework" -I"../src" -I"../src/system_config/MX450_BASIC_DEMO0" -I"../src/MX450_BASIC_DEMO0" -I"../../../../../../framework" -I"../src/system_config/MX450_BASIC_DEMO0/framework" -MMD -MF "${OBJECTDIR}/_ext/1634889738/bt_command_send.o.d" -o ${OBJECTDIR}/_ext/1634889738/bt_command_send.o "../BT Common/bt_command_send.c"   
	
${OBJECTDIR}/_ext/1634889738/bt_hfp.o: ../BT\ Common/bt_hfp.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1634889738" 
	@${RM} ${OBJECTDIR}/_ext/1634889738/bt_hfp.o.d 
	@${RM} ${OBJECTDIR}/_ext/1634889738/bt_hfp.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1634889738/bt_hfp.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../Codec" -ffunction-sections -Os -I"../bt_application" -I"../BT Common" -I"../../../codec" -I"../../../../../framework" -I"../src" -I"../src/system_config/MX450_BASIC_DEMO0" -I"../src/MX450_BASIC_DEMO0" -I"../../../../../../framework" -I"../src/system_config/MX450_BASIC_DEMO0/framework" -MMD -MF "${OBJECTDIR}/_ext/1634889738/bt_hfp.o.d" -o ${OBJECTDIR}/_ext/1634889738/bt_hfp.o "../BT Common/bt_hfp.c"   
	
${OBJECTDIR}/_ext/1634889738/bt_line_in.o: ../BT\ Common/bt_line_in.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1634889738" 
	@${RM} ${OBJECTDIR}/_ext/1634889738/bt_line_in.o.d 
	@${RM} ${OBJECTDIR}/_ext/1634889738/bt_line_in.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1634889738/bt_line_in.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../Codec" -ffunction-sections -Os -I"../bt_application" -I"../BT Common" -I"../../../codec" -I"../../../../../framework" -I"../src" -I"../src/system_config/MX450_BASIC_DEMO0" -I"../src/MX450_BASIC_DEMO0" -I"../../../../../../framework" -I"../src/system_config/MX450_BASIC_DEMO0/framework" -MMD -MF "${OBJECTDIR}/_ext/1634889738/bt_line_in.o.d" -o ${OBJECTDIR}/_ext/1634889738/bt_line_in.o "../BT Common/bt_line_in.c"   
	
${OBJECTDIR}/_ext/1634889738/bt_multi_spk.o: ../BT\ Common/bt_multi_spk.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1634889738" 
	@${RM} ${OBJECTDIR}/_ext/1634889738/bt_multi_spk.o.d 
	@${RM} ${OBJECTDIR}/_ext/1634889738/bt_multi_spk.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1634889738/bt_multi_spk.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../Codec" -ffunction-sections -Os -I"../bt_application" -I"../BT Common" -I"../../../codec" -I"../../../../../framework" -I"../src" -I"../src/system_config/MX450_BASIC_DEMO0" -I"../src/MX450_BASIC_DEMO0" -I"../../../../../../framework" -I"../src/system_config/MX450_BASIC_DEMO0/framework" -MMD -MF "${OBJECTDIR}/_ext/1634889738/bt_multi_spk.o.d" -o ${OBJECTDIR}/_ext/1634889738/bt_multi_spk.o "../BT Common/bt_multi_spk.c"   
	
${OBJECTDIR}/_ext/1634889738/bt_volume.o: ../BT\ Common/bt_volume.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1634889738" 
	@${RM} ${OBJECTDIR}/_ext/1634889738/bt_volume.o.d 
	@${RM} ${OBJECTDIR}/_ext/1634889738/bt_volume.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1634889738/bt_volume.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../Codec" -ffunction-sections -Os -I"../bt_application" -I"../BT Common" -I"../../../codec" -I"../../../../../framework" -I"../src" -I"../src/system_config/MX450_BASIC_DEMO0" -I"../src/MX450_BASIC_DEMO0" -I"../../../../../../framework" -I"../src/system_config/MX450_BASIC_DEMO0/framework" -MMD -MF "${OBJECTDIR}/_ext/1634889738/bt_volume.o.d" -o ${OBJECTDIR}/_ext/1634889738/bt_volume.o "../BT Common/bt_volume.c"   
	
${OBJECTDIR}/_ext/2146212583/sta369bwdsp_handler.o: ../Codec/sta369bwdsp_handler.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/2146212583" 
	@${RM} ${OBJECTDIR}/_ext/2146212583/sta369bwdsp_handler.o.d 
	@${RM} ${OBJECTDIR}/_ext/2146212583/sta369bwdsp_handler.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/2146212583/sta369bwdsp_handler.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../Codec" -ffunction-sections -Os -I"../bt_application" -I"../BT Common" -I"../../../codec" -I"../../../../../framework" -I"../src" -I"../src/system_config/MX450_BASIC_DEMO0" -I"../src/MX450_BASIC_DEMO0" -I"../../../../../../framework" -I"../src/system_config/MX450_BASIC_DEMO0/framework" -MMD -MF "${OBJECTDIR}/_ext/2146212583/sta369bwdsp_handler.o.d" -o ${OBJECTDIR}/_ext/2146212583/sta369bwdsp_handler.o ../Codec/sta369bwdsp_handler.c   
	
${OBJECTDIR}/_ext/912498863/sys_devcon.o: ../../../../../../framework/system/devcon/src/sys_devcon.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/912498863" 
	@${RM} ${OBJECTDIR}/_ext/912498863/sys_devcon.o.d 
	@${RM} ${OBJECTDIR}/_ext/912498863/sys_devcon.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/912498863/sys_devcon.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../Codec" -ffunction-sections -Os -I"../bt_application" -I"../BT Common" -I"../../../codec" -I"../../../../../framework" -I"../src" -I"../src/system_config/MX450_BASIC_DEMO0" -I"../src/MX450_BASIC_DEMO0" -I"../../../../../../framework" -I"../src/system_config/MX450_BASIC_DEMO0/framework" -MMD -MF "${OBJECTDIR}/_ext/912498863/sys_devcon.o.d" -o ${OBJECTDIR}/_ext/912498863/sys_devcon.o ../../../../../../framework/system/devcon/src/sys_devcon.c   
	
${OBJECTDIR}/_ext/912498863/sys_devcon_pic32mx.o: ../../../../../../framework/system/devcon/src/sys_devcon_pic32mx.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/912498863" 
	@${RM} ${OBJECTDIR}/_ext/912498863/sys_devcon_pic32mx.o.d 
	@${RM} ${OBJECTDIR}/_ext/912498863/sys_devcon_pic32mx.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/912498863/sys_devcon_pic32mx.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../Codec" -ffunction-sections -Os -I"../bt_application" -I"../BT Common" -I"../../../codec" -I"../../../../../framework" -I"../src" -I"../src/system_config/MX450_BASIC_DEMO0" -I"../src/MX450_BASIC_DEMO0" -I"../../../../../../framework" -I"../src/system_config/MX450_BASIC_DEMO0/framework" -MMD -MF "${OBJECTDIR}/_ext/912498863/sys_devcon_pic32mx.o.d" -o ${OBJECTDIR}/_ext/912498863/sys_devcon_pic32mx.o ../../../../../../framework/system/devcon/src/sys_devcon_pic32mx.c   
	
${OBJECTDIR}/_ext/711155467/sys_int_pic32.o: ../../../../../../framework/system/int/src/sys_int_pic32.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/711155467" 
	@${RM} ${OBJECTDIR}/_ext/711155467/sys_int_pic32.o.d 
	@${RM} ${OBJECTDIR}/_ext/711155467/sys_int_pic32.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/711155467/sys_int_pic32.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../Codec" -ffunction-sections -Os -I"../bt_application" -I"../BT Common" -I"../../../codec" -I"../../../../../framework" -I"../src" -I"../src/system_config/MX450_BASIC_DEMO0" -I"../src/MX450_BASIC_DEMO0" -I"../../../../../../framework" -I"../src/system_config/MX450_BASIC_DEMO0/framework" -MMD -MF "${OBJECTDIR}/_ext/711155467/sys_int_pic32.o.d" -o ${OBJECTDIR}/_ext/711155467/sys_int_pic32.o ../../../../../../framework/system/int/src/sys_int_pic32.c   
	
else
${OBJECTDIR}/_ext/823550626/drv_i2c_static_buffer_model.o: ../src/system_config/MX450_BASIC_DEMO0/framework/driver/i2c/src/drv_i2c_static_buffer_model.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/823550626" 
	@${RM} ${OBJECTDIR}/_ext/823550626/drv_i2c_static_buffer_model.o.d 
	@${RM} ${OBJECTDIR}/_ext/823550626/drv_i2c_static_buffer_model.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/823550626/drv_i2c_static_buffer_model.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../Codec" -ffunction-sections -Os -I"../bt_application" -I"../BT Common" -I"../../../codec" -I"../../../../../framework" -I"../src" -I"../src/system_config/MX450_BASIC_DEMO0" -I"../src/MX450_BASIC_DEMO0" -I"../../../../../../framework" -I"../src/system_config/MX450_BASIC_DEMO0/framework" -MMD -MF "${OBJECTDIR}/_ext/823550626/drv_i2c_static_buffer_model.o.d" -o ${OBJECTDIR}/_ext/823550626/drv_i2c_static_buffer_model.o ../src/system_config/MX450_BASIC_DEMO0/framework/driver/i2c/src/drv_i2c_static_buffer_model.c   
	
${OBJECTDIR}/_ext/823550626/drv_i2c_mapping.o: ../src/system_config/MX450_BASIC_DEMO0/framework/driver/i2c/src/drv_i2c_mapping.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/823550626" 
	@${RM} ${OBJECTDIR}/_ext/823550626/drv_i2c_mapping.o.d 
	@${RM} ${OBJECTDIR}/_ext/823550626/drv_i2c_mapping.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/823550626/drv_i2c_mapping.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../Codec" -ffunction-sections -Os -I"../bt_application" -I"../BT Common" -I"../../../codec" -I"../../../../../framework" -I"../src" -I"../src/system_config/MX450_BASIC_DEMO0" -I"../src/MX450_BASIC_DEMO0" -I"../../../../../../framework" -I"../src/system_config/MX450_BASIC_DEMO0/framework" -MMD -MF "${OBJECTDIR}/_ext/823550626/drv_i2c_mapping.o.d" -o ${OBJECTDIR}/_ext/823550626/drv_i2c_mapping.o ../src/system_config/MX450_BASIC_DEMO0/framework/driver/i2c/src/drv_i2c_mapping.c   
	
${OBJECTDIR}/_ext/2052027997/drv_tmr_static.o: ../src/system_config/MX450_BASIC_DEMO0/framework/driver/tmr/src/drv_tmr_static.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/2052027997" 
	@${RM} ${OBJECTDIR}/_ext/2052027997/drv_tmr_static.o.d 
	@${RM} ${OBJECTDIR}/_ext/2052027997/drv_tmr_static.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/2052027997/drv_tmr_static.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../Codec" -ffunction-sections -Os -I"../bt_application" -I"../BT Common" -I"../../../codec" -I"../../../../../framework" -I"../src" -I"../src/system_config/MX450_BASIC_DEMO0" -I"../src/MX450_BASIC_DEMO0" -I"../../../../../../framework" -I"../src/system_config/MX450_BASIC_DEMO0/framework" -MMD -MF "${OBJECTDIR}/_ext/2052027997/drv_tmr_static.o.d" -o ${OBJECTDIR}/_ext/2052027997/drv_tmr_static.o ../src/system_config/MX450_BASIC_DEMO0/framework/driver/tmr/src/drv_tmr_static.c   
	
${OBJECTDIR}/_ext/2052027997/drv_tmr_mapping.o: ../src/system_config/MX450_BASIC_DEMO0/framework/driver/tmr/src/drv_tmr_mapping.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/2052027997" 
	@${RM} ${OBJECTDIR}/_ext/2052027997/drv_tmr_mapping.o.d 
	@${RM} ${OBJECTDIR}/_ext/2052027997/drv_tmr_mapping.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/2052027997/drv_tmr_mapping.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../Codec" -ffunction-sections -Os -I"../bt_application" -I"../BT Common" -I"../../../codec" -I"../../../../../framework" -I"../src" -I"../src/system_config/MX450_BASIC_DEMO0" -I"../src/MX450_BASIC_DEMO0" -I"../../../../../../framework" -I"../src/system_config/MX450_BASIC_DEMO0/framework" -MMD -MF "${OBJECTDIR}/_ext/2052027997/drv_tmr_mapping.o.d" -o ${OBJECTDIR}/_ext/2052027997/drv_tmr_mapping.o ../src/system_config/MX450_BASIC_DEMO0/framework/driver/tmr/src/drv_tmr_mapping.c   
	
${OBJECTDIR}/_ext/382828169/drv_usart_mapping.o: ../src/system_config/MX450_BASIC_DEMO0/framework/driver/usart/src/drv_usart_mapping.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/382828169" 
	@${RM} ${OBJECTDIR}/_ext/382828169/drv_usart_mapping.o.d 
	@${RM} ${OBJECTDIR}/_ext/382828169/drv_usart_mapping.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/382828169/drv_usart_mapping.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../Codec" -ffunction-sections -Os -I"../bt_application" -I"../BT Common" -I"../../../codec" -I"../../../../../framework" -I"../src" -I"../src/system_config/MX450_BASIC_DEMO0" -I"../src/MX450_BASIC_DEMO0" -I"../../../../../../framework" -I"../src/system_config/MX450_BASIC_DEMO0/framework" -MMD -MF "${OBJECTDIR}/_ext/382828169/drv_usart_mapping.o.d" -o ${OBJECTDIR}/_ext/382828169/drv_usart_mapping.o ../src/system_config/MX450_BASIC_DEMO0/framework/driver/usart/src/drv_usart_mapping.c   
	
${OBJECTDIR}/_ext/382828169/drv_usart_static.o: ../src/system_config/MX450_BASIC_DEMO0/framework/driver/usart/src/drv_usart_static.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/382828169" 
	@${RM} ${OBJECTDIR}/_ext/382828169/drv_usart_static.o.d 
	@${RM} ${OBJECTDIR}/_ext/382828169/drv_usart_static.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/382828169/drv_usart_static.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../Codec" -ffunction-sections -Os -I"../bt_application" -I"../BT Common" -I"../../../codec" -I"../../../../../framework" -I"../src" -I"../src/system_config/MX450_BASIC_DEMO0" -I"../src/MX450_BASIC_DEMO0" -I"../../../../../../framework" -I"../src/system_config/MX450_BASIC_DEMO0/framework" -MMD -MF "${OBJECTDIR}/_ext/382828169/drv_usart_static.o.d" -o ${OBJECTDIR}/_ext/382828169/drv_usart_static.o ../src/system_config/MX450_BASIC_DEMO0/framework/driver/usart/src/drv_usart_static.c   
	
${OBJECTDIR}/_ext/382828169/drv_usart_static_byte_model.o: ../src/system_config/MX450_BASIC_DEMO0/framework/driver/usart/src/drv_usart_static_byte_model.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/382828169" 
	@${RM} ${OBJECTDIR}/_ext/382828169/drv_usart_static_byte_model.o.d 
	@${RM} ${OBJECTDIR}/_ext/382828169/drv_usart_static_byte_model.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/382828169/drv_usart_static_byte_model.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../Codec" -ffunction-sections -Os -I"../bt_application" -I"../BT Common" -I"../../../codec" -I"../../../../../framework" -I"../src" -I"../src/system_config/MX450_BASIC_DEMO0" -I"../src/MX450_BASIC_DEMO0" -I"../../../../../../framework" -I"../src/system_config/MX450_BASIC_DEMO0/framework" -MMD -MF "${OBJECTDIR}/_ext/382828169/drv_usart_static_byte_model.o.d" -o ${OBJECTDIR}/_ext/382828169/drv_usart_static_byte_model.o ../src/system_config/MX450_BASIC_DEMO0/framework/driver/usart/src/drv_usart_static_byte_model.c   
	
${OBJECTDIR}/_ext/195891987/sys_clk_static.o: ../src/system_config/MX450_BASIC_DEMO0/framework/system/clk/src/sys_clk_static.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/195891987" 
	@${RM} ${OBJECTDIR}/_ext/195891987/sys_clk_static.o.d 
	@${RM} ${OBJECTDIR}/_ext/195891987/sys_clk_static.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/195891987/sys_clk_static.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../Codec" -ffunction-sections -Os -I"../bt_application" -I"../BT Common" -I"../../../codec" -I"../../../../../framework" -I"../src" -I"../src/system_config/MX450_BASIC_DEMO0" -I"../src/MX450_BASIC_DEMO0" -I"../../../../../../framework" -I"../src/system_config/MX450_BASIC_DEMO0/framework" -MMD -MF "${OBJECTDIR}/_ext/195891987/sys_clk_static.o.d" -o ${OBJECTDIR}/_ext/195891987/sys_clk_static.o ../src/system_config/MX450_BASIC_DEMO0/framework/system/clk/src/sys_clk_static.c   
	
${OBJECTDIR}/_ext/766220707/sys_ports_static.o: ../src/system_config/MX450_BASIC_DEMO0/framework/system/ports/src/sys_ports_static.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/766220707" 
	@${RM} ${OBJECTDIR}/_ext/766220707/sys_ports_static.o.d 
	@${RM} ${OBJECTDIR}/_ext/766220707/sys_ports_static.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/766220707/sys_ports_static.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../Codec" -ffunction-sections -Os -I"../bt_application" -I"../BT Common" -I"../../../codec" -I"../../../../../framework" -I"../src" -I"../src/system_config/MX450_BASIC_DEMO0" -I"../src/MX450_BASIC_DEMO0" -I"../../../../../../framework" -I"../src/system_config/MX450_BASIC_DEMO0/framework" -MMD -MF "${OBJECTDIR}/_ext/766220707/sys_ports_static.o.d" -o ${OBJECTDIR}/_ext/766220707/sys_ports_static.o ../src/system_config/MX450_BASIC_DEMO0/framework/system/ports/src/sys_ports_static.c   
	
${OBJECTDIR}/_ext/1823359670/system_init.o: ../src/system_config/MX450_BASIC_DEMO0/system_init.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1823359670" 
	@${RM} ${OBJECTDIR}/_ext/1823359670/system_init.o.d 
	@${RM} ${OBJECTDIR}/_ext/1823359670/system_init.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1823359670/system_init.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../Codec" -ffunction-sections -Os -I"../bt_application" -I"../BT Common" -I"../../../codec" -I"../../../../../framework" -I"../src" -I"../src/system_config/MX450_BASIC_DEMO0" -I"../src/MX450_BASIC_DEMO0" -I"../../../../../../framework" -I"../src/system_config/MX450_BASIC_DEMO0/framework" -MMD -MF "${OBJECTDIR}/_ext/1823359670/system_init.o.d" -o ${OBJECTDIR}/_ext/1823359670/system_init.o ../src/system_config/MX450_BASIC_DEMO0/system_init.c   
	
${OBJECTDIR}/_ext/1823359670/system_interrupt.o: ../src/system_config/MX450_BASIC_DEMO0/system_interrupt.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1823359670" 
	@${RM} ${OBJECTDIR}/_ext/1823359670/system_interrupt.o.d 
	@${RM} ${OBJECTDIR}/_ext/1823359670/system_interrupt.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1823359670/system_interrupt.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../Codec" -ffunction-sections -Os -I"../bt_application" -I"../BT Common" -I"../../../codec" -I"../../../../../framework" -I"../src" -I"../src/system_config/MX450_BASIC_DEMO0" -I"../src/MX450_BASIC_DEMO0" -I"../../../../../../framework" -I"../src/system_config/MX450_BASIC_DEMO0/framework" -MMD -MF "${OBJECTDIR}/_ext/1823359670/system_interrupt.o.d" -o ${OBJECTDIR}/_ext/1823359670/system_interrupt.o ../src/system_config/MX450_BASIC_DEMO0/system_interrupt.c   
	
${OBJECTDIR}/_ext/1823359670/system_exceptions.o: ../src/system_config/MX450_BASIC_DEMO0/system_exceptions.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1823359670" 
	@${RM} ${OBJECTDIR}/_ext/1823359670/system_exceptions.o.d 
	@${RM} ${OBJECTDIR}/_ext/1823359670/system_exceptions.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1823359670/system_exceptions.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../Codec" -ffunction-sections -Os -I"../bt_application" -I"../BT Common" -I"../../../codec" -I"../../../../../framework" -I"../src" -I"../src/system_config/MX450_BASIC_DEMO0" -I"../src/MX450_BASIC_DEMO0" -I"../../../../../../framework" -I"../src/system_config/MX450_BASIC_DEMO0/framework" -MMD -MF "${OBJECTDIR}/_ext/1823359670/system_exceptions.o.d" -o ${OBJECTDIR}/_ext/1823359670/system_exceptions.o ../src/system_config/MX450_BASIC_DEMO0/system_exceptions.c   
	
${OBJECTDIR}/_ext/1823359670/system_tasks.o: ../src/system_config/MX450_BASIC_DEMO0/system_tasks.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1823359670" 
	@${RM} ${OBJECTDIR}/_ext/1823359670/system_tasks.o.d 
	@${RM} ${OBJECTDIR}/_ext/1823359670/system_tasks.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1823359670/system_tasks.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../Codec" -ffunction-sections -Os -I"../bt_application" -I"../BT Common" -I"../../../codec" -I"../../../../../framework" -I"../src" -I"../src/system_config/MX450_BASIC_DEMO0" -I"../src/MX450_BASIC_DEMO0" -I"../../../../../../framework" -I"../src/system_config/MX450_BASIC_DEMO0/framework" -MMD -MF "${OBJECTDIR}/_ext/1823359670/system_tasks.o.d" -o ${OBJECTDIR}/_ext/1823359670/system_tasks.o ../src/system_config/MX450_BASIC_DEMO0/system_tasks.c   
	
${OBJECTDIR}/_ext/1360937237/app.o: ../src/app.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/app.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/app.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/app.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../Codec" -ffunction-sections -Os -I"../bt_application" -I"../BT Common" -I"../../../codec" -I"../../../../../framework" -I"../src" -I"../src/system_config/MX450_BASIC_DEMO0" -I"../src/MX450_BASIC_DEMO0" -I"../../../../../../framework" -I"../src/system_config/MX450_BASIC_DEMO0/framework" -MMD -MF "${OBJECTDIR}/_ext/1360937237/app.o.d" -o ${OBJECTDIR}/_ext/1360937237/app.o ../src/app.c   
	
${OBJECTDIR}/_ext/1360937237/main.o: ../src/main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/main.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../Codec" -ffunction-sections -Os -I"../bt_application" -I"../BT Common" -I"../../../codec" -I"../../../../../framework" -I"../src" -I"../src/system_config/MX450_BASIC_DEMO0" -I"../src/MX450_BASIC_DEMO0" -I"../../../../../../framework" -I"../src/system_config/MX450_BASIC_DEMO0/framework" -MMD -MF "${OBJECTDIR}/_ext/1360937237/main.o.d" -o ${OBJECTDIR}/_ext/1360937237/main.o ../src/main.c   
	
${OBJECTDIR}/_ext/1205520658/bt_app.o: ../bt_application/bt_app.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1205520658" 
	@${RM} ${OBJECTDIR}/_ext/1205520658/bt_app.o.d 
	@${RM} ${OBJECTDIR}/_ext/1205520658/bt_app.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1205520658/bt_app.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../Codec" -ffunction-sections -Os -I"../bt_application" -I"../BT Common" -I"../../../codec" -I"../../../../../framework" -I"../src" -I"../src/system_config/MX450_BASIC_DEMO0" -I"../src/MX450_BASIC_DEMO0" -I"../../../../../../framework" -I"../src/system_config/MX450_BASIC_DEMO0/framework" -MMD -MF "${OBJECTDIR}/_ext/1205520658/bt_app.o.d" -o ${OBJECTDIR}/_ext/1205520658/bt_app.o ../bt_application/bt_app.c   
	
${OBJECTDIR}/_ext/1205520658/bt_data.o: ../bt_application/bt_data.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1205520658" 
	@${RM} ${OBJECTDIR}/_ext/1205520658/bt_data.o.d 
	@${RM} ${OBJECTDIR}/_ext/1205520658/bt_data.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1205520658/bt_data.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../Codec" -ffunction-sections -Os -I"../bt_application" -I"../BT Common" -I"../../../codec" -I"../../../../../framework" -I"../src" -I"../src/system_config/MX450_BASIC_DEMO0" -I"../src/MX450_BASIC_DEMO0" -I"../../../../../../framework" -I"../src/system_config/MX450_BASIC_DEMO0/framework" -MMD -MF "${OBJECTDIR}/_ext/1205520658/bt_data.o.d" -o ${OBJECTDIR}/_ext/1205520658/bt_data.o ../bt_application/bt_data.c   
	
${OBJECTDIR}/_ext/1205520658/bt_hardware_profile.o: ../bt_application/bt_hardware_profile.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1205520658" 
	@${RM} ${OBJECTDIR}/_ext/1205520658/bt_hardware_profile.o.d 
	@${RM} ${OBJECTDIR}/_ext/1205520658/bt_hardware_profile.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1205520658/bt_hardware_profile.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../Codec" -ffunction-sections -Os -I"../bt_application" -I"../BT Common" -I"../../../codec" -I"../../../../../framework" -I"../src" -I"../src/system_config/MX450_BASIC_DEMO0" -I"../src/MX450_BASIC_DEMO0" -I"../../../../../../framework" -I"../src/system_config/MX450_BASIC_DEMO0/framework" -MMD -MF "${OBJECTDIR}/_ext/1205520658/bt_hardware_profile.o.d" -o ${OBJECTDIR}/_ext/1205520658/bt_hardware_profile.o ../bt_application/bt_hardware_profile.c   
	
${OBJECTDIR}/_ext/1205520658/key.o: ../bt_application/key.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1205520658" 
	@${RM} ${OBJECTDIR}/_ext/1205520658/key.o.d 
	@${RM} ${OBJECTDIR}/_ext/1205520658/key.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1205520658/key.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../Codec" -ffunction-sections -Os -I"../bt_application" -I"../BT Common" -I"../../../codec" -I"../../../../../framework" -I"../src" -I"../src/system_config/MX450_BASIC_DEMO0" -I"../src/MX450_BASIC_DEMO0" -I"../../../../../../framework" -I"../src/system_config/MX450_BASIC_DEMO0/framework" -MMD -MF "${OBJECTDIR}/_ext/1205520658/key.o.d" -o ${OBJECTDIR}/_ext/1205520658/key.o ../bt_application/key.c   
	
${OBJECTDIR}/_ext/1205520658/key_handler.o: ../bt_application/key_handler.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1205520658" 
	@${RM} ${OBJECTDIR}/_ext/1205520658/key_handler.o.d 
	@${RM} ${OBJECTDIR}/_ext/1205520658/key_handler.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1205520658/key_handler.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../Codec" -ffunction-sections -Os -I"../bt_application" -I"../BT Common" -I"../../../codec" -I"../../../../../framework" -I"../src" -I"../src/system_config/MX450_BASIC_DEMO0" -I"../src/MX450_BASIC_DEMO0" -I"../../../../../../framework" -I"../src/system_config/MX450_BASIC_DEMO0/framework" -MMD -MF "${OBJECTDIR}/_ext/1205520658/key_handler.o.d" -o ${OBJECTDIR}/_ext/1205520658/key_handler.o ../bt_application/key_handler.c   
	
${OBJECTDIR}/_ext/1205520658/led.o: ../bt_application/led.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1205520658" 
	@${RM} ${OBJECTDIR}/_ext/1205520658/led.o.d 
	@${RM} ${OBJECTDIR}/_ext/1205520658/led.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1205520658/led.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../Codec" -ffunction-sections -Os -I"../bt_application" -I"../BT Common" -I"../../../codec" -I"../../../../../framework" -I"../src" -I"../src/system_config/MX450_BASIC_DEMO0" -I"../src/MX450_BASIC_DEMO0" -I"../../../../../../framework" -I"../src/system_config/MX450_BASIC_DEMO0/framework" -MMD -MF "${OBJECTDIR}/_ext/1205520658/led.o.d" -o ${OBJECTDIR}/_ext/1205520658/led.o ../bt_application/led.c   
	
${OBJECTDIR}/_ext/1205520658/timer.o: ../bt_application/timer.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1205520658" 
	@${RM} ${OBJECTDIR}/_ext/1205520658/timer.o.d 
	@${RM} ${OBJECTDIR}/_ext/1205520658/timer.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1205520658/timer.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../Codec" -ffunction-sections -Os -I"../bt_application" -I"../BT Common" -I"../../../codec" -I"../../../../../framework" -I"../src" -I"../src/system_config/MX450_BASIC_DEMO0" -I"../src/MX450_BASIC_DEMO0" -I"../../../../../../framework" -I"../src/system_config/MX450_BASIC_DEMO0/framework" -MMD -MF "${OBJECTDIR}/_ext/1205520658/timer.o.d" -o ${OBJECTDIR}/_ext/1205520658/timer.o ../bt_application/timer.c   
	
${OBJECTDIR}/_ext/1634889738/bt_a2dp.o: ../BT\ Common/bt_a2dp.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1634889738" 
	@${RM} ${OBJECTDIR}/_ext/1634889738/bt_a2dp.o.d 
	@${RM} ${OBJECTDIR}/_ext/1634889738/bt_a2dp.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1634889738/bt_a2dp.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../Codec" -ffunction-sections -Os -I"../bt_application" -I"../BT Common" -I"../../../codec" -I"../../../../../framework" -I"../src" -I"../src/system_config/MX450_BASIC_DEMO0" -I"../src/MX450_BASIC_DEMO0" -I"../../../../../../framework" -I"../src/system_config/MX450_BASIC_DEMO0/framework" -MMD -MF "${OBJECTDIR}/_ext/1634889738/bt_a2dp.o.d" -o ${OBJECTDIR}/_ext/1634889738/bt_a2dp.o "../BT Common/bt_a2dp.c"   
	
${OBJECTDIR}/_ext/1634889738/bt_command_decode.o: ../BT\ Common/bt_command_decode.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1634889738" 
	@${RM} ${OBJECTDIR}/_ext/1634889738/bt_command_decode.o.d 
	@${RM} ${OBJECTDIR}/_ext/1634889738/bt_command_decode.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1634889738/bt_command_decode.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../Codec" -ffunction-sections -Os -I"../bt_application" -I"../BT Common" -I"../../../codec" -I"../../../../../framework" -I"../src" -I"../src/system_config/MX450_BASIC_DEMO0" -I"../src/MX450_BASIC_DEMO0" -I"../../../../../../framework" -I"../src/system_config/MX450_BASIC_DEMO0/framework" -MMD -MF "${OBJECTDIR}/_ext/1634889738/bt_command_decode.o.d" -o ${OBJECTDIR}/_ext/1634889738/bt_command_decode.o "../BT Common/bt_command_decode.c"   
	
${OBJECTDIR}/_ext/1634889738/bt_command_send.o: ../BT\ Common/bt_command_send.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1634889738" 
	@${RM} ${OBJECTDIR}/_ext/1634889738/bt_command_send.o.d 
	@${RM} ${OBJECTDIR}/_ext/1634889738/bt_command_send.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1634889738/bt_command_send.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../Codec" -ffunction-sections -Os -I"../bt_application" -I"../BT Common" -I"../../../codec" -I"../../../../../framework" -I"../src" -I"../src/system_config/MX450_BASIC_DEMO0" -I"../src/MX450_BASIC_DEMO0" -I"../../../../../../framework" -I"../src/system_config/MX450_BASIC_DEMO0/framework" -MMD -MF "${OBJECTDIR}/_ext/1634889738/bt_command_send.o.d" -o ${OBJECTDIR}/_ext/1634889738/bt_command_send.o "../BT Common/bt_command_send.c"   
	
${OBJECTDIR}/_ext/1634889738/bt_hfp.o: ../BT\ Common/bt_hfp.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1634889738" 
	@${RM} ${OBJECTDIR}/_ext/1634889738/bt_hfp.o.d 
	@${RM} ${OBJECTDIR}/_ext/1634889738/bt_hfp.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1634889738/bt_hfp.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../Codec" -ffunction-sections -Os -I"../bt_application" -I"../BT Common" -I"../../../codec" -I"../../../../../framework" -I"../src" -I"../src/system_config/MX450_BASIC_DEMO0" -I"../src/MX450_BASIC_DEMO0" -I"../../../../../../framework" -I"../src/system_config/MX450_BASIC_DEMO0/framework" -MMD -MF "${OBJECTDIR}/_ext/1634889738/bt_hfp.o.d" -o ${OBJECTDIR}/_ext/1634889738/bt_hfp.o "../BT Common/bt_hfp.c"   
	
${OBJECTDIR}/_ext/1634889738/bt_line_in.o: ../BT\ Common/bt_line_in.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1634889738" 
	@${RM} ${OBJECTDIR}/_ext/1634889738/bt_line_in.o.d 
	@${RM} ${OBJECTDIR}/_ext/1634889738/bt_line_in.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1634889738/bt_line_in.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../Codec" -ffunction-sections -Os -I"../bt_application" -I"../BT Common" -I"../../../codec" -I"../../../../../framework" -I"../src" -I"../src/system_config/MX450_BASIC_DEMO0" -I"../src/MX450_BASIC_DEMO0" -I"../../../../../../framework" -I"../src/system_config/MX450_BASIC_DEMO0/framework" -MMD -MF "${OBJECTDIR}/_ext/1634889738/bt_line_in.o.d" -o ${OBJECTDIR}/_ext/1634889738/bt_line_in.o "../BT Common/bt_line_in.c"   
	
${OBJECTDIR}/_ext/1634889738/bt_multi_spk.o: ../BT\ Common/bt_multi_spk.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1634889738" 
	@${RM} ${OBJECTDIR}/_ext/1634889738/bt_multi_spk.o.d 
	@${RM} ${OBJECTDIR}/_ext/1634889738/bt_multi_spk.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1634889738/bt_multi_spk.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../Codec" -ffunction-sections -Os -I"../bt_application" -I"../BT Common" -I"../../../codec" -I"../../../../../framework" -I"../src" -I"../src/system_config/MX450_BASIC_DEMO0" -I"../src/MX450_BASIC_DEMO0" -I"../../../../../../framework" -I"../src/system_config/MX450_BASIC_DEMO0/framework" -MMD -MF "${OBJECTDIR}/_ext/1634889738/bt_multi_spk.o.d" -o ${OBJECTDIR}/_ext/1634889738/bt_multi_spk.o "../BT Common/bt_multi_spk.c"   
	
${OBJECTDIR}/_ext/1634889738/bt_volume.o: ../BT\ Common/bt_volume.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1634889738" 
	@${RM} ${OBJECTDIR}/_ext/1634889738/bt_volume.o.d 
	@${RM} ${OBJECTDIR}/_ext/1634889738/bt_volume.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1634889738/bt_volume.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../Codec" -ffunction-sections -Os -I"../bt_application" -I"../BT Common" -I"../../../codec" -I"../../../../../framework" -I"../src" -I"../src/system_config/MX450_BASIC_DEMO0" -I"../src/MX450_BASIC_DEMO0" -I"../../../../../../framework" -I"../src/system_config/MX450_BASIC_DEMO0/framework" -MMD -MF "${OBJECTDIR}/_ext/1634889738/bt_volume.o.d" -o ${OBJECTDIR}/_ext/1634889738/bt_volume.o "../BT Common/bt_volume.c"   
	
${OBJECTDIR}/_ext/2146212583/sta369bwdsp_handler.o: ../Codec/sta369bwdsp_handler.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/2146212583" 
	@${RM} ${OBJECTDIR}/_ext/2146212583/sta369bwdsp_handler.o.d 
	@${RM} ${OBJECTDIR}/_ext/2146212583/sta369bwdsp_handler.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/2146212583/sta369bwdsp_handler.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../Codec" -ffunction-sections -Os -I"../bt_application" -I"../BT Common" -I"../../../codec" -I"../../../../../framework" -I"../src" -I"../src/system_config/MX450_BASIC_DEMO0" -I"../src/MX450_BASIC_DEMO0" -I"../../../../../../framework" -I"../src/system_config/MX450_BASIC_DEMO0/framework" -MMD -MF "${OBJECTDIR}/_ext/2146212583/sta369bwdsp_handler.o.d" -o ${OBJECTDIR}/_ext/2146212583/sta369bwdsp_handler.o ../Codec/sta369bwdsp_handler.c   
	
${OBJECTDIR}/_ext/912498863/sys_devcon.o: ../../../../../../framework/system/devcon/src/sys_devcon.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/912498863" 
	@${RM} ${OBJECTDIR}/_ext/912498863/sys_devcon.o.d 
	@${RM} ${OBJECTDIR}/_ext/912498863/sys_devcon.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/912498863/sys_devcon.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../Codec" -ffunction-sections -Os -I"../bt_application" -I"../BT Common" -I"../../../codec" -I"../../../../../framework" -I"../src" -I"../src/system_config/MX450_BASIC_DEMO0" -I"../src/MX450_BASIC_DEMO0" -I"../../../../../../framework" -I"../src/system_config/MX450_BASIC_DEMO0/framework" -MMD -MF "${OBJECTDIR}/_ext/912498863/sys_devcon.o.d" -o ${OBJECTDIR}/_ext/912498863/sys_devcon.o ../../../../../../framework/system/devcon/src/sys_devcon.c   
	
${OBJECTDIR}/_ext/912498863/sys_devcon_pic32mx.o: ../../../../../../framework/system/devcon/src/sys_devcon_pic32mx.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/912498863" 
	@${RM} ${OBJECTDIR}/_ext/912498863/sys_devcon_pic32mx.o.d 
	@${RM} ${OBJECTDIR}/_ext/912498863/sys_devcon_pic32mx.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/912498863/sys_devcon_pic32mx.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../Codec" -ffunction-sections -Os -I"../bt_application" -I"../BT Common" -I"../../../codec" -I"../../../../../framework" -I"../src" -I"../src/system_config/MX450_BASIC_DEMO0" -I"../src/MX450_BASIC_DEMO0" -I"../../../../../../framework" -I"../src/system_config/MX450_BASIC_DEMO0/framework" -MMD -MF "${OBJECTDIR}/_ext/912498863/sys_devcon_pic32mx.o.d" -o ${OBJECTDIR}/_ext/912498863/sys_devcon_pic32mx.o ../../../../../../framework/system/devcon/src/sys_devcon_pic32mx.c   
	
${OBJECTDIR}/_ext/711155467/sys_int_pic32.o: ../../../../../../framework/system/int/src/sys_int_pic32.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/711155467" 
	@${RM} ${OBJECTDIR}/_ext/711155467/sys_int_pic32.o.d 
	@${RM} ${OBJECTDIR}/_ext/711155467/sys_int_pic32.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/711155467/sys_int_pic32.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../Codec" -ffunction-sections -Os -I"../bt_application" -I"../BT Common" -I"../../../codec" -I"../../../../../framework" -I"../src" -I"../src/system_config/MX450_BASIC_DEMO0" -I"../src/MX450_BASIC_DEMO0" -I"../../../../../../framework" -I"../src/system_config/MX450_BASIC_DEMO0/framework" -MMD -MF "${OBJECTDIR}/_ext/711155467/sys_int_pic32.o.d" -o ${OBJECTDIR}/_ext/711155467/sys_int_pic32.o ../../../../../../framework/system/int/src/sys_int_pic32.c   
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compileCPP
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/Bluetooth_Basic_Demo_BM83_EVB.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk  ../../../../../../bin/framework/peripheral/PIC32MX450F256L_peripherals.a  
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -mdebugger -D__MPLAB_DEBUGGER_PK3=1 -mprocessor=$(MP_PROCESSOR_OPTION)  -o dist/${CND_CONF}/${IMAGE_TYPE}/Bluetooth_Basic_Demo_BM83_EVB.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}    ..\..\..\..\..\..\bin\framework\peripheral\PIC32MX450F256L_peripherals.a       -mreserve=data@0x0:0x1FC -mreserve=boot@0x1FC02000:0x1FC02FEF -mreserve=boot@0x1FC02000:0x1FC0275F  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_PK3=1,--defsym=_min_heap_size=0,--gc-sections,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/Bluetooth_Basic_Demo_BM83_EVB.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk  ../../../../../../bin/framework/peripheral/PIC32MX450F256L_peripherals.a 
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -mprocessor=$(MP_PROCESSOR_OPTION)  -o dist/${CND_CONF}/${IMAGE_TYPE}/Bluetooth_Basic_Demo_BM83_EVB.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}    ..\..\..\..\..\..\bin\framework\peripheral\PIC32MX450F256L_peripherals.a      -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=_min_heap_size=0,--gc-sections,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml
	${MP_CC_DIR}\\xc32-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/Bluetooth_Basic_Demo_BM83_EVB.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} 
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/MX450_BASIC_DEMO0
	${RM} -r dist/MX450_BASIC_DEMO0

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
