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
#include <stdbool.h>
#include <stdint.h>
#include <xc.h>
#include "bt_hardware_profile.h"
#define BT_VOLUME_C
#include "bt_volume.h"
#include "bt_multi_spk.h"
#include "bt_a2dp.h"
#include "bt_command_send.h"
#include "sta369bwdsp_handler.h"
#include "bt_app.h"


#define A2DP_VOL_INDEX_MAX 8
struct {
    uint8_t a2dpVol[A2DP_VOL_INDEX_MAX];     //change to 8 seperate A2DP_VOL_MODE volume, for multi link function. But current linked data base max. is only 4
    uint8_t hfpVol;
    uint8_t lineInVol;
    VOLUME_MODE currentVolMode;
} BTAPP_Volume;

/*------------------------------------------------------------*/
/* private function */
/*------------------------------------------------------------*/

/*------------------------------------------------------------*/
static uint8_t volumeFormatTo4bits(uint8_t volume)
{
    return volume>>1;
}

/*------------------------------------------------------------*/
static uint8_t volumeFormatTo7bits(uint8_t volume)
{
    return volume*127/30;
}

/*------------------------------------------------------------*/
static void volumeUp(VOLUME_MODE mode, uint8_t bt_index)
{
    uint8_t* p;
    switch(mode)
    {
        case A2DP_VOL_MODE:
            p = &(BTAPP_Volume.a2dpVol[bt_index]);
            break;
        case HFP_VOL_MODE:
            p = &BTAPP_Volume.hfpVol;
            break;
        case LINE_IN_VOL_MODE:
            p = &BTAPP_Volume.lineInVol;
            break;
    }
    if(*p < 30)
    {
        if(mode == HFP_VOL_MODE)
            *p=(*p)+2; 
        else
            (*p)++;
    }
}

/*------------------------------------------------------------*/
static void volumeDown(VOLUME_MODE mode, uint8_t bt_index)
{
    uint8_t* p;
    switch(mode)
    {
        case A2DP_VOL_MODE:
            p = &(BTAPP_Volume.a2dpVol[bt_index]);
            break;
        case HFP_VOL_MODE:
            p = &BTAPP_Volume.hfpVol;
            break;
        case LINE_IN_VOL_MODE:
            p = &BTAPP_Volume.lineInVol;
            break;
    }
    if(*p > 0)
    {
        if((mode == HFP_VOL_MODE) && (*p > 1))
        {
            *p=(*p)-2;
        }   
        else
            (*p)--;
    }
}

/*------------------------------------------------------------*/
static void set4bitVol(uint8_t vol, VOLUME_MODE mode, uint8_t bt_index)
{
    uint8_t* p;
    switch(mode)
    {
        case A2DP_VOL_MODE:
            p = &(BTAPP_Volume.a2dpVol[bt_index]);
            break;
        case HFP_VOL_MODE:
            p = &BTAPP_Volume.hfpVol;
            break;
        case LINE_IN_VOL_MODE:
            p = &BTAPP_Volume.lineInVol;
            break;
    }
    vol &= 0x0f;
    *p = vol<<1;
}

/*------------------------------------------------------------*/
static void set7bitVol(uint8_t vol, VOLUME_MODE mode, uint8_t bt_index)
{
    uint8_t* p;
    switch(mode)
    {
        case A2DP_VOL_MODE:
            p = &(BTAPP_Volume.a2dpVol[bt_index]);
            break;
        case HFP_VOL_MODE:
            p = &BTAPP_Volume.hfpVol;
            break;
        case LINE_IN_VOL_MODE:
            p = &BTAPP_Volume.lineInVol;
            break;
    }
    vol &= 0x7f;
    *p = vol*30/127;
    if(*p == 0 && vol !=0 )
        *p = 1;
}

/*------------------------------------------------------------*/
static void DSP_setVol(VOLUME_MODE mode)
{
     uint8_t* p;
    switch(mode)
    {
        case A2DP_VOL_MODE:
            p = &(BTAPP_Volume.a2dpVol[BTMA2DP_getActiveDatabaseIndex()]);
            break;
        case HFP_VOL_MODE:
            p = &BTAPP_Volume.hfpVol;
            break;
        case LINE_IN_VOL_MODE:
            p = &BTAPP_Volume.lineInVol;
            break;
    }
    sta369bw_SetVol(*p);
 }

/*------------------------------------------------------------*/
static void DSP_setVolCurrentMode( void )
{
     uint8_t* p;
    switch(BTAPP_Volume.currentVolMode)
    {
        case A2DP_VOL_MODE:
            p = &(BTAPP_Volume.a2dpVol[BTMA2DP_getActiveDatabaseIndex()]);
            break;
        case HFP_VOL_MODE:
            p = &BTAPP_Volume.hfpVol;
            break;
        case LINE_IN_VOL_MODE:
            p = &BTAPP_Volume.lineInVol;
            break;
    }
    sta369bw_SetVol(*p);
 }


/*------------------------------------------------------------*/
/* public function */
/*------------------------------------------------------------*/
void BTVOL_EventHandler( BT_VOLUME_EVENTS event, uint8_t* data, uint16_t size )
{
    switch( event )
    {
        case BT_EVENT_HFP_VOLUME_CHANGED:
            if ( BTAPP_Volume.currentVolMode == HFP_VOL_MODE ) 
            {
                set4bitVol( data[1], HFP_VOL_MODE, BTMHFP_GetDatabaseIndex());
                DSP_setVolCurrentMode();
            }
            break;

        case BT_EVENT_AVRCP_VOLUME_CTRL:        //AVRCP 1.0
            if (BTAPP_Volume.currentVolMode == A2DP_VOL_MODE)
            {
                if(data[1] == 0)       //vol up
                    volumeUp(A2DP_VOL_MODE, BTMA2DP_getActiveDatabaseIndex());
                else if(data[1] == 1)      //vol down
                    volumeDown(A2DP_VOL_MODE, BTMA2DP_getActiveDatabaseIndex());
                DSP_setVolCurrentMode();
            }
            break;

        case BT_EVENT_AVRCP_ABS_VOLUME_CHANGED: //AVRCP > 1.0
            if (BTAPP_Volume.currentVolMode == A2DP_VOL_MODE)
            {
#ifdef _CODE_FOR_APP            
			if( ( BTMSPK_GetMSPKStatus() == BT_CSB_STATUS_CONNECTED_AS_BROADCAST_MASTER) ||
			   ( BTMSPK_GetMSPKStatus() == BT_CSB_STATUS_BROADCAST_MASTER_CONNECTING ) ) 
            {
                //BT_Vendor_SendVol( data[1] );
                BTVOL_SyncA2DPAbsVolFromMasterToSlaveByVendorCmd( data[1] );
            }
#endif        
                set7bitVol((uint8_t)data[1], A2DP_VOL_MODE, data[0]);
                if (data[0] == BTMA2DP_getActiveDatabaseIndex())
                {
                    DSP_setVolCurrentMode();
                }
            }

			break;

        case NSPK_EVENT_SYNC_VOL_CTRL:
#ifdef _CODE_FOR_APP            
			if( ( BTMSPK_GetMSPKStatus() == BT_CSB_STATUS_CONNECTED_AS_BROADCAST_MASTER) ||
			   ( BTMSPK_GetMSPKStatus() == BT_CSB_STATUS_BROADCAST_MASTER_CONNECTING ) ) 
            {
                BTVOL_SyncVolCtrlFromMasterToSlaveByVendorCmd( data[1] );
            }
#endif              
            if(data[1] == 0)       //vol up
            {
                //volumeUp(A2DP_VOL_MODE, BTMA2DP_getActiveDatabaseIndex());
                //DSP_setVolCurrentMode();
                if ( BTAPP_Volume.currentVolMode == HFP_VOL_MODE ) 
                {
                    volumeUp(HFP_VOL_MODE, BTMHFP_GetDatabaseIndex());
                    DSP_setVolCurrentMode();
                    BT_updateHFPGain(volumeFormatTo4bits(BTAPP_Volume.hfpVol), BTMHFP_GetDatabaseIndex());
                }
                else if( BTAPP_Volume.currentVolMode == LINE_IN_VOL_MODE )
                {
                    volumeUp(LINE_IN_VOL_MODE, 0 );
                    DSP_setVolCurrentMode();
                    BT_updateLineInGain(volumeFormatTo4bits(BTAPP_Volume.lineInVol), 0);
                }
                else
                {
                    volumeUp(A2DP_VOL_MODE, BTMA2DP_getActiveDatabaseIndex());
                    DSP_setVolCurrentMode();
                    BT_updateA2DPGain(volumeFormatTo7bits(BTAPP_Volume.a2dpVol[BTMA2DP_getActiveDatabaseIndex()]), BTMA2DP_getActiveDatabaseIndex());
                }
                
            }
            else if(data[1] == 1)      //vol down
            {
                //volumeDown(A2DP_VOL_MODE, BTMA2DP_getActiveDatabaseIndex());
                //DSP_setVolCurrentMode();
                if ( BTAPP_Volume.currentVolMode == HFP_VOL_MODE ) 
                {
                    volumeDown(HFP_VOL_MODE, BTMHFP_GetDatabaseIndex());
                    DSP_setVolCurrentMode();
                    BT_updateHFPGain(volumeFormatTo4bits(BTAPP_Volume.hfpVol), BTMHFP_GetDatabaseIndex());
                }
                else if( BTAPP_Volume.currentVolMode == LINE_IN_VOL_MODE )
                {
                    volumeDown(LINE_IN_VOL_MODE, 0 );
                    DSP_setVolCurrentMode();
                    BT_updateLineInGain(volumeFormatTo4bits(BTAPP_Volume.lineInVol), 0);
                }
                else
                {
                    volumeDown(A2DP_VOL_MODE, BTMA2DP_getActiveDatabaseIndex());
                    DSP_setVolCurrentMode();
                    BT_updateA2DPGain(volumeFormatTo7bits(BTAPP_Volume.a2dpVol[BTMA2DP_getActiveDatabaseIndex()]), BTMA2DP_getActiveDatabaseIndex());
                }
            }
            break;

        case NSPK_EVENT_SYNC_INTERNAL_GAIN:
            //...set4bitVol( data[1] & 0x0f, A2DP_VOL_MODE, BTMA2DP_getActiveDatabaseIndex());               //bit3~0 indicates A2DP_VOL_MODE gain
            //...set4bitVol( data[1] >> 4, LINE_IN_VOL_MODE, 0 );     //bit7~4 indicates LINE IN gain
            //BT_updateA2DPGain(volumeFormatTo7bits(BTAPP_Volume.a2dpVol[BTMA2DP_getActiveDatabaseIndex()]), BTMA2DP_getActiveDatabaseIndex());
            //BT_updateLineInGain(volumeFormatTo4bits(BTAPP_Volume.lineInVol), 0);
            //if (BTAPP_Volume.currentVolMode == A2DP_VOL_MODE || BTAPP_Volume.currentVolMode == LINE_IN_VOL_MODE )
            //    DSP_setVolCurrentMode();
            break;
            
        case NSPK_EVENT_SYNC_ABS_VOL:
            if (BTAPP_Volume.currentVolMode == A2DP_VOL_MODE) {
                set7bitVol(data[1], A2DP_VOL_MODE, BTMA2DP_getActiveDatabaseIndex());
                DSP_setVolCurrentMode();
                BT_updateA2DPGain(volumeFormatTo7bits(BTAPP_Volume.a2dpVol[BTMA2DP_getActiveDatabaseIndex()]), BTMA2DP_getActiveDatabaseIndex());
            }
            else {
                //not this event in other mode
            }
            break;
    }
}

/*------------------------------------------------------------*/
void BTVOL_VolUp( void )
{
    switch(BTAPP_Volume.currentVolMode)
    {
        case A2DP_VOL_MODE:
            if ( (BTMSPK_GetMSPKStatus() == BT_CSB_STATUS_CONNECTED_AS_NSPK_MASTER)
                    || (BTMSPK_GetMSPKStatus() == BT_CSB_STATUS_CONNECTED_AS_NSPK_SLAVE ) //NSPK mode
                    || (BTMSPK_GetMSPKStatus() == BT_CSB_STATUS_CONNECTED_AS_BROADCAST_SLAVE ))
            {
                BT_MMI_ActionCommand(INC_SPK_GAIN, BTMA2DP_getActiveDatabaseIndex());
            }
#ifdef _CODE_FOR_APP            
			else if( ( BTMSPK_GetMSPKStatus() == BT_CSB_STATUS_CONNECTED_AS_BROADCAST_MASTER) ||
			   ( BTMSPK_GetMSPKStatus() == BT_CSB_STATUS_BROADCAST_MASTER_CONNECTING ) ) 
            {
                BT_MMI_ActionCommand(INC_SPK_GAIN, BTMA2DP_getActiveDatabaseIndex());
            }   
#endif            
            else //single speaker mode or NSPK connecting or broadcast mode
            {
                volumeUp(A2DP_VOL_MODE, BTMA2DP_getActiveDatabaseIndex());
                DSP_setVolCurrentMode();//DSP_setVol(A2DP_VOL_MODE);
                if(BTAPP_GetStatus() == BT_STATUS_ON || BTAPP_GetStatus() == BT_STATUS_READY)
                {
                    BT_updateA2DPGain(volumeFormatTo7bits(BTAPP_Volume.a2dpVol[BTMA2DP_getActiveDatabaseIndex()]), BTMA2DP_getActiveDatabaseIndex());
                }
            }
            break;
        case HFP_VOL_MODE:
            volumeUp(HFP_VOL_MODE, BTMHFP_GetDatabaseIndex());
            DSP_setVolCurrentMode();//DSP_setVol(HFP_VOL_MODE);
            if(BTAPP_GetStatus() == BT_STATUS_ON || BTAPP_GetStatus() == BT_STATUS_READY)
            {
                BT_updateHFPGain(volumeFormatTo4bits(BTAPP_Volume.hfpVol), BTMHFP_GetDatabaseIndex());
            }
            break;
        case LINE_IN_VOL_MODE:
            if ( (BTMSPK_GetMSPKStatus() == BT_CSB_STATUS_CONNECTED_AS_NSPK_MASTER)
                    || (BTMSPK_GetMSPKStatus() == BT_CSB_STATUS_CONNECTED_AS_NSPK_SLAVE ) //NSPK mode
                    || (BTMSPK_GetMSPKStatus() == BT_CSB_STATUS_CONNECTED_AS_BROADCAST_SLAVE ))
            {
                BT_MMI_ActionCommand(INC_SPK_GAIN, BTMA2DP_getActiveDatabaseIndex());
            }
#ifdef _CODE_FOR_APP            
			else if( ( BTMSPK_GetMSPKStatus() == BT_CSB_STATUS_CONNECTED_AS_BROADCAST_MASTER) ||
			   ( BTMSPK_GetMSPKStatus() == BT_CSB_STATUS_BROADCAST_MASTER_CONNECTING ) ) 
            {
                BT_MMI_ActionCommand(INC_SPK_GAIN, BTMA2DP_getActiveDatabaseIndex());
            }   
#endif            
            else //single speaker mode or NSPK connecting or broadcast mode
            {
                volumeUp(LINE_IN_VOL_MODE, 0 );
                DSP_setVolCurrentMode();DSP_setVol(LINE_IN_VOL_MODE);
                if(BTAPP_GetStatus() == BT_STATUS_ON || BTAPP_GetStatus() == BT_STATUS_READY)
                {
                    BT_updateLineInGain(volumeFormatTo4bits(BTAPP_Volume.lineInVol), 0);
                }
            }
            break;
    }
}

/*------------------------------------------------------------*/
void BTVOL_VolDown( void )
{
    switch(BTAPP_Volume.currentVolMode)
    {
        case A2DP_VOL_MODE:
            if ( (BTMSPK_GetMSPKStatus() == BT_CSB_STATUS_CONNECTED_AS_NSPK_MASTER)
                    || (BTMSPK_GetMSPKStatus() == BT_CSB_STATUS_CONNECTED_AS_NSPK_SLAVE ) //NSPK mode
                    || (BTMSPK_GetMSPKStatus() == BT_CSB_STATUS_CONNECTED_AS_BROADCAST_SLAVE ))
            {
                BT_MMI_ActionCommand(DEC_SPK_GAIN, BTMA2DP_getActiveDatabaseIndex());
            }
#ifdef _CODE_FOR_APP            
			else if( ( BTMSPK_GetMSPKStatus() == BT_CSB_STATUS_CONNECTED_AS_BROADCAST_MASTER) ||
			   ( BTMSPK_GetMSPKStatus() == BT_CSB_STATUS_BROADCAST_MASTER_CONNECTING ) ) 
            {
                BT_MMI_ActionCommand(DEC_SPK_GAIN, BTMA2DP_getActiveDatabaseIndex());
            }   
#endif            
            else //single speaker mode or NSPK connecting
            {
                volumeDown(A2DP_VOL_MODE, BTMA2DP_getActiveDatabaseIndex());
                DSP_setVolCurrentMode();//DSP_setVol(A2DP_VOL_MODE);
                if(BTAPP_GetStatus() == BT_STATUS_ON || BTAPP_GetStatus() == BT_STATUS_READY)
                {
                        BT_updateA2DPGain(volumeFormatTo7bits(BTAPP_Volume.a2dpVol[BTMA2DP_getActiveDatabaseIndex()]), BTMA2DP_getActiveDatabaseIndex());
                }
            }
            break;
        case HFP_VOL_MODE:
            volumeDown(HFP_VOL_MODE, BTMHFP_GetDatabaseIndex());
            DSP_setVolCurrentMode();
            if(BTAPP_GetStatus() == BT_STATUS_ON || BTAPP_GetStatus() == BT_STATUS_READY)
            {
                BT_updateHFPGain(volumeFormatTo4bits(BTAPP_Volume.hfpVol), BTMHFP_GetDatabaseIndex());
            }
            break;
        case LINE_IN_VOL_MODE:
            if ( (BTMSPK_GetMSPKStatus() == BT_CSB_STATUS_CONNECTED_AS_NSPK_MASTER)
                    || (BTMSPK_GetMSPKStatus() == BT_CSB_STATUS_CONNECTED_AS_NSPK_SLAVE ) //NSPK mode
                    || (BTMSPK_GetMSPKStatus() == BT_CSB_STATUS_CONNECTED_AS_BROADCAST_SLAVE ))
            {
                    BT_MMI_ActionCommand(DEC_SPK_GAIN, BTMA2DP_getActiveDatabaseIndex());
            }
#ifdef _CODE_FOR_APP            
			else if( ( BTMSPK_GetMSPKStatus() == BT_CSB_STATUS_CONNECTED_AS_BROADCAST_MASTER) ||
			   ( BTMSPK_GetMSPKStatus() == BT_CSB_STATUS_BROADCAST_MASTER_CONNECTING ) ) 
            {
                BT_MMI_ActionCommand(DEC_SPK_GAIN, BTMA2DP_getActiveDatabaseIndex());
            }   
#endif            
            else //single speaker mode or NSPK connecting or broadcast mode
            {
                volumeDown(LINE_IN_VOL_MODE, 0 );
                DSP_setVolCurrentMode();//DSP_setVol(LINE_IN_VOL_MODE);
                if(BTAPP_GetStatus() == BT_STATUS_ON || BTAPP_GetStatus() == BT_STATUS_READY)
                {
                    BT_updateLineInGain(volumeFormatTo4bits(BTAPP_Volume.lineInVol), 0);
                }
            }
            break;
    }
}

/*------------------------------------------------------------*/
void BTVOL_InitVolMode( void )
{
    BTAPP_Volume.currentVolMode = A2DP_VOL_MODE;
    DSP_setVolCurrentMode();
    BT_SetOverallGain(volumeFormatTo7bits(BTAPP_Volume.a2dpVol[BTMA2DP_getActiveDatabaseIndex()]), volumeFormatTo7bits(BTAPP_Volume.hfpVol), volumeFormatTo7bits(BTAPP_Volume.lineInVol), BTMA2DP_getActiveDatabaseIndex());
}

/*------------------------------------------------------------*/
void BTVOL_ChangeVolMode( VOLUME_MODE mode, bool syncToBTM )
{
    BTAPP_Volume.currentVolMode = mode;
    DSP_setVolCurrentMode();
    if(syncToBTM)
    {
        switch (mode) 
        {
            case A2DP_VOL_MODE:
                BT_updateA2DPGain(volumeFormatTo7bits(BTAPP_Volume.a2dpVol[BTMA2DP_getActiveDatabaseIndex()]), BTMA2DP_getActiveDatabaseIndex());
                break;
            case LINE_IN_VOL_MODE:
                BT_updateLineInGain(volumeFormatTo4bits(BTAPP_Volume.lineInVol), 0);
                break;
            case HFP_VOL_MODE:
                BT_updateHFPGain(volumeFormatTo4bits(BTAPP_Volume.hfpVol), BTMHFP_GetDatabaseIndex());
                break;
            default:
                break;
        }
    }
}

/*------------------------------------------------------------*/
void BTVOL_SyncVolFromMasterToSlaveByVendorCmd( void )
{
    // FE 00 xx (sync init MCU volume from stereo master to slave)
    uint8_t vendor_data[11];
    vendor_data[0] = 0xFE;
    vendor_data[1] = 0x00;
    if(BTAPP_Volume.currentVolMode == A2DP_VOL_MODE || BTAPP_Volume.currentVolMode == HFP_VOL_MODE)
        vendor_data[2] = BTAPP_Volume.a2dpVol[BTMA2DP_getActiveDatabaseIndex()];
    else
        vendor_data[2] = BTAPP_Volume.lineInVol;
    BT_Vendor_SendCommand(vendor_data, 4);
}

void BTVOL_SyncA2DPAbsVolFromMasterToSlaveByVendorCmd( uint8_t absVol )
{
    //FE 01 xx  (sync A2DP abs volume from concert master to slave)
    uint8_t vendor_data[11];
    vendor_data[0] = 0xFE;
    vendor_data[1] = 0x01;
    vendor_data[2] = absVol;
    BT_Vendor_SendCommand(vendor_data, 3);
}

void BTVOL_SyncVolCtrlFromMasterToSlaveByVendorCmd( uint8_t volCtrl )
{
    //FE 02 xx  (sync volume up/down from concert master to slave)
    uint8_t vendor_data[11];
    vendor_data[0] = 0xFE;
    vendor_data[1] = 0x02;
    vendor_data[2] = volCtrl;
    BT_Vendor_SendCommand(vendor_data, 3);
}

void BTVOL_GotSyncVolFromMasterByVendorCmd( uint8_t vol_req, uint8_t vol_value )
{
    switch( vol_req )
    {
        case 0x00:  // FE 00 xx (sync init MCU volume from stereo master to slave)
            BTAPP_Volume.a2dpVol[BTMA2DP_getActiveDatabaseIndex()] = vol_value;
            break;
            
        case 0x01:  //FE 01 xx  (sync A2DP abs volume from concert master to slave)     -- MCHP demo
#ifdef _CODE_FOR_APP             
            if (BTAPP_Volume.currentVolMode == A2DP_VOL_MODE)
            {
                set7bitVol(vol_value, A2DP_VOL_MODE, BTMA2DP_getActiveDatabaseIndex());
                DSP_setVolCurrentMode();
            }
#endif
            break;
            
        case 0x02: //FE 02 xx (sync volume control (vol up, vol down) from concert master to slave )       --MCHP demo
#ifdef _CODE_FOR_APP             
            if(vol_value == 0)      //volume up
            {
                if ( BTAPP_Volume.currentVolMode == HFP_VOL_MODE ) 
                {
                    volumeUp(HFP_VOL_MODE, BTMHFP_GetDatabaseIndex());
                    DSP_setVolCurrentMode();
                    BT_updateHFPGain(volumeFormatTo4bits(BTAPP_Volume.hfpVol), BTMHFP_GetDatabaseIndex());
                }
                else if( BTAPP_Volume.currentVolMode == LINE_IN_VOL_MODE )
                {
                    volumeUp(LINE_IN_VOL_MODE, 0 );
                    DSP_setVolCurrentMode();
                    BT_updateLineInGain(volumeFormatTo4bits(BTAPP_Volume.lineInVol), 0);
                }
                else
                {
                    volumeUp(A2DP_VOL_MODE, BTMA2DP_getActiveDatabaseIndex());
                    DSP_setVolCurrentMode();
                    BT_updateA2DPGain(volumeFormatTo7bits(BTAPP_Volume.a2dpVol[BTMA2DP_getActiveDatabaseIndex()]), BTMA2DP_getActiveDatabaseIndex());
                }
            }
            else if(vol_value == 1)                   //volume down
            {
                if ( BTAPP_Volume.currentVolMode == HFP_VOL_MODE ) 
                {
                    volumeDown(HFP_VOL_MODE, BTMHFP_GetDatabaseIndex());
                    DSP_setVolCurrentMode();
                    BT_updateHFPGain(volumeFormatTo4bits(BTAPP_Volume.hfpVol), BTMHFP_GetDatabaseIndex());
                }
                else if( BTAPP_Volume.currentVolMode == LINE_IN_VOL_MODE )
                {
                    volumeDown(LINE_IN_VOL_MODE, 0 );
                    DSP_setVolCurrentMode();
                    BT_updateLineInGain(volumeFormatTo4bits(BTAPP_Volume.lineInVol), 0);
                }
                else
                {
                    volumeDown(A2DP_VOL_MODE, BTMA2DP_getActiveDatabaseIndex());
                    DSP_setVolCurrentMode();
                    BT_updateA2DPGain(volumeFormatTo7bits(BTAPP_Volume.a2dpVol[BTMA2DP_getActiveDatabaseIndex()]), BTMA2DP_getActiveDatabaseIndex());
                }
            }
#endif
            
        default:
            break;
    }
}

/*------------------------------------------------------------*/
VOLUME_MODE BTVOL_GetVolMode( void )
{
    return BTAPP_Volume.currentVolMode;
}

/*------------------------------------------------------------*/
void BTVOL_SetVolMode( VOLUME_MODE change_mode )
{
    BTAPP_Volume.currentVolMode = change_mode;
}

/*------------------------------------------------------------*/
uint8_t BTVOL_GetCurrentA2DPVol( void )
{
    return BTAPP_Volume.a2dpVol[BTMA2DP_getActiveDatabaseIndex()];
}

/*------------------------------------------------------------*/
uint8_t BTVOL_GetHFPVol( void )
{
    return BTAPP_Volume.hfpVol;
}

/*------------------------------------------------------------*/
uint8_t BTVOL_GetLineInVol( void )
{
    return BTAPP_Volume.lineInVol;
}

/*------------------------------------------------------------*/
void BTVOL_Init( void )
{
    uint8_t i;
    for( i = 0; i < A2DP_VOL_INDEX_MAX; i++ )
    {
        BTAPP_Volume.a2dpVol[i] = EXT_DSP_INIT_VOL;
    }
    BTAPP_Volume.hfpVol = EXT_DSP_INIT_VOL;
    BTAPP_Volume.lineInVol = EXT_DSP_INIT_VOL;
    BTAPP_Volume.currentVolMode = A2DP_VOL_MODE;
}

/*------------------------------------------------------------*/
void BTVOL_InitWithSpecificVolume( uint8_t a2dpVol, uint8_t hfpVol, uint8_t lineInVol )
{
    uint8_t i;
    if(a2dpVol <= MAX_VOL_TAB)
    {
        for( i = 0; i < A2DP_VOL_INDEX_MAX; i++ )
        {
            BTAPP_Volume.a2dpVol[i] = a2dpVol;
        }
    }
    if(hfpVol <= MAX_VOL_TAB)
        BTAPP_Volume.hfpVol = hfpVol;
    if(lineInVol <= MAX_VOL_TAB)
        BTAPP_Volume.lineInVol = lineInVol;
}
