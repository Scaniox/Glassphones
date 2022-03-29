/********************************************************************
  File Information:
    FileName:       app_cfg_ble.h
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

#ifndef APP_CFG_BLE_H
#define APP_CFG_BLE_H

/** \cond NON_DOC 

\#BUILD_TARGET : MSPKv2_App_Basic
\#BUILD_TARGET : MSPKv2_GFP
\#BUILD_TARGET : MSPKv2_SPP
\#BUILD_TARGET : MSPKv2_PBAP
\#BUILD_TARGET : AT_App
\#TARGET_START
\#REMOVE_PARAM : BLE_CFG_KEY_ADV_FLAG
\#REMOVE_BIT : ENABLE_ADV_RANDOM_ADDRESS
\#REMOVE_PARAM : BLE_CFG_KEY_TRANSPARENT_SRV_TX_PROPERTY
\#REMOVE_PARAM : BLE_CFG_KEY_TRANSPARENT_SRV_RX_PROPERTY
\#REMOVE_PARAM : BLE_CFG_KEY_TRANSPARENT_SRV_TX_PERMISSION
\#REMOVE_PARAM : BLE_CFG_KEY_TRANSPARENT_SRV_RX_PERMISSION
\#TARGET_END
\endcond
*/


/**
  @addtogroup APP_CFG_MODULE_BLE BLE Configuration
  @{
  @brief Definitions and prototypes for the MODULE_BLE Configuration.
 */

//Config Key definiton of MODULE_BLE(0x04)
/**
 * @brief Configuration key definition of the module @ref CFG_MODULE_ID_BLE.
 * */

typedef enum _BLE_CFG_Key_IdDefinition_T
{
    BLE_CFG_KEY_ADV_DATA                        = 0x01, /**<\#PARAM_NAME : BLE_CFG_KEY_ADV_DATA \n
                                                            \#ALIAS : ADV DATA \n
                                                            \#PARAM_TYPE : Public \n
                                                            \#PARAM_DESC : LE advertising data. The max length is 0x1C \n
                                                                           Format:
                                                                           {
                                                                                {(u8) length1, (u8) type1, data1[length1]},
                                                                                {(u8) length2, (u8) type2, data2[length2]},
                                                                                ...
                                                                           }\n
                                                            \#DESC_END
                                                            \#GROUP_ID : 0x04\n
                                                            \#KEY_ID : 0x01 \n
                                                	    */
                                                	     
    BLE_CFG_KEY_SCAN_RSP_DATA                   = 0x02, /**<\#PARAM_NAME : BLE_CFG_KEY_SCAN_RSP_DATA \n
                                                            \#ALIAS : SCAN RSP DATA \n
                                                            \#PARAM_TYPE : Public \n
                                                            \#PARAM_DESC : LE scan response data. The max length is 0x1F\n
                                                                           Format:
                                                                           {
                                                                                {(u8) length1, (u8) type1, data1[length1]},
                                                                                {(u8) length2, (u8) type2, data2[length2]},
                                                                                ...
                                                                           }\n
                                                            \#DESC_END
                                                            \#GROUP_ID : 0x04\n
                                                            \#KEY_ID : 0x02 \n
                                                	    */
                                                	     
    BLE_CFG_KEY_AUTO_DISCONNECT_TIME            = 0x03, /**<\#PARAM_NAME : BLE_CFG_KEY_AUTO_DISCONNECT_TIME \n
                                                            \#ALIAS : LE Reconnection Timeout \n
                                                            \#PARAM_TYPE : Public \n
                                                            \#PARAM_DESC : If no data is transmitted over this time, disconnect LE connection. \n
                                                                           Unit:min, 0 means this function is disabled. \n
                                                            \#DESC_END
                                                            \#GROUP_ID : 0x04\n
                                                            \#KEY_ID : 0x03 \n
                                                	    */
                                                	     
    BLE_CFG_KEY_FAST_ADV_TIMEOUT                = 0x04, /**<\#PARAM_NAME : BLE_CFG_KEY_FAST_ADV_TIMEOUT \n
                                                            \#ALIAS : LE Fast Advertising Timeout \n
                                                            \#PARAM_TYPE : Public \n
                                                            \#PARAM_DESC : the advertising timeout for fast advertising (shorter advertising interval) \n
                                                                           0: no timeout \n
                                                                           unit: 10.24ms \n
                                                                           It's used only if  EMBEDDED_SPP_ENABLE is enabled \n
                                                            \#DESC_END
                                                            \#GROUP_ID : 0x04\n
                                                            \#KEY_ID : 0x04 \n
                                                	    */
                                                	     
    BLE_CFG_KEY_REDUCED_POWER_ADV_TIMEOUT       = 0x05, /**<\#PARAM_NAME : BLE_CFG_KEY_REDUCED_POWER_ADV_TIMEOUT \n
                                                            \#ALIAS : LE Reduced Power Advertising Timeout \n
                                                            \#PARAM_TYPE : Public \n
                                                            \#PARAM_DESC : the advertising timeout for reduced power advertising (longer advertising interval) \n
                                                                           0: no timeout \n
                                                                           unit: 10.24s \n
                                                                           It's used only if EMBEDDED_SPP_ENABLE is enabled \n
                                                            \#DESC_END
                                                            \#GROUP_ID : 0x04\n
                                                            \#KEY_ID : 0x05 \n
                                                	    */
                                                	     
    BLE_CFG_KEY_REDUCED_POWER_ADV_INTERVAL      = 0x06, /**<\#PARAM_NAME : BLE_CFG_KEY_REDUCED_POWER_ADV_INTERVAL \n
                                                            \#ALIAS : LE Reduced Power Advertising Interval \n
                                                            \#PARAM_TYPE : Public \n
                                                            \#PARAM_DESC : reduced power advertising interval \n
                                                                           unit: 0.625ms \n
                                                                           It's used only if EMBEDDED_SPP_ENABLE is enabled \n
                                                            \#DESC_END
                                                            \#GROUP_ID : 0x04\n
                                                            \#KEY_ID : 0x06 \n
                                                	    */
                                                	     
    BLE_CFG_KEY_CONNECTION_INTERVAL_MIN         = 0x07, /**<\#PARAM_NAME : BLE_CFG_KEY_CONNECTION_INTERVAL_MIN \n
                                                            \#ALIAS : Min. LE Connection Interval \n
                                                            \#PARAM_TYPE : Public \n
                                                            \#PARAM_DESC : This parameter is used to set LE min connection interval if EMBEDDED_SPP_ENABLE is enabled. \n
                                                                           The value 0x0000 means Dual Speaker won't issue parameter update request command. \n
                                                                           Valid range:0x0000, 0x0008~0x0C80 \n
                                                                           Unit: 1.25ms \n
                                                            \#DESC_END
                                                            \#GROUP_ID : 0x04\n
                                                            \#KEY_ID : 0x07 \n
                                                            \#VALID_MAX : 0x0C80 \n
                                                	        \#VALID_MIN : 0x0000 \n
                                                	    */
                                                	     
    BLE_CFG_KEY_CONNECTION_INTERVAL_MAX         = 0x08, /**<\#PARAM_NAME : BLE_CFG_KEY_CONNECTION_INTERVAL_MAX \n
                                                            \#ALIAS : Max. LE Connection Interval \n
                                                            \#PARAM_TYPE : Public \n
                                                            \#PARAM_DESC : This parameter is used to set LE max connection interval if EMBEDDED_SPP_ENABLE is enabled. \n
                                                                           The value 0x0000 means Dual Speaker won't issue parameter update request command.\n
                                                                           Valid range:0x0000, 0x0010~0x0C80\n
                                                                           Unit: 1.25ms\n
                                                            \#DESC_END
                                                            \#GROUP_ID : 0x04\n
                                                            \#KEY_ID : 0x08 \n
                                                	    */
                                                	     
    BLE_CFG_KEY_SLAVE_LATENCY                   = 0x09, /**<\#PARAM_NAME : BLE_CFG_KEY_SLAVE_LATENCY \n
                                                            \#ALIAS : LE Slave Latency \n
                                                            \#PARAM_TYPE : Public \n
                                                            \#PARAM_DESC : This parameter is used to set LE slave latency \n
                                                            \#DESC_END
                                                            \#GROUP_ID : 0x04\n
                                                            \#KEY_ID : 0x09 \n
                                                            \#VALID_MAX : 0x3E8 \n
                                                	        \#VALID_MIN : 0x000 \n
                                                	    */
                                                	     
    BLE_CFG_KEY_SUPERVISION_TIMEOUT             = 0x0A, /**<\#PARAM_NAME : BLE_CFG_KEY_SUPERVISION_TIMEOUT \n
                                                            \#ALIAS : LE Supervision Timeout \n
                                                            \#PARAM_TYPE : Public \n
                                                            \#PARAM_DESC : This parameter is used to set LE supervision timeout \n
                                                                           Unit: 10ms \n
                                                                           Apple recommended parameters: \n
                                                                           ● connectionIntervalMax * (slaveLatency + 1) ≤ 2 seconds \n
                                                                           ● connectionIntervalMin ≥ 20 ms \n
                                                                           ● connectionIntervalMin + 20 ms ≤connectionIntervalMax \n
                                                                           ● slaveLatency ≤ 4 \n
                                                                           ● supervisionTimeout ≤ 6 seconds \n
                                                                           ● connectionIntervalMax * slaveLatency + 1) * 3 < supervisionTimeout \n
                                                                           If the parameters don't follow these rules, iOS may reject the connection parameter update request. \n
                                                            \#DESC_END
                                                            \#GROUP_ID : 0x04\n
                                                            \#KEY_ID : 0x0A \n
                                                            \#VALID_MAX : 0x0C80 \n
                                                	        \#VALID_MIN : 0x000A \n
                                                	    */
                                                	     
    BLE_CFG_KEY_ADV_FLAG                        = 0x0B, /**<\#PARAM_NAME : BLE_CFG_KEY_ADV_FLAG \n
                                                            \#ALIAS : ADV FLAG \n
                                                            \#PARAM_TYPE : Public \n
                                                            \#PARAM_DESC : The value of the "flags" ADV type in advertising data  \n
                                                            \#DESC_END
                                                            \#GROUP_ID : 0x04\n
                                                            \#KEY_ID : 0x0B \n
                                                	    */
                                               	     
    BLE_CFG_KEY_BLE_OPTION                      = 0x0C, /**<\#PARAM_NAME : BLE_CFG_KEY_BLE_OPTION \n
                                                            \#PARAM_TYPE : Public \n
                                                            \#GROUP_ID : 0x04\n
                                                            \#KEY_ID : 0x0C \n
                                                            Bit Options:
                                                        	\par
                                                        	\#BIT_PARAM : ENABLE_ADV_RANDOM_ADDRESS \n
                                                        	\#BIT_ALIAS : Enable advertising random address \n
                                                        	\#BIT_POS : 0 \n
                                                        	\#BIT_SIZE : 1 \n
                                                        	\#BIT_DESC : If enabled, BLE device will be advertised using a random BD address \n
                                                        	\#DESC_END

                                                            \par
                                                        	\#BIT_PARAM : reserved \n
                                                        	\#BIT_ALIAS : reserved \n
                                                        	\#BIT_POS : 1 \n
                                                        	\#BIT_SIZE : 1 \n
                                                        	\#BIT_DESC : \n
                                                        	\#DESC_END

                                                        	\par
                                                        	\#BIT_PARAM : ENABLE_BLE_APPLICATION \n
                                                        	\#BIT_ALIAS : BLE Application in Embedded Mode \n
                                                        	\#BIT_POS : 2 \n
                                                        	\#BIT_SIZE : 1 \n
                                                        	\#BIT_DESC : \n
                                                        	\#DESC_END

                                                        	\par
                                                        	\#BIT_PARAM : BEACON_DATA_IN_ADV_DATA \n
                                                        	\#BIT_ALIAS : Beacon data in advertising data. \n
                                                        	\#BIT_POS : 3 \n
                                                        	\#BIT_SIZE : 1 \n
                                                        	\#BIT_DESC : \n
                                                        	\#DESC_END

                                                        	\par
                                                        	\#BIT_PARAM : BEACON_DATA_IN_SCAN_RESP_DATA \n
                                                        	\#BIT_ALIAS : Beacon data in scan resp data. \n
                                                        	\#BIT_POS : 4 \n
                                                        	\#BIT_SIZE : 1 \n
                                                        	\#BIT_DESC : \n
                                                        	\#DESC_END

                                                             \par
                                                        	\#BIT_PARAM : AUTH_REQUEST_IN_TRANSPARENT \n
                                                        	\#BIT_ALIAS : Authentication Request \n
                                                        	\#BIT_POS : 5 \n
                                                        	\#BIT_SIZE : 1 \n
                                                        	\#BIT_DESC : Set to 1 to enable authentication for transparent service \n
                                                        	\#DESC_END

                                                        	\par
                                                        	\#BIT_PARAM : DISABLE_OTA_DFU_SERVICE \n
                                                        	\#BIT_ALIAS : OTA DFU Service \n
                                                        	\#BIT_POS : 6 \n
                                                        	\#BIT_SIZE : 1 \n
                                                        	\#BIT_DESC : set to 1 to disable OTA DFU service \n
                                                        	\#DESC_END
                                                        	
                                                        	\par
                                                        	\#BIT_PARAM : ENABLE_BLE_CUSTOMIZED_LOCAL_NAME \n
                                                        	\#BIT_ALIAS : Customized Local Name \n
                                                        	\#BIT_POS : 7 \n
                                                        	\#BIT_SIZE : 1 \n
                                                        	\#BIT_DESC : Enable this option to keep the local name edited in configuration, otherwise the local name 
                                                        	             will be updated by BT device name in system initialization.\n
                                                        	\#DESC_END
                                                                          
                                                	    */
                                                	     
    BLE_CFG_KEY_TRANSPARENT_SRV_UUID            = 0x0D, /**<\#PARAM_NAME : BLE_CFG_KEY_TRANSPARENT_SRV_UUID \n
                                                            \#ALIAS : Transparent Service UUID \n
                                                            \#PARAM_TYPE : Public \n
                                                            \#PARAM_DESC : The UUID of transparent service \n
                                                            \#DESC_END
                                                            \#GROUP_ID : 0x04\n
                                                            \#KEY_ID : 0x0D \n
                                                	    */
                                                	     
    BLE_CFG_KEY_TRANSPARENT_TX_UUID             = 0x0E, /**<\#PARAM_NAME : BLE_CFG_KEY_TRANSPARENT_TX_UUID \n
                                                            \#ALIAS : Transparent TX UUID \n
                                                            \#PARAM_TYPE : Public \n
                                                            \#PARAM_DESC : The UUID of transparent TX characteristic \n
                                                            \#DESC_END
                                                            \#GROUP_ID : 0x04\n
                                                            \#KEY_ID : 0x0E \n
                                                	    */
                                                	     
    BLE_CFG_KEY_TRANSPARENT_RX_UUID             = 0x0F, /**<\#PARAM_NAME : BLE_CFG_KEY_TRANSPARENT_RX_UUID \n
                                                            \#ALIAS : Transparent RX UUID \n
                                                            \#PARAM_TYPE : Public \n
                                                            \#PARAM_DESC : The UUID of transparent RX characteristic \n
                                                            \#DESC_END
                                                            \#GROUP_ID : 0x04\n
                                                            \#KEY_ID : 0x0F \n
                                                	    */
                                                	     
    BLE_CFG_KEY_MANUFACTURE_NAME_STRING         = 0x10, /**<\#PARAM_NAME : BLE_CFG_KEY_MANUFACTURE_NAME_STRING \n
                                                            \#ALIAS : Manufacture Name \n
                                                            \#PARAM_TYPE : Public \n
                                                            \#PARAM_DESC : This parameter is used to configure the name of the manufacturer of the device \n
                                                            \#DESC_END
                                                            \#GROUP_ID : 0x04\n
                                                            \#KEY_ID : 0x10 \n
                                                	    */
                                                	     
    BLE_CFG_KEY_MODEL_NAME_STRING               = 0x11, /**<\#PARAM_NAME : BLE_CFG_KEY_MODEL_NAME_STRING \n
                                                            \#ALIAS : Model Name \n
                                                            \#PARAM_TYPE : Public \n
                                                            \#PARAM_DESC : Thisparameter is used to configure the model number that is assigned by the device vendor \n
                                                            \#DESC_END
                                                            \#GROUP_ID : 0x04\n
                                                            \#KEY_ID : 0x11 \n
                                                	    */
                                                	     
    BLE_CFG_KEY_SERIAL_NUMBER_STRING             = 0x12, /**<\#PARAM_NAME : BLE_CFG_KEY_SERIAL_NUMBER_STRING \n
                                                            \#ALIAS : Serial Number \n
                                                            \#PARAM_TYPE : Public \n
                                                            \#PARAM_DESC : This parameter is used to configure the serial number for a particular instance of the device. \n
                                                            \#DESC_END
                                                            \#GROUP_ID : 0x04\n
                                                            \#KEY_ID : 0x12 \n
                                                	    */
                                                	     
    BLE_CFG_KEY_SOFTWARE_REVISION_STRING        = 0x13, /**<\#PARAM_NAME : BLE_CFG_KEY_SOFTWARE_REVISION_STRING \n
                                                            \#ALIAS : Software Revision \n
                                                            \#PARAM_TYPE : Public \n
                                                            \#PARAM_DESC : This parameter is used to configure the software revision for the software within the device \n
                                                            \#DESC_END
                                                            \#GROUP_ID : 0x04\n
                                                            \#KEY_ID : 0x13 \n
                                                	    */
                                                	     
    BLE_CFG_KEY_TRANSPARENT_SRV_TX_PROPERTY     = 0x14, /**<\#PARAM_NAME : BLE_CFG_KEY_TRANSPARENT_SRV_TX_PROPERTY \n
                                                            \#ALIAS : TRANSPARENT SRV TX PROPERTY \n
                                                            \#PARAM_TYPE : Public \n
                                                            \#PARAM_DESC : (not implement)Transparent Service TX property \n
                                                            \#DESC_END
                                                            \#GROUP_ID : 0x04\n
                                                            \#KEY_ID : 0x14 \n
                                                	    */
                                                	     
    BLE_CFG_KEY_TRANSPARENT_SRV_RX_PROPERTY     = 0x15, /**<\#PARAM_NAME : BLE_CFG_KEY_TRANSPARENT_SRV_RX_PROPERTY \n
                                                            \#ALIAS : TRANSPARENT SRV RX PROPERTY \n
                                                            \#PARAM_TYPE : Public \n
                                                            \#PARAM_DESC : (not implement)Transparent Service RX property \n
                                                            \#DESC_END
                                                            \#GROUP_ID : 0x04\n
                                                            \#KEY_ID : 0x15 \n
                                                	    */
                                                	     
    BLE_CFG_KEY_TRANSPARENT_SRV_TX_PERMISSION   = 0x16, /**<\#PARAM_NAME : BLE_CFG_KEY_TRANSPARENT_SRV_TX_PERMISSION \n
                                                            \#ALIAS : TRANSPARENT SRV TX PERMISSION \n
                                                            \#PARAM_TYPE : Public \n
                                                            \#PARAM_DESC : (not implement)Transparent Service TX Permission \n
                                                            \#DESC_END
                                                            \#GROUP_ID : 0x04\n
                                                            \#KEY_ID : 0x16 \n
                                                	    */
                                                	     
    BLE_CFG_KEY_TRANSPARENT_SRV_RX_PERMISSION   = 0x17, /**<\#PARAM_NAME : BLE_CFG_KEY_TRANSPARENT_SRV_RX_PERMISSION \n
                                                            \#ALIAS : TRANSPARENT SRV RX PERMISSION \n
                                                            \#PARAM_TYPE : Public \n
                                                            \#PARAM_DESC : (not implement)Transparent Service RX Permission \n
                                                            \#DESC_END
                                                            \#GROUP_ID : 0x04\n
                                                            \#KEY_ID : 0x17 \n
                                                	    */
                                                	     
    BLE_CFG_KEY_SLAVE_ADV_POLICY                = 0x18, /**<\#PARAM_NAME : BLE_CFG_KEY_SLAVE_ADV_POLICY \n
                                                            \#PARAM_TYPE : Public \n
                                                            \#GROUP_ID : 0x04\n
                                                            \#KEY_ID : 0x18 \n
                                                            \par
                                                    	    \#BIT_PARAM : STEREO_MODE_SLAVE_ADV_POLICY \n
                                                    	    \#BIT_ALIAS : ADV Policy in Stereo Slave.\n
                                                    	    \#BIT_POS : 0 \n
                                                    	    \#BIT_SIZE : 4 \n
                                                    	    \#BIT_DESC : The Advertising policy for the Stereo Mode Slave. \n
                                                                        0000 - Disable (No BLE Advertising in TWS Slave) \n
                                                                        0001 - Non-Connectable Advertising in TWS Slave \n
                                                                        0010 - Scannable Advertising in TWS Slave \n
                                                                        0011 - Connectable Advertising in TWS Slave \n
                                                    	    \#DESC_END  \n
                                                            \par
                                                    	    \#BIT_PARAM : CONCERT_MODE_SLAVE_ADV_POLICY \n
                                                    	    \#BIT_ALIAS : ADV Policy in Concert Slave.\n
                                                    	    \#BIT_POS : 4 \n
                                                    	    \#BIT_SIZE : 4 \n
                                                    	    \#BIT_DESC : The Advertising policy for the Concert Mode Slave. \n
                                                                        0000 - Disable (No BLE Advertising in Concert Mode Slave) \n
                                                                        0001 - Non-Connectable Advertising in Concert Mode Slave \n
                                                                        0010 - Scannable Advertising in Concert Mode Slave \n
                                                                        0011 - Connectable Advertising in Concert Mode Slave \n
                                                    	    \#DESC_END  \n 

                                                	    */
                                                	     
    BLE_CFG_KEY_MAX_RF_TX_POWER_LEVEL           = 0x19, /**<\#PARAM_NAME : BLE_CFG_KEY_MAX_RF_TX_POWER_LEVEL \n
                                                            \#PARAM_TYPE : Public \n
                                                            \#GROUP_ID : 0x04\n
                                                            \#KEY_ID : 0x19\n
                                                            \par
                                                    	    \#BIT_PARAM : BLE_ADV_RF_TX_POWER_LEVEL \n
                                                    	    \#BIT_ALIAS : Advertising TX Power Level.\n
                                                    	    \#BIT_POS : 0 \n
                                                    	    \#BIT_SIZE : 4 \n
                                                    	    \#BIT_DESC : The ADV TX power level. Level 0 ~ 6 (max) \n
                                                                         The max reference power is 5 dBm and decrease 5 dBm for each following level. \n
                                                                         The actual power is upon calibration in MP process. \n
                                                    	    \#DESC_END  \n
                                                            \par
                                                    	    \#BIT_PARAM : BLE_CONNECTED_RF_TX_POWER_LEVEL \n
                                                    	    \#BIT_ALIAS : Connected TX Power Level.\n
                                                    	    \#BIT_POS : 4 \n
                                                    	    \#BIT_SIZE : 4 \n
                                                    	    \#BIT_DESC : The BLE connected TX power level. Level 0 ~ 6 (max) \n
                                                                         The max reference power is 5 dBm and decrease 5 dBm for each following level. \n
                                                                         The actual power is upon calibration in MP process. \n
                                                    	    \#DESC_END  \n 
                                                	    */
                                                	     

    BLE_CFG_KEY_END       
}BLE_CFG_Key_IdDefinition_T;


/**@defgroup MODULE_BLE_KEY_DEFAULT_VALUE  BLE Configuration Default Value
 * @brief Default value definition of the module @ref CFG_MODULE_ID_BLE.
 * @{ */

 
//Module BLE
#define BLE_CFG_KEY_ADV_DATA_LEN                                0x1C    /**< The default length of @ref BLE_CFG_KEY_ADV_DATA. */
#define BLE_CFG_KEY_ADV_DATA_DEFAULT_VALUE                      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, \
                                                                0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00  /**< The default value of @ref BLE_CFG_KEY_ADV_DATA. */
                                                                //move local name to scan response

#define BLE_CFG_KEY_SCAN_RSP_DATA_LEN                           0x1F    /**< The default length of @ref BLE_CFG_KEY_SCAN_RSP_DATA. */
#define BLE_CFG_KEY_SCAN_RSP_DATA_DEFAULT_VALUE                 0x02, 0x0A, 0x05, 0x0A, 0x09, 0x4D, 0x43, 0x48, 0x50, 0x20, 0x42, 0x4D, 0x38, 0x33, 0x00, 0x00, \
                                                                0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00  /**< The default value of @ref BLE_CFG_KEY_SCAN_RSP_DATA. */

#define BLE_CFG_KEY_AUTO_DISCONNECT_TIME_LEN                    0x01    /**< The default length of @ref BLE_CFG_KEY_AUTO_DISCONNECT_TIME. */
#define BLE_CFG_KEY_AUTO_DISCONNECT_TIME_DEFAULT_VALUE          0x00    /**< The default value of @ref BLE_CFG_KEY_AUTO_DISCONNECT_TIME. */

#define BLE_CFG_KEY_FAST_ADV_TIMEOUT_LEN                        0x01    /**< The default length of @ref BLE_CFG_KEY_FAST_ADV_TIMEOUT. */
#define BLE_CFG_KEY_FAST_ADV_TIMEOUT_DEFAULT_VALUE              0x03    /**< The default value of @ref BLE_CFG_KEY_FAST_ADV_TIMEOUT. */

#define BLE_CFG_KEY_REDUCED_POWER_ADV_TIMEOUT_LEN               0x01    /**< The default length of @ref BLE_CFG_KEY_REDUCED_POWER_ADV_TIMEOUT. */
#define BLE_CFG_KEY_REDUCED_POWER_ADV_TIMEOUT_DEFAULT_VALUE     0x00    /**< The default value of @ref BLE_CFG_KEY_REDUCED_POWER_ADV_TIMEOUT. */

#define BLE_CFG_KEY_REDUCED_POWER_ADV_INTERVAL_LEN              0x02    /**< The default length of @ref BLE_CFG_KEY_REDUCED_POWER_ADV_INTERVAL. */
#define BLE_CFG_KEY_REDUCED_POWER_ADV_INTERVAL_DEFAULT_VALUE    0x06, 0x64    /**< The default value of @ref BLE_CFG_KEY_REDUCED_POWER_ADV_INTERVAL. */

#define BLE_CFG_KEY_CONNECTION_INTERVAL_MIN_LEN                 0x02    /**< The default length of @ref BLE_CFG_KEY_CONNECTION_INTERVAL_MIN. */
#define BLE_CFG_KEY_CONNECTION_INTERVAL_MIN_DEFAULT_VALUE       0x00, 0x00    /**< The default value of @ref BLE_CFG_KEY_CONNECTION_INTERVAL_MIN. */

#define BLE_CFG_KEY_CONNECTION_INTERVAL_MAX_LEN                 0x02    /**< The default length of @ref BLE_CFG_KEY_CONNECTION_INTERVAL_MAX. */
#define BLE_CFG_KEY_CONNECTION_INTERVAL_MAX_DEFAULT_VALUE       0x00, 0x00    /**< The default value of @ref BLE_CFG_KEY_CONNECTION_INTERVAL_MAX. */

#define BLE_CFG_KEY_SLAVE_LATENCY_LEN                           0x02    /**< The default length of @ref BLE_CFG_KEY_SLAVE_LATENCY. */
#define BLE_CFG_KEY_SLAVE_LATENCY_DEFAULT_VALUE                 0x00, 0x00    /**< The default value of @ref BLE_CFG_KEY_SLAVE_LATENCY. */

#define BLE_CFG_KEY_SUPERVISION_TIMEOUT_LEN                     0x02    /**< The default length of @ref BLE_CFG_KEY_SUPERVISION_TIMEOUT. */
#define BLE_CFG_KEY_SUPERVISION_TIMEOUT_DEFAULT_VALUE           0x00, 0x00    /**< The default value of @ref BLE_CFG_KEY_SUPERVISION_TIMEOUT. */

#define BLE_CFG_KEY_ADV_FLAG_LEN                                0x01    /**< The default length of @ref BLE_CFG_KEY_ADV_FLAG. */
#define BLE_CFG_KEY_ADV_FLAG_DEFAULT_VALUE                      0x1A    /**< The default value of @ref BLE_CFG_KEY_ADV_FLAG. */

#define BLE_CFG_KEY_BLE_OPTION_LEN                              0x01    /**< The default length of @ref BLE_CFG_KEY_BLE_OPTION. */
#define BLE_CFG_KEY_BLE_OPTION_DEFAULT_VALUE                    0x0D    /**< The default value of @ref BLE_CFG_KEY_BLE_OPTION. */

#define BLE_CFG_KEY_TRANSPARENT_SRV_UUID_LEN                    0x10    /**< The default length of @ref BLE_CFG_KEY_TRANSPARENT_SRV_UUID. */
#define BLE_CFG_KEY_TRANSPARENT_SRV_UUID_DEFAULT_VALUE          0x55, 0xE4, 0x05, 0xD2, 0xAF, 0x9F, 0xA9, 0x8F, 0xE5, 0x4A, 0x7D, 0xFE, 0x43, 0x53, 0x53, 0x49    /**< The default value of @ref BLE_CFG_KEY_TRANSPARENT_SRV_UUID. */

#define BLE_CFG_KEY_TRANSPARENT_TX_UUID_LEN                     0x10    /**< The default length of @ref BLE_CFG_KEY_TRANSPARENT_TX_UUID. */
#define BLE_CFG_KEY_TRANSPARENT_TX_UUID_DEFAULT_VALUE           0x16, 0x96, 0x24, 0x47, 0xC6, 0x23, 0x61, 0xBA, 0xD9, 0x4B, 0x4D, 0x1E, 0x43, 0x53, 0x53, 0x49    /**< The default value of @ref BLE_CFG_KEY_TRANSPARENT_TX_UUID. */

#define BLE_CFG_KEY_TRANSPARENT_RX_UUID_LEN                     0x10    /**< The default length of @ref BLE_CFG_KEY_TRANSPARENT_RX_UUID. */
#define BLE_CFG_KEY_TRANSPARENT_RX_UUID_DEFAULT_VALUE           0xB3, 0x9B, 0x72, 0x34, 0xBE, 0xEC, 0xD4, 0xA8, 0xF4, 0x43, 0x41, 0x88, 0x43, 0x53, 0x53, 0x49    /**< The default value of @ref BLE_CFG_KEY_TRANSPARENT_RX_UUID. */

#define BLE_CFG_KEY_MANUFACTURE_NAME_STRING_LEN                 0x05    /**< The default length of @ref BLE_CFG_KEY_MANUFACTURE_NAME_STRING. */
#define BLE_CFG_KEY_MANUFACTURE_NAME_STRING_DEFAULT_VALUE       0x4D, 0x43, 0x48, 0x50, 0x00   //"MCHP"     /**< The default value of @ref BLE_CFG_KEY_MANUFACTURE_NAME_STRING. */

#define BLE_CFG_KEY_MODEL_NAME_STRING_LEN                       0x05    /**< The default length of @ref BLE_CFG_KEY_MODEL_NAME_STRING. */
#define BLE_CFG_KEY_MODEL_NAME_STRING_DEFAULT_VALUE             0x42, 0x4D, 0x38, 0x33, 0x00 //"BM83"     /**< The default value of @ref BLE_CFG_KEY_MODEL_NAME_STRING. */

#define BLE_CFG_KEY_SERIAL_NUMBER_STRING_LEN                     0x10    /**< The default length of @ref BLE_CFG_KEY_SERIAL_NUMBER_STRING. */
#define BLE_CFG_KEY_SERIAL_NUMBER_STRING_DEFAULT_VALUE           0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00    /**< The default value of @ref BLE_CFG_KEY_SERIAL_NUMBER_STRING. */

#define BLE_CFG_KEY_SOFTWARE_REVISION_STRING_LEN                0x10    /**< The default length of @ref BLE_CFG_KEY_SOFTWARE_REVISION_STRING. */
#define BLE_CFG_KEY_SOFTWARE_REVISION_STRING_DEFAULT_VALUE      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00    /**< The default value of @ref BLE_CFG_KEY_SOFTWARE_REVISION_STRING. */

#define BLE_CFG_KEY_TRANSPARENT_SRV_TX_PROPERTY_LEN             0x01    /**< The default length of @ref BLE_CFG_KEY_TRANSPARENT_SRV_TX_PROPERTY. */
#define BLE_CFG_KEY_TRANSPARENT_SRV_TX_PROPERTY_DEFAULT_VALUE   0x10    /**< The default value of @ref BLE_CFG_KEY_TRANSPARENT_SRV_TX_PROPERTY. */

#define BLE_CFG_KEY_TRANSPARENT_SRV_RX_PROPERTY_LEN             0x01    /**< The default length of @ref BLE_CFG_KEY_TRANSPARENT_SRV_RX_PROPERTY. */
#define BLE_CFG_KEY_TRANSPARENT_SRV_RX_PROPERTY_DEFAULT_VALUE   0x08    /**< The default value of @ref BLE_CFG_KEY_TRANSPARENT_SRV_RX_PROPERTY. */

#define BLE_CFG_KEY_TRANSPARENT_SRV_TX_PERMISSION_LEN           0x01    /**< The default length of @ref BLE_CFG_KEY_TRANSPARENT_SRV_TX_PERMISSION. */
#define BLE_CFG_KEY_TRANSPARENT_SRV_TX_PERMISSION_DEFAULT_VALUE 0x00    /**< The default value of @ref BLE_CFG_KEY_TRANSPARENT_SRV_TX_PERMISSION. */

#define BLE_CFG_KEY_TRANSPARENT_SRV_RX_PERMISSION_LEN           0x01    /**< The default length of @ref BLE_CFG_KEY_TRANSPARENT_SRV_RX_PERMISSION. */
#define BLE_CFG_KEY_TRANSPARENT_SRV_RX_PERMISSION_DEFAULT_VALUE 0x00    /**< The default value of @ref BLE_CFG_KEY_TRANSPARENT_SRV_RX_PERMISSION. */

#define BLE_CFG_KEY_SLAVE_ADV_POLICY_LEN                        0x01    /**< The default length of @ref BLE_CFG_KEY_SLAVE_ADV_POLICY. */
#define BLE_CFG_KEY_SLAVE_ADV_POLICY_DEFAULT_VALUE              0x33    /**< The default value of @ref BLE_CFG_KEY_SLAVE_ADV_POLICY. */

#define BLE_CFG_KEY_MAX_RF_TX_POWER_LEVEL_LEN                   0x01    /**< The default length of @ref BLE_CFG_KEY_MAX_RF_TX_POWER_LEVEL. */
#define BLE_CFG_KEY_MAX_RF_TX_POWER_LEVEL_DEFAULT_VALUE         0x66    /**< The default value of @ref BLE_CFG_KEY_MAX_RF_TX_POWER_LEVEL. */


/** @} */
/** @} */

/** \cond NON_DOC */

#define CFG_BLE_MODULE_TOTAL_NUM_KEYS   (BLE_CFG_KEY_END - 1) /**< The total key number of this module. */

#define CFG_BLE_MODULE_TOTAL_SIZE   ((CFG_BLE_MODULE_TOTAL_NUM_KEYS*SIZEOF_CFG_KEY_STRUCT) +        \
                                    BLE_CFG_KEY_ADV_DATA_LEN +                        \
                                    BLE_CFG_KEY_SCAN_RSP_DATA_LEN +                   \
                                    BLE_CFG_KEY_AUTO_DISCONNECT_TIME_LEN +            \
                                    BLE_CFG_KEY_FAST_ADV_TIMEOUT_LEN +                \
                                    BLE_CFG_KEY_REDUCED_POWER_ADV_TIMEOUT_LEN +       \
                                    BLE_CFG_KEY_REDUCED_POWER_ADV_INTERVAL_LEN +      \
                                    BLE_CFG_KEY_CONNECTION_INTERVAL_MIN_LEN +         \
                                    BLE_CFG_KEY_CONNECTION_INTERVAL_MAX_LEN +         \
                                    BLE_CFG_KEY_SLAVE_LATENCY_LEN +                   \
                                    BLE_CFG_KEY_SUPERVISION_TIMEOUT_LEN +             \
                                    BLE_CFG_KEY_ADV_FLAG_LEN +                        \
                                    BLE_CFG_KEY_BLE_OPTION_LEN +                      \
                                    BLE_CFG_KEY_TRANSPARENT_SRV_UUID_LEN +            \
                                    BLE_CFG_KEY_TRANSPARENT_TX_UUID_LEN +             \
                                    BLE_CFG_KEY_TRANSPARENT_RX_UUID_LEN +             \
                                    BLE_CFG_KEY_MANUFACTURE_NAME_STRING_LEN +         \
                                    BLE_CFG_KEY_MODEL_NAME_STRING_LEN +               \
                                    BLE_CFG_KEY_SERIAL_NUMBER_STRING_LEN +             \
                                    BLE_CFG_KEY_SOFTWARE_REVISION_STRING_LEN +        \
                                    BLE_CFG_KEY_TRANSPARENT_SRV_TX_PROPERTY_LEN +     \
                                    BLE_CFG_KEY_TRANSPARENT_SRV_RX_PROPERTY_LEN +     \
                                    BLE_CFG_KEY_TRANSPARENT_SRV_TX_PERMISSION_LEN +   \
                                    BLE_CFG_KEY_TRANSPARENT_SRV_RX_PERMISSION_LEN +   \
                                    BLE_CFG_KEY_SLAVE_ADV_POLICY_LEN +                \
                                    BLE_CFG_KEY_MAX_RF_TX_POWER_LEVEL_LEN)

//BLE Config keys definition
#define CFG_BLE_MODULE_DEFAULT_VALUE    CFG_MODULE_ID_BLE,               /*moduleID*/   \
                                        CFG_BLE_MODULE_TOTAL_NUM_KEYS,   /*numKeys*/    \
                                        (CFG_BLE_MODULE_TOTAL_SIZE >> 8),  /*moduleSize*/  \
                                        CFG_BLE_MODULE_TOTAL_SIZE,                      \
                                        /*CFG_KEYs[numKeys]*/                           \
                                        /*    //ID                                                                  //Len                                                                                    //Value    */                                      \
                                        BLE_CFG_KEY_ADV_DATA,                        BLE_CFG_KEY_ADV_DATA_LEN,                       BLE_CFG_KEY_ADV_DATA_DEFAULT_VALUE,                         \
                                        BLE_CFG_KEY_SCAN_RSP_DATA,                   BLE_CFG_KEY_SCAN_RSP_DATA_LEN,                  BLE_CFG_KEY_SCAN_RSP_DATA_DEFAULT_VALUE,                    \
                                        BLE_CFG_KEY_AUTO_DISCONNECT_TIME,            BLE_CFG_KEY_AUTO_DISCONNECT_TIME_LEN,           BLE_CFG_KEY_AUTO_DISCONNECT_TIME_DEFAULT_VALUE,             \
                                        BLE_CFG_KEY_FAST_ADV_TIMEOUT,                BLE_CFG_KEY_FAST_ADV_TIMEOUT_LEN,               BLE_CFG_KEY_FAST_ADV_TIMEOUT_DEFAULT_VALUE,                 \
                                        BLE_CFG_KEY_REDUCED_POWER_ADV_TIMEOUT,       BLE_CFG_KEY_REDUCED_POWER_ADV_TIMEOUT_LEN,      BLE_CFG_KEY_REDUCED_POWER_ADV_TIMEOUT_DEFAULT_VALUE,        \
                                        BLE_CFG_KEY_REDUCED_POWER_ADV_INTERVAL,      BLE_CFG_KEY_REDUCED_POWER_ADV_INTERVAL_LEN,     BLE_CFG_KEY_REDUCED_POWER_ADV_INTERVAL_DEFAULT_VALUE,       \
                                        BLE_CFG_KEY_CONNECTION_INTERVAL_MIN,         BLE_CFG_KEY_CONNECTION_INTERVAL_MIN_LEN,        BLE_CFG_KEY_CONNECTION_INTERVAL_MIN_DEFAULT_VALUE,          \
                                        BLE_CFG_KEY_CONNECTION_INTERVAL_MAX,         BLE_CFG_KEY_CONNECTION_INTERVAL_MAX_LEN,        BLE_CFG_KEY_CONNECTION_INTERVAL_MAX_DEFAULT_VALUE,          \
                                        BLE_CFG_KEY_SLAVE_LATENCY,                   BLE_CFG_KEY_SLAVE_LATENCY_LEN,                  BLE_CFG_KEY_SLAVE_LATENCY_DEFAULT_VALUE,                    \
                                        BLE_CFG_KEY_SUPERVISION_TIMEOUT,             BLE_CFG_KEY_SUPERVISION_TIMEOUT_LEN,            BLE_CFG_KEY_SUPERVISION_TIMEOUT_DEFAULT_VALUE,              \
                                        BLE_CFG_KEY_ADV_FLAG,                        BLE_CFG_KEY_ADV_FLAG_LEN,                       BLE_CFG_KEY_ADV_FLAG_DEFAULT_VALUE,                         \
                                        BLE_CFG_KEY_BLE_OPTION,                      BLE_CFG_KEY_BLE_OPTION_LEN,                     BLE_CFG_KEY_BLE_OPTION_DEFAULT_VALUE,                       \
                                        BLE_CFG_KEY_TRANSPARENT_SRV_UUID,            BLE_CFG_KEY_TRANSPARENT_SRV_UUID_LEN,           BLE_CFG_KEY_TRANSPARENT_SRV_UUID_DEFAULT_VALUE,             \
                                        BLE_CFG_KEY_TRANSPARENT_TX_UUID,             BLE_CFG_KEY_TRANSPARENT_TX_UUID_LEN,            BLE_CFG_KEY_TRANSPARENT_TX_UUID_DEFAULT_VALUE,              \
                                        BLE_CFG_KEY_TRANSPARENT_RX_UUID,             BLE_CFG_KEY_TRANSPARENT_RX_UUID_LEN,            BLE_CFG_KEY_TRANSPARENT_RX_UUID_DEFAULT_VALUE,              \
                                        BLE_CFG_KEY_MANUFACTURE_NAME_STRING,         BLE_CFG_KEY_MANUFACTURE_NAME_STRING_LEN,        BLE_CFG_KEY_MANUFACTURE_NAME_STRING_DEFAULT_VALUE,          \
                                        BLE_CFG_KEY_MODEL_NAME_STRING,               BLE_CFG_KEY_MODEL_NAME_STRING_LEN,              BLE_CFG_KEY_MODEL_NAME_STRING_DEFAULT_VALUE,                \
                                        BLE_CFG_KEY_SERIAL_NUMBER_STRING,             BLE_CFG_KEY_SERIAL_NUMBER_STRING_LEN,            BLE_CFG_KEY_SERIAL_NUMBER_STRING_DEFAULT_VALUE,              \
                                        BLE_CFG_KEY_SOFTWARE_REVISION_STRING,        BLE_CFG_KEY_SOFTWARE_REVISION_STRING_LEN,       BLE_CFG_KEY_SOFTWARE_REVISION_STRING_DEFAULT_VALUE,         \
                                        BLE_CFG_KEY_TRANSPARENT_SRV_TX_PROPERTY,     BLE_CFG_KEY_TRANSPARENT_SRV_TX_PROPERTY_LEN,    BLE_CFG_KEY_TRANSPARENT_SRV_TX_PROPERTY_DEFAULT_VALUE,      \
                                        BLE_CFG_KEY_TRANSPARENT_SRV_RX_PROPERTY,     BLE_CFG_KEY_TRANSPARENT_SRV_RX_PROPERTY_LEN,    BLE_CFG_KEY_TRANSPARENT_SRV_RX_PROPERTY_DEFAULT_VALUE,      \
                                        BLE_CFG_KEY_TRANSPARENT_SRV_TX_PERMISSION,   BLE_CFG_KEY_TRANSPARENT_SRV_TX_PERMISSION_LEN,  BLE_CFG_KEY_TRANSPARENT_SRV_TX_PERMISSION_DEFAULT_VALUE,    \
                                        BLE_CFG_KEY_TRANSPARENT_SRV_RX_PERMISSION,   BLE_CFG_KEY_TRANSPARENT_SRV_RX_PERMISSION_LEN,  BLE_CFG_KEY_TRANSPARENT_SRV_RX_PERMISSION_DEFAULT_VALUE,    \
                                        BLE_CFG_KEY_SLAVE_ADV_POLICY,                BLE_CFG_KEY_SLAVE_ADV_POLICY_LEN,               BLE_CFG_KEY_SLAVE_ADV_POLICY_DEFAULT_VALUE,                 \
                                        BLE_CFG_KEY_MAX_RF_TX_POWER_LEVEL,           BLE_CFG_KEY_MAX_RF_TX_POWER_LEVEL_LEN,          BLE_CFG_KEY_MAX_RF_TX_POWER_LEVEL_DEFAULT_VALUE

void APP_CFG_ReadBleMaxRfTxPowerLevel(uint8_t XDATA *p_connectedPowerLevel, uint8_t XDATA *p_advPowerLevel) large;
void APP_CFG_ReadBleMaxConnInterVal(uint8_t XDATA *p_maxConnInterval) large;
void APP_CFG_ReadBleMinConnInterVal(uint8_t XDATA *p_minConnInterval) large;
void APP_CFG_ReadBleSlaveLatency(uint8_t XDATA *p_slaveLatency) large;
void APP_CFG_ReadBleSupervisionTo(uint8_t XDATA *p_supervisionTo) large;
void APP_CFG_ReadBleManufactureName(uint8_t XDATA *p_manuName, uint8_t XDATA *p_len) large;
void APP_CFG_ReadBleModelName(uint8_t XDATA *p_modelName, uint8_t XDATA *p_len) large;
void APP_CFG_ReadBleSerialNumber(uint8_t XDATA *p_serialNum, uint8_t XDATA *p_len) large;
void APP_CFG_ReadBleSoftwareRevision(uint8_t XDATA *p_softwareRev, uint8_t XDATA *p_len) large;
void APP_CFG_ReadBleTrsSrvUuid(uint8_t XDATA *p_Uuid) large;
void APP_CFG_ReadBleTrsTxUuid(uint8_t XDATA *p_Uuid) large;
void APP_CFG_ReadBleTrsRxUuid(uint8_t XDATA *p_Uuid) large;

/// \endcond

#endif//APP_CFG_BLE_H

