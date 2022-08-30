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
#ifndef LINE_IN_H
#define LINE_IN_H

void AnalogAudioDetectInit(void);
void AnalogAudioDetectTask(void);
void AnalogAudioDetect_Timer1MS_event();

//@ event define
typedef enum {
    BT_EVENT_LINE_IN_STATUS = 112,
    BT_LINE_IN_EVENT_MAX
}BT_LINE_IN_EVENTS;
void BTM_LINE_IN_EventHandler( BT_LINE_IN_EVENTS event, uint8_t* paras, uint16_t size );

//@
typedef enum {
    LINE_IN_INACTIVE = 0,
    LINE_IN_ACTIVE,
    LINE_IN_ACTIVE_WITH_AUDIO,
    LINE_IN_WITH_SILENCE_AUDIO
} BT_LINE_IN_STATUS;
BT_LINE_IN_STATUS BTM_LINE_IN_GetLineInStatus( void );

bool BTM_LINE_IN_IsPlugged( void );
void BTM_LINE_IN_Init( void );

#endif
