/********************************************************************
  File Information:
    FileName:       app_cfg_iap.h
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

#ifndef APP_CFG_IAP_H
#define APP_CFG_IAP_H

/** \cond NON_DOC 

\#BUILD_TARGET : MSPKv2_App_Basic
\#BUILD_TARGET : MSPKv2_PBAP
\#BUILD_TARGET : MSPKv2_GFP
\#BUILD_TARGET : AT_App
\#TARGET_START

\#REMOVE_PARAM : IAP_CFG_KEY_BONDLESEEDIDPREFTOKEN
\#REMOVE_PARAM : IAP_CFG_KEY_SDKPROTOCOLTOKEN
\#REMOVE_PARAM : IAP_CFG_KEY_APPBUNDLE_ID
\#REMOVE_PARAM : IAP_CFG_KEY_ACC_NAME
\#REMOVE_PARAM : IAP_CFG_KEY_ACC_FW_VER
\#REMOVE_PARAM : IAP_CFG_KEY_ACC_HW_VER
\#REMOVE_PARAM : IAP_CFG_KEY_ACC_MANU
\#REMOVE_PARAM : IAP_CFG_KEY_ACC_MODEL_NUM
\#REMOVE_PARAM : IAP_CFG_KEY_ACC_SERIAL_NUM
\#REMOVE_PARAM : IAP_CFG_KEY_SDKPROTOCOLTOKEN2
\#REMOVE_PARAM : IAP_CFG_KEY_OPTION
\#REMOVE_BIT : iAP_AUTO_LAUNCH_APP_ENABLE

\#TARGET_END

\#BUILD_TARGET : MSPKv2_SPP
\#TARGET_START

\#TARGET_END

\endcond
*/

/**
  @addtogroup APP_CFG_IAP IAP Configuration
  @{
  @brief Definitions and prototypes for the IAP Configuration.
 */



/**
 * @brief Configuration key definition of the module @ref CFG_MODULE_ID_IAP.
 *
 */ 


//Config Key definiton of MODULE_IAP(0x0B)
typedef enum _IAP_CFG_Key_IdDefinition_T
{
    IAP_CFG_KEY_BONDLESEEDIDPREFTOKEN   = 0x01,  /**<\#PARAM_NAME : IAP_CFG_KEY_BONDLESEEDIDPREFTOKEN \n
                                                     \#ALIAS : Bundle Seed ID Pref Token \n
                                                     \#PARAM_TYPE : Public \n
                                                     \#PARAM_DESC : This string identifies the accessory’s preferred application. \n
                                                     \#DESC_END
                                                     \#GROUP_ID : 0x0B \n
                                                     \#KEY_ID : 0x01 \n
                                            	 */
                                                  
    IAP_CFG_KEY_SDKPROTOCOLTOKEN        = 0x02,  /**<\#PARAM_NAME : IAP_CFG_KEY_SDKPROTOCOLTOKEN \n
                                                     \#ALIAS : SDK Protocol Token \n
                                                     \#PARAM_TYPE : Public \n
                                                     \#PARAM_DESC : This information is used to establish communication channels to the application.\n
                                                     \#DESC_END
                                                     \#GROUP_ID : 0x0B \n
                                                     \#KEY_ID : 0x02 \n
                                            	 */
                                                  
    IAP_CFG_KEY_APPBUNDLE_ID            = 0x03,  /**<\#PARAM_NAME : IAP_CFG_KEY_APPBUNDLE_ID \n
                                                     \#ALIAS : APP Bundle ID \n
                                                     \#PARAM_TYPE : Public \n
                                                     \#PARAM_DESC : The accessory sends this command to an iPod to request that it launch a specific application. The accessory passes an Application Bundle ID string,\n
                                                                    such as 'com.mycompany.myapp', to specify which application to launch.\n
                                                     \#DESC_END
                                                     \#GROUP_ID : 0x0B \n
                                                     \#KEY_ID : 0x03 \n
                                            	 */
                                                  
    IAP_CFG_KEY_ACC_NAME                = 0x04,  /**<\#PARAM_NAME : IAP_CFG_KEY_ACC_NAME \n
                                                     \#ALIAS : Accessory Name \n
                                                     \#PARAM_TYPE : Public \n
                                                     \#PARAM_DESC : Accessory name(in ASCII). \n
                                                     \#DESC_END
                                                     \#GROUP_ID : 0x0B \n
                                                     \#KEY_ID : 0x04 \n
                                            	 */
                                                  
    IAP_CFG_KEY_ACC_FW_VER              = 0x05,  /**<\#PARAM_NAME : IAP_CFG_KEY_ACC_FW_VER \n
                                                     \#ALIAS : Accessory Firmware Version \n
                                                     \#PARAM_TYPE : Public \n
                                                     \#PARAM_DESC : Accessory firmware version. \n
                                                     \#DESC_END
                                                     \#GROUP_ID : 0x0B \n
                                                     \#KEY_ID : 0x05 \n
                                            	 */
                                                  
    IAP_CFG_KEY_ACC_HW_VER              = 0x06,  /**<\#PARAM_NAME : IAP_CFG_KEY_ACC_HW_VER \n
                                                     \#ALIAS : Accessory Hardware Version \n
                                                     \#PARAM_TYPE : Public \n
                                                     \#PARAM_DESC : Accessory hardware version. \n
                                                     \#DESC_END
                                                     \#GROUP_ID : 0x0B \n
                                                     \#KEY_ID : 0x06 \n
                                            	 */
                                                  
    IAP_CFG_KEY_ACC_MANU                = 0x07,  /**<\#PARAM_NAME : IAP_CFG_KEY_ACC_MANU \n
                                                     \#ALIAS : Accessory Manufacturer \n
                                                     \#PARAM_TYPE : Public \n
                                                     \#PARAM_DESC : Accessory manufacturer(in ASCII). \n
                                                     \#DESC_END
                                                     \#GROUP_ID : 0x0B \n
                                                     \#KEY_ID : 0x07 \n
                                            	 */
                                                  
    IAP_CFG_KEY_ACC_MODEL_NUM           = 0x08,  /**<\#PARAM_NAME : IAP_CFG_KEY_ACC_MODEL_NUM \n
                                                     \#ALIAS : Accessory Model Number \n
                                                     \#PARAM_TYPE : Public \n
                                                     \#PARAM_DESC : Accessory model number(in ASCII). \n
                                                     \#DESC_END
                                                     \#GROUP_ID : 0x0B \n
                                                     \#KEY_ID : 0x08 \n
                                            	 */
                                                  
    IAP_CFG_KEY_ACC_SERIAL_NUM          = 0x09,  /**<\#PARAM_NAME : IAP_CFG_KEY_ACC_SERIAL_NUM \n
                                                     \#ALIAS : Accessory Serial Number \n
                                                     \#PARAM_TYPE : Public \n
                                                     \#PARAM_DESC : Accessory serial number(in ASCII). \n
                                                     \#DESC_END
                                                     \#GROUP_ID : 0x0B \n
                                                     \#KEY_ID : 0x09 \n
                                            	 */
                                                  
    IAP_CFG_KEY_SDKPROTOCOLTOKEN2       = 0x0A,  /**<\#PARAM_NAME : IAP_CFG_KEY_SDKPROTOCOLTOKEN2 \n
                                                     \#ALIAS : SDK Protocol Token2 \n
                                                     \#PARAM_TYPE : Public \n
                                                     \#PARAM_DESC : This information is used to establish communication channels to the application.\n
                                                                    This is for the second data section.\n
                                                     \#DESC_END
                                                     \#GROUP_ID : 0x0B \n
                                                     \#KEY_ID : 0x0A \n
                                            	 */
                                                  
    IAP_CFG_KEY_OPTION                  = 0x0B,  /**<\#PARAM_NAME : IAP_CFG_KEY_OPTION \n
                                                     \#PARAM_TYPE : Public \n
                                                     \#GROUP_ID : 0x0B \n
                                                     \#KEY_ID : 0x0B \n
                                                     Bit Options:
                                            	     \par

                                            	     \#BIT_PARAM : iAP_AUTO_LAUNCH_APP_ENABLE \n
                                            	     \#BIT_ALIAS : Enable Auto Launch APP \n
                                            	     \#BIT_POS : 4 \n
                                            	     \#BIT_SIZE : 1 \n
                                            	     \#BIT_DESC : Enable to send APP launch request to auto lauch APP after identification and authentication process complete. \n
                                            	     \#DESC_END
                                            	 */
                                                  
    IAP_CFG_KEY_END
}IAP_CFG_Key_IdDefinition_T;


/**@defgroup MODULE_IAP_CFG_DEFAULT_VALUE IAP Configuration Default Value
 * @brief Default value definition of the module @ref CFG_MODULE_ID_IAP.
 * @{ */

//Module IAP
#define IAP_CFG_KEY_BONDLESEEDIDPREFTOKEN_LEN           0x0A    /**< The default length of @ref IAP_CFG_KEY_BONDLESEEDIDPREFTOKEN. */
#define IAP_CFG_KEY_BONDLESEEDIDPREFTOKEN_DEFAULT_VALUE 0x4d, 0x38, 0x42, 0x5a, 0x32, 0x38, 0x47, 0x53, 0x58, 0x37 /*M8BZ28GSX7*/ /**< The default value of @ref IAP_CFG_KEY_BONDLESEEDIDPREFTOKEN. */

#define IAP_CFG_KEY_SDKPROTOCOLTOKEN_LEN                0x11    /**< The default length of @ref IAP_CFG_KEY_SDKPROTOCOLTOKEN. */
#define IAP_CFG_KEY_SDKPROTOCOLTOKEN_DEFAULT_VALUE      0x63, 0x6f, 0x6d, 0x2e, 0x69, 0x73, 0x73, 0x63, 0x2e, 0x64, 0x61, 0x74, 0x61, 0x70, 0x61, 0x74, 0x68 /*com.issc.datapath*/ /**< The default value of @ref IAP_CFG_KEY_SDKPROTOCOLTOKEN. */

#define IAP_CFG_KEY_APPBUNDLE_ID_LEN                    0x1D    /**< The default length of @ref IAP_CFG_KEY_APPBUNDLE_ID. */
#define IAP_CFG_KEY_APPBUNDLE_ID_DEFAULT_VALUE          0x63, 0x6f, 0x6d, 0x2e, 0x6d, 0x69, 0x63, 0x72, 0x6f, 0x63, 0x68, 0x69, 0x70, 0x2e, 0x42, 0x74, 0x43, 0x68, 0x61, 0x74, 0x2d, 0x44, 0x75, 0x61, 0x6c, 0x4d, 0x6f, 0x64, 0x65 /*com.microchip.BtChat-DualMode*/ /**< The default value of @ref IAP_CFG_KEY_APPBUNDLE_ID. */

#define IAP_CFG_KEY_ACC_NAME_LEN                        0x09    /**< The default length of @ref IAP_CFG_KEY_ACC_NAME. */
#define IAP_CFG_KEY_ACC_NAME_DEFAULT_VALUE              0x43, 0x68, 0x61, 0x74, 0x62, 0x6f, 0x61, 0x72, 0x64 /*Chatboard*/ /**< The default value of @ref IAP_CFG_KEY_ACC_NAME. */

#define IAP_CFG_KEY_ACC_FW_VER_LEN                      0x05    /**< The default length of @ref IAP_CFG_KEY_ACC_FW_VER. */
#define IAP_CFG_KEY_ACC_FW_VER_DEFAULT_VALUE            0x31, 0x2e, 0x30, 0x2e, 0x30 /*1.0.0*/ /**< The default value of @ref IAP_CFG_KEY_ACC_FW_VER. */

#define IAP_CFG_KEY_ACC_HW_VER_LEN                      0x05    /**< The default length of @ref IAP_CFG_KEY_ACC_HW_VER. */
#define IAP_CFG_KEY_ACC_HW_VER_DEFAULT_VALUE            0x31, 0x2e, 0x30, 0x2e, 0x30 /*1.0.0*/ /**< The default value of @ref IAP_CFG_KEY_ACC_HW_VER. */

#define IAP_CFG_KEY_ACC_MANU_LEN                        0x04    /**< The default length of @ref IAP_CFG_KEY_ACC_MANU. */
#define IAP_CFG_KEY_ACC_MANU_DEFAULT_VALUE              0x4d, 0x43, 0x48, 0x50 /*MCHP*/ /**< The default value of @ref IAP_CFG_KEY_ACC_MANU. */

#define IAP_CFG_KEY_ACC_MODEL_NUM_LEN                   0x04    /**< The default length of @ref IAP_CFG_KEY_ACC_MODEL_NUM. */
#define IAP_CFG_KEY_ACC_MODEL_NUM_DEFAULT_VALUE         0x42, 0x4d, 0x38, 0x33 /*BM83*/ /**< The default value of @ref IAP_CFG_KEY_ACC_MODEL_NUM. */

#define IAP_CFG_KEY_ACC_SERIAL_NUM_LEN                  0x02    /**< The default length of @ref IAP_CFG_KEY_ACC_SERIAL_NUM. */
#define IAP_CFG_KEY_ACC_SERIAL_NUM_DEFAULT_VALUE        0x56, 0x32 /*V2*/ /**< The default value of @ref IAP_CFG_KEY_ACC_SERIAL_NUM. */

#define IAP_CFG_KEY_SDKPROTOCOLTOKEN2_LEN               0x12    /**< The default length of @ref IAP_CFG_KEY_SDKPROTOCOLTOKEN2. */
#define IAP_CFG_KEY_SDKPROTOCOLTOKEN2_DEFAULT_VALUE     0x63, 0x6f, 0x6d, 0x2e, 0x69, 0x73, 0x73, 0x63, 0x2e, 0x64, 0x61, 0x74, 0x61, 0x70, 0x61, 0x74, 0x68, 0x32 /*com.issc.datapath2*/ /**< The default value of @ref IAP_CFG_KEY_SDKPROTOCOLTOKEN2. */

#define IAP_CFG_KEY_OPTION_LEN                          0x01    /**< The default length of @ref IAP_CFG_KEY_OPTION. */
#define IAP_CFG_KEY_OPTION_DEFAULT_VALUE                0x09    /**< The default value of @ref IAP_CFG_KEY_OPTION. */

/** @} */
/** @} */

/** \cond NON_DOC */

#define CFG_IAP_MODULE_TOTAL_NUM_KEYS   (IAP_CFG_KEY_END - 1)

#define CFG_IAP_MODULE_TOTAL_SIZE   ((CFG_IAP_MODULE_TOTAL_NUM_KEYS*SIZEOF_CFG_KEY_STRUCT) +   \
                                    IAP_CFG_KEY_BONDLESEEDIDPREFTOKEN_LEN +                 \
                                    IAP_CFG_KEY_SDKPROTOCOLTOKEN_LEN +                      \
                                    IAP_CFG_KEY_APPBUNDLE_ID_LEN +                          \
                                    IAP_CFG_KEY_ACC_NAME_LEN +                              \
                                    IAP_CFG_KEY_ACC_FW_VER_LEN +                            \
                                    IAP_CFG_KEY_ACC_HW_VER_LEN +                            \
                                    IAP_CFG_KEY_ACC_MANU_LEN +                              \
                                    IAP_CFG_KEY_ACC_MODEL_NUM_LEN +                         \
                                    IAP_CFG_KEY_ACC_SERIAL_NUM_LEN +                        \
                                    IAP_CFG_KEY_SDKPROTOCOLTOKEN2_LEN +                     \
                                    IAP_CFG_KEY_OPTION_LEN)


//IAP Config keys definition
#define CFG_IAP_MODULE_DEFAULT_VALUE    CFG_MODULE_ID_IAP,               /*moduleID*/   \
                                        CFG_IAP_MODULE_TOTAL_NUM_KEYS,   /*numKeys*/    \
                                        (CFG_IAP_MODULE_TOTAL_SIZE >> 8),  /*moduleSize*/  \
                                        CFG_IAP_MODULE_TOTAL_SIZE,                      \
                                        /*CFG_KEYs[numKeys]*/                           \
                                        /*    //ID                                                                  //Len                                                                                    //Value    */        \
                                        IAP_CFG_KEY_BONDLESEEDIDPREFTOKEN,   IAP_CFG_KEY_BONDLESEEDIDPREFTOKEN_LEN,  IAP_CFG_KEY_BONDLESEEDIDPREFTOKEN_DEFAULT_VALUE,  \
                                        IAP_CFG_KEY_SDKPROTOCOLTOKEN,        IAP_CFG_KEY_SDKPROTOCOLTOKEN_LEN,       IAP_CFG_KEY_SDKPROTOCOLTOKEN_DEFAULT_VALUE,      \
                                        IAP_CFG_KEY_APPBUNDLE_ID,            IAP_CFG_KEY_APPBUNDLE_ID_LEN,           IAP_CFG_KEY_APPBUNDLE_ID_DEFAULT_VALUE,          \
                                        IAP_CFG_KEY_ACC_NAME,                IAP_CFG_KEY_ACC_NAME_LEN,               IAP_CFG_KEY_ACC_NAME_DEFAULT_VALUE,              \
                                        IAP_CFG_KEY_ACC_FW_VER,              IAP_CFG_KEY_ACC_FW_VER_LEN,             IAP_CFG_KEY_ACC_FW_VER_DEFAULT_VALUE,            \
                                        IAP_CFG_KEY_ACC_HW_VER,              IAP_CFG_KEY_ACC_HW_VER_LEN,             IAP_CFG_KEY_ACC_HW_VER_DEFAULT_VALUE,            \
                                        IAP_CFG_KEY_ACC_MANU,                IAP_CFG_KEY_ACC_MANU_LEN,               IAP_CFG_KEY_ACC_MANU_DEFAULT_VALUE,              \
                                        IAP_CFG_KEY_ACC_MODEL_NUM,           IAP_CFG_KEY_ACC_MODEL_NUM_LEN,          IAP_CFG_KEY_ACC_MODEL_NUM_DEFAULT_VALUE,         \
                                        IAP_CFG_KEY_ACC_SERIAL_NUM,          IAP_CFG_KEY_ACC_SERIAL_NUM_LEN,         IAP_CFG_KEY_ACC_SERIAL_NUM_DEFAULT_VALUE,        \
                                        IAP_CFG_KEY_SDKPROTOCOLTOKEN2,       IAP_CFG_KEY_SDKPROTOCOLTOKEN2_LEN,      IAP_CFG_KEY_SDKPROTOCOLTOKEN2_DEFAULT_VALUE,     \
                                        IAP_CFG_KEY_OPTION,                  IAP_CFG_KEY_OPTION_LEN,                 IAP_CFG_KEY_OPTION_DEFAULT_VALUE            


typedef struct _APP_Cfg_IapOption_T
{
    uint8_t reserved1: 4;
    uint8_t autoLaunchAppEnable: 1;     /**< Enable to send APP launch request to auto lauch APP after identification and authentication process complete. */
    uint8_t reserved2: 3;   
} APP_Cfg_IapOption_T;


void APP_CFG_ReadIap2ConfigData(BT_IAP2_infoConfig_T XDATA *p_cfgData);
void APP_CFG_ReadIap2Option(APP_Cfg_IapOption_T XDATA *p_iap2Option);

/// \endcond

#endif//APP_CFG_IAP_H

