/********************************************************************
  File Information:
    FileName:       app_cfg_common.h
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
	
#ifndef APP_CFG_COMMON_H
#define APP_CFG_COMMON_H
    
#include "app_common.h"
#include "App_cfg_system.h"
#include "App_cfg_bt.h"
#include "App_cfg_audio_mcu.h"
#include "App_cfg_ble.h"
#include "App_cfg_power.h"
#include "App_cfg_led.h"
#include "App_cfg_tone.h"
#include "App_cfg_btn_gpio.h"
#include "App_cfg_mspk.h"
#include "App_cfg_iap.h"
#include "App_cfg_dsp.h"
#include "cfg_service.h"    


/**
  @addtogroup MODULE_CFG_COMMON   Common Configuration
  @{
  @brief Enumeration of configuration module ID.
 */
typedef enum _APP_CFG_ModuleID_T
{
    CFG_MODULE_ID_SYSTEM    = 0x01, /**< The Configuration Module Id of SYSTEM. */
    CFG_MODULE_ID_BT        = 0x02, /**< The Configuration Module Id of BT. */
    CFG_MODULE_ID_AUD_MCU   = 0x03, /**< The Configuration Module Id of AUD_MCU. */
    CFG_MODULE_ID_BLE       = 0x04, /**< The Configuration Module Id of BLE. */
    CFG_MODULE_ID_POWER     = 0x05, /**< The Configuration Module Id of POWER. */
    CFG_MODULE_ID_LED       = 0x06, /**< The Configuration Module Id of LED. */
    CFG_MODULE_ID_TONE      = 0x07, /**< The Configuration Module Id of TONE. */
    CFG_MODULE_ID_RESERVED  = 0x08, /**< The Configuration Module Id of RESERVED. */
    CFG_MODULE_ID_BTN_GPIO  = 0x09, /**< The Configuration Module Id of BTN_GPIO. */
    CFG_MODULE_ID_MSPK      = 0x0A, /**< The Configuration Module Id of MSPK. */
    CFG_MODULE_ID_IAP       = 0x0B, /**< The Configuration Module Id of IAP. */
    CFG_MODULE_ID_AUD_DSP   = 0x0C, /**< The Configuration Module Id of AUD_DSP. */
    CFG_MODULE_ID_VOICE_DSP = 0x0D, /**< The Configuration Module Id of VOICE_DSP. */
    CFG_MODULE_ID_I2S_DSP   = 0x0E, /**< The Configuration Module Id of I2S_DSP. */

    CFG_MODULE_ID_END        
}APP_CFG_ModuleID_T;

/** @} */

/** \cond NON_DOC */

#define CFG_TOTAL_NUM_MODULES       (CFG_MODULE_ID_END  - 1)
    
#define TOTAL_CONFIG_PARAM_LEN  ((CFG_TOTAL_NUM_MODULES * SIZEOF_CFG_MODULE_STRUCT) +    \    
                                CFG_SYS_MODULE_TOTAL_SIZE +         \
                                CFG_BT_MODULE_TOTAL_SIZE +          \
                                CFG_AUD_MCU_MODULE_TOTAL_SIZE +     \
                                CFG_BLE_MODULE_TOTAL_SIZE +         \
                                CFG_POWER_MODULE_TOTAL_SIZE +       \
                                CFG_LED_MODULE_TOTAL_SIZE +         \
                                CFG_TONE_MODULE_TOTAL_SIZE +        \
                                CFG_BTN_GPIO_MODULE_TOTAL_SIZE +    \
                                CFG_MSPK_MODULE_TOTAL_SIZE +        \
                                CFG_IAP_MODULE_TOTAL_SIZE +         \
                                CFG_AUD_DSP_MODULE_TOTAL_SIZE +     \
                                CFG_VOICE_DSP_MODULE_TOTAL_SIZE +   \
                                CFG_I2S_DSP_MODULE_TOTAL_SIZE)

#define APP_CFG_DEFAULT_TABLE \
    TOTAL_CONFIG_PARAM_LEN,/*totalLen;*/    \
    CFG_TOTAL_NUM_MODULES,/*numModules;*/    \
    {\
        CFG_SYS_MODULE_DEFAULT_VALUE,\
        CFG_BT_MODULE_DEFAULT_VALUE,\
        CFG_AUD_MCU_MODULE_DEFAULT_VALUE,\
        CFG_BLE_MODULE_DEFAULT_VALUE,\
        CFG_POWER_MODULE_DEFAULT_VALUE,\
        CFG_LED_MODULE_DEFAULT_VALUE,\
        CFG_TONE_MODULE_DEFAULT_VALUE,\
        CFG_BTN_GPIO_MODULE_DEFAULT_VALUE,\
        CFG_MSPK_MODULE_DEFAULT_VALUE,\
        CFG_IAP_MODULE_DEFAULT_VALUE,\
        CFG_AUD_DSP_MODULE_DEFAULT_VALUE,\
        CFG_VOICE_DSP_MODULE_DEFAULT_VALUE,\
        CFG_I2S_DSP_MODULE_DEFAULT_VALUE\
    }
		
/* This structure is re-created from CFG_SRV_CfgData_T, to create the MCODE CFG Data */
typedef struct _APP_CFG_CfgData_MCODE_T
{
    uint16_t        totalLen;                // does not include 2bytes for "total_len"
    uint8_t        numModules;
    uint8_t        cfgModules[TOTAL_CONFIG_PARAM_LEN];            // type case to CFG_SRV_CfgModule_T
} APP_CFG_CfgData_MCODE_T;

/// \endcond
#endif    //APP_CFG_COMMON_H


