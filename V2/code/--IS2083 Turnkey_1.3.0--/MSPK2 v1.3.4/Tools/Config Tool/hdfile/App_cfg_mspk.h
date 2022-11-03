/********************************************************************
  File Information:
    FileName:       app_cfg_mspk.h
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

#ifndef APP_CFG_MSPK_H
#define APP_CFG_MSPK_H

#include "audio_dsp.h"

/** \cond NON_DOC 

\#BUILD_TARGET : MSPKv2_App_Basic
\#BUILD_TARGET : MSPKv2_PBAP
\#BUILD_TARGET : AT_App
\#TARGET_START

\#REMOVE_PARAM : MSPK_CFG_KEY_CSB_GROUP_ID
\#REMOVE_PARAM : MSPK_CFG_KEY_MODEL_ID
\#REMOVE_PARAM : MSPK_CFG_KEY_CSB_RESERVED1
\#REMOVE_PARAM : MSPK_CFG_KEY_CSB_SYNC_TIMEOUT
\#REMOVE_PARAM : MSPK_CFG_KEY_CSB_SYNC_ONEKEY_SLAVE_TIMEOUT
\#REMOVE_PARAM : MSPK_CFG_KEY_NSPK_CHANNEL
\#REMOVE_PARAM : MSPK_CFG_KEY_SHS_STATE_AFTER_CSB_NG
\#REMOVE_PARAM : MSPK_CFG_KEY_SHS_STATE_AFTER_CSB_MASTER_OK
\#REMOVE_PARAM : MSPK_CFG_KEY_NSPK_CHANNEL_DEFAULT
\#REMOVE_PARAM : MSPK_CFG_KEY_CSB_TRIGGER_SYNC_SCHEME
\#REMOVE_BIT : ENABLE_MSPK_ROLE_BY_CONFIG_SETTING
\#REMOVE_BIT : ENABLE_MSPK_ROLE_BY_GPIO
\#REMOVE_BIT : ENABLE_MSPK_BACK_TO_LAST_MODE
\#REMOVE_PARAM : MSPK_CFG_KEY_CSB_TRIGGER_SYNC_ROLE_SETTING
\#REMOVE_BIT : MSPK_MASTER_BY_CONFIG
\#REMOVE_BIT : MSPK_SLAVE_BY_CONFIG
\#REMOVE_BIT : SAVE_MSPK_ROLE_WHEN_CONNECTED
\#REMOVE_BIT : MSPK_MSSTER_BY_LAST_MODE
\#REMOVE_BIT : MSPK_SLAVE_BY_LAST_MODE
\#REMOVE_PARAM : MSPK_CFG_KEY_OPTION1
\#REMOVE_BIT : MSPK_RECOVERY_CSB_LINK_AS_LINKLOSS
\#REMOVE_BIT : DEFAULT_MSPK_MODE
\#REMOVE_BIT : ENABLE_AUX_IN_CSB
\#REMOVE_BIT : ENABLE_CONCERT_BACK_To_LAST_MODE
\#REMOVE_BIT : ENABLE_BT_LINKBACK_IN_AUX_IN_CSB
\#REMOVE_PARAM : MSPK_CFG_KEY_OPTION2
\#REMOVE_BIT : ENALBE_CONCERT_MODE_ENDLESS_GROUPING
\#REMOVE_BIT : ENABLE_CONCERT_MODE_SLAVE_VOL_CTRL
\#REMOVE_BIT : ENABLE_AAC_IN_CSB
\#REMOVE_BIT : ENABLE_SEAMLESS_AUDIO_RESYNC
\#REMOVE_PARAM : MSPK_CFG_KEY_CSB_RESERVED2
\#REMOVE_PARAM : MSPK_CFG_KEY_CSB_ACCESS_CODE
\#REMOVE_PARAM : MSPK_CFG_KEY_CSB_POWER_SAVING_CONN_INT
\#REMOVE_PARAM : MSPK_CFG_KEY_ENDLESS_GROUPING_GAC_DAC_INT
\#REMOVE_PARAM : MSPK_CFG_KEY_CSB_CONCERT_EXT_GROUPING_TIME

\#TARGET_END

\#BUILD_TARGET : MSPKv2_GFP
\#BUILD_TARGET : MSPKv2_SPP
\#TARGET_START

\#REMOVE_PARAM : MSPK_CFG_KEY_CSB_RESERVED1
\#REMOVE_PARAM : MSPK_CFG_KEY_CSB_RESERVED2
\#REMOVE_PARAM : MSPK_CFG_KEY_CSB_CONCERT_EXT_GROUPING_TIME

\#TARGET_END

\endcond
*/

/**
  @addtogroup APP_CFG_MSPK MSPK Configuration
  @{
  @brief Definitions and prototypes for the MODULE_MSPK Configuration.
 */


/**
 * @brief Configuration key definition of the module @ref CFG_MODULE_ID_MSPK.
 *  
 */

//Config Key definiton of MODULE_MSPK(0x0A)
typedef enum _MSPK_CFG_Key_IdDefinition_T
{
    MSPK_CFG_KEY_CSB_GROUP_ID                   = 0x01, /**<\#PARAM_NAME : MSPK_CFG_KEY_CSB_GROUP_ID \n
                                                            \#ALIAS : General MSPK Mode Group Code \n
                                                            \#PARAM_TYPE : Public \n
                                                            \#PARAM_DESC : The group code for general CSB pairing. \n
                                                                           1. This is used to ensure the device which has the same Group code can pair \n
                                                                              with others.\n
                                                                           2. It is just for concert mode, that means you can have more than 1 slaves. \n
                                                            \#DESC_END
                                                            \#GROUP_ID : 0x0A \n
                                                            \#KEY_ID : 0x01 \n
                                                	    */
                                                	    
    MSPK_CFG_KEY_MODEL_ID                       = 0x02, /**<\#PARAM_NAME : MSPK_CFG_KEY_MODEL_ID \n
                                                            \#ALIAS : Stereo Mode Model ID \n
                                                            \#PARAM_TYPE : Public \n
                                                            \#PARAM_DESC : The model ID is used with MSPK_CFG_KEY_CSB_GROUP_ID as a group ID for Stereo Mode. \n
                                                                           1. This is used to ensure the device which has the same Group code can pair \n
                                                                              with others. \n
                                                                           2. It is just for stereo mode, that means you can just have 1 slave. \n
                                                            \#DESC_END
                                                            \#GROUP_ID : 0x0A \n
                                                            \#KEY_ID : 0x02 \n
                                                	    */
                                                	    
    MSPK_CFG_KEY_CSB_RESERVED1                  = 0x03, /**<\#PARAM_NAME :  MSPK_CFG_KEY_CSB_RESERVED1\n
                                                            \#ALIAS :  reserved\n
                                                            \#PARAM_TYPE : Public \n
                                                            \#PARAM_DESC : reserved \n
                                                            \#DESC_END
                                                            \#GROUP_ID : 0x0A \n
                                                            \#KEY_ID : 0x03 \n
                                                	    */
                                                	    
    MSPK_CFG_KEY_CSB_SYNC_TIMEOUT               = 0x04, /**<\#PARAM_NAME :  MSPK_CFG_KEY_CSB_SYNC_TIMEOUT\n
                                                            \#ALIAS :  MSPK Pairing Duration \n
                                                            \#PARAM_TYPE : Public \n
                                                            \#PARAM_DESC : The CSB pairing timeout. Unit: 5s\n
                                                            \#DESC_END
                                                            \#GROUP_ID : 0x0A \n
                                                            \#KEY_ID : 0x04 \n
                                                	    */
                                                	    
    MSPK_CFG_KEY_CSB_SYNC_ONEKEY_SLAVE_TIMEOUT  = 0x05, /**<\#PARAM_NAME :  MSPK_CFG_KEY_CSB_SYNC_ONEKEY_SLAVE_TIMEOUT\n
                                                            \#ALIAS :  MSPK Aux. Pairing Duration \n
                                                            \#PARAM_TYPE : Public \n
                                                            \#PARAM_DESC : The CSB pairing timeout of Slave role in One_Key_Operation. \n
                                                                           When the One_Key_Operation is triggered, it enters CSB pairing as Slave role first \n
                                                                           and then change to Master role after this timeout occurs. \n
                                                                           Unit 2s \n
                                                            \#DESC_END
                                                            \#GROUP_ID : 0x0A \n
                                                            \#KEY_ID : 0x05 \n
                                                	    */
                                                	    
    MSPK_CFG_KEY_NSPK_CHANNEL                   = 0x06, /**<\#PARAM_NAME :  MSPK_CFG_KEY_NSPK_CHANNEL\n
                                                            \#ALIAS :  MSPK Audio Channel \n
                                                            \#PARAM_TYPE : Public \n
                                                            \#PARAM_DESC : audio channel setting for multi-speaker \n
                                                                           Bit0 ~ bit3: the channel setting for Slave role in multi-speaker, the range is 0 ~ 3 \n
                                                                           Bit4 ~ bit7: the channel setting for Master role in multi-speaker, the range is 0 ~ 3 \n
                                                                           The channel definition: \n
                                                                           0: No Mixing, (L, R) \n
                                                                           1: only output audio from left channel ,(L, L) \n
                                                                           2: only output audio from right channel, (R,R) \n
                                                                           3: mix the audio of left channel and right channel, ( (L + R)/2 , (L + R)/2 ) \n
                                                            \#DESC_END
                                                            \#GROUP_ID : 0x0A \n
                                                            \#KEY_ID : 0x06 \n
                                                	    */
                                                	    
    MSPK_CFG_KEY_SHS_STATE_AFTER_CSB_NG         = 0x07, /**<\#PARAM_NAME :  MSPK_CFG_KEY_SHS_STATE_AFTER_CSB_NG\n
                                                            \#ALIAS :  MSPK SHS STATE AFTER CSB NG\n
                                                            \#PARAM_TYPE : Public \n
                                                            \#PARAM_DESC : Bit[0:1] The action after CSB creation fails or CSB link disconnects while CSB connection process is triggered in SHS STANDBY. \n
                                                                           Bit[2:3] The action after CSB creation fails or CSB link disconnects while CSB connection process is triggered in SHS CONNECTED. \n
                                                                           Bit[4:5] The action after CSB creation fails or CSB link disconnects while CSB connection process is triggered in SHS PAGING. \n
                                                                           Bit[6:7]  The action after CSB creation fails or CSB link disconnects while CSB connection process is triggered in SHS PAIRING. \n
                                                                           Actions for above options. \n
                                                                            00: enter SHS STANDBY mode. \n
                                                                            01: reconnect to last device if have and go to SHS CONNECTED mode. \n
                                                                            10: reconnect to last device if have. \n
                                                                            11: enter SHS PAGING mode \n 
                                                            \#DESC_END
                                                            \#GROUP_ID : 0x0A \n
                                                            \#KEY_ID : 0x07 \n
                                                	    */
                                                	    
    MSPK_CFG_KEY_SHS_STATE_AFTER_CSB_MASTER_OK  = 0x08, /**<\#PARAM_NAME :  MSPK_CFG_KEY_SHS_STATE_AFTER_CSB_MASTER_OK\n
                                                            \#ALIAS :  MSPK SHS STATE AFTER CSB MASTER OK\n
                                                            \#PARAM_TYPE : Public \n
                                                            \#PARAM_DESC :  Bit[0:1] The action after CSB link is created while CSB connection process is triggered in SHS STANDBY. \n
                                                                            Bit[2:3] The action after CSB link is created while CSB connection process is triggered in SHS CONNECTED. \n
                                                                            Bit[4:5] The action after CSB link is created while CSB connection process is triggered in SHS PAGING. \n
                                                                            Bit[6:7] The action after CSB link is created while CSB connection process is triggered in SHS PAIRING. \n
                                                                            Actions for above options. \n
                                                                             00: enter SHS STANDBY mode. \n
                                                                             01: reconnect to last device if have and go to SHS CONNECTED mode. \n
                                                                             10: reconnect to last device if have. \n
                                                                             11: enter SHS PAIRING mode. \n
                                                                           
                                                            \#DESC_END
                                                            \#GROUP_ID : 0x0A \n
                                                            \#KEY_ID : 0x08 \n
                                                	    */
                                                	    
    MSPK_CFG_KEY_NSPK_CHANNEL_DEFAULT           = 0x09, /**<\#PARAM_NAME :  MSPK_CFG_KEY_NSPK_CHANNEL_DEFAULT\n
                                                            \#ALIAS :  MSPK NSPK CHANNEL DEFAULT\n
                                                            \#PARAM_TYPE : Public \n
                                                            \#PARAM_DESC :  The default audio channel for 2-SPK used when the speaker master reset. \n
                                                                            This value will overwrite the NSPK_channel parameter. \n
                                                            \#DESC_END
                                                            \#GROUP_ID : 0x0A \n
                                                            \#KEY_ID : 0x09 \n
                                                	    */
                                                	    
    MSPK_CFG_KEY_CSB_TRIGGER_SYNC_SCHEME        = 0x0A, /**<\#PARAM_NAME :  MSPK_CFG_KEY_CSB_TRIGGER_SYNC_SCHEME \n
                                                            \#PARAM_TYPE : Public \n
                                                            \#GROUP_ID : 0x0A \n
                                                            \#KEY_ID : 0x0A \n

                                                            Bit Options:
                                                    	    \par
                                                    	    \#BIT_PARAM : ENABLE_MSPK_ROLE_BY_CONFIG_SETTING \n
                                                    	    \#BIT_ALIAS : Enable MSPK Role By Config Setting \n
                                                    	    \#BIT_POS : 0 \n
                                                    	    \#BIT_SIZE : 1 \n
                                                    	    \#BIT_DESC : This option is to pre-assign MSPK role in configuration settings. If this option is enabled (set to 1), \n
                                                                         it will check MSPK_MASTER_BY_CONFIG and MSPK_SLAVE_BY_CONFIG option to determine which role should be used when the speaker power on. \n
                                                    	    \#DESC_END

                                                    	    \par
                                                    	    \#BIT_PARAM : RESERVED \n
                                                    	    \#BIT_ALIAS : Reserved \n
                                                    	    \#BIT_POS : 1 \n
                                                    	    \#BIT_SIZE : 1 \n
                                                    	    \#BIT_DESC : Reserved.
                                                    	    \#DESC_END

                                                    	    \par
                                                    	    \#BIT_PARAM : ENABLE_MSPK_BACK_TO_LAST_MODE \n
                                                    	    \#BIT_ALIAS : Enable MSPK Back To Last Mode \n
                                                    	    \#BIT_POS : 2 \n
                                                    	    \#BIT_SIZE : 1 \n
                                                    	    \#BIT_DESC : If this option is enabled (set to 1), the speaker will store the MSPK role in configuration when it power off. \n
                                                                         Once the speaker power on again, the role and CSB link will be recovered if need. \n
                                                                         All above three options are checked when the speaker power on. If they conflict, the highest priority is MSPK_ROLE_BY_CONFIG_SETTING, \n
                                                                         second is MSPK_ROLE_BY_GPIO and the last is MSPK_BACK_TO_LAST_MODE.\n
                                                    	    \#DESC_END
                                                	    */
                                                	    
    MSPK_CFG_KEY_CSB_TRIGGER_SYNC_ROLE_SETTING  = 0x0B, /**<\#PARAM_NAME :  MSPK_CFG_KEY_CSB_TRIGGER_SYNC_ROLE_SETTING\n
                                                            \#PARAM_TYPE : Public \n
                                                            \#GROUP_ID : 0x0A \n
                                                            \#KEY_ID : 0x0B \n

                                                            Bit Options:
                                                    	    \par
                                                    	    \#BIT_PARAM : MSPK_MASTER_BY_CONFIG \n
                                                    	    \#BIT_ALIAS : Predefined MSPK Master By Config Setting \n
                                                    	    \#BIT_POS : 0 \n
                                                    	    \#BIT_SIZE : 1 \n
                                                    	    \#BIT_DESC : Predefine MSPK role as master role. This is used when the option \n
                                                    	                 ENABLE_MSPK_ROLE_BY_CONFIG_SETTING is enabled. \n
                                                    	    \#DESC_END

                                                    	    \par
                                                    	    \#BIT_PARAM : MSPK_SLAVE_BY_CONFIG \n
                                                    	    \#BIT_ALIAS : Predefined MSPK Slave By Config Setting \n
                                                    	    \#BIT_POS : 1 \n
                                                    	    \#BIT_SIZE : 1 \n
                                                    	    \#BIT_DESC : Predefine MSPK role as slave role. This is used when the option \n
                                                    	                 ENABLE_MSPK_ROLE_BY_CONFIG_SETTING is enabled. \n
                                                    	    \#DESC_END

                                                            \par
                                                            \#BIT_PARAM : SAVE_MSPK_ROLE_WHEN_CONNECTED \n
                                                            \#BIT_ALIAS : Save MSPK Role When Connected \n
                                                            \#BIT_POS : 2 \n
                                                            \#BIT_SIZE : 1 \n
                                                            \#BIT_DESC : Save MSPK role setting once CSB is connected. \n
                                                            \#DESC_END

                                                    	    \par
                                                    	    \#BIT_PARAM : MSPK_MSSTER_BY_LAST_MODE \n
                                                    	    \#BIT_ALIAS : MSPK Master By Last Mode \n
                                                    	    \#BIT_POS : 3 \n
                                                    	    \#BIT_SIZE : 1 \n
                                                    	    \#BIT_DESC : MSPK role is stored as master when the speaker as master powered off \n
                                                    	                 in MSPK connected state. \n
                                                    	    \#DESC_END

                                                    	    \par
                                                    	    \#BIT_PARAM : MSPK_SLAVE_BY_LAST_MODE \n
                                                    	    \#BIT_ALIAS : MSPK Slave By Last Mode \n
                                                    	    \#BIT_POS : 4 \n
                                                    	    \#BIT_SIZE : 1 \n
                                                    	    \#BIT_DESC : MSPK role is stored as slave when the speaker as slave powered off \n
                                                    	                 in MSPK connected state. \n
                                                    	    \#DESC_END
                                                	    */
 
    MSPK_CFG_KEY_OPTION1                        = 0x0C, /**<\#PARAM_NAME :  MSPK_CFG_KEY_OPTION1\n
                                                            \#PARAM_TYPE : Public \n
                                                            \#GROUP_ID : 0x0A \n
                                                            \#KEY_ID : 0x0C \n
                                                             Bit Options:
                                                    	    \par
                                                    	    \#BIT_PARAM : MSPK_RECOVERY_CSB_LINK_AS_LINKLOSS \n
                                                    	    \#BIT_ALIAS : Recover MSPK Link As Link Loss \n
                                                    	    \#BIT_POS : 0 \n
                                                    	    \#BIT_SIZE : 1 \n
                                                    	    \#BIT_DESC : If this option is enabled (set to 1), the speaker will try to recover the CSB link \n
                                                    	                 when the CSB link disconnects abnormally. Only for Stereo mode.\n
                                                    	    \#DESC_END

                                                    	    \par
                                                    	    \#BIT_PARAM : DEFAULT_MSPK_MODE \n
                                                    	    \#BIT_ALIAS : Default MSPK Mode \n
                                                    	    \#BIT_POS : 3 \n
                                                    	    \#BIT_SIZE : 1 \n
                                                    	    \#BIT_DESC : Use to indicate current CSB mode. \n
                                                                         0: Stereo mode. \n
                                                                         1: Concert mode. \n
                                                    	    \#DESC_END

                                                    	    \par
                                                    	    \#BIT_PARAM : ENABLE_AUX_IN_CSB \n
                                                    	    \#BIT_ALIAS : Line In CSB \n
                                                    	    \#BIT_POS : 5 \n
                                                    	    \#BIT_SIZE : 1 \n
                                                    	    \#BIT_DESC : Enable MSPK Aux-in mode \n
                                                    	    \#DESC_END

                                                    	    \par
                                                    	    \#BIT_PARAM : ENABLE_CONCERT_BACK_To_LAST_MODE \n
                                                    	    \#BIT_ALIAS : Enable Back To Last Mode for Concert Mode\n
                                                    	    \#BIT_POS : 6 \n
                                                    	    \#BIT_SIZE : 1 \n
                                                    	    \#BIT_DESC : Enable Back To Last Mode for Concert Mode \n
                                                    	    \#DESC_END

                                                            \par
                                                    	    \#BIT_PARAM : ENABLE_BT_LINKBACK_IN_AUX_IN_CSB \n
                                                    	    \#BIT_ALIAS : Enable Link back BT in MSPK Aux-in mode\n
                                                    	    \#BIT_POS : 7 \n
                                                    	    \#BIT_SIZE : 1 \n
                                                    	    \#BIT_DESC : Enable Link back BT in MSPK Aux-in mode, this will impact Aux-in CSB performance if enabled. \n
                                                    	    \#DESC_END
                                                	    */
                	    
    MSPK_CFG_KEY_OPTION2                        = 0x0D, /**<\#PARAM_NAME :  MSPK_CFG_KEY_OPTION2\n
                                                            \#PARAM_TYPE : Public \n
                                                            \#GROUP_ID : 0x0A \n
                                                            \#KEY_ID : 0x0D \n
                                                            
                                                            Bit Options:
                                                            \par
                                                            \#BIT_PARAM : (RESERVED) \n
                                                            \#BIT_ALIAS : RESERVED \n
                                                            \#BIT_POS : 0 \n
                                                            \#BIT_SIZE : 2 \n
                                                            \#BIT_DESC : RESERVED \n
                                                            \#DESC_END
                                                            
                                                            \par
                                                            \#BIT_PARAM : ENALBE_CONCERT_MODE_ENDLESS_GROUPING \n
                                                            \#BIT_ALIAS : Enable Concert Mode Master SPK Endless Grouping \n
                                                            \#BIT_POS : 2 \n
                                                            \#BIT_SIZE : 1 \n
                                                            \#BIT_DESC : Enable Concert mode Master SPK Endless Grouping. \n
                                                            \#DESC_END

                                                            \par
                                                            \#BIT_PARAM : ENABLE_CONCERT_MODE_SLAVE_VOL_CTRL \n
                                                            \#BIT_ALIAS : enable concert mode slave vol ctrl \n
                                                            \#BIT_POS : 3 \n
                                                            \#BIT_SIZE : 1 \n
                                                            \#BIT_DESC : Allow Concert mode Slave SPK can pass button action (Vol +/-) to Master and sync the volume value from Master SPK.\n
                                                            \#DESC_END

                                                            \par
                                                            \#BIT_PARAM : ENABLE_AAC_IN_CSB \n
                                                            \#BIT_ALIAS : Enable AAC Codec in MSPK \n
                                                            \#BIT_POS : 4 \n
                                                            \#BIT_SIZE : 1 \n
                                                            \#BIT_DESC : enable AAC codec in MSPK. \n
                                                            \#DESC_END

                                                            \par
                                                            \#BIT_PARAM : ENABLE_SEAMLESS_AUDIO_RESYNC \n
                                                            \#BIT_ALIAS : Enable Audio Seamless Resync \n
                                                            \#BIT_POS : 5 \n
                                                            \#BIT_SIZE : 1 \n
                                                            \#BIT_DESC : Enable seamless audio resync that can keep audio sync \n
                                                                         in CSB master and other slaves with audio breaks \n
                                                                         when a new slave is added. \n
                                                            \#DESC_END

                                                            \par
                                                            \#BIT_PARAM : ENALBE_SLAVE_CONCERT_MODE_ENDLESS_GROUPING \n
                                                            \#BIT_ALIAS : Enable Slave Concert Mode Endless Grouping \n
                                                            \#BIT_POS : 6 \n
                                                            \#BIT_SIZE : 1 \n
                                                            \#BIT_DESC : Enable Concert mode Slave SPK Endless Grouping. \n
                                                            \#DESC_END

                                                            \par
                                                            \#BIT_PARAM : (RESERVED) \n
                                                            \#BIT_ALIAS : RESERVED \n
                                                            \#BIT_POS : 7 \n
                                                            \#BIT_SIZE : 1 \n
                                                            \#BIT_DESC : RESERVED \n
                                                            \#DESC_END
                                                	    */
                                                	    
    MSPK_CFG_KEY_CSB_RESERVED2                  = 0x0E, /**<\#PARAM_NAME :  MSPK_CFG_KEY_CSB_RESERVED2\n
                                                            \#ALIAS :  Reserved\n
                                                            \#PARAM_TYPE : Public \n
                                                            \#PARAM_DESC : Reserved.\n
                                                            \#DESC_END
                                                            \#GROUP_ID : 0x0A \n
                                                            \#KEY_ID : 0x0E \n
                                                	    */
                                                	    
    MSPK_CFG_KEY_CSB_ACCESS_CODE                = 0x0F, /**<\#PARAM_NAME :  MSPK_CFG_KEY_CSB_ACCESS_CODE\n
                                                            \#ALIAS :  MSPK CSB ACCESS CODE\n
                                                            \#PARAM_TYPE : Private \n
                                                            \#PARAM_DESC : The access code for dedicated CSB pairing.\n
                                                            \#DESC_END
                                                            \#GROUP_ID : 0x0A \n
                                                            \#KEY_ID : 0x0F \n
                                                	    */
                                                	    
    MSPK_CFG_KEY_CSB_POWER_SAVING_CONN_INT      = 0x10, /**<\#PARAM_NAME :  MSPK_CFG_KEY_CSB_POWER_SAVING_CONN_INT\n
                                                            \#ALIAS :  MSPK Power Saving Grouping Interval\n
                                                            \#PARAM_TYPE : Public \n
                                                            \#PARAM_DESC : CSB Maseter power saving (endless grouping) connection interval (unit: 625us).\n
                                                            \#DESC_END
                                                            \#GROUP_ID : 0x0A \n
                                                            \#KEY_ID : 0x10 \n
                                                	    */

    MSPK_CFG_KEY_ENDLESS_GROUPING_GAC_DAC_INT   = 0x11, /**<\#PARAM_NAME : MSPK_CFG_KEY_ENDLESS_GROUPING_GAC_DAC_INT \n
                                                        \#PARAM_TYPE : Public \n
                                                        \#GROUP_ID : 0x0A \n
                                                        \#KEY_ID : 0x11 \n

                                                        \par
                                                        \#BYTE_PARAM : Endless_Grouping_GAC_Interval \n
                                        	            \#BYTE_ALIAS : Endless Grouping GAC Interval \n
                                        	            \#BYTE_POS : 0 \n
                                        	            \#BYTE_SIZE : 1 \n
                                        	            \#BYTE_DESC : CSB endless grouping connection GAC interval (unit: 5sec) \n
                                        	                          1.This is used to let Master add new Slave(s)
                                                                      2.If you enable the below item, the Master will periodically wait for new slave(s) \n
                                                                        to join in the Concert mode.
                                                                        (refer to item name : "Enable Concert Mode Master SPK Endless Grouping") \n
                                                                      Please find the details in document "AN3118"
                                        	            \#DESC_END  \n

                                        	            \par
                                        	            \#BYTE_PARAM : Endless_Grouping_DAC_Interval \n
                                        	            \#BYTE_ALIAS : Endless Grouping DAC Interval \n
                                        	            \#BYTE_POS : 1 \n
                                        	            \#BYTE_SIZE : 1 \n
                                        	            \#BYTE_DESC : CSB endless grouping connection DAC interval (unit: 5sec)\n
                                        	                          1. This is used to let a slave can link back to Master.
                                                                      2. If you enable the below item, the Master will periodically wait for the slave(s) \n
                                                                         to join in the Concert mode.\n
                                                                         (refer to item name : "Enable Concert Mode Master SPK Endless Grouping") \n
                                                                      Please find the details in document "AN3118"
                                        	            \#DESC_END  \n
                                                	    */

    MSPK_CFG_KEY_CSB_CONCERT_EXT_GROUPING_TIME      = 0x12, /**<\#PARAM_NAME :  MSPK_CFG_KEY_CSB_CONCERT_EXT_GROUPING_TIME\n
                                                            \#ALIAS :  Concert Extended Grouping Time \n
                                                            \#PARAM_TYPE : Public \n
                                                            \#PARAM_DESC : The CSB concert mode add 3rd speaker timeout. Unit: 5s\n
                                                            \#DESC_END
                                                            \#GROUP_ID : 0x0A \n
                                                            \#KEY_ID : 0x12 \n
                                                	    */
                                                	    

    MSPK_CFG_KEY_END       
} MSPK_CFG_Key_IdDefinition_T;

/**@defgroup MODULE_MSPK_CFG_DEFAULT_VALUE MSPK Configuration Default Value
 * @brief Default value definition of the module @ref CFG_MODULE_ID_MSPK.
 * @{ */




//Module MSPK
#define MSPK_CFG_KEY_CSB_GROUP_ID_LEN                               0x02            /**< The default length of @ref MSPK_CFG_KEY_CSB_GROUP_ID. */
#define MSPK_CFG_KEY_CSB_GROUP_ID_DEFAULT_VALUE                     0x7B, 0x36      /**< The default value of @ref MSPK_CFG_KEY_CSB_GROUP_ID. */

#define MSPK_CFG_KEY_MODEL_ID_LEN                                   0x02            /**< The default length of @ref MSPK_CFG_KEY_MODEL_ID. */
#define MSPK_CFG_KEY_MODEL_ID_DEFAULT_VALUE                         0x00, 0x00      /**< The default value of @ref MSPK_CFG_KEY_MODEL_ID. */

#define MSPK_CFG_KEY_CSB_RESERVED1_LEN                              0x01            /**< The default length of @ref MSPK_CFG_KEY_CSB_RESERVED1. */
#define MSPK_CFG_KEY_CSB_RESERVED1_DEFAULT_VALUE                    0x00            /**< The default value of @ref MSPK_CFG_KEY_CSB_RESERVED1. */

#define MSPK_CFG_KEY_CSB_SYNC_TIMEOUT_LEN                           0x01            /**< The default length of @ref MSPK_CFG_KEY_CSB_SYNC_TIMEOUT. */
#define MSPK_CFG_KEY_CSB_SYNC_TIMEOUT_DEFAULT_VALUE                 0x1E            /**< The default value of @ref MSPK_CFG_KEY_CSB_SYNC_TIMEOUT. */

#define MSPK_CFG_KEY_CSB_SYNC_ONEKEY_SLAVE_TIMEOUT_LEN              0x01            /**< The default length of @ref MSPK_CFG_KEY_CSB_SYNC_ONEKEY_SLAVE_TIMEOUT. */
#define MSPK_CFG_KEY_CSB_SYNC_ONEKEY_SLAVE_TIMEOUT_DEFAULT_VALUE    0x03            /**< The default value of @ref MSPK_CFG_KEY_CSB_SYNC_ONEKEY_SLAVE_TIMEOUT. */

#define MSPK_CFG_KEY_NSPK_CHANNEL_LEN                               0x01            /**< The default length of @ref MSPK_CFG_KEY_NSPK_CHANNEL. */
#define MSPK_CFG_KEY_NSPK_CHANNEL_DEFAULT_VALUE                     0x21            /**< The default value of @ref MSPK_CFG_KEY_NSPK_CHANNEL. */

#define MSPK_CFG_KEY_SHS_STATE_AFTER_CSB_NG_LEN                     0x01            /**< The default length of @ref MSPK_CFG_KEY_SHS_STATE_AFTER_CSB_NG. */
#define MSPK_CFG_KEY_SHS_STATE_AFTER_CSB_NG_DEFAULT_VALUE           0xE4            /**< The default value of @ref MSPK_CFG_KEY_SHS_STATE_AFTER_CSB_NG. */

#define MSPK_CFG_KEY_SHS_STATE_AFTER_CSB_MASTER_OK_LEN              0x01            /**< The default length of @ref MSPK_CFG_KEY_SHS_STATE_AFTER_CSB_MASTER_OK. */
#define MSPK_CFG_KEY_SHS_STATE_AFTER_CSB_MASTER_OK_DEFAULT_VALUE    0xE4            /**< The default value of @ref MSPK_CFG_KEY_SHS_STATE_AFTER_CSB_MASTER_OK. */

#define MSPK_CFG_KEY_NSPK_CHANNEL_DEFAULT_LEN                       0x01            /**< The default length of @ref MSPK_CFG_KEY_NSPK_CHANNEL_DEFAULT. */
#define MSPK_CFG_KEY_NSPK_CHANNEL_DEFAULT_DEFAULT_VALUE             0x21            /**< The default value of @ref MSPK_CFG_KEY_NSPK_CHANNEL_DEFAULT. */

#define MSPK_CFG_KEY_CSB_TRIGGER_SYNC_SCHEME_LEN                    0x01            /**< The default length of @ref MSPK_CFG_KEY_CSB_TRIGGER_SYNC_SCHEME. */
#define MSPK_CFG_KEY_CSB_TRIGGER_SYNC_SCHEME_DEFAULT_VALUE          0x04            /**< The default value of @ref MSPK_CFG_KEY_CSB_TRIGGER_SYNC_SCHEME. */

#define MSPK_CFG_KEY_CSB_TRIGGER_SYNC_ROLE_SETTING_LEN              0x01            /**< The default length of @ref MSPK_CFG_KEY_CSB_TRIGGER_SYNC_ROLE_SETTING. */
#define MSPK_CFG_KEY_CSB_TRIGGER_SYNC_ROLE_SETTING_DEFAULT_VALUE    0x00            /**< The default value of @ref MSPK_CFG_KEY_CSB_TRIGGER_SYNC_ROLE_SETTING. */

#define MSPK_CFG_KEY_OPTION1_LEN                                    0x01            /**< The default length of @ref MSPK_CFG_KEY_OPTION1. */
#define MSPK_CFG_KEY_OPTION1_DEFAULT_VALUE                          0x69            /**< The default value of @ref MSPK_CFG_KEY_OPTION1. */

#define MSPK_CFG_KEY_OPTION2_LEN                                    0x01            /**< The default length of @ref MSPK_CFG_KEY_OPTION2. */
#define MSPK_CFG_KEY_OPTION2_DEFAULT_VALUE                          0x3B            /**< The default value of @ref MSPK_CFG_KEY_OPTION2. */

#define MSPK_CFG_KEY_CSB_RESERVED2_LEN                              0x01            /**< The default length of @ref MSPK_CFG_KEY_CSB_RESERVED2. */
#define MSPK_CFG_KEY_CSB_RESERVED2_DEFAULT_VALUE                    0x00            /**< The default value of @ref MSPK_CFG_KEY_CSB_RESERVED2. */

#define MSPK_CFG_KEY_CSB_ACCESS_CODE_LEN                            0x04            /**< The default length of @ref MSPK_CFG_KEY_CSB_ACCESS_CODE. */
#define MSPK_CFG_KEY_CSB_ACCESS_CODE_DEFAULT_VALUE                  0x00, 0x00, 0x00, 0x00  /**< The default value of @ref MSPK_CFG_KEY_CSB_ACCESS_CODE. */

#define MSPK_CFG_KEY_CSB_POWER_SAVING_CONN_INT_LEN                  0x02            /**< The default length of @ref MSPK_CFG_KEY_CSB_POWER_SAVING_CONN_INT. */
#define MSPK_CFG_KEY_CSB_POWER_SAVING_CONN_INT_DEFAULT_VALUE        0x08, 0x00      /**< The default value of @ref MSPK_CFG_KEY_CSB_POWER_SAVING_CONN_INT. */

#define MSPK_CFG_KEY_ENDLESS_GROUPING_GAC_DAC_INT_LEN               0x02            /**< The default length of @ref MSPK_CFG_KEY_ENDLESS_GROUPING_GAC_DAC_INT. */
#define MSPK_CFG_KEY_ENDLESS_GROUPING_GAC_DAC_INT_DEFAULT_VALUE     0x00, 0x00      /**< The default value of @ref MSPK_CFG_KEY_ENDLESS_GROUPING_GAC_DAC_INT. */

#define MSPK_CFG_KEY_CSB_CONCERT_EXT_GROUPING_TIME_LEN               0x01           /**< The default length of @ref MSPK_CFG_KEY_CSB_CONCERT_EXT_GROUPING_TIME. */
#define MSPK_CFG_KEY_CSB_CONCERT_EXT_GROUPING_TIME_DEFAULT_VALUE     0x06           /**< The default value of @ref MSPK_CFG_KEY_CSB_CONCERT_EXT_GROUPING_TIME. */


/** @} */
/** @} */

/** \cond NON_DOC */

#define CFG_MSPK_MODULE_TOTAL_NUM_KEYS   (MSPK_CFG_KEY_END - 1)

#define CFG_MSPK_MODULE_TOTAL_SIZE  ((CFG_MSPK_MODULE_TOTAL_NUM_KEYS*SIZEOF_CFG_KEY_STRUCT) +  \
                                    MSPK_CFG_KEY_CSB_GROUP_ID_LEN +                         \
                                    MSPK_CFG_KEY_MODEL_ID_LEN +                             \
                                    MSPK_CFG_KEY_CSB_RESERVED1_LEN +                \
                                    MSPK_CFG_KEY_CSB_SYNC_TIMEOUT_LEN +                     \
                                    MSPK_CFG_KEY_CSB_SYNC_ONEKEY_SLAVE_TIMEOUT_LEN +        \
                                    MSPK_CFG_KEY_NSPK_CHANNEL_LEN +                         \
                                    MSPK_CFG_KEY_SHS_STATE_AFTER_CSB_NG_LEN +               \
                                    MSPK_CFG_KEY_SHS_STATE_AFTER_CSB_MASTER_OK_LEN +        \
                                    MSPK_CFG_KEY_NSPK_CHANNEL_DEFAULT_LEN +                 \
                                    MSPK_CFG_KEY_CSB_TRIGGER_SYNC_SCHEME_LEN +              \
                                    MSPK_CFG_KEY_CSB_TRIGGER_SYNC_ROLE_SETTING_LEN +        \
                                    MSPK_CFG_KEY_OPTION1_LEN +                              \
                                    MSPK_CFG_KEY_OPTION2_LEN +                         \
                                    MSPK_CFG_KEY_CSB_RESERVED2_LEN +                        \
                                    MSPK_CFG_KEY_CSB_ACCESS_CODE_LEN +                      \
                                    MSPK_CFG_KEY_CSB_POWER_SAVING_CONN_INT_LEN +            \
                                    MSPK_CFG_KEY_ENDLESS_GROUPING_GAC_DAC_INT_LEN +         \
                                    MSPK_CFG_KEY_CSB_CONCERT_EXT_GROUPING_TIME_LEN)

//MSPK Config keys definition
#define CFG_MSPK_MODULE_DEFAULT_VALUE   CFG_MODULE_ID_MSPK,               /*moduleID*/   \
                                        CFG_MSPK_MODULE_TOTAL_NUM_KEYS,   /*numKeys*/    \
                                        (CFG_MSPK_MODULE_TOTAL_SIZE >> 8),  /*moduleSize*/  \
                                        CFG_MSPK_MODULE_TOTAL_SIZE,                      \
                                        /*CFG_KEYs[numKeys]*/                           \
                                        /*    //ID                                        //Len                                                       //Value    */                                        \
                                        MSPK_CFG_KEY_CSB_GROUP_ID,                   MSPK_CFG_KEY_CSB_GROUP_ID_LEN,                      MSPK_CFG_KEY_CSB_GROUP_ID_DEFAULT_VALUE,                     \
                                        MSPK_CFG_KEY_MODEL_ID,                       MSPK_CFG_KEY_MODEL_ID_LEN,                          MSPK_CFG_KEY_MODEL_ID_DEFAULT_VALUE,                         \
                                        MSPK_CFG_KEY_CSB_RESERVED1,          MSPK_CFG_KEY_CSB_RESERVED1_LEN,             MSPK_CFG_KEY_CSB_RESERVED1_DEFAULT_VALUE,            \
                                        MSPK_CFG_KEY_CSB_SYNC_TIMEOUT,               MSPK_CFG_KEY_CSB_SYNC_TIMEOUT_LEN,                  MSPK_CFG_KEY_CSB_SYNC_TIMEOUT_DEFAULT_VALUE,                 \
                                        MSPK_CFG_KEY_CSB_SYNC_ONEKEY_SLAVE_TIMEOUT,  MSPK_CFG_KEY_CSB_SYNC_ONEKEY_SLAVE_TIMEOUT_LEN,     MSPK_CFG_KEY_CSB_SYNC_ONEKEY_SLAVE_TIMEOUT_DEFAULT_VALUE,    \
                                        MSPK_CFG_KEY_NSPK_CHANNEL,                   MSPK_CFG_KEY_NSPK_CHANNEL_LEN,                      MSPK_CFG_KEY_NSPK_CHANNEL_DEFAULT_VALUE,                     \
                                        MSPK_CFG_KEY_SHS_STATE_AFTER_CSB_NG,         MSPK_CFG_KEY_SHS_STATE_AFTER_CSB_NG_LEN,            MSPK_CFG_KEY_SHS_STATE_AFTER_CSB_NG_DEFAULT_VALUE,           \
                                        MSPK_CFG_KEY_SHS_STATE_AFTER_CSB_MASTER_OK,  MSPK_CFG_KEY_SHS_STATE_AFTER_CSB_MASTER_OK_LEN,     MSPK_CFG_KEY_SHS_STATE_AFTER_CSB_MASTER_OK_DEFAULT_VALUE,    \
                                        MSPK_CFG_KEY_NSPK_CHANNEL_DEFAULT,           MSPK_CFG_KEY_NSPK_CHANNEL_DEFAULT_LEN,              MSPK_CFG_KEY_NSPK_CHANNEL_DEFAULT_DEFAULT_VALUE,             \
                                        MSPK_CFG_KEY_CSB_TRIGGER_SYNC_SCHEME,        MSPK_CFG_KEY_CSB_TRIGGER_SYNC_SCHEME_LEN,           MSPK_CFG_KEY_CSB_TRIGGER_SYNC_SCHEME_DEFAULT_VALUE,          \
                                        MSPK_CFG_KEY_CSB_TRIGGER_SYNC_ROLE_SETTING,  MSPK_CFG_KEY_CSB_TRIGGER_SYNC_ROLE_SETTING_LEN,     MSPK_CFG_KEY_CSB_TRIGGER_SYNC_ROLE_SETTING_DEFAULT_VALUE,    \
                                        MSPK_CFG_KEY_OPTION1,                        MSPK_CFG_KEY_OPTION1_LEN,                           MSPK_CFG_KEY_OPTION1_DEFAULT_VALUE,                          \
                                        MSPK_CFG_KEY_OPTION2,                        MSPK_CFG_KEY_OPTION2_LEN,                           MSPK_CFG_KEY_OPTION2_DEFAULT_VALUE,                          \
                                        MSPK_CFG_KEY_CSB_RESERVED2,                  MSPK_CFG_KEY_CSB_RESERVED2_LEN,                     MSPK_CFG_KEY_CSB_RESERVED2_DEFAULT_VALUE,                    \
                                        MSPK_CFG_KEY_CSB_ACCESS_CODE,                MSPK_CFG_KEY_CSB_ACCESS_CODE_LEN,                   MSPK_CFG_KEY_CSB_ACCESS_CODE_DEFAULT_VALUE,                  \
                                        MSPK_CFG_KEY_CSB_POWER_SAVING_CONN_INT,      MSPK_CFG_KEY_CSB_POWER_SAVING_CONN_INT_LEN,         MSPK_CFG_KEY_CSB_POWER_SAVING_CONN_INT_DEFAULT_VALUE,        \
                                        MSPK_CFG_KEY_ENDLESS_GROUPING_GAC_DAC_INT,   MSPK_CFG_KEY_ENDLESS_GROUPING_GAC_DAC_INT_LEN,      MSPK_CFG_KEY_ENDLESS_GROUPING_GAC_DAC_INT_DEFAULT_VALUE,     \
                                        MSPK_CFG_KEY_CSB_CONCERT_EXT_GROUPING_TIME,  MSPK_CFG_KEY_CSB_CONCERT_EXT_GROUPING_TIME_LEN,     MSPK_CFG_KEY_CSB_CONCERT_EXT_GROUPING_TIME_DEFAULT_VALUE

#define APP_CFG_BIT0_MASK               0x01            /**< Bit 0. */
#define APP_CFG_BIT1_MASK               0x02            /**< Bit 1. */
#define APP_CFG_BIT2_MASK               0x04            /**< Bit 2. */
#define APP_CFG_BIT3_MASK               0x08            /**< Bit 3. */
#define APP_CFG_BIT4_MASK               0x10            /**< Bit 4. */
#define APP_CFG_BIT5_MASK               0x20            /**< Bit 5. */
#define APP_CFG_BIT6_MASK               0x40            /**< Bit 6. */
#define APP_CFG_BIT7_MASK               0x80            /**< Bit 7. */

#if 0
typedef enum
{
    APP_CFG_CHANNEL_NO_MIXING,                     /**< No Mixing, (L, R). */
    APP_CFG_CHANNEL_ONLY_LEFT,                     /**< Only output audio from left channel ,(L, L). */
    APP_CFG_CHANNEL_ONLY_RIGHT,                    /**< Only output audio from right channel ,(R, R). */
    APP_CFG_CHANNEL_MIX,                           /**< Mix the audio of left channel and right channel, ( (L + R)/2 , (L + R)/2 ). */

    APP_CFG_CHANNEL_TOTAL
} APP_Cfg_AudioChannelType_T;
#endif

typedef struct APP_Cfg_MspkOption1_T
{
    uint8_t recoverCsbLink: 1;               /**< If this option is enabled (set to 1), the speaker will try to recover the CSB link when the CSB link disconnects abnormally.*/
    uint8_t reserved1: 2;                    /**< Reserved. */
    uint8_t concertModeEnabled: 1;           /**< Indicate Concert mode is enabled or not. */
    uint8_t reserved2: 1;                    /**< Reserved. */
    uint8_t enableLineInCsb: 1;              /**< Enable Concert/Stereo Aux-in mode. */
    uint8_t enableConcertBackToLastMode: 1;  /**< Enable back to last mode for Concert mode. */
    uint8_t enableBtLinkbackInLineInCsb: 1;  /**< Enable BT link back in Aux-in mode CSB. */ 
} APP_Cfg_MspkOption1_T;

typedef struct APP_Cfg_MspkOption2_T
{
    uint8_t reserved1: 2;                    /**< Reserved.*/
    uint8_t enableEndlessSyncTrain: 1;       /**< Enable Concert mode Master SPK Endless Grouping. */
    uint8_t enableConcertSlaveVolCtrl: 1;    /**< Allow Concert mode Slave SPK can pass button action (Vol +/-) to Master and sync the volume value from Master SPK. */
    uint8_t enableAacInCsb: 1;               /**< Enable AAC codec in CSB. */     
    uint8_t enableSeamlessResync: 1;         /**< Enable seamless audio resync that can keep audio sync in CSB master and other slaves with audio breaks when a new slave is added. */
    uint8_t enableEndlessSyncScan: 1;        /**< Enable Concert mode Slave SPK Endless Grouping. */
    uint8_t reserved: 1;                     /**< Reserved . */ 
} APP_Cfg_MspkOption2_T;


typedef struct APP_Cfg_EndlessGroupingInterval_T
{
    uint8_t csbGACTime;       /**< GAC time interval.*/
    uint8_t csbDACTime;       /**< DAC time interval.*/
} APP_Cfg_EndlessGroupingInterval_T;


typedef struct APP_Cfg_CsbTriggerSyncScheme_T  
{
    uint8_t syncByCfgSetting: 1;      /**< If this option is enabled (set to 1), BTM will assign CSB role by config data setting.*/
    uint8_t reserved1: 1;    					/**< Reserved. */
    uint8_t backToLastMode: 1;        /**< If this option is enabled (set to 1), when BTM powers on, the role and CSB link will be recovered based on the setting which is stored when BTM powers off. */
    uint8_t reserved: 5;              /**< Reserved . */ 
} APP_Cfg_CsbTriggerSyncScheme_T;

typedef struct APP_Cfg_CsbTriggerSyncRoleSetting_T  
{
    uint8_t csbMasterByCfgSetting: 1; /**< Pre-define CSB role as Master role. This is used when the option "syncByCfgSetting" is enabled. */
    uint8_t csbSlaveByCfgSetting: 1;  /**< Pre-define CSB role as Slave role. This is used when the option "syncByCfgSetting" is enabled. */
    uint8_t saveConnectedRole: 1;     /**< Save CSB role setting once CSB is connected. */
    uint8_t csbMasterByLastMode: 1;   /**< CSB role is Master when last time BTM powered off */
    uint8_t csbSlaveByLastMode: 1;    /**< CSB role is Slave when last time BTM powered off */
    uint8_t reserved2: 3;             /**< Reserved . */ 
} APP_Cfg_CsbTriggerSyncRoleSetting_T;

typedef struct APP_Cfg_CsbChannelSetting_T  
{
    AUDIO_DSP_AudioChannelType_T slaveChannel: 4;          /**< The audio channel setting for Slave SPK. See @ref APP_Cfg_AudioChannelType_T. */
    AUDIO_DSP_AudioChannelType_T masterChannel: 4;         /**< The audio channel setting for Master SPK. See @ref APP_Cfg_AudioChannelType_T.*/
} APP_Cfg_CsbChannelSetting_T;

void APP_CFG_ReadCsbGroupId(uint8_t XDATA *p_groupId);
void APP_CFG_WriteCsbGroupId(uint8_t len, uint8_t XDATA *p_groupId);
void APP_CFG_ReadModelId(uint8_t XDATA *p_len, uint8_t XDATA *p_modelId);
void APP_CFG_WriteModelId(uint8_t len, uint8_t XDATA *p_modelId);
void APP_CFG_ReadCsbTimeout(uint8_t XDATA *p_csbTimeout);
void APP_CFG_WriteCsbTimeout(uint8_t csbTimeout);
void APP_CFG_ReadCsbOnekeyTimeout(uint8_t XDATA *p_csbOnekeyTimeout);
void APP_CFG_WriteCsbOnekeyTimeout(uint8_t csbOnekeyTimeout);
void APP_CFG_ReadBtmStateAfterCsbFailed(uint8_t XDATA *p_state);
void APP_CFG_ReadBtmStateAfterCsbOk(uint8_t XDATA *p_state);
void APP_CFG_ReadCsbOption1(APP_Cfg_MspkOption1_T XDATA *option);
void APP_CFG_WriteCsbOption1(uint8_t bitMask, bool enable);
void APP_CFG_ReadCsbOption2(APP_Cfg_MspkOption2_T XDATA *option);
void APP_CFG_ReadCsbEndlessGroupingInterval(APP_Cfg_EndlessGroupingInterval_T XDATA *option);
void APP_CFG_ReadCsbTriggerSyncScheme(APP_Cfg_CsbTriggerSyncScheme_T XDATA *option);
void APP_CFG_ReadCsbTriggerSyncRoleSetting(APP_Cfg_CsbTriggerSyncRoleSetting_T XDATA *option);
void APP_CFG_WriteCsbLastModeRoleSetting(uint8_t bitMask, bool enable);
void APP_CFG_ReadCsbChannelSetting(APP_Cfg_CsbChannelSetting_T XDATA *channelSetting);
void APP_CFG_WriteCsbChannelSetting(APP_Cfg_CsbChannelSetting_T channelSetting);
void APP_CFG_ReadCsbChannelDefaultSetting(APP_Cfg_CsbChannelSetting_T XDATA *channelSetting);
void APP_CFG_ReadCsbAccessCode(uint8_t XDATA *p_accessCode);
void APP_CFG_WriteCsbAccessCode(uint8_t len, uint8_t XDATA *p_accessCode);
void APP_CFG_ReadCsbPowerSavingConnInt(uint8_t XDATA *p_connectionInterval);
void APP_CFG_ReadConcertExtendedGroupingTime(uint8_t XDATA *p_extGroupingTime);

/// \endcond

#endif//APP_CFG_MSPK_H

