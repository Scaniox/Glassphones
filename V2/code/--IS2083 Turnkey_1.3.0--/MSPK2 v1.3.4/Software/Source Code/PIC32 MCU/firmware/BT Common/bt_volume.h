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
#ifndef BT_VOLUME_H
#define BT_VOLUME_H

#include <stdbool.h>
#include <stdint.h>

//@volume mode
typedef enum {
    A2DP_VOL_MODE = 0,
    HFP_VOL_MODE,
    LINE_IN_VOL_MODE
} VOLUME_MODE;

//@ event define
typedef enum {
    BT_EVENT_HFP_VOLUME_CHANGED = 144,
    BT_EVENT_AVRCP_VOLUME_CTRL,
    BT_EVENT_AVRCP_ABS_VOLUME_CHANGED,
    NSPK_EVENT_SYNC_VOL_CTRL,
    NSPK_EVENT_SYNC_INTERNAL_GAIN,
    NSPK_EVENT_SYNC_ABS_VOL,
    BT_VOL_EVENT_MAX
}BT_VOLUME_EVENTS;

void BTVOL_EventHandler( BT_VOLUME_EVENTS event, uint8_t* paras, uint16_t size );
void BTVOL_VolUp( void );
void BTVOL_VolDown( void );
void BTVOL_InitVolMode( void );
void BTVOL_SyncVolFromMasterToSlaveByVendorCmd( void );
void BTVOL_SyncA2DPAbsVolFromMasterToSlaveByVendorCmd( uint8_t absVol );
void BTVOL_SyncVolCtrlFromMasterToSlaveByVendorCmd( uint8_t volCtrl );
void BTVOL_GotSyncVolFromMasterByVendorCmd( uint8_t vol_req, uint8_t vol_value );
//void BTVOL_SyncVolFromMasterToSlaveByVendorCmd( void );
void BTVOL_ChangeVolMode( VOLUME_MODE mode, bool syncToBTM );
VOLUME_MODE BTVOL_GetVolMode( void );
void BTVOL_SetVolMode( VOLUME_MODE change_mode );
uint8_t BTVOL_GetCurrentA2DPVol( void );
uint8_t BTVOL_GetHFPVol( void );
uint8_t BTVOL_GetLineInVol( void );
void BTVOL_Init( void );
void BTVOL_InitWithSpecificVolume( uint8_t a2dpVol, uint8_t hfpVol, uint8_t lineInVol );

#ifdef BT_VOLUME_C
/* private */

#else
/* public */

#endif
        
#endif


