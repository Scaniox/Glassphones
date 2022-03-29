/********************************************************************
  File Information:
    FileName:       app_cfg_led.h
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

#ifndef APP_CFG_LED_H
#define APP_CFG_LED_H

/** \cond NON_DOC 

\#BUILD_TARGET : MSPKv2_GFP
\#BUILD_TARGET : MSPKv2_SPP
\#TARGET_START

\#TARGET_END

\#BUILD_TARGET : MSPKv2_App_Basic
\#BUILD_TARGET : MSPKv2_PBAP
\#BUILD_TARGET : AT_App
\#TARGET_START
\#REMOVE_PARAM : LED_CFG_KEY_MSPK_MODE_PAIRING_MASTER_INDICATION                     
\#REMOVE_PARAM : LED_CFG_KEY_MSPK_MODE_PAIRING_SLAVE_INDICATION                      
\#REMOVE_PARAM : LED_CFG_KEY_MSPK_MODE_CONNECTED_BT_CONNECTED_MASTER_INDICATION      
\#REMOVE_PARAM : LED_CFG_KEY_MSPK_MODE_CONNECTED_BT_PAIRING_MASTER_INDICATION        
\#REMOVE_PARAM : LED_CFG_KEY_MSPK_MODE_CONNECTED_BT_PAGING_MASTER_INDICATION         
\#REMOVE_PARAM : LED_CFG_KEY_MSPK_MODE_CONNECTED_BT_WAITING_MASTER_INDICATION        
\#REMOVE_PARAM : LED_CFG_KEY_STEREO_MODE_CONNECTED_SLAVE_INDICATION
\#REMOVE_PARAM : LED_CFG_KEY_CONCERT_MODE_CONNECTED_SLAVE_INDICATION

\#TARGET_END

\endcond
*/

/**
  @addtogroup APP_CFG_LED LED Configuration
  @{
  @brief Definitions and prototypes for the LED Configuration.
 */


//Config Key definiton of MODULE_LED(0x06)
/**
 * @brief Configuration key definition of the module @ref CFG_MODULE_ID_LED.
 *  
 */

typedef enum _LED_CFG_Key_IdDefinition_T
{
    LED_CFG_KEY_CHARGER_LED_OPTION                                      = 0x01,     /**<\#PARAM_NAME : LED_CFG_KEY_CHARGER_LED_OPTION \n
                                                                                        \#PARAM_TYPE : Public \n
                                                                                        \#GROUP_ID : 0x06 \n
                                                                                        \#KEY_ID : 0x01 \n
                                                                                	    \par
                                                                                	    \#BIT_PARAM : CHARGING_COMPLETE_LED_INDICATION_SETTING \n
                                                                                	    \#BIT_ALIAS : Charging Complete LED Indication Setting \n
                                                                                	    \#BIT_POS : 0 \n
                                                                                	    \#BIT_SIZE : 4 \n
                                                                                	    \#BIT_DESC : 0: charger release LED control(back to normal display) \n
                                                                                                     1: LED1 ON and then charger release LED control \n
                                                                                                     2: LED1 always ON, LED2 normal display \n
                                                                                                     3: LED1 always OFF, LED2 normal display. \n
                                                                                	    \#DESC_END

                                                                                	    \par
                                                                                	    \#BIT_PARAM : CHARGEING_ERROR_LED_INDICATION_SETTING \n
                                                                                	    \#BIT_ALIAS : Charging Error LED Indication Setting \n
                                                                                	    \#BIT_POS : 4 \n
                                                                                	    \#BIT_SIZE : 4 \n
                                                                                	    \#BIT_DESC : 0: same as charger complete \n
                                                                                                     1: LED1 always OFF and LED2 flash \n
                                                                                	    \#DESC_END
                                                                            	    */
                                                                            	    
    LED_CFG_KEY_STANDBY_LED_INDICATION                                  = 0x02,     /**<\#PARAM_NAME : LED_CFG_KEY_STANDBY_LED_INDICATION \n
                                                                                        \#ALIAS : STANDBY LED INDICATION \n
                                                                                        \#PARAM_TYPE : Public \n
                                                                                        \#PARAM_DESC : The LED indication for the state which the speaker has no any link.\n
                                                                                        Format:
                                                                                        {
                                                                                           STANDBY_LED_FLASH_ON_TIME,
                                                                                           STANDBY_LED_FLASH_OFF_TIME,
                                                                                           STANDBY_LED_FLASH_COUNT,
                                                                                           STANDBY_LED_FLASH_INTERVAL,
                                                                                           STANDBY_LED_TYPE
                                                                                        } \n
                                                                                        \#DESC_END
                                                                                        \#GROUP_ID : 0x06 \n
                                                                                        \#KEY_ID : 0x02 \n
                                                                            	    */
                                                                            	    
    LED_CFG_KEY_LINK_LED_INDICATION                                     = 0x03,     /**<\#PARAM_NAME : LED_CFG_KEY_LINK_LED_INDICATION \n
                                                                                        \#ALIAS : LINK LED INDICATION \n
                                                                                        \#PARAM_TYPE : Public \n
                                                                                        \#PARAM_DESC : The LED indication for the state which the speaker has BT a link. \n
                                                                                        Format:
                                                                                        {
                                                                                           LINK_LED_FLASH_ON_TIME,
                                                                                           LINK_LED_FLASH_OFF_TIME,
                                                                                           LINK_LED_FLASH_COUNT, (range: 0 ~ 3)
                                                                                           LINK_LED_FLASH_INTERVAL,
                                                                                           LINK_LED_TYPE
                                                                                        } \n
                                                                                        \#DESC_END
                                                                                        \#GROUP_ID : 0x06 \n
                                                                                        \#KEY_ID : 0x03 \n
                                                                            	    */
                                                                            	    
    LED_CFG_KEY_TALK_LED_INDICATION                                     = 0x04,     /**<\#PARAM_NAME : LED_CFG_KEY_TALK_LED_INDICATION \n
                                                                                        \#ALIAS : TALK LED INDICATION \n
                                                                                        \#PARAM_TYPE : Public \n
                                                                                        \#PARAM_DESC : The LED indication for the state which the speaker has active call(s). \n
                                                                                        Format:
                                                                                        {
                                                                                           TALK_LED_FLASH_ON_TIME,
                                                                                           TALK_LED_FLASH_OFF_TIME,
                                                                                           TALK_LED_FLASH_COUNT, (range: 0 ~ 3)
                                                                                           TALK_LED_FLASH_INTERVAL,
                                                                                           TALK_LED_TYPE
                                                                                        } \n
                                                                                        \#DESC_END
                                                                                        \#GROUP_ID : 0x06 \n
                                                                                        \#KEY_ID : 0x04 \n
                                                                            	    */
                                                                            	    
    LED_CFG_KEY_PAIRING_LED_INDICATION                                  = 0x05,     /**<\#PARAM_NAME : LED_CFG_KEY_PAIRING_LED_INDICATION \n
                                                                                        \#ALIAS : PAIRING LED INDICATION \n
                                                                                        \#PARAM_TYPE : Public \n
                                                                                        \#PARAM_DESC : The LED indication for the state which the speaker is in pairing mode. \n
                                                                                        Format:
                                                                                        {
                                                                                           PAIRING_LED_FLASH_ON_TIME,
                                                                                           PAIRING_LED_FLASH_OFF_TIME,
                                                                                           PAIRING_LED_FLASH_COUNT, (range: 0 ~ 3)
                                                                                           PAIRING_LED_FLASH_INTERVAL,
                                                                                           PAIRING_LED_TYPE
                                                                                        } \n
                                                                                        \#DESC_END
                                                                                        \#GROUP_ID : 0x06 \n
                                                                                        \#KEY_ID : 0x05 \n
                                                                            	    */
                                                                            	    
    LED_CFG_KEY_POWER_ON_LED_INDICATION                                 = 0x06,     /**<\#PARAM_NAME : LED_CFG_KEY_POWER_ON_LED_INDICATION \n
                                                                                        \#ALIAS : POWER ON LED INDICATION \n
                                                                                        \#PARAM_TYPE : Public \n
                                                                                        \#PARAM_DESC : The LED indication for the event which the speaker power on. \n
                                                                                        Format:
                                                                                        {
                                                                                            POWER_ON_LED_FLASH_ON_TIME,
                                                                                            POWER_ON_LED_FLASH_OFF_TIME,
                                                                                            POWER_ON_LED_FLASH_COUNT, (range: 0 ~ 254)
                                                                                            POWER_ON_LED_TYPE
                                                                                        } \n
                                                                                        \#DESC_END
                                                                                        \#GROUP_ID : 0x06 \n
                                                                                        \#KEY_ID : 0x06 \n
                                                                            	    */
                                                                            	    
    LED_CFG_KEY_POWER_OFF_LED_INDICATION                                = 0x07,     /**<\#PARAM_NAME : LED_CFG_KEY_POWER_OFF_LED_INDICATION \n
                                                                                        \#ALIAS : POWER OFF LED INDICATION \n
                                                                                        \#PARAM_TYPE : Public \n
                                                                                        \#PARAM_DESC : The LED indication for the event which the speaker power off. \n
                                                                                        Format:
                                                                                        {
                                                                                            POWER_OFF_LED_FLASH_ON_TIME,
                                                                                            POWER_OFF_LED_FLASH_OFF_TIME,
                                                                                            POWER_OFF_LED_FLASH_COUNT, (range: 0 ~ 254)
                                                                                            POWER_OFF_LED_TYPE
                                                                                        } \n
                                                                                        \#DESC_END
                                                                                        \#GROUP_ID : 0x06 \n
                                                                                        \#KEY_ID : 0x07 \n
                                                                            	    */
                                                                            	    
    LED_CFG_KEY_PAIRING_OK_LED_INDICATION                               = 0x08,     /**<\#PARAM_NAME : LED_CFG_KEY_PAIRING_OK_LED_INDICATION \n
                                                                                        \#ALIAS : PAIRING OK LED INDICATION \n
                                                                                        \#PARAM_TYPE : Public \n
                                                                                        \#PARAM_DESC : The LED indication for the event which the speaker is paired with a device. \n
                                                                                        Format:
                                                                                        {
                                                                                            PAIRING_OK_LED_FLASH_ON_TIME,
                                                                                            PAIRING_OK_LED_FLASH_OFF_TIME,
                                                                                            PAIRING_OK_LED_FLASH_COUNT, (range: 0 ~ 254)
                                                                                            PAIRING_OK_LED_TYPE
                                                                                        } \n
                                                                                        \#DESC_END
                                                                                        \#GROUP_ID : 0x06 \n
                                                                                        \#KEY_ID : 0x08 \n
                                                                            	    */
                                                                            	    
    LED_CFG_KEY_LOW_BATTERY_LED_INDICATION                              = 0x09,     /**<\#PARAM_NAME : LED_CFG_KEY_LOW_BATTERY_LED_INDICATION \n
                                                                                        \#ALIAS : LOW BATTERY LED INDICATION \n
                                                                                        \#PARAM_TYPE : Public \n
                                                                                        \#PARAM_DESC : The LED indication for the warning which the voltage battery is low. \n
                                                                                        Format:
                                                                                        {
                                                                                            LOW_BATTERY_LED_FLASH_ON_TIME,
                                                                                            LOW_BATTERY_LED_FLASH_OFF_TIME,
                                                                                            LOW_BATTERY_LED_FLASH_COUNT, (range: 0 ~ 254)
                                                                                            LOW_BATTERY_LED_TYPE
                                                                                        } \n
                                                                                        \#DESC_END
                                                                                        \#GROUP_ID : 0x06 \n
                                                                                        \#KEY_ID : 0x09 \n
                                                                            	    */
                                                                            	    
    LED_CFG_KEY_AV_LED_INDICATION                                       = 0x0A,     /**<\#PARAM_NAME : LED_CFG_KEY_AV_LED_INDICATION \n
                                                                                        \#ALIAS : AV LED INDICATION \n
                                                                                        \#PARAM_TYPE : Public \n
                                                                                        \#PARAM_DESC : The LED indication for the state which the speaker is playing via A2DP. \n
                                                                                        Format:
                                                                                        {
                                                                                            AV_LED_FLASH_ON_TIME,
                                                                                            AV_LED_FLASH_OFF_TIME,
                                                                                            AV_LED_FLASH_COUNT, (range: 0 ~ 3)
                                                                                            AV_LED_FLASH_INTERVAL,
                                                                                            AV_LED_TYPE
                                                                                        } \n
                                                                                        \#DESC_END
                                                                                        \#GROUP_ID : 0x06 \n
                                                                                        \#KEY_ID : 0x0A \n
                                                                            	    */
                                                                            	    
    LED_CFG_KEY_INCOMING_CALL_LED_INDICATION                            = 0x0B,     /**<\#PARAM_NAME : LED_CFG_KEY_INCOMING_CALL_LED_INDICATION \n
                                                                                        \#ALIAS : INCOMING CALL LED INDICATION \n
                                                                                        \#PARAM_TYPE : Public \n
                                                                                        \#PARAM_DESC : The LED indication for the state which the speaker has an incoming call. \n
                                                                                        Format:
                                                                                        {
                                                                                            INCOMING_CALL_LED_FLASH_ON_TIME,
                                                                                            INCOMING_CALL_LED_FLASH_OFF_TIME,
                                                                                            INCOMING_CALL_LED_FLASH_COUNT, (range: 0 ~ 3)
                                                                                            INCOMING_CALL_LED_FLASH_INTERVAL,
                                                                                            INCOMING_CALL_LED_TYPE
                                                                                        } \n
                                                                                        \#DESC_END
                                                                                        \#GROUP_ID : 0x06 \n
                                                                                        \#KEY_ID : 0x0B \n
                                                                            	    */
                                                                            	    
    LED_CFG_KEY_LINK_BACK_LED_INDICATION                                = 0x0C,     /**<\#PARAM_NAME : LED_CFG_KEY_LINK_BACK_LED_INDICATION \n
                                                                                        \#ALIAS : LINK BACK LED INDICATION \n
                                                                                        \#PARAM_TYPE : Public \n
                                                                                        \#PARAM_DESC : The LED indication for the state which the speaker is reconnecting to a device. \n
                                                                                        Format:
                                                                                        {
                                                                                            LINK_BACK_LED_FLASH_ON_TIME,
                                                                                            LINK_BACK_LED_FLASH_OFF_TIME,
                                                                                            LINK_BACK_LED_FLASH_COUNT, (range: 0 ~ 3)
                                                                                            LINK_BACK_LED_FLASH_INTERVAL,
                                                                                            LINK_BACK_LED_TYPE
                                                                                        } \n
                                                                                        \#DESC_END
                                                                                        \#GROUP_ID : 0x06 \n
                                                                                        \#KEY_ID : 0x0C \n
                                                                            	    */
                                                                            	    
    LED_CFG_KEY_MULTILINK_LED_INDICATION                                = 0x0D,     /**<\#PARAM_NAME : LED_CFG_KEY_MULTILINK_LED_INDICATION \n
                                                                                        \#ALIAS : MULTI-LINK LED INDICATION \n
                                                                                        \#PARAM_TYPE : Public \n
                                                                                        \#PARAM_DESC : The LED indication for the state which the speaker has more than one BT ACL link. \n
                                                                                        Format:
                                                                                        {
                                                                                            MULTILINK_LED_FLASH_ON_TIME,
                                                                                            MULTILINK_LED_FLASH_OFF_TIME,
                                                                                            MULTILINK_LED_FLASH_COUNT, (range: 0 ~ 3)
                                                                                            MULTILINK_LED_FLASH_INTERVAL,
                                                                                            MULTILINK_LED_TYPE
                                                                                        } \n
                                                                                        \#DESC_END
                                                                                        \#GROUP_ID : 0x06 \n
                                                                                        \#KEY_ID : 0x0D \n
                                                                            	    */
                                                                            	    
    LED_CFG_KEY_MIC_MUTE_LED_INDICATION                                 = 0x0E,     /**<\#PARAM_NAME : LED_CFG_KEY_MIC_MUTE_LED_INDICATION \n
                                                                                        \#ALIAS : MIC MUTE LED INDICATION \n
                                                                                        \#PARAM_TYPE : Public \n
                                                                                        \#PARAM_DESC : The LED indication for the state which the microphone of the speaker is muted. \n
                                                                                        Format:
                                                                                        {
                                                                                            MULTILINK_LED_FLASH_ON_TIME,
                                                                                            MULTILINK_LED_FLASH_OFF_TIME,
                                                                                            MULTILINK_LED_FLASH_COUNT, (range: 0 ~ 3)
                                                                                            MULTILINK_LED_FLASH_INTERVAL,
                                                                                            MULTILINK_LED_TYPE
                                                                                        } \n
                                                                                        \#DESC_END
                                                                                        \#GROUP_ID : 0x06 \n
                                                                                        \#KEY_ID : 0x0E \n
                                                                            	    */
                                                                            	    
    LED_CFG_KEY_LINEIN_LED_INDICATION                                   = 0x0F,     /**<\#PARAM_NAME : LED_CFG_KEY_LINEIN_LED_INDICATION \n
                                                                                        \#ALIAS : LINE IN LED INDICATION \n
                                                                                        \#PARAM_TYPE : Public \n
                                                                                        \#PARAM_DESC : The LED indication for the state which the speaker is in line-in mode. \n
                                                                                        Format:
                                                                                        {
                                                                                            LINEIN_LED_FLASH_ON_TIME,
                                                                                            LINEIN_LED_FLASH_OFF_TIME,
                                                                                            LINEIN_LED_FLASH_COUNT, (range: 0 ~ 3)
                                                                                            LINEIN_LED_FLASH_INTERVAL,
                                                                                            LINEIN_LED_TYPE (0xFF means no effect)
                                                                                        } \n
                                                                                        \#DESC_END
                                                                                        \#GROUP_ID : 0x06 \n
                                                                                        \#KEY_ID : 0x0F \n
                                                                            	    */
                                                                            	    
    LED_CFG_KEY_VOL_ADJUST_LED_INDICATION                               = 0x10,     /**<\#PARAM_NAME : LED_CFG_KEY_VOL_ADJUST_LED_INDICATION \n
                                                                                        \#ALIAS : VOL ADJUST LED_INDICATION \n
                                                                                        \#PARAM_TYPE : Public \n
                                                                                        \#PARAM_DESC : The LED indication for the event which the volume of the speaker is changed. \n
                                                                                        Format:
                                                                                        {                                                                                            
                                                                                            VOL_ADJUST_LED_FLASH_ON_TIME,
                                                                                            VOL_ADJUST_LED_FLASH_OFF_TIME,
                                                                                            VOL_ADJUST_LED_FLASH_COUNT,(range: 0 ~ 3)
                                                                                            VOL_ADJUST_LED_TYPE (0xFF means no effect)
                                                                                        } \n
                                                                                        \#DESC_END
                                                                                        \#GROUP_ID : 0x06 \n
                                                                                        \#KEY_ID : 0x10 \n
                                                                            	    */
                                                                            	    
    LED_CFG_KEY_MSPK_MODE_PAIRING_MASTER_INDICATION                     = 0x11,     /**<\#PARAM_NAME : LED_CFG_KEY_MSPK_MODE_PAIRING_MASTER_INDICATION \n
                                                                                        \#ALIAS : MSPK MODE PAIRING MASTER INDICATION \n
                                                                                        \#PARAM_TYPE : Public \n
                                                                                        \#PARAM_DESC : The LED indication for the state which the speaker is creating a MSPK link as master role. \n
                                                                                        Format:
                                                                                        {
                                                                                            MSPK_mode_pairing_master_on_time,
                                                                                            MSPK_mode_pairing_master_off_time,
                                                                                            MSPK_mode_pairing_master_count,
                                                                                            MSPK_mode_pairing_master_interval,
                                                                                            MSPK_mode_pairing_master_type
                                                                                        } \n
                                                                                        \#DESC_END
                                                                                        \#GROUP_ID : 0x06 \n
                                                                                        \#KEY_ID : 0x11 \n
                                                                            	    */
                                                                            	    
    LED_CFG_KEY_MSPK_MODE_PAIRING_SLAVE_INDICATION                      = 0x12,     /**<\#PARAM_NAME : LED_CFG_KEY_MSPK_MODE_PAIRING_SLAVE_INDICATION \n
                                                                                        \#ALIAS : MSPK MODE PAIRING SLAVE INDICATION \n
                                                                                        \#PARAM_TYPE : Public \n
                                                                                        \#PARAM_DESC : The LED indication for the state which the speaker as slave role is listening MSPK master. \n
                                                                                        Format:
                                                                                        {
                                                                                            MSPK_mode_pairing_slave_on_time,
                                                                                            MSPK_mode_pairing_slave_off_time,
                                                                                            MSPK_mode_pairing_slave_count,
                                                                                            MSPK_mode_pairing_slave_interval,
                                                                                            MSPK_mode_pairing_slave_type
                                                                                        } \n
                                                                                        \#DESC_END
                                                                                        \#GROUP_ID : 0x06 \n
                                                                                        \#KEY_ID : 0x12 \n
                                                                            	    */
                                                                            	    
    LED_CFG_KEY_MSPK_MODE_CONNECTED_BT_CONNECTED_MASTER_INDICATION      = 0x13,     /**<\#PARAM_NAME : LED_CFG_KEY_MSPK_MODE_CONNECTED_BT_CONNECTED_MASTER_INDICATION \n
                                                                                        \#ALIAS : MSPK MODE CONNECTED BT CONNECTED MASTER INDICATION \n
                                                                                        \#PARAM_TYPE : Public \n
                                                                                        \#PARAM_DESC : The LED indication for the state which the speaker as master role has both of MSPK link and BT link. \n
                                                                                        Format:
                                                                                        {
                                                                                            MSPK_mode_connected_bt_connected_master_on_time,
                                                                                            MSPK_mode_connected_bt_connected_master_off_time,
                                                                                            MSPK_mode_connected_bt_connected_master_count,
                                                                                            MSPK_mode_connected_bt_connected_master_interval,
                                                                                            MSPK_mode_connected_bt_connected_master_type
                                                                                        } \n
                                                                                        \#DESC_END
                                                                                        \#GROUP_ID : 0x06 \n
                                                                                        \#KEY_ID : 0x13 \n
                                                                            	    */
                                                                            	    
    LED_CFG_KEY_MSPK_MODE_CONNECTED_BT_PAIRING_MASTER_INDICATION        = 0x14,     /**<\#PARAM_NAME : LED_CFG_KEY_MSPK_MODE_CONNECTED_BT_PAIRING_MASTER_INDICATION \n
                                                                                        \#ALIAS : MSPK MODE CONNECTED BT PAIRING MASTER INDICATION \n
                                                                                        \#PARAM_TYPE : Public \n
                                                                                        \#PARAM_DESC : The LED indication for the state which the speaker as master role has MSPK link and is in pairing mode for BT link. \n
                                                                                        Format:
                                                                                        {
                                                                                            MSPK_mode_connected_bt_pairing_master_on_time,
                                                                                            MSPK_mode_connected_bt_pairing_master_off_time,
                                                                                            MSPK_mode_connected_bt_pairing_master_count,
                                                                                            MSPK_mode_connected_bt_pairing_master_interval,
                                                                                            MSPK_mode_connected_bt_pairing_master_type
                                                                                        } \n
                                                                                        \#DESC_END
                                                                                        \#GROUP_ID : 0x06 \n
                                                                                        \#KEY_ID : 0x14 \n
                                                                            	    */
                                                                            	    
    LED_CFG_KEY_MSPK_MODE_CONNECTED_BT_PAGING_MASTER_INDICATION         = 0x15,     /**<\#PARAM_NAME : LED_CFG_KEY_MSPK_MODE_CONNECTED_BT_PAGING_MASTER_INDICATION \n
                                                                                        \#ALIAS : MSPK MODE CONNECTED BT PAGING MASTER INDICATION \n
                                                                                        \#PARAM_TYPE : Public \n
                                                                                        \#PARAM_DESC : The LED indication for the state which the speaker as master role has MSPK link and is reconnecting BT link. \n
                                                                                        Format:
                                                                                        {
                                                                                            MSPK_mode_connected_bt_paging_master_on_time,
                                                                                            MSPK_mode_connected_bt_paging_master_off_time,
                                                                                            MSPK_mode_connected_bt_paging_master_count,
                                                                                            MSPK_mode_connected_bt_paging_master_interval,
                                                                                            MSPK_mode_connected_bt_paging_master_type
                                                                                        } \n
                                                                                        \#DESC_END
                                                                                        \#GROUP_ID : 0x06 \n
                                                                                        \#KEY_ID : 0x15 \n
                                                                            	    */
                                                                            	    
    LED_CFG_KEY_MSPK_MODE_CONNECTED_BT_WAITING_MASTER_INDICATION        = 0x16,     /**<\#PARAM_NAME : LED_CFG_KEY_MSPK_MODE_CONNECTED_BT_WAITING_MASTER_INDICATION \n
                                                                                        \#ALIAS : MSPK MODE CONNECTED_BT WAITING MASTER INDICATION \n
                                                                                        \#PARAM_TYPE : Public \n
                                                                                        \#PARAM_DESC : The LED indication for the state which the speaker as master role has MSPK link but no BT link. \n
                                                                                        Format:
                                                                                        {
                                                                                            MSPK_mode_connected_bt_waiting_master_on_time,
                                                                                            MSPK_mode_connected_bt_waiting_master_off_time,
                                                                                            MSPK_mode_connected_bt_waiting_master_count,
                                                                                            MSPK_mode_connected_bt_waiting_master_interval,
                                                                                            MSPK_mode_connected_bt_waiting_master_type
                                                                                        } \n
                                                                                        \#DESC_END
                                                                                        \#GROUP_ID : 0x06 \n
                                                                                        \#KEY_ID : 0x16 \n
                                                                            	    */
                                                                            	    
    LED_CFG_KEY_STEREO_MODE_CONNECTED_SLAVE_INDICATION        = 0x17,     /**<\#PARAM_NAME : LED_CFG_KEY_STEREO_MODE_CONNECTED_SLAVE_INDICATION \n
                                                                                        \#ALIAS : STEREO MODE CONNECTED BT WAITING SLAVE INDICATION \n
                                                                                        \#PARAM_TYPE : Public \n
                                                                                        \#PARAM_DESC : The LED indication for the state which the speaker has Stereo MSPK link as slave role. \n 
                                                                                        Format:
                                                                                        {
                                                                                            stereo_mode_connected_bt_wainting_slave_on_time,
                                                                                            stereo_mode_connected_bt_wainting_slave_off_time,
                                                                                            stereo_mode_connected_bt_wainting_slave_count,
                                                                                            stereo_mode_connected_bt_wainting_slave_interval,
                                                                                            stereo_mode_connected_bt_wainting_slave_type
                                                                                        } \n
                                                                                        \#DESC_END
                                                                                        \#GROUP_ID : 0x06 \n
                                                                                        \#KEY_ID : 0x17 \n
                                                                            	    */
                                                                            	    
    LED_CFG_KEY_CONCERT_MODE_CONNECTED_SLAVE_INDICATION    = 0x18,     /**<\#PARAM_NAME : LED_CFG_KEY_CONCERT_MODE_CONNECTED_SLAVE_INDICATION \n
                                                                                        \#ALIAS : CONCERT MODE CONNECTED SLAVE INDICATION \n
                                                                                        \#PARAM_TYPE : Public \n
                                                                                        \#PARAM_DESC : The LED indication for the state which the speaker has Concert MSPK link as slave role. \n
                                                                                        Format:
                                                                                        {
                                                                                            concert_mode_connected_bt_waiting_slave_on_time,
                                                                                            concert_mode_connected_bt_waiting_slave_off_time,
                                                                                            concert_mode_connected_bt_waiting_slave_count,
                                                                                            concert_mode_connected_bt_waiting_slave_interval,
                                                                                            concert_mode_connected_bt_waiting_slave_type
                                                                                        } \n
                                                                                        \#DESC_END
                                                                                        \#GROUP_ID : 0x06 \n
                                                                                        \#KEY_ID : 0x18 \n
                                                                            	    */
                                                                            	    
    LED_CFG_KEY_LED_OPTION                                              = 0x19,     /**<\#PARAM_NAME : LED_CFG_KEY_LED_OPTION \n
                                                                                        \#PARAM_TYPE : Public \n
                                                                                        \#GROUP_ID : 0x06 \n
                                                                                        \#KEY_ID : 0x19 \n
                                                                                        \par
                                                                                	    \#BIT_PARAM : DEDICATE_LINEIN_LED_ENABLE \n
                                                                                	    \#BIT_ALIAS : Line In Indicate LED \n
                                                                                	    \#BIT_POS : 0 \n
                                                                                	    \#BIT_SIZE : 1 \n
                                                                                	    \#BIT_DESC : Use the GPIO pin to indicate Aux-in status if this option is enabled (set to 1). \n
                                                                                                       The pin is low active, 0 means the speaker is in Aux-in mode. Please refer to GPIO configuration to check which pin is used for this function. \n
                                                                                                       This one is effective only when you enable it and assign a GPIO in item "AUX-IN Led Ind". \n
                                                                                	    \#DESC_END

                                                                                	    \par
                                                                                	    \#BIT_PARAM : DISABLE_CHARGER_LED_INDICATION \n
                                                                                	    \#BIT_ALIAS : Charging  Led Indication Setting \n
                                                                                	    \#BIT_POS : 1 \n
                                                                                	    \#BIT_SIZE : 1 \n
                                                                                	    \#BIT_DESC : Don't indicate the charging status in LED1 and LED2 if this option is enabled. \n
                                                                                                       1: Don't indicate the charging status in LED1 and LED2 \n
                                                                                                       0: Indicate the charging status in LED1 and LED2 \n
                                                                                	    \#DESC_END
                                                                            	    */
                                                                            	    
    LED_CFG_KEY_LED_BRIGHTNESS                                          = 0x1A,     /**<\#PARAM_NAME : LED_CFG_KEY_LED_BRIGHTNESS \n
                                                                                        \#PARAM_TYPE : Public \n
                                                                                        \#GROUP_ID : 0x06 \n
                                                                                        \#KEY_ID : 0x1A \n
                                                                                        \par
                                                                                	    \#BIT_PARAM : LED1_BRIGHTNESS \n
                                                                                	    \#BIT_ALIAS : LED1 Brightness \n
                                                                                	    \#BIT_POS : 0 \n
                                                                                	    \#BIT_SIZE : 4 \n
                                                                                	    \#BIT_DESC : The brightness setting of LED1 \n
                                                                                	    \#DESC_END

                                                                                	    \par
                                                                                	    \#BIT_PARAM : LED2_BRIGHTNESS \n
                                                                                	    \#BIT_ALIAS : LED2 Brightness \n
                                                                                	    \#BIT_POS : 4 \n
                                                                                	    \#BIT_SIZE : 4 \n
                                                                                	    \#BIT_DESC : The brightness setting of LED2 \n
                                                                                	    \#DESC_END
                                                                            	    */
                                                                            	    
    LED_CFG_KEY_LOW_BATT_DISALLOW_POWER_ON_LED_INDICATION				= 0x1B,     /**<\#PARAM_NAME : LED_CFG_KEY_LOW_BATT_DISALLOW_POWER_ON_LED_INDICATION \n
                                                                                        \#ALIAS : LOW BATTERY DISALLOW POWER ON LED INDICATION \n
                                                                                        \#PARAM_TYPE : Public \n
                                                                                        \#PARAM_DESC : The LED indication for the event which the speaker can't power on due to low battery voltage. \n
                                                                                        Format:
                                                                                        {
                                                                                            low_batt_disallow_power_on_on_time,
                                                                                            low_batt_disallow_power_on_off_time,
                                                                                            low_batt_disallow_power_on_count,
                                                                                            low_batt_disallow_power_on_type
                                                                                        } \n
                                                                                        \#DESC_END
                                                                                        \#GROUP_ID : 0x06 \n
                                                                                        \#KEY_ID : 0x1B \n
                                                                            	    */
                                                                            	    

    LED_CFG_KEY_END
}LED_CFG_Key_IdDefinition_T;

/**@defgroup LED_CFG_DEFAULT_VALUE LED Configuration Default Value
 * @brief Default value definition of the module @ref CFG_MODULE_ID_LED.
 * @{ */

//Module LED
#define LED_CFG_KEY_CHARGER_LED_OPTION_LEN                                              0x01    /**< The default length of @ref LED_CFG_KEY_CHARGER_LED_OPTION. */
#define LED_CFG_KEY_CHARGER_LED_OPTION_DEFAULT_VALUE                                    0x00    /**< The default value of @ref LED_CFG_KEY_CHARGER_LED_OPTION. */

#define LED_CFG_KEY_STANDBY_LED_INDICATION_LEN                                          0x05                            /**< The default length of @ref LED_CFG_KEY_STANDBY_LED_INDICATION. */
#define LED_CFG_KEY_STANDBY_LED_INDICATION_DEFAULT_VALUE                                0x01, 0x04, 0x01, 0x64, 0x05    /**< The default value of @ref LED_CFG_KEY_STANDBY_LED_INDICATION. */

#define LED_CFG_KEY_LINK_LED_INDICATION_LEN                                             0x05                            /**< The default length of @ref LED_CFG_KEY_LINK_LED_INDICATION. */
#define LED_CFG_KEY_LINK_LED_INDICATION_DEFAULT_VALUE                                   0x01, 0x04, 0x02, 0x64, 0x05    /**< The default value of @ref LED_CFG_KEY_LINK_LED_INDICATION. */

#define LED_CFG_KEY_TALK_LED_INDICATION_LEN                                             0x05                            /**< The default length of @ref LED_CFG_KEY_TALK_LED_INDICATION. */
#define LED_CFG_KEY_TALK_LED_INDICATION_DEFAULT_VALUE                                   0x01, 0x04, 0x03, 0x3C, 0x08    /**< The default value of @ref LED_CFG_KEY_TALK_LED_INDICATION. */

#define LED_CFG_KEY_PAIRING_LED_INDICATION_LEN                                          0x05                            /**< The default length of @ref LED_CFG_KEY_PAIRING_LED_INDICATION. */
#define LED_CFG_KEY_PAIRING_LED_INDICATION_DEFAULT_VALUE                                0x0A, 0x0A, 0x00, 0x00, 0x09    /**< The default value of @ref LED_CFG_KEY_PAIRING_LED_INDICATION. */

#define LED_CFG_KEY_POWER_ON_LED_INDICATION_LEN                                         0x04                            /**< The default length of @ref LED_CFG_KEY_POWER_ON_LED_INDICATION. */
#define LED_CFG_KEY_POWER_ON_LED_INDICATION_DEFAULT_VALUE                               0x02, 0x02, 0x03, 0x08          /**< The default value of @ref LED_CFG_KEY_POWER_ON_LED_INDICATION. */

#define LED_CFG_KEY_POWER_OFF_LED_INDICATION_LEN                                        0x04                            /**< The default length of @ref LED_CFG_KEY_POWER_OFF_LED_INDICATION. */
#define LED_CFG_KEY_POWER_OFF_LED_INDICATION_DEFAULT_VALUE                              0x02, 0x02, 0x03, 0x08          /**< The default value of @ref LED_CFG_KEY_POWER_OFF_LED_INDICATION. */

#define LED_CFG_KEY_PAIRING_OK_LED_INDICATION_LEN                                       0x04                            /**< The default length of @ref LED_CFG_KEY_PAIRING_OK_LED_INDICATION. */
#define LED_CFG_KEY_PAIRING_OK_LED_INDICATION_DEFAULT_VALUE                             0x02, 0x02, 0x0A, 0x05          /**< The default value of @ref LED_CFG_KEY_PAIRING_OK_LED_INDICATION. */

#define LED_CFG_KEY_LOW_BATTERY_LED_INDICATION_LEN                                      0x04                            /**< The default length of @ref LED_CFG_KEY_LOW_BATTERY_LED_INDICATION. */  
#define LED_CFG_KEY_LOW_BATTERY_LED_INDICATION_DEFAULT_VALUE                            0x02, 0x02, 0x02, 0x04          /**< The default value of @ref LED_CFG_KEY_LOW_BATTERY_LED_INDICATION. */

#define LED_CFG_KEY_AV_LED_INDICATION_LEN                                               0x05                            /**< The default length of @ref LED_CFG_KEY_AV_LED_INDICATION. */
#define LED_CFG_KEY_AV_LED_INDICATION_DEFAULT_VALUE                                     0x02, 0x02, 0x01, 0x64, 0x08    /**< The default value of @ref LED_CFG_KEY_AV_LED_INDICATION. */

#define LED_CFG_KEY_INCOMING_CALL_LED_INDICATION_LEN                                    0x05                            /**< The default length of @ref LED_CFG_KEY_INCOMING_CALL_LED_INDICATION. */
#define LED_CFG_KEY_INCOMING_CALL_LED_INDICATION_DEFAULT_VALUE                          0x01, 0x03, 0x03, 0x64, 0x05    /**< The default value of @ref LED_CFG_KEY_INCOMING_CALL_LED_INDICATION. */

#define LED_CFG_KEY_LINK_BACK_LED_INDICATION_LEN                                        0x05                            /**< The default length of @ref LED_CFG_KEY_LINK_BACK_LED_INDICATION. */
#define LED_CFG_KEY_LINK_BACK_LED_INDICATION_DEFAULT_VALUE                              0x01, 0x03, 0x01, 0x0A, 0x05    /**< The default value of @ref LED_CFG_KEY_LINK_BACK_LED_INDICATION. */

#define LED_CFG_KEY_MULTILINK_LED_INDICATION_LEN                                        0x05                            /**< The default length of @ref LED_CFG_KEY_MULTILINK_LED_INDICATION. */
#define LED_CFG_KEY_MULTILINK_LED_INDICATION_DEFAULT_VALUE                              0x01, 0x04, 0x02, 0x64, 0x04    /**< The default value of @ref LED_CFG_KEY_MULTILINK_LED_INDICATION. */

#define LED_CFG_KEY_MIC_MUTE_LED_INDICATION_LEN                                         0x05                            /**< The default length of @ref LED_CFG_KEY_MIC_MUTE_LED_INDICATION. */
#define LED_CFG_KEY_MIC_MUTE_LED_INDICATION_DEFAULT_VALUE                               0x01, 0x04, 0x03, 0x3C, 0x08    /**< The default value of @ref LED_CFG_KEY_MIC_MUTE_LED_INDICATION. */

#define LED_CFG_KEY_LINEIN_LED_INDICATION_LEN                                           0x05                            /**< The default length of @ref LED_CFG_KEY_LINEIN_LED_INDICATION. */
#define LED_CFG_KEY_LINEIN_LED_INDICATION_DEFAULT_VALUE                                 0x02, 0x02, 0x01, 0x64, 0xFF    /**< The default value of @ref LED_CFG_KEY_LINEIN_LED_INDICATION. */

#define LED_CFG_KEY_VOL_ADJUST_LED_INDICATION_LEN                                       0x04                            /**< The default length of @ref LED_CFG_KEY_VOL_ADJUST_LED_INDICATION. */
#define LED_CFG_KEY_VOL_ADJUST_LED_INDICATION_DEFAULT_VALUE                             0x02, 0x02, 0x02, 0xFF          /**< The default value of @ref LED_CFG_KEY_VOL_ADJUST_LED_INDICATION. */

#define LED_CFG_KEY_MSPK_MODE_PAIRING_MASTER_INDICATION_LEN                              0x05                           /**< The default length of @ref LED_CFG_KEY_MSPK_MODE_PAIRING_MASTER_INDICATION. */
#define LED_CFG_KEY_MSPK_MODE_PAIRING_MASTER_INDICATION_DEFAULT_VALUE                    0x03, 0x03, 0x03, 0x25, 0x05   /**< The default value of @ref LED_CFG_KEY_MSPK_MODE_PAIRING_MASTER_INDICATION. */

#define LED_CFG_KEY_MSPK_MODE_PAIRING_SLAVE_INDICATION_LEN                               0x05                           /**< The default length of @ref LED_CFG_KEY_MSPK_MODE_PAIRING_SLAVE_INDICATION. */
#define LED_CFG_KEY_MSPK_MODE_PAIRING_SLAVE_INDICATION_DEFAULT_VALUE                     0x03, 0x03, 0x03, 0x25, 0x04   /**< The default value of @ref LED_CFG_KEY_MSPK_MODE_PAIRING_SLAVE_INDICATION. */

#define LED_CFG_KEY_MSPK_MODE_CONNECTED_BT_CONNECTED_MASTER_INDICATION_LEN               0x05                           /**< The default length of @ref LED_CFG_KEY_MSPK_MODE_CONNECTED_BT_CONNECTED_MASTER_INDICATION. */
#define LED_CFG_KEY_MSPK_MODE_CONNECTED_BT_CONNECTED_MASTER_INDICATION_DEFAULT_VALUE     0x01, 0x04, 0x02, 0x05, 0x02   /**< The default value of @ref LED_CFG_KEY_MSPK_MODE_CONNECTED_BT_CONNECTED_MASTER_INDICATION. */

#define LED_CFG_KEY_MSPK_MODE_CONNECTED_BT_PAIRING_MASTER_INDICATION_LEN                 0x05                           /**< The default length of @ref LED_CFG_KEY_MSPK_MODE_CONNECTED_BT_PAIRING_MASTER_INDICATION. */
#define LED_CFG_KEY_MSPK_MODE_CONNECTED_BT_PAIRING_MASTER_INDICATION_DEFAULT_VALUE       0x03, 0x03, 0x00, 0x00, 0x05   /**< The default value of @ref LED_CFG_KEY_MSPK_MODE_CONNECTED_BT_PAIRING_MASTER_INDICATION. */

#define LED_CFG_KEY_MSPK_MODE_CONNECTED_BT_PAGING_MASTER_INDICATION_LEN                  0x05                           /**< The default length of @ref LED_CFG_KEY_MSPK_MODE_CONNECTED_BT_PAGING_MASTER_INDICATION. */
#define LED_CFG_KEY_MSPK_MODE_CONNECTED_BT_PAGING_MASTER_INDICATION_DEFAULT_VALUE        0x01, 0x04, 0x02, 0x64, 0x05   /**< The default value of @ref LED_CFG_KEY_MSPK_MODE_CONNECTED_BT_PAGING_MASTER_INDICATION. */

#define LED_CFG_KEY_MSPK_MODE_CONNECTED_BT_WAITING_MASTER_INDICATION_LEN                 0x05                           /**< The default length of @ref LED_CFG_KEY_MSPK_MODE_CONNECTED_BT_WAITING_MASTER_INDICATION. */
#define LED_CFG_KEY_MSPK_MODE_CONNECTED_BT_WAITING_MASTER_INDICATION_DEFAULT_VALUE       0x10, 0x10, 0x00, 0x00, 0x05   /**< The default value of @ref LED_CFG_KEY_MSPK_MODE_CONNECTED_BT_WAITING_MASTER_INDICATION. */

#define LED_CFG_KEY_STEREO_MODE_CONNECTED_SLAVE_INDICATION_LEN                 0x05                           /**< The default length of @ref LED_CFG_KEY_STEREO_MODE_CONNECTED_SLAVE_INDICATION. */
#define LED_CFG_KEY_STEREO_MODE_CONNECTED_SLAVE_INDICATION_DEFAULT_VALUE       0x10, 0x10, 0x00, 0x00, 0x03   /**< The default value of @ref LED_CFG_KEY_STEREO_MODE_CONNECTED_SLAVE_INDICATION. */

#define LED_CFG_KEY_CONCERT_MODE_CONNECTED_SLAVE_INDICATION_LEN             0x05                           /**< The default length of @ref LED_CFG_KEY_CONCERT_MODE_CONNECTED_SLAVE_INDICATION. */
#define LED_CFG_KEY_CONCERT_MODE_CONNECTED_SLAVE_INDICATION_DEFAULT_VALUE   0x10, 0x10, 0x00, 0x00, 0x03   /**< The default value of @ref LED_CFG_KEY_CONCERT_MODE_CONNECTED_SLAVE_INDICATION. */

#define LED_CFG_KEY_LED_OPTION_LEN                                                       0x01                           /**< The default length of @ref LED_CFG_KEY_LED_OPTION. */
#define LED_CFG_KEY_LED_OPTION_DEFAULT_VALUE                                             0x00                           /**< The default value of @ref LED_CFG_KEY_LED_OPTION. */

#define LED_CFG_KEY_LED_BRIGHTNESS_LEN                                                   0x01                           /**< The default length of @ref LED_CFG_KEY_LED_BRIGHTNESS. */
#define LED_CFG_KEY_LED_BRIGHTNESS_DEFAULT_VALUE                                         0x88                           /**< The default value of @ref LED_CFG_KEY_LED_BRIGHTNESS. */

#define LED_CFG_KEY_LOW_BATT_DISALLOW_POWER_ON_LED_INDICATION_LEN                        0x04                           /**< The default length of @ref LED_CFG_KEY_LOW_BATT_DISALLOW_POWER_ON_LED_INDICATION. */
#define LED_CFG_KEY_LOW_BATT_DISALLOW_POWER_ON_LED_INDICATION_DEFAULT_VALUE              0x02, 0x02, 0x03, 0x08         /**< The default value of @ref LED_CFG_KEY_LOW_BATT_DISALLOW_POWER_ON_LED_INDICATION. */

/** @} */
/** @} */

/** \cond NON_DOC */

#define CFG_LED_MODULE_TOTAL_NUM_KEYS   (LED_CFG_KEY_END - 1)

#define CFG_LED_MODULE_TOTAL_SIZE   ((CFG_LED_MODULE_TOTAL_NUM_KEYS*SIZEOF_CFG_KEY_STRUCT) +                   \
                                    LED_CFG_KEY_CHARGER_LED_OPTION_LEN +                                    \
                                    LED_CFG_KEY_STANDBY_LED_INDICATION_LEN +                                \
                                    LED_CFG_KEY_LINK_LED_INDICATION_LEN +                                   \
                                    LED_CFG_KEY_TALK_LED_INDICATION_LEN +                                   \
                                    LED_CFG_KEY_PAIRING_LED_INDICATION_LEN +                                \
                                    LED_CFG_KEY_POWER_ON_LED_INDICATION_LEN +                               \
                                    LED_CFG_KEY_POWER_OFF_LED_INDICATION_LEN +                              \
                                    LED_CFG_KEY_PAIRING_OK_LED_INDICATION_LEN +                             \
                                    LED_CFG_KEY_LOW_BATTERY_LED_INDICATION_LEN +                            \
                                    LED_CFG_KEY_AV_LED_INDICATION_LEN +                                     \
                                    LED_CFG_KEY_INCOMING_CALL_LED_INDICATION_LEN +                          \
                                    LED_CFG_KEY_LINK_BACK_LED_INDICATION_LEN +                              \
                                    LED_CFG_KEY_MULTILINK_LED_INDICATION_LEN +                              \
                                    LED_CFG_KEY_MIC_MUTE_LED_INDICATION_LEN +                               \
                                    LED_CFG_KEY_LINEIN_LED_INDICATION_LEN +                                 \
                                    LED_CFG_KEY_VOL_ADJUST_LED_INDICATION_LEN +                             \
                                    LED_CFG_KEY_MSPK_MODE_PAIRING_MASTER_INDICATION_LEN +                   \
                                    LED_CFG_KEY_MSPK_MODE_PAIRING_SLAVE_INDICATION_LEN +                    \
                                    LED_CFG_KEY_MSPK_MODE_CONNECTED_BT_CONNECTED_MASTER_INDICATION_LEN +    \
                                    LED_CFG_KEY_MSPK_MODE_CONNECTED_BT_PAIRING_MASTER_INDICATION_LEN +      \
                                    LED_CFG_KEY_MSPK_MODE_CONNECTED_BT_PAGING_MASTER_INDICATION_LEN +       \
                                    LED_CFG_KEY_MSPK_MODE_CONNECTED_BT_WAITING_MASTER_INDICATION_LEN +      \
                                    LED_CFG_KEY_STEREO_MODE_CONNECTED_SLAVE_INDICATION_LEN +      \
                                    LED_CFG_KEY_CONCERT_MODE_CONNECTED_SLAVE_INDICATION_LEN +  \
                                    LED_CFG_KEY_LED_OPTION_LEN +                                            \
                                    LED_CFG_KEY_LED_BRIGHTNESS_LEN +                                        \
                                    LED_CFG_KEY_LOW_BATT_DISALLOW_POWER_ON_LED_INDICATION_LEN)


//LED Config keys definition
#define CFG_LED_MODULE_DEFAULT_VALUE    CFG_MODULE_ID_LED,               /*moduleID*/   \
                                        CFG_LED_MODULE_TOTAL_NUM_KEYS,   /*numKeys*/    \
                                        (CFG_LED_MODULE_TOTAL_SIZE >> 8),  /*moduleSize*/  \
                                        CFG_LED_MODULE_TOTAL_SIZE,                      \
                                        /*CFG_KEYs[numKeys]*/                           \
                                        /*    //ID                                                                                                             //Len                                                                                                                        //Value    */                                                           \
                                        LED_CFG_KEY_CHARGER_LED_OPTION,                                     LED_CFG_KEY_CHARGER_LED_OPTION_LEN,                                     LED_CFG_KEY_CHARGER_LED_OPTION_DEFAULT_VALUE,                                   \
                                        LED_CFG_KEY_STANDBY_LED_INDICATION,                                 LED_CFG_KEY_STANDBY_LED_INDICATION_LEN,                                 LED_CFG_KEY_STANDBY_LED_INDICATION_DEFAULT_VALUE,                               \ 
                                        LED_CFG_KEY_LINK_LED_INDICATION,                                    LED_CFG_KEY_LINK_LED_INDICATION_LEN,                                    LED_CFG_KEY_LINK_LED_INDICATION_DEFAULT_VALUE,                                  \
                                        LED_CFG_KEY_TALK_LED_INDICATION,                                    LED_CFG_KEY_TALK_LED_INDICATION_LEN,                                    LED_CFG_KEY_TALK_LED_INDICATION_DEFAULT_VALUE,                                  \
                                        LED_CFG_KEY_PAIRING_LED_INDICATION,                                 LED_CFG_KEY_PAIRING_LED_INDICATION_LEN,                                 LED_CFG_KEY_PAIRING_LED_INDICATION_DEFAULT_VALUE,                               \
                                        LED_CFG_KEY_POWER_ON_LED_INDICATION,                                LED_CFG_KEY_POWER_ON_LED_INDICATION_LEN,                                LED_CFG_KEY_POWER_ON_LED_INDICATION_DEFAULT_VALUE,                              \
                                        LED_CFG_KEY_POWER_OFF_LED_INDICATION,                               LED_CFG_KEY_POWER_OFF_LED_INDICATION_LEN,                               LED_CFG_KEY_POWER_OFF_LED_INDICATION_DEFAULT_VALUE,                             \
                                        LED_CFG_KEY_PAIRING_OK_LED_INDICATION,                              LED_CFG_KEY_PAIRING_OK_LED_INDICATION_LEN,                              LED_CFG_KEY_PAIRING_OK_LED_INDICATION_DEFAULT_VALUE,                            \
                                        LED_CFG_KEY_LOW_BATTERY_LED_INDICATION,                             LED_CFG_KEY_LOW_BATTERY_LED_INDICATION_LEN,                             LED_CFG_KEY_LOW_BATTERY_LED_INDICATION_DEFAULT_VALUE,                           \
                                        LED_CFG_KEY_AV_LED_INDICATION,                                      LED_CFG_KEY_AV_LED_INDICATION_LEN,                                      LED_CFG_KEY_AV_LED_INDICATION_DEFAULT_VALUE,                                    \
                                        LED_CFG_KEY_INCOMING_CALL_LED_INDICATION,                           LED_CFG_KEY_INCOMING_CALL_LED_INDICATION_LEN,                           LED_CFG_KEY_INCOMING_CALL_LED_INDICATION_DEFAULT_VALUE,                         \
                                        LED_CFG_KEY_LINK_BACK_LED_INDICATION,                               LED_CFG_KEY_LINK_BACK_LED_INDICATION_LEN,                               LED_CFG_KEY_LINK_BACK_LED_INDICATION_DEFAULT_VALUE,                             \
                                        LED_CFG_KEY_MULTILINK_LED_INDICATION,                               LED_CFG_KEY_MULTILINK_LED_INDICATION_LEN,                               LED_CFG_KEY_MULTILINK_LED_INDICATION_DEFAULT_VALUE,                             \
                                        LED_CFG_KEY_MIC_MUTE_LED_INDICATION,                                LED_CFG_KEY_MIC_MUTE_LED_INDICATION_LEN,                                LED_CFG_KEY_MIC_MUTE_LED_INDICATION_DEFAULT_VALUE,                              \
                                        LED_CFG_KEY_LINEIN_LED_INDICATION,                                  LED_CFG_KEY_LINEIN_LED_INDICATION_LEN,                                  LED_CFG_KEY_LINEIN_LED_INDICATION_DEFAULT_VALUE,                                \
                                        LED_CFG_KEY_VOL_ADJUST_LED_INDICATION,                              LED_CFG_KEY_VOL_ADJUST_LED_INDICATION_LEN,                              LED_CFG_KEY_VOL_ADJUST_LED_INDICATION_DEFAULT_VALUE,                            \
                                        LED_CFG_KEY_MSPK_MODE_PAIRING_MASTER_INDICATION,                    LED_CFG_KEY_MSPK_MODE_PAIRING_MASTER_INDICATION_LEN,                    LED_CFG_KEY_MSPK_MODE_PAIRING_MASTER_INDICATION_DEFAULT_VALUE,                  \
                                        LED_CFG_KEY_MSPK_MODE_PAIRING_SLAVE_INDICATION,                     LED_CFG_KEY_MSPK_MODE_PAIRING_SLAVE_INDICATION_LEN,                     LED_CFG_KEY_MSPK_MODE_PAIRING_SLAVE_INDICATION_DEFAULT_VALUE,                   \
                                        LED_CFG_KEY_MSPK_MODE_CONNECTED_BT_CONNECTED_MASTER_INDICATION,     LED_CFG_KEY_MSPK_MODE_CONNECTED_BT_CONNECTED_MASTER_INDICATION_LEN,     LED_CFG_KEY_MSPK_MODE_CONNECTED_BT_CONNECTED_MASTER_INDICATION_DEFAULT_VALUE,   \
                                        LED_CFG_KEY_MSPK_MODE_CONNECTED_BT_PAIRING_MASTER_INDICATION,       LED_CFG_KEY_MSPK_MODE_CONNECTED_BT_PAIRING_MASTER_INDICATION_LEN,       LED_CFG_KEY_MSPK_MODE_CONNECTED_BT_PAIRING_MASTER_INDICATION_DEFAULT_VALUE,     \
                                        LED_CFG_KEY_MSPK_MODE_CONNECTED_BT_PAGING_MASTER_INDICATION,        LED_CFG_KEY_MSPK_MODE_CONNECTED_BT_PAGING_MASTER_INDICATION_LEN,        LED_CFG_KEY_MSPK_MODE_CONNECTED_BT_PAGING_MASTER_INDICATION_DEFAULT_VALUE,      \
                                        LED_CFG_KEY_MSPK_MODE_CONNECTED_BT_WAITING_MASTER_INDICATION,       LED_CFG_KEY_MSPK_MODE_CONNECTED_BT_WAITING_MASTER_INDICATION_LEN,       LED_CFG_KEY_MSPK_MODE_CONNECTED_BT_WAITING_MASTER_INDICATION_DEFAULT_VALUE,     \
                                        LED_CFG_KEY_STEREO_MODE_CONNECTED_SLAVE_INDICATION,       LED_CFG_KEY_STEREO_MODE_CONNECTED_SLAVE_INDICATION_LEN,       LED_CFG_KEY_STEREO_MODE_CONNECTED_SLAVE_INDICATION_DEFAULT_VALUE,     \
                                        LED_CFG_KEY_CONCERT_MODE_CONNECTED_SLAVE_INDICATION,   LED_CFG_KEY_CONCERT_MODE_CONNECTED_SLAVE_INDICATION_LEN,   LED_CFG_KEY_CONCERT_MODE_CONNECTED_SLAVE_INDICATION_DEFAULT_VALUE, \
                                        LED_CFG_KEY_LED_OPTION,                                             LED_CFG_KEY_LED_OPTION_LEN,                                             LED_CFG_KEY_LED_OPTION_DEFAULT_VALUE,                                           \
                                        LED_CFG_KEY_LED_BRIGHTNESS,                                         LED_CFG_KEY_LED_BRIGHTNESS_LEN,                                         LED_CFG_KEY_LED_BRIGHTNESS_DEFAULT_VALUE,                                       \
                                        LED_CFG_KEY_LOW_BATT_DISALLOW_POWER_ON_LED_INDICATION,              LED_CFG_KEY_LOW_BATT_DISALLOW_POWER_ON_LED_INDICATION_LEN,              LED_CFG_KEY_LOW_BATT_DISALLOW_POWER_ON_LED_INDICATION_DEFAULT_VALUE


#define LED_CHARGE_COMPLETE_RLS_CTRL                (0)
#define LED_CHARGE_COMPLETE_LED0_ON_ONCE            (1)
#define LED_CHARGE_COMPLETE_LED0_ON_LED1_RLS_CTRL   (2)
#define LED_CHARGE_COMPLETE_LED0_OFF_LED1_RLS_CTRL  (3)

#define LED_CHARGE_ERROR_SAME_AS_CHG_CPL            (0)
#define LED_CHARGE_ERROR_LED0_OFF_LED1_FLASH        (1)

typedef struct _APP_Cfg_LedParam5_T
{
    uint8_t flashOn;
    uint8_t flashOff;
    uint8_t flashCount;
    uint8_t flashInterval;
    uint8_t type;
} APP_Cfg_LedParam5_T;

typedef struct _APP_Cfg_LedParam4_T
{
    uint8_t flashOn;
    uint8_t flashOff;
    uint8_t flashCount;
    uint8_t type;
} APP_Cfg_LedParam4_T;

typedef struct _APP_Cfg_LedChargerOption_T
{
    uint8_t ChargeCompleteOption : 4;
    uint8_t ChargeErrorOption : 4;
} APP_Cfg_LedChargerOption_T;

typedef struct _APP_Cfg_LedOption_T
{
    uint8_t dedicateLineInLed : 1;
    uint8_t disableChargerControlLed : 1;
    uint8_t reserved : 6;
} APP_Cfg_LedOption_T;



void APP_CFG_ReadLedChargerOption(APP_Cfg_LedChargerOption_T XDATA *p_option);
void APP_CFG_ReadLedStandbyIndication(APP_Cfg_LedParam5_T XDATA *p_param);
void APP_CFG_ReadLedLinkIndication(APP_Cfg_LedParam5_T XDATA *p_param);
void APP_CFG_ReadLedTalkIndication(APP_Cfg_LedParam5_T XDATA *p_param);
void APP_CFG_ReadLedPairingIndication(APP_Cfg_LedParam5_T XDATA *p_param);
void APP_CFG_ReadLedPowerOnIndication(APP_Cfg_LedParam4_T XDATA *p_param);
void APP_CFG_ReadLedPowerOffIndication(APP_Cfg_LedParam4_T XDATA *p_param);
void APP_CFG_ReadLedPairingOkIndication(APP_Cfg_LedParam4_T XDATA *p_param);
void APP_CFG_ReadLedLowBatteryIndication(APP_Cfg_LedParam4_T XDATA *p_param);
void APP_CFG_ReadLedAvIndication(APP_Cfg_LedParam5_T XDATA *p_param);
void APP_CFG_ReadLedIncomingCallIndication(APP_Cfg_LedParam5_T XDATA *p_param);
void APP_CFG_ReadLedLinkbackIndication(APP_Cfg_LedParam5_T XDATA *p_param);
void APP_CFG_ReadLedMultiLinkIndication(APP_Cfg_LedParam5_T XDATA *p_param);
void APP_CFG_ReadLedMicMuteIndication(APP_Cfg_LedParam5_T XDATA *p_param);
void APP_CFG_ReadLedLineinIndication(APP_Cfg_LedParam5_T XDATA *p_param);
void APP_CFG_ReadLedVolAdjustIndication(APP_Cfg_LedParam4_T XDATA *p_param);
void APP_CFG_ReadLedMspkPairingMInd(APP_Cfg_LedParam5_T XDATA *p_param);
void APP_CFG_ReadLedMspkPairingSInd(APP_Cfg_LedParam5_T XDATA *p_param);
void APP_CFG_ReadLedMspkConnBtConnMInd(APP_Cfg_LedParam5_T XDATA *p_param);
void APP_CFG_ReadLedMspkConnBtPairingMInd(APP_Cfg_LedParam5_T XDATA *p_param);
void APP_CFG_ReadLedMspkConnBtPagingMInd(APP_Cfg_LedParam5_T XDATA *p_param);
void APP_CFG_ReadLedMspkConnBtWaitingMInd(APP_Cfg_LedParam5_T XDATA *p_param);
void APP_CFG_ReadLedStereoConnSInd(APP_Cfg_LedParam5_T XDATA *p_param);
void APP_CFG_ReadLedConcertConnSInd(APP_Cfg_LedParam5_T XDATA *p_param);
void APP_CFG_ReadLowBattDisallowPoweronInd(APP_Cfg_LedParam4_T XDATA *p_param);
void APP_CFG_ReadLedOption(APP_Cfg_LedOption_T XDATA *p_param);
void APP_CFG_ReadLedBrightness(uint8_t XDATA *p_param);
/// \endcond

#endif//APP_CFG_LED_H

