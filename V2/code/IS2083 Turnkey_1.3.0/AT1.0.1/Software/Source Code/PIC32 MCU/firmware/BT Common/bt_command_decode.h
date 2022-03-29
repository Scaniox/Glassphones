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
#ifndef BT_COMMAND_DECODE_H
#define BT_COMMAND_DECODE_H

#include <stdbool.h>
#include <stdint.h>

void BT_CommandHandler(void);
void BT_CommandDecode( void );

void BT_CommandDecodeInit(void);
void BT_CommandDecodeMain(void);
//void BT_CommandDecode1MS_event( void );

void BT_CommandDecode_AddByteToBuffer();

bool ParsePayloadAsCommand(uint8_t* command, uint8_t length);
uint16_t BT_GetUartDataFromBuf(uint8_t *buff, uint16_t sz);


#endif
