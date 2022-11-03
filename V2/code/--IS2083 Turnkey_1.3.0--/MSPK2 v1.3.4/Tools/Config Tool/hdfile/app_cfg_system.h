/********************************************************************
    File Information:
    FileName:       app_cfg_system.h
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

#ifndef APP_CFG_SYSTEM_H
#define APP_CFG_SYSTEM_H

/** \cond NON_DOC 

\#TARGET_LIST : MSPKv2_SPP
\#TARGET_LIST : MSPKv2_GFP
\#TARGET_LIST : MSPKv2_PBAP
\#TARGET_LIST : MSPKv2_App_Basic
\#TARGET_LIST : AT_App

\#BUILD_TARGET : MSPKv2_App_Basic
\#BUILD_TARGET : MSPKv2_SPP
\#BUILD_TARGET : MSPKv2_GFP
\#BUILD_TARGET : MSPKv2_PBAP
\#TARGET_START

\#REMOVE_PARAM : SYS_CFG_KEY_USB_VID
\#REMOVE_PARAM : SYS_CFG_KEY_USB_PID
\#REMOVE_PARAM : SYS_CFG_KEY_VIRTUAL_OFF_COUNTER
\#REMOVE_PARAM : SYS_CFG_KEY_DEVICE_NAME_BACKUP
\#REMOVE_BIT : ENABLE_POWER_ON_DIRECTLY
\#REMOVE_BIT : HOST_ENABLE_SIMPLE_PAIRING
\#REMOVE_PARAM : SYS_CFG_KEY_RESERVE2
\#REMOVE_PARAM : SYS_CFG_KEY_RESERVE3
\#REMOVE_PARAM : SYS_CFG_KEY_SOFT_RESET_DIRECT_POWERON
\#REMOVE_PARAM : SYS_CFG_KEY_OTA_DFU_IV
\#REMOVE_PARAM : SYS_CFG_KEY_AT_APP_MODE

\#TARGET_END


\#BUILD_TARGET : AT_App
\#TARGET_START

\#REMOVE_PARAM : SYS_CFG_KEY_VENDOR_DATA
\#REMOVE_PARAM : SYS_CFG_KEY_USB_VID
\#REMOVE_PARAM : SYS_CFG_KEY_USB_PID
\#REMOVE_PARAM : SYS_CFG_KEY_VIRTUAL_OFF_COUNTER
\#REMOVE_PARAM : SYS_CFG_KEY_DEVICE_NAME_BACKUP
\#REMOVE_BIT : ENABLE_POWER_ON_DIRECTLY
\#REMOVE_BIT : HOST_ENABLE_SIMPLE_PAIRING
\#REMOVE_PARAM : SYS_CFG_KEY_RESERVE2
\#REMOVE_PARAM : SYS_CFG_KEY_RESERVE3
\#REMOVE_PARAM : SYS_CFG_KEY_SOFT_RESET_DIRECT_POWERON
\#REMOVE_PARAM : SYS_CFG_KEY_OTA_DFU_IV

\#TARGET_END

\endcond
*/

/**
  @addtogroup APP_CFG_SYSTEM SYSTEM Configuration
  @{
  @brief Definitions and prototypes for the System Configuration.
 */

//Config Key definiton of MODULE_SYSTEM(0x01)
/**
 * @brief Configuration key definition of the module @ref CFG_MODULE_ID_SYSTEM.
 *  */
typedef enum _SYS_CFG_Key_IdDefinition_T
{
	
    SYS_CFG_KEY_CLASS                = 0x01,    /**<\#PARAM_NAME : SYS_CFG_KEY_CLASS \n
                                                    \#ALIAS : BT Class of Device \n
                                                    \#PARAM_TYPE : Public \n
                                                    \#PARAM_DESC : The class of device/service field (CoD) of the device configuration. \n
                                                    \#DESC_END \n
                                                    \#GROUP_ID : 0x01 \n
                                                    \#KEY_ID : 0x01 \n
                                            	*/

	
    SYS_CFG_KEY_HCI_BAUD_RATE_INDEX  = 0x02,    /**<\#PARAM_NAME : SYS_CFG_KEY_HCI_BAUD_RATE_INDEX \n
                                                    \#ALIAS : UART Baudrate \n
                                                    \#PARAM_TYPE : Public \n
                                                    \#PARAM_DESC : The baud rate configuration of UART. Unit : bps. \n
                                                                   This option is choosable only if choose item "Host MCU Mode" \n
                                                    \par           
                                                                   Baud rate definitions: \n
                                                                   0x00: 921600 \n
                                                                   0x01: 460800 \n
                                                                   0x02: 230400 \n
                                                                   0x03: 115200 \n
                                                                   0x04: 57600  \n
                                                                   0x05: 38400  \n
                                                                   0x06: 28800  \n
                                                                   0x07: 19200  \n
                                                                   0x08: 14400  \n
                                                                   0x09: 9600   \n
                                                                   0x0A: 4800   \n
                                                                   0x0B: 2400   \n
                                                    \#DESC_END  \n                                                             
                                                    \#GROUP_ID : 0x01 \n
                                                    \#KEY_ID : 0x02 \n
                                            	*/
    
	
	SYS_CFG_KEY_AUTO_POWER_OFF_TIME  = 0x03,   /**<  \#PARAM_NAME : SYS_CFG_KEY_AUTO_POWER_OFF_TIME \n
                                                	 \#ALIAS : Auto Power Off Time \n
                                                     \#PARAM_TYPE : Public \n
                                                	 \#PARAM_DESC : The timer of auto power off for power saving. \n
                                                	 \#DESC_END  \n
                                                	 \#GROUP_ID : 0x01 \n
                                                	 \#KEY_ID : 0x03 \n
                                                	 \#VALID_MAX : 0xFE \n
                                                	 \#VALID_MIN : 0x01 \n
                                               */

   

    SYS_CFG_KEY_MUTE_ALARM_TIME      = 0x04,   /**<  \#PARAM_NAME : SYS_CFG_KEY_MUTE_ALARM_TIME \n
                                                	 \#ALIAS : Microphone Mute Alarm Interval \n
                                                     \#PARAM_TYPE : Public \n
                                                	 \#PARAM_DESC : If the speaker has calls and its microphone is muted , it will ring the mute tone to alert user \n
                                                                    periodically with this interval(unit in 640 ms) \n
                                                     \#DESC_END  \n
                                                	 \#GROUP_ID : 0x01 \n
                                                	 \#KEY_ID : 0x04 \n
                                                	 \#VALID_MAX : 0xFE \n
                                                	 \#VALID_MIN : 0x03 \n
                                               */
                                               

 
    SYS_CFG_KEY_MCU_WAKEUP_TIME      = 0x05,   /**<  \#PARAM_NAME : SYS_CFG_KEY_MCU_WAKEUP_TIME \n
                                                	 \#ALIAS : Wake Up Host MCU Delay Time \n
                                                     \#PARAM_TYPE : Public \n
                                                	 \#PARAM_DESC : The waiting time to start UART TX after wakeup mcu. That is, it is the guard time for MCU wakeup.
                                                                   The value 0x00 means the speaker doesn't need to wake up MCU before sending data to MCU. (unit in 0.3125ms) \n
                                                     \#DESC_END  \n
                                                	 \#GROUP_ID : 0x01 \n
                                                	 \#KEY_ID : 0x05 \n
                                                	 \#VALID_MAX : 0xFE \n
                                                	 \#VALID_MIN : 0x00 \n
                                               */
    

    SYS_CFG_KEY_VENDOR_DATA           = 0x06,  /**<  \#PARAM_NAME : SYS_CFG_KEY_VENDOR_DATA \n
                                                	 \#ALIAS : Vendor Data \n
                                                     \#PARAM_TYPE : Private \n
                                                	 \#PARAM_DESC : 1. Vendor Data can be used to save information, e.g., developer configuration version information. \n
                                                                    2. You can use the UART command 0x31 to get that information. \n
                                                	 \#DESC_END  \n
                                                     \#GROUP_ID : 0x01 \n
                                                	 \#KEY_ID : 0x06 \n
                                               */

    SYS_CFG_KEY_USB_VID              = 0x07,   /**<  \#PARAM_NAME : SYS_CFG_KEY_USB_VID \n
                                                	 \#ALIAS : USB vendor ID \n
                                                     \#PARAM_TYPE : Private \n
                                                	 \#PARAM_DESC : USB vendor ID \n
                                                	 \#DESC_END  \n
                                                	 \#GROUP_ID : 0x01 \n
                                                	 \#KEY_ID : 0x07 \n
                                               */ 

    SYS_CFG_KEY_USB_PID              = 0x08,    /**< \#PARAM_NAME : SYS_CFG_KEY_USB_PID \n
                                                	 \#ALIAS : USB product ID \n
                                                     \#PARAM_TYPE : Private \n
                                                	 \#PARAM_DESC : USB product ID \n
                                                	 \#DESC_END  \n
                                                	 \#GROUP_ID : 0x01 \n
                                                	 \#KEY_ID : 0x08 \n
                                               */
    SYS_CFG_KEY_VIRTUAL_OFF_COUNTER  = 0x09,   /**<  \#PARAM_NAME : SYS_CFG_KEY_VIRTUAL_OFF_COUNTER \n
                                                	 \#ALIAS : Internal off time \n
                                                     \#PARAM_TYPE : Private \n
                                                	 \#PARAM_DESC : This timer will be trigger when MFB is pressed in off state. It will cut the power when timeout. \n
                                                	 \#DESC_END  \n
                                                	 \#GROUP_ID : 0x01 \n
                                                	 \#KEY_ID : 0x09 \n
                                                	 \#VALID_MAX : 0xFF \n
                                                	 \#VALID_MIN : 0x01 \n
                                                	 \note Depreciated.
                                               */
    SYS_CFG_KEY_DEVICE_NAME_BACKUP   = 0x0A,   /**<  \#PARAM_NAME : SYS_CFG_KEY_DEVICE_NAME_BACKUP \n
                                                	 \#ALIAS : Internal parameter to store backup name \n
                                                     \#PARAM_TYPE : Private \n
                                                	 \#PARAM_DESC : Internal parameter to store backup name. \n
                                                	 \#DESC_END  \n
                                                	 \#GROUP_ID : 0x01 \n
                                                	 \#KEY_ID : 0x0A \n
                                               */
    SYS_CFG_KEY_OPTION1              = 0x0B,   /**<  \#PARAM_NAME : SYS_CFG_KEY_OPTION1 \n
                                                	 \#PARAM_TYPE : Public \n
                                                	 \#GROUP_ID : 0x01 \n
                                                	 \#KEY_ID : 0x0B \n
                                                	 Bit Options:
                                                	 \par
                                                	 \#BIT_PARAM : ENABLE_UART_STATUS_REPORT \n
                                                	 \#BIT_ALIAS : Enable UART events \n
                                                	 \#BIT_POS : 0 \n
                                                	 \#BIT_SIZE : 1 \n
                                                	 \#BIT_DESC : Enable this option to support host MCU mode.\n
                                                	 \#DESC_END  \n

                                                     \par
                                                	 \#BIT_PARAM : ENABLE_UART_INTERFACE \n
                                                	 \#BIT_ALIAS : UART Command \n
                                                	 \#BIT_POS : 1 \n
                                                	 \#BIT_SIZE : 1 \n
                                                	 \#BIT_DESC : Enable this option to support UART interface which is necessary for host MCU mode. \n
                                                                  option value auto changed according to "Host MCU Mode" or "Embedded Mode", not changeable.
                                                	 \#DESC_END  \n

                                                	 \par
                                                	 \#BIT_PARAM : DISABLE_UART_ACK_CONFIRM \n
                                                	 \#BIT_ALIAS : Disable Waiting for ACK \n
                                                	 \#BIT_POS : 2 \n
                                                	 \#BIT_SIZE : 1 \n
                                                	 \#BIT_DESC : If this option is set, it will not wait the ACK of UART event from MCU after reporting \n
                                                	 transparent data (UART event ID 0x22) to MCU. It is usually used in throughput sensitive case and MCU 
                                                	 has capability to process burst data.\n
                                                	 \#DESC_END  \n

                                                	 \par
                                                	 \#BIT_PARAM : ENABLE_POWER_ON_DIRECTLY \n
                                                	 \#BIT_ALIAS : Power on directly \n
                                                	 \#BIT_POS : 3 \n
                                                	 \#BIT_SIZE : 1 \n
                                                	 \#BIT_DESC : If this option is set, it will power on directly after system initialization complete\n
                                                	 \#DESC_END  \n

                                                	 \par
                                                	 \#BIT_PARAM : ENABLE_UART_EVENT_PREFIX_PADDING \n
                                                	 \#BIT_ALIAS : UART Protocol Tx Padding \n
                                                	 \#BIT_POS : 4 \n
                                                	 \#BIT_SIZE : 1 \n
                                                	 \#BIT_DESC : Insert one byte 0x00 in the front of the start byte 0xAA of UART event. This can be used to wake up host MCU.\n
                                                	 \#DESC_END  \n

                                                	 \par
                                                	 \#BIT_PARAM : ENABLE_EMBEDDED_MODE \n
                                                	 \#BIT_ALIAS : Enable embedded mode \n
                                                	 \#BIT_POS : 7 \n
                                                	 \#BIT_SIZE : 1 \n
                                                	 \#BIT_DESC : If this option is set, the application will be running in embedded mode.\n
                                                	 \#DESC_END  \n
                                               */  

    SYS_CFG_KEY_OPTION2              = 0x0C,   /**<  \#PARAM_NAME : SYS_CFG_KEY_OPTION2 \n
                                                	 \#PARAM_TYPE : Public \n
                                                	 \#GROUP_ID : 0x01 \n
                                                	 \#KEY_ID : 0x0C \n
                                                	 Bit Options:
                                                	 \par
                                                	 \#BIT_PARAM : HOST_ENABLE_SIMPLE_PAIRING \n
                                                	 \#BIT_ALIAS : Simple Pairing \n
                                                	 \#BIT_POS : 0 \n
                                                	 \#BIT_SIZE : 1 \n
                                                	 \#BIT_DESC : Enable this option to support host MCU mode.\n
                                                	 \#DESC_END  \n

                                                     \par
                                                	 \#BIT_PARAM : ENABLE_KEEP_BLE_IN_POWEROFF \n
                                                	 \#BIT_ALIAS : Keep BLE In Power Off \n
                                                	 \#BIT_POS : 2 \n
                                                	 \#BIT_SIZE : 1 \n
                                                	 \#BIT_DESC : Keep BLE link or ADV active when the speaker is in off state.\n
                                                	 \#DESC_END  \n

                                                	 \par
                                                	 \#BIT_PARAM : ENABLE_DISCONNECT_ALL_IN_PAIRING \n
                                                	 \#BIT_ALIAS : Disconnect All In Pairing \n
                                                	 \#BIT_POS : 3 \n
                                                	 \#BIT_SIZE : 1 \n
                                                	 \#BIT_DESC : Disconnect all classic BT links when the speaker enters pairing mode.\n
                                                	 \#DESC_END  \n

                                                	 \par
                                                	 \#BIT_PARAM : ENABLE_ONLY_ACCEPT_PAIRED_DEVICE \n
                                                	 \#BIT_ALIAS : Only Accept Paired Device \n
                                                	 \#BIT_POS : 6 \n
                                                	 \#BIT_SIZE : 1 \n
                                                	 \#BIT_DESC : If this option is set, the speaker only accepts the connect request from paired devices when it is not in pairing mode.\n
                                                	 \#DESC_END  \n

                                                	 \par
                                                	 \#BIT_PARAM : ENABLE_NO_STREAM_AUTO_OFF \n
                                                	 \#BIT_ALIAS : A2DP Link Silence \n
                                                	 \#BIT_POS : 7 \n
                                                	 \#BIT_SIZE : 1 \n
                                                	 \#BIT_DESC : If this option is set, then system will be shut down automatically when it meets all of below conditions. \n
                                                	             A2DP/AVRCP is only one link \n
                                                	             Auto Power Off Timer has been timeout \n
                                                	             No button is pressed \n
                                                	             No power adapter plug in \n
                                                	             BT device doesn't receive any audio packet from AG any more.\n
                                                	 \#DESC_END  \n
                                               */

    SYS_CFG_KEY_OPTION3              = 0x0D,   /**<  \#PARAM_NAME : SYS_CFG_KEY_OPTION3 \n
                                                	 \#PARAM_TYPE : Public \n
                                                	 \#GROUP_ID : 0x01 \n
                                                	 \#KEY_ID : 0x0D \n
                                                	 Bit Options:
                                                	 \par
                                                	 \#BIT_PARAM : ENABLE_STANDBY_AUTO_POWER_OFF \n
                                                	 \#BIT_ALIAS : Auto Power Off Enable \n
                                                	 \#BIT_POS : 0 \n
                                                	 \#BIT_SIZE : 1 \n
                                                	 \#BIT_DESC : When system enter standby state, then set auto_power_off_time to shut down power. \n
                                                	             There are some conditions will disable this function:\n
                                                                        1. In charging. \n
                                                                        2. MSPK link exists (for MSPK Slave role). \n
                                                                        3. Aux-in is plugged in and not silent. \n
                                                                        4. The speaker is reconnecting. \n
                                                                        5. A2DP streaming. \n
                                                                        6. The speaker isn't in standby state.\n
                                                     \#DESC_END  \n

                                                     \par
                                                	 \#BIT_PARAM : ENABLE_SHUT_DOWN_AS_PAIRING_TO \n
                                                	 \#BIT_ALIAS : Pairing Timeout Shut Down Directly \n
                                                	 \#BIT_POS : 1 \n
                                                	 \#BIT_SIZE : 1 \n
                                                	 \#BIT_DESC : If this option is set, the speaker will shut down automatically when pairing timeout.\n
                                                	 \#DESC_END  \n

                                                	 \par
                                                	 \#BIT_PARAM : ENABLE_LINEIN_SILENCE_DETECTION \n
                                                	 \#BIT_ALIAS : Line In Silence Detection \n
                                                	 \#BIT_POS : 3 \n
                                                	 \#BIT_SIZE : 1 \n
                                                	 \#BIT_DESC : Detect silence status for Aux-in signal if this option is enabled. \n
                                                	             The duration to determine the Aux-in is silence is about 33 seconds. \n
                                                	 \#DESC_END  \n

                                                	 \par
                                                	 \#BIT_PARAM : POWER_ON_BY_UART_COMMAND_ONLY \n
                                                	 \#BIT_ALIAS : Power On by "Power On" Command \n
                                                	 \#BIT_POS : 6 \n
                                                	 \#BIT_SIZE : 1 \n
                                                	 \#BIT_DESC : This option is only for Configuration tool "Power Switch Type" setting storage and no use in FW.\n
                                                	 \#DESC_END  \n
                                               */

    //deleteItem
    SYS_CFG_KEY_RESERVE2         = 0x0E,       /**<  \#PARAM_NAME : SYS_CFG_KEY_RESERVE2 \n
                                                	 \#ALIAS : Reserved2 \n
                                                     \#PARAM_TYPE : Private \n
                                                	 \#PARAM_DESC : Reserved. \n
                                                	 \#DESC_END  \n
                                                	 \#GROUP_ID : 0x01 \n
                                                	 \#KEY_ID : 0x0E \n
                                               */
    //deleteItem
    SYS_CFG_KEY_RESERVE3		 = 0x0F,       /**<  \#PARAM_NAME : SYS_CFG_KEY_RESERVE3 \n
                                                	 \#ALIAS : Reserved3 \n
                                                     \#PARAM_TYPE : Private \n
                                                	 \#PARAM_DESC : Reserved. \n
                                                	 \#DESC_END  \n
                                                	 \#GROUP_ID : 0x01 \n
                                                	 \#KEY_ID : 0x0F \n
                                               */
    
    SYS_CFG_KEY_POWER_SAVE_OPTION    = 0x10,   /**<  \#PARAM_NAME : SYS_CFG_KEY_POWER_SAVE_OPTION \n
                                                     \#PARAM_TYPE : Public \n
                                                	 \#GROUP_ID : 0x01 \n
                                                	 \#KEY_ID : 0x10 \n
                                                	 
                                                	 \par
                                                	 \#BIT_PARAM : ENABLE_CPU_IDLE_MODE \n
                                                	 \#BIT_ALIAS : CPU Idle Mode \n
                                                	 \#BIT_POS : 0 \n
                                                	 \#BIT_SIZE : 1 \n
                                                	 \#BIT_DESC : If this option is set, it will enter 32K clock mode when system is idle. \n
                                                	 \#DESC_END  \n
                                               */ 
    SYS_CFG_KEY_SOFT_RESET_DIRECT_POWERON   = 0x11, /**< \#PARAM_NAME : SYS_CFG_KEY_SOFT_RESET_DIRECT_POWERON \n
                                                	     \#ALIAS : System internal parameter \n
                                                         \#PARAM_TYPE : Private \n
                                                    	 \#PARAM_DESC : If this value is non-zero, it will do power on process directly after software reset. \n
                                                    	               This value will be set before software reset (it might need software reset after OTA tuning.) \n
                                                    	 \#DESC_END  \n
                                                    	 \#GROUP_ID : 0x01 \n
                                                    	 \#KEY_ID : 0x11 \n
                                                    */
    SYS_CFG_KEY_SNIFF_INTERVAL              = 0x12, /**< \#PARAM_NAME : SYS_CFG_KEY_SNIFF_INTERVAL \n
                                                	 \#PARAM_TYPE : Public \n
                                                    	 \#PARAM_DESC : BT sniff interval setting. The first 2 bytes are MAX interval, the 3rd, 4th bytes are MIN interval (Unit: 625 us)\n
                                                    	 \#DESC_END  \n
                                                    	 \#GROUP_ID : 0x01 \n
                                                    	 \#KEY_ID : 0x12 \n
                                                              \par
                                                              \#BIT_PARAM : MAX_BT_SNIFF_INTERVAL \n
                                                              \#BIT_ALIAS : Max BT Sniff Interval \n
                                                              \#BIT_POS : 0 \n
                                                              \#BIT_SIZE : 16 \n
                                                              \#BIT_DESC : Max BT sniff interval \n
                                                              \#DESC_END
                                                              \par
                                                              \#BIT_PARAM : MIN_BT_SNIFF_INTERVAL \n
                                                              \#BIT_ALIAS : Min BT Sniff Interval \n
                                                              \#BIT_POS : 17 \n
                                                              \#BIT_SIZE : 16 \n
                                                              \#BIT_DESC : Min BT sniff interval \n
                                                              \#DESC_END
                                                    */
    SYS_CFG_KEY_OPTION4                     = 0x13, /**< \#PARAM_NAME : SYS_CFG_KEY_OPTION4 \n
                                                    	 \#PARAM_TYPE : Public \n
                                                    	 \#GROUP_ID : 0x01 \n
                                                    	 \#KEY_ID : 0x13 \n
                                                    	 Bit Options:
                                                    	 \par
                                                    	 \#BIT_PARAM : DISABLE_AUTO_UNSNIFF \n
                                                    	 \#BIT_ALIAS : Auto Unsniff in Data Transmission \n
                                                    	 \#BIT_POS : 0 \n
                                                    	 \#BIT_SIZE : 1 \n
                                                    	 \#BIT_DESC : After system enters sniff mode, it would not auto exit sniff mode if received packets or send packets. \n
                                                    	 \#DESC_END  \n
                                                         \par
                                                    	 \#BIT_PARAM : ENABLE_AVRCP_BROWSING \n
                                                    	 \#BIT_ALIAS : Enable AVRCP Browsing Feature\n
                                                    	 \#BIT_POS : 1 \n
                                                    	 \#BIT_SIZE : 1 \n
                                                    	 \#BIT_DESC : Enable AVRCP browsing feature. \n
                                                    	 \#DESC_END  \n
                                                    	 \par
                                                    	 \#BIT_PARAM : ENABLE_EDUTM \n
                                                    	 \#BIT_ALIAS : Allow Users to Enable Device Under Test Mode \n
                                                    	 \#BIT_POS : 2 \n
                                                    	 \#BIT_SIZE : 1 \n
                                                    	 \#BIT_DESC : This item is used to let the device enter test mode \n
                                                    	              so that user can do Bluetooth related hardware and certification test. \n
                                                    	              If you enable this item you can let the device switch to test mode by 
                                                    	              placing device in pairing mode and combine with either one of the following event. 
                                                    	              Besides, you don't need pull low some dedicated GPIO anymore.
                                                    	              Button trigger: triple click MFB
                                                    	              UART Command: MMI_Action(0x02)+Action ID(0x03) \n
                                                    	 \#DESC_END  \n
                                                    	 \par
                                                    	 \#BIT_PARAM : ENABLE_ROLE_SWITCH_MASTER \n
                                                    	 \#BIT_ALIAS : Auto Role Switch to BT Master \n
                                                    	 \#BIT_POS : 3 \n
                                                    	 \#BIT_SIZE : 1 \n
                                                    	 \#BIT_DESC : Role switch to be BT Master in piconet if current link is BT Slave. For multi-link scheme, enable this option to have a better performance.\n
                                                    	 \#DESC_END  \n
                                                    	 \par
                                                    	 \#BIT_PARAM : ENABLE_ROLE_SWITCH_POLICY \n
                                                    	 \#BIT_ALIAS : Enable Role Switch in Link Policy \n
                                                    	 \#BIT_POS : 4 \n
                                                    	 \#BIT_SIZE : 1 \n
                                                    	 \#BIT_DESC : Enable role switch in linkpolicy when BT link connected. \n
                                                    	 \#DESC_END  \n
                                                    	 \par
                                                    	 \#BIT_PARAM : FORCE_AS_BT_SLAVE \n
                                                    	 \#BIT_ALIAS : Force as BT Slave role\n
                                                    	 \#BIT_POS : 5 \n
                                                    	 \#BIT_SIZE : 1 \n
                                                    	 \#BIT_DESC : Role switch to be BT Slave in piconet if current link is BT Master. This option is exclusive with ENABLE_ROLE_SWITCH_MASTER.\n
                                                    	 \#DESC_END  \n
                                                   */
    SYS_CFG_KEY_OTA_DFU_IV                  = 0x14, /**< \#PARAM_NAME : SYS_CFG_KEY_OTA_DFU_IV \n
                                                	     \#ALIAS : OTA DFU IV \n
                                                         \#PARAM_TYPE : Private \n
                                                    	 \#PARAM_DESC : OTA DFU IV\n
                                                    	 \#DESC_END  \n
                                                    	 \#GROUP_ID : 0x01 \n
                                                    	 \#KEY_ID : 0x14 \n
                                                    */
    SYS_CFG_KEY_OTA_DFU_KEY                 = 0x15, /**< \#PARAM_NAME : SYS_CFG_KEY_OTA_DFU_KEY \n
                                                	     \#ALIAS : OTA DFU Key \n
                                                         \#PARAM_TYPE : Public \n
                                                    	 \#PARAM_DESC : OTA DFU key is used for encryption. For more details, you can search document "AN3118" on Microchip website\n
                                                    	 \#DESC_END  \n
                                                    	 \#GROUP_ID : 0x01 \n
                                                    	 \#KEY_ID : 0x15 \n
                                                    */
    SYS_CFG_KEY_AT_APP_MODE                 = 0x16,/**< \#PARAM_NAME : SYS_CFG_KEY_AT_APP_MODE \n
                                                	     \#ALIAS : AT APP MODE \n
                                                         \#PARAM_TYPE : Private \n
                                                    	 \#PARAM_DESC : Current AT Application Mode\n
                                                    	 \#DESC_END  \n
                                                    	 \#GROUP_ID : 0x01 \n
                                                    	 \#KEY_ID : 0x16 \n
                                                    */

    SYS_CFG_KEY_FW_IMAGE_ID                 = 0x17, /**< \#PARAM_NAME : SYS_CFG_KEY_FW_IMAGE_ID \n
                                                     \#ALIAS : FW Image ID \n
                                                     \#PARAM_TYPE : Private \n
                                                     \#PARAM_DESC : FW Image ID: The first bytes is Project ID; the second bytes is Target build ID \n
                                                     \#DESC_END  \n
                                                     \#GROUP_ID : 0x01 \n
                                                     \#KEY_ID : 0x17 \n
                                                    */
    SYS_CFG_KEY_END
}SYS_CFG_Key_IdDefinition_T;


/**@defgroup SYS_CFG_KEY_DEFAULT_VALUE SYS Configuration Default Value
 * @brief Default value definition of the module @ref CFG_MODULE_ID_SYSTEM.
 * @{ */

#define SYS_CFG_KEY_CLASS_LEN                            0x03   /**< The default length of @ref SYS_CFG_KEY_CLASS. */
#define SYS_CFG_KEY_CLASS_DEFAULT_VALUE                  0x04, 0x04, 0x24 /**< The default value of @ref SYS_CFG_KEY_CLASS. */

#define SYS_CFG_KEY_HCI_BAUD_RATE_INDEX_LEN              0x01   /**< The default length of @ref SYS_CFG_KEY_HCI_BAUD_RATE_INDEX. */
#define SYS_CFG_KEY_HCI_BAUD_RATE_INDEX_DEFAULT_VALUE    0x03   /**< The default value of @ref SYS_CFG_KEY_HCI_BAUD_RATE_INDEX. */

#define SYS_CFG_KEY_AUTO_POWER_OFF_TIME_LEN              0x01   /**< The default length of @ref SYS_CFG_KEY_AUTO_POWER_OFF_TIME. */
#define SYS_CFG_KEY_AUTO_POWER_OFF_TIME_DEFAULT_VALUE    0x0F   /**< The default value of @ref SYS_CFG_KEY_AUTO_POWER_OFF_TIME. */

#define SYS_CFG_KEY_MUTE_ALARM_TIME_LEN                  0x01   /**< The default length of @ref SYS_CFG_KEY_MUTE_ALARM_TIME. */
#define SYS_CFG_KEY_MUTE_ALARM_TIME_DEFAULT_VALUE        0x05   /**< The default value of @ref SYS_CFG_KEY_MUTE_ALARM_TIME. */

#define SYS_CFG_KEY_MCU_WAKEUP_TIME_LEN                  0x01   /**< The default length of @ref SYS_CFG_KEY_MCU_WAKEUP_TIME. */
#define SYS_CFG_KEY_MCU_WAKEUP_TIME_DEFAULT_VALUE        0x1E   /**< The default value of @ref SYS_CFG_KEY_MCU_WAKEUP_TIME. */

#define SYS_CFG_KEY_VENDOR_DATA_LEN                      0x20   /**< The default length of @ref SYS_CFG_KEY_VENDOR_DATA. */
#define SYS_CFG_KEY_VENDOR_DATA_DEFAULT_VALUE            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,\
                                                         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
                                                                /**< The default value of @ref SYS_CFG_KEY_VENDOR_DATA. */

#define SYS_CFG_KEY_USB_VID_LEN                          0x02   /**< The default length of @ref SYS_CFG_KEY_USB_VID. */
#define SYS_CFG_KEY_USB_VID_DEFAULT_VALUE                0x31, 0x11 /**< The default value of @ref SYS_CFG_KEY_USB_VID. */

#define SYS_CFG_KEY_USB_PID_LEN                          0x02   /**< The default length of @ref SYS_CFG_KEY_USB_PID. */
#define SYS_CFG_KEY_USB_PID_DEFAULT_VALUE                0x10, 0x18 /**< The default value of @ref SYS_CFG_KEY_USB_PID. */

#define SYS_CFG_KEY_VIRTUAL_OFF_COUNTER_LEN              0x01   /**< The default length of @ref SYS_CFG_KEY_VIRTUAL_OFF_COUNTER. */
#define SYS_CFG_KEY_VIRTUAL_OFF_COUNTER_DEFAULT_VALUE    0x1E   /**< The default value of @ref SYS_CFG_KEY_VIRTUAL_OFF_COUNTER. */

#define SYS_CFG_KEY_DEVICE_NAME_BACKUP_LEN               0x0E   /**< The default length of @ref SYS_CFG_KEY_DEVICE_NAME_BACKUP. */
#define SYS_CFG_KEY_DEVICE_NAME_BACKUP_DEFAULT_VALUE     0x42, 0x54, 0x2D, 0x35, 0x35, 0x31, 0x31, 0x2D, 0x42, 0x41, 0x43 ,0x4B, 0x55, 0x50
                                                                /**< The default value of @ref SYS_CFG_KEY_DEVICE_NAME_BACKUP. */

#define SYS_CFG_KEY_OPTION1_LEN                          0x01   /**< The default length of @ref SYS_CFG_KEY_OPTION1. */
#define SYS_CFG_KEY_OPTION1_DEFAULT_VALUE                0xC0   /**< The default value of @ref SYS_CFG_KEY_OPTION1. */

#define SYS_CFG_KEY_OPTION2_LEN                          0x01   /**< The default length of @ref SYS_CFG_KEY_OPTION2. */
#define SYS_CFG_KEY_OPTION2_DEFAULT_VALUE                0x95   /**< The default value of @ref SYS_CFG_KEY_OPTION2. */

#define SYS_CFG_KEY_OPTION3_LEN                          0x01   /**< The default length of @ref SYS_CFG_KEY_OPTION3. */
#define SYS_CFG_KEY_OPTION3_DEFAULT_VALUE                0x00   /**< The default value of @ref SYS_CFG_KEY_OPTION3. */

#define SYS_CFG_KEY_RESERVE2_LEN                         0x01   /**< The default length of @ref SYS_CFG_KEY_RESERVE2. */
#define SYS_CFG_KEY_RESERVE2_DEFAULT_VALUE               0x00   /**< The default value of @ref SYS_CFG_KEY_RESERVE2. */

#define SYS_CFG_KEY_RESERVE3_LEN                         0x01   /**< The default length of @ref SYS_CFG_KEY_RESERVE3. */
#define SYS_CFG_KEY_RESERVE3_DEFAULT_VALUE               0x00   /**< The default value of @ref SYS_CFG_KEY_RESERVE3. */

#define SYS_CFG_KEY_POWER_SAVE_OPTION_LEN                0x01   /**< The default length of @ref SYS_CFG_KEY_POWER_SAVE_OPTION. */
#define SYS_CFG_KEY_POWER_SAVE_OPTION_DEFAULT_VALUE      0x01   /**< The default value of @ref SYS_CFG_KEY_POWER_SAVE_OPTION. */

#define SYS_CFG_KEY_SOFT_RESET_DIRECT_POWERON_LEN		 0x01   /**< The default length of @ref SYS_CFG_KEY_SOFT_RESET_DIRECT_POWERON. */
#define SYS_CFG_KEY_SOFT_RESET_DIRECT_POWERON_DEFAULT_VALUE 0x00    /**< The default value of @ref SYS_CFG_KEY_SOFT_RESET_DIRECT_POWERON. */

#define SYS_CFG_KEY_SNIFF_INTERVAL_LEN                  0x04    /**< The default length of @ref SYS_CFG_KEY_SNIFF_INTERVAL. */
#define SYS_CFG_KEY_SNIFF_INTERVAL_DEFAULT_VALUE        0x03, 0x20, 0x03, 0x20  /**< The default value of @ref SYS_CFG_KEY_SNIFF_INTERVAL. */

#define SYS_CFG_KEY_OPTION4_LEN                         0x01    /**< The default length of @ref SYS_CFG_KEY_OPTION4. */
#define SYS_CFG_KEY_OPTION4_DEFAULT_VALUE               0x0B    /**< The default value of @ref SYS_CFG_KEY_OPTION4. */

#define SYS_CFG_KEY_OTA_DFU_IV_LEN                      0x10    /**< The default length of @ref SYS_CFG_KEY_OTA_DFU_IV. */
#define SYS_CFG_KEY_OTA_DFU_IV_DEFAULT_VALUE            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
                                                                /**< The default value of @ref SYS_CFG_KEY_OTA_DFU_IV. */

#define SYS_CFG_KEY_OTA_DFU_KEY_LEN                     0x10    /**< The default length of @ref SYS_CFG_KEY_OTA_DFU_KEY. */
#define SYS_CFG_KEY_OTA_DFU_KEY_DEFAULT_VALUE           0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22
                                                                /**< The default value of @ref SYS_CFG_KEY_OTA_DFU_KEY. */
#define SYS_CFG_KEY_AT_APP_MODE_LEN                     0x01
#define SYS_CFG_KEY_AT_APP_MODE_DEFAULT_VALUE           0x00                                                              

#define SYS_CFG_KEY_FW_IMAGE_ID_LEN                     0x02         /**< The default length of @ref SYS_CFG_KEY_FW_IMAGE_ID. */
#define SYS_CFG_KEY_FW_IMAGE_ID_DEFAULT_VALUE           0x00, 0x00   /**< The default value of @ref SYS_CFG_KEY_FW_IMAGE_ID. */
/** @} */
/** @} */

/** \cond NON_DOC */

#define CFG_SYS_MODULE_TOTAL_NUM_KEYS    (SYS_CFG_KEY_END - 1)  /**< The number of parameters in @ref CFG_MODULE_ID_SYSTEM. */

#define CFG_SYS_MODULE_TOTAL_SIZE   ((CFG_SYS_MODULE_TOTAL_NUM_KEYS*SIZEOF_CFG_KEY_STRUCT) + \
                                    SYS_CFG_KEY_CLASS_LEN +                         \
                                    SYS_CFG_KEY_HCI_BAUD_RATE_INDEX_LEN +           \
                                    SYS_CFG_KEY_AUTO_POWER_OFF_TIME_LEN +           \
                                    SYS_CFG_KEY_MUTE_ALARM_TIME_LEN +               \
                                    SYS_CFG_KEY_MCU_WAKEUP_TIME_LEN +               \
                                    SYS_CFG_KEY_VENDOR_DATA_LEN +                   \
                                    SYS_CFG_KEY_USB_VID_LEN +                       \
                                    SYS_CFG_KEY_USB_PID_LEN +                       \
                                    SYS_CFG_KEY_VIRTUAL_OFF_COUNTER_LEN +           \
                                    SYS_CFG_KEY_DEVICE_NAME_BACKUP_LEN +            \
                                    SYS_CFG_KEY_OPTION1_LEN +                       \
                                    SYS_CFG_KEY_OPTION2_LEN +                       \
                                    SYS_CFG_KEY_OPTION3_LEN +                       \
                                    SYS_CFG_KEY_RESERVE2_LEN +            \
                                    SYS_CFG_KEY_RESERVE3_LEN +               \
                                    SYS_CFG_KEY_POWER_SAVE_OPTION_LEN +				\
                                    SYS_CFG_KEY_SOFT_RESET_DIRECT_POWERON_LEN +     \
                                    SYS_CFG_KEY_SNIFF_INTERVAL_LEN +                \
                                    SYS_CFG_KEY_OPTION4_LEN +                       \
                                    SYS_CFG_KEY_OTA_DFU_IV_LEN +                    \
                                    SYS_CFG_KEY_AT_APP_MODE_LEN +                   \
                                    SYS_CFG_KEY_OTA_DFU_KEY_LEN +                   \
                                    SYS_CFG_KEY_FW_IMAGE_ID_LEN)   /**< The total length of parameters in @ref CFG_MODULE_ID_SYSTEM. */ 
                                    
//System Config keys definition
#define CFG_SYS_MODULE_DEFAULT_VALUE    CFG_MODULE_ID_SYSTEM,            /*moduleID*/   \
                                        CFG_SYS_MODULE_TOTAL_NUM_KEYS,    /*numKeys*/           \
                                        (CFG_SYS_MODULE_TOTAL_SIZE >> 8),/*moduleSize*/    \    
                                        CFG_SYS_MODULE_TOTAL_SIZE,                      \
                                        /*CFG_KEYs[numKeys]*/                        \
                                        /*    //ID                                //Len                                        //Value    */                         \
                                        SYS_CFG_KEY_CLASS,                  SYS_CFG_KEY_CLASS_LEN,                  SYS_CFG_KEY_CLASS_DEFAULT_VALUE,                 \
                                        SYS_CFG_KEY_HCI_BAUD_RATE_INDEX,    SYS_CFG_KEY_HCI_BAUD_RATE_INDEX_LEN,    SYS_CFG_KEY_HCI_BAUD_RATE_INDEX_DEFAULT_VALUE,   \
                                        SYS_CFG_KEY_AUTO_POWER_OFF_TIME,    SYS_CFG_KEY_AUTO_POWER_OFF_TIME_LEN,    SYS_CFG_KEY_AUTO_POWER_OFF_TIME_DEFAULT_VALUE,   \
                                        SYS_CFG_KEY_MUTE_ALARM_TIME,        SYS_CFG_KEY_MUTE_ALARM_TIME_LEN,        SYS_CFG_KEY_MUTE_ALARM_TIME_DEFAULT_VALUE,       \
                                        SYS_CFG_KEY_MCU_WAKEUP_TIME,        SYS_CFG_KEY_MCU_WAKEUP_TIME_LEN,        SYS_CFG_KEY_MCU_WAKEUP_TIME_DEFAULT_VALUE,       \
                                        SYS_CFG_KEY_VENDOR_DATA,            SYS_CFG_KEY_VENDOR_DATA_LEN,            SYS_CFG_KEY_VENDOR_DATA_DEFAULT_VALUE,           \
                                        SYS_CFG_KEY_USB_VID,                SYS_CFG_KEY_USB_VID_LEN,                SYS_CFG_KEY_USB_VID_DEFAULT_VALUE,               \
                                        SYS_CFG_KEY_USB_PID,                SYS_CFG_KEY_USB_PID_LEN,                SYS_CFG_KEY_USB_PID_DEFAULT_VALUE,               \
                                        SYS_CFG_KEY_VIRTUAL_OFF_COUNTER,    SYS_CFG_KEY_VIRTUAL_OFF_COUNTER_LEN,    SYS_CFG_KEY_VIRTUAL_OFF_COUNTER_DEFAULT_VALUE,   \
                                        SYS_CFG_KEY_DEVICE_NAME_BACKUP,     SYS_CFG_KEY_DEVICE_NAME_BACKUP_LEN,     SYS_CFG_KEY_DEVICE_NAME_BACKUP_DEFAULT_VALUE,    \
                                        SYS_CFG_KEY_OPTION1,                SYS_CFG_KEY_OPTION1_LEN,                SYS_CFG_KEY_OPTION1_DEFAULT_VALUE,               \
                                        SYS_CFG_KEY_OPTION2,                SYS_CFG_KEY_OPTION2_LEN,                SYS_CFG_KEY_OPTION2_DEFAULT_VALUE,               \
                                        SYS_CFG_KEY_OPTION3,                SYS_CFG_KEY_OPTION3_LEN,                SYS_CFG_KEY_OPTION3_DEFAULT_VALUE,               \
                                        SYS_CFG_KEY_RESERVE2,               SYS_CFG_KEY_RESERVE2_LEN,               SYS_CFG_KEY_RESERVE2_DEFAULT_VALUE,    \
                                        SYS_CFG_KEY_RESERVE3,               SYS_CFG_KEY_RESERVE3_LEN,               SYS_CFG_KEY_RESERVE3_DEFAULT_VALUE,       \
                                        SYS_CFG_KEY_POWER_SAVE_OPTION,      SYS_CFG_KEY_POWER_SAVE_OPTION_LEN,      SYS_CFG_KEY_POWER_SAVE_OPTION_DEFAULT_VALUE,	 \
                                        SYS_CFG_KEY_SOFT_RESET_DIRECT_POWERON, SYS_CFG_KEY_SOFT_RESET_DIRECT_POWERON_LEN, SYS_CFG_KEY_SOFT_RESET_DIRECT_POWERON_DEFAULT_VALUE,\  
                                        SYS_CFG_KEY_SNIFF_INTERVAL,         SYS_CFG_KEY_SNIFF_INTERVAL_LEN,         SYS_CFG_KEY_SNIFF_INTERVAL_DEFAULT_VALUE,        \
                                        SYS_CFG_KEY_OPTION4,                SYS_CFG_KEY_OPTION4_LEN,                SYS_CFG_KEY_OPTION4_DEFAULT_VALUE,               \
                                        SYS_CFG_KEY_OTA_DFU_IV,             SYS_CFG_KEY_OTA_DFU_IV_LEN,             SYS_CFG_KEY_OTA_DFU_IV_DEFAULT_VALUE,            \
                                        SYS_CFG_KEY_OTA_DFU_KEY,            SYS_CFG_KEY_OTA_DFU_KEY_LEN,            SYS_CFG_KEY_OTA_DFU_KEY_DEFAULT_VALUE,           \
                                        SYS_CFG_KEY_AT_APP_MODE,            SYS_CFG_KEY_AT_APP_MODE_LEN,            SYS_CFG_KEY_AT_APP_MODE_DEFAULT_VALUE,           \
                                        SYS_CFG_KEY_FW_IMAGE_ID,            SYS_CFG_KEY_FW_IMAGE_ID_LEN,            SYS_CFG_KEY_FW_IMAGE_ID_DEFAULT_VALUE
                                        /**< The default parameters table in @ref CFG_MODULE_ID_SYSTEM. */ 


/**@brief The structure contains the bit options for @ref SYS_CFG_KEY_OPTION1*/
typedef struct _APP_Cfg_SysOption1_T
{
    uint8_t enableStatusReport: 1;           
    uint8_t enableAppHciUart: 1;             
    uint8_t disableWaitForAck: 1;            
    uint8_t directPowerOn: 1;                
    uint8_t enableUartTxPaddingPrefix: 1;    
    uint8_t reserved: 2;                     
    uint8_t enableEmbeddedSpp: 1;            
} APP_Cfg_SysOption1_T;

/**@brief The structure contains the bit options for @ref SYS_CFG_KEY_OPTION2*/
typedef struct _APP_Cfg_SysOption2_T
{
    uint8_t hostEnableSimplePairing: 1;              
    uint8_t reserve: 1; //hangUpCallWhenSwitchOff: 1;  
    uint8_t keepBleInPowerOff: 1;                    
    uint8_t disconnectAllInPairing: 1;               
    uint8_t reserve2: 2;                             
    uint8_t onlyAcceptPairedDevice: 1;               
    uint8_t noStreamAutoOff: 1;                      
} APP_Cfg_SysOption2_T;

/**@brief The structure contains the bit options for @ref SYS_CFG_KEY_OPTION3*/
typedef struct _APP_Cfg_SysOption3_T
{
    uint8_t standbyAutoPowerOff: 1;                  
    uint8_t pairingTimeoutCutOffPower: 1;            
    uint8_t reserve: 1;//enableEsdRecovery: 1;       
    uint8_t enableLineInSilenceDetection: 1;         
    uint8_t reserve2: 2;//enableUartRxdWakeup: 1;    
    //uint8_t enableStandbyMode: 1;                  
    uint8_t uartCommandPowerOnMode: 1;               
    uint8_t reserve3: 1;                             
} APP_Cfg_SysOption3_T;

/**@brief The structure contains the bit options for @ref SYS_CFG_KEY_OPTION4*/
typedef struct _APP_Cfg_SysOption4_T
{
    uint8_t disableAutoUnsniff: 1;                   
    uint8_t enableAvrcpBrowsing: 1;
    uint8_t enableTestMode: 1;
    uint8_t roleSwitch2Master: 1;
    uint8_t enableRoleSwitchLinkPolicy: 1;
    uint8_t forceAsBtSlave: 1;
    uint8_t reserved : 2;                            
} APP_Cfg_SysOption4_T;

/**@brief The structure contains the bit options for @ref SYS_CFG_KEY_POWER_SAVE_OPTION*/
typedef struct _APP_Cfg_PwrSavingOption_T
{
    uint8_t enablePowerDown: 1;                      
    uint8_t reserved : 7;                            
} APP_Cfg_PwrSavingOption_T;


void APP_CFG_ReadSysAutoPowerOffTime(uint16_t XDATA *p_time);
void APP_CFG_ReadSysVendorData(uint8_t XDATA *p_data);
void APP_CFG_WriteSysVendorData(uint8_t length, uint8_t XDATA *p_data);
void APP_CFG_ReadSysVirtualOffCounter(uint8_t XDATA *p_counter);
void APP_CFG_ReadSysOption1(APP_Cfg_SysOption1_T XDATA *p_option);
void APP_CFG_WriteSysOption1(APP_Cfg_SysOption1_T option);
void APP_CFG_ReadSysOption2(APP_Cfg_SysOption2_T XDATA *p_option);
void APP_CFG_ReadSysOption3(APP_Cfg_SysOption3_T XDATA *p_option);
void APP_CFG_WriteSysOption3(APP_Cfg_SysOption3_T option);
void APP_CFG_ReadBtBackupDeviceName(uint8_t XDATA *p_len, uint8_t XDATA *p_backupName);
void APP_CFG_WriteBtBackupDeviceName(uint8_t len, uint8_t XDATA *p_backupName);
void APP_CFG_ReadUartBaudrateSetting(uint8_t XDATA *p_baudrate);
void APP_CFG_WriteUartBaudrateSetting(uint8_t XDATA baudrate);
void APP_CFG_ReadPIDVID(uint8_t XDATA *p_vid, uint8_t XDATA *p_pid);
uint8_t APP_CFG_CheckSoftwareResetDirectPowerOn(void);
void APP_CFG_ResetSoftwareResetDirectPowerOn(void);
void APP_CFG_SetSoftwareResetDirectPowerOn(void);
void APP_CFG_ReadSniffInterval(uint16_t XDATA *p_maxInterval,uint16_t XDATA *p_minInterval);
void APP_CFG_ReadSysOption4(APP_Cfg_SysOption4_T XDATA *p_option);
void APP_CFG_ReadSysCod(uint8_t XDATA *p_cod);
void APP_CFG_ReadMuteAlarmTime(uint16_t XDATA *p_time);
void APP_CFG_ReadMcuWakeupTime(uint16_t XDATA *p_time);
void APP_CFG_ReadPowerSavingOption(APP_Cfg_PwrSavingOption_T XDATA *p_option);
void APP_CFG_ReadOtaDfuIv(uint8_t XDATA *p_iv);
void APP_CFG_ReadOtaDfuKey(uint8_t XDATA *p_key);

void APP_CFG_ReadAtAppMode(uint8_t XDATA *p_atAppMode);
void APP_CFG_WriteATAppMode(uint8_t atAppMode);
/// \endcond
#endif //APP_CFG_SYSTEM_H


