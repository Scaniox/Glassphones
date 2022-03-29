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
#ifndef BT_MULTI_SPK_H
#define BT_MULTI_SPK_H

#include <stdbool.h>
#include <stdint.h>

//@multi speaker status define
typedef enum {
    BT_CSB_STATUS_STANDBY = 0,
    BT_CSB_STATUS_CONNECTING,
    BT_CSB_STATUS_CONNECTED_AS_NSPK_MASTER,
    BT_CSB_STATUS_CONNECTED_AS_NSPK_SLAVE,
    BT_CSB_STATUS_NSPK_MASTER_CONNECTING,       //NA now
    BT_CSB_STATUS_CONNECTED_AS_BROADCAST_MASTER,
    BT_CSB_STATUS_CONNECTED_AS_BROADCAST_SLAVE,
    BT_CSB_STATUS_BROADCAST_MASTER_CONNECTING,
} BT_NSPK_SYSTEM_STATUS;    //system define, external use

typedef enum {
    MSPK_AUDIO_CH_STEREO = 0,
    MSPK_AUDIO_CH_LEFT = 1,
    MSPK_AUDIO_CH_RIGHT = 2,
    MSPK_AUDIO_CH_MIXED = 3,
} BT_MSPK_AUDIO_CHANNEL;

//@ event define
typedef enum {
    BT_EVENT_NSPK_STATUS = 128,
    BT_EVENT_NSPK_AUDIO_CHANNEL,
    NSPK_EVENT_ADD_SPEAKER3,
    BT_MSPK_EVENT_MAX
}BT_MSPK_EVENTS;

void BTMSPK_EventHandler( BT_MSPK_EVENTS event, uint8_t* paras, uint16_t size );
BT_NSPK_SYSTEM_STATUS BTMSPK_GetMSPKStatus( void );
void BTMSPK_GetNSPKLinksStatusAndEvent( uint8_t* pNspkLink, uint8_t* pNspkEvent );
uint8_t BTMSPK_GetSlaveCounter( void );
uint8_t* BTMSPK_GetMasterBDAddress( void );
void BTMSPK_Init( void );
void BTMSPK_TriggerStereoModeMaster( void );
void BTMSPK_TriggerStereoModeSlave( void );
void BTMSPK_TriggerConcertModeMaster( void );
void BTMSPK_TriggerConcertModeSlave( void );
void BTMSPK_CreatStereoMode( void );
void BTMSPK_CreatConcertMode( void );
void BTMSPK_AddMoreSpeaker( void );
void BTMSPK_CancelGroupCreation( void );
void BTMSPK_CancelGroup( void );
void BTMSPK_BackToLastGroupMode( void );
void BTMSPK_GroupModeSwitch( void );
void BTMSPK_GroupSpeakerSoundSync( void );
void BTMSPK_StereoModeSwitchAudioChannel( void );
void BTMSPK_StereoModeSetAudioChannel( BT_MSPK_AUDIO_CHANNEL ch );
BT_MSPK_AUDIO_CHANNEL BTMSPK_GetStereoModeAudioChannel( void );

#ifdef BT_MULTI_SPK_C
/* private */

#else
/* public */

#endif

#define MSPK_CTRL 1

#endif
