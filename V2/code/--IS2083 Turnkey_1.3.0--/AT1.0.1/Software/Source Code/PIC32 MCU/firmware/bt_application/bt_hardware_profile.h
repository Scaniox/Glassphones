/******************************************************************************
 Software License Agreement:

 The software supplied herewith by Microchip Technology Incorporated
 (the "Company") for its PICmicro(r) Microcontroller is intended and
 supplied to you, the Company's customer, for use solely and
 exclusively on Microchip PICmicro Microcontroller products. The
 software is owned by the Company and/or its supplier, and is
 protected under applicable copyright laws. All rights are reserved.
 Any use in violation of the foregoing restrictions may subject the
 user to criminal sanctions under applicable laws, as well as to
 civil liability for the breach of the terms and conditions of this
 license.

 THIS SOFTWARE IS PROVIDED IN AN "AS IS" CONDITION. NO WARRANTIES,
 WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING, BUT NOT LIMITED
 TO, IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
 PARTICULAR PURPOSE APPLY TO THIS SOFTWARE. THE COMPANY SHALL NOT,
 IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL OR
 CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
********************************************************************/
#ifndef BT_HARDWARE_PROFILE_H
#define BT_HARDWARE_PROFILE_H

#include <xc.h>
#include <stdbool.h>
#include <stdint.h>
#include "system_config.h"
#include "system_definitions.h"

//build option for code included - MBA Support
#define _BLE_ADV_CTRL_BY_MCU
#define _CODE_FOR_APP

//#define _UNSUPPORT_3A_EVENT     //3A event is used to return link mode, it is supported by MSPK but not support by 104 ROM
//#define _SUPPORT_SIMPLE_33_EVENT //33 event is to report multi speaker status. For MSPK, it return connected status with peer address. But for 104 ROM, there is no address, so need to define this macro

//define command size, command buffer size for command in and out
#define     UR_TX_BUF_SIZE              500         //maximum buffer size for command sending
#define     UR_RX_BUF_SIZE              500         //maximum buffer size for command receiving
#define     BT_CMD_SIZE_MAX				200         //maximum size for a single command
#define     QUEQUED_CMD_MAX                 30      //maximum number of command in buffer to be sending 
#define     QUEQUED_ACK_MAX                 30      //maximum number of ack command in buffer to be sending
#define     ACK_TIME_OUT_MS                 800     //number of ms to be waiting for ack
#define     INTERVAL_AFTER_CMD_ACK_NG          10   //interval(ms) before re-transmit this command in case of no ack and ack with error
#define     INTERVAL_AFTER_CMD_ACK_OK          10   //interval(ms) before send next command

//BM6X BT configuration
#define BM6X_MFB_SetHigh()      PLIB_PORTS_PinSet( PORTS_ID_0, PORT_CHANNEL_G, PORTS_BIT_POS_0)
#define BM6X_MFB_SetLow()       PLIB_PORTS_PinClear( PORTS_ID_0, PORT_CHANNEL_G, PORTS_BIT_POS_0)

#define BM6X_RESET_SetHigh()    PLIB_PORTS_PinSet( PORTS_ID_0, PORT_CHANNEL_F, PORTS_BIT_POS_3)
#define BM6X_RESET_SetLow()     PLIB_PORTS_PinClear( PORTS_ID_0, PORT_CHANNEL_F, PORTS_BIT_POS_3)

#ifdef BM83_EVB_VERSION_1_0
#define BT_P3_7_STATUS_GET()      (PLIB_PORTS_PinGet(PORTS_ID_0, PORT_CHANNEL_B, PORTS_BIT_POS_1))

#define LINE_IN_DETECT_STATUS_GET()   (PLIB_PORTS_PinGet(PORTS_ID_0, PORT_CHANNEL_B, PORTS_BIT_POS_0))
#else
#define BT_P3_7_STATUS_GET()      (PLIB_PORTS_PinGet(PORTS_ID_0, PORT_CHANNEL_B, PORTS_BIT_POS_6))

#define LINE_IN_DETECT_STATUS_GET()   (PLIB_PORTS_PinGet(PORTS_ID_0, PORT_CHANNEL_B, PORTS_BIT_POS_7))
#endif

//P2_0
#define BT_P2_0_SetOutput()         //PLIB_PORTS_PinDirectionOutputSet( PORTS_ID_0, PORT_CHANNEL_C, PORTS_BIT_POS_1)
#define BT_P2_0_SetHigh()           //PLIB_PORTS_PinSet( PORTS_ID_0, PORT_CHANNEL_C, PORTS_BIT_POS_1)
#define BT_P2_0_SetLow()            //PLIB_PORTS_PinClear( PORTS_ID_0, PORT_CHANNEL_C, PORTS_BIT_POS_1)

//EAN
#define BT_EAN_SetOutput()          //PLIB_PORTS_PinDirectionOutputSet( PORTS_ID_0, PORT_CHANNEL_C, PORTS_BIT_POS_3)
#define BT_EAN_SetHigh()            //PLIB_PORTS_PinSet( PORTS_ID_0, PORT_CHANNEL_C, PORTS_BIT_POS_3)
#define BT_EAN_SetLow()             //PLIB_PORTS_PinClear( PORTS_ID_0, PORT_CHANNEL_C, PORTS_BIT_POS_3)

//P2_4
#define BT_P2_4_SetOutput()         //PLIB_PORTS_PinDirectionOutputSet( PORTS_ID_0, PORT_CHANNEL_C, PORTS_BIT_POS_2)
#define BT_P2_4_SetHigh()           //PLIB_PORTS_PinSet( PORTS_ID_0, PORT_CHANNEL_C, PORTS_BIT_POS_2)
#define BT_P2_4_SetLow()            //PLIB_PORTS_PinClear( PORTS_ID_0, PORT_CHANNEL_C, PORTS_BIT_POS_2)

//UART RX
#define UART_RX_SetInput()         PLIB_PORTS_PinDirectionInputSet( PORTS_ID_0, PORT_CHANNEL_F, PORTS_BIT_POS_4)
//UART TX
#define UART_UR_TX_SetInput()         PLIB_PORTS_PinDirectionInputSet( PORTS_ID_0, PORT_CHANNEL_F, PORTS_BIT_POS_5)

//DSP configuration
#define DSP_RESET_SetHigh()         PLIB_PORTS_PinSet( PORTS_ID_0, PORT_CHANNEL_A, PORTS_BIT_POS_6)
#define DSP_RESET_SetLow()          PLIB_PORTS_PinClear( PORTS_ID_0, PORT_CHANNEL_A, PORTS_BIT_POS_6)
#define DSP_POWER_DN_SetHigh()      PLIB_PORTS_PinSet( PORTS_ID_0, PORT_CHANNEL_A, PORTS_BIT_POS_5)
#define DSP_POWER_DN_SetLow()       PLIB_PORTS_PinClear( PORTS_ID_0, PORT_CHANNEL_A, PORTS_BIT_POS_5)
#define DSP_MUTE_SetHigh()          PLIB_PORTS_PinSet( PORTS_ID_0, PORT_CHANNEL_A, PORTS_BIT_POS_4)
#define DSP_MUTE_SetLow()           PLIB_PORTS_PinClear( PORTS_ID_0, PORT_CHANNEL_A, PORTS_BIT_POS_4)
#define DSP_PROT_SetInput()         //NONE, PLIB_PORTS_PinDirectionInputSet( PORTS_ID_0, PORT_CHANNEL_D, PORTS_BIT_POS_6)
#define DSP_PROT_SetOutput()         //NONE, PLIB_PORTS_PinDirectionOutputSet( PORTS_ID_0, PORT_CHANNEL_D, PORTS_BIT_POS_6)
#define DSP_IRQ_SetInput()          //NONE, PLIB_PORTS_PinDirectionInputSet( PORTS_ID_0, PORT_CHANNEL_D, PORTS_BIT_POS_4)
#define DSP_IRQ_SetOutput()          //NONE, PLIB_PORTS_PinDirectionOutputSet( PORTS_ID_0, PORT_CHANNEL_D, PORTS_BIT_POS_4)

//LED configuration
#define LED0_ON()       PLIB_PORTS_PinClear( PORTS_ID_0, PORT_CHANNEL_F, PORTS_BIT_POS_13)
#define LED0_OFF()      PLIB_PORTS_PinSet( PORTS_ID_0, PORT_CHANNEL_F, PORTS_BIT_POS_13)
#define LED0_TOGGLE()   PLIB_PORTS_PinToggle( PORTS_ID_0, PORT_CHANNEL_F, PORTS_BIT_POS_13)
#define LED0_STATUS_GET()   (PLIB_PORTS_PinGet(PORTS_ID_0, PORT_CHANNEL_F, PORTS_BIT_POS_13))

#define LED1_ON()       PLIB_PORTS_PinClear( PORTS_ID_0, PORT_CHANNEL_F, PORTS_BIT_POS_12)
#define LED1_OFF()      PLIB_PORTS_PinSet( PORTS_ID_0, PORT_CHANNEL_F, PORTS_BIT_POS_12)
#define LED1_TOGGLE()       PLIB_PORTS_PinToggle( PORTS_ID_0, PORT_CHANNEL_F, PORTS_BIT_POS_12)
#define LED1_STATUS_GET()   (PLIB_PORTS_PinGet(PORTS_ID_0, PORT_CHANNEL_F, PORTS_BIT_POS_12))

#define LED2_ON()       PLIB_PORTS_PinClear( PORTS_ID_0, PORT_CHANNEL_B, PORTS_BIT_POS_12)
#define LED2_OFF()      PLIB_PORTS_PinSet( PORTS_ID_0, PORT_CHANNEL_B, PORTS_BIT_POS_12)
#define LED2_TOGGLE()       PLIB_PORTS_PinToggle( PORTS_ID_0, PORT_CHANNEL_B, PORTS_BIT_POS_12)
#define LED2_STATUS_GET()   (PLIB_PORTS_PinGet(PORTS_ID_0, PORT_CHANNEL_B, PORTS_BIT_POS_12))

#define LED3_ON()       PLIB_PORTS_PinClear( PORTS_ID_0, PORT_CHANNEL_B, PORTS_BIT_POS_13)
#define LED3_OFF()      PLIB_PORTS_PinSet( PORTS_ID_0, PORT_CHANNEL_B, PORTS_BIT_POS_13)
#define LED3_TOGGLE()       PLIB_PORTS_PinToggle( PORTS_ID_0, PORT_CHANNEL_B, PORTS_BIT_POS_13)
#define LED3_STATUS_GET()   (PLIB_PORTS_PinGet(PORTS_ID_0, PORT_CHANNEL_B, PORTS_BIT_POS_13))

#define LED4_ON()       PLIB_PORTS_PinClear( PORTS_ID_0, PORT_CHANNEL_B, PORTS_BIT_POS_14)
#define LED4_OFF()      PLIB_PORTS_PinSet( PORTS_ID_0, PORT_CHANNEL_B, PORTS_BIT_POS_14)
#define LED4_TOGGLE()       PLIB_PORTS_PinToggle( PORTS_ID_0, PORT_CHANNEL_B, PORTS_BIT_POS_14)
#define LED4_STATUS_GET()   (PLIB_PORTS_PinGet(PORTS_ID_0, PORT_CHANNEL_B, PORTS_BIT_POS_14))

#define LED5_ON()       PLIB_PORTS_PinClear( PORTS_ID_0, PORT_CHANNEL_B, PORTS_BIT_POS_15)
#define LED5_OFF()      PLIB_PORTS_PinSet( PORTS_ID_0, PORT_CHANNEL_B, PORTS_BIT_POS_15)
#define LED5_TOGGLE()       PLIB_PORTS_PinToggle( PORTS_ID_0, PORT_CHANNEL_B, PORTS_BIT_POS_15)
#define LED5_STATUS_GET()   (PLIB_PORTS_PinGet(PORTS_ID_0, PORT_CHANNEL_B, PORTS_BIT_POS_15))

#define LED6_ON()       PLIB_PORTS_PinClear( PORTS_ID_0, PORT_CHANNEL_D, PORTS_BIT_POS_14)
#define LED6_OFF()      PLIB_PORTS_PinSet( PORTS_ID_0, PORT_CHANNEL_D, PORTS_BIT_POS_14)
#define LED6_TOGGLE()       PLIB_PORTS_PinToggle( PORTS_ID_0, PORT_CHANNEL_D, PORTS_BIT_POS_14)
#define LED6_STATUS_GET()   (PLIB_PORTS_PinGet(PORTS_ID_0, PORT_CHANNEL_D, PORTS_BIT_POS_14))

#define LED7_ON()       PLIB_PORTS_PinClear( PORTS_ID_0, PORT_CHANNEL_D, PORTS_BIT_POS_15)
#define LED7_OFF()      PLIB_PORTS_PinSet( PORTS_ID_0, PORT_CHANNEL_D, PORTS_BIT_POS_15)
#define LED7_TOGGLE()       PLIB_PORTS_PinToggle( PORTS_ID_0, PORT_CHANNEL_D, PORTS_BIT_POS_15)
#define LED7_STATUS_GET()   (PLIB_PORTS_PinGet(PORTS_ID_0, PORT_CHANNEL_D, PORTS_BIT_POS_15))

//Button configuration
#define KEY0_STATUS_GET()   (PLIB_PORTS_PinGet(PORTS_ID_0, PORT_CHANNEL_A, PORTS_BIT_POS_10))   //PLAY/PAUSE
#define KEY1_STATUS_GET()   (PLIB_PORTS_PinGet(PORTS_ID_0, PORT_CHANNEL_B, PORTS_BIT_POS_3))    //PIRING
#define KEY2_STATUS_GET()   (PLIB_PORTS_PinGet(PORTS_ID_0, PORT_CHANNEL_A, PORTS_BIT_POS_9))    //FUNC1 
#define KEY3_STATUS_GET()   (PLIB_PORTS_PinGet(PORTS_ID_0, PORT_CHANNEL_E, PORTS_BIT_POS_9))    //FUNC2 RB2
#define KEY4_STATUS_GET()   (PLIB_PORTS_PinGet(PORTS_ID_0, PORT_CHANNEL_B, PORTS_BIT_POS_9))    //FWD
#define KEY5_STATUS_GET()   (PLIB_PORTS_PinGet(PORTS_ID_0, PORT_CHANNEL_B, PORTS_BIT_POS_8))    //REV
#define KEY6_STATUS_GET()   (PLIB_PORTS_PinGet(PORTS_ID_0, PORT_CHANNEL_B, PORTS_BIT_POS_11))   //VOL UP
#define KEY7_STATUS_GET()   (PLIB_PORTS_PinGet(PORTS_ID_0, PORT_CHANNEL_B, PORTS_BIT_POS_10))   //VOL DN

//Power configuration
#define ENABLE_DSP_POWER()      //NONE
#define DISABLE_DSP_POWER()         //NONE

//Others
#define BT_P0_0_STATUS_GET()      (PLIB_PORTS_PinGet(PORTS_ID_0, PORT_CHANNEL_B, PORTS_BIT_POS_1))
#define BT_P2_7_STATUS_GET()      (PLIB_PORTS_PinGet(PORTS_ID_0, PORT_CHANNEL_G, PORTS_BIT_POS_9))

#define BT_UART_RX_BYTE_MODEL
#define BT_UART_TX_BYTE_MODEL

#ifdef BT_UART_RX_BYTE_MODEL
#define BT_UART_RX_ISR      BT_CommandDecode_AddByteToBuffer
#endif

#ifdef BT_UART_TX_BYTE_MODEL
void HM_UART_WriteOneByte(uint8_t byte);
#define BT_UART_TX_ISR      BT_CommandSend_SendByte
#define UART_WriteOneByte   HM_UART_WriteOneByte
#endif

void bt_issueUartTransfer( void );
void bt_disableUartTransferIntr( void );
void bt_temporaryDisableUartTransferIntr( void );
void bt_restoreUartTransferIntr( void );

#endif
