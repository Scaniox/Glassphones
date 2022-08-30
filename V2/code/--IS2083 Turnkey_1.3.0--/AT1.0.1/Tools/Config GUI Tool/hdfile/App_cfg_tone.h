/********************************************************************
  File Information:
    FileName:       app_cfg_tone.h
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

#ifndef APP_CFG_TONE_H
#define APP_CFG_TONE_H

/** \cond NON_DOC 

\#BUILD_TARGET : MSPKv2_GFP
\#BUILD_TARGET : MSPKv2_SPP
\#TARGET_START

\#TARGET_END

\#BUILD_TARGET : MSPKv2_App_Basic
\#BUILD_TARGET : MSPKv2_PBAP
\#BUILD_TARGET : AT_App
\#TARGET_START

\#REMOVE_PARAM : TONE_CFG_KEY_CSB_ENTER_PAIRING_TONE
\#REMOVE_PARAM : TONE_CFG_KEY_CSB_CONNECTION_TONE
\#REMOVE_PARAM : TONE_CFG_KEY_CSB_DISCONNECTION_TONE
\#REMOVE_BIT : ENABLE_VP_TONE_IN_MSPK_SLAVE

\#TARGET_END

\endcond
*/

/**
  @addtogroup APP_CFG_TONE TONE Configuration
  @{
  @brief Definitions and prototypes for the Tones Configuration.
 */


//Config Key definiton of MODULE_TONE(0x07)
/**
 * @brief Configuration key definition of the module @ref CFG_MODULE_ID_TONE.
 *  
 */

typedef enum _TONE_CFG_Key_IdDefinition_T
{
    TONE_CFG_KEY_TONE_SET                   = 0x01, /**<\#PARAM_NAME : TONE_CFG_KEY_TONE_SET \n
                                                        \#ALIAS : Configure Tone Set \n
                                                        \#PARAM_TYPE : Private \n
                                                        \#PARAM_DESC : which tone set been used : currently support max 4 tone sets:(0~3). \n
                                                        \#DESC_END
                                                        \#GROUP_ID : 0x07 \n
                                                        \#KEY_ID : 0x01 \n
                                            	    */


    TONE_CFG_KEY_SHORT_PRESS_TONE           = 0x02, /**<\#PARAM_NAME : TONE_CFG_KEY_SHORT_PRESS_TONE \n
                                                        \#ALIAS : Short Press Tone \n
                                                        \#PARAM_TYPE : Public \n
                                                        \#PARAM_DESC : Tone type for button short press. \n 
                                                                       It is uesd if the option ALL_BUTTON_FORCE_ALARM_ENABLE is enabled or \n
                                                                       the triggered button event is related to HFP or voice functions such as voice dial and redial. \n
                                                        \#DESC_END
                                                        \#GROUP_ID : 0x07 \n
                                                        \#KEY_ID : 0x02 \n
                                            	    */

    
    TONE_CFG_KEY_LONG_PRESS_TONE            = 0x03, /**<\#PARAM_NAME : TONE_CFG_KEY_LONG_PRESS_TONE \n
                                                        \#ALIAS : Long Press Tone \n
                                                        \#PARAM_TYPE : Public \n
                                                        \#PARAM_DESC : Tone type for button long press. It is used for below conditions: \n
                                                                       1. If the option ALL_BUTTON_FORCE_ALARM_ENABLE is enabled, it rings for any button that is long pressed \n
                                                                       2. If the triggered button event is related to HFP or voice functions \n
                                                                       3. If the option BUTTON_0_FORCE_ALARM_ENABLE is enabled, it rings for button 0 that is long pressed \n
                                                        \#DESC_END
                                                        \#GROUP_ID : 0x07 \n
                                                        \#KEY_ID : 0x03 \n
                                            	    */

    
    TONE_CFG_KEY_DOUBLE_CLICK_TONE          = 0x04, /**<\#PARAM_NAME : TONE_CFG_KEY_DOUBLE_CLICK_TONE \n
                                                        \#ALIAS : Double Click Tone \n
                                                        \#PARAM_TYPE : Public \n
                                                        \#PARAM_DESC : Tone type for button double click. It is uesd if the option ALL_BUTTON_FORCE_ALARM_ENABLE is enabled \n
                                                                       or the triggered button event is related to HFP or voice functions such as voice dial and redial. \n
                                                        \#DESC_END
                                                        \#GROUP_ID : 0x07 \n
                                                        \#KEY_ID : 0x04 \n
                                            	    */

    
    TONE_CFG_KEY_LINK_QUALITY_WARNING_TONE  = 0x05, /**<\#PARAM_NAME : TONE_CFG_KEY_LINK_QUALITY_WARNING_TONE \n
                                                        \#ALIAS : Quality Warning Tone \n
                                                        \#PARAM_TYPE : Public \n
                                                        \#PARAM_DESC : Tone type for bad signal of Bluetooth connection. \n
                                                        \#DESC_END
                                                        \#GROUP_ID : 0x07 \n
                                                        \#KEY_ID : 0x05 \n
                                            	    */

    
    TONE_CFG_KEY_TONE_SET_MASK              = 0x06, /**<\#PARAM_NAME : TONE_CFG_KEY_TONE_SET_MASK \n
                                                        \#ALIAS : Setting Tone Mask \n
                                                        \#PARAM_TYPE : Public \n
                                                        \#PARAM_DESC : Tone set mask (bit0 ~ bit3) to indicate support which set of tone settings: \n
                                                                       
                                                        \#DESC_END
                                                        \#GROUP_ID : 0x07 \n
                                                        \#KEY_ID : 0x06 \n
                                            	    */

    
    TONE_CFG_KEY_PRESS_VOL_KEY_TONE         = 0x07, /**<\#PARAM_NAME : TONE_CFG_KEY_PRESS_VOL_KEY_TONE \n
                                                        \#ALIAS : Press Volume key Tone \n
                                                        \#PARAM_TYPE : Public \n
                                                        \#PARAM_DESC : tone type for vol key press \n
                                                        \#DESC_END
                                                        \#GROUP_ID : 0x07 \n
                                                        \#KEY_ID : 0x07 \n
                                            	    */

    
    TONE_CFG_KEY_CONNECTED_TONE2            = 0x08, /**<\#PARAM_NAME : TONE_CFG_KEY_CONNECTED_TONE2 \n
                                                        \#ALIAS : Enable Connected Tone_2 \n
                                                        \#PARAM_TYPE : Public \n
                                                        \#PARAM_DESC : when ENABLE_USE_CONNECTED_TONE2 is enable, then generate this tone for 2nd profile connected \n
                                                        \#DESC_END
                                                        \#GROUP_ID : 0x07 \n
                                                        \#KEY_ID : 0x08 \n
                                            	    */

    
    TONE_CFG_KEY_FUNCTION_ALARM_TONE        = 0x09, /**<\#PARAM_NAME : TONE_CFG_KEY_FUNCTION_ALARM_TONE \n
                                                        \#ALIAS : Setting Function Alarm Tone \n
                                                        \#PARAM_TYPE : Public \n
                                                        \#PARAM_DESC : tone mode for some function indication, such NFC… \n
                                                        \#DESC_END
                                                        \#GROUP_ID : 0x07 \n
                                                        \#KEY_ID : 0x09 \n
                                            	    */

    
    TONE_CFG_KEY_RINGTONE_VOLUME            = 0x0A, /**<\#PARAM_NAME : TONE_CFG_KEY_RINGTONE_VOLUME \n
                                                        \#ALIAS : Ring Tone Volume \n
                                                        \#PARAM_TYPE : Public \n
                                                        \#PARAM_DESC : Gain level(0~15) for fix ring tone volume usage \n
                                                        \#DESC_END
                                                        \#GROUP_ID : 0x07 \n
                                                        \#KEY_ID : 0x0A \n
                                            	    */

    TONE_CFG_KEY_TONE_MODE_4_32             = 0x0B, /**<\#PARAM_NAME : TONE_CFG_KEY_TONE_MODE_4_32 \n
                                                        \#PARAM_TYPE : Public \n
                                                        \#GROUP_ID : 0x07 \n
                                                        \#KEY_ID : 0x0B \n

                                                        \#BYTE_PARAM : POWER_ON_TONE \n
                                        	            \#BYTE_ALIAS : Power On Tone\n
                                        	            \#BYTE_POS : 0 \n
                                        	            \#BYTE_SIZE : 1 \n
                                        	            \#BYTE_DESC : Tone type for power on event \n
                                        	            \#DESC_END  \n

                                        	            \par
                                        	            \#BYTE_PARAM : POWER_OFF_TONE \n
                                        	            \#BYTE_ALIAS : Power Off Tone\n
                                        	            \#BYTE_POS : 1 \n
                                        	            \#BYTE_SIZE : 1 \n
                                        	            \#BYTE_DESC : Tone type for power off event \n
                                        	            \#DESC_END  \n

                                        	            \par
                                        	            \#BYTE_PARAM : ENTER_PAIRING_TONE \n
                                        	            \#BYTE_ALIAS : Enter Pairing Tone \n
                                        	            \#BYTE_POS : 2 \n
                                        	            \#BYTE_SIZE : 1 \n
                                        	            \#BYTE_DESC : Tone type for entering pairing event \n
                                        	            \#DESC_END  \n

                                        	            \par
                                        	            \#BYTE_PARAM : PAIRING_COMPLETE_TONE \n
                                        	            \#BYTE_ALIAS : Pairing Complete Tone \n
                                        	            \#BYTE_POS : 3 \n
                                        	            \#BYTE_SIZE : 1 \n
                                        	            \#BYTE_DESC : Tone type for pairing complete event \n
                                        	            \#DESC_END  \n

                                        	            \par
                                        	            \#BYTE_PARAM : PAIRING_INCOMPLETE_TONE \n
                                        	            \#BYTE_ALIAS : Pairing Not Complete Tone \n
                                        	            \#BYTE_POS : 4 \n
                                        	            \#BYTE_SIZE : 1 \n
                                        	            \#BYTE_DESC : Tone type for pairing failure event \n
                                        	            \#DESC_END  \n

                                        	            \par
                                        	            \#BYTE_PARAM : INCOMING_CALL_TONE \n
                                        	            \#BYTE_ALIAS : Incoming Call Tone \n
                                        	            \#BYTE_POS : 5 \n
                                        	            \#BYTE_SIZE : 1 \n
                                        	            \#BYTE_DESC : Tone type for incoming call event \n
                                        	            \#DESC_END  \n

                                        	            \par
                                        	            \#BYTE_PARAM : REJECT_CALL_TONE \n
                                        	            \#BYTE_ALIAS : Reject Call Tone \n
                                        	            \#BYTE_POS : 6 \n
                                        	            \#BYTE_SIZE : 1 \n
                                        	            \#BYTE_DESC : Tone type for rejecting call event \n
                                        	            \#DESC_END  \n

                                        	            \par
                                        	            \#BYTE_PARAM : CALL_ACTIVE_TONE \n
                                        	            \#BYTE_ALIAS : Call Active Tone \n
                                        	            \#BYTE_POS : 7 \n
                                        	            \#BYTE_SIZE : 1 \n
                                        	            \#BYTE_DESC : Tone type for call active event \n
                                        	            \#DESC_END  \n

                                                        \par
                                                        \#BYTE_PARAM : CALL_END_TONE \n
                                                        \#BYTE_ALIAS : Call End Tone \n
                                                        \#BYTE_POS : 8 \n
                                                        \#BYTE_SIZE : 1 \n
                                                        \#BYTE_DESC : Tone type for call end event \n
                                                        \#DESC_END  \n
                                        	            
                                                        \par
                                                        \#BYTE_PARAM : CHARGING_INITIATE_TONE \n
                                                        \#BYTE_ALIAS : Charging Initiate Tone \n
                                                        \#BYTE_POS : 9 \n
                                                        \#BYTE_SIZE : 1 \n
                                                        \#BYTE_DESC : Tone type for charging initate event \n
                                                        \#DESC_END  \n

                                                        \par
                                                        \#BYTE_PARAM : CHARGING_COMPLETE_TONE \n
                                                        \#BYTE_ALIAS : Charging Complete Tone \n
                                                        \#BYTE_POS : 10 \n
                                                        \#BYTE_SIZE : 1 \n
                                                        \#BYTE_DESC : Tone type for charging complete event \n
                                                        \#DESC_END  \n    

                                                        \par
                                                        \#BYTE_PARAM : LOW_BATTERY_TONE \n
                                                        \#BYTE_ALIAS : Low Battery Tone \n
                                                        \#BYTE_POS : 11 \n
                                                        \#BYTE_SIZE : 1 \n
                                                        \#BYTE_DESC : Tone type for low battery warning \n
                                                        \#DESC_END  \n                                                         

                                                        \par
                                                        \#BYTE_PARAM : BATTERY_LEVEL1_TONE \n
                                                        \#BYTE_ALIAS : Battery Level 1 Tone \n
                                                        \#BYTE_POS : 12 \n
                                                        \#BYTE_SIZE : 1 \n
                                                        \#BYTE_DESC : Tone type for the indication of battery level 1 \n
                                                        \#DESC_END  \n    

                                                        \par
                                                        \#BYTE_PARAM : BATTERY_LEVEL2_TONE \n
                                                        \#BYTE_ALIAS : Battery Level 2 Tone \n
                                                        \#BYTE_POS : 13 \n
                                                        \#BYTE_SIZE : 1 \n
                                                        \#BYTE_DESC : Tone type for the indication of battery level 2 \n
                                                        \#DESC_END  \n 
                                                        
                                                        \par
                                                        \#BYTE_PARAM : BATTERY_LEVEL3_TONE \n
                                                        \#BYTE_ALIAS : Battery Level 3 Tone \n
                                                        \#BYTE_POS : 14 \n
                                                        \#BYTE_SIZE : 1 \n
                                                        \#BYTE_DESC : Tone type for the indication of battery level 3 \n
                                                        \#DESC_END  \n   

                                                        \par
                                                        \#BYTE_PARAM : BATTERY_LEVEL4_TONE \n
                                                        \#BYTE_ALIAS : Battery Level 4 Tone \n
                                                        \#BYTE_POS : 15 \n
                                                        \#BYTE_SIZE : 1 \n
                                                        \#BYTE_DESC : Tone type for the indication of battery level 4 \n
                                                        \#DESC_END  \n                                               

                                                        \par
                                                        \#BYTE_PARAM : BATTERY_LEVEL5_TONE \n
                                                        \#BYTE_ALIAS : Battery Level 5 Tone \n
                                                        \#BYTE_POS : 16 \n
                                                        \#BYTE_SIZE : 1 \n
                                                        \#BYTE_DESC : Tone type for the indication of battery level 5 \n
                                                        \#DESC_END  \n  

                                                        \par
                                                        \#BYTE_PARAM : BATTERY_LEVEL6_TONE \n
                                                        \#BYTE_ALIAS : Battery Level 6 Tone \n
                                                        \#BYTE_POS : 17 \n
                                                        \#BYTE_SIZE : 1 \n
                                                        \#BYTE_DESC : Tone type for the indication of battery level 6 \n
                                                        \#DESC_END  \n                                               

                                                        \par
                                                        \#BYTE_PARAM : FULL_BATTERY_TONE \n
                                                        \#BYTE_ALIAS : Full Battery Tone \n
                                                        \#BYTE_POS : 18 \n
                                                        \#BYTE_SIZE : 1 \n
                                                        \#BYTE_DESC : Tone type for the indication of battery full \n
                                                        \#DESC_END  \n  

                                                        \par
                                                        \#BYTE_PARAM : MAX_VOL_TONE \n
                                                        \#BYTE_ALIAS : Max Vol Tone \n
                                                        \#BYTE_POS : 19 \n
                                                        \#BYTE_SIZE : 1 \n
                                                        \#BYTE_DESC : Tone type for the event which the volume reaches to maximum volume \n
                                                        \#DESC_END  \n  

                                                        \par
                                                        \#BYTE_PARAM : Min_VOL_TONE \n
                                                        \#BYTE_ALIAS : Min Vol Tone \n
                                                        \#BYTE_POS : 20 \n
                                                        \#BYTE_SIZE : 1 \n
                                                        \#BYTE_DESC : Tone type for the event which the volume reaches to minimum volume \n
                                                        \#DESC_END  \n   

                                                        \par
                                                        \#BYTE_PARAM : HFP_CONNECTED_TONE \n
                                                        \#BYTE_ALIAS : HFP Connected Tone \n
                                                        \#BYTE_POS : 21 \n
                                                        \#BYTE_SIZE : 1 \n
                                                        \#BYTE_DESC : Tone type for HFP connected tone \n
                                                        \#DESC_END  \n 

                                                        \par
                                                        \#BYTE_PARAM : A2DP_CONNECTED_TONE \n
                                                        \#BYTE_ALIAS : Music Mode Ready Tone \n
                                                        \#BYTE_POS : 22 \n
                                                        \#BYTE_SIZE : 1 \n
                                                        \#BYTE_DESC : Tone type for the event which the volume reaches to minimum volume \n
                                                        \#DESC_END  \n   

                                                        \par
                                                        \#BYTE_PARAM : LINK_DISCONNECTED_TONE \n
                                                        \#BYTE_ALIAS : BT Link Disconnect Tone \n
                                                        \#BYTE_POS : 23 \n
                                                        \#BYTE_SIZE : 1 \n
                                                        \#BYTE_DESC : Tone type for BT ACL link disconnected event. \n
                                                        \#DESC_END  \n  

                                                        \par
                                                        \#BYTE_PARAM : LINK_LOSS_TONE \n
                                                        \#BYTE_ALIAS : Link Loss Tone \n
                                                        \#BYTE_POS : 24 \n
                                                        \#BYTE_SIZE : 1 \n
                                                        \#BYTE_DESC : Tone type for BT ACL link loss event \n
                                                        \#DESC_END  \n  

                                                        \par
                                                        \#BYTE_PARAM : TONE_SET_CHANGED_TONE \n
                                                        \#BYTE_ALIAS : Tone Set Changed Tone \n
                                                        \#BYTE_POS : 25 \n
                                                        \#BYTE_SIZE : 1 \n
                                                        \#BYTE_DESC : Tone type for the tone set changed event \n
                                                        \#DESC_END  \n                                                         

                                                        \par
                                                        \#BYTE_PARAM : VOICE_DIAL_TONE \n
                                                        \#BYTE_ALIAS : Voice Dial Tone \n
                                                        \#BYTE_POS : 26 \n
                                                        \#BYTE_SIZE : 1 \n
                                                        \#BYTE_DESC : Tone type for the event which voice dial is triggered. \n
                                                        \#DESC_END  \n 

                                                        \par
                                                        \#BYTE_PARAM : LAST_NUMBER_REDIAL_TONE \n
                                                        \#BYTE_ALIAS : Last Number Redial Tone \n
                                                        \#BYTE_POS : 27 \n
                                                        \#BYTE_SIZE : 1 \n
                                                        \#BYTE_DESC : Tone type for the event which last number redial is triggered \n
                                                        \#DESC_END  \n     

                                                        \par
                                                        \#BYTE_PARAM : NO_CALL_SERVICE_TONE \n
                                                        \#BYTE_ALIAS : No Service Tone \n
                                                        \#BYTE_POS : 28 \n
                                                        \#BYTE_SIZE : 1 \n
                                                        \#BYTE_DESC : Tone type for the event which phone can't communicate with base station and have call service. \n
                                                        \#DESC_END  \n  

                                                        \par
                                                        \#BYTE_PARAM : BUTTON_LOCK_TONE \n
                                                        \#BYTE_ALIAS : Button Lock Tone \n
                                                        \#BYTE_POS : 29 \n
                                                        \#BYTE_SIZE : 1 \n
                                                        \#BYTE_DESC : Tone type for button lock state. \n
                                                        \#DESC_END  \n                                

                                                        \par
                                                        \#BYTE_PARAM : MIC_MUTE_TONE \n
                                                        \#BYTE_ALIAS : Microphone Mute Tone \n
                                                        \#BYTE_POS : 30 \n
                                                        \#BYTE_SIZE : 1 \n
                                                        \#BYTE_DESC : Tone type for the warning which microphone is muted. \n
                                                        \#DESC_END  \n 

                                                        \par
                                                        \#BYTE_PARAM : RESERVED \n
                                                        \#BYTE_ALIAS : reserved \n
                                                        \#BYTE_POS : 31 \n
                                                        \#BYTE_SIZE : 1 \n
                                                        \#BYTE_DESC : Reserved. \n
                                                        \#DESC_END  \n        

                                                        \par
                                                        \#BYTE_PARAM : TONE_SET_2 \n
                                                        \#BYTE_ALIAS : Microphone Mute Tone \n
                                                        \#BYTE_POS : 32 \n
                                                        \#BYTE_SIZE : 32 \n
                                                        \#BYTE_DESC : For second set of tone type settings. \n
                                                        \#DESC_END  \n 

                                                        \par
                                                        \#BYTE_PARAM : TONE_SET_3 \n
                                                        \#BYTE_ALIAS : Microphone Mute Tone \n
                                                        \#BYTE_POS : 64 \n
                                                        \#BYTE_SIZE : 32 \n
                                                        \#BYTE_DESC : For third set of tone type settings. \n
                                                        \#DESC_END  \n   

                                                        \par
                                                        \#BYTE_PARAM : TONE_SET_4 \n
                                                        \#BYTE_ALIAS : Microphone Mute Tone \n
                                                        \#BYTE_POS : 96 \n
                                                        \#BYTE_SIZE : 32 \n
                                                        \#BYTE_DESC : For forth set of tone type settings. \n
                                                        \#DESC_END  \n                                                         
                                            	    */
    
    TONE_CFG_KEY_CSB_ENTER_PAIRING_TONE     = 0x0C, /**<\#PARAM_NAME : TONE_CFG_KEY_CSB_ENTER_PAIRING_TONE \n
                                                        \#ALIAS : Setting CSB Enter Pairing Tone \n
                                                        \#PARAM_TYPE : Public \n
                                                        \#PARAM_DESC : The tone rings when the speaker enters CSB pairing. \n
                                                        \#DESC_END
                                                        \#GROUP_ID : 0x07 \n
                                                        \#KEY_ID : 0x0C \n
                                            	    */

    
    TONE_CFG_KEY_CSB_CONNECTION_TONE        = 0x0D, /**<\#PARAM_NAME : TONE_CFG_KEY_CSB_CONNECTION_TONE \n
                                                        \#ALIAS : Setting CSB Connection Tone \n
                                                        \#PARAM_TYPE : Public \n
                                                        \#PARAM_DESC : The tone rings when the CSB link is connected. \n 
                                                                       If Master of CSB link is playing music at this moment, it won’t ring the tone. \n
                                                        \#DESC_END
                                                        \#GROUP_ID : 0x07 \n
                                                        \#KEY_ID : 0x0D \n
                                            	    */

    
    TONE_CFG_KEY_CSB_DISCONNECTION_TONE     = 0x0E, /**<\#PARAM_NAME : TONE_CFG_KEY_CSB_DISCONNECTION_TONE \n
                                                        \#ALIAS : Setting CSB Disconnection Tone \n
                                                        \#PARAM_TYPE : Public \n
                                                        \#PARAM_DESC : The tone rings when the CSB link is disconnected. \n
                                                        \#DESC_END
                                                        \#GROUP_ID : 0x07 \n
                                                        \#KEY_ID : 0x0E \n
                                            	    */

    TONE_CFG_KEY_TONE_OPTION                = 0x0F, /**<\#PARAM_NAME : TONE_CFG_KEY_TONE_OPTION \n
                                                    	 \#PARAM_TYPE : Public \n
                                                    	 \#GROUP_ID : 0x07 \n
                                                    	 \#KEY_ID : 0x0F \n
                                                    	 Bit Options:
                                                    	 \par
                                                    	 \#BIT_PARAM : RESERVED \n
                                                    	 \#BIT_ALIAS : reserved \n
                                                    	 \#BIT_POS : 0 \n
                                                    	 \#BIT_SIZE : 1 \n
                                                    	 \#BIT_DESC : \n
                                                    	 \#DESC_END

                                                         \par
                                                    	 \#BIT_PARAM : FIX_RING_TONE_VOL_ENABLE \n
                                                    	 \#BIT_ALIAS : Enable Fix Ring Tone Volume \n
                                                    	 \#BIT_POS : 1 \n
                                                    	 \#BIT_SIZE : 1 \n
                                                    	 \#BIT_DESC : If this option is enabled (set to 1), the gain level of ring tone gain will use fixed value \n
                                                    	              (refer to the RingTone_Volume parameter). Otherwise, it has two conditions: \n
                                                                      1. The ring tone volume will follow the volume of playing sound. \n
                                                                      2. The ring tone gain level will use the level of SCO if no sound is playing. \n
                                                    	 \#DESC_END

                                                    	 \par
                                                    	 \#BIT_PARAM : BUTTON_0_FORCE_ALARM_ENABLE \n
                                                    	 \#BIT_ALIAS : Enable Force Button_0 Alarm \n
                                                    	 \#BIT_POS : 2 \n
                                                    	 \#BIT_SIZE : 1 \n
                                                    	 \#BIT_DESC : Always ring a long press tone when button 0 is pressed over the time of Long_Button_Press_time parameter. \n
                                                    	              The button 0 is MFB button. 1: enabled, 0:disabled. \n
                                                    	 \#DESC_END

                                                    	 \par
                                                    	 \#BIT_PARAM : ALL_BUTTON_FORCE_ALARM_ENABLE \n
                                                    	 \#BIT_ALIAS : Enable Force All Button Alarm \n
                                                    	 \#BIT_POS : 3 \n
                                                    	 \#BIT_SIZE : 1 \n
                                                    	 \#BIT_DESC : Always ring a tone when button(s) is pressed. \n
                                                    	              The tone type depends on pressing behavior, it may be short press tone, long press tone and double click tone. \n
                                                    	              1:enabled, 0:disabled. \n
                                                    	 \#DESC_END

                                                    	 \par
                                                    	 \#BIT_PARAM : ENABLE_USE_CONNECTED_TONE2 \n
                                                    	 \#BIT_ALIAS : Enable Use Connected Tone2 \n
                                                    	 \#BIT_POS : 4 \n
                                                    	 \#BIT_SIZE : 1 \n
                                                    	 \#BIT_DESC : 0 : use dedicate profile connected tone setting \n
                                                                      1 : use connected_tone2 as 2nd connected profile indication tone \n
                                                    	 \#DESC_END
                                                    	 
                                                         \par
                                                         \#BIT_PARAM : ENABLE_VOICE_PROMPT_BATT_STATUS \n
                                                         \#BIT_ALIAS : Report Battery Status By Voice Prompt \n
                                                         \#BIT_POS : 5 \n
                                                         \#BIT_SIZE : 1 \n
                                                         \#BIT_DESC : If this option is enabled, prompt battery status by tones when trigger MMI event "SHS_INDICATE_BATTERY_STATUS". \n
                                                                      Otherwise, indicate battery status by LED. \n
                                                         \#DESC_END

                                                    	 \par
                                                    	 \#BIT_PARAM : ENABLE_POWERON_PROMPT_BATT_LEVEL \n
                                                    	 \#BIT_ALIAS : Power On Prompt Battery Level \n
                                                    	 \#BIT_POS : 6 \n
                                                    	 \#BIT_SIZE : 1 \n
                                                    	 \#BIT_DESC : If this option is enabled, it will prompt battery status by tones when power on. \n
                                                    	 \#DESC_END

                                                    	 \par
                                                    	 \#BIT_PARAM : ENABLE_VP_TONE_IN_MSPK_SLAVE \n
                                                    	 \#BIT_ALIAS : Allow Voice Prompt in MSPK Slave \n
                                                    	 \#BIT_POS : 7 \n
                                                    	 \#BIT_SIZE : 1 \n
                                                    	 \#BIT_DESC : Set this option to allow voice prompt in MSPK slave(s). Please note that it might cause audio unsync after MSPK slave \n
                                                    	 \#DESC_END
                                                    */  
    

    TONE_CFG_KEY_END
}TONE_CFG_Key_IdDefinition_T;



/**@defgroup APP_CFG_TONE_DEFAULT_VALUE  TONE Configuration Default Value
 * @brief Default value definition of the module @ref CFG_MODULE_ID_TONE.
 * @{ */

#define CFG_TONE_MODULE_TOTAL_NUM_KEYS   (TONE_CFG_KEY_END - 1)

//Module TONE
#define TONE_CFG_KEY_TONE_SET_LEN                               0x01    /**< The default length of @ref TONE_CFG_KEY_TONE_SET. */
#define TONE_CFG_KEY_TONE_SET_DEFAULT_VALUE                     0x00    /**< The default value of @ref TONE_CFG_KEY_TONE_SET. */

#define TONE_CFG_KEY_SHORT_PRESS_TONE_LEN                       0x01    /**< The default length of @ref TONE_CFG_KEY_SHORT_PRESS_TONE. */
#define TONE_CFG_KEY_SHORT_PRESS_TONE_DEFAULT_VALUE             0x02    /**< The default value of @ref TONE_CFG_KEY_SHORT_PRESS_TONE. */

#define TONE_CFG_KEY_LONG_PRESS_TONE_LEN                        0x01    /**< The default length of @ref TONE_CFG_KEY_LONG_PRESS_TONE. */
#define TONE_CFG_KEY_LONG_PRESS_TONE_DEFAULT_VALUE              0x07    /**< The default value of @ref TONE_CFG_KEY_LONG_PRESS_TONE. */

#define TONE_CFG_KEY_DOUBLE_CLICK_TONE_LEN                      0x01    /**< The default length of @ref TONE_CFG_KEY_DOUBLE_CLICK_TONE. */
#define TONE_CFG_KEY_DOUBLE_CLICK_TONE_DEFAULT_VALUE            0x0D    /**< The default value of @ref TONE_CFG_KEY_DOUBLE_CLICK_TONE. */

#define TONE_CFG_KEY_LINK_QUALITY_WARNING_TONE_LEN              0x01    /**< The default length of @ref TONE_CFG_KEY_LINK_QUALITY_WARNING_TONE. */
#define TONE_CFG_KEY_LINK_QUALITY_WARNING_TONE_DEFAULT_VALUE    0x00    /**< The default value of @ref TONE_CFG_KEY_LINK_QUALITY_WARNING_TONE. */

#define TONE_CFG_KEY_TONE_SET_MASK_LEN                          0x01    /**< The default length of @ref TONE_CFG_KEY_TONE_SET_MASK. */
#define TONE_CFG_KEY_TONE_SET_MASK_DEFAULT_VALUE                0x0F    /**< The default value of @ref TONE_CFG_KEY_TONE_SET_MASK. */

#define TONE_CFG_KEY_PRESS_VOL_KEY_TONE_LEN                     0x01    /**< The default length of @ref TONE_CFG_KEY_PRESS_VOL_KEY_TONE. */
#define TONE_CFG_KEY_PRESS_VOL_KEY_TONE_DEFAULT_VALUE           0x00    /**< The default value of @ref TONE_CFG_KEY_PRESS_VOL_KEY_TONE. */

#define TONE_CFG_KEY_CONNECTED_TONE2_LEN                        0x01    /**< The default length of @ref TONE_CFG_KEY_CONNECTED_TONE2. */
#define TONE_CFG_KEY_CONNECTED_TONE2_DEFAULT_VALUE              0x1B    /**< The default value of @ref TONE_CFG_KEY_CONNECTED_TONE2. */

#define TONE_CFG_KEY_FUNCTION_ALARM_TONE_LEN                    0x01    /**< The default length of @ref TONE_CFG_KEY_FUNCTION_ALARM_TONE. */
#define TONE_CFG_KEY_FUNCTION_ALARM_TONE_DEFAULT_VALUE          0x02    /**< The default value of @ref TONE_CFG_KEY_FUNCTION_ALARM_TONE. */

#define TONE_CFG_KEY_RINGTONE_VOLUME_LEN                        0x01    /**< The default length of @ref TONE_CFG_KEY_RINGTONE_VOLUME. */
#define TONE_CFG_KEY_RINGTONE_VOLUME_DEFAULT_VALUE              0x09    /**< The default value of @ref TONE_CFG_KEY_RINGTONE_VOLUME. */

#define TONE_CFG_KEY_TONE_MODE_4_32_LEN                         0x80    /**< The default length of @ref TONE_CFG_KEY_TONE_MODE_4_32. */
#define TONE_CFG_KEY_TONE_MODE_4_32_DEFAULT_VALUE               /*tone set 0*/ /**< The default value of @ref TONE_CFG_KEY_TONE_MODE_4_32. */ \
                                                                0x1E, 0x1F, 0x1D, 0x02, 0x00, 0x1C, 0x00, 0x1B, /*0-7*/  \
                                                                0x1A, 0x00, 0x00, 0x16, 0x00, 0x00, 0x00, 0x00, /*8-15*/ \
                                                                0x00, 0x00, 0x00, 0x0C, 0x0C, 0x00, 0x1B, 0x00, /*16-23*/\
                                                                0x0F, 0x00, 0x00, 0x00, 0x00, 0x06, 0x01, 0x00, /*24-31*/\
                                                                /*tone set 1*/\
                                                                0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /*0-7*/  \
                                                                0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /*8-15*/ \
                                                                0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /*16-23*/\
                                                                0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /*24-31*/\
                                                                /*tone set 2*/\
                                                                0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /*0-7*/  \
                                                                0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /*8-15*/ \
                                                                0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /*16-23*/\
                                                                0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /*24-31*/\
                                                                /*tone set 3*/\
                                                                0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /*0-7*/  \
                                                                0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /*8-15*/ \
                                                                0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /*16-23*/\
                                                                0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00  /*24-31*/
                                                                /**< The default value of @ref TONE_CFG_KEY_TONE_MODE_4_32. */

#define TONE_CFG_KEY_CSB_ENTER_PAIRING_TONE_LEN                 0x01    /**< The default length of @ref TONE_CFG_KEY_CSB_ENTER_PAIRING_TONE. */
#define TONE_CFG_KEY_CSB_ENTER_PAIRING_TONE_DEFAULT_VALUE       0x0F    /**< The default value of @ref TONE_CFG_KEY_CSB_ENTER_PAIRING_TONE. */

#define TONE_CFG_KEY_CSB_CONNECTION_TONE_LEN                    0x01    /**< The default length of @ref TONE_CFG_KEY_CSB_CONNECTION_TONE. */
#define TONE_CFG_KEY_CSB_CONNECTION_TONE_DEFAULT_VALUE          0x02    /**< The default value of @ref TONE_CFG_KEY_CSB_CONNECTION_TONE. */

#define TONE_CFG_KEY_CSB_DISCONNECTION_TONE_LEN                 0x01    /**< The default length of @ref TONE_CFG_KEY_CSB_DISCONNECTION_TONE. */
#define TONE_CFG_KEY_CSB_DISCONNECTION_TONE_DEFAULT_VALUE       0x0F    /**< The default value of @ref TONE_CFG_KEY_CSB_DISCONNECTION_TONE. */

#define TONE_CFG_KEY_TONE_OPTION_LEN                            0x01    /**< The default length of @ref TONE_CFG_KEY_TONE_OPTION. */
#define TONE_CFG_KEY_TONE_OPTION_DEFAULT_VALUE                  0x14    /**< The default value of @ref TONE_CFG_KEY_TONE_OPTION. */


/** @} */
/** @} */

/** \cond NON_DOC */

#define CFG_TONE_MODULE_TOTAL_SIZE  ((CFG_TONE_MODULE_TOTAL_NUM_KEYS*SIZEOF_CFG_KEY_STRUCT) +  \
                                    TONE_CFG_KEY_TONE_SET_LEN +                             \
                                    TONE_CFG_KEY_SHORT_PRESS_TONE_LEN +                     \
                                    TONE_CFG_KEY_LONG_PRESS_TONE_LEN +                      \
                                    TONE_CFG_KEY_DOUBLE_CLICK_TONE_LEN +                    \
                                    TONE_CFG_KEY_LINK_QUALITY_WARNING_TONE_LEN +            \
                                    TONE_CFG_KEY_TONE_SET_MASK_LEN +                        \
                                    TONE_CFG_KEY_PRESS_VOL_KEY_TONE_LEN +                   \
                                    TONE_CFG_KEY_CONNECTED_TONE2_LEN +                      \
                                    TONE_CFG_KEY_FUNCTION_ALARM_TONE_LEN +                  \
                                    TONE_CFG_KEY_RINGTONE_VOLUME_LEN +                      \
                                    TONE_CFG_KEY_TONE_MODE_4_32_LEN +                       \
                                    TONE_CFG_KEY_CSB_ENTER_PAIRING_TONE_LEN +               \
                                    TONE_CFG_KEY_CSB_CONNECTION_TONE_LEN +                  \
                                    TONE_CFG_KEY_CSB_DISCONNECTION_TONE_LEN +               \
                                    TONE_CFG_KEY_TONE_OPTION_LEN)


//TONE Config keys definition
#define CFG_TONE_MODULE_DEFAULT_VALUE   CFG_MODULE_ID_TONE,               /*moduleID*/   \
                                        CFG_TONE_MODULE_TOTAL_NUM_KEYS,   /*numKeys*/    \
                                        (CFG_TONE_MODULE_TOTAL_SIZE >> 8),  /*moduleSize*/  \
                                        CFG_TONE_MODULE_TOTAL_SIZE,                      \
                                        /*CFG_KEYs[numKeys]*/                           \
                                        /*    //ID                                                                  //Len                                                                                    //Value    */                                  \
                                        TONE_CFG_KEY_TONE_SET,                   TONE_CFG_KEY_TONE_SET_LEN,                     TONE_CFG_KEY_TONE_SET_DEFAULT_VALUE,                   \
                                        TONE_CFG_KEY_SHORT_PRESS_TONE,           TONE_CFG_KEY_SHORT_PRESS_TONE_LEN,             TONE_CFG_KEY_SHORT_PRESS_TONE_DEFAULT_VALUE,           \
                                        TONE_CFG_KEY_LONG_PRESS_TONE,            TONE_CFG_KEY_LONG_PRESS_TONE_LEN,              TONE_CFG_KEY_LONG_PRESS_TONE_DEFAULT_VALUE,            \
                                        TONE_CFG_KEY_DOUBLE_CLICK_TONE,          TONE_CFG_KEY_DOUBLE_CLICK_TONE_LEN,            TONE_CFG_KEY_DOUBLE_CLICK_TONE_DEFAULT_VALUE,          \
                                        TONE_CFG_KEY_LINK_QUALITY_WARNING_TONE,  TONE_CFG_KEY_LINK_QUALITY_WARNING_TONE_LEN,    TONE_CFG_KEY_LINK_QUALITY_WARNING_TONE_DEFAULT_VALUE,  \
                                        TONE_CFG_KEY_TONE_SET_MASK,              TONE_CFG_KEY_TONE_SET_MASK_LEN,                TONE_CFG_KEY_TONE_SET_MASK_DEFAULT_VALUE,              \
                                        TONE_CFG_KEY_PRESS_VOL_KEY_TONE,         TONE_CFG_KEY_PRESS_VOL_KEY_TONE_LEN,           TONE_CFG_KEY_PRESS_VOL_KEY_TONE_DEFAULT_VALUE,         \
                                        TONE_CFG_KEY_CONNECTED_TONE2,            TONE_CFG_KEY_CONNECTED_TONE2_LEN,              TONE_CFG_KEY_CONNECTED_TONE2_DEFAULT_VALUE,            \
                                        TONE_CFG_KEY_FUNCTION_ALARM_TONE,        TONE_CFG_KEY_FUNCTION_ALARM_TONE_LEN,          TONE_CFG_KEY_FUNCTION_ALARM_TONE_DEFAULT_VALUE,        \
                                        TONE_CFG_KEY_RINGTONE_VOLUME,            TONE_CFG_KEY_RINGTONE_VOLUME_LEN,              TONE_CFG_KEY_RINGTONE_VOLUME_DEFAULT_VALUE,            \
                                        TONE_CFG_KEY_TONE_MODE_4_32,             TONE_CFG_KEY_TONE_MODE_4_32_LEN,               TONE_CFG_KEY_TONE_MODE_4_32_DEFAULT_VALUE,             \
                                        TONE_CFG_KEY_CSB_ENTER_PAIRING_TONE,     TONE_CFG_KEY_CSB_ENTER_PAIRING_TONE_LEN,       TONE_CFG_KEY_CSB_ENTER_PAIRING_TONE_DEFAULT_VALUE,     \
                                        TONE_CFG_KEY_CSB_CONNECTION_TONE,        TONE_CFG_KEY_CSB_CONNECTION_TONE_LEN,          TONE_CFG_KEY_CSB_CONNECTION_TONE_DEFAULT_VALUE,        \
                                        TONE_CFG_KEY_CSB_DISCONNECTION_TONE,     TONE_CFG_KEY_CSB_DISCONNECTION_TONE_LEN,       TONE_CFG_KEY_CSB_DISCONNECTION_TONE_DEFAULT_VALUE,     \
                                        TONE_CFG_KEY_TONE_OPTION,                TONE_CFG_KEY_TONE_OPTION_LEN,                  TONE_CFG_KEY_TONE_OPTION_DEFAULT_VALUE



#define TONE_TYPE_MAX_SIZE (0x20)

/**@brief The structure contains the bit options for @ref TONE_CFG_KEY_TONE_MODE_4_32*/
typedef struct _APP_Cfg_ToneType_T
{
    uint8_t powerOn;
    uint8_t powerOff;
    uint8_t enterPairing;
    uint8_t pairingComplete;
    uint8_t pairingIncomplete;
    uint8_t incomingCall;
    uint8_t rejectCall;
    uint8_t callActive;
    uint8_t callEnd;
    uint8_t chargingInitiate;
    uint8_t chargingComplete;
    uint8_t batteryLevel_0;
    uint8_t batteryLevel_1;
    uint8_t batteryLevel_2;
    uint8_t batteryLevel_3;
    uint8_t batteryLevel_4;
    uint8_t batteryLevel_5;
    uint8_t batteryLevel_6;
    uint8_t batteryLevel_7;
    uint8_t maxVol;
    uint8_t minVol;
    uint8_t hfConnected;
    uint8_t a2dpConnected;
    uint8_t disconnected;
    uint8_t linkLost;
    uint8_t changeToneSet;
    uint8_t voiceDial;
    uint8_t lastCallRedial;
    uint8_t noService;
    uint8_t buttonLock;
    uint8_t micMute;
    uint8_t reserved;
} APP_Cfg_ToneType_T;

typedef struct _APP_Cfg_ToneCsb_T
{
    uint8_t enterPairing;
    uint8_t connected;
    uint8_t disconnected;
} APP_Cfg_ToneCsb_T;

typedef struct _APP_Cfg_ToneBtn_T
{
    uint8_t shortPressedTone;
    uint8_t longPressedTone;
    uint8_t singleClickTone;
    uint8_t doubleClickTone;
    uint8_t tripleClickTone;
} APP_Cfg_ToneBtn_T;

typedef struct _APP_Cfg_ToneOption_T
{
    uint8_t reserved0 : 1;
    uint8_t fixedRingtoneVolume : 1;
    uint8_t mfbButtonForceAlarm : 1;
    uint8_t allButtonForceAlarm : 1;
    uint8_t useConnectedTone2 : 1;
    uint8_t voicePromptBattStatus : 1;
    uint8_t powerOnPromptBattLevel : 1;
    uint8_t enableVpInMspkSlave : 1;
} APP_Cfg_ToneOption_T;


void APP_CFG_ReadToneAllTypeOfToneSet(APP_Cfg_ToneType_T XDATA *p_toneType);
void APP_CFG_ReadToneCsb(APP_Cfg_ToneCsb_T XDATA *p_csbTone);
void APP_CFG_ReadToneAlarm(uint8_t XDATA *p_toneMode);
void APP_CFG_ReadToneButton(APP_Cfg_ToneBtn_T XDATA *p_btnTone);
void APP_CFG_ReadToneOption(APP_Cfg_ToneOption_T XDATA *p_toneOption);
void APP_CFG_ChangeNextValidToneSet(APP_Cfg_ToneType_T XDATA *p_toneType);
void APP_CFG_ReadConnectedTone2(uint8_t XDATA *p_toneMode);
void APP_CFG_ReadRingtoneVolume(uint8_t XDATA *p_toneVolume);
/// @endcond

#endif//APP_CFG_TONE_H

