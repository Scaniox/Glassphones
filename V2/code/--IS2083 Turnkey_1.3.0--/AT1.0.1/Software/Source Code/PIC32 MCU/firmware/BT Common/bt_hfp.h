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
#ifndef BT_HFP_H
#define BT_HFP_H

#include <stdbool.h>
#include <stdint.h>

//@
typedef enum {
    BT_CALL_IDLE = 0,
    BT_VOICE_DIAL = 1,
    BT_CALL_INCOMMING = 2,
    BT_CALL_OUTGOING = 3,
    BT_CALLING = 4,
    BT_CALLING_WAITING = 5,
    BT_CALLING_SWITCH_CALL = 6,
    BT_CALLING_HOLD = 7
} BT_HFP_STATUS;

typedef struct {
    struct {
        uint8_t bfHFP           : 1;
        uint8_t reserved        : 7;
    } HFPLinkStatus;
    uint8_t HFP_DatabaseIndex;
} BTM_HFP_LINK_STATUS;

//@ event define
typedef enum {
    BT_EVENT_HFP_CONNECTED = 96,
    BT_EVENT_HFP_DISCONNECTED,
    BT_EVENT_CALL_STATUS_CHANGED,
    BT_HFP_EVENT_MAX
}BT_HFP_EVENTS;

void BTMHFP_EventHandler( BT_HFP_EVENTS event, uint8_t* paras, uint16_t size );
BT_HFP_STATUS BTMHFP_GetCallStatus( void );
void BTMHFP_Init( void );
uint8_t BTMHFP_GetDatabaseIndex( void );
bool BTMHFP_GetHFPLinkStatus( uint8_t databaseIndex );
void BTMHFP_AcceptCall( void );
void BTMHFP_EndCall( void );
void BTMHFP_RejectCall( void );
void BTMHFP_SwitchToHoldCall( void );
void BTMHFP_RejectWaitingCallOrReleaseHoldCall( void );
void BTMHFP_AcceptWaitingCall( void );
void BTMHFP_TransferCall( void );
void BTMHFP_DialLastNumber( void );
void BTMHFP_VoiceDial( void );
void BTMHFP_CancelVoiceDial( void );

#ifdef BT_HFP_C
/* private */

#else
/* public */

#endif

#endif
