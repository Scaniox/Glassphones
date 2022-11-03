/********************************************************************
  File Information:
    FileName:       app_cfg_bt.h
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

#ifndef APP_CFG_BT_H
#define APP_CFG_BT_H

/** \cond NON_DOC 

\#BUILD_TARGET : MSPKv2_App_Basic
\#TARGET_START
\#REMOVE_PARAM : BT_CFG_KEY_A2DP_DEVICE_INDEX
\#REMOVE_PARAM : BT_CFG_KEY_RSSI_WEAK_THRESHOLD
\#REMOVE_PARAM : BT_CFG_KEY_SPECIFIC_SPP_UUID_0
\#REMOVE_PARAM : BT_CFG_KEY_SPECIFIC_SPP_UUID_1
\#REMOVE_PARAM : BT_CFG_KEY_HF_DEVICE_INDEX
\#REMOVE_BIT : LINK_QUALITY_DETECTION_ENABLE
\#REMOVE_BIT : ENABLE_SINGLE_CUSTOMER_SPP_FLAG
\#REMOVE_BIT : ENABLE_DOUBLE_CUSTOMER_SPP_FLAG
\#REMOVE_BIT : SUPPORT_STANDARD_SPP_ENABLE
\#REMOVE_BIT : ENABLE_128_SPECIFY_UUID
\#REMOVE_BIT : RSP_SDP_SPP
\#REMOVE_BIT : RSP_SDP_IAP
\#REMOVE_BIT : RSP_SDP_PBAP
\#REMOVE_PARAM : BT_CFG_KEY_SPP_DEVICE_INDEX
\#REMOVE_PARAM : BT_CFG_KEY_PAGE_SPP_TIME
\#REMOVE_BIT : ENABLE_GOOGLE_FAST_PAIR
\#REMOVE_BIT : ENABLE_BATTERY_NOTIFICATION
\#REMOVE_PARAM : BT_CFG_KEY_GFPS_MODELID
\#REMOVE_PARAM : BT_CFG_KEY_GFPS_PRIVATE_KEY
\#REMOVE_PARAM : BT_CFG_KEY_GFPS_ACCOUNT_KEY
\#REMOVE_PARAM : BT_CFG_KEY_GFPS_TX_POWER
\#REMOVE_PARAM : BT_CFG_KEY_NUM_DEV_TO_CONN_AFTER_INQUIRY
\#REMOVE_PARAM : BT_CFG_KEY_INQUIRY_TIMEOUT
\#REMOVE_PARAM : BT_CFG_KEY_NUM_INQUIRY_RESULTS
\#REMOVE_BIT : AT_ENABLE_A2DP_STREAM_CONTROL
\#REMOVE_BIT : AT_ENABLE_CONNECT_IMM_AFTER_DISCOVER_DEVICE
\#REMOVE_BIT : AT_ENABLE_DUAL_STREAMING
\#REMOVE_BIT : AT_RSSI_FILTER
\#REMOVE_PARAM : BT_CFG_KEY_AT_SBC_SAMPLING_RATE
\#REMOVE_PARAM : BT_CFG_KEY_AT_SBC_BITPOOL
\#REMOVE_PARAM : BT_CFG_KEY_AT_RSSI_THRESHOLD
\#REMOVE_PARAM : BT_CFG_KEY_APP_FIX_PIN_CODE
\#TARGET_END

\#BUILD_TARGET : MSPKv2_GFP
\#TARGET_START
\#REMOVE_PARAM : BT_CFG_KEY_A2DP_DEVICE_INDEX
\#REMOVE_PARAM : BT_CFG_KEY_RSSI_WEAK_THRESHOLD
\#REMOVE_PARAM : BT_CFG_KEY_SPECIFIC_SPP_UUID_0
\#REMOVE_PARAM : BT_CFG_KEY_SPECIFIC_SPP_UUID_1
\#REMOVE_PARAM : BT_CFG_KEY_HF_DEVICE_INDEX
\#REMOVE_BIT : LINK_QUALITY_DETECTION_ENABLE
\#REMOVE_BIT : ENABLE_SINGLE_CUSTOMER_SPP_FLAG
\#REMOVE_BIT : ENABLE_DOUBLE_CUSTOMER_SPP_FLAG
\#REMOVE_BIT : SUPPORT_STANDARD_SPP_ENABLE
\#REMOVE_BIT : ENABLE_128_SPECIFY_UUID
\#REMOVE_BIT : RSP_SDP_SPP
\#REMOVE_BIT : RSP_SDP_IAP
\#REMOVE_BIT : RSP_SDP_PBAP
\#REMOVE_PARAM : BT_CFG_KEY_SPP_DEVICE_INDEX
\#REMOVE_PARAM : BT_CFG_KEY_PAGE_SPP_TIME
\#REMOVE_PARAM : BT_CFG_KEY_NUM_DEV_TO_CONN_AFTER_INQUIRY
\#REMOVE_PARAM : BT_CFG_KEY_INQUIRY_TIMEOUT
\#REMOVE_PARAM : BT_CFG_KEY_NUM_INQUIRY_RESULTS
\#REMOVE_BIT : AT_ENABLE_A2DP_STREAM_CONTROL
\#REMOVE_BIT : AT_ENABLE_CONNECT_IMM_AFTER_DISCOVER_DEVICE
\#REMOVE_BIT : AT_ENABLE_DUAL_STREAMING
\#REMOVE_BIT : AT_RSSI_FILTER
\#REMOVE_PARAM : BT_CFG_KEY_AT_SBC_SAMPLING_RATE
\#REMOVE_PARAM : BT_CFG_KEY_AT_SBC_BITPOOL
\#REMOVE_PARAM : BT_CFG_KEY_AT_RSSI_THRESHOLD
\#REMOVE_PARAM : BT_CFG_KEY_APP_FIX_PIN_CODE
\#TARGET_END

\#BUILD_TARGET : MSPKv2_SPP
\#TARGET_START
\#REMOVE_PARAM : BT_CFG_KEY_A2DP_DEVICE_INDEX
\#REMOVE_PARAM : BT_CFG_KEY_RSSI_WEAK_THRESHOLD
\#REMOVE_PARAM : BT_CFG_KEY_SPECIFIC_SPP_UUID_0
\#REMOVE_PARAM : BT_CFG_KEY_SPECIFIC_SPP_UUID_1
\#REMOVE_PARAM : BT_CFG_KEY_HF_DEVICE_INDEX
\#REMOVE_BIT : LINK_QUALITY_DETECTION_ENABLE
\#REMOVE_BIT : ENABLE_SINGLE_CUSTOMER_SPP_FLAG
\#REMOVE_BIT : ENABLE_DOUBLE_CUSTOMER_SPP_FLAG
\#REMOVE_BIT : SUPPORT_STANDARD_SPP_ENABLE
\#REMOVE_BIT : ENABLE_128_SPECIFY_UUID
\#REMOVE_BIT : RSP_SDP_PBAP
\#REMOVE_PARAM : BT_CFG_KEY_SPP_DEVICE_INDEX
\#REMOVE_BIT : ENABLE_GOOGLE_FAST_PAIR
\#REMOVE_BIT : ENABLE_BATTERY_NOTIFICATION
\#REMOVE_PARAM : BT_CFG_KEY_GFPS_MODELID
\#REMOVE_PARAM : BT_CFG_KEY_GFPS_PRIVATE_KEY
\#REMOVE_PARAM : BT_CFG_KEY_GFPS_ACCOUNT_KEY
\#REMOVE_PARAM : BT_CFG_KEY_GFPS_TX_POWER
\#REMOVE_PARAM : BT_CFG_KEY_NUM_DEV_TO_CONN_AFTER_INQUIRY
\#REMOVE_PARAM : BT_CFG_KEY_INQUIRY_TIMEOUT
\#REMOVE_PARAM : BT_CFG_KEY_NUM_INQUIRY_RESULTS
\#REMOVE_BIT : AT_ENABLE_A2DP_STREAM_CONTROL
\#REMOVE_BIT : AT_ENABLE_CONNECT_IMM_AFTER_DISCOVER_DEVICE
\#REMOVE_BIT : AT_ENABLE_DUAL_STREAMING
\#REMOVE_BIT : AT_RSSI_FILTER
\#REMOVE_PARAM : BT_CFG_KEY_AT_SBC_SAMPLING_RATE
\#REMOVE_PARAM : BT_CFG_KEY_AT_SBC_BITPOOL
\#REMOVE_PARAM : BT_CFG_KEY_AT_RSSI_THRESHOLD
\#REMOVE_PARAM : BT_CFG_KEY_APP_FIX_PIN_CODE
\#TARGET_END

\#BUILD_TARGET : MSPKv2_PBAP
\#TARGET_START
\#REMOVE_PARAM : BT_CFG_KEY_A2DP_DEVICE_INDEX
\#REMOVE_PARAM : BT_CFG_KEY_RSSI_WEAK_THRESHOLD
\#REMOVE_PARAM : BT_CFG_KEY_SPECIFIC_SPP_UUID_0
\#REMOVE_PARAM : BT_CFG_KEY_SPECIFIC_SPP_UUID_1
\#REMOVE_PARAM : BT_CFG_KEY_HF_DEVICE_INDEX
\#REMOVE_BIT : LINK_QUALITY_DETECTION_ENABLE
\#REMOVE_BIT : ENABLE_SINGLE_CUSTOMER_SPP_FLAG
\#REMOVE_BIT : ENABLE_DOUBLE_CUSTOMER_SPP_FLAG
\#REMOVE_BIT : SUPPORT_STANDARD_SPP_ENABLE
\#REMOVE_BIT : ENABLE_128_SPECIFY_UUID
\#REMOVE_BIT : RSP_SDP_SPP
\#REMOVE_BIT : RSP_SDP_IAP
\#REMOVE_PARAM : BT_CFG_KEY_SPP_DEVICE_INDEX
\#REMOVE_PARAM : BT_CFG_KEY_PAGE_SPP_TIME
\#REMOVE_BIT : ENABLE_GOOGLE_FAST_PAIR
\#REMOVE_BIT : ENABLE_BATTERY_NOTIFICATION
\#REMOVE_PARAM : BT_CFG_KEY_GFPS_MODELID
\#REMOVE_PARAM : BT_CFG_KEY_GFPS_PRIVATE_KEY
\#REMOVE_PARAM : BT_CFG_KEY_GFPS_ACCOUNT_KEY
\#REMOVE_PARAM : BT_CFG_KEY_GFPS_TX_POWER
\#REMOVE_PARAM : BT_CFG_KEY_NUM_DEV_TO_CONN_AFTER_INQUIRY
\#REMOVE_PARAM : BT_CFG_KEY_INQUIRY_TIMEOUT
\#REMOVE_PARAM : BT_CFG_KEY_NUM_INQUIRY_RESULTS
\#REMOVE_BIT : AT_ENABLE_A2DP_STREAM_CONTROL
\#REMOVE_BIT : AT_ENABLE_CONNECT_IMM_AFTER_DISCOVER_DEVICE
\#REMOVE_BIT : AT_ENABLE_DUAL_STREAMING
\#REMOVE_BIT : AT_RSSI_FILTER
\#REMOVE_PARAM : BT_CFG_KEY_AT_SBC_SAMPLING_RATE
\#REMOVE_PARAM : BT_CFG_KEY_AT_SBC_BITPOOL
\#REMOVE_PARAM : BT_CFG_KEY_AT_RSSI_THRESHOLD
\#REMOVE_PARAM : BT_CFG_KEY_APP_FIX_PIN_CODE
\#TARGET_END

\#BUILD_TARGET : AT_App
\#TARGET_START
\#REMOVE_PARAM : BT_CFG_KEY_A2DP_DEVICE_INDEX
\#REMOVE_PARAM : BT_CFG_KEY_RSSI_WEAK_THRESHOLD
\#REMOVE_PARAM : BT_CFG_KEY_SPECIFIC_SPP_UUID_0
\#REMOVE_PARAM : BT_CFG_KEY_SPECIFIC_SPP_UUID_1
\#REMOVE_PARAM : BT_CFG_KEY_HF_DEVICE_INDEX
\#REMOVE_BIT : LINK_QUALITY_DETECTION_ENABLE
\#REMOVE_BIT : ENABLE_SINGLE_CUSTOMER_SPP_FLAG
\#REMOVE_BIT : ENABLE_DOUBLE_CUSTOMER_SPP_FLAG
\#REMOVE_BIT : SUPPORT_STANDARD_SPP_ENABLE
\#REMOVE_BIT : ENABLE_128_SPECIFY_UUID
\#REMOVE_BIT : RSP_SDP_SPP
\#REMOVE_BIT : RSP_SDP_IAP
\#REMOVE_BIT : RSP_SDP_PBAP
\#REMOVE_PARAM : BT_CFG_KEY_SPP_DEVICE_INDEX
\#REMOVE_PARAM : BT_CFG_KEY_PAGE_SPP_TIME
\#REMOVE_BIT : ENABLE_GOOGLE_FAST_PAIR
\#REMOVE_BIT : ENABLE_BATTERY_NOTIFICATION
\#REMOVE_PARAM : BT_CFG_KEY_GFPS_MODELID
\#REMOVE_PARAM : BT_CFG_KEY_GFPS_PRIVATE_KEY
\#REMOVE_PARAM : BT_CFG_KEY_GFPS_ACCOUNT_KEY
\#REMOVE_PARAM : BT_CFG_KEY_GFPS_TX_POWER
\#REMOVE_PARAM : BT_CFG_KEY_APP_FIX_PIN_CODE
\#TARGET_END

\endcond
*/


/**
  @addtogroup APP_CFG_MODULE_BT BT Configuration
  @{
  @brief Definitions and prototypes for the MODULE_BT Configuration.
 */

//Config Key definiton of MODULE_BT(0x02)
/**
 * @brief Configuration key definition of the module @ref CFG_MODULE_ID_BT.
 *  */
typedef enum _BT_CFG_Key_IdDefinition_T
{
    BT_CFG_KEY_APP_FIX_PIN_CODE             = 0x01, /**<\#PARAM_NAME : BT_CFG_KEY_APP_FIX_PIN_CODE \n
                                                        \#ALIAS : Pin Code \n
                                                        \#PARAM_TYPE : Public \n
                                                        \#PARAM_DESC : The App_Fix_PIN_Code  which is four byte ASCII code is a fixed PIN code of a local device. \n 
                                                                       The local device replies the PIN code using the App_Fix_PIN_Code when remote devices send a PIN code request command.\n
                                                        \#DESC_END
                                                        \#GROUP_ID : 0x02 \n
                                                        \#KEY_ID : 0x01 \n
                                            	    */
                                                	          
    BT_CFG_KEY_NO_SERVICE_WARNING_TIME      = 0x02, /**<\#PARAM_NAME : BT_CFG_KEY_NO_SERVICE_WARNING_TIME \n
                                                        \#ALIAS : No Service Warning Time \n
                                                        \#PARAM_TYPE : Public \n
                                                        \#PARAM_DESC : When mobile phone can not receive the signal from base station, headset alert user periodically with this interval(unit in 640 ms).\n
                                                                       This function is through HFP. \n
                                                        \#DESC_END
                                                        \#GROUP_ID : 0x02 \n
                                                        \#KEY_ID : 0x02 \n
                                            	    */
                                                	          
    BT_CFG_KEY_LINK_LOSS_RECONNECT_TIME     = 0x03, /**<\#PARAM_NAME : BT_CFG_KEY_LINK_LOSS_RECONNECT_TIME \n
                                                        \#ALIAS : Link Loss Reconnect Time \n
                                                        \#PARAM_TYPE : Public \n
                                                        \#PARAM_DESC : The timeout to reconnecting to link loss device. \n
                                                                       0x00 : don't reconnect \n
                                                                       0xFF : recover without timeout \n
                                                                       other : (unit in 5 second) \n
                                                        \#DESC_END
                                                        \#GROUP_ID : 0x02 \n
                                                        \#KEY_ID : 0x03 \n
                                            	    */
                                                	          
    BT_CFG_KEY_PAGE_HS_TIME                 = 0x04, /**<\#PARAM_NAME : BT_CFG_KEY_PAGE_HS_TIME \n
                                                        \#ALIAS : Page HS Time \n
                                                        \#PARAM_TYPE : Public \n
                                                        \#PARAM_DESC : The timeout value for reconnecting HF/HS device (unit in 5 second), 0 means no timeout. \n
                                                        \#DESC_END
                                                        \#GROUP_ID : 0x02 \n
                                                        \#KEY_ID : 0x04 \n
                                            	    */
                                                	          
    BT_CFG_KEY_PAIRING_TIMEOUT              = 0x05, /**<\#PARAM_NAME : BT_CFG_KEY_PAIRING_TIMEOUT \n
                                                        \#ALIAS : Pairing Timeout \n
                                                        \#PARAM_TYPE : Public \n
                                                        \#PARAM_DESC : The timeout value for pairing mode(unit in 30 second), 0 means no timeout. \n
                                                        \#DESC_END
                                                        \#GROUP_ID : 0x02 \n
                                                        \#KEY_ID : 0x05 \n
                                            	    */
                                                	          
    BT_CFG_KEY_A2DP_DEVICE_INDEX            = 0x06, /**<\#PARAM_NAME : BT_CFG_KEY_A2DP_DEVICE_INDEX \n
                                                        \#ALIAS : A2DP Device Index \n
                                                        \#PARAM_TYPE : Private \n
                                                        \#PARAM_DESC : used to record A2DP device, lower 4 bits record primary device and higher 4 bits record secondary device [Run Time Updated]. \n
                                                        \#DESC_END
                                                        \#GROUP_ID : 0x02 \n
                                                        \#KEY_ID : 0x06 \n
                                            	    */
                                                	          
    BT_CFG_KEY_PAGE_A2DP_TIME               = 0x07, /**<\#PARAM_NAME : BT_CFG_KEY_PAGE_A2DP_TIME \n
                                                        \#ALIAS : Page A2DP Time \n
                                                        \#PARAM_TYPE : Public \n
                                                        \#PARAM_DESC : page A2DP device time out value(unit in 5 second), o means no timeout. \n
                                                        \#DESC_END
                                                        \#GROUP_ID : 0x02 \n
                                                        \#KEY_ID : 0x07 \n
                                            	    */
                                                	          
    BT_CFG_KEY_RSSI_WEAK_THRESHOLD          = 0x08, /**<\#PARAM_NAME : BT_CFG_KEY_RSSI_WEAK_THRESHOLD \n
                                                        \#ALIAS : RSSI Weak Threshold \n
                                                        \#PARAM_TYPE : Public \n
                                                        \#PARAM_DESC : (not implement)SHS will alarm user when average RSSI is less than this value. \n
                                                        \#DESC_END
                                                        \#GROUP_ID : 0x02 \n
                                                        \#KEY_ID : 0x08 \n
                                            	    */
                                                	          
    BT_CFG_KEY_SPECIFIC_SPP_UUID_0          = 0x09, /**<\#PARAM_NAME : BT_CFG_KEY_SPECIFIC_SPP_UUID_0 \n
                                                        \#ALIAS : Specific SPP UUID 0 \n
                                                        \#PARAM_TYPE : Public \n
                                                        \#PARAM_DESC : (not implement)custom SPP UUID 1. \n
                                                        \#DESC_END
                                                        \#GROUP_ID : 0x02 \n
                                                        \#KEY_ID : 0x09 \n
                                            	    */
                                                	          
    BT_CFG_KEY_SPECIFIC_SPP_UUID_1          = 0x0A, /**<\#PARAM_NAME : BT_CFG_KEY_SPECIFIC_SPP_UUID_1 \n
                                                        \#ALIAS : Specific SPP UUID 1 \n
                                                        \#PARAM_TYPE : Public \n
                                                        \#PARAM_DESC : (not implement)custom SPP UUID 2. \n
                                                        \#DESC_END
                                                        \#GROUP_ID : 0x02 \n
                                                        \#KEY_ID : 0x0A \n
                                            	    */
                                                	          
    BT_CFG_KEY_DEVICE_NAME                  = 0x0B, /**<\#PARAM_NAME : BT_CFG_KEY_DEVICE_NAME \n
                                                        \#ALIAS : Device Name \n
                                                        \#PARAM_TYPE : Public \n
                                                        \#PARAM_DESC : device name. \n
                                                        \#DESC_END
                                                        \#GROUP_ID : 0x02 \n
                                                        \#KEY_ID : 0x0B \n
                                            	    */
                                                	          
    BT_CFG_KEY_PAIRED_DEVICES               = 0x0C, /**<\#PARAM_NAME : BT_CFG_KEY_PAIRED_DEVICES \n
                                                        \#ALIAS : Paired Devices \n
                                                        \#PARAM_TYPE : Public \n
                                                        \#PARAM_DESC : There are 8 bytes in each record and 8 records total,\n 
                                                                       The first 6 bytes are BD Address, 7th byte is priority, and 8th byte is BeBondle [Run Time Updated] \n
                                                        \#DESC_END
                                                        \#GROUP_ID : 0x02 \n
                                                        \#KEY_ID : 0x0C \n
                                            	    */
                                                	          
    BT_CFG_KEY_HF_DEVICE_INDEX              = 0x0D, /**<\#PARAM_NAME : BT_CFG_KEY_HF_DEVICE_INDEX \n
                                                        \#ALIAS : HF Device Index \n
                                                        \#PARAM_TYPE : Private \n
                                                        \#PARAM_DESC : use lower 4 bits only : used to record HF primary device index [Run Time Updated]. \n
                                                        \#DESC_END
                                                        \#GROUP_ID : 0x02 \n
                                                        \#KEY_ID : 0x0D \n
                                            	    */
                                                	          
    BT_CFG_KEY_LINK_QUALITY_DETECT_OPTION   = 0x0E, /**<\#PARAM_NAME : BT_CFG_KEY_LINK_QUALITY_DETECT_OPTION \n
                                                        \#PARAM_TYPE : Public \n
                                                        \#GROUP_ID : 0x02 \n
                                                        \#KEY_ID : 0x0E \n
                                                        Bit Options:
                                                	    \par
                                                	    \#BIT_PARAM : LINK_QUALITY_DETECTION_ENABLE \n
                                                	    \#BIT_ALIAS : Link Quality Detection \n
                                                	    \#BIT_POS : 4 \n
                                                	    \#BIT_SIZE : 1 \n
                                                	    \#BIT_DESC : (not implement)Enable/disable link quality detection. \n
                                                                     If the rssi is less than the value of rssi_weak_threshold parameter, ring the warning tone (about 5 seconds once) \n
                                                	    \#DESC_END
                                            	    */
                                                	          
    BT_CFG_KEY_SPP_OPTION                   = 0x0F, /**<\#PARAM_NAME : BT_CFG_KEY_SPP_OPTION \n
                                                        \#PARAM_TYPE : Public \n
                                                        \#GROUP_ID : 0x02 \n
                                                        \#KEY_ID : 0x0F \n
                                                         Bit Options:
                                                	    \par
                                                	    \#BIT_PARAM : ENABLE_SINGLE_CUSTOMER_SPP_FLAG \n
                                                	    \#BIT_ALIAS : Enable Single Customer Spp Flag \n
                                                	    \#BIT_POS : 0 \n
                                                	    \#BIT_SIZE : 1 \n
                                                	    \#BIT_DESC : (not implement)Enable custom SPP UUID 1 for SPP profile. \n
                                                	    \#DESC_END

                                                	    \par
                                                	    \#BIT_PARAM : ENABLE_DOUBLE_CUSTOMER_SPP_FLAG \n
                                                	    \#BIT_ALIAS : Enable Double Customer SPP Flag \n
                                                	    \#BIT_POS : 1 \n
                                                	    \#BIT_SIZE : 1 \n
                                                	    \#BIT_DESC : (not implement)Enable custom SPP UUID 2 for SPP profile. \n
                                                	    \#DESC_END

                                                	    \par
                                                	    \#BIT_PARAM : SUPPORT_STANDARD_SPP_ENABLE \n
                                                	    \#BIT_ALIAS : Support Standard SPP \n
                                                	    \#BIT_POS : 2 \n
                                                	    \#BIT_SIZE : 1 \n
                                                	    \#BIT_DESC : (not implement)Use standard SPP 16-bit UUID 0x1101 as SDP query parameters when the speaker reconnect to SPP link. \n
                                                	                 1: enabled, 0: disabled \n
                                                	    \#DESC_END

                                                	    \par
                                                	    \#BIT_PARAM : ENABLE_128_SPECIFY_UUID \n
                                                	    \#BIT_ALIAS : Enable 128 Specify UUID \n
                                                	    \#BIT_POS : 3 \n
                                                	    \#BIT_SIZE : 1 \n
                                                	    \#BIT_DESC : (not implement)If the option SUPPORT_STANDARD_SPP_ENABLE is disaable, check this option to use 128 bit or 16 bit custom UUID for SPP. \n
                                                                      0: 16 bit UUID \n
                                                                      1: 128 bit UUID \n
                                                	    \#DESC_END

                                                	    \par
                                                	    \#BIT_PARAM : Reserved \n
                                                	    \#BIT_ALIAS : reserved \n
                                                	    \#BIT_POS : 4 \n
                                                	    \#BIT_SIZE : 4 \n
                                                	    \#BIT_DESC : reserved \n
                                                	    \#DESC_END
                                            	    */
                                                	          
    BT_CFG_KEY_LINK_OPTION                  = 0x10, /**<\#PARAM_NAME : BT_CFG_KEY_LINK_OPTION \n
                                                        \#PARAM_TYPE : Public \n
                                                        \#GROUP_ID : 0x02 \n
                                                        \#KEY_ID : 0x10 \n
                                                        Bit Options:
                                                        \par
                                                        \#BIT_PARAM : LINK_SCENARIO \n
                                                        \#BIT_ALIAS : Power On Link Back Profile(s) Setting \n
                                                        \#BIT_POS : 0 \n
                                                        \#BIT_SIZE : 4 \n
                                                        \#BIT_DESC : 
                                                                     This is used for power on reconnection. \n
                                                                     0 : LINK_SCENARIO_LAST_DEVICE, only reconnect to last device no matter SUPPORT_MULTILINK_MULTIPROFILE and ENABLE_LINK_BACK_BY_PRIORITY are enabled or not. \n
                                                                     1 : LINK_SCENARIO_HF_BASE, reconnect to the highest priority device with HFP profile. \n
                                                                         The priority is ordered by HFP link, the speaker updates the priority as the highest when HFP link is created. \n
                                                                         If the option ENABLE_LINK_BACK_BY_PRIORITY is enabled, it will try next priority device once the speaker fails to the highest device. \n
                                                                         If the option SUPPORT_MULTILINK_MULTIPROFILE is enabled, it will try to connect second device. \n
                                                                     2 : LINK_SCENARIO_A2DP_BASE,  reconnect to the highest priority device with A2DP profile. \n
                                                                         The priority is ordered by A2DP link, the speaker updates the priority as the highest when A2DP link is created. \n
                                                                         If the option ENABLE_LINK_BACK_BY_PRIORITY is enabled, it will try next priority device once the speaker fails to the highest device. \n
                                                                         If the option SUPPORT_MULTILINK_MULTIPROFILE is enabled, it will try to connect second device. \n
                                                        \#DESC_END

                                                        \par
                                                        \#BIT_PARAM : reserved for SPP_SCENARIO: \n
                                                        \#BIT_ALIAS : reserved for SPP SCENARIO \n
                                                        \#BIT_POS : 4 \n
                                                        \#BIT_SIZE : 4 \n
                                                        \#BIT_DESC : reserved \n
                                                        \#DESC_END

                                            	    */
                                                	          
    BT_CFG_KEY_HF_SUPPORT_FEATURE           = 0x11, /**<\#PARAM_NAME : BT_CFG_KEY_HF_SUPPORT_FEATURE \n
                                                        \#ALIAS : Wide Band Speech Enable(mSBC) \n
                                                        \#PARAM_TYPE : Public \n
                                                        \#PARAM_DESC : 
                                                                        The feature that BTM supported for HF profile, it is BRSF bit definition. Please refer to HFP spec. for the detail. \n
                                                                        Bit0:EC_AND_OR_NR_FUNCTION \n
                                                                        Bit1:CALL_WAITING_AND_THREE_WAY_CALLING \n
                                                                        Bit2:CLI_PRESENTATION_CAPABILITY \n
                                                                        Bit3:VOICE_RECOGNITION_ACTIVATION \n
                                                                        Bit4:REMOTE_VOLUME_CONTROL \n
                                                                        Bit5: ENHANCE_CALL_STATUS \n
                                                                        Bit6: ENHANCE_CALL_CONTROL \n
                                                                        Bit7: CODEC_NEGOTIATION \n
                                                                        Bit8: HF_INDICATORS \n
                                                                        Bit9: ESCO_S4_SETTINGS \n
                                                        \#DESC_END
                                                        \#GROUP_ID : 0x02 \n
                                                        \#KEY_ID : 0x11 \n
                                            	    */
                                                	          
    BT_CFG_KEY_OPTION1                      = 0x12, /**<\#PARAM_NAME : BT_CFG_KEY_OPTION1 \n
                                                        \#PARAM_TYPE : Public \n
                                                        \#GROUP_ID : 0x02 \n
                                                        \#KEY_ID : 0x12 \n
                                                        Bit Options:
                                                	    \par
                                                	    \#BIT_PARAM : ENABLE_POWER_ON_LINK_BACK \n
                                                	    \#BIT_ALIAS : Power On Link Back Setting \n
                                                	    \#BIT_POS : 0 \n
                                                	    \#BIT_SIZE : 1 \n
                                                	    \#BIT_DESC : Enable link back feature when power on. \n
                                                                     1:enabled, 0:disabled. \n
                                                	    \#DESC_END

                                                	    \par
                                                	    \#BIT_PARAM : LINK_BACK_FAIL_ENTER_PAIRING \n
                                                	    \#BIT_ALIAS : Enter Pairing When Power On Link Back Fail \n
                                                	    \#BIT_POS : 1 \n
                                                	    \#BIT_SIZE : 1 \n
                                                	    \#BIT_DESC : Enable this option (set to 1) to enter pairing automatically if it fails to reconnect to phone when power on. \n
                                                	    \#DESC_END

                                                	    \par
                                                	    \#BIT_PARAM : ENABLE_LINK_BACK_BY_PRIORITY \n
                                                	    \#BIT_ALIAS : Seach Paired Device Pattern Setting \n
                                                	    \#BIT_POS : 2 \n
                                                	    \#BIT_SIZE : 1 \n
                                                	    \#BIT_DESC : 0 : link back last device only \n
                                                                     1 : power on link back based on link priority and with loop \n
                                                	    \#DESC_END

                                                	    \par
                                                	    \#BIT_PARAM : ASK_PHONE_DISABLE_NREC_ENABLE \n
                                                	    \#BIT_ALIAS : Ask Phone Disable NREC Enable \n
                                                	    \#BIT_POS : 3 \n
                                                	    \#BIT_SIZE : 1 \n
                                                	    \#BIT_DESC : If this option is enabled,  it sends AT command to ask phone disable its NR & AEC functio+F51n. \n
                                                                     There is a pre-condition: both of the speaker and phone must support NR (Noise Reduction) or EC (Echo Cancellation). \n
                                                                     1: send AT command to disable phone's NR, EC function \n
                                                                     0: don't send AT command to disable phone's NR, EC function \n
                                                	    \#DESC_END

                                                	    \par
                                                	    \#BIT_PARAM : ALWAYS_AUTO_ANSWER_INCOMING_CALL_ENABLE \n
                                                	    \#BIT_ALIAS : Always Answer Incoming Call \n
                                                	    \#BIT_POS : 4 \n
                                                	    \#BIT_SIZE : 1 \n
                                                	    \#BIT_DESC : If this option is enabled (set to 1) and HFP connection exists, it will always answer incoming calls automatically. \n
                                                	    \#DESC_END

                                                	    \par
                                                	    \#BIT_PARAM : AUTO_ANSWER_INCOMING_CALL_AS_CONNECTED_ENABLE \n
                                                	    \#BIT_ALIAS : Auto Answer Incoming Call When Link Back \n
                                                	    \#BIT_POS : 5 \n
                                                	    \#BIT_SIZE : 1 \n
                                                	    \#BIT_DESC : when the speaker links back HF link and call status is incoming call, then it will answer the call automatically if this option is enabled (set to 1). \n
                                                	    \#DESC_END

                                                	    \par
                                                	    \#BIT_PARAM : ENABLE_POWER_ON_ENTER_PAIRING \n
                                                	    \#BIT_ALIAS : Enable Power On Enter Pairing \n
                                                	    \#BIT_POS : 6 \n
                                                	    \#BIT_SIZE : 1 \n
                                                	    \#BIT_DESC : If this options is enabled and the speaker meets below two conditions, it will enter pairing mode when power on. \n
                                                                     Condition1: The speaker doesn't try to create CSB link when power on \n
                                                                     Condition2: The speaker doesn't need to reconnect to remove device (no paired record or ENABLE_POWER_ON_LINK_BACK is not enabled) when power on \n
                                                	    \#DESC_END

                                                	    \par
                                                	    \#BIT_PARAM : ENABLE_INQUIRY_SCAN_IN_STANDBY \n
                                                	    \#BIT_ALIAS : Enable Inquiry Scan In Standby \n
                                                	    \#BIT_POS : 7 \n
                                                	    \#BIT_SIZE : 1 \n
                                                	    \#BIT_DESC : Open Inquiry scan window in when the speaker is in standby mode. That is, \n
                                                                     if this option is enabled the speaker is discoverable in not only pairing mode but also standby mode.\n
                                                                     1: enabled, 0:disabled \n
                                                	    \#DESC_END
                                            	    */
                                                	          
    BT_CFG_KEY_OPTION2                      = 0x13, /**<\#PARAM_NAME : BT_CFG_KEY_OPTION2 \n
                                                        \#PARAM_TYPE : Public \n
                                                        \#GROUP_ID : 0x02 \n
                                                        \#KEY_ID : 0x13 \n
                                                         Bit Options:
                                                	    
                                                	    \par
                                                	    \#BIT_PARAM : SUPPORT_MULTILINK_MULTIPROFILE \n
                                                	    \#BIT_ALIAS : Link Application \n
                                                	    \#BIT_POS : 1 \n
                                                	    \#BIT_SIZE : 1 \n
                                                	    \#BIT_DESC : 0 : support 1HF+1A2DP links \n
                                                                     1 : support 1HF+3A2DP links \n
                                                	    \#DESC_END

                                                	    \par
                                                	    \#BIT_PARAM : BATTERY_REPORT_VIA_AT_CMD_ENABLE \n
                                                	    \#BIT_ALIAS : Report Battery Status to Smart Phone \n
                                                	    \#BIT_POS : 5 \n
                                                	    \#BIT_SIZE : 1 \n
                                                	    \#BIT_DESC : Report speaker/hs battery status via AT command base on HFP to mobile phone \n
                                                	    \#DESC_END

                                                	    \par
                                                	    \#BIT_PARAM : AVRCP_VERSION \n
                                                	    \#BIT_ALIAS : AVRCP Version \n
                                                	    \#BIT_POS : 6 \n
                                                	    \#BIT_SIZE : 1 \n
                                                	    \#BIT_DESC : AVRCP version selection. \n
                                                                     0: AVRCP 1.3 \n
                                                                     1: AVRCP 1.6 \n
                                                	    \#DESC_END

                                            	    */
                                                	          
    BT_CFG_KEY_PROFILES_OPTION              = 0x14, /**<\#PARAM_NAME : BT_CFG_KEY_PROFILES_OPTION \n
                                                        \#PARAM_TYPE : Public \n
                                                        \#GROUP_ID : 0x02 \n
                                                        \#KEY_ID : 0x14 \n
                                                        Bit Options:
                                                	    \par
                                                	    \#BIT_PARAM : RSP_SDP_HS \n
                                                	    \#BIT_ALIAS : HS \n
                                                	    \#BIT_POS : 0 \n
                                                	    \#BIT_SIZE : 1 \n
                                                	    \#BIT_DESC : Response HS profile in SDP query. The speaker supports Handset profile if this bit is enabled (set to 1). \n
                                                	    \#DESC_END

                                                	    \par
                                                	    \#BIT_PARAM : RSP_SDP_HF \n
                                                	    \#BIT_ALIAS : HF \n
                                                	    \#BIT_POS : 1 \n
                                                	    \#BIT_SIZE : 1 \n
                                                	    \#BIT_DESC : Response HF profile in SDP query. The speaker supports Hands-Free profile if this bit is enabled (set to 1). \n
                                                	    \#DESC_END

                                                	    \par
                                                	    \#BIT_PARAM : RSP_SDP_A2DP \n
                                                	    \#BIT_ALIAS : A2DP \n
                                                	    \#BIT_POS : 2 \n
                                                	    \#BIT_SIZE : 1 \n
                                                	    \#BIT_DESC : Response A2DP profile in SDP query. The speaker supports A2DP profile if this bit is enabled (set to 1). \n
                                                	    \#DESC_END

                                                	    \par
                                                	    \#BIT_PARAM : RSP_SDP_AVRCP_CT \n
                                                	    \#BIT_ALIAS : CT \n
                                                	    \#BIT_POS : 3 \n
                                                	    \#BIT_SIZE : 1 \n
                                                	    \#BIT_DESC : Response AVRCP CT profile query. The speaker supports the controller role of AVRCP profile if this bit is enabled (set to 1). \n
                                                	    \#DESC_END

                                                	    \par
                                                	    \#BIT_PARAM : RSP_SDP_AVRCP_TG \n
                                                	    \#BIT_ALIAS : TG \n
                                                	    \#BIT_POS : 4 \n
                                                	    \#BIT_SIZE : 1 \n
                                                	    \#BIT_DESC : Response AVRCP TG profile query. The speaker supports the target role of AVRCP if this bit is enabled (set to 1). \n
                                                	    \#DESC_END

                                                	    \par
                                                	    \#BIT_PARAM : RSP_SDP_SPP \n
                                                	    \#BIT_ALIAS : SPP \n
                                                	    \#BIT_POS : 5 \n
                                                	    \#BIT_SIZE : 1 \n
                                                	    \#BIT_DESC : Response SPP profile in SDP query. The speaker supports SPP profile if this bit is enabled (set to 1). \n
                                                	    \#DESC_END

                                                	    \par
                                                	    \#BIT_PARAM : RSP_SDP_IAP \n
                                                	    \#BIT_ALIAS : iAP \n
                                                	    \#BIT_POS : 6 \n
                                                	    \#BIT_SIZE : 1 \n
                                                	    \#BIT_DESC : Response iAP in SDP query, The speaker support Apple iAP protocol if this bit is enabled (set to 1). \n
                                                	    \#DESC_END

                                                	    \par
                                                	    \#BIT_PARAM : RSP_SDP_PBAP \n
                                                	    \#BIT_ALIAS : PBAP \n
                                                	    \#BIT_POS : 7 \n
                                                	    \#BIT_SIZE : 1 \n
                                                	    \#BIT_DESC : Response PBAP profile, The speaker support PBAP profile if this bit is enabled (set to 1). \n
                                                	    \#DESC_END
                                            	    */
                                                	          
    BT_CFG_KEY_SPP_DEVICE_INDEX             = 0x15, /**<\#PARAM_NAME : BT_CFG_KEY_SPP_DEVICE_INDEX \n
                                                        \#ALIAS : SPP Device Index \n
                                                        \#PARAM_TYPE : Public \n
                                                        \#PARAM_DESC : used to record SPP device, lower 4 bits record primary device and higher 4 bits record secondary device[Run Time Updated] \n
                                                        \#DESC_END
                                                        \#GROUP_ID : 0x02 \n
                                                        \#KEY_ID : 0x15 \n
                                            	    */
                                                	          
    BT_CFG_KEY_PAGE_SPP_TIME                = 0x16, /**<\#PARAM_NAME : BT_CFG_KEY_PAGE_SPP_TIME \n
                                                        \#ALIAS : Page SPP Time \n
                                                        \#PARAM_TYPE : Public \n
                                                        \#PARAM_DESC : page SPP device time out value(unit in 5 second), 0 means no timeout. So far the SPP reconnection can be only triggered by host MCU. \n
                                                        \#DESC_END
                                                        \#GROUP_ID : 0x02 \n
                                                        \#KEY_ID : 0x16 \n
                                            	    */
                                                	          
    BT_CFG_KEY_MAX_RF_TX_POWER_LEVEL        = 0x17, /**<\#PARAM_NAME : BT_CFG_KEY_MAX_RF_TX_POWER_LEVEL \n
                                                        \#PARAM_TYPE : Public \n
                                                        \#PARAM_DESC : Bit0~Bit3: The inquiry TX power level. Level 0 ~ 6 (max) \n
                                                                       Bit4~Bit7: The BT connected TX power level. Level 0 ~ 6 (max) \n
                                                                       The max reference power is 10 dBm and decrease 5 dBm for each following level. \n
                                                                       The actual power is upon calibration in MP process. \n
                                                        \#DESC_END
                                                        \#GROUP_ID : 0x02 \n
                                                        \#KEY_ID : 0x17 \n
                                                        \par
                                                    	\#BIT_PARAM : BT_INQUIRY_RF_TX_POWER_LEVEL \n
                                                    	\#BIT_ALIAS : Inquiry TX Power Level.\n
                                                    	\#BIT_POS : 0 \n
                                                    	\#BIT_SIZE : 4 \n
                                                    	\#BIT_DESC : The inquiry TX power level. Level 0 ~ 6 (max) \n
                                                                     The max reference power is 10 dBm and decrease 5 dBm for each following level. \n
                                                                     The actual power is upon calibration in MP process. \n
                                                    	\#DESC_END  \n
                                                        \par
                                                    	\#BIT_PARAM : BT_CONNECTED_RF_TX_POWER_LEVEL \n
                                                    	\#BIT_ALIAS : BT Connected TX Power Level.\n
                                                    	\#BIT_POS : 4 \n
                                                    	\#BIT_SIZE : 4 \n
                                                    	\#BIT_DESC : The BT connected TX power level. Level 0 ~ 6 (max) \n
                                                                     The max reference power is 10 dBm and decrease 5 dBm for each following level. \n
                                                                     The actual power is upon calibration in MP process. \n
                                                    	\#DESC_END  \n 

                                            	    */
    BT_CFG_KEY_GFPS_OPTION                  = 0x18,    /**<\#PARAM_NAME : BT_CFG_KEY_GFPS_OPTION \n
                                                            \#PARAM_TYPE : Public \n
                                                            \#GROUP_ID : 0x02 \n
                                                            \#KEY_ID : 0x18 \n
                                                             Bit Options:
                                                    	    \par
                                                    	    \#BIT_PARAM : ENABLE_GOOGLE_FAST_PAIR \n
                                                    	    \#BIT_ALIAS : Google Fast Pair \n
                                                    	    \#BIT_POS : 0 \n
                                                    	    \#BIT_SIZE : 1 \n
                                                    	    \#BIT_DESC : Enable or disable Google Fast Pair. \n
                                                    	    \#DESC_END

                                                    	    \par
                                                    	    \#BIT_PARAM : ENABLE_BATTERY_NOTIFICATION \n
                                                    	    \#BIT_ALIAS : Battery Notification \n
                                                    	    \#BIT_POS : 1 \n
                                                    	    \#BIT_SIZE : 1 \n
                                                    	    \#BIT_DESC : Enable or disable Battery Notification for Non-discoverable advertising. \n
                                                    	    \#DESC_END

                                                    	    \par
                                                    	    \#BIT_PARAM : Reserved \n
                                                    	    \#BIT_ALIAS : reserved \n
                                                    	    \#BIT_POS : 2 \n
                                                    	    \#BIT_SIZE : 6 \n
                                                    	    \#BIT_DESC : Reserved. \n
                                                    	    \#DESC_END
                                                       */
    BT_CFG_KEY_GFPS_MODELID                 = 0x19,    /**<  \#PARAM_NAME : BT_CFG_KEY_GFPS_MODELID \n
                                                             \#ALIAS : Google Fast Pair Model ID \n
                                                             \#PARAM_TYPE : Public \n
                                                             \#PARAM_DESC : Each provider device has a 24-bit model ID, \n
                                                                            which is provided by Google during model registration. \n
                                                             \#DESC_END  \n
                                                             \#GROUP_ID : 0x02 \n
                                                             \#KEY_ID : 0x19 \n
                                                             \#VALID_MAX : 0xFFFFFF \n
                                                             \#VALID_MIN : 0x000000 \n
                                                       */
    BT_CFG_KEY_GFPS_PRIVATE_KEY             = 0x1A,    /**<  \#PARAM_NAME : BT_CFG_KEY_GFPS_PRIVATE_KEY \n
                                                             \#ALIAS : Google Fast Pair Private Key \n
                                                             \#PARAM_TYPE : Public \n
                                                             \#PARAM_DESC : A 256-bit Anti-Spoofing Private Key distributed from Google \n
                                                                            after model registration. \n
                                                             \#DESC_END  \n
                                                             \#GROUP_ID : 0x02 \n
                                                             \#KEY_ID : 0x1A \n
                                                       */
    BT_CFG_KEY_GFPS_ACCOUNT_KEY             = 0x1B,   /**<  \#PARAM_NAME : BT_CFG_KEY_GFPS_ACCOUNT_KEY \n
                                                             \#ALIAS : Google Fast Pair Account Key List \n
                                                             \#PARAM_TYPE : Private \n
                                                             \#PARAM_DESC : Five 128-bit Account Key list (80 bytes). Each Account Key allows the Provider \n
                                                                            to be recognized as belonging to a certain user account. \n
                                                             \#DESC_END  \n
                                                             \#GROUP_ID : 0x02 \n
                                                             \#KEY_ID : 0x1B \n
                                                       */
    BT_CFG_KEY_GFPS_TX_POWER                = 0x1C,    /**<  \#PARAM_NAME : BT_CFG_KEY_GFPS_TX_POWER \n
                                                             \#ALIAS : Google Fast Pair TX Power \n
                                                             \#PARAM_TYPE : Public \n
                                                             \#PARAM_DESC : TX Power shown on Google Fast Pair Advertising. \n
                                                             \#DESC_END  \n
                                                             \#GROUP_ID : 0x02 \n
                                                             \#KEY_ID : 0x1C \n
                                                       */
    BT_CFG_KEY_NUM_DEV_TO_CONN_AFTER_INQUIRY = 0x1D,   /**<  \#PARAM_NAME : BT_CFG_KEY_NUM_DEV_TO_CONN_AFTER_INQUIRY \n
                                                             \#ALIAS : Max Pairing Devices \n
                                                             \#PARAM_TYPE : Public \n
                                                             \#PARAM_DESC : Number of Devices to Connect After Inquiry. \n
                                                             \#DESC_END  \n
                                                             \#GROUP_ID : 0x02 \n
                                                             \#KEY_ID : 0x1D \n
                                                       */
    BT_CFG_KEY_INQUIRY_TIMEOUT              = 0x1E,    /**<  \#PARAM_NAME : BT_CFG_KEY_INQUIRY_TIMEOUT \n
                                                             \#ALIAS : Inquiry Timout \n
                                                             \#PARAM_TYPE : Public \n
                                                             \#PARAM_DESC : Inquiry Timout. \n
                                                             \#DESC_END  \n
                                                             \#GROUP_ID : 0x02 \n
                                                             \#KEY_ID : 0x1E \n
                                                       */
    BT_CFG_KEY_NUM_INQUIRY_RESULTS          = 0x1F,    /**<  \#PARAM_NAME : BT_CFG_KEY_NUM_INQUIRY_RESULTS \n
                                                             \#ALIAS : Max Inquiry Devices \n
                                                             \#PARAM_TYPE : Public \n
                                                             \#PARAM_DESC : Number of Inquiry Results. \n
                                                             \#DESC_END  \n
                                                             \#GROUP_ID : 0x02 \n
                                                             \#KEY_ID : 0x1F \n
                                                       */

    BT_CFG_KEY_AT_OPTIONS                   = 0x20,    /**<\#PARAM_NAME : BT_CFG_KEY_AT_OPTIONS \n
                                                            \#PARAM_TYPE : Public \n
                                                            \#GROUP_ID : 0x02 \n
                                                            \#KEY_ID : 0x20 \n
                                                             Bit Options:
                                                            \par
                                                            \#BIT_PARAM : AT_ENABLE_A2DP_STREAM_CONTROL \n
                                                            \#BIT_ALIAS : Stream Control by Plug-In Signal \n
                                                            \#BIT_POS : 0 \n
                                                            \#BIT_SIZE : 1 \n
                                                            \#BIT_DESC : Enable A2DP Stream Control during audio input plug or un-plug. \n
                                                            \#DESC_END

                                                            \par
                                                            \#BIT_PARAM : AT_ENABLE_CONNECT_IMM_AFTER_DISCOVER_DEVICE \n
                                                            \#BIT_ALIAS : Enable Quick Connection \n
                                                            \#BIT_POS : 1 \n
                                                            \#BIT_SIZE : 1 \n
                                                            \#BIT_DESC : AT Enable Connect Immediatly After Discover Device. \n
                                                            \#DESC_END

                                                            \par
                                                            \#BIT_PARAM : AT_ENABLE_DUAL_STREAMING \n
                                                            \#BIT_ALIAS : Dual Streaming Enable \n
                                                            \#BIT_POS : 2 \n
                                                            \#BIT_SIZE : 1 \n
                                                            \#BIT_DESC : AT Enable Dual Streaming. \n
                                                            \#DESC_END

                                                            \par
                                                            \#BIT_PARAM : AT_RSSI_FILTER \n
                                                            \#BIT_ALIAS : Enable Inquiry Filter by RSSI \n
                                                            \#BIT_POS : 3 \n
                                                            \#BIT_SIZE : 1 \n
                                                            \#BIT_DESC : AT Enable Dual Streaming. \n
                                                            \#DESC_END

                                                            \par
                                                            \#BIT_PARAM : Reserved \n
                                                            \#BIT_ALIAS : reserved \n
                                                            \#BIT_POS : 4 \n
                                                            \#BIT_SIZE : 4 \n
                                                            \#BIT_DESC : Reserved. \n
                                                            \#DESC_END
                                                       */
    BT_CFG_KEY_AT_SBC_SAMPLING_RATE         = 0x21,    /**<  \#PARAM_NAME : BT_CFG_KEY_AT_SBC_SAMPLING_RATE \n
                                                             \#ALIAS : SBC Sampling Rate \n
                                                             \#PARAM_TYPE : Public \n
                                                             \#PARAM_DESC : SBC Encode Sampling Rate. \n
                                                             \#DESC_END  \n
                                                             \#GROUP_ID : 0x02 \n
                                                             \#KEY_ID : 0x21 \n
                                                       */
    BT_CFG_KEY_AT_SBC_BITPOOL               = 0x22,    /**<  \#PARAM_NAME : BT_CFG_KEY_AT_SBC_BITPOOL \n
                                                             \#ALIAS : SBC Bitpool Setting \n
                                                             \#PARAM_TYPE : Public \n
                                                             \#PARAM_DESC : SBC Encode Bitpool for single link. \n
                                                             \#DESC_END  \n
                                                             \#GROUP_ID : 0x02 \n
                                                             \#KEY_ID : 0x22 \n
                                                       */
    BT_CFG_KEY_A2DP_SRC_DEVICE_INDEX        = 0x23,    /**<  \#PARAM_NAME : BT_CFG_KEY_A2DP_SRC_DEVICE_INDEX \n
                                                             \#ALIAS : A2DP SRC Device Index \n
                                                             \#PARAM_TYPE : Private \n
                                                             \#PARAM_DESC : A2DP SRC Device Index. \n
                                                             \#DESC_END  \n
                                                             \#GROUP_ID : 0x02 \n
                                                             \#KEY_ID : 0x23 \n
                                                       */
    BT_CFG_KEY_AT_RSSI_THRESHOLD           = 0x24,     /**<  \#PARAM_NAME : BT_CFG_KEY_AT_RSSI_THRESHOLD \n
                                                             \#ALIAS : RSSI Threshold of Inquiry Filter \n
                                                             \#PARAM_TYPE : Public \n
                                                             \#PARAM_DESC : RSSI THreshold value for filtering Inquiry Results. \n
                                                             \#DESC_END  \n
                                                             \#GROUP_ID : 0x02 \n
                                                             \#KEY_ID : 0x24 \n
                                                       */                                              	          
    BT_CFG_KEY_END       
}BT_CFG_Key_IdDefinition_T;


/**@defgroup MODULE_BT_CFG_DEFAULT_VALUE  BT Configuration Default Value
 * @brief Default value definition of the module @ref CFG_MODULE_ID_BT.
 * @{ */

//Module BT config key definitions
#define BT_CFG_KEY_APP_FIX_PIN_CODE_LEN                      0x04   /**< The default length of @ref BT_CFG_KEY_APP_FIX_PIN_CODE. */
#define BT_CFG_KEY_APP_FIX_PIN_CODE_DEFAULT_VALUE            0x30, 0x30, 0x30, 0x30 /**< The default value of @ref BT_CFG_KEY_APP_FIX_PIN_CODE. */

#define BT_CFG_KEY_NO_SERVICE_WARNING_TIME_LEN               0x01   /**< The default length of @ref BT_CFG_KEY_NO_SERVICE_WARNING_TIME. */
#define BT_CFG_KEY_NO_SERVICE_WARNING_TIME_DEFAULT_VALUE     0x1E   /**< The default value of @ref BT_CFG_KEY_NO_SERVICE_WARNING_TIME. */

#define BT_CFG_KEY_LINK_LOSS_RECONNECT_TIME_LEN              0x01   /**< The default length of @ref BT_CFG_KEY_LINK_LOSS_RECONNECT_TIME. */
#define BT_CFG_KEY_LINK_LOSS_RECONNECT_TIME_DEFAULT_VALUE    0x0C   /**< The default value of @ref BT_CFG_KEY_LINK_LOSS_RECONNECT_TIME. */

#define BT_CFG_KEY_PAGE_HS_TIME_LEN                          0x01   /**< The default length of @ref BT_CFG_KEY_PAGE_HS_TIME. */
#define BT_CFG_KEY_PAGE_HS_TIME_DEFAULT_VALUE                0x0C   /**< The default value of @ref BT_CFG_KEY_PAGE_HS_TIME. */

#define BT_CFG_KEY_PAIRING_TIMEOUT_LEN                       0x01   /**< The default length of @ref BT_CFG_KEY_PAIRING_TIMEOUT. */
#define BT_CFG_KEY_PAIRING_TIMEOUT_DEFAULT_VALUE             0x0A   /**< The default value of @ref BT_CFG_KEY_PAIRING_TIMEOUT. */

#define BT_CFG_KEY_A2DP_DEVICE_INDEX_LEN                     0x01   /**< The default length of @ref BT_CFG_KEY_A2DP_DEVICE_INDEX. */
#define BT_CFG_KEY_A2DP_DEVICE_INDEX_DEFAULT_VALUE           0xFF   /**< The default value of @ref BT_CFG_KEY_A2DP_DEVICE_INDEX. */

#define BT_CFG_KEY_PAGE_A2DP_TIME_LEN                        0x01   /**< The default length of @ref BT_CFG_KEY_PAGE_A2DP_TIME. */
#define BT_CFG_KEY_PAGE_A2DP_TIME_DEFAULT_VALUE              0x0C   /**< The default value of @ref BT_CFG_KEY_PAGE_A2DP_TIME. */

#define BT_CFG_KEY_RSSI_WEAK_THRESHOLD_LEN                   0x01   /**< The default length of @ref BT_CFG_KEY_RSSI_WEAK_THRESHOLD. */
#define BT_CFG_KEY_RSSI_WEAK_THRESHOLD_DEFAULT_VALUE         0xBA   /**< The default value of @ref BT_CFG_KEY_RSSI_WEAK_THRESHOLD. */

#define BT_CFG_KEY_SPECIFIC_SPP_UUID_0_LEN                   0x10   /**< The default length of @ref BT_CFG_KEY_SPECIFIC_SPP_UUID_0. */
#define BT_CFG_KEY_SPECIFIC_SPP_UUID_0_DEFAULT_VALUE         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00   /**< The default value of @ref BT_CFG_KEY_SPECIFIC_SPP_UUID_0. */

#define BT_CFG_KEY_SPECIFIC_SPP_UUID_1_LEN                   0x10   /**< The default length of @ref BT_CFG_KEY_SPECIFIC_SPP_UUID_1. */
#define BT_CFG_KEY_SPECIFIC_SPP_UUID_1_DEFAULT_VALUE          0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00   /**< The default value of @ref BT_CFG_KEY_SPECIFIC_SPP_UUID_1. */

#define BT_CFG_KEY_DEVICE_NAME_LEN                           0x09   /**< The default length of @ref BT_CFG_KEY_DEVICE_NAME. */
#define BT_CFG_KEY_DEVICE_NAME_DEFAULT_VALUE                 0x4D, 0x43, 0x48, 0x50, 0x20, 0x42, 0x4D, 0x38, 0x33   /**< The default value of @ref BT_CFG_KEY_DEVICE_NAME. */

//size of paired device = BDA(6 bytes) + priority(1 byte) +be_bondle(1 byte) = 8 bytes
#define BT_CFG_KEY_PAIRED_DEVICES_LEN                        0x40 //(0x08*0x08) /**< The default length of @ref BT_CFG_KEY_PAIRED_DEVICES. */
#define BT_CFG_KEY_PAIRED_DEVICES_DEFAULT_VALUE              0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,\
                                                             0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,\
                                                             0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,\
                                                             0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,\
                                                             0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,\
                                                             0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,\
                                                             0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,\
                                                             0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00   /**< The default value of @ref BT_CFG_KEY_PAIRED_DEVICES. */
                                                             

#define BT_CFG_KEY_HF_DEVICE_INDEX_LEN                       0x01   /**< The default length of @ref BT_CFG_KEY_HF_DEVICE_INDEX. */
#define BT_CFG_KEY_HF_DEVICE_INDEX_DEFAULT_VALUE             0xFF   /**< The default value of @ref BT_CFG_KEY_HF_DEVICE_INDEX. */

#define BT_CFG_KEY_LINK_QUALITY_DETECT_OPTION_LEN            0x01   /**< The default length of @ref BT_CFG_KEY_LINK_QUALITY_DETECT_OPTION. */
#define BT_CFG_KEY_LINK_QUALITY_DETECT_OPTION_DEFAULT_VALUE  0x43   /**< The default value of @ref BT_CFG_KEY_LINK_QUALITY_DETECT_OPTION. */

#define BT_CFG_KEY_SPP_OPTION_LEN                            0x01   /**< The default length of @ref BT_CFG_KEY_SPP_OPTION. */
#define BT_CFG_KEY_SPP_OPTION_DEFAULT_VALUE                  0x00   /**< The default value of @ref BT_CFG_KEY_SPP_OPTION. */

#define BT_CFG_KEY_LINK_OPTION_LEN                           0x01   /**< The default length of @ref BT_CFG_KEY_LINK_OPTION. */
#define BT_CFG_KEY_LINK_OPTION_DEFAULT_VALUE                 0x00   /**< The default value of @ref BT_CFG_KEY_LINK_OPTION. */

#define BT_CFG_KEY_HF_SUPPORT_FEATURE_LEN                    0x02   /**< The default length of @ref BT_CFG_KEY_HF_SUPPORT_FEATURE. */
#define BT_CFG_KEY_HF_SUPPORT_FEATURE_DEFAULT_VALUE          0x00, 0x9E   /**< The default value of @ref BT_CFG_KEY_HF_SUPPORT_FEATURE. */

#define BT_CFG_KEY_OPTION1_LEN                               0x01   /**< The default length of @ref BT_CFG_KEY_OPTION1. */
#define BT_CFG_KEY_OPTION1_DEFAULT_VALUE                     0x01   /**< The default value of @ref BT_CFG_KEY_OPTION1. */

#define BT_CFG_KEY_OPTION2_LEN                               0x01   /**< The default length of @ref BT_CFG_KEY_OPTION2. */
#define BT_CFG_KEY_OPTION2_DEFAULT_VALUE                     0x62   /**< The default value of @ref BT_CFG_KEY_OPTION2. */

#define BT_CFG_KEY_PROFILES_OPTION_LEN                       0x01   /**< The default length of @ref BT_CFG_KEY_PROFILES_OPTION. */
#define BT_CFG_KEY_PROFILES_OPTION_DEFAULT_VALUE             0x3F   /**< The default value of @ref BT_CFG_KEY_PROFILES_OPTION. */

#define BT_CFG_KEY_SPP_DEVICE_INDEX_LEN                      0x01   /**< The default length of @ref BT_CFG_KEY_SPP_DEVICE_INDEX. */
#define BT_CFG_KEY_SPP_DEVICE_INDEX_DEFAULT_VALUE            0xFF   /**< The default value of @ref BT_CFG_KEY_SPP_DEVICE_INDEX. */

#define BT_CFG_KEY_PAGE_SPP_TIME_LEN                         0x01   /**< The default length of @ref BT_CFG_KEY_PAGE_SPP_TIME. */
#define BT_CFG_KEY_PAGE_SPP_TIME_DEFAULT_VALUE               0x0C   /**< The default value of @ref BT_CFG_KEY_PAGE_SPP_TIME. */

#define BT_CFG_KEY_MAX_RF_TX_POWER_LEVEL_LEN                 0x01   /**< The default length of @ref BT_CFG_KEY_MAX_RF_TX_POWER_LEVEL. */
#define BT_CFG_KEY_MAX_RF_TX_POWER_LEVEL_DEFAULT_VALUE       0x66   /**< The default value of @ref BT_CFG_KEY_MAX_RF_TX_POWER_LEVEL. */

#define BT_CFG_KEY_GFPS_OPTION_LEN                           0x01    /**< The default length of @ref BT_CFG_KEY_BT_CFG_KEY_GFPS_ENABLE. */
#define BT_CFG_KEY_GFPS_OPTION_DEFAULT_VALUE                 0x00    /**< The default value of @ref BT_CFG_KEY_BT_CFG_KEY_GFPS_ENABLE. */

#define BT_CFG_KEY_GFPS_MODELID_LEN                          0x03    /**< The default length of @ref BT_CFG_KEY_GFPS_MODELID. */
#define BT_CFG_KEY_GFPS_MODELID_DEFAULT_VALUE                0x53, 0x90, 0x9A    /**< The default value of @ref BT_CFG_KEY_GFPS_MODELID. */

#define BT_CFG_KEY_GFPS_PRIVATE_KEY_LEN                      0x20    /**< The default length of @ref BT_CFG_KEY_GFPS_PRIVATE_KEY. */
#define BT_CFG_KEY_GFPS_PRIVATE_KEY_DEFAULT_VALUE            0x80, 0x6f, 0xd6, 0x42, 0x7e, 0x50, 0xb8, 0x89, 0xc3, 0x55, 0x14, 0xc4,\
                                                             0x33, 0x03, 0xf8, 0xc7, 0xcb, 0x6c, 0xf1, 0xab, 0x47, 0x55, 0xe7, 0xb3,\
                                                             0x53, 0x61, 0xbc, 0xd3, 0xe7, 0x86, 0x23, 0x87
                                                                     /**< The default value of @ref BT_CFG_KEY_GFPS_PRIVATE_KEY. */

#define BT_CFG_KEY_GFPS_ACCOUNT_KEY_LEN                      0x55    /**< The default length of @ref BT_CFG_KEY_GFPS_ACCOUNT_KEY. */
#define BT_CFG_KEY_GFPS_ACCOUNT_KEY_DEFAULT_VALUE            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,\
                                                             0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,\
                                                             0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,\
                                                             0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,\
                                                             0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
                                                                     /**< The default value of @ref BT_CFG_KEY_GFPS_ACCOUNT_KEY. */

#define BT_CFG_KEY_GFPS_TX_POWER_LEN                         0x01    /**< The default length of @ref BT_CFG_KEY_GFPS_TX_POWER. */
#define BT_CFG_KEY_GFPS_TX_POWER_DEFAULT_VALUE               0xE5    /**< The default value of @ref BT_CFG_KEY_GFPS_TX_POWER. */

#define BT_CFG_KEY_NUM_DEV_TO_CONN_AFTER_INQUIRY_LEN                0x01
#define BT_CFG_KEY_NUM_DEV_TO_CONN_AFTER_INQUIRY_DEFAULT_VALUE      0x02

#define BT_CFG_KEY_INQUIRY_TIMEOUT_LEN                       0x01
#define BT_CFG_KEY_INQUIRY_TIMEOUT_DEFAULT_VALUE             0x0A

#define BT_CFG_KEY_NUM_INQUIRY_RESULTS_LEN                   0x01
#define BT_CFG_KEY_NUM_INQUIRY_RESULTS_DEFAULT_VALUE         0x0A

#define BT_CFG_KEY_AT_OPTIONS_LEN                            0x01
#define BT_CFG_KEY_AT_OPTIONS_DEFAULT_VALUE                  0x0F

#define BT_CFG_KEY_AT_SBC_SAMPLING_RATE_LEN                  0x01
#define BT_CFG_KEY_AT_SBC_SAMPLING_RATE_DEFAULT_VALUE        0x00

#define BT_CFG_KEY_AT_SBC_BITPOOL_LEN                        0x01
#define BT_CFG_KEY_AT_SBC_BITPOOL_DEFAULT_VALUE              0x35

#define BT_CFG_KEY_A2DP_SRC_DEVICE_INDEX_LEN                 0x01
#define BT_CFG_KEY_A2DP_SRC_DEVICE_INDEX_DEFAULT_VALUE       0xFF

#define BT_CFG_KEY_AT_RSSI_THRESHOLD_LEN                     0x01
#define BT_CFG_KEY_AT_RSSI_THRESHOLD_DEFAULT_VALUE           0xBA


/** @} */
/** @} */

/** \cond NON_DOC */

#define CFG_BT_MODULE_TOTAL_NUM_KEYS    (BT_CFG_KEY_END - 1)  /**< The number of parameters in @ref CFG_MODULE_ID_BT. */

#define CFG_BT_MODULE_TOTAL_SIZE    ((CFG_BT_MODULE_TOTAL_NUM_KEYS*SIZEOF_CFG_KEY_STRUCT) +    \
                                    BT_CFG_KEY_APP_FIX_PIN_CODE_LEN +            \
                                    BT_CFG_KEY_NO_SERVICE_WARNING_TIME_LEN +     \
                                    BT_CFG_KEY_LINK_LOSS_RECONNECT_TIME_LEN +    \
                                    BT_CFG_KEY_PAGE_HS_TIME_LEN +                \
                                    BT_CFG_KEY_PAIRING_TIMEOUT_LEN +             \
                                    BT_CFG_KEY_A2DP_DEVICE_INDEX_LEN +           \
                                    BT_CFG_KEY_PAGE_A2DP_TIME_LEN +              \
                                    BT_CFG_KEY_RSSI_WEAK_THRESHOLD_LEN +         \
                                    BT_CFG_KEY_SPECIFIC_SPP_UUID_0_LEN +         \
                                    BT_CFG_KEY_SPECIFIC_SPP_UUID_1_LEN +         \
                                    BT_CFG_KEY_DEVICE_NAME_LEN +                 \
                                    BT_CFG_KEY_PAIRED_DEVICES_LEN +              \
                                    BT_CFG_KEY_HF_DEVICE_INDEX_LEN +             \
                                    BT_CFG_KEY_LINK_QUALITY_DETECT_OPTION_LEN +  \
                                    BT_CFG_KEY_SPP_OPTION_LEN +                  \
                                    BT_CFG_KEY_LINK_OPTION_LEN +                 \
                                    BT_CFG_KEY_HF_SUPPORT_FEATURE_LEN +          \
                                    BT_CFG_KEY_OPTION1_LEN +                     \
                                    BT_CFG_KEY_OPTION2_LEN +                     \
                                    BT_CFG_KEY_PROFILES_OPTION_LEN +             \
                                    BT_CFG_KEY_SPP_DEVICE_INDEX_LEN +            \
                                    BT_CFG_KEY_PAGE_SPP_TIME_LEN +               \
                                    BT_CFG_KEY_MAX_RF_TX_POWER_LEVEL_LEN +       \
                                    BT_CFG_KEY_GFPS_OPTION_LEN +                 \
                                    BT_CFG_KEY_GFPS_MODELID_LEN +                \
                                    BT_CFG_KEY_GFPS_PRIVATE_KEY_LEN +            \
                                    BT_CFG_KEY_GFPS_ACCOUNT_KEY_LEN +            \
                                    BT_CFG_KEY_GFPS_TX_POWER_LEN +               \
                                    BT_CFG_KEY_NUM_DEV_TO_CONN_AFTER_INQUIRY_LEN + \
                                    BT_CFG_KEY_INQUIRY_TIMEOUT_LEN +             \
                                    BT_CFG_KEY_NUM_INQUIRY_RESULTS_LEN +         \
                                    BT_CFG_KEY_AT_OPTIONS_LEN +                  \
                                    BT_CFG_KEY_AT_SBC_SAMPLING_RATE_LEN +        \
                                    BT_CFG_KEY_AT_SBC_BITPOOL_LEN +              \
                                    BT_CFG_KEY_A2DP_SRC_DEVICE_INDEX_LEN +       \
                                    BT_CFG_KEY_AT_RSSI_THRESHOLD_LEN)


//BT Config keys definition
#define CFG_BT_MODULE_DEFAULT_VALUE CFG_MODULE_ID_BT,               /*moduleID*/    \
                                    CFG_BT_MODULE_TOTAL_NUM_KEYS,   /*numKeys*/     \
                                    (CFG_BT_MODULE_TOTAL_SIZE >> 8),  /*moduleSize*/   \
                                    CFG_BT_MODULE_TOTAL_SIZE,                       \
                                    /*CFG_KEYs[numKeys]*/                    \
                                    /*    //ID                                    //Len                                        //Value        */                                    \    
                                    BT_CFG_KEY_APP_FIX_PIN_CODE,            BT_CFG_KEY_APP_FIX_PIN_CODE_LEN,            BT_CFG_KEY_APP_FIX_PIN_CODE_DEFAULT_VALUE,            \
                                    BT_CFG_KEY_NO_SERVICE_WARNING_TIME,     BT_CFG_KEY_NO_SERVICE_WARNING_TIME_LEN,     BT_CFG_KEY_NO_SERVICE_WARNING_TIME_DEFAULT_VALUE,    \
                                    BT_CFG_KEY_LINK_LOSS_RECONNECT_TIME,    BT_CFG_KEY_LINK_LOSS_RECONNECT_TIME_LEN,    BT_CFG_KEY_LINK_LOSS_RECONNECT_TIME_DEFAULT_VALUE,    \
                                    BT_CFG_KEY_PAGE_HS_TIME,                BT_CFG_KEY_PAGE_HS_TIME_LEN,                BT_CFG_KEY_PAGE_HS_TIME_DEFAULT_VALUE,                \
                                    BT_CFG_KEY_PAIRING_TIMEOUT,             BT_CFG_KEY_PAIRING_TIMEOUT_LEN,             BT_CFG_KEY_PAIRING_TIMEOUT_DEFAULT_VALUE,            \
                                    BT_CFG_KEY_A2DP_DEVICE_INDEX,           BT_CFG_KEY_A2DP_DEVICE_INDEX_LEN,           BT_CFG_KEY_A2DP_DEVICE_INDEX_DEFAULT_VALUE,            \
                                    BT_CFG_KEY_PAGE_A2DP_TIME,              BT_CFG_KEY_PAGE_A2DP_TIME_LEN,              BT_CFG_KEY_PAGE_A2DP_TIME_DEFAULT_VALUE,             \
                                    BT_CFG_KEY_RSSI_WEAK_THRESHOLD,         BT_CFG_KEY_RSSI_WEAK_THRESHOLD_LEN,         BT_CFG_KEY_RSSI_WEAK_THRESHOLD_DEFAULT_VALUE,        \
                                    BT_CFG_KEY_SPECIFIC_SPP_UUID_0,         BT_CFG_KEY_SPECIFIC_SPP_UUID_0_LEN,         BT_CFG_KEY_SPECIFIC_SPP_UUID_0_DEFAULT_VALUE,        \
                                    BT_CFG_KEY_SPECIFIC_SPP_UUID_1,         BT_CFG_KEY_SPECIFIC_SPP_UUID_1_LEN,         BT_CFG_KEY_SPECIFIC_SPP_UUID_1_DEFAULT_VALUE,         \
                                    BT_CFG_KEY_DEVICE_NAME,                 BT_CFG_KEY_DEVICE_NAME_LEN,                 BT_CFG_KEY_DEVICE_NAME_DEFAULT_VALUE,                \
                                    BT_CFG_KEY_PAIRED_DEVICES,              BT_CFG_KEY_PAIRED_DEVICES_LEN,              BT_CFG_KEY_PAIRED_DEVICES_DEFAULT_VALUE,             \
                                    BT_CFG_KEY_HF_DEVICE_INDEX,             BT_CFG_KEY_HF_DEVICE_INDEX_LEN,             BT_CFG_KEY_HF_DEVICE_INDEX_DEFAULT_VALUE,            \
                                    BT_CFG_KEY_LINK_QUALITY_DETECT_OPTION,  BT_CFG_KEY_LINK_QUALITY_DETECT_OPTION_LEN,  BT_CFG_KEY_LINK_QUALITY_DETECT_OPTION_DEFAULT_VALUE,    \
                                    BT_CFG_KEY_SPP_OPTION,                  BT_CFG_KEY_SPP_OPTION_LEN,                  BT_CFG_KEY_SPP_OPTION_DEFAULT_VALUE,                 \
                                    BT_CFG_KEY_LINK_OPTION,                 BT_CFG_KEY_LINK_OPTION_LEN,                 BT_CFG_KEY_LINK_OPTION_DEFAULT_VALUE,                \
                                    BT_CFG_KEY_HF_SUPPORT_FEATURE,          BT_CFG_KEY_HF_SUPPORT_FEATURE_LEN,          BT_CFG_KEY_HF_SUPPORT_FEATURE_DEFAULT_VALUE,         \
                                    BT_CFG_KEY_OPTION1,                     BT_CFG_KEY_OPTION1_LEN,                     BT_CFG_KEY_OPTION1_DEFAULT_VALUE,                    \
                                    BT_CFG_KEY_OPTION2,                     BT_CFG_KEY_OPTION2_LEN,                     BT_CFG_KEY_OPTION2_DEFAULT_VALUE,                    \
                                    BT_CFG_KEY_PROFILES_OPTION,             BT_CFG_KEY_PROFILES_OPTION_LEN,             BT_CFG_KEY_PROFILES_OPTION_DEFAULT_VALUE,            \
                                    BT_CFG_KEY_SPP_DEVICE_INDEX,            BT_CFG_KEY_SPP_DEVICE_INDEX_LEN,            BT_CFG_KEY_SPP_DEVICE_INDEX_DEFAULT_VALUE,           \
                                    BT_CFG_KEY_PAGE_SPP_TIME,               BT_CFG_KEY_PAGE_SPP_TIME_LEN,               BT_CFG_KEY_PAGE_SPP_TIME_DEFAULT_VALUE,              \
                                    BT_CFG_KEY_MAX_RF_TX_POWER_LEVEL,       BT_CFG_KEY_MAX_RF_TX_POWER_LEVEL_LEN,       BT_CFG_KEY_MAX_RF_TX_POWER_LEVEL_DEFAULT_VALUE,      \
                                    BT_CFG_KEY_GFPS_OPTION,                 BT_CFG_KEY_GFPS_OPTION_LEN,                 BT_CFG_KEY_GFPS_OPTION_DEFAULT_VALUE,                \
                                    BT_CFG_KEY_GFPS_MODELID,                BT_CFG_KEY_GFPS_MODELID_LEN,                BT_CFG_KEY_GFPS_MODELID_DEFAULT_VALUE,               \
                                    BT_CFG_KEY_GFPS_PRIVATE_KEY,            BT_CFG_KEY_GFPS_PRIVATE_KEY_LEN,            BT_CFG_KEY_GFPS_PRIVATE_KEY_DEFAULT_VALUE,           \
                                    BT_CFG_KEY_GFPS_ACCOUNT_KEY,            BT_CFG_KEY_GFPS_ACCOUNT_KEY_LEN,            BT_CFG_KEY_GFPS_ACCOUNT_KEY_DEFAULT_VALUE,           \
                                    BT_CFG_KEY_GFPS_TX_POWER,               BT_CFG_KEY_GFPS_TX_POWER_LEN,               BT_CFG_KEY_GFPS_TX_POWER_DEFAULT_VALUE,               \
                                    BT_CFG_KEY_NUM_DEV_TO_CONN_AFTER_INQUIRY,   BT_CFG_KEY_NUM_DEV_TO_CONN_AFTER_INQUIRY_LEN,   BT_CFG_KEY_NUM_DEV_TO_CONN_AFTER_INQUIRY_DEFAULT_VALUE, \
                                    BT_CFG_KEY_INQUIRY_TIMEOUT,                 BT_CFG_KEY_INQUIRY_TIMEOUT_LEN,                 BT_CFG_KEY_INQUIRY_TIMEOUT_DEFAULT_VALUE,               \
                                    BT_CFG_KEY_NUM_INQUIRY_RESULTS,             BT_CFG_KEY_NUM_INQUIRY_RESULTS_LEN,             BT_CFG_KEY_NUM_INQUIRY_RESULTS_DEFAULT_VALUE,           \
                                    BT_CFG_KEY_AT_OPTIONS,                      BT_CFG_KEY_AT_OPTIONS_LEN,                      BT_CFG_KEY_AT_OPTIONS_DEFAULT_VALUE,                    \
                                    BT_CFG_KEY_AT_SBC_SAMPLING_RATE,            BT_CFG_KEY_AT_SBC_SAMPLING_RATE_LEN,            BT_CFG_KEY_AT_SBC_SAMPLING_RATE_DEFAULT_VALUE,           \
                                    BT_CFG_KEY_AT_SBC_BITPOOL,                  BT_CFG_KEY_AT_SBC_BITPOOL_LEN,                  BT_CFG_KEY_AT_SBC_BITPOOL_DEFAULT_VALUE,                 \
                                    BT_CFG_KEY_A2DP_SRC_DEVICE_INDEX,           BT_CFG_KEY_A2DP_SRC_DEVICE_INDEX_LEN,           BT_CFG_KEY_A2DP_SRC_DEVICE_INDEX_DEFAULT_VALUE,          \
                                    BT_CFG_KEY_AT_RSSI_THRESHOLD,               BT_CFG_KEY_AT_RSSI_THRESHOLD_LEN,               BT_CFG_KEY_AT_RSSI_THRESHOLD_DEFAULT_VALUE



#define BT_CFG_TU_LINK_LOST_RECONNECT        0x08 /*slow timer 8*640ms=>5.12s*/    /**< timer unit of link lost reconnect*/
#define BT_CFG_TU_PAIRING                    0x2F /*slow timer 47*640ms=>30.08s*/  /**< timer unit of pairing enable*/
#define BT_CFG_TU_SERVICE_WARNING            0x01 /*slow timer 1*640ms=>0.64s*/    /**< timer unit of no service warning*/
#define BT_CFG_TU_PAGE_HF                    0x08 /*slow timer 8*640ms=>5.12s*/    /**< timer unit of connect to HF/HS profile*/ 
#define BT_CFG_TU_PAGE_A2DP                  0x08 /*slow timer 8*640ms=>5.12s*/    /**< timer unit of connect to A2DP profile*/ 
#define BT_CFG_TU_PAGE_SPP                   0x08 /*slow timer 8*640ms=>5.12s*/    /**< timer unit of connect to SPP profile*/ 
#define BT_CFG_TU_AUTO_POWER_OFF             0x5E /*slow timer 94*640ms=>60.16s*/  /**< timer unit of auto power off*/ 
#define BT_CFG_DEVICE_NAME_MAX_LEN           0x40
#define BT_CFG_BTN_TABLE_ACTION_NUM          (0x10)
#define BT_CFG_LINK_LOST_RECONNECT_FOREVER   0x7F8/*0xFF*BT_CFG_TU_LINK_LOST_RECONNECT*/

#define BT_CFG_LINK_SCENARIO_LAST_DEVICE    (0)
#define BT_CFG_LINK_SCENARIO_HF_BASE        (1)
#define BT_CFG_LINK_SCENARIO_A2DP_BASE      (2)

#define BT_CFG_AVRCP_SELECT_1_3             (0)
#define BT_CFG_AVRCP_SELECT_1_6             (1)

// Audio Transmitter BT_CFG_KEY_AT_OPTIONS bit_positions
#define BT_CFG_AT_A2DP_STREAM_CONTROL_PLUG_UNPLUG   (0x01)
#define BT_CFG_AT_CONNECT_AFTER_DISCOVER_DEVICE     (0x02)
#define BT_CFG_AT_ENABLE_DUAL_STREAMING             (0x04)
#define BT_CFG_AT_ENABLE_RSSI_FILTER                (0x08)

typedef struct _APP_Cfg_BtPairedDevice_T
{
    uint8_t  bdAddr[BT_GAP_MAX_BD_ADDRESS_LEN];
    uint8_t  priority;
    uint8_t  beBondle;
} APP_Cfg_BtPairedDevice_T;


typedef struct _APP_Cfg_BtOption1_T
{
    uint8_t PowerOnLinkback: 1;
    uint8_t linkbackFailEnterPairing: 1;
    uint8_t linkbackByPriority: 1;
    uint8_t askPhoneDisableNrec: 1;
    uint8_t autoAnswerIncomingCall: 1; 
    uint8_t linkbackAutoAnswerIncomingCall: 1;
    uint8_t powerOnPairing: 1;
    uint8_t discoverableInStandby: 1;
} APP_Cfg_BtOption1_T;

typedef struct _APP_Cfg_BtOption2_T
{
    uint8_t reserved1 : 1;
    uint8_t supportMultiLinkProfile : 1;
    uint8_t reserved2 : 3;
    uint8_t batteryReportAtCmd : 1;
    uint8_t avrcpVersion : 1;
    uint8_t reserved3 : 1;
} APP_Cfg_BtOption2_T;


//sequence follow HFP specification
typedef struct _APP_Cfg_BtHfSupportFeature_T
{
    uint16_t enableEcNr : 1;
    uint16_t enableCallWaiting : 1;
    uint16_t cliPresent : 1;
    uint16_t vrActivation : 1;
    uint16_t remoteVolCtrl : 1;
    uint16_t enhanceCallStatus : 1;
    uint16_t enhanceCallCtrl : 1;
    uint16_t codecNego : 1;
    uint16_t hfIndicator : 1;
    uint16_t eScoS4Setting : 1;
    uint16_t reserved : 6;
} APP_Cfg_BtHfSupportFeature_T;

typedef struct _APP_Cfg_BtProfileOption_T
{
    uint8_t enableHs : 1;
    uint8_t enableHf : 1;
    uint8_t enableA2dp : 1;
    uint8_t enableAvrcpCt : 1;
    uint8_t enableAvrcpTg : 1;
    uint8_t enableSpp : 1;
    uint8_t enableIap : 1;
    uint8_t enablePbap : 1;
} APP_Cfg_BtProfileOption_T;

typedef struct _APP_Cfg_BtGfpsOption_T
{
    uint8_t enableGfps : 1;
    uint8_t enableBattNotification : 1;
    uint8_t reserved : 6;
} APP_Cfg_BtGfpsOption_T;

#ifdef APP_AT_ENABLE
void APP_CFG_ReadAtSbcEncodeSamplingRate(uint8_t XDATA *p_sampleRate);
void APP_CFG_WriteAtSbcEncodeSamplingRate(uint8_t XDATA *p_sampleRate);
void APP_CFG_ReadAtSbcEncodeBitPool(uint8_t XDATA *p_bitPool);

void APP_CFG_ReadNumOfDevToConnectAfterInquiry(uint8_t XDATA *p_devNum);
void APP_CFG_ReadInquiryTimeout(uint8_t XDATA *p_devTimeout);
void APP_CFG_ReadNumInquiryResults(uint8_t XDATA *p_devNumInquiryResults);
void APP_CFG_ReadAtOptions(uint8_t XDATA *p_atOptions);
void APP_CFG_ReadAtRssiThresValue(int8_t XDATA * p_rssiThresValue);
#endif

void APP_CFG_ReadBtFixPinCode(uint8_t XDATA *p_len, uint8_t XDATA *p_pinCode);
void APP_CFG_WriteBtFixPinCode(uint8_t len, uint8_t XDATA *p_pinCOde);

void APP_CFG_ReadBtNoServiceWarningTime(uint16_t XDATA *p_warningTime);

void APP_CFG_ReadBtLinkLostReconnTimeout(uint16_t XDATA *p_reconnTime);

void APP_CFG_ReadBtHfDevIndex(uint8_t XDATA *p_devIndex);
void APP_CFG_WriteBtHfDevIndex(uint8_t devIndex);

void APP_CFG_ReadBtPageHsTime(uint16_t XDATA *p_pageTime);

void APP_CFG_ReadBtPairingTimeout(uint16_t XDATA *p_pairingTimeout);
void APP_CFG_WriteBtPairingTimeout(uint8_t pairingTimeout);

void APP_CFG_ReadBtA2dpDevIndex(uint8_t XDATA *p_devIndex);
void APP_CFG_WriteBtA2dpDevIndex(uint8_t devIndex);

void APP_CFG_ReadBtA2dpSrcDevIndex(uint8_t XDATA *p_devIndex);
void APP_CFG_WriteBtA2dpSrcDevIndex(uint8_t devIndex);

void APP_CFG_ReadBtPageA2dpTime(uint16_t XDATA *p_pageTime);

void APP_CFG_ReadBtSppDevIndex(uint8_t XDATA *p_devIndex);
void APP_CFG_WriteBtSppDevIndex(uint8_t devIndex);

void APP_CFG_ReadBtPageSppTime(uint16_t XDATA *p_pageTime);

void APP_CFG_ReadBtDeviceName(uint8_t XDATA *p_len, uint8_t XDATA *p_deviceName);
void APP_CFG_WriteBtDeviceName(uint8_t len, uint8_t XDATA *p_deviceName);


void APP_CFG_ReadBtPairedDevices(uint8_t XDATA *p_len, APP_Cfg_BtPairedDevice_T XDATA *p_pairedDevices);
void APP_CFG_WriteBtPairedDevices(uint8_t len, APP_Cfg_BtPairedDevice_T XDATA *p_pairedDevices);

void APP_CFG_ReadBtLinkOption(uint8_t XDATA *p_linkOption);

void APP_CFG_ReadBtHfSupportFeature(APP_Cfg_BtHfSupportFeature_T XDATA *p_hfFeature);

void APP_CFG_ReadBtOption1(APP_Cfg_BtOption1_T XDATA *p_option);

void APP_CFG_ReadBtOption2(APP_Cfg_BtOption2_T XDATA *p_option);
void APP_CFG_ReadBtProfileOption(APP_Cfg_BtProfileOption_T XDATA *p_option);
void APP_CFG_WriteBtProfileOption(APP_Cfg_BtProfileOption_T option);
void APP_CFG_ReadBtMaxRfTxPowerLevel(uint8_t XDATA * p_connectedPowerLevel, uint8_t XDATA *p_inquiryPagePowerLevel) large;

#ifdef ENABLE_GFPS
void APP_CFG_ReadBtGfpsOption(APP_Cfg_BtGfpsOption_T XDATA *p_option);
void APP_CFG_ReadBtGfpsModelId(u8 XDATA *p_modelId);
void APP_CFG_ReadBtGfpsPrivateKey(u8 XDATA *p_privateKey);
void APP_CFG_ReadBtGfpsAccountKeyList(u8 XDATA *p_accountKeyList);
void APP_CFG_WriteBtGfpsAccountKeyList(u8 len, u8 XDATA *p_accountKeyList);
void APP_CFG_ReadBtGfpsTxPower(u8 XDATA *p_txPower);
#endif

/// \endcond
#endif    //APP_CFG_BT_H



