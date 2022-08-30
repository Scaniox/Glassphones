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
#define BT_HFP_C
#include "bt_hfp.h"
#include "bt_a2dp.h"
#include "bt_volume.h"
#include "bt_line_in.h"
#include "bt_command_send.h"
#include "bt_app.h"
#include "bt_data.h"

BT_HFP_STATUS BT_CallStatus;
BTM_HFP_LINK_STATUS BTM_HFPLinkStatus;

/*-----------------------------------------------------------------------------*/
void BTMHFP_EventHandler( BT_HFP_EVENTS event, uint8_t* paras, uint16_t size )
{
    switch(event)
    {
        case BT_EVENT_CALL_STATUS_CHANGED:
            BT_CallStatus = paras[1];
//            if(BT_CallStatus != BT_CALL_IDLE)
//            {
//                BTVOL_ChangeVolMode(HFP_VOL_MODE, false);
//            }
//            else
//            {
//                if(BTM_LINE_IN_GetLineInStatus() != LINE_IN_INACTIVE)
//                {
//                    BTVOL_ChangeVolMode(LINE_IN_VOL_MODE, false);
//                }
//                else
//                {
//                    BTVOL_ChangeVolMode(A2DP_VOL_MODE, false);
//                }
//            }
            break;
            
        case BT_EVENT_HFP_CONNECTED:
            BTM_HFPLinkStatus.HFPLinkStatus.bfHFP = 1;
            BTM_HFPLinkStatus.HFP_DatabaseIndex = paras[1] & 0xf; 
            BTAPP_EventHandler(BT_EVENT_HFP_LINK_CONNECTED, 0, 0);
            break;
            
        case BT_EVENT_HFP_DISCONNECTED:
            BTM_HFPLinkStatus.HFPLinkStatus.bfHFP = 0;
#ifdef _SPP_MULTI_LINK_CTRL
            if( !BTMA2DP_getA2DPLinkStatus(BTM_HFPLinkStatus.HFP_DatabaseIndex)
                    && !BTMA2DP_getAVRCPLinkStatus(BTM_HFPLinkStatus.HFP_DatabaseIndex) )   //A2DP and AVRCP belonging to this database index are also disconnected?
            {
                if( BTMDATA_GetSPPiAPActiveDatabaseIndex() == BTM_HFPLinkStatus.HFP_DatabaseIndex
                        && BTMDATA_isSPPorIAPConnected() )      //there is SPP or iAP link belonging to this database index?
                {
                    BT_DisconnectSPPProfile();
                }
            }
#endif            
            BTAPP_EventHandler(BT_EVENT_HFP_LINK_DISCONNECTED, 0, 0);
            break;
            
    }
}

/*-----------------------------------------------------------------------------*/
BT_HFP_STATUS BTMHFP_GetCallStatus( void )
{
    return BT_CallStatus;
}

/*-----------------------------------------------------------------------------*/
void BTMHFP_Init( void )
{
    BTM_HFPLinkStatus.HFP_DatabaseIndex = 0;
    BTM_HFPLinkStatus.HFPLinkStatus.bfHFP = 0;
    BT_CallStatus = BT_CALL_IDLE;
}

/*-----------------------------------------------------------------------------*/
uint8_t BTMHFP_GetDatabaseIndex( void )
{
    return BTM_HFPLinkStatus.HFP_DatabaseIndex;
}

/*-----------------------------------------------------------------------------*/
bool BTMHFP_GetHFPLinkStatus( uint8_t databaseIndex )
{
    if(BTM_HFPLinkStatus.HFPLinkStatus.bfHFP)
        return true;
    else
        return false;
}

/*-----------------------------------------------------------------------------*/
void BTMHFP_AcceptCall( void )
{
    if( BTM_HFPLinkStatus.HFPLinkStatus.bfHFP )
        BT_MMI_ActionCommand ( ACCEPT_CALL, BTM_HFPLinkStatus.HFP_DatabaseIndex );
}

/*-----------------------------------------------------------------------------*/
void BTMHFP_EndCall( void )
{
    if( BTM_HFPLinkStatus.HFPLinkStatus.bfHFP )
        BT_MMI_ActionCommand ( FORCE_END_CALL, BTM_HFPLinkStatus.HFP_DatabaseIndex );
}

/*-----------------------------------------------------------------------------*/
void BTMHFP_RejectCall( void )
{
    if( BTM_HFPLinkStatus.HFPLinkStatus.bfHFP )
        BT_MMI_ActionCommand ( REJECT_CALL, BTM_HFPLinkStatus.HFP_DatabaseIndex );
}

/*-----------------------------------------------------------------------------*/
void BTMHFP_SwitchToHoldCall( void )
{
    if( BTM_HFPLinkStatus.HFPLinkStatus.bfHFP )
        BT_MMI_ActionCommand ( 0x0D, BTM_HFPLinkStatus.HFP_DatabaseIndex );     //switch between active and hold call
}

/*-----------------------------------------------------------------------------*/
void BTMHFP_RejectWaitingCallOrReleaseHoldCall( void )
{
    if( BTM_HFPLinkStatus.HFPLinkStatus.bfHFP )
        BT_MMI_ActionCommand ( 0x11, BTM_HFPLinkStatus.HFP_DatabaseIndex );         //reject waiting incoming call or end the hold call
}

/*-----------------------------------------------------------------------------*/
void BTMHFP_AcceptWaitingCall( void )
{
    if( BTM_HFPLinkStatus.HFPLinkStatus.bfHFP )
        BT_MMI_ActionCommand ( 0x12, BTM_HFPLinkStatus.HFP_DatabaseIndex );         //answer waiting incoming call   
}

/*-----------------------------------------------------------------------------*/
void BTMHFP_TransferCall( void )
{
    if( BTM_HFPLinkStatus.HFPLinkStatus.bfHFP )
        BT_MMI_ActionCommand ( 0x0E, BTM_HFPLinkStatus.HFP_DatabaseIndex );     //switch voice between phone and headset
}

/*-----------------------------------------------------------------------------*/
void BTMHFP_DialLastNumber( void )
{
    if( BTM_HFPLinkStatus.HFPLinkStatus.bfHFP )
        BT_MMI_ActionCommand ( LAST_NUMBER_REDIAL, BTM_HFPLinkStatus.HFP_DatabaseIndex );
}

/*-----------------------------------------------------------------------------*/
void BTMHFP_VoiceDial( void )
{
    if( BTM_HFPLinkStatus.HFPLinkStatus.bfHFP )
        BT_MMI_ActionCommand ( 0x0A, BTM_HFPLinkStatus.HFP_DatabaseIndex);     //voice dial
}

/*-----------------------------------------------------------------------------*/
void BTMHFP_CancelVoiceDial( void )
{
    if( BTM_HFPLinkStatus.HFPLinkStatus.bfHFP )
        BT_MMI_ActionCommand ( 0x0B, BTM_HFPLinkStatus.HFP_DatabaseIndex );     //cancel voice dial
}

