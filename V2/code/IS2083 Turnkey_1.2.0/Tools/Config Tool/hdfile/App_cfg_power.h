/*******************************************************************
  File Information:
    FileName:       app_cfg_power.h
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

#ifndef APP_CFG_POWER_H
#define APP_CFG_POWER_H

/** \cond NON_DOC 

\#BUILD_TARGET : MSPKv2_App_Basic
\#BUILD_TARGET : MSPKv2_GFP
\#BUILD_TARGET : MSPKv2_SPP
\#BUILD_TARGET : MSPKv2_PBAP
\#BUILD_TARGET : AT_App
\#TARGET_START
\#REMOVE_BIT : ENABLE_INTERNAL_USB_CHARGER
\#REMOVE_BIT : CHARGING_WITH_ALL_USB_BC_TYPE
\#REMOVE_PARAM : POWER_CFG_KEY_RECHARGING_BATT_CAPACITY
\#TARGET_END
\endcond
*/

/**
  @addtogroup APP_CFG_POWER POWER Configuration
  @{
  @brief Definitions and prototypes for the POWER Configuration.
 */



/**
 * @brief Configuration key definition of the module @ref CFG_MODULE_ID_POWER.
 *  
 */

//Config Key definiton of MODULE_POWER(0x05)
typedef enum _POWER_CFG_Key_IdDefinition_T
{
    POWER_CFG_KEY_STOP_CHARGING_SAR_MIN                 = 0x01, /**<\#PARAM_NAME : POWER_CFG_KEY_STOP_CHARGING_SAR_MIN \n
                                                                    \#ALIAS : Stop Charging SAR Min \n
                                                                    \#PARAM_TYPE : Public \n
                                                                    \#PARAM_DESC : The minimum SAR value for charger working range. The value represents temperature up to circuit design. \n
                                                                                   Degree: \n
                                                                                   0x00C3: 35 degree C \n
                                                                                   0x00A7: 40 degree C \n
                                                                                   0x0092: 45 degree C \n
                                                                                   0x0082: 50 degree C \n
                                                                                   0x0073: 55 degree C \n
                                                                                   Customize:0000~FFFF \n
                                                                    \#DESC_END
                                                                    \#GROUP_ID : 0x05 \n
                                                                    \#KEY_ID : 0x01 \n
                                                                */
                                                                
    POWER_CFG_KEY_STOP_CHARGING_SAR_MAX                 = 0x02, /**<\#PARAM_NAME : POWER_CFG_KEY_STOP_CHARGING_SAR_MAX \n
                                                                    \#ALIAS : Stop Charging SAR Max \n
                                                                    \#PARAM_TYPE : Public \n
                                                                    \#PARAM_DESC : The maximum SAR value for charger working range. \n
                                                                                   The value represents temperature up to circuit design. \n
                                                                                   Degree:  \n
                                                                                   0x0331: -5 degree C  \n
                                                                                   0x02B0: 0 degree C   \n
                                                                                   0x0239: 5 degree C   \n
                                                                                   0x01D6: 10 degree C  \n
                                                                                   0x0186: 15 degree C  \n
                                                                                   Customize:0000~FFFF  \n
                                                                    \#DESC_END
                                                                    \#GROUP_ID : 0x05 \n
                                                                    \#KEY_ID : 0x02 \n
                                                                */
                                                                
    POWER_CFG_KEY_RESTART_CHARGING_SAR_MIN              = 0x03, /**<\#PARAM_NAME : POWER_CFG_KEY_RESTART_CHARGING_SAR_MIN \n
                                                                    \#ALIAS : Resart Charging SAR Min \n
                                                                    \#PARAM_TYPE : Public \n
                                                                    \#PARAM_DESC : The minimum SAR value of range to restart charging. \n
                                                                                   It is for ambient temperature detection function. If the temperature over working range, \n
                                                                                   it will stop charger and keep detecting the temperature and restart charger when the temperature back to this assigned range . \n
                                                                                   It needs hardware circuit support and translates the temperature to voltage. \n

                                                                                   Degree:  \n
                                                                                   0x00E4: 35 degree C  \n
                                                                                   0x00C3: 40 degree C  \n
                                                                                   0x00A7: 45 degree C  \n
                                                                                   0x0092 50 degree C   \n
                                                                                   0x0082: 55 degree C  \n
                                                                                   Customize:0000~FFFF  \n
                                                                    \#DESC_END
                                                                    \#GROUP_ID : 0x05 \n
                                                                    \#KEY_ID : 0x03 \n
                                                                */
                                                                
    POWER_CFG_KEY_RESTART_CHARGING_SAR_MAX              = 0x04, /**<\#PARAM_NAME : POWER_CFG_KEY_RESTART_CHARGING_SAR_MAX \n
                                                                    \#ALIAS : Resart Charging SAR Max \n
                                                                    \#PARAM_TYPE : Public \n
                                                                    \#PARAM_DESC : The maximum SAR value of range to restart charging. It is for ambient temperature detection function. If the temperature over working range, \n
                                                                                   it will stop charger and keep detecting the temperature and restart charger when the temperature back to this assigned range . \n
                                                                                   It needs hardware circuit support and translates the temperature to voltage. \n
                                                                                    Degree: \n
                                                                                    0x02B0: -5 degree C \n
                                                                                    0x0239: 0 degree C  \n
                                                                                    0x01D6: 5 degree C  \n
                                                                                    0x0186: 10 degree C \n
                                                                                    0x0144: 15 degree C \n
                                                                                    Customize:0000~FFFF \n
                                                                    \#DESC_END
                                                                    \#GROUP_ID : 0x05 \n
                                                                    \#KEY_ID : 0x04 \n
                                                                */
                                                                
    POWER_CFG_KEY_MAX_CV_CHARGING_CURRENT               = 0x05, /**<\#PARAM_NAME : POWER_CFG_KEY_MAX_CV_CHARGING_CURRENT \n
                                                                    \#ALIAS : Maximum CV Charging Current \n
                                                                    \#PARAM_TYPE : Public \n
                                                                    \#PARAM_DESC : Maximum charging current, when cc mode enter to cv mode \n
                                                                                   Unit :mA \n
                                                                                   (100 - Max 350mA) \n
                                                                    \#DESC_END
                                                                    \#GROUP_ID : 0x05 \n
                                                                    \#KEY_ID : 0x05 \n
                                                                */
                                                                
    POWER_CFG_KEY_WARNING_BATTERY_LEVEL                 = 0x06, /**<\#PARAM_NAME : POWER_CFG_KEY_WARNING_BATTERY_LEVEL \n
                                                                    \#ALIAS : Low Battery Warning Level \n
                                                                    \#PARAM_TYPE : Public \n
                                                                    \#PARAM_DESC : 
                                                                                   The lowest voltage level that device can work well,when battery voltage is under this value, \n
                                                                                   device will generate some warning, such as tone, LED and buzzer (if buzzer is enabled). \n
                                                                                   Range:(3V-to-3.6V) or( 3000 to 3600) \n
                                                                                   Unit :Voltage, Size:2bytes \n
                                                                                   3000 (3.0V) \n
                                                                                   3100 (3.1V) \n
                                                                                   3200 (3.2V) \n
                                                                                   3300 (3.3V) \n
                                                                                   3400 (3.4V) \n
                                                                                   3500 (3.5V) \n
                                                                                   3600 (3.6V) \n
                                                                    \#DESC_END
                                                                    \#GROUP_ID : 0x05 \n
                                                                    \#KEY_ID : 0x06 \n
                                                                */
                                                                
    POWER_CFG_KEY_SHUTDOWN_BATTERY_LEVEL                = 0x07, /**<\#PARAM_NAME : POWER_CFG_KEY_SHUTDOWN_BATTERY_LEVEL \n
                                                                    \#ALIAS : Battery Shutdown Level \n
                                                                    \#PARAM_TYPE : Public \n
                                                                    \#PARAM_DESC : 
                                                                                   When the battery voltage level is lower this value, the speaker will shutdown automatically. \n
                                                                                   The value definitionl is the same with Warning_Battery_Level. \n
                                                                                   Range:(3V-to-3.6V) or( 3000 to 3600) \n
                                                                                   Unit :Voltage \n
                                                                                   3000 (3.0V) \n
                                                                                   3100 (3.1V) \n
                                                                                   3200 (3.2V) \n
                                                                                   3300 (3.3V) \n
                                                                                   3400 (3.4V) \n
                                                                                   3500 (3.5V) \n
                                                                                   3600 (3.6V) \n
                                                                    \#DESC_END
                                                                    \#GROUP_ID : 0x05 \n
                                                                    \#KEY_ID : 0x07 \n
                                                                */
                                                                
    POWER_CFG_KEY_CC_SUB_MODE_PROTECT_TIME              = 0x08, /**<\#PARAM_NAME : POWER_CFG_KEY_CC_SUB_MODE_PROTECT_TIME \n
                                                                    \#PARAM_TYPE : Public \n
                                                                    \#GROUP_ID : 0x05\n
                                                                    \#KEY_ID : 0x08 \n
                                                                    \par
                                                    	            \#BYTE_PARAM : FIRST_STAGE_CC_MODE_PROTECT_TIME \n
                                                    	            \#BYTE_ALIAS : 1st Max Charging Time\n
                                                    	            \#BYTE_POS : 0 \n
                                                    	            \#BYTE_SIZE : 1 \n
                                                    	            \#BYTE_DESC : When cc mode over protective time expired, charging will be completed and stop charging. \n
                                                                                  CC Mode protective timer stage 0 (unit in min). Range:0-254 Size 1 byte \n
                                                    	            \#DESC_END  \n

                                                    	            \par
                                                    	            \#BYTE_PARAM : SECOND_STAGE_CC_MODE_PROTECT_TIME \n
                                                    	            \#BYTE_ALIAS : 2nd Max Charging Time\n
                                                    	            \#BYTE_POS : 1 \n
                                                    	            \#BYTE_SIZE : 1 \n
                                                    	            \#BYTE_DESC : When cc mode over protective time expired, charging will be completed and stop charging. \n
                                                                                  CC Mode protective timer stage 1 (unit in min). Range:0-254 Size 1 byte \n
                                                    	            \#DESC_END  \n

                                                    	            \par
                                                    	            \#BYTE_PARAM : THIRD_STAGE_CC_MODE_PROTECT_TIME \n
                                                    	            \#BYTE_ALIAS : 3rd Max Charging Time\n
                                                    	            \#BYTE_POS : 2 \n
                                                    	            \#BYTE_SIZE : 1 \n
                                                    	            \#BYTE_DESC : When cc mode over protective time expired, charging will be completed and stop charging. \n
                                                                                  CC Mode protective timer stage 2 (unit in min). Range:0-254 Size 1 byte \n
                                                    	            \#DESC_END  \n

                                                    	            \par
                                                    	            \#BYTE_PARAM : FOURTH_STAGE_CC_MODE_PROTECT_TIME \n
                                                    	            \#BYTE_ALIAS : 4th Max Charging Time\n
                                                    	            \#BYTE_POS : 3 \n
                                                    	            \#BYTE_SIZE : 1 \n
                                                    	            \#BYTE_DESC : When cc mode over protective time expired, charging will be completed and stop charging. \n
                                                                                  CC Mode protective timer stage 3 (unit in min). Range:0-254 Size 1 byte \n
                                                    	            \#DESC_END  \n
                                                	            */
                                                                
    POWER_CFG_KEY_CV_PROTECT_TIME                       = 0x09, /**<\#PARAM_NAME : POWER_CFG_KEY_CV_PROTECT_TIME \n
                                                                    \#ALIAS : Maximum Charging Time \n
                                                                    \#PARAM_TYPE : Public \n
                                                                    \#PARAM_DESC : Protect time in constant voltage charging mode(unit in min). \n
                                                                    \#DESC_END
                                                                    \#GROUP_ID : 0x05 \n
                                                                    \#KEY_ID : 0x09 \n
                                                                */
                                                                
    POWER_CFG_KEY_OPTION1                               = 0x0A, /**<\#PARAM_NAME : POWER_CFG_KEY_OPTION1 \n
                                                                    \#PARAM_TYPE : Public \n
                                                                    \#GROUP_ID : 0x05 \n
                                                                    \#KEY_ID : 0x0A \n
                                                                    Bit Options:
                                                                	\par
                                                                	\#BIT_PARAM : DEDICATE_CHARGER_LED_ENABLE \n
                                                                	\#BIT_ALIAS : dedicate charger led enable \n
                                                                	\#BIT_POS : 0 \n
                                                                	\#BIT_SIZE : 1 \n
                                                                	\#BIT_DESC : Use GPIO as acive low to indicate charging complete if this option is enabled (set to 1). \n
                                                                	             Please refer to GPIO configuration to check which pin is used. \n
                                                                	\#DESC_END

                                                                	\par
                                                                	\#BIT_PARAM : ENABLE_SHUTDOWN_POWER \n
                                                                	\#BIT_ALIAS : Shut Down Power in Off State \n
                                                                	\#BIT_POS : 1 \n
                                                                	\#BIT_SIZE : 1 \n
                                                                	\#BIT_DESC : Cut off the power when the speaker enter off state if this option is enabled (set to 1) \n
                                                                	\#DESC_END

                                                                	\par
                                                                	\#BIT_PARAM : ENABLE_CHARGER_DETECT \n
                                                                	\#BIT_ALIAS : Charger Detect \n
                                                                	\#BIT_POS : 2 \n
                                                                	\#BIT_SIZE : 1 \n
                                                                	\#BIT_DESC : Enable/disable charger function. \n 
                                                                                 1: enabled, 0: disabled. \n
                                                                	\#DESC_END

                                                                	\par
                                                                	\#BIT_PARAM : ENABLE_BATTERY_VOLTAGE_DETECT \n
                                                                	\#BIT_ALIAS : Battery Detection Enable \n
                                                                	\#BIT_POS : 3 \n
                                                                	\#BIT_SIZE : 1 \n
                                                                	\#BIT_DESC : Enable/Disable polling the battery voltage. \n
                                                                                 1: eanbled, 0:disabled. \n
                                                                	\#DESC_END

                                                                	\par
                                                                	\#BIT_PARAM : CHARGING_DISALLOW_SHS_ACTIVE \n
                                                                	\#BIT_ALIAS : Charging Disallow SHS Active \n
                                                                	\#BIT_POS : 4 \n
                                                                	\#BIT_SIZE : 1 \n
                                                                	\#BIT_DESC : If this option is enabled (set to 1), the speaker will shut down and disallow any operation in charging. \n
                                                                	\#DESC_END

                                                                	\par
                                                                	\#BIT_PARAM : ENABLE_INTERNAL_USB_CHARGER \n
                                                                	\#BIT_ALIAS : Enable Internal USB Charger \n
                                                                	\#BIT_POS : 5 \n
                                                                	\#BIT_SIZE : 1 \n
                                                                	\#BIT_DESC : Internal usb charger \n
                                                                	\#DESC_END

                                                                	\par
                                                                	\#BIT_PARAM : CHARGING_WITH_ALL_USB_BC_TYPE \n
                                                                	\#BIT_ALIAS : Charging With All USB BC Type \n
                                                                	\#BIT_POS : 6 \n
                                                                	\#BIT_SIZE : 1 \n
                                                                	\#BIT_DESC : Enable charger for all USB battery charging type. \n
                                                                	\#DESC_END

                                                                	\par
                                                                	\#BIT_PARAM : ENABLE_AMBIENT_TEMP_AS_CHARGING \n
                                                                	\#BIT_ALIAS : Ambient Temperature Charging Detection \n
                                                                	\#BIT_POS : 7 \n
                                                                	\#BIT_SIZE : 1 \n
                                                                	\#BIT_DESC : Enable ambient temperture detection in charging. \n
                                                                	\#DESC_END
                                                                */
                                                                
    POWER_CFG_KEY_OPTION2                               = 0x0B, /**<\#PARAM_NAME : POWER_CFG_KEY_OPTION2 \n
                                                                    \#PARAM_TYPE : Public \n
                                                                    \#GROUP_ID : 0x05 \n
                                                                    \#KEY_ID : 0x0B \n
                                                                    Bit Options:
                                                                    \par
                                                                    \#BIT_PARAM : ENABLE_LOW_BATTERY_DEBOUNCE \n
                                                                    \#BIT_ALIAS : Low Battery Debounce \n
                                                                    \#BIT_POS : 0 \n
                                                                    \#BIT_SIZE : 1 \n
                                                                    \#BIT_DESC : If this option is set to 1, the low battery warning will keep until power adaptor in or power cycle. \n
                                                                    \#DESC_END

                                                                    \par
                                                                    \#BIT_PARAM : CONTINUE_CHARGING_AS_BATTERY_FULL \n
                                                                    \#BIT_ALIAS : Continue Charging As Battery Full \n
                                                                    \#BIT_POS : 1 \n
                                                                    \#BIT_SIZE : 1 \n
                                                                    \#BIT_DESC : If this option is set to 1,If the Battery detection is enabled in UI and battery voltage drops below 0.1V of the fourth stage of the CC charging,\n
                                                                                 the charging will restart based on UI parameter “Restart charging”. \n
                                                                                 (E.g.: If battery charging successful at 4.2V  then re-charging will start when the battery voltage drops to 4.1V). \n
                                                                    \#DESC_END

                                                                    \par
                                                                    \#BIT_PARAM : ENABLE_AMBIENTEMP_FOR_OPERATING \n
                                                                    \#BIT_ALIAS : Working Temperature \n
                                                                    \#BIT_POS : 2 \n
                                                                    \#BIT_SIZE : 1 \n
                                                                    \#BIT_DESC : If this option is set to 1: \n
                                                                                 In operation mode: Once the ambient temperature is out of working temperature range,app code will process power off procedure. \n
                                                                                 In power off mode: If the ambient temperature is out of working temperature range, product powered on. \n
                                                                    \#DESC_END

                                                                    \par
                                                                    \#BIT_PARAM : reserved \n
                                                                    \#BIT_ALIAS :  reserved \n
                                                                    \#BIT_POS : 3 \n
                                                                    \#BIT_SIZE : 5 \n
                                                                    \#BIT_DESC : reserved \n
                                                                    \#DESC_END

                                                                */
                                                                
    POWER_CFG_KEY_RECHARGING_BATT_CAPACITY              = 0x0C, /**<\#PARAM_NAME : POWER_CFG_KEY_RECHARGING_BATT_CAPACITY \n
                                                                    \#ALIAS : Power Recharging Batt Capacity \n
                                                                    \#PARAM_TYPE : Public \n
                                                                    \#PARAM_DESC : When battery less than this threshold(unit in %) and adaptor in, it will restart charging. \n
                                                                                   It is used for the scenario that MCU report battery level percentage to BM83. \n
                                                                                   This feature is only for external charger and not implement here. \n
                                                                    \#DESC_END
                                                                    \#GROUP_ID : 0x05 \n
                                                                    \#KEY_ID : 0x0C \n
                                                                */
                                                                
    POWER_CFG_KEY_VOLTAGE_LEVELS                        = 0x0D, /**<\#PARAM_NAME : POWER_CFG_KEY_VOLTAGE_LEVELS \n
                                                                    \#PARAM_TYPE : Public \n
                                                                    \#GROUP_ID : 0x05 \n
                                                                    \#KEY_ID : 0x0D \n
                                                                    
                                                                    \par
                                                    	            \#BYTE_PARAM : FIRST_STAGE_CC_MODE_MAX_VOLTAGE \n
                                                    	            \#BYTE_ALIAS : 1st CC Maximum Charging Voltage \n
                                                    	            \#BYTE_POS : 0 \n
                                                    	            \#BYTE_SIZE : 1 \n
                                                    	            \#BYTE_DESC : The max voltage of constant current charging stage 0. \n
                                                                                    Range:(2V-to-4.2V) or( 2000 to 4200) \n
                                                                                    Unit :Voltage. Size:2bytes \n
                                                                                    2000(2.0V)  \n
                                                                                    2500(2.5V)  \n
                                                                                    3000 (3.0V) \n
                                                                                    3100 (3.1V) \n
                                                                                    3200 (3.2V) \n
                                                                                    3300 (3.3V) \n
                                                                                    3400 (3.4V) \n
                                                                                    3500 (3.5V) \n
                                                                                    3600 (3.6V) \n
                                                                                    3700 (3.7V) \n
                                                                                    3800 (3.8V) \n
                                                                                    3900 (3.9V) \n
                                                                                    4000 (4.0V) \n
                                                                                    4100 (4.1V) \n
                                                                                    4200 (4.2V) \n
                                                    	            \#DESC_END  \n

                                                    	            \par
                                                    	            \#BYTE_PARAM : SECOND_STAGE_CC_MODE_MAX_VOLTAGE \n
                                                    	            \#BYTE_ALIAS : 2nd CC Maximum Charging Voltage\n
                                                    	            \#BYTE_POS : 1 \n
                                                    	            \#BYTE_SIZE : 1 \n
                                                    	            \#BYTE_DESC : The max voltage of constant current charging stage 1. \n
                                                                                    Range:(2V-to-4.2V) or( 2000 to 4200) \n
                                                                                    Unit :Voltage. Size:2bytes \n
                                                                                    2000(2.0V)  \n
                                                                                    2500(2.5V)  \n
                                                                                    3000 (3.0V) \n
                                                                                    3100 (3.1V) \n
                                                                                    3200 (3.2V) \n
                                                                                    3300 (3.3V) \n
                                                                                    3400 (3.4V) \n
                                                                                    3500 (3.5V) \n
                                                                                    3600 (3.6V) \n
                                                                                    3700 (3.7V) \n
                                                                                    3800 (3.8V) \n
                                                                                    3900 (3.9V) \n
                                                                                    4000 (4.0V) \n
                                                                                    4100 (4.1V) \n
                                                                                    4200 (4.2V) \n
                                                    	            \#DESC_END  \n

                                                    	            \par
                                                    	            \#BYTE_PARAM : THIRD_STAGE_CC_MODE_MAX_VOLTAGE \n
                                                    	            \#BYTE_ALIAS : 3rd CC Maximum Charging Voltage\n
                                                    	            \#BYTE_POS : 2 \n
                                                    	            \#BYTE_SIZE : 1 \n
                                                    	            \#BYTE_DESC : The max voltage of constant current charging stage 2. \n
                                                                                    Range:(2V-to-4.2V) or( 2000 to 4200) \n
                                                                                    Unit :Voltage. Size:2bytes \n
                                                                                    2000(2.0V)  \n
                                                                                    2500(2.5V)  \n
                                                                                    3000 (3.0V) \n
                                                                                    3100 (3.1V) \n
                                                                                    3200 (3.2V) \n
                                                                                    3300 (3.3V) \n
                                                                                    3400 (3.4V) \n
                                                                                    3500 (3.5V) \n
                                                                                    3600 (3.6V) \n
                                                                                    3700 (3.7V) \n
                                                                                    3800 (3.8V) \n
                                                                                    3900 (3.9V) \n
                                                                                    4000 (4.0V) \n
                                                                                    4100 (4.1V) \n
                                                                                    4200 (4.2V) \n
                                                    	            \#DESC_END  \n

                                                    	            \par
                                                    	            \#BYTE_PARAM : FORTH_STAGE_CC_MODE_MAX_VOLTAGE \n
                                                    	            \#BYTE_ALIAS : 4th CC Maximum Charging Voltage\n
                                                    	            \#BYTE_POS : 3 \n
                                                    	            \#BYTE_SIZE : 1 \n
                                                    	            \#BYTE_DESC : The max voltage of constant current charging stage 3. \n
                                                                                    Range:(2V-to-4.2V) or( 2000 to 4200) \n
                                                                                    Unit :Voltage. Size:2bytes \n
                                                                                    2000(2.0V)  \n
                                                                                    2500(2.5V)  \n
                                                                                    3000 (3.0V) \n
                                                                                    3100 (3.1V) \n
                                                                                    3200 (3.2V) \n
                                                                                    3300 (3.3V) \n
                                                                                    3400 (3.4V) \n
                                                                                    3500 (3.5V) \n
                                                                                    3600 (3.6V) \n
                                                                                    3700 (3.7V) \n
                                                                                    3800 (3.8V) \n
                                                                                    3900 (3.9V) \n
                                                                                    4000 (4.0V) \n
                                                                                    4100 (4.1V) \n
                                                                                    4200 (4.2V) \n
                                                    	            \#DESC_END  \n
                                                                    
                                                                */
                                                                
    POWER_CFG_KEY_MAX_CC_CHARGING_CURRENT               = 0x0E, /**<\#PARAM_NAME : POWER_CFG_KEY_MAX_CC_CHARGING_CURRENT \n
                                                                    \#PARAM_TYPE : Public \n
                                                                    \#GROUP_ID : 0x05 \n
                                                                    \#KEY_ID : 0x0E \n

                                                                    \par
                                                    	            \#BYTE_PARAM : FIRST_STAGE_CC_MODE_CHARGING_CURRENT \n
                                                    	            \#BYTE_ALIAS : 1st CC Charging Current Setting \n
                                                    	            \#BYTE_POS : 0 \n
                                                    	            \#BYTE_SIZE : 1 \n
                                                    	            \#BYTE_DESC : Charging current for charging stage 0 \n
                                                                                  Unit :mA \n
                                                                                  Range :0 - Max 350mA. \n
                                                    	            \#DESC_END  \n

                                                    	            \par
                                                    	            \#BYTE_PARAM : SECOND_STAGE_CC_CHARGING_CURRENT \n
                                                    	            \#BYTE_ALIAS : 2nd CC Charging Current Setting\n
                                                    	            \#BYTE_POS : 1 \n
                                                    	            \#BYTE_SIZE : 1 \n
                                                    	            \#BYTE_DESC : Charging current for charging stage 1 \n
                                                                                  Unit :mA \n
                                                                                  Range :0 - Max 350mA. \n
                                                    	            \#DESC_END  \n

                                                    	            \par
                                                    	            \#BYTE_PARAM : THIRD_STAGE_CC_MODE_CHARGING_CURRENT \n
                                                    	            \#BYTE_ALIAS : 3rd CC Charging Current Setting\n
                                                    	            \#BYTE_POS : 2 \n
                                                    	            \#BYTE_SIZE : 1 \n
                                                    	            \#BYTE_DESC : Charging current for charging stage 2 \n
                                                                                  Unit :mA \n
                                                                                  Range :0 - Max 350mA. \n
                                                    	            \#DESC_END  \n

                                                    	            \par
                                                    	            \#BYTE_PARAM : FORTH_STAGE_CC_MODE_CHARGING_CURRENT \n
                                                    	            \#BYTE_ALIAS : 4th CC Charging Current Setting\n
                                                    	            \#BYTE_POS : 3 \n
                                                    	            \#BYTE_SIZE : 1 \n
                                                    	            \#BYTE_DESC : Charging current for charging stage 3 \n
                                                                                  Unit :mA \n
                                                                                  Range :0 - Max 350mA. \n
                                                    	            \#DESC_END  \n
                                                                */
                                                                
    POWER_CFG_KEY_LOW_BATTERY_WARNING_TIME              = 0x0F, /**<\#PARAM_NAME : POWER_CFG_KEY_LOW_BATTERY_WARNING_TIME \n
                                                                    \#ALIAS : Low Battery Warning Time \n
                                                                    \#PARAM_TYPE : Public \n
                                                                    \#PARAM_DESC : When the voltage battery is lower than Warning_Battery_Level (the voltage setting for low battery), \n
                                                                                   the speaker alerts users periodically with this interval(unit in 640 ms). \n
                                                                    \#DESC_END
                                                                    \#GROUP_ID : 0x05 \n
                                                                    \#KEY_ID : 0x0F \n
                                                                */
                                                                
    POWER_CFG_KEY_STOP_WORKING_SAR_MIN                  = 0x10, /**<\#PARAM_NAME : POWER_CFG_KEY_STOP_WORKING_SAR_MIN \n
                                                                    \#ALIAS : Stop Working SAR Min \n
                                                                    \#PARAM_TYPE : Public \n
                                                                    \#PARAM_DESC : The minimum SAR value for product working range. \n
                                                                                   The value represents temperature up to circuit design \n
                                                                                   0x00C3: 35 degree C  \n
                                                                                   0x00A7: 40 degree C  \n
                                                                                   0x0092: 45 degree C  \n
                                                                                   0x0082: 50 degree C  \n
                                                                                   0x0073: 55 degree C  \n
                                                                    \#DESC_END
                                                                    \#GROUP_ID : 0x05 \n
                                                                    \#KEY_ID : 0x10 \n
                                                                */
                                                                
    POWER_CFG_KEY_STOP_WORKING_SAR_MAX                  = 0x11, /**<\#PARAM_NAME : POWER_CFG_KEY_STOP_WORKING_SAR_MAX \n
                                                                    \#ALIAS : Stop Working SAR Max \n
                                                                    \#PARAM_TYPE : Public \n
                                                                    \#PARAM_DESC : The maximum SAR value for product working range. \n
                                                                                   The value represents temperature up to circuit design. \n
                                                                                   0x0331: -5 degree C  \n
                                                                                   0x02B0: 0 degree C   \n
                                                                                   0x0239: 5 degree C   \n
                                                                                   0x01D6: 10 degree C  \n
                                                                                   0x0186: 15 degree C  \n
                                                                    \#DESC_END
                                                                    \#GROUP_ID : 0x05 \n
                                                                    \#KEY_ID : 0x11 \n
                                                                */
                                                                
    POWER_CFG_KEY_CV_SOTP_CHARGING_CURRENT              = 0x12, /**<\#PARAM_NAME : POWER_CFG_KEY_CV_SOTP_CHARGING_CURRENT \n
                                                                    \#ALIAS : Stop Charging Current \n
                                                                    \#PARAM_TYPE : Public \n
                                                                    \#PARAM_DESC : Charging stops, when charging current less than the current. \n
                                                                                   Unit :mA \n
                                                                                   (0 - Max 80mA)   \n
                                                                                   *Should not exceed min value of Max Charging current \n
                                                                    \#DESC_END
                                                                    \#GROUP_ID : 0x05 \n
                                                                    \#KEY_ID : 0x12 \n
                                                                */
                                                                
    POWER_CFG_KEY_CV_FIRST_HALF_BATTERY_MONITOR_COUNT   = 0x13, /**<\#PARAM_NAME : POWER_CFG_KEY_CV_FIRST_HALF_BATTERY_MONITOR_COUNT \n
                                                                    \#ALIAS : First Half Battery Monitor Counter \n
                                                                    \#PARAM_TYPE : Public \n
                                                                    \#PARAM_DESC : If charging current during CV Mode is configured larger than 252 mA, this monitor counter will be applied. \n
                                                                                   Charging current decreases 8mA, if the voltage has been monitored exceeded the fourth stage of CC mode voltage up to mentioned battery monitor count. \n
                                                                                   Range : 1 ~ 20  \n
                                                                                   Unit : 100ms    \n
                                                                                   Count 1 is equal to = 100 msec.  \n
                                                                    \#DESC_END
                                                                    \#GROUP_ID : 0x05 \n
                                                                    \#KEY_ID : 0x13 \n
                                                                */
                                                                
    POWER_CFG_KEY_CV_SECOND_HALF_BATTERY_MONITOR_COUNT  = 0x14, /**<\#PARAM_NAME : POWER_CFG_KEY_CV_SECOND_HALF_BATTERY_MONITOR_COUNT \n
                                                                    \#ALIAS : Second Half Battery Monitor Counter \n
                                                                    \#PARAM_TYPE : Public \n
                                                                    \#PARAM_DESC : If charging current is less than 252 mA, this monitor counter will be applied. \n
                                                                                   Charging current decreases 4mA if the voltage has been monitored exceeded the fourth stage of CC mode voltage up to mentioned battery monitor count. \n
                                                                                   Range : 1 ~ 20  \n
                                                                                   Unit : 100ms    \n
                                                                                   Count 1 is equal to = 100 msec.  \n
                                                                    \#DESC_END
                                                                    \#GROUP_ID : 0x05 \n
                                                                    \#KEY_ID : 0x14 \n
                                                                */
                                                                
    POWER_CFG_KEY_MAX_CV_RECHARGING_CURRENT             = 0x15, /**<\#PARAM_NAME : POWER_CFG_KEY_MAX_CV_RECHARGING_CURRENT \n
                                                                    \#ALIAS : Maximum CV Re-charging Current \n
                                                                    \#PARAM_TYPE : Public \n
                                                                    \#PARAM_DESC : Maximum re-charging current. \n
                                                                                   Unit :mA \n
                                                                                   (0 - Max 350mA) \n
                                                                    \#DESC_END
                                                                    \#GROUP_ID : 0x05 \n
                                                                    \#KEY_ID : 0x15 \n
                                                                */
    
    POWER_CFG_KEY_END
}POWER_CFG_Key_IdDefinition_T;

/**@defgroup POWER_CFG_DEFAULT_VALUE POWER Configuration Default Value
 * @brief Default value definition of the module @ref CFG_MODULE_ID_POWER.
 * @{ */




//Module POWER
#define POWER_CFG_KEY_STOP_CHARGING_SAR_MIN_LEN                             0x02        /**< The default length of @ref POWER_CFG_KEY_STOP_CHARGING_SAR_MIN. */
#define POWER_CFG_KEY_STOP_CHARGING_SAR_MIN_DEFAULT_VALUE                   0x00, 0xA7  /**< The default value of @ref POWER_CFG_KEY_STOP_CHARGING_SAR_MIN. */

#define POWER_CFG_KEY_STOP_CHARGING_SAR_MAX_LEN                             0x02        /**< The default length of @ref POWER_CFG_KEY_STOP_CHARGING_SAR_MAX. */
#define POWER_CFG_KEY_STOP_CHARGING_SAR_MAX_DEFAULT_VALUE                   0x03, 0x31  /**< The default value of @ref POWER_CFG_KEY_STOP_CHARGING_SAR_MAX. */

#define POWER_CFG_KEY_RESTART_CHARGING_SAR_MIN_LEN                          0x02        /**< The default length of @ref POWER_CFG_KEY_RESTART_CHARGING_SAR_MIN. */
#define POWER_CFG_KEY_RESTART_CHARGING_SAR_MIN_DEFAULT_VALUE                0x00, 0xc3  /**< The default value of @ref POWER_CFG_KEY_RESTART_CHARGING_SAR_MIN. */

#define POWER_CFG_KEY_RESTART_CHARGING_SAR_MAX_LEN                          0x02        /**< The default length of @ref POWER_CFG_KEY_RESTART_CHARGING_SAR_MAX. */
#define POWER_CFG_KEY_RESTART_CHARGING_SAR_MAX_DEFAULT_VALUE                0x02, 0xB0  /**< The default value of @ref POWER_CFG_KEY_RESTART_CHARGING_SAR_MAX. */

#define POWER_CFG_KEY_MAX_CV_CHARGING_CURRENT_LEN                           0x02        /**< The default length of @ref POWER_CFG_KEY_MAX_CV_CHARGING_CURRENT. */
#define POWER_CFG_KEY_MAX_CV_CHARGING_CURRENT_DEFAULT_VALUE                 0x00, 0xFA  //250mA /**< The default value of @ref POWER_CFG_KEY_MAX_CV_CHARGING_CURRENT. */

#define POWER_CFG_KEY_WARNING_BATTERY_LEVEL_LEN                             0x02        /**< The default length of @ref POWER_CFG_KEY_WARNING_BATTERY_LEVEL. */
#define POWER_CFG_KEY_WARNING_BATTERY_LEVEL_DEFAULT_VALUE                   0x0C, 0xE4  /**< The default value of @ref POWER_CFG_KEY_WARNING_BATTERY_LEVEL. */

#define POWER_CFG_KEY_SHUTDOWN_BATTERY_LEVEL_LEN                            0x02        /**< The default length of @ref POWER_CFG_KEY_SHUTDOWN_BATTERY_LEVEL. */
#define POWER_CFG_KEY_SHUTDOWN_BATTERY_LEVEL_DEFAULT_VALUE                  0x0B, 0xB8  //3.0V  /**< The default value of @ref POWER_CFG_KEY_SHUTDOWN_BATTERY_LEVEL. */

#define POWER_CFG_KEY_CC_SUB_MODE_PROTECT_TIME_LEN                          0x04        /**< The default length of @ref POWER_CFG_KEY_CC_SUB_MODE_PROTECT_TIME. */
#define POWER_CFG_KEY_CC_SUB_MODE_PROTECT_TIME_DEFAULT_VALUE                0x14, 0x14, 0xB4, 0xB4  //20,20,180,180 min /**< The default value of @ref POWER_CFG_KEY_CC_SUB_MODE_PROTECT_TIME. */

#define POWER_CFG_KEY_CV_PROTECT_TIME_LEN                                   0x01        /**< The default length of @ref POWER_CFG_KEY_CV_PROTECT_TIME_LEN. */
#define POWER_CFG_KEY_CV_PROTECT_TIME_DEFAULT_VALUE                         0x78        /**< The default value of @ref POWER_CFG_KEY_CV_PROTECT_TIME_LEN. */

#define POWER_CFG_KEY_OPTION1_LEN                                           0x01        /**< The default length of @ref POWER_CFG_KEY_OPTION1. */
#define POWER_CFG_KEY_OPTION1_DEFAULT_VALUE                                 0x62        /**< The default value of @ref POWER_CFG_KEY_OPTION1. */

#define POWER_CFG_KEY_OPTION2_LEN                                           0x01        /**< The default length of @ref POWER_CFG_KEY_OPTION2. */
#define POWER_CFG_KEY_OPTION2_DEFAULT_VALUE                                 0x00        /**< The default value of @ref POWER_CFG_KEY_OPTION2. */

#define POWER_CFG_KEY_RECHARGING_BATT_CAPACITY_LEN                          0x01        /**< The default length of @ref POWER_CFG_KEY_RECHARGING_BATT_CAPACITY. */
#define POWER_CFG_KEY_RECHARGING_BATT_CAPACITY_DEFAULT_VALUE                0x5F        /**< The default value of @ref POWER_CFG_KEY_RECHARGING_BATT_CAPACITY. */

#define POWER_CFG_KEY_VOLTAGE_LEVELS_LEN                                    0x08        /**< The default length of @ref POWER_CFG_KEY_VOLTAGE_LEVELS. */
#define POWER_CFG_KEY_VOLTAGE_LEVELS_DEFAULT_VALUE                          0x09, 0xC4, 0x0C, 0x80, 0x0E, 0x74, 0x10, 0x68   /**< The default value of @ref POWER_CFG_KEY_VOLTAGE_LEVELS. 2.5V,3.2,3.7,4.2V.*/

#define POWER_CFG_KEY_MAX_CC_CHARGING_CURRENT_LEN                           0x08        /**< The default length of @ref POWER_CFG_KEY_MAX_CC_CHARGING_CURRENT. */
#define POWER_CFG_KEY_MAX_CC_CHARGING_CURRENT_DEFAULT_VALUE                 0x00, 0x1E, 0x00, 0x1E, 0x01, 0x2C, 0x01, 0x2C  //30mA,30mA,300mA,300mA. /**< The default value of @ref POWER_CFG_KEY_MAX_CC_CHARGING_CURRENT. */

#define POWER_CFG_KEY_LOW_BATTERY_WARNING_TIME_LEN                          0x01        /**< The default length of @ref POWER_CFG_KEY_LOW_BATTERY_WARNING_TIME. */
#define POWER_CFG_KEY_LOW_BATTERY_WARNING_TIME_DEFAULT_VALUE                0x1E        /**< The default value of @ref POWER_CFG_KEY_LOW_BATTERY_WARNING_TIME. */

#define POWER_CFG_KEY_STOP_WORKING_SAR_MIN_LEN                              0x02        /**< The default length of @ref POWER_CFG_KEY_STOP_WORKING_SAR_MIN. */
#define POWER_CFG_KEY_STOP_WORKING_SAR_MIN_DEFAULT_VALUE                    0x00, 0x92  /**< The default value of @ref POWER_CFG_KEY_STOP_WORKING_SAR_MIN. */

#define POWER_CFG_KEY_STOP_WORKING_SAR_MAX_LEN                              0x02        /**< The default length of @ref POWER_CFG_KEY_STOP_WORKING_SAR_MAX. */
#define POWER_CFG_KEY_STOP_WORKING_SAR_MAX_DEFAULT_VALUE                    0x03, 0x31  /**< The default value of @ref POWER_CFG_KEY_STOP_WORKING_SAR_MAX. */

#define POWER_CFG_KEY_CV_SOTP_CHARGING_CURRENT_LEN                          0x02        /**< The default length of @ref POWER_CFG_KEY_CV_SOTP_CHARGING_CURRENT. */
#define POWER_CFG_KEY_CV_SOTP_CHARGING_CURRENT_DEFAULT_VALUE                0x00,0x19   /**< The default value of @ref POWER_CFG_KEY_CV_SOTP_CHARGING_CURRENT. */ //25mA

#define POWER_CFG_KEY_CV_FIRST_HALF_BATTERY_MONITOR_COUNT_LEN               0x01        /**< The default length of @ref POWER_CFG_KEY_CV_FIRST_HALF_BATTERY_MONITOR_COUNT. */
#define POWER_CFG_KEY_CV_FIRST_HALF_BATTERY_MONITOR_COUNT_DEFAULT_VALUE     0x04        /**< The default value of @ref POWER_CFG_KEY_CV_FIRST_HALF_BATTERY_MONITOR_COUNT. */ //100ms * 0x04,Count 1 is equal to = 100 msec.

#define POWER_CFG_KEY_CV_SECOND_HALF_BATTERY_MONITOR_COUNT_LEN              0x01        /**< The default length of @ref POWER_CFG_KEY_CV_SECOND_HALF_BATTERY_MONITOR_COUNT. */
#define POWER_CFG_KEY_CV_SECOND_HALF_BATTERY_MONITOR_COUNT_DEFAULT_VALUE   0x04        /**< The default value of @ref POWER_CFG_KEY_CV_SECOND_HALF_BATTERY_MONITOR_COUNT. */ //100ms * 0x04,Count 1 is equal to = 100 msec.

#define POWER_CFG_KEY_MAX_CV_RECHARGING_CURRENT_LEN                         0x02        /**< The default length of @ref POWER_CFG_KEY_MAX_CV_RECHARGING_CURRENT. */
#define POWER_CFG_KEY_MAX_CV_RECHARGING_CURRENT_DEFAULT_VALUE               0x00, 0xFA  /**< The default value of @ref POWER_CFG_KEY_MAX_CV_RECHARGING_CURRENT. */ //250mA

/** @} */
/** @} */

/** \cond NON_DOC */

#define CFG_POWER_MODULE_TOTAL_NUM_KEYS   (POWER_CFG_KEY_END - 1)

#define CFG_POWER_MODULE_TOTAL_SIZE ((CFG_POWER_MODULE_TOTAL_NUM_KEYS*SIZEOF_CFG_KEY_STRUCT) + \
                                    POWER_CFG_KEY_STOP_CHARGING_SAR_MIN_LEN +               \
                                    POWER_CFG_KEY_STOP_CHARGING_SAR_MAX_LEN +               \
                                    POWER_CFG_KEY_RESTART_CHARGING_SAR_MIN_LEN +            \
                                    POWER_CFG_KEY_RESTART_CHARGING_SAR_MAX_LEN +            \
                                    POWER_CFG_KEY_MAX_CV_CHARGING_CURRENT_LEN+              \
                                    POWER_CFG_KEY_WARNING_BATTERY_LEVEL_LEN +               \
                                    POWER_CFG_KEY_SHUTDOWN_BATTERY_LEVEL_LEN +              \
                                    POWER_CFG_KEY_CC_SUB_MODE_PROTECT_TIME_LEN +            \
                                    POWER_CFG_KEY_CV_PROTECT_TIME_LEN +                     \
                                    POWER_CFG_KEY_OPTION1_LEN +                             \
                                    POWER_CFG_KEY_OPTION2_LEN +                             \
                                    POWER_CFG_KEY_RECHARGING_BATT_CAPACITY_LEN +            \
                                    POWER_CFG_KEY_VOLTAGE_LEVELS_LEN +                      \
                                    POWER_CFG_KEY_MAX_CC_CHARGING_CURRENT_LEN +             \
                                    POWER_CFG_KEY_LOW_BATTERY_WARNING_TIME_LEN +            \
                                    POWER_CFG_KEY_STOP_WORKING_SAR_MIN_LEN +                \
                                    POWER_CFG_KEY_STOP_WORKING_SAR_MAX_LEN +                \
                                    POWER_CFG_KEY_CV_SOTP_CHARGING_CURRENT_LEN +            \
                                    POWER_CFG_KEY_CV_FIRST_HALF_BATTERY_MONITOR_COUNT_LEN + \
                                    POWER_CFG_KEY_CV_SECOND_HALF_BATTERY_MONITOR_COUNT_LEN+ \
                                    POWER_CFG_KEY_MAX_CV_RECHARGING_CURRENT_LEN)


//POWER Config keys definition
#define CFG_POWER_MODULE_DEFAULT_VALUE  CFG_MODULE_ID_POWER,               /*moduleID*/   \
                                        CFG_POWER_MODULE_TOTAL_NUM_KEYS,   /*numKeys*/    \
                                        (CFG_POWER_MODULE_TOTAL_SIZE >> 8),  /*moduleSize*/  \
                                        CFG_POWER_MODULE_TOTAL_SIZE,                      \
                                        /*CFG_KEYs[numKeys]*/                           \
                                        /*    //ID                                                                                       //Len                                                                                    //Value    */                                              \
                                        POWER_CFG_KEY_STOP_CHARGING_SAR_MIN,                POWER_CFG_KEY_STOP_CHARGING_SAR_MIN_LEN,                POWER_CFG_KEY_STOP_CHARGING_SAR_MIN_DEFAULT_VALUE,                  \
                                        POWER_CFG_KEY_STOP_CHARGING_SAR_MAX,                POWER_CFG_KEY_STOP_CHARGING_SAR_MAX_LEN,                POWER_CFG_KEY_STOP_CHARGING_SAR_MAX_DEFAULT_VALUE,                  \
                                        POWER_CFG_KEY_RESTART_CHARGING_SAR_MIN,             POWER_CFG_KEY_RESTART_CHARGING_SAR_MIN_LEN,             POWER_CFG_KEY_RESTART_CHARGING_SAR_MIN_DEFAULT_VALUE,               \
                                        POWER_CFG_KEY_RESTART_CHARGING_SAR_MAX,             POWER_CFG_KEY_RESTART_CHARGING_SAR_MAX_LEN,             POWER_CFG_KEY_RESTART_CHARGING_SAR_MAX_DEFAULT_VALUE,               \
                                        POWER_CFG_KEY_MAX_CV_CHARGING_CURRENT,              POWER_CFG_KEY_MAX_CV_CHARGING_CURRENT_LEN,              POWER_CFG_KEY_MAX_CV_CHARGING_CURRENT_DEFAULT_VALUE,                  \
                                        POWER_CFG_KEY_WARNING_BATTERY_LEVEL,                POWER_CFG_KEY_WARNING_BATTERY_LEVEL_LEN,                POWER_CFG_KEY_WARNING_BATTERY_LEVEL_DEFAULT_VALUE,                  \
                                        POWER_CFG_KEY_SHUTDOWN_BATTERY_LEVEL,               POWER_CFG_KEY_SHUTDOWN_BATTERY_LEVEL_LEN,               POWER_CFG_KEY_SHUTDOWN_BATTERY_LEVEL_DEFAULT_VALUE,                 \
                                        POWER_CFG_KEY_CC_SUB_MODE_PROTECT_TIME,             POWER_CFG_KEY_CC_SUB_MODE_PROTECT_TIME_LEN,             POWER_CFG_KEY_CC_SUB_MODE_PROTECT_TIME_DEFAULT_VALUE,               \
                                        POWER_CFG_KEY_CV_PROTECT_TIME,                      POWER_CFG_KEY_CV_PROTECT_TIME_LEN,                      POWER_CFG_KEY_CV_PROTECT_TIME_DEFAULT_VALUE,                        \
                                        POWER_CFG_KEY_OPTION1,                              POWER_CFG_KEY_OPTION1_LEN,                              POWER_CFG_KEY_OPTION1_DEFAULT_VALUE,                                \
                                        POWER_CFG_KEY_OPTION2,                              POWER_CFG_KEY_OPTION2_LEN,                              POWER_CFG_KEY_OPTION2_DEFAULT_VALUE,                                \
                                        POWER_CFG_KEY_RECHARGING_BATT_CAPACITY,             POWER_CFG_KEY_RECHARGING_BATT_CAPACITY_LEN,             POWER_CFG_KEY_RECHARGING_BATT_CAPACITY_DEFAULT_VALUE,               \ 
                                        POWER_CFG_KEY_VOLTAGE_LEVELS,                       POWER_CFG_KEY_VOLTAGE_LEVELS_LEN,                       POWER_CFG_KEY_VOLTAGE_LEVELS_DEFAULT_VALUE,                          \
                                        POWER_CFG_KEY_MAX_CC_CHARGING_CURRENT,              POWER_CFG_KEY_MAX_CC_CHARGING_CURRENT_LEN,              POWER_CFG_KEY_MAX_CC_CHARGING_CURRENT_DEFAULT_VALUE,                \
                                        POWER_CFG_KEY_LOW_BATTERY_WARNING_TIME,             POWER_CFG_KEY_LOW_BATTERY_WARNING_TIME_LEN,             POWER_CFG_KEY_LOW_BATTERY_WARNING_TIME_DEFAULT_VALUE,               \
                                        POWER_CFG_KEY_STOP_WORKING_SAR_MIN,                 POWER_CFG_KEY_STOP_WORKING_SAR_MIN_LEN,                 POWER_CFG_KEY_STOP_WORKING_SAR_MIN_DEFAULT_VALUE,                   \
                                        POWER_CFG_KEY_STOP_WORKING_SAR_MAX,                 POWER_CFG_KEY_STOP_WORKING_SAR_MAX_LEN,                 POWER_CFG_KEY_STOP_WORKING_SAR_MAX_DEFAULT_VALUE,                   \
                                        POWER_CFG_KEY_CV_SOTP_CHARGING_CURRENT,             POWER_CFG_KEY_CV_SOTP_CHARGING_CURRENT_LEN,             POWER_CFG_KEY_CV_SOTP_CHARGING_CURRENT_DEFAULT_VALUE,               \
                                        POWER_CFG_KEY_CV_FIRST_HALF_BATTERY_MONITOR_COUNT,  POWER_CFG_KEY_CV_FIRST_HALF_BATTERY_MONITOR_COUNT_LEN,  POWER_CFG_KEY_CV_FIRST_HALF_BATTERY_MONITOR_COUNT_DEFAULT_VALUE,    \
                                        POWER_CFG_KEY_CV_SECOND_HALF_BATTERY_MONITOR_COUNT, POWER_CFG_KEY_CV_SECOND_HALF_BATTERY_MONITOR_COUNT_LEN, POWER_CFG_KEY_CV_SECOND_HALF_BATTERY_MONITOR_COUNT_DEFAULT_VALUE,  \
                                        POWER_CFG_KEY_MAX_CV_RECHARGING_CURRENT,            POWER_CFG_KEY_MAX_CV_RECHARGING_CURRENT_LEN,            POWER_CFG_KEY_MAX_CV_RECHARGING_CURRENT_DEFAULT_VALUE


typedef struct _APP_Cfg_PwrOption1_T
{
    uint8_t dedicateChargerLedEnable: 1;
    uint8_t enableShutdownPower: 1;
    uint8_t enableChargerDetect: 1;
    uint8_t enableBatteryVoltageDetect: 1;
    uint8_t chargingDisallowShsActive: 1;
    uint8_t enableInternalUsbCharger: 1;
    uint8_t chargingWithAllUsbBcType: 1;
    uint8_t enableAmbientTempAsCharging: 1;
} APP_Cfg_PwrOption1_T;

typedef struct _APP_Cfg_PwrOption2_T
{ 
    uint8_t enablelowbatterydebounce :1;
    uint8_t ReChargingAsChargeComplete: 1;
    uint8_t enableAmbientTempForoperating: 1;
    uint8_t reserved: 5;
} APP_Cfg_PwrOption2_T;


void APP_CFG_ReadPwrOption1(APP_Cfg_PwrOption1_T XDATA *p_option);
void APP_CFG_ReadPwrOption2(APP_Cfg_PwrOption2_T XDATA *p_option);
void APP_CFG_ReadPwrRechargingBattCap(uint8_t XDATA *p_threshold);
void APP_CFG_WritePwrRechargingBattCap(uint8_t threshold);
void APP_CFG_ReadWarningBattLevel(uint8_t XDATA *p_threshold);
void APP_CFG_ReadShutDownBattLevel(uint8_t XDATA *p_threshold);
void APP_CFG_ReadmaxCVchargingcurrent(uint8_t XDATA *p_cvcurrent);
void APP_CFG_Readcvprotecttime(uint8_t XDATA *p_time);
void APP_CFG_Readccprotecttime(uint8_t XDATA *p_time);
void APP_CFG_Readvoltagelevels(uint8_t XDATA *vlevel);
void APP_CFG_Readmaxchargingcurrent(uint8_t XDATA *p_current);
void APP_CFG_Readlowbattwarningtime(uint8_t XDATA *p_time);
void APP_CFG_ReadminmaxTemp(uint8_t XDATA *p_stoptempmin,uint8_t XDATA *p_stoptempmax,uint8_t XDATA *p_rsttempmin,uint8_t XDATA *p_rsttempmax);
void APP_CFG_ReadminmaxworkTemp(uint8_t XDATA *p_stoptempmin,uint8_t XDATA *p_stoptempmax);
void APP_CFG_Readbatmonitorcounter(uint8_t XDATA *p_count1,uint8_t XDATA *p_count2);
void APP_CFG_Readmaxandstopcvcurrent(uint8_t XDATA *p_stopcvcurrent,uint8_t XDATA *p_maxcvcurrent);
void APP_CFG_Readmaxrechargingcurrent(uint8_t XDATA *p_current);

/// \endcond

#endif//APP_CFG_POWER_H

