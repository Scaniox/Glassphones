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
#define BT_A2DP_C
#include "bt_a2dp.h"
#include "bt_hfp.h"
#include "bt_multi_spk.h"
#include "bt_volume.h"
#include "bt_line_in.h"
#include "bt_command_send.h"
#include "sta369bwdsp_handler.h"
#include "bt_app.h"
#include "bt_data.h"


BTM_A2DP_STATUS BTM_A2DPStatus;
BTM_A2DP_LINK_STATUS BTM_A2DPLinkStatus;
//extern uint16_t DSP_UnmuteTimer1ms;
/*-----------------------------------------------------------------------------*/
void BTMA2DP_EventHandler( BT_A2DP_EVENTS event, uint8_t* paras, uint16_t size )
{
    uint8_t i, a2dp;
    switch(event)
    {
        case BT_EVENT_A2DP_CONNECTED:
            a2dp = 0;
            for(i = 0; i< A2DP_DATABASE_INDEX_MAX; i++)
            {
                if( BTM_A2DPLinkStatus.A2DPLinkStatus[i].bfA2DP )
                {
                    a2dp = 1;       //found A2DP link
                    break;
                }
            }
            BTM_A2DPLinkStatus.A2DPLinkStatus[ paras[1] & 0xf ].bfA2DP = 1;
            if( !a2dp )     //not found A2DP link
            {
                BTM_A2DPLinkStatus.currentA2DP_DatabaseIndex = paras[1] & 0xf;
#ifdef _SPP_MULTI_LINK_CTRL
                if( !BTMDATA_isSPPorIAPConnected() ) //no SPP connected                
                {           
                    BTMDATA_SPPLinkChangeStart( BTMA2DP_getActiveDatabaseIndex() );      //task request to create SPP link
                }
#endif                
                BTAPP_EventHandler(BT_EVENT_A2DP_LINK_CHANGED, 0, 0);       //A2DP linked, and active A2DP database index is also changed
            }
            else
            {
                BTAPP_EventHandler(BT_EVENT_A2DP_LINK_CONNECTED, 0, 0);     //one A2DP linked, but active A2DP database index is not changed.
            }
/*
            if(!( BTM_A2DPStatus.playingStatus == BT_PLAYING_PLAYING || BTM_A2DPStatus.playingStatus == BT_PLAYING_FF || BTM_A2DPStatus.playingStatus == BT_PLAYING_FR)) //not in playing, ff, fr
            {
                BTM_A2DPLinkStatus.currentA2DP_DatabaseIndex = paras[1] & 0xf;
                BTAPP_EventHandler(BT_EVENT_A2DP_LINK_CHANGED, 0, 0);       //A2DP linked, and active A2DP database index is also changed
            }
            else
            {
                BTAPP_EventHandler(BT_EVENT_A2DP_LINK_CONNECTED, 0, 0);     //one A2DP linked, but active A2DP database index is not changed.
            }
*/
            break;
            
        case BT_EVENT_A2DP_DISCONNECTED:
            BTM_A2DPLinkStatus.A2DPLinkStatus[ paras[1] & 0xf ].bfA2DP = 0;
#ifdef _SPP_MULTI_LINK_CTRL
            if( !BTMHFP_GetHFPLinkStatus(paras[1] & 0xf) 
                    && !BTM_A2DPLinkStatus.A2DPLinkStatus[ paras[1] & 0xf ].bfAVRCP )  //HFP and AVRCP link is also disconnected?
            {
                if( BTMDATA_GetSPPiAPActiveDatabaseIndex() == ( paras[1] & 0xf )
                        && BTMDATA_isSPPorIAPConnected() )      //there is SPP or iAP link belonging to this database index?
                {
                    BT_DisconnectSPPProfile();
                }
            }
#endif             
            if( (paras[1] & 0xf) == BTM_A2DPLinkStatus.currentA2DP_DatabaseIndex )    //if disconnected link is current link
            {
                //set current link from least available link
                if(BTM_A2DPLinkStatus.A2DPLinkStatus[0].bfA2DP)
                {
                    BTM_A2DPLinkStatus.currentA2DP_DatabaseIndex = 0;
                }
                else if(BTM_A2DPLinkStatus.A2DPLinkStatus[1].bfA2DP)
                {
                    BTM_A2DPLinkStatus.currentA2DP_DatabaseIndex = 1;
                }
                else if(BTM_A2DPLinkStatus.A2DPLinkStatus[2].bfA2DP)
                {
                    BTM_A2DPLinkStatus.currentA2DP_DatabaseIndex = 2;
                }
            }
            BTAPP_EventHandler(BT_EVENT_A2DP_LINK_DISCONNECTED, 0, 0);
            break;
            
        case BT_EVENT_AVRCP_CONNECTED:
            BTM_A2DPLinkStatus.A2DPLinkStatus[ paras[1] & 0xf ].bfAVRCP = 1;
            break;
            
        case BT_EVENT_AVRCP_DISCONNECTED:
            BTM_A2DPLinkStatus.A2DPLinkStatus[ paras[1] & 0xf ].bfAVRCP = 0;
#ifdef _SPP_MULTI_LINK_CTRL
            if( !BTMHFP_GetHFPLinkStatus(paras[1] & 0xf) 
                    && !BTM_A2DPLinkStatus.A2DPLinkStatus[ paras[1] & 0xf ].bfA2DP )  //HFP and AVRCP link is also disconnected?
            {
                if( BTMDATA_GetSPPiAPActiveDatabaseIndex() == ( paras[1] & 0xf )
                        && BTMDATA_isSPPorIAPConnected() )      //there is SPP or iAP link belonging to this database index?
                {
                    BT_DisconnectSPPProfile();
                }
            }
#endif            
            break;  
        
        case BT_EVENT_A2DP_STATUS:
            BTM_A2DPStatus.a2dpCodecStatus = paras[1];
            if(BTM_A2DPStatus.a2dpCodecStatus == BT_A2DP_ACTIVE)
            {
                if(BTMHFP_GetCallStatus() == BT_CALL_IDLE && BTM_LINE_IN_GetLineInStatus() == LINE_IN_INACTIVE)   //not in SCO or line in mode
                {
                    BTVOL_ChangeVolMode(A2DP_VOL_MODE, false);
                }
                //DSP_UnmuteTimer1ms = 30;      //delay to mute off
            }
            else if(BTM_A2DPStatus.a2dpCodecStatus == BT_A2DP_IDLE)
            {
                if(BTMHFP_GetCallStatus() == BT_CALL_IDLE && BTM_LINE_IN_GetLineInStatus() == LINE_IN_INACTIVE)
                {
                    //DSP_MUTE_SetLow();      //mute on to reduce pop sound
                    BTVOL_ChangeVolMode(BTVOL_GetVolMode(), false);
                }
            }
            break;
            
        case BT_EVENT_PLAYBACK_STATUS_CHANGED:
            //paras[0] = database 0 or 1 link
            //paras[1] = 0x0F or 0x0D(INTRIM or CHANGED)
            //paras = 0x48 fixed(Subunit_type + Subunit_ID)
            //paras = 0x00 fixed(Opcode)
            //paras[4 ~ 6] = 00 19 58 fixed(company ID
            //paras[7] = 0x31 fixed(PDU ID)
            //paras[8] = 0x00 fixed(packet ID)
            //paras[9 - 10] = parameter length
            //paras[11] = EventID2 (EVENT_PLAYBACK_STATUS_CHANGED (0x01), EVENT_VOLUME_CHANGED (0x0d))
            //paras[12] = PLAYING STATUS
            if( paras[11] == 0x01)        //EVENT_PLAYBACK_STATUS_CHANGED (0x01)
            {
                if( ( paras[0] != BTM_A2DPLinkStatus.currentA2DP_DatabaseIndex )     //database ID changed 
                    && (paras[12] == BT_PLAYING_PLAYING || paras[12] == BT_PLAYING_FF || paras[12] == BT_PLAYING_FR))   // && must be playing status
                {
                    //data base ID is changed, means the connected phone is changed
                    BTM_A2DPLinkStatus.currentA2DP_DatabaseIndex = paras[0];  //the first byte is linded data base ID
                    BTM_A2DPStatus.playingStatus = paras[12]; //update playing status
                    sta369bw_SetVol(1);
                    BTAPP_EventHandler( BT_EVENT_A2DP_BREAK_IN, 0, 0);
                }
                else if( paras[0] == BTM_A2DPLinkStatus.currentA2DP_DatabaseIndex )
                {
                    BTM_A2DPStatus.playingStatus = paras[12]; //update playing status
                    if (paras[1] == 0x0F)
                    {
                        BTAPP_EventHandler( BT_EVENT_A2DP_BREAK_IN, 0, 0);
                    }
                }
                else
                {
                    //don't update playing status if database ID is different from current
                }
            }
            
            break;

        case BT_EVENT_SAMPLINGRATE_CHANGED:
            if( BTM_A2DPStatus.playingSamplingRate == SAMP_96KHZ || BTM_A2DPStatus.playingSamplingRate == SAMP_88_2KHZ)
            {
                if((paras[0] != SAMP_96KHZ) && (paras[0] != SAMP_88_2KHZ))
                {
                    //set normal sampling rate
                    sta369bw_SoftMute();  
                    sta369bw_DSPStop();
                    sta369bw_setNormalSamplingrateInput();
                    sta369bw_DSPStart();
                    sta369bw_SoftMuteOff();
                }
            }
            else
            {
                if((paras[0] == SAMP_96KHZ) || (paras[0] == SAMP_88_2KHZ))
                {
                    //set high sampling rate
                    sta369bw_SoftMute();  
                    sta369bw_DSPStop();
                    sta369bw_setHighSamplingrateInput();
                    sta369bw_DSPStart();
                    sta369bw_SoftMuteOff();
                }
            }
            BTM_A2DPStatus.playingSamplingRate = paras[0];
            break;    
    }
}

/*-----------------------------------------------------------------------------*/
void BTMA2DP_Init( void )
{
#if defined (__XC32__)     
    memset( &BTM_A2DPLinkStatus, 0, sizeof(BTM_A2DPLinkStatus) );
#else
    uint8_t i;
    for(i = 0; i < A2DP_DATABASE_INDEX_MAX; i++)
    {
        BTM_A2DPLinkStatus.A2DPLinkStatus[i].bfA2DP = 0;
        BTM_A2DPLinkStatus.A2DPLinkStatus[i].bfAVRCP = 0;
    }
    BTM_A2DPLinkStatus.currentA2DP_DatabaseIndex = 0;
#endif
    BTM_A2DPStatus.a2dpCodecStatus = BT_A2DP_IDLE;
    BTM_A2DPStatus.playingStatus = BT_PLAYING_STOPPED;
}

/*-----------------------------------------------------------------------------*/
uint8_t BTMA2DP_getActiveDatabaseIndex( void )
{
    return BTM_A2DPLinkStatus.currentA2DP_DatabaseIndex;
}

/*-----------------------------------------------------------------------------*/
bool BTMA2DP_getA2DPLinkStatus( uint8_t databaseIndex )
{
    if(BTM_A2DPLinkStatus.A2DPLinkStatus[databaseIndex].bfA2DP)
        return true;
    else
        return false;  
}

/*-----------------------------------------------------------------------------*/
bool BTMA2DP_getAVRCPLinkStatus( uint8_t databaseIndex )
{
    if(BTM_A2DPLinkStatus.A2DPLinkStatus[databaseIndex].bfAVRCP)
        return true;
    else
        return false;  
}

/*-----------------------------------------------------------------------------*/
BT_A2DP_CODEC_STATUS BTMA2DP_GetA2DPCodecStatus( void )
{
    return BTM_A2DPStatus.a2dpCodecStatus;
}

/*-----------------------------------------------------------------------------*/
BT_PLAYING_STATUS BTMA2DP_GetPlayingStatus( void )
{
    return BTM_A2DPStatus.playingStatus;
}

/*-----------------------------------------------------------------------------*/
BT_PLAYING_SAMPLING_RATE BTM22DP_GetPlayingSamplingRate( void )
{
    return BTM_A2DPStatus.playingSamplingRate;
}

/*-----------------------------------------------------------------------------*/
void BTMA2DP_PlayStart( void )
{
    if (BTM_A2DPLinkStatus.A2DPLinkStatus[BTM_A2DPLinkStatus.currentA2DP_DatabaseIndex].bfAVRCP )
        BT_MusicControlCommand(0x05, BTM_A2DPLinkStatus.currentA2DP_DatabaseIndex );
}

/*-----------------------------------------------------------------------------*/
void BTMA2DP_PauseStart( void )
{
    if (BTM_A2DPLinkStatus.A2DPLinkStatus[BTM_A2DPLinkStatus.currentA2DP_DatabaseIndex].bfAVRCP )
     BT_MusicControlCommand(0x06, BTM_A2DPLinkStatus.currentA2DP_DatabaseIndex );
}

/*-----------------------------------------------------------------------------*/
void BTMA2DP_StopStart( void )
{
    if ((BTM_A2DPLinkStatus.A2DPLinkStatus[BTM_A2DPLinkStatus.currentA2DP_DatabaseIndex].bfAVRCP )
            || (BTMSPK_GetMSPKStatus() == BT_CSB_STATUS_CONNECTED_AS_NSPK_SLAVE)
            || (BTMSPK_GetMSPKStatus() == BT_CSB_STATUS_CONNECTED_AS_BROADCAST_SLAVE ))
    {
        BT_MusicControlCommand(0x08, BTM_A2DPLinkStatus.currentA2DP_DatabaseIndex );
    }
}

/*-----------------------------------------------------------------------------*/
void BTMA2DP_PlayPauseToggle( void )
{
    if( (BTMSPK_GetMSPKStatus() == BT_CSB_STATUS_CONNECTED_AS_NSPK_SLAVE) || 
        (BTMSPK_GetMSPKStatus() == BT_CSB_STATUS_CONNECTED_AS_BROADCAST_SLAVE ))       //NSPK slave
    {
        BT_MMI_ActionCommand ( 0x32, BTM_A2DPLinkStatus.currentA2DP_DatabaseIndex );
    }
    else if ( BTM_A2DPLinkStatus.A2DPLinkStatus[BTM_A2DPLinkStatus.currentA2DP_DatabaseIndex].bfAVRCP )
    {
        BT_MusicControlCommand(0x07, BTM_A2DPLinkStatus.currentA2DP_DatabaseIndex );
    }
}

/*-----------------------------------------------------------------------------*/
void BTMA2DP_PlayNext( void )
{
    if ((BTM_A2DPLinkStatus.A2DPLinkStatus[BTM_A2DPLinkStatus.currentA2DP_DatabaseIndex].bfAVRCP ) ||
        (BTMSPK_GetMSPKStatus() == BT_CSB_STATUS_CONNECTED_AS_NSPK_SLAVE) ||
        (BTMSPK_GetMSPKStatus() == BT_CSB_STATUS_CONNECTED_AS_BROADCAST_SLAVE))
    {
        BT_MMI_ActionCommand ( NEXT_SONG, BTM_A2DPLinkStatus.currentA2DP_DatabaseIndex );
    }
}

/*-----------------------------------------------------------------------------*/
void BTMA2DP_PlayPrevious( void )
{
    if ((BTM_A2DPLinkStatus.A2DPLinkStatus[BTM_A2DPLinkStatus.currentA2DP_DatabaseIndex].bfAVRCP ) ||
        (BTMSPK_GetMSPKStatus() == BT_CSB_STATUS_CONNECTED_AS_NSPK_SLAVE) ||
        (BTMSPK_GetMSPKStatus() == BT_CSB_STATUS_CONNECTED_AS_BROADCAST_SLAVE))
    {
        BT_MMI_ActionCommand ( PREVIOUS_SONG, BTM_A2DPLinkStatus.currentA2DP_DatabaseIndex );
    }
}

/*-----------------------------------------------------------------------------*/
void BTMA2DP_StartFastForward( void )
{
    if (BTM_A2DPLinkStatus.A2DPLinkStatus[BTM_A2DPLinkStatus.currentA2DP_DatabaseIndex].bfAVRCP )
    {
        BT_MusicControlCommand(0x01, BTM_A2DPLinkStatus.currentA2DP_DatabaseIndex );
    }
}

/*-----------------------------------------------------------------------------*/
void BTMA2DP_StartFastRewind( void )
{
    if (BTM_A2DPLinkStatus.A2DPLinkStatus[BTM_A2DPLinkStatus.currentA2DP_DatabaseIndex].bfAVRCP )
    {
        BT_MusicControlCommand(0x03, BTM_A2DPLinkStatus.currentA2DP_DatabaseIndex );
    }
}

/*-----------------------------------------------------------------------------*/
void BTMA2DP_CancelForwardOrRewind( void )
{
    if (BTM_A2DPLinkStatus.A2DPLinkStatus[BTM_A2DPLinkStatus.currentA2DP_DatabaseIndex].bfAVRCP )
    {
        BT_MusicControlCommand(0x00, BTM_A2DPLinkStatus.currentA2DP_DatabaseIndex );
    }
}
