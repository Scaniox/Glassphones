/********************************************************************
  File Information:
    FileName:       app_cfg_btn_gpio.h
    Processor:      8051
    Hardware:
    Complier:       Keil C51
    Company:        Microchip Technology, Inc.

    Software License Agreement:

    The software supplied herewith by Microchip Technology Incorporated
    (the "Company") for 8051 Microcontroller is intended and supplied
    to you, the Company's customer, for use solely and exclusively on
    Microchip 8051 Microcontroller products. The software is owned by
    the Company and/or its supplier, and is protected under applicable
    copyright laws. All rights are reserved. Any use in violation of
    the foregoing restrictions may subject the user to criminal
    sanctions under applicable laws, as well as to civil liability for
    the breach of the terms and conditions of this license.

    THIS SOFTWARE IS PROVIDED IN AN "AS IS" CONDITION. NO WARRANTIES,
    WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING, BUT NOT LIMITED
    TO, IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
    PARTICULAR PURPOSE APPLY TO THIS SOFTWARE. THE COMPANY SHALL NOT,
    IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL OR
    CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.

********************************************************************/

#ifndef APP_CFG_BTN_GPIO_H
#define APP_CFG_BTN_GPIO_H
#include "gpio.h"
#include "bt_service.h"

/** \cond NON_DOC 

\#BUILD_TARGET : MSPKv2_App_Basic
\#BUILD_TARGET : MSPKv2_GFP
\#BUILD_TARGET : MSPKv2_SPP
\#BUILD_TARGET : MSPKv2_PBAP
\#TARGET_START
\#REMOVE_PARAM : BTN_GPIO_CFG_KEY_RESERVED
\#REMOVE_BIT   : AT_APP_MODE_SELECT_IO
\#REMOVE_BIT   : AT_AUDIO_INPUT_SOURCE_SELECT_IO
\#REMOVE_BIT   : AT_AUDIO_INPUT_SOURCE_SELECT_GPIO_REVERSE_POLARITY
\#REMOVE_BIT   : AT_APP_MODE_SELECT_GPIO_REVERSE_POLARITY
\#REMOVE_PARAM : BTN_GPIO_CFG_KEY_RESERVED2
\#REMOVE_PARAM : BTN_GPIO_CFG_KEY_RESERVED3
\#REMOVE_PARAM : BTN_GPIO_CFG_KEY_RESERVED4
\#REMOVE_PARAM : BTN_GPIO_CFG_KEY_RESERVED5
\#REMOVE_PARAM : BTN_GPIO_CFG_KEY_RESERVED6
\#REMOVE_PARAM : BTN_GPIO_CFG_KEY_RESERVED7
\#REMOVE_PARAM : BTN_GPIO_CFG_KEY_RESERVED8
\#REMOVE_PARAM : BTN_GPIO_CFG_KEY_RESERVED9
\#REMOVE_PARAM : BTN_GPIO_CFG_KEY_RESERVED10
\#REMOVE_PARAM : BTN_GPIO_CFG_KEY_RESERVED11
\#REMOVE_PARAM : BTN_GPIO_CFG_KEY_RESERVED12
\#REMOVE_PARAM : BTN_GPIO_CFG_KEY_RESERVED13
\#REMOVE_PARAM : BTN_GPIO_CFG_KEY_AT_APP_MODE_SELECT_IO
\#REMOVE_PARAM : BTN_GPIO_CFG_KEY_AT_AUDIO_INPUT_SOURCE_SELECT_IO
\#TARGET_END

\#BUILD_TARGET : AT_App
\#TARGET_START
\#REMOVE_PARAM : BTN_GPIO_CFG_KEY_RESERVED
\#REMOVE_PARAM : BTN_GPIO_CFG_KEY_RESERVED2
\#REMOVE_PARAM : BTN_GPIO_CFG_KEY_RESERVED3
\#REMOVE_PARAM : BTN_GPIO_CFG_KEY_RESERVED4
\#REMOVE_PARAM : BTN_GPIO_CFG_KEY_RESERVED5
\#REMOVE_PARAM : BTN_GPIO_CFG_KEY_RESERVED6
\#REMOVE_PARAM : BTN_GPIO_CFG_KEY_RESERVED7
\#REMOVE_PARAM : BTN_GPIO_CFG_KEY_RESERVED8
\#REMOVE_PARAM : BTN_GPIO_CFG_KEY_RESERVED9
\#REMOVE_PARAM : BTN_GPIO_CFG_KEY_RESERVED10
\#REMOVE_PARAM : BTN_GPIO_CFG_KEY_RESERVED11
\#REMOVE_PARAM : BTN_GPIO_CFG_KEY_RESERVED12
\#REMOVE_PARAM : BTN_GPIO_CFG_KEY_RESERVED13
\#TARGET_END
\endcond
*/

/**
  @addtogroup APP_CFG_BTN_GPIO BTN_GPIO Configuration
  @{
  @brief Definitions and prototypes for the BTN_GPIO Configuration.
 */


/**
 * @brief Configuration key definition of the module @ref CFG_MODULE_ID_BTN_GPIO.
 *  
 */
//Config Key definiton of MODULE_BTN_GPIO(0x09)
typedef enum _BTN_GPIO_CFG_Key_IdDefinition_T
{
    BTN_GPIO_CFG_KEY_BUTTON_OPERATION_NUM_0             = 0x01, /**<\#PARAM_NAME :  BTN_GPIO_CFG_KEY_BUTTON_OPERATION_NUM_0 \n
                                                                    \#ALIAS : GPIO BUTTON OPERATION NUM 0 \n
                                                                    \#PARAM_TYPE : Public \n
                                                                    \#PARAM_DESC : The number of button operation in BTN_GPIO_CFG_KEY_BUTTON_TABLE_0. \n
                                                                    \#DESC_END
                                                                    \#GROUP_ID : 0x09 \n
                                                                    \#KEY_ID : 0x01 \n
                                                        	    */
                                                	          
    BTN_GPIO_CFG_KEY_BUTTON_TABLE_0              		= 0x02, /**<\#PARAM_NAME : BTN_GPIO_CFG_KEY_BUTTON_TABLE_0 \n
                                                                    \#ALIAS : GPIO BUTTON TABLE 0 \n
                                                                    \#PARAM_TYPE : Public \n
                                                                    \#PARAM_DESC : structure of each button operation as below, it need 38 bytes for each operation. 0 ~ 228 (38*6) bytes. \n
                                                                                   Max to 16 button operations in three tables. \n
                                                                                   typedef struct _APP_Cfg_PhyButtonAction_T \n
                                                                                   { \n
                                                                                       u8 action1; \n
                                                                                       u8 action2; \n
                                                                                       u8 action3; \n
                                                                                   }APP_Cfg_ButtonAction_T; \n
                                                                                   
                                                                                   typedef struct _APP_Cfg_ButtonTable_T \n
                                                                                   { \n
                                                                                       u8          portMask[4]; \n
                                                                                       u8          mfbMask; \n
                                                                                       u8          pressType; \n
                                                                                       u8          pressTimeUnit; \n
                                                                                       u8          holdPressCount; \n
                                                                                       APP_Cfg_ButtonAction_T  actionTable[BT_SRV_CALL_STATUS_TOTAL]; \n
                                                                                   }APP_Cfg_ButtonTable_T; \n
                                                                                   The BT_SRV_CALL_STATUS_TOTAL is 0x0A.
                                                                    \#DESC_END
                                                                    \#GROUP_ID : 0x09 \n
                                                                    \#KEY_ID : 0x02 \n
                                                        	    */
                                                	          
    BTN_GPIO_CFG_KEY_BUTTON_OPERATION_NUM_1             = 0x03, /**<\#PARAM_NAME : BTN_GPIO_CFG_KEY_BUTTON_OPERATION_NUM_1 \n
                                                                    \#ALIAS : GPIO BUTTON OPERATION NUM 1 \n
                                                                    \#PARAM_TYPE : Public \n
                                                                    \#PARAM_DESC : The number of button operation in BTN_GPIO_CFG_KEY_BUTTON_TABLE_1. \n
                                                                    \#DESC_END
                                                                    \#GROUP_ID : 0x09 \n
                                                                    \#KEY_ID : 0x03 \n
                                                        	    */
                                                	          
    BTN_GPIO_CFG_KEY_BUTTON_TABLE_1              		= 0x04, /**<\#PARAM_NAME : BTN_GPIO_CFG_KEY_BUTTON_TABLE_1 \n
                                                                    \#ALIAS : GPIO BUTTON TABLE 1 \n
                                                                    \#PARAM_TYPE : Public \n
                                                                    \#PARAM_DESC : 0 ~ 228 (38*6) bytes. \n
                                                                    \#DESC_END
                                                                    \#GROUP_ID : 0x09 \n
                                                                    \#KEY_ID : 0x04 \n
                                                        	    */
                                                	          
    BTN_GPIO_CFG_KEY_BUTTON_OPERATION_NUM_2             = 0x05, /**<\#PARAM_NAME : BTN_GPIO_CFG_KEY_BUTTON_OPERATION_NUM_2 \n
                                                                    \#ALIAS : GPIO BUTTON OPERATION NUM 2 \n
                                                                    \#PARAM_TYPE : Public \n
                                                                    \#PARAM_DESC : The number of button operation in BTN_GPIO_CFG_KEY_BUTTON_TABLE_1. \n
                                                                    \#DESC_END
                                                                    \#GROUP_ID : 0x09 \n
                                                                    \#KEY_ID : 0x05 \n
                                                        	    */
                                                	          
    BTN_GPIO_CFG_KEY_BUTTON_TABLE_2              		= 0x06, /**<\#PARAM_NAME : BTN_GPIO_CFG_KEY_BUTTON_TABLE_2 \n
                                                                    \#ALIAS : GPIO BUTTON TABLE 2 \n
                                                                    \#PARAM_TYPE : Public \n
                                                                    \#PARAM_DESC : 0 ~ 152 (38*4) bytes. \n
                                                                    \#DESC_END
                                                                    \#GROUP_ID : 0x09 \n
                                                                    \#KEY_ID : 0x06 \n
                                                        	    */
                                                	          
    BTN_GPIO_CFG_KEY_POWER_ON_INTERVAL					= 0x07, /**<\#PARAM_NAME : BTN_GPIO_CFG_KEY_POWER_ON_INTERVAL \n
                                                                    \#ALIAS : Power On \n
                                                                    \#PARAM_TYPE : Public \n
                                                                    \#PARAM_DESC : when in OFF mode, the power button is pressed over this time, system will power on (unit in 80ms) \n
                                                                                   PS: the real power on time will larger than this interval around 1second due to system initialization. \n
                                                                    \#DESC_END
                                                                    \#GROUP_ID : 0x09 \n
                                                                    \#KEY_ID : 0x07 \n
                                                        	    */
                                                	          
	BTN_GPIO_CFG_KEY_POWER_OFF_INTERVAL                 = 0x08, /**<\#PARAM_NAME : BTN_GPIO_CFG_KEY_POWER_OFF_INTERVAL \n
                                                                    \#ALIAS : Power Off \n
                                                                    \#PARAM_TYPE : Public \n
                                                                    \#PARAM_DESC : When in ON mode, the power button is press over this time, system will power off (unit in 80ms) \n
                                                                    \#DESC_END
                                                                    \#GROUP_ID : 0x09 \n
                                                                    \#KEY_ID : 0x08 \n
                                                        	    */
                                                	          
    BTN_GPIO_CFG_KEY_RESET_TO_DEAFULT_TIMER             = 0x09, /**<\#PARAM_NAME : BTN_GPIO_CFG_KEY_RESET_TO_DEAFULT_TIMER \n
                                                                    \#ALIAS : Factory Default Timer \n
                                                                    \#PARAM_TYPE : Public \n
                                                                    \#PARAM_DESC :  if the power button is pressed over this time in OFF state, the speaker will clear some configuration parameters to default values. \n
                                                                                    1. line_in_gain_level \n
                                                                                    2. Device_List_Table \n
                                                                                    3. device_speaker_gain \n
                                                                                    4. device_absolute_volume \n
                                                                                    5. linked_priority \n
                                                                                    6. app_function_status \n
                                                                                    7. hf_device_index \n
                                                                                    8. a2dp_device_index \n
                                                                                    9. mic_gain_level \n
                                                                                    10. CSB_DIAC (if PAIRING_WITH_MIAC is enabled) \n
                                                                                    11. clear the options LAST_MODE_N_SPK_MASTER and LAST_MODE_N_SPK_SLAVE (if the option BACK_TO_LAST_MODE is enabled.) \n
                                                                                    12. NSPK_channel \n
                                                                                    13. LE paired record \n
                                                                    \#DESC_END
                                                                    \#GROUP_ID : 0x09 \n
                                                                    \#KEY_ID : 0x09 \n
                                                        	    */
                                                	          
    BTN_GPIO_CFG_KEY_OUTPUT_INDICATION_TABLE            = 0x0A, /**<\#PARAM_NAME : BTN_GPIO_CFG_KEY_OUTPUT_INDICATION_TABLE \n
                                                                    \#ALIAS : GPIO OUTPUT INDICATION TABLE \n
                                                                    \#PARAM_TYPE : Public \n
                                                                    \#PARAM_DESC : set output indication function by indenpendent GPIO \n
                                                                                    Byte0&1: {AUDIO_INDICATE_GPIO_NUM, GPIO polarity} \n
                                                                                    Byte2&3: {VOICE_INDICATE_GPIO_NUM, GPIO polarity} \n
                                                                                    Byte4&5: {RINGTONE_INDICATE_GPIO_NUM, GPIO polarity} \n
                                                                                        Indicator activates when a tone is ringing. \n
                                                                                    Byte6&7: {INCALL_INDICATE_GPIO_NUM, GPIO polarity} \n
                                                                                        Incoming call indication \n
                                                                                    Byte8&9: {AMP_INDICATE_GPIO_NUM, GPIO polarity} \n
                                                                                        External amplifier control \n
                                                                                    ByteA&B: {HF_LINK_INDICATE_GPIO_NUM, GPIO polarity} \n
                                                                                        Indicator activates when HFP link exists. \n
                                                                                    ByteC&D: {A2DP_LINK_INDICATE_GPIO_NUM, GPIO polarity} \n
                                                                                        Indicator activates when A2DP link exists. \n
                                                                                    ByteE&F: {BUTTON_INDICATE_GPIO_NUM, GPIO polarity} \n
                                                                                        This indicator will be controlled by MMI event SHS_BUTTON_INDICATION_TOGGLE (0x58).\n
                                                                    \#DESC_END
                                                                    \#GROUP_ID : 0x09 \n
                                                                    \#KEY_ID : 0x0A \n

                                                                    \#BYTE_PARAM : A2DP_STREAMING_INDICATION \n
                                                    	            \#BYTE_ALIAS : Audio(A2DP) Indication\n
                                                    	            \#BYTE_POS : 0 \n
                                                    	            \#BYTE_SIZE : 2 \n
                                                    	            \#BYTE_DESC : The pair of GPIO and polarity (high/low active) is for the indication of A2DP streaming status. \n
                                                    	            \#DESC_END  \n
                                                                    
                                                                    \#BYTE_PARAM : VOICE_SCO_INDICATION \n
                                                    	            \#BYTE_ALIAS : Voice(SCO) Indication\n
                                                    	            \#BYTE_POS : 2 \n
                                                    	            \#BYTE_SIZE : 2 \n
                                                    	            \#BYTE_DESC : The pair of GPIO and polarity (high/low active) is for the indication of SCO voice status. \n
                                                    	            \#DESC_END  \n

                                                                    \#BYTE_PARAM : RING_TONE_INDICATION \n
                                                    	            \#BYTE_ALIAS : Ring Tone Indication\n
                                                    	            \#BYTE_POS : 4 \n
                                                    	            \#BYTE_SIZE : 2 \n
                                                    	            \#BYTE_DESC : The pair of GPIO and polarity (high/low active) is for the indication of ring tone status. \n
                                                    	            \#DESC_END  \n

                                                                    \#BYTE_PARAM : INCOMING_CALL_INDICATION \n
                                                    	            \#BYTE_ALIAS : Incoming Call Indication\n
                                                    	            \#BYTE_POS : 6 \n
                                                    	            \#BYTE_SIZE : 2 \n
                                                    	            \#BYTE_DESC : The pair of GPIO and polarity (high/low active) is for the indication of an incoming call. \n
                                                    	            \#DESC_END  \n

                                                    	            \#BYTE_PARAM : EXTERNAL_AMPLIFIER_INDICATION \n
                                                    	            \#BYTE_ALIAS : External Amplifier Indication\n
                                                    	            \#BYTE_POS : 8 \n
                                                    	            \#BYTE_SIZE : 2 \n
                                                    	            \#BYTE_DESC : The pair of GPIO and polarity (high/low active) is for the control of external amplifier. \n
                                                    	            \#DESC_END  \n

                                                    	            \#BYTE_PARAM : HFP_LINK_INDICATION \n
                                                    	            \#BYTE_ALIAS : HFP Link Indication\n
                                                    	            \#BYTE_POS : 10 \n
                                                    	            \#BYTE_SIZE : 2 \n
                                                    	            \#BYTE_DESC : The pair of GPIO and polarity (high/low active) is for the indication of HFP link status. \n
                                                    	            \#DESC_END  \n  

                                                    	            \#BYTE_PARAM : A2DP_LINK_INDICATION \n
                                                    	            \#BYTE_ALIAS : A2DP Link Indication\n
                                                    	            \#BYTE_POS : 12 \n
                                                    	            \#BYTE_SIZE : 2 \n
                                                    	            \#BYTE_DESC : The pair of GPIO and polarity (high/low active) is for the indication of A2DP link status. \n
                                                    	            \#DESC_END  \n  

                                                    	            \#BYTE_PARAM : BUTTON_MMI_TRIGGER_INDICATION \n
                                                    	            \#BYTE_ALIAS : Button Event Trigger Indication\n
                                                    	            \#BYTE_POS : 14 \n
                                                    	            \#BYTE_SIZE : 2 \n
                                                    	            \#BYTE_DESC : The pair of GPIO and polarity (high/low active). This GPIO is controlled by the specific button event. \n
                                                    	            \#DESC_END  \n                                                    	            
                                                                    */                                                                    
 
    BTN_GPIO_CFG_KEY_AT_OPTION                          = 0x0B, /**<\#PARAM_NAME : BTN_GPIO_CFG_KEY_AT_OPTION \n
                                                                    \#PARAM_TYPE : Public \n
                                                                    \#BYTE_DESC : AT Button GPIO option. \n
                                                    	            \#DESC_END  \n
                                                                    \#GROUP_ID : 0x09 \n
                                                                    \#KEY_ID : 0x0B \n
                                                                     Bit Options:
                                                                    \par
                                                                    \#BIT_PARAM : AT_APP_MODE_SELECT_IO \n
                                                                    \#BIT_POS : 0 \n
                                                                    \#BIT_SIZE : 1 \n
                                                                    \#BIT_DESC : AT Enable App Mode Select IO. \n
                                                                    \#DESC_END

                                                                    \par
                                                                    \#BIT_PARAM : AT_AUDIO_INPUT_SOURCE_SELECT_IO \n
                                                                    \#BIT_POS : 1 \n
                                                                    \#BIT_SIZE : 1 \n
                                                                    \#BIT_DESC : AT Enable Audio Input Source Select IO. \n
                                                                    \#DESC_END

                                                                    \par
                                                                    \#BIT_PARAM : AT_AUDIO_INPUT_SOURCE_SELECT_GPIO_REVERSE_POLARITY \n
                                                                    \#BIT_POS : 2 \n
                                                                    \#BIT_SIZE : 1 \n
                                                                    \#BIT_DESC : AT Audio Input source select GPIO sensing reverse polarity. \n
                                                                    \#DESC_END
																	
																	\par
                                                                    \#BIT_PARAM : AT_APP_MODE_SELECT_GPIO_REVERSE_POLARITY \n
                                                                    \#BIT_POS : 3 \n
                                                                    \#BIT_SIZE : 1 \n
                                                                    \#BIT_DESC : AT Audio Mode select GPIO sensing reverse polarity. \n
                                                                    \#DESC_END

                                                                    \par
                                                                    \#BIT_PARAM : Reserved \n
                                                                    \#BIT_POS : 4 \n
                                                                    \#BIT_SIZE : 4 \n
                                                                    \#BIT_DESC : Reserved. \n
                                                                    \#DESC_END
                                                        	      */
                                                	          
    BTN_GPIO_CFG_KEY_RESERVED2                          = 0x0C, /**<\#PARAM_NAME : BTN_GPIO_CFG_KEY_RESERVED2 \n
                                                                    \#ALIAS : reserved \n
                                                                    \#PARAM_TYPE : Public \n
                                                                    \#PARAM_DESC : reserved \n
                                                                    \#DESC_END
                                                                    \#GROUP_ID : 0x09 \n
                                                                    \#KEY_ID : 0x0C \n
                                                        	    */
                                                	          
    BTN_GPIO_CFG_KEY_RESERVED3                          = 0x0D,  /**<\#PARAM_NAME : BTN_GPIO_CFG_KEY_RESERVED3 \n
                                                                    \#ALIAS : reserved \n
                                                                    \#PARAM_TYPE : Public \n
                                                                    \#PARAM_DESC : reserved \n
                                                                    \#DESC_END
                                                                    \#GROUP_ID : 0x09 \n
                                                                    \#KEY_ID : 0x0D \n
                                                        	    */
                                                	          
    BTN_GPIO_CFG_KEY_RESERVED4                          = 0x0E,  /**<\#PARAM_NAME : BTN_GPIO_CFG_KEY_RESERVED4 \n
                                                                    \#ALIAS : reserved \n
                                                                    \#PARAM_TYPE : Public \n
                                                                    \#PARAM_DESC : reserved \n
                                                                    \#DESC_END
                                                                    \#GROUP_ID : 0x09 \n
                                                                    \#KEY_ID : 0x0E \n
                                                        	    */
                                                	          
    BTN_GPIO_CFG_KEY_RESERVED5                          = 0x0F, /**<\#PARAM_NAME : BTN_GPIO_CFG_KEY_RESERVED5 \n
                                                                    \#ALIAS : reserved \n
                                                                    \#PARAM_TYPE : Public \n
                                                                    \#PARAM_DESC : reserved \n
                                                                    \#DESC_END
                                                                    \#GROUP_ID : 0x09 \n
                                                                    \#KEY_ID : 0x0F \n
                                                        	    */
                                                	          
    BTN_GPIO_CFG_KEY_RESERVED6                          = 0x10,  /**<\#PARAM_NAME : BTN_GPIO_CFG_KEY_RESERVED6 \n
                                                                    \#ALIAS : reserved \n
                                                                    \#PARAM_TYPE : Public \n
                                                                    \#PARAM_DESC : reserved \n
                                                                    \#DESC_END
                                                                    \#GROUP_ID : 0x09 \n
                                                                    \#KEY_ID : 0x10 \n
                                                        	    */
                                                	          
	BTN_GPIO_CFG_KEY_ENTER_PAIRING_PRESS_TIME           = 0x11, /**<\#PARAM_NAME : BTN_GPIO_CFG_KEY_ENTER_PAIRING_PRESS_TIME \n
                                                                    \#ALIAS : BT Classic Pairing \n
                                                                    \#PARAM_TYPE : Public \n
                                                                    \#PARAM_DESC : If the power button is pressed over this time in OFF mode, the speaker will enter pairing mode (unit in 80ms) \n
                                                                                   PS: the real time will larger than this interval around 1second due to system initialization. \n
                                                                    \#DESC_END
                                                                    \#GROUP_ID : 0x09 \n
                                                                    \#KEY_ID : 0x11 \n
                                                        	    */
                                                	          
	BTN_GPIO_CFG_KEY_RESERVED7                          = 0x12, /**<\#PARAM_NAME : BTN_GPIO_CFG_KEY_RESERVED7 \n
                                                                    \#ALIAS : reserved \n
                                                                    \#PARAM_TYPE : Public \n
                                                                    \#PARAM_DESC : reserved \n
                                                                    \#DESC_END
                                                                    \#GROUP_ID : 0x09 \n
                                                                    \#KEY_ID : 0x12 \n
                                                        	    */
                                                	          
	BTN_GPIO_CFG_KEY_RESERVED8                          = 0x13, /**<\#PARAM_NAME : BTN_GPIO_CFG_KEY_RESERVED8 \n
                                                                    \#ALIAS : reserved \n
                                                                    \#PARAM_TYPE : Public \n
                                                                    \#PARAM_DESC : reserved \n
                                                                    \#DESC_END
                                                                    \#GROUP_ID : 0x09 \n
                                                                    \#KEY_ID : 0x13 \n
                                                        	    */
                                                	          
	BTN_GPIO_CFG_KEY_RESERVED9                          = 0x14, /**<\#PARAM_NAME : BTN_GPIO_CFG_KEY_RESERVED9 \n
                                                                    \#ALIAS : reserved \n
                                                                    \#PARAM_TYPE : Public \n
                                                                    \#PARAM_DESC : reserved. \n
                                                                    \#DESC_END
                                                                    \#GROUP_ID : 0x09 \n
                                                                    \#KEY_ID : 0x14 \n
                                                        	    */
                                                	          
	BTN_GPIO_CFG_KEY_RESERVED10                          = 0x15, /**<\#PARAM_NAME : BTN_GPIO_CFG_KEY_RESERVED10 \n
                                                                    \#ALIAS : reserved \n
                                                                    \#PARAM_TYPE : Public \n
                                                                    \#PARAM_DESC : reserved \n
                                                                    \#DESC_END
                                                                    \#GROUP_ID : 0x09 \n
                                                                    \#KEY_ID : 0x15 \n
                                                        	    */
                                                	          
	BTN_GPIO_CFG_KEY_RESERVED11                         = 0x16, /**<\#PARAM_NAME : BTN_GPIO_CFG_KEY_RESERVED11 \n
                                                                    \#ALIAS : reserved \n
                                                                    \#PARAM_TYPE : Public \n
                                                                    \#PARAM_DESC : reserved \n
                                                                    \#DESC_END
                                                                    \#GROUP_ID : 0x09 \n
                                                                    \#KEY_ID : 0x16 \n
                                                        	    */
                                                	          
	BTN_GPIO_CFG_KEY_CHARGER_INDICATION_IO              = 0x17, /**<\#PARAM_NAME : BTN_GPIO_CFG_KEY_CHARGER_INDICATION_IO \n
                                                                    \#ALIAS : GPIO CHARGER INDICATION IO \n
                                                                    \#PARAM_TYPE : Public \n
                                                                    \#PARAM_DESC : GPIO configuration for extra charger indication. \n
                                                                    \#DESC_END
                                                                    \#GROUP_ID : 0x09 \n
                                                                    \#KEY_ID : 0x17 \n
                                                        	    */
                                                	          
	BTN_GPIO_CFG_KEY_AUX_IN_INDICATION_IO               = 0x18, /**<\#PARAM_NAME : BTN_GPIO_CFG_KEY_AUX_IN_INDICATION_IO \n
                                                                    \#ALIAS : GPIO AUX IN INDICATION IO \n
                                                                    \#PARAM_TYPE : Public \n
                                                                    \#PARAM_DESC : GPIO configuration for aux in indication. \n
                                                                    \#DESC_END
                                                                    \#GROUP_ID : 0x09 \n
                                                                    \#KEY_ID : 0x18 \n
                                                        	    */
                                                	          
	BTN_GPIO_CFG_KEY_RESERVED12                         = 0x19, /**<\#PARAM_NAME : BTN_GPIO_CFG_KEY_RESERVED12 \n
                                                                    \#ALIAS : reserved \n
                                                                    \#PARAM_TYPE : Public \n
                                                                    \#PARAM_DESC : reserved \n
                                                                    \#DESC_END
                                                                    \#GROUP_ID : 0x09 \n
                                                                    \#KEY_ID : 0x19 \n
                                                        	    */
                                                	          
	BTN_GPIO_CFG_KEY_AUX_IN_DETECTION_IO                = 0x1A, /**<\#PARAM_NAME : BTN_GPIO_CFG_KEY_AUX_IN_DETECTION_IO \n
                                                                    \#ALIAS : GPIO AUX IN DETECTION IO \n
                                                                    \#PARAM_TYPE : Public \n
                                                                    \#PARAM_DESC : GPIO configuration for aux in detection. \n
                                                                    \#DESC_END
                                                                    \#GROUP_ID : 0x09 \n
                                                                    \#KEY_ID : 0x1A \n
                                                        	    */
                                                	          
	BTN_GPIO_CFG_KEY_UART_TX_INDICATION_IO              = 0x1B, /**<\#PARAM_NAME : BTN_GPIO_CFG_KEY_UART_TX_INDICATION_IO \n
                                                                    \#ALIAS : GPIO UART TX INDICATION IO \n
                                                                    \#PARAM_TYPE : Public \n
                                                                    \#PARAM_DESC : GPIO configuration for UART TX indication (BM8x TX). \n
                                                                    \#DESC_END
                                                                    \#GROUP_ID : 0x09 \n
                                                                    \#KEY_ID : 0x1B \n
                                                        	    */
                                                	          
	BTN_GPIO_CFG_KEY_RESERVED13                         = 0x1C, /**<\#PARAM_NAME : BTN_GPIO_CFG_KEY_RESERVED13 \n
                                                                    \#ALIAS : reserved \n
                                                                    \#PARAM_TYPE : Public \n
                                                                    \#PARAM_DESC : reserved \n
                                                                    \#DESC_END
                                                                    \#GROUP_ID : 0x09 \n
                                                                    \#KEY_ID : 0x1C \n
                                                        	    */
                                                	          
	BTN_GPIO_CFG_KEY_RESERVED                           = 0x1D, /**<\#PARAM_NAME : BTN_GPIO_CFG_KEY_RESERVED \n
                                                                    \#ALIAS : reserved \n
                                                                    \#PARAM_TYPE : Public \n
                                                                    \#PARAM_DESC : reserved \n
                                                                    \#DESC_END
                                                                    \#GROUP_ID : 0x09 \n
                                                                    \#KEY_ID : 0x1D \n
                                                        	    */
    BTN_GPIO_CFG_KEY_AT_APP_MODE_SELECT_IO              = 0x1E, /**<\#PARAM_NAME : BTN_GPIO_CFG_KEY_AT_APP_MODE_SELECT_IO \n
                                                                    \#ALIAS : GPIO AT APP MODE SELECT IO \n
                                                                    \#PARAM_TYPE : Public \n
                                                                    \#PARAM_DESC : GPIO configuration for AT Application Mode selection. \n
                                                                    \#DESC_END
                                                                    \#GROUP_ID : 0x09 \n
                                                                    \#KEY_ID : 0x1E \n
                                                        	    */
    BTN_GPIO_CFG_KEY_AT_AUDIO_INPUT_SOURCE_SELECT_IO    = 0x1F, /**<\#PARAM_NAME : BTN_GPIO_CFG_KEY_AT_AUDIO_INPUT_SOURCE_SELECT_IO \n
                                                                    \#ALIAS : GPIO AT AUDIO INPUT SOURCE SELECT IO \n
                                                                    \#PARAM_TYPE : Public \n
                                                                    \#PARAM_DESC : GPIO configuration for AT Audio Input Source selection (for A2dp Audio Encode and Transmit) \n
                                                                    \#DESC_END
                                                                    \#GROUP_ID : 0x09 \n
                                                                    \#KEY_ID : 0x1F \n
                                                        	    */                                               	          
    BTN_GPIO_CFG_KEY_BUTTON_OPERATION_NUM_AT_TXMODE     = 0x20, /**<\#PARAM_NAME :  BTN_GPIO_CFG_KEY_BUTTON_OPERATION_NUM_AT_TXMODE \n
                                                                    \#ALIAS : AT GPIO BUTTON OPERATION NUM \n
                                                                    \#PARAM_TYPE : Public \n
                                                                    \#PARAM_DESC : The number of button operation in BTN_GPIO_CFG_KEY_BUTTON_TABLE_0. \n
                                                                    \#DESC_END
                                                                    \#GROUP_ID : 0x09 \n
                                                                    \#KEY_ID : 0x20 \n
                                                                */
                                                              
    BTN_GPIO_CFG_KEY_BUTTON_TABLE_AT_TXMODE             = 0x21, /**<\#PARAM_NAME : BTN_GPIO_CFG_KEY_BUTTON_TABLE_AT_TXMODE \n
                                                                    \#ALIAS : AT GPIO BUTTON TABLE \n
                                                                    \#PARAM_TYPE : Public \n
                                                                    \#PARAM_DESC : structure of each button operation as below, it need 38 bytes for each operation. 0 ~ 228 (38*6) bytes. \n
                                                                                   Max to 16 button operations in three tables. \n
                                                                                   typedef struct _APP_Cfg_PhyButtonAction_T \n
                                                                                   { \n
                                                                                       u8 action1; \n
                                                                                       u8 action2; \n
                                                                                       u8 action3; \n
                                                                                   }APP_Cfg_ButtonAction_T; \n
                                                                                   
                                                                                   typedef struct _APP_Cfg_AtTxModeButtonTable_T \n
                                                                                   { \n
                                                                                       u8          portMask[4]; \n
                                                                                       u8          mfbMask; \n
                                                                                       u8          pressType; \n
                                                                                       u8          pressTimeUnit; \n
                                                                                       u8          holdPressCount; \n
                                                                                       APP_Cfg_ButtonAction_T  actionTable[BT_SRV_AT_TXMODE_STATUS_TOTAL]; \n
                                                                                   }APP_Cfg_AtTxModeButtonTable_T; \n
                                                                                   The BT_SRV_AT_TXMODE_STATUS_TOTAL is 0x0A.
                                                                    \#DESC_END
                                                                    \#GROUP_ID : 0x09 \n
                                                                    \#KEY_ID : 0x21 \n
                                                                */

    BTN_GPIO_CFG_KEY_END       
}BTN_GPIO_CFG_Key_IdDefinition_T;

/**@defgroup MODULE_BTN_GPIO_CFG_DEFAULT_VALUE BTN_GPIO Configuration Default Value
* @brief Default value definition of the module @ref CFG_MODULE_ID_BTN_GPIO.
* @{ */


#define BTN_GPIO_CFG_KEY_POWER_ON_INTERVAL_LEN                          0x01    /**< The default length of @ref BTN_GPIO_CFG_KEY_POWER_ON_INTERVAL. */
#define BTN_GPIO_CFG_KEY_POWER_ON_INTERVAL_DEFAULT_VALUE                0x1E    /**< The default value of @ref BTN_GPIO_CFG_KEY_POWER_ON_INTERVAL. */

#define BTN_GPIO_CFG_KEY_POWER_OFF_INTERVAL_LEN                         0x01    /**< The default length of @ref BTN_GPIO_CFG_KEY_POWER_OFF_INTERVAL. */
#define BTN_GPIO_CFG_KEY_POWER_OFF_INTERVAL_DEFAULT_VALUE               0x28    /**< The default value of @ref BTN_GPIO_CFG_KEY_POWER_OFF_INTERVAL. */

#define BTN_GPIO_CFG_KEY_RESET_TO_DEAFULT_TIMER_LEN                     0x01    /**< The default length of @ref BTN_GPIO_CFG_KEY_RESET_TO_DEAFULT_TIMER. */
#define BTN_GPIO_CFG_KEY_RESET_TO_DEAFULT_TIMER_DEFAULT_VALUE           0x80    /**< The default value of @ref BTN_GPIO_CFG_KEY_RESET_TO_DEAFULT_TIMER. */

#define BTN_GPIO_CFG_KEY_OUTPUT_INDICATION_TABLE_LEN                    0x10    /**< The default length of @ref BTN_GPIO_CFG_KEY_OUTPUT_INDICATION_TABLE. */
#define BTN_GPIO_CFG_KEY_OUTPUT_INDICATION_TABLE_DEFAULT_VALUE          GPIO_NULL, GPIO_VALUE_LOW, \
                                                                        GPIO_NULL, GPIO_VALUE_LOW, \
                                                                        GPIO_NULL, GPIO_VALUE_LOW, \
                                                                        GPIO_NULL, GPIO_VALUE_LOW, \
                                                                        GPIO_NULL, GPIO_VALUE_LOW, \
                                                                        GPIO_NULL, GPIO_VALUE_LOW, \
                                                                        GPIO_NULL, GPIO_VALUE_LOW, \
                                                                        GPIO_NULL, GPIO_VALUE_LOW    /**< The default value of @ref BTN_GPIO_CFG_KEY_OUTPUT_INDICATION_TABLE. */


#define BTN_GPIO_CFG_KEY_AT_OPTION_LEN                                  0x01    /**< The default length of @ref BTN_GPIO_CFG_KEY_OPTION. */
#define BTN_GPIO_CFG_KEY_AT_OPTION_DEFAULT_VALUE                        0x03    /**< The default value of @ref BTN_GPIO_CFG_KEY_OPTION. */

#define BTN_GPIO_CFG_KEY_RESERVED2_LEN                                  0x01    /**< The default length of @ref BTN_GPIO_CFG_KEY_RESERVED2. */
#define BTN_GPIO_CFG_KEY_RESERVED2_DEFAULT_VALUE                        0x00    /**< The default value of @ref BTN_GPIO_CFG_KEY_RESERVED2. */

#define BTN_GPIO_CFG_KEY_RESERVED3_LEN                                  0x01    /**< The default length of @ref BTN_GPIO_CFG_KEY_RESERVED3. */
#define BTN_GPIO_CFG_KEY_RESERVED3_DEFAULT_VALUE                        0x00    /**< The default value of @ref BTN_GPIO_CFG_KEY_RESERVED3. */

#define BTN_GPIO_CFG_KEY_RESERVED4_LEN                                  0x01    /**< The default length of @ref BTN_GPIO_CFG_KEY_RESERVED4. */
#define BTN_GPIO_CFG_KEY_RESERVED4_DEFAULT_VALUE                        0x00    /**< The default value of @ref BTN_GPIO_CFG_KEY_RESERVED4. */

#define BTN_GPIO_CFG_KEY_RESERVED5_LEN                                  0x01    /**< The default length of @ref BTN_GPIO_CFG_KEY_RESERVED5. */
#define BTN_GPIO_CFG_KEY_RESERVED5_DEFAULT_VALUE                        0x00    /**< The default value of @ref BTN_GPIO_CFG_KEY_RESERVED5. */

#define BTN_GPIO_CFG_KEY_RESERVED6_LEN                                  0x01    /**< The default length of @ref BTN_GPIO_CFG_KEY_RESERVED6. */
#define BTN_GPIO_CFG_KEY_RESERVED6_DEFAULT_VALUE                        0x00    /**< The default value of @ref BTN_GPIO_CFG_KEY_RESERVED6. */

#define BTN_GPIO_CFG_KEY_ENTER_PAIRING_PRESS_TIME_LEN                   0x01    /**< The default length of @ref BTN_GPIO_CFG_KEY_ENTER_PAIRING_PRESS_TIME. */
#define BTN_GPIO_CFG_KEY_ENTER_PAIRING_PRESS_TIME_DEFAULT_VALUE         0x32    /**< The default value of @ref BTN_GPIO_CFG_KEY_ENTER_PAIRING_PRESS_TIME_LEN. */

#define BTN_GPIO_CFG_KEY_RESERVED7_LEN                                  0x01    /**< The default length of @ref BTN_GPIO_CFG_KEY_RESERVED7. */
#define BTN_GPIO_CFG_KEY_RESERVED7_DEFAULT_VALUE                        GPIO_NULL    /**< The default value of @ref BTN_GPIO_CFG_KEY_RESERVED7. */

#define BTN_GPIO_CFG_KEY_RESERVED8_LEN                                  0x01    /**< The default length of @ref BTN_GPIO_CFG_KEY_RESERVED8. */
#define BTN_GPIO_CFG_KEY_RESERVED8_DEFAULT_VALUE                        GPIO_NULL    /**< The default value of @ref BTN_GPIO_CFG_KEY_RESERVED8. */

#define BTN_GPIO_CFG_KEY_RESERVED9_LEN                                  0x02    /**< The default length of @ref BTN_GPIO_CFG_KEY_RESERVED9. */
#define BTN_GPIO_CFG_KEY_RESERVED9_DEFAULT_VALUE                        GPIO_NULL, GPIO_NULL    /**< The default value of @ref BTN_GPIO_CFG_KEY_RESERVED9. */

#define BTN_GPIO_CFG_KEY_RESERVED10_LEN                                 0x01    /**< The default length of @ref BTN_GPIO_CFG_KEY_RESERVED10. */
#define BTN_GPIO_CFG_KEY_RESERVED10_DEFAULT_VALUE                       GPIO_NULL    /**< The default value of @ref BTN_GPIO_CFG_KEY_RESERVED10. */

#define BTN_GPIO_CFG_KEY_RESERVED11_LEN                                 0x02    /**< The default length of @ref BTN_GPIO_CFG_KEY_RESERVED11. */
#define BTN_GPIO_CFG_KEY_RESERVED11_DEFAULT_VALUE                       GPIO_NULL, GPIO_NULL    /**< The default value of @ref BTN_GPIO_CFG_KEY_RESERVED11. */

#define BTN_GPIO_CFG_KEY_CHARGER_INDICATION_IO_LEN                      0x01    /**< The default length of @ref BTN_GPIO_CFG_KEY_CHARGER_INDICATION_IO. */
#define BTN_GPIO_CFG_KEY_CHARGER_INDICATION_IO_DEFAULT_VALUE            GPIO_NULL    /**< The default value of @ref BTN_GPIO_CFG_KEY_CHARGER_INDICATION_IO. */

#define BTN_GPIO_CFG_KEY_AUX_IN_INDICATION_IO_LEN                       0x01    /**< The default length of @ref BTN_GPIO_CFG_KEY_AUX_IN_INDICATION_IO. */
#define BTN_GPIO_CFG_KEY_AUX_IN_INDICATION_IO_DEFAULT_VALUE             GPIO_NULL    /**< The default value of @ref BTN_GPIO_CFG_KEY_AUX_IN_INDICATION_IO. */

#define BTN_GPIO_CFG_KEY_RESERVED12_LEN                                 0x01    /**< The default length of @ref BTN_GPIO_CFG_KEY_RESERVED12. */
#define BTN_GPIO_CFG_KEY_RESERVED12_DEFAULT_VALUE                       GPIO_NULL    /**< The default value of @ref BTN_GPIO_CFG_KEY_RESERVED12. */

#define BTN_GPIO_CFG_KEY_AUX_IN_DETECTION_IO_LEN                        0x01    /**< The default length of @ref BTN_GPIO_CFG_KEY_AUX_IN_DETECTION_IO. */
#define BTN_GPIO_CFG_KEY_AUX_IN_DETECTION_IO_DEFAULT_VALUE              GPIO_P32    /**< The default value of @ref BTN_GPIO_CFG_KEY_AUX_IN_DETECTION_IO. */

#define BTN_GPIO_CFG_KEY_UART_TX_INDICATION_IO_LEN                      0x01    /**< The default length of @ref BTN_GPIO_CFG_KEY_UART_TX_INDICATION_IO. */
#define BTN_GPIO_CFG_KEY_UART_TX_INDICATION_IO_DEFAULT_VALUE            GPIO_NULL    /**< The default value of @ref BTN_GPIO_CFG_KEY_UART_TX_INDICATION_IO. */

#define BTN_GPIO_CFG_KEY_RESERVED13_LEN                                 0x01    /**< The default length of @ref BTN_GPIO_CFG_KEY_RESERVED13. */
#define BTN_GPIO_CFG_KEY_RESERVED13_DEFAULT_VALUE                       GPIO_NULL    /**< The default value of @ref BTN_GPIO_CFG_KEY_RESERVED13. */

#define BTN_GPIO_CFG_KEY_BUTTON_OPERATION_NUM_0_LEN                     0x01    /**< The default length of @ref BTN_GPIO_CFG_KEY_BUTTON_OPERATION_NUM_0. */
#define BTN_GPIO_CFG_KEY_BUTTON_OPERATION_NUM_0_DEFAULT_VALUE           0x06    /**< The default value of @ref BTN_GPIO_CFG_KEY_BUTTON_OPERATION_NUM_0. */

#define BTN_GPIO_CFG_KEY_BUTTON_TABLE_0_LEN                             0xE4    /**< The default length of @ref BTN_GPIO_CFG_KEY_BUTTON_TABLE_0. */
#define BTN_GPIO_CFG_KEY_BUTTON_TABLE_0_DEFAULT_VALUE \
    /* MFB (B0) */ \
        0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x0D, 0x04, \
            0x0A, 0x5D, 0x00, \
            0x0B, 0x0B, 0x00, \
            0x04, 0x05, 0x00, \
            0x06, 0x06, 0x00, \
            0x06, 0x0D, 0x00, \
            0x06, 0x0D, 0x00, \
            0x06, 0x0D, 0x00, \
            0x06, 0x0D, 0x00, \
            0x06, 0x0D, 0x00, \
            0x06, 0x0D, 0x00, \
    /* PLAY_PAUSE (B1) //P0_2 */ \
        0x04, 0x00, 0x00, 0x00, 0x00, 0x01, 0x19, 0x04, \
            0x32, 0x33, 0x00, \
            0x00, 0x00, 0x00, \
            0x00, 0x00, 0x00, \
            0x00, 0x00, 0x00, \
            0x00, 0x00, 0x00, \
            0x00, 0x00, 0x00, \
            0x00, 0x00, 0x00, \
            0x00, 0x00, 0x00, \
            0x00, 0x00, 0x00, \
            0x00, 0x00, 0x00, \
    /* REV (B5) //P0_3 */ \
        0x08, 0x00, 0x00, 0x00, 0x00, 0x01, 0x19, 0x04, \
            0x35, 0x37, 0x00, \
            0x00, 0x00, 0x00, \
            0x00, 0x00, 0x00, \
            0x00, 0x00, 0x00, \
            0x00, 0x12, 0x00, \
            0x00, 0x12, 0x00, \
            0x00, 0x12, 0x00, \
            0x00, 0x12, 0x00, \
            0x0E, 0x12, 0x00, \
            0x0E, 0x12, 0x00, \
    /* FWD (B4) //P0_1 */ \
        0x02, 0x00, 0x00, 0x00, 0x00, 0x01, 0x19, 0x04, \
            0x34, 0x36, 0x00, \
            0x00, 0x00, 0x00, \
            0x00, 0x00, 0x00, \
            0x00, 0x00, 0x00, \
            0x00, 0x11, 0x00, \
            0x00, 0x11, 0x00, \
            0x00, 0x11, 0x00, \
            0x00, 0x11, 0x00, \
            0x00, 0x11, 0x00, \
            0x00, 0x11, 0x00, \
    /* VOL_DN (B3) //P0_5 */ \
        0x20, 0x00, 0x00, 0x00, 0x00, 0x01, 0x19, 0x04, \
            0x31, 0xFB, 0x00, \
            0x31, 0x00, 0x00, \
            0x31, 0x00, 0x00, \
            0x31, 0x00, 0x00, \
            0x31, 0x08, 0x00, \
            0x31, 0x08, 0x00, \
            0x31, 0x08, 0x00, \
            0x31, 0x08, 0x00, \
            0x31, 0x08, 0x00, \
            0x31, 0x08, 0x00, \
    /* VOL_UP (B2) // P2_7 */ \
        0x00,0x00, 0x80,0x00, 0x00, 0x01, 0x19, 0x04, \
            0x30, 0xFC, 0x00, \
            0x30, 0x00, 0x00, \
            0x30, 0x00, 0x00, \
            0x30, 0x00, 0x00, \
            0x30, 0x09, 0x00, \
            0x30, 0x09, 0x00, \
            0x30, 0x09, 0x00, \
            0x30, 0x09, 0x00, \
            0x30, 0x09, 0x00, \
            0x30, 0x09, 0x00    /**< The default value of @ref BTN_GPIO_CFG_KEY_BUTTON_TABLE_0. */





#define BTN_GPIO_CFG_KEY_BUTTON_OPERATION_NUM_1_LEN                             0x01    /**< The default length of @ref BTN_GPIO_CFG_KEY_BUTTON_OPERATION_NUM_1. */
#define BTN_GPIO_CFG_KEY_BUTTON_OPERATION_NUM_1_DEFAULT_VALUE                   0x01    /**< The default value of @ref BTN_GPIO_CFG_KEY_BUTTON_OPERATION_NUM_1. */

#define BTN_GPIO_CFG_KEY_BUTTON_TABLE_1_LEN                                     0x26    /**< The default length of @ref BTN_GPIO_CFG_KEY_BUTTON_TABLE_1. */
#define BTN_GPIO_CFG_KEY_BUTTON_TABLE_1_DEFAULT_VALUE                           \
        /* VOL_DN (B3) + VOL_UP (B2) //P0_5 & P2_7*/ \
        0x20, 0x00, 0x80, 0x00, 0x00, 0x01, 0x19, 0x04, \
            0x00, 0xF6, 0x00, \
            0x00, 0x00, 0x00, \
            0x00, 0x00, 0x00, \
            0x00, 0x00, 0x00, \
            0x00, 0x00, 0x00, \
            0x00, 0x00, 0x00, \
            0x00, 0x00, 0x00, \
            0x00, 0x00, 0x00, \
            0x00, 0x00, 0x00, \
            0x00, 0x00, 0x00  /**< The default value of @ref BTN_GPIO_CFG_KEY_BUTTON_TABLE_1. */
            

#define BTN_GPIO_CFG_KEY_BUTTON_OPERATION_NUM_2_LEN                             0x01    /**< The default length of @ref BTN_GPIO_CFG_KEY_BUTTON_OPERATION_NUM_2. */
#define BTN_GPIO_CFG_KEY_BUTTON_OPERATION_NUM_2_DEFAULT_VALUE                   0x00    /**< The default value of @ref BTN_GPIO_CFG_KEY_BUTTON_OPERATION_NUM_2. */

#define BTN_GPIO_CFG_KEY_BUTTON_TABLE_2_LEN                                     0x01    /**< The default length of @ref BTN_GPIO_CFG_KEY_BUTTON_TABLE_2. */
#define BTN_GPIO_CFG_KEY_BUTTON_TABLE_2_DEFAULT_VALUE                           0x00    /**< The default value of @ref BTN_GPIO_CFG_KEY_BUTTON_TABLE_2. */

#define BTN_GPIO_CFG_KEY_RESERVED_LEN                                           0x02    /**< The default length of @ref BTN_GPIO_CFG_KEY_RESERVED. */
#define BTN_GPIO_CFG_KEY_RESERVED_DEFAULT_VALUE                                 GPIO_NULL, GPIO_NULL    /**< The default value of @ref BTN_GPIO_CFG_KEY_RESERVED. */

#define BTN_GPIO_CFG_KEY_AT_APP_MODE_SELECT_IO_LEN                              0x01
#define BTN_GPIO_CFG_KEY_AT_APP_MODE_SELECT_IO_DEFAULT_VALUE                    GPIO_P16

#define BTN_GPIO_CFG_KEY_AT_AUDIO_INPUT_SOURCE_SELECT_IO_LEN                    0x01
#define BTN_GPIO_CFG_KEY_AT_AUDIO_INPUT_SOURCE_SELECT_IO_DEFAULT_VALUE          GPIO_P27

#define BTN_GPIO_CFG_KEY_BUTTON_OPERATION_NUM_AT_TXMODE_LEN                     0x01    /**< The default length of @ref BTN_GPIO_CFG_KEY_BUTTON_OPERATION_NUM_0. */
#define BTN_GPIO_CFG_KEY_BUTTON_OPERATION_NUM_AT_TXMODE_DEFAULT_VALUE           0x01    /**< The default value of @ref BTN_GPIO_CFG_KEY_BUTTON_OPERATION_NUM_0. */

#define BTN_GPIO_CFG_KEY_BUTTON_TABLE_AT_TXMODE_LEN                             0x26    /**< The default length of @ref BTN_GPIO_CFG_KEY_BUTTON_TABLE_0. */
#define BTN_GPIO_CFG_KEY_BUTTON_TABLE_AT_TXMODE_DEFAULT_VALUE \
    /* MFB (B0) */ \
        0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x0D, 0x04, \
            0x6C, 0x7E, 0x00, \
            0x7F, 0x00, 0x00, \
            0x41, 0x00, 0x00, \
            0x00, 0x00, 0x00, \
            0x00, 0x00, 0x00, \
            0x00, 0x00, 0x00, \
            0x00, 0x00, 0x00, \
            0x00, 0x00, 0x00, \
            0x00, 0x00, 0x00, \
            0x00, 0x00, 0x00

/** @} */
/** @} */

/** \cond NON_DOC */

#define CFG_BTN_GPIO_MODULE_TOTAL_NUM_KEYS   (BTN_GPIO_CFG_KEY_END - 1)

#define CFG_BTN_GPIO_MODULE_TOTAL_SIZE  ((CFG_BTN_GPIO_MODULE_TOTAL_NUM_KEYS*SIZEOF_CFG_KEY_STRUCT) +  \
                                        BTN_GPIO_CFG_KEY_BUTTON_OPERATION_NUM_0_LEN +               \
                                        BTN_GPIO_CFG_KEY_BUTTON_TABLE_0_LEN +                       \
                                        BTN_GPIO_CFG_KEY_BUTTON_OPERATION_NUM_1_LEN +               \
                                        BTN_GPIO_CFG_KEY_BUTTON_TABLE_1_LEN +                       \
                                        BTN_GPIO_CFG_KEY_BUTTON_OPERATION_NUM_2_LEN +               \
                                        BTN_GPIO_CFG_KEY_BUTTON_TABLE_2_LEN +                       \
                                        BTN_GPIO_CFG_KEY_POWER_ON_INTERVAL_LEN +                    \
                                        BTN_GPIO_CFG_KEY_POWER_OFF_INTERVAL_LEN +                   \
                                        BTN_GPIO_CFG_KEY_RESET_TO_DEAFULT_TIMER_LEN +               \
                                        BTN_GPIO_CFG_KEY_OUTPUT_INDICATION_TABLE_LEN +              \
                                        BTN_GPIO_CFG_KEY_AT_OPTION_LEN +                            \
                                        BTN_GPIO_CFG_KEY_RESERVED2_LEN +                              \
                                        BTN_GPIO_CFG_KEY_RESERVED3_LEN +             \
                                        BTN_GPIO_CFG_KEY_RESERVED4_LEN +             \
                                        BTN_GPIO_CFG_KEY_RESERVED5_LEN +            \
                                        BTN_GPIO_CFG_KEY_RESERVED6_LEN +            \
                                        BTN_GPIO_CFG_KEY_ENTER_PAIRING_PRESS_TIME_LEN +             \
                                        BTN_GPIO_CFG_KEY_RESERVED7_LEN +                      \
                                        BTN_GPIO_CFG_KEY_RESERVED8_LEN +                     \
                                        BTN_GPIO_CFG_KEY_RESERVED9_LEN +                 \
                                        BTN_GPIO_CFG_KEY_RESERVED10_LEN +                            \
                                        BTN_GPIO_CFG_KEY_RESERVED11_LEN +                  \
                                        BTN_GPIO_CFG_KEY_CHARGER_INDICATION_IO_LEN +                \
                                        BTN_GPIO_CFG_KEY_AUX_IN_INDICATION_IO_LEN +                 \
                                        BTN_GPIO_CFG_KEY_RESERVED12_LEN +                          \
                                        BTN_GPIO_CFG_KEY_AUX_IN_DETECTION_IO_LEN +                  \
                                        BTN_GPIO_CFG_KEY_UART_TX_INDICATION_IO_LEN +                \
                                        BTN_GPIO_CFG_KEY_RESERVED13_LEN +                \
                                        BTN_GPIO_CFG_KEY_AT_AUDIO_INPUT_SOURCE_SELECT_IO_LEN +      \
                                        BTN_GPIO_CFG_KEY_AT_APP_MODE_SELECT_IO_LEN +                \
                                        BTN_GPIO_CFG_KEY_RESERVED_LEN +                             \
                                        BTN_GPIO_CFG_KEY_BUTTON_TABLE_AT_TXMODE_LEN +               \
                                        BTN_GPIO_CFG_KEY_BUTTON_OPERATION_NUM_AT_TXMODE_LEN)

//BTN_GPIO Config keys definition
#define CFG_BTN_GPIO_MODULE_DEFAULT_VALUE   CFG_MODULE_ID_BTN_GPIO,               /*moduleID*/   \
                                            CFG_BTN_GPIO_MODULE_TOTAL_NUM_KEYS,   /*numKeys*/    \
                                            (CFG_BTN_GPIO_MODULE_TOTAL_SIZE >> 8),  /*moduleSize*/  \
                                            CFG_BTN_GPIO_MODULE_TOTAL_SIZE,                      \
                                            /*CFG_KEYs[numKeys]*/                           \
                                             /*//ID                                             //Len                                                   //Value    */                                                     \
                                            BTN_GPIO_CFG_KEY_BUTTON_OPERATION_NUM_0,            BTN_GPIO_CFG_KEY_BUTTON_OPERATION_NUM_0_LEN,            BTN_GPIO_CFG_KEY_BUTTON_OPERATION_NUM_0_DEFAULT_VALUE,           \
                                            BTN_GPIO_CFG_KEY_BUTTON_TABLE_0,                    BTN_GPIO_CFG_KEY_BUTTON_TABLE_0_LEN,                    BTN_GPIO_CFG_KEY_BUTTON_TABLE_0_DEFAULT_VALUE,                   \
                                            BTN_GPIO_CFG_KEY_BUTTON_OPERATION_NUM_1,            BTN_GPIO_CFG_KEY_BUTTON_OPERATION_NUM_1_LEN,            BTN_GPIO_CFG_KEY_BUTTON_OPERATION_NUM_1_DEFAULT_VALUE,           \
                                            BTN_GPIO_CFG_KEY_BUTTON_TABLE_1,                    BTN_GPIO_CFG_KEY_BUTTON_TABLE_1_LEN,                    BTN_GPIO_CFG_KEY_BUTTON_TABLE_1_DEFAULT_VALUE,                   \
                                            BTN_GPIO_CFG_KEY_BUTTON_OPERATION_NUM_2,            BTN_GPIO_CFG_KEY_BUTTON_OPERATION_NUM_2_LEN,            BTN_GPIO_CFG_KEY_BUTTON_OPERATION_NUM_2_DEFAULT_VALUE,         \
                                            BTN_GPIO_CFG_KEY_BUTTON_TABLE_2,                    BTN_GPIO_CFG_KEY_BUTTON_TABLE_2_LEN,                    BTN_GPIO_CFG_KEY_BUTTON_TABLE_2_DEFAULT_VALUE,                 \
                                            BTN_GPIO_CFG_KEY_POWER_ON_INTERVAL,                 BTN_GPIO_CFG_KEY_POWER_ON_INTERVAL_LEN,                 BTN_GPIO_CFG_KEY_POWER_ON_INTERVAL_DEFAULT_VALUE,                \
                                            BTN_GPIO_CFG_KEY_POWER_OFF_INTERVAL,                BTN_GPIO_CFG_KEY_POWER_OFF_INTERVAL_LEN,                BTN_GPIO_CFG_KEY_POWER_OFF_INTERVAL_DEFAULT_VALUE,               \
                                            BTN_GPIO_CFG_KEY_RESET_TO_DEAFULT_TIMER,            BTN_GPIO_CFG_KEY_RESET_TO_DEAFULT_TIMER_LEN,            BTN_GPIO_CFG_KEY_RESET_TO_DEAFULT_TIMER_DEFAULT_VALUE,           \
                                            BTN_GPIO_CFG_KEY_OUTPUT_INDICATION_TABLE,           BTN_GPIO_CFG_KEY_OUTPUT_INDICATION_TABLE_LEN,           BTN_GPIO_CFG_KEY_OUTPUT_INDICATION_TABLE_DEFAULT_VALUE,          \
                                            BTN_GPIO_CFG_KEY_AT_OPTION,                         BTN_GPIO_CFG_KEY_AT_OPTION_LEN,                         BTN_GPIO_CFG_KEY_AT_OPTION_DEFAULT_VALUE,                        \
                                            BTN_GPIO_CFG_KEY_RESERVED2,                         BTN_GPIO_CFG_KEY_RESERVED2_LEN,                           BTN_GPIO_CFG_KEY_RESERVED2_DEFAULT_VALUE,                          \
                                            BTN_GPIO_CFG_KEY_RESERVED3,                         BTN_GPIO_CFG_KEY_RESERVED3_LEN,          BTN_GPIO_CFG_KEY_RESERVED3_DEFAULT_VALUE,         \
                                            BTN_GPIO_CFG_KEY_RESERVED4,                         BTN_GPIO_CFG_KEY_RESERVED4_LEN,          BTN_GPIO_CFG_KEY_RESERVED4_DEFAULT_VALUE,         \
                                            BTN_GPIO_CFG_KEY_RESERVED5,                         BTN_GPIO_CFG_KEY_RESERVED5_LEN,         BTN_GPIO_CFG_KEY_RESERVED5_DEFAULT_VALUE,        \
                                            BTN_GPIO_CFG_KEY_RESERVED6,                         BTN_GPIO_CFG_KEY_RESERVED6_LEN,         BTN_GPIO_CFG_KEY_RESERVED6_DEFAULT_VALUE,        \
                                            BTN_GPIO_CFG_KEY_ENTER_PAIRING_PRESS_TIME,          BTN_GPIO_CFG_KEY_ENTER_PAIRING_PRESS_TIME_LEN,          BTN_GPIO_CFG_KEY_ENTER_PAIRING_PRESS_TIME_DEFAULT_VALUE,         \
                                            BTN_GPIO_CFG_KEY_RESERVED7,                         BTN_GPIO_CFG_KEY_RESERVED7_LEN,                   BTN_GPIO_CFG_KEY_RESERVED7_DEFAULT_VALUE,                  \
                                            BTN_GPIO_CFG_KEY_RESERVED8,                         BTN_GPIO_CFG_KEY_RESERVED8_LEN,                  BTN_GPIO_CFG_KEY_RESERVED8_DEFAULT_VALUE,                 \
                                            BTN_GPIO_CFG_KEY_RESERVED9,                         BTN_GPIO_CFG_KEY_RESERVED9_LEN,              BTN_GPIO_CFG_KEY_RESERVED9_DEFAULT_VALUE,             \
                                            BTN_GPIO_CFG_KEY_RESERVED10,                        BTN_GPIO_CFG_KEY_RESERVED10_LEN,                         BTN_GPIO_CFG_KEY_RESERVED10_DEFAULT_VALUE,                        \
                                            BTN_GPIO_CFG_KEY_RESERVED11,                        BTN_GPIO_CFG_KEY_RESERVED11_LEN,               BTN_GPIO_CFG_KEY_RESERVED11_DEFAULT_VALUE,              \
                                            BTN_GPIO_CFG_KEY_CHARGER_INDICATION_IO,             BTN_GPIO_CFG_KEY_CHARGER_INDICATION_IO_LEN,             BTN_GPIO_CFG_KEY_CHARGER_INDICATION_IO_DEFAULT_VALUE,                    \
                                            BTN_GPIO_CFG_KEY_AUX_IN_INDICATION_IO,              BTN_GPIO_CFG_KEY_AUX_IN_INDICATION_IO_LEN,              BTN_GPIO_CFG_KEY_AUX_IN_INDICATION_IO_DEFAULT_VALUE,             \
                                            BTN_GPIO_CFG_KEY_RESERVED12,                        BTN_GPIO_CFG_KEY_RESERVED12_LEN,                       BTN_GPIO_CFG_KEY_RESERVED12_DEFAULT_VALUE,                      \                       
                                            BTN_GPIO_CFG_KEY_AUX_IN_DETECTION_IO,               BTN_GPIO_CFG_KEY_AUX_IN_DETECTION_IO_LEN,               BTN_GPIO_CFG_KEY_AUX_IN_DETECTION_IO_DEFAULT_VALUE,              \
                                            BTN_GPIO_CFG_KEY_UART_TX_INDICATION_IO,             BTN_GPIO_CFG_KEY_UART_TX_INDICATION_IO_LEN,             BTN_GPIO_CFG_KEY_UART_TX_INDICATION_IO_DEFAULT_VALUE,            \
                                            BTN_GPIO_CFG_KEY_RESERVED13,                        BTN_GPIO_CFG_KEY_RESERVED13_LEN,             BTN_GPIO_CFG_KEY_RESERVED13_DEFAULT_VALUE,            \
                                            BTN_GPIO_CFG_KEY_RESERVED,                          BTN_GPIO_CFG_KEY_RESERVED_LEN,                          BTN_GPIO_CFG_KEY_RESERVED_DEFAULT_VALUE,                         \
                                            BTN_GPIO_CFG_KEY_AT_APP_MODE_SELECT_IO,             BTN_GPIO_CFG_KEY_AT_APP_MODE_SELECT_IO_LEN,             BTN_GPIO_CFG_KEY_AT_APP_MODE_SELECT_IO_DEFAULT_VALUE,                   \
                                            BTN_GPIO_CFG_KEY_AT_AUDIO_INPUT_SOURCE_SELECT_IO,   BTN_GPIO_CFG_KEY_AT_AUDIO_INPUT_SOURCE_SELECT_IO_LEN,   BTN_GPIO_CFG_KEY_AT_AUDIO_INPUT_SOURCE_SELECT_IO_DEFAULT_VALUE,         \
                                            BTN_GPIO_CFG_KEY_BUTTON_OPERATION_NUM_AT_TXMODE,    BTN_GPIO_CFG_KEY_BUTTON_OPERATION_NUM_AT_TXMODE_LEN,    BTN_GPIO_CFG_KEY_BUTTON_OPERATION_NUM_AT_TXMODE_DEFAULT_VALUE,           \
                                            BTN_GPIO_CFG_KEY_BUTTON_TABLE_AT_TXMODE,            BTN_GPIO_CFG_KEY_BUTTON_TABLE_AT_TXMODE_LEN,            BTN_GPIO_CFG_KEY_BUTTON_TABLE_AT_TXMODE_DEFAULT_VALUE


typedef struct _APP_Cfg_PhyButtonAction_T
{
    uint8_t action1;
    uint8_t action2;
    uint8_t action3;
}APP_Cfg_ButtonAction_T;


typedef struct _APP_Cfg_ButtonTable_T
{
    uint8_t          portMask[4];
    uint8_t          mfbMask;
    uint8_t          pressType;
    uint8_t          pressTimeUnit;
    uint8_t          holdPressCount;
    APP_Cfg_ButtonAction_T  actionTable[BT_SRV_CALL_STATUS_TOTAL];
}APP_Cfg_ButtonTable_T;

typedef struct _APP_Cfg_MfbActionTimer_T
{
    uint8_t powerOn;
    uint8_t powerOff;
    uint8_t factoryReset;
    uint8_t powerOnPairing;
}APP_Cfg_MfbActionTimer_T;

typedef struct _APP_Cfg_GpioAssignment_T
{
    //GPIO_PinNum_T  slideSwitch;
    //GPIO_PinNum_T  nfcDetect;
    //GPIO_PinNum_T  buzzer;
    GPIO_PinNum_T  chargeCmpl;
    GPIO_PinNum_T  auxInLed;
    GPIO_PinNum_T  auxInDetect;
    //GPIO_PinNum_T  cpReset;
    //GPIO_PinNum_T  switchCtrl[2];
    GPIO_PinNum_T  uartCmdTx;
    //GPIO_PinNum_T  uartCmdRx;
}APP_Cfg_GpioAssignment_T;

#ifdef APP_AT_ENABLE

typedef struct _APP_Cfg_AtGpioAssignment_T
{
    GPIO_PinNum_T  atAppModeChangePin;
    GPIO_PinNum_T  atAudioInputSrcPin;
} APP_Cfg_AtGpioAssignment_T;

#endif

typedef struct _APP_Cfg_OutputInd_T
{
    GPIO_PinNum_T  ioPin;
    uint8_t             polarity;
}APP_Cfg_OutputInd_T;

typedef struct _APP_Cfg_GpioOutputIndTable_T
{
    APP_Cfg_OutputInd_T  audioInd;
    APP_Cfg_OutputInd_T  voiceInd;
    APP_Cfg_OutputInd_T  ringtoneInd;
    APP_Cfg_OutputInd_T  inCallInd;
    APP_Cfg_OutputInd_T  ampInd;
    APP_Cfg_OutputInd_T  hfLinkInd;
    APP_Cfg_OutputInd_T  a2dpLinkInd;
    APP_Cfg_OutputInd_T  btnInd;
}APP_Cfg_GpioOutputIndTable_T;

typedef struct _APP_Cfg_AtKeyOption_T
{
    uint8_t atAppModeChange:1;
    uint8_t atAudioInputSrcChange:1;
	uint8_t atAudioInputSrcReversePolarity:1;
	uint8_t atAppModeReversePolarity:1;
    uint8_t resvered1:4;
}APP_Cfg_AtKeyOption_T;

// Button Module Part
void APP_CFG_ReadBtnTableNum0(uint8_t XDATA *p_btnNum);
void APP_CFG_ReadBtnTable0(uint8_t XDATA *p_len, APP_Cfg_ButtonTable_T XDATA *p_param);
void APP_CFG_ReadBtnTableNum1(uint8_t XDATA *p_btnNum);
void APP_CFG_ReadBtnTable1(uint8_t XDATA *p_len, APP_Cfg_ButtonTable_T XDATA *p_param);
void APP_CFG_ReadBtnTableNum2(uint8_t XDATA *p_btnNum);
void APP_CFG_ReadBtnTable2(uint8_t XDATA *p_len, APP_Cfg_ButtonTable_T XDATA *p_param);
void APP_CFG_ReadMfbActionTimer(APP_Cfg_MfbActionTimer_T XDATA *p_param);
void APP_CFG_ReadGpioAssignment(APP_Cfg_GpioAssignment_T XDATA *p_param);
void APP_CFG_ReadGpioOutputIndTable(APP_Cfg_GpioOutputIndTable_T XDATA *p_param);
                    
#ifdef APP_AT_ENABLE
void APP_CFG_ReadAtGpioAssignment(APP_Cfg_AtGpioAssignment_T XDATA *p_param); 
void APP_CFG_ReadAtKeyOption(APP_Cfg_AtKeyOption_T XDATA *p_param);
void APP_CFG_ReadBtnTableNumAtTxMode(uint8_t XDATA *p_btnNum);
void APP_CFG_ReadBtnTableAtTxMode(uint8_t XDATA *p_len, APP_Cfg_ButtonTable_T XDATA *p_param);
#endif
/// \endcond

#endif//APP_CFG_BTN_GPIO_H

