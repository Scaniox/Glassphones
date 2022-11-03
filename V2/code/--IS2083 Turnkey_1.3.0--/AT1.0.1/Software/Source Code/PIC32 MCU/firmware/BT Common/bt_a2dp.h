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
#ifndef BT_A2DP_H
#define BT_A2DP_H

#include <stdbool.h>
#include <stdint.h>

#define A2DP_DATABASE_INDEX_MAX     3
typedef struct {
    struct {
        uint8_t bfA2DP          : 1;
        uint8_t bfAVRCP         : 1;
        uint8_t reserved        : 6;
    } A2DPLinkStatus[A2DP_DATABASE_INDEX_MAX];
    uint8_t currentA2DP_DatabaseIndex;
} BTM_A2DP_LINK_STATUS;

//@
typedef enum {
    BT_A2DP_IDLE = 0,
    BT_A2DP_ACTIVE = 1
} BT_A2DP_CODEC_STATUS;
//@
typedef enum {
    BT_PLAYING_STOPPED,
    BT_PLAYING_PLAYING,
    BT_PLAYING_PAUSED,
    BT_PLAYING_FF,
    BT_PLAYING_FR,
    BT_PLAYING_ERROR
} BT_PLAYING_STATUS;//BT_PlayingStatus;
//@
typedef enum {
    SAMP_8KHZ = 0,
            SAMP_12KHZ,
            SAMP_16KHZ,
            SAMP_24KHZ,
            SAMP_32KHZ,
            SAMP_48KHZ,
            SAMP_44_1KHZ,
            SAMP_88_2KHZ,
            SAMP_96KHZ
} BT_PLAYING_SAMPLING_RATE;//BT_PlayingSamplingRate;

typedef struct {
    BT_A2DP_CODEC_STATUS a2dpCodecStatus;
    BT_PLAYING_STATUS playingStatus;
    BT_PLAYING_SAMPLING_RATE playingSamplingRate;
} BTM_A2DP_STATUS;

//@ event define
typedef enum {
    BT_EVENT_A2DP_CONNECTED = 80,
    BT_EVENT_A2DP_DISCONNECTED,
    BT_EVENT_AVRCP_CONNECTED,
    BT_EVENT_AVRCP_DISCONNECTED,
    BT_EVENT_A2DP_STATUS,
    BT_EVENT_PLAYBACK_STATUS_CHANGED,
    BT_EVENT_SAMPLINGRATE_CHANGED,
    BT_A2DP_EVENT_MAX
}BT_A2DP_EVENTS;

void BTMA2DP_EventHandler( BT_A2DP_EVENTS event, uint8_t* paras, uint16_t size );
void BTMA2DP_Init( void );
uint8_t BTMA2DP_getActiveDatabaseIndex( void );
bool BTMA2DP_getA2DPLinkStatus( uint8_t databaseIndex );
bool BTMA2DP_getAVRCPLinkStatus( uint8_t databaseIndex );
BT_A2DP_CODEC_STATUS BTMA2DP_GetA2DPCodecStatus( void );
BT_PLAYING_STATUS BTMA2DP_GetPlayingStatus( void );
BT_PLAYING_SAMPLING_RATE BTM22DP_GetPlayingSamplingRate( void );
void BTMA2DP_PlayStart( void );
void BTMA2DP_PauseStart( void );
void BTMA2DP_StopStart( void );
void BTMA2DP_PlayPauseToggle( void );
void BTMA2DP_PlayNext( void );
void BTMA2DP_PlayPrevious( void );
void BTMA2DP_StartFastForward( void );
void BTMA2DP_StartFastRewind( void );
void BTMA2DP_CancelForwardOrRewind( void );

#ifdef BT_A2DP_C
/* private */

#else
/* public */

#endif

#endif
