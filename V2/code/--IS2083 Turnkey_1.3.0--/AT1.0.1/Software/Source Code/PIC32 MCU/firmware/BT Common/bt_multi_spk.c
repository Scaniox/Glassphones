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
#define BT_MULTI_SPK_C
#include "bt_multi_spk.h"
#include "bt_command_send.h"
#include "bt_app.h"


typedef enum {
    BT_NSPK_NO_LINK = 0,
    BT_NSPK_MASTER_LINK_TO_SLAVE2 = 1,
    BT_NSPK_MASTER_LINK_TO_SLAVE3 = 2,
    BT_NSPK_MASTER_LINK_TO_BOTH = 3,
    BT_NSPK_SLAVE_LINK_TO_MASTER = 4,
    BT_BROADCAST_MASTER = 5,
    BT_BROADCAST_SLAVE = 6,
    BT_BROADCAST_END = 7
} BT_NSPK_LINK_STATUS;  //E33 para 1(CSB_Connection_State))

typedef enum {
    BT_CSB_EVENT_STANDBY = 0,
    BT_CSB_EVENT_BUSY = 1,
    BT_CSB_EVENT_CONNECTING = 2,
    BT_CSB_EVENT_CONNECTED = 3,
    BT_CSB_EVENT_LOSS = 4,
    BT_NSPK_EVENT_BACK_TO_MASTER = 5,
    BT_NSPK_EVENT_BACK_TO_SLAVE = 6,
    BT_CSB_EVENT_CHANGE_ROLE = 7,
    BT_CSB_EVENT_DISCONNECTED_BY_NFC = 8,
    BT_CSB_EVENT_CONTINUE_CONNECTING = 9
} BT_NSPK_EVENT;//E33 para 2(CSB_State)

struct {
    BT_NSPK_LINK_STATUS nspk_link;  //E33 para 1(CSB_Connection_State))
    BT_NSPK_EVENT snpk_event;       //E33 para 2(CSB_State)
    BT_NSPK_SYSTEM_STATUS  nspk_status; //system define, external use
    uint8_t nspkSlaveCounter;
    BT_MSPK_AUDIO_CHANNEL nspkAudioChannel;
    uint8_t masterBDAddr[6];         //master device address if device is slave
#ifdef PATCH_01
    uint8_t latestConcertSlaveBDAddr[6];
#endif
    
} BT_eCSBStatus;

/*-----------------------------------------------------------------------------*/
void BTMSPK_EventHandler( BT_MSPK_EVENTS event, uint8_t* paras, uint16_t size )
{
    uint8_t* p;
    
    switch(event)
    {
        case BT_EVENT_NSPK_STATUS:
            BT_eCSBStatus.nspk_link = paras[0];
            BT_eCSBStatus.snpk_event = paras[1];

            if(BT_eCSBStatus.nspk_link)     //NSPK exist
            {
                switch(BT_eCSBStatus.nspk_link)                     {
                    case BT_NSPK_MASTER_LINK_TO_SLAVE2:// = 1,
                    case BT_NSPK_MASTER_LINK_TO_SLAVE3:// = 2,
                    case BT_NSPK_MASTER_LINK_TO_BOTH:// = 3,
                        if (BT_eCSBStatus.snpk_event == BT_CSB_EVENT_CONNECTED) {
                            BT_eCSBStatus.nspk_status = BT_CSB_STATUS_CONNECTED_AS_NSPK_MASTER;
                            BT_eCSBStatus.nspkSlaveCounter = 1;
                            p = BT_GetLocalBDAddress();
                            BT_eCSBStatus.masterBDAddr[0] = *p++;
                            BT_eCSBStatus.masterBDAddr[1] = *p++;
                            BT_eCSBStatus.masterBDAddr[2] = *p++;
                            BT_eCSBStatus.masterBDAddr[3] = *p++;
                            BT_eCSBStatus.masterBDAddr[4] = *p++;
                            BT_eCSBStatus.masterBDAddr[5] = *p;  
//#ifndef _USE_3D_ISSUE_INDEX_ASSIGN                            
                            BTAPP_EventHandler(BT_EVENT_MSPK_CONNECTED_AS_NSPK_MASTER, &paras[3], 6);
//#else
//                            BTAPP_EventHandler(BT_EVENT_MSPK_CONNECTED_AS_NSPK_MASTER, &paras[4], 6);
//#endif
                            
                            BTVOL_SyncVolFromMasterToSlaveByVendorCmd();
                        }
                        break;

                    case BT_NSPK_SLAVE_LINK_TO_MASTER:// = 4,
                        if (BT_eCSBStatus.snpk_event == BT_CSB_EVENT_CONNECTED) {
                            BT_eCSBStatus.nspk_status = BT_CSB_STATUS_CONNECTED_AS_NSPK_SLAVE;
                            BT_eCSBStatus.nspkSlaveCounter = 0;
#ifndef _SUPPORT_SIMPLE_33_EVENT
                            if(size >= 9 )
                            {
                            BT_eCSBStatus.masterBDAddr[0] = paras[3];
                            BT_eCSBStatus.masterBDAddr[1] = paras[4];
                            BT_eCSBStatus.masterBDAddr[2] = paras[5];
                            BT_eCSBStatus.masterBDAddr[3] = paras[6];
                            BT_eCSBStatus.masterBDAddr[4] = paras[7];
                            BT_eCSBStatus.masterBDAddr[5] = paras[8]; 
                            }
#endif
//#ifndef _USE_3D_ISSUE_INDEX_ASSIGN                             
                            BTAPP_EventHandler(BT_EVENT_MSPK_CONNECTED_AS_NSPK_SLAVE, &paras[3], 6); 
//#else
//                            BTAPP_EventHandler(BT_EVENT_MSPK_CONNECTED_AS_NSPK_SLAVE, &paras[4], 6); 
//#endif
                                                                                  
                        }
                        break;

                    case BT_BROADCAST_MASTER:// = 5,
                        if (BT_eCSBStatus.snpk_event == BT_CSB_EVENT_CONNECTED) {
                            if(size <9 )
                            {
                                //33 05 03 without slave index and slave address will be regard as broadcast grouping cancelling
                                if( BT_eCSBStatus.nspk_status == BT_CSB_STATUS_BROADCAST_MASTER_CONNECTING )
                                {
                                    BT_eCSBStatus.nspk_status = BT_CSB_STATUS_CONNECTED_AS_BROADCAST_MASTER;        //connecting -> connected
                                    BTAPP_EventHandler(BT_EVENT_MSPK_BROADCAST_MASTER_CONNECTING_END, 0, 0); 
                                }
                                break;
                            }
                            BT_eCSBStatus.nspk_status = BT_CSB_STATUS_CONNECTED_AS_BROADCAST_MASTER;
#ifdef PATCH_01
                            if( BT_eCSBStatus.latestConcertSlaveBDAddr[0] == paras[3]
                                    && BT_eCSBStatus.latestConcertSlaveBDAddr[1] == paras[4]
                                    && BT_eCSBStatus.latestConcertSlaveBDAddr[2] == paras[5]
                                    && BT_eCSBStatus.latestConcertSlaveBDAddr[3] == paras[6]
                                    && BT_eCSBStatus.latestConcertSlaveBDAddr[4] == paras[7]
                                    && BT_eCSBStatus.latestConcertSlaveBDAddr[5] == paras[8] )
                                break;
                            BT_eCSBStatus.latestConcertSlaveBDAddr[0] = paras[3];
                            BT_eCSBStatus.latestConcertSlaveBDAddr[1] = paras[4];
                            BT_eCSBStatus.latestConcertSlaveBDAddr[2] = paras[5];
                            BT_eCSBStatus.latestConcertSlaveBDAddr[3] = paras[6];
                            BT_eCSBStatus.latestConcertSlaveBDAddr[4] = paras[7];
                            BT_eCSBStatus.latestConcertSlaveBDAddr[5] = paras[8];
#endif                            
                            BT_eCSBStatus.nspkSlaveCounter++;
                            p = BT_GetLocalBDAddress();
                            BT_eCSBStatus.masterBDAddr[0] = *p++;
                            BT_eCSBStatus.masterBDAddr[1] = *p++;
                            BT_eCSBStatus.masterBDAddr[2] = *p++;
                            BT_eCSBStatus.masterBDAddr[3] = *p++;
                            BT_eCSBStatus.masterBDAddr[4] = *p++;
                            BT_eCSBStatus.masterBDAddr[5] = *p;
//#ifndef _USE_3D_ISSUE_INDEX_ASSIGN                             
                            BTAPP_EventHandler(BT_EVENT_MSPK_CONNECTED_AS_BROADCAST_MASTER,  &paras[3], 6); 
//#else
//                            BTAPP_EventHandler(BT_EVENT_MSPK_CONNECTED_AS_BROADCAST_MASTER,  &paras[4], 6); 
//#endif                            
                        }
                        else if(BT_eCSBStatus.snpk_event == BT_CSB_EVENT_CONTINUE_CONNECTING) {
                            BT_eCSBStatus.nspk_status = BT_CSB_STATUS_BROADCAST_MASTER_CONNECTING;
                            BTAPP_EventHandler(BT_EVENT_MSPK_BROADCAST_MASTER_CONNECTING_MORE, 0, 0); 
                            
                        }
                        break;

                    case BT_BROADCAST_SLAVE:// = 6
                        if (BT_eCSBStatus.snpk_event == BT_CSB_EVENT_CONNECTED) {
                            BT_eCSBStatus.nspk_status = BT_CSB_STATUS_CONNECTED_AS_BROADCAST_SLAVE;
                            BT_eCSBStatus.nspkSlaveCounter = 0;
#ifndef _SUPPORT_SIMPLE_33_EVENT                            
                            if(size >= 9 )
                            {
                            BT_eCSBStatus.masterBDAddr[0] = paras[3];
                            BT_eCSBStatus.masterBDAddr[1] = paras[4];
                            BT_eCSBStatus.masterBDAddr[2] = paras[5];
                            BT_eCSBStatus.masterBDAddr[3] = paras[6];
                            BT_eCSBStatus.masterBDAddr[4] = paras[7];
                            BT_eCSBStatus.masterBDAddr[5] = paras[8];
                            }
#endif
//#ifndef _USE_3D_ISSUE_INDEX_ASSIGN                            
                            BTAPP_EventHandler(BT_EVENT_MSPK_CONNECTED_AS_BROADCAST_SLAVE,  &paras[3], 6); 
//#else
//                            BTAPP_EventHandler(BT_EVENT_MSPK_CONNECTED_AS_BROADCAST_SLAVE,  &paras[4], 6); 
//#endif
                        }
                        break;
                        //>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
                    case BT_BROADCAST_END:  //7
                        if( BT_eCSBStatus.nspk_status == BT_CSB_STATUS_BROADCAST_MASTER_CONNECTING )
                        {
                            BT_eCSBStatus.nspk_status = BT_CSB_STATUS_CONNECTED_AS_BROADCAST_MASTER;        //connecting -> connected
                            BTAPP_EventHandler(BT_EVENT_MSPK_BROADCAST_MASTER_CONNECTING_END, 0, 0); 
                        }
                        break;
                        //<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
                }
            }
            else
            {
                if(BT_eCSBStatus.snpk_event == BT_CSB_EVENT_STANDBY){
                    BT_eCSBStatus.nspk_status = BT_CSB_STATUS_STANDBY;	
                    BT_eCSBStatus.nspkSlaveCounter = 0;
                    BTAPP_EventHandler(BT_EVENT_MSPK_STANDBY, 0, 0);                     
#ifdef PATCH_01
                    BT_eCSBStatus.latestConcertSlaveBDAddr[0] = 0;
                    BT_eCSBStatus.latestConcertSlaveBDAddr[1] = 0;
                    BT_eCSBStatus.latestConcertSlaveBDAddr[2] = 0;
                    BT_eCSBStatus.latestConcertSlaveBDAddr[3] = 0;
                    BT_eCSBStatus.latestConcertSlaveBDAddr[4] = 0;
                    BT_eCSBStatus.latestConcertSlaveBDAddr[5] = 0;
#endif                    
                }
                else if(BT_eCSBStatus.snpk_event == BT_CSB_EVENT_CONNECTING){
                    BT_eCSBStatus.nspk_status = BT_CSB_STATUS_CONNECTING;
                    BT_eCSBStatus.nspkSlaveCounter = 0;
                    BTAPP_EventHandler(BT_EVENT_MSPK_CONNECTING, 0, 0); 
#ifdef PATCH_01
                    BT_eCSBStatus.latestConcertSlaveBDAddr[0] = 0;
                    BT_eCSBStatus.latestConcertSlaveBDAddr[1] = 0;
                    BT_eCSBStatus.latestConcertSlaveBDAddr[2] = 0;
                    BT_eCSBStatus.latestConcertSlaveBDAddr[3] = 0;
                    BT_eCSBStatus.latestConcertSlaveBDAddr[4] = 0;
                    BT_eCSBStatus.latestConcertSlaveBDAddr[5] = 0;
#endif                    
                }
                else if( BT_eCSBStatus.snpk_event == BT_CSB_EVENT_LOSS ) {
                    if( BT_eCSBStatus.nspk_status == BT_CSB_STATUS_CONNECTED_AS_BROADCAST_SLAVE )   //in other situation, peer lost will start auto connecting
                    {
                        BT_eCSBStatus.nspk_status = BT_CSB_STATUS_STANDBY;	
                        BTAPP_EventHandler(BT_EVENT_MSPK_STANDBY, 0, 0);  
                    }
                }
            }
            break;      //switch event
            
        case BT_EVENT_NSPK_AUDIO_CHANNEL:
            BT_eCSBStatus.nspkAudioChannel = paras[1];
            BTAPP_EventHandler(BT_EVENT_MSPK_SYNC_AUDIO_CHANNEL, &paras[1], 1); 
            break;
            
        case NSPK_EVENT_ADD_SPEAKER3:
            if(BT_eCSBStatus.nspk_link == BT_NSPK_MASTER_LINK_TO_SLAVE2     //this is master, it connects to speaker 2 only
            || BT_eCSBStatus.nspk_link == BT_NSPK_MASTER_LINK_TO_SLAVE3)    //this is master, it connects to speaker 3 only
            {
                BT_MMI_ActionCommand ( 0xF6, 0);
            }
            break;
            
        default:
            break;
    }
}

/*-----------------------------------------------------------------------------*/
BT_NSPK_SYSTEM_STATUS BTMSPK_GetMSPKStatus( void )
{
    return BT_eCSBStatus.nspk_status;
}

/*-----------------------------------------------------------------------------*/
void BTMSPK_GetNSPKLinksStatusAndEvent( uint8_t* pNspkLink, uint8_t* pNspkEvent )
{
    *pNspkLink = BT_eCSBStatus.nspk_link;
    *pNspkEvent = BT_eCSBStatus.snpk_event;
}

/*-----------------------------------------------------------------------------*/
uint8_t BTMSPK_GetSlaveCounter( void )
{
    return BT_eCSBStatus.nspkSlaveCounter;
}

/*-----------------------------------------------------------------------------*/
uint8_t* BTMSPK_GetMasterBDAddress( void )
{
    return &BT_eCSBStatus.masterBDAddr[0];
}

/*-----------------------------------------------------------------------------*/
void BTMSPK_Init( void )
{
    BT_eCSBStatus.nspk_link = BT_NSPK_NO_LINK;
    BT_eCSBStatus.snpk_event = BT_CSB_EVENT_STANDBY;
    BT_eCSBStatus.nspk_status = BT_CSB_STATUS_STANDBY;
}

/*-----------------------------------------------------------------------------*/
void BTMSPK_TriggerStereoModeMaster( void )
{
    if( BT_eCSBStatus.nspk_status == BT_CSB_STATUS_STANDBY
            || BT_eCSBStatus.nspk_status == BT_CSB_STATUS_CONNECTED_AS_BROADCAST_MASTER
            || BT_eCSBStatus.nspk_status == BT_CSB_STATUS_CONNECTED_AS_BROADCAST_SLAVE
            || BT_eCSBStatus.nspk_status == BT_CSB_STATUS_BROADCAST_MASTER_CONNECTING )
    {
        BT_MMI_ActionCommand ( 0xF4, 0 );
        BT_MMI_ActionCommand(MASTERSPK_ENTER_CSB_PAGE, 0 );
    }
}

/*-----------------------------------------------------------------------------*/
void BTMSPK_TriggerStereoModeSlave( void )
{
    if( BT_eCSBStatus.nspk_status == BT_CSB_STATUS_STANDBY
            || BT_eCSBStatus.nspk_status == BT_CSB_STATUS_CONNECTED_AS_BROADCAST_MASTER
            || BT_eCSBStatus.nspk_status == BT_CSB_STATUS_CONNECTED_AS_BROADCAST_SLAVE
            || BT_eCSBStatus.nspk_status == BT_CSB_STATUS_BROADCAST_MASTER_CONNECTING )
    {
        BT_MMI_ActionCommand ( 0xF4, 0 );
        BT_MMI_ActionCommand(SLAVESPK_ENTER_CSB_PAGESCAN, 0 );
    }
}

/*-----------------------------------------------------------------------------*/
void BTMSPK_TriggerConcertModeMaster( void )
{
    if( BT_eCSBStatus.nspk_status == BT_CSB_STATUS_STANDBY 
            || BT_eCSBStatus.nspk_status == BT_CSB_STATUS_CONNECTED_AS_NSPK_MASTER
            || BT_eCSBStatus.nspk_status == BT_CSB_STATUS_CONNECTED_AS_NSPK_SLAVE
            || BT_eCSBStatus.nspk_status == BT_CSB_STATUS_NSPK_MASTER_CONNECTING )
    {
        BT_MMI_ActionCommand ( 0xF5, 0 );
        BT_MMI_ActionCommand(MASTERSPK_ENTER_CSB_PAGE, 0 );
    }
}

/*-----------------------------------------------------------------------------*/
void BTMSPK_TriggerConcertModeSlave( void )
{
    if( BT_eCSBStatus.nspk_status == BT_CSB_STATUS_STANDBY 
            || BT_eCSBStatus.nspk_status == BT_CSB_STATUS_CONNECTED_AS_NSPK_MASTER
            || BT_eCSBStatus.nspk_status == BT_CSB_STATUS_CONNECTED_AS_NSPK_SLAVE
            || BT_eCSBStatus.nspk_status == BT_CSB_STATUS_NSPK_MASTER_CONNECTING )
    {
        BT_MMI_ActionCommand ( 0xF5, 0 );
        BT_MMI_ActionCommand(SLAVESPK_ENTER_CSB_PAGESCAN, 0 );
    }
}

/*-----------------------------------------------------------------------------*/
void BTMSPK_CreatStereoMode( void )
{
    if( BT_eCSBStatus.nspk_status == BT_CSB_STATUS_STANDBY
            || BT_eCSBStatus.nspk_status == BT_CSB_STATUS_CONNECTED_AS_BROADCAST_MASTER
            || BT_eCSBStatus.nspk_status == BT_CSB_STATUS_CONNECTED_AS_BROADCAST_SLAVE
            || BT_eCSBStatus.nspk_status == BT_CSB_STATUS_BROADCAST_MASTER_CONNECTING )
    {
        BT_MMI_ActionCommand ( 0xF4, 0 );
        BT_MMI_ActionCommand(NSPK_ADD_SPEAKER, 0 );
    }
}

/*-----------------------------------------------------------------------------*/
void BTMSPK_CreatConcertMode( void )
{
    if( BT_eCSBStatus.nspk_status == BT_CSB_STATUS_STANDBY 
            || BT_eCSBStatus.nspk_status == BT_CSB_STATUS_CONNECTED_AS_NSPK_MASTER
            || BT_eCSBStatus.nspk_status == BT_CSB_STATUS_CONNECTED_AS_NSPK_SLAVE
            || BT_eCSBStatus.nspk_status == BT_CSB_STATUS_NSPK_MASTER_CONNECTING )
    {
        BT_MMI_ActionCommand ( 0xF5, 0 );   //nwo code support adding two command at one time
        BT_MMI_ActionCommand(NSPK_ADD_SPEAKER, 0 ); 
    }
}

/*-----------------------------------------------------------------------------*/
void BTMSPK_AddMoreSpeaker( void )
{
    if( BT_eCSBStatus.nspk_status == BT_CSB_STATUS_CONNECTED_AS_BROADCAST_MASTER )
    {
        BT_MMI_ActionCommand(0xF6, 0 );
    }
}

/*-----------------------------------------------------------------------------*/
void BTMSPK_CancelGroupCreation( void )
{
    if( BT_eCSBStatus.nspk_status != BT_CSB_STATUS_STANDBY )
    {
        BT_MMI_ActionCommand ( 0xE3, 0 );     //cancel NSPK creation
    }
}

/*-----------------------------------------------------------------------------*/
void BTMSPK_CancelGroup( void )
{
    if( BT_eCSBStatus.nspk_status != BT_CSB_STATUS_STANDBY )
    {
        BT_MMI_ActionCommand ( 0xE5, 0 );     //cancel/terminate NSPK link
    }
}

/*-----------------------------------------------------------------------------*/
void BTMSPK_BackToLastGroupMode( void )
{
    BT_MMI_ActionCommand ( 0xF9, 0 ); 
}

/*-----------------------------------------------------------------------------*/
void BTMSPK_GroupModeSwitch( void )
{
    BT_MMI_ActionCommand ( 0xF8, 0 ); 
}

/*-----------------------------------------------------------------------------*/
void BTMSPK_GroupSpeakerSoundSync( void )
{
    if( BT_eCSBStatus.nspk_status == BT_CSB_STATUS_CONNECTED_AS_BROADCAST_MASTER 
            || BT_eCSBStatus.nspk_status == BT_CSB_STATUS_BROADCAST_MASTER_CONNECTING
            || BT_eCSBStatus.nspk_status == BT_CSB_STATUS_CONNECTED_AS_NSPK_MASTER
            || BT_eCSBStatus.nspk_status == BT_CSB_STATUS_CONNECTED_AS_NSPK_SLAVE ) 
    {
        BT_MMI_ActionCommand ( 0xF7, 0 );
    }
}

/*-----------------------------------------------------------------------------*/
void BTMSPK_StereoModeSwitchAudioChannel( void )
{
    if ( BT_eCSBStatus.nspk_status == BT_CSB_STATUS_CONNECTED_AS_NSPK_MASTER //nspk master
        || BT_eCSBStatus.nspk_status == BT_CSB_STATUS_CONNECTED_AS_NSPK_SLAVE) //nspk slave
    {
        BT_MMI_ActionCommand ( 0xEC, 0 );
    }
}

/*-----------------------------------------------------------------------------*/
void BTMSPK_StereoModeSetAudioChannel( BT_MSPK_AUDIO_CHANNEL ch )
{
    if ( BT_eCSBStatus.nspk_status == BT_CSB_STATUS_CONNECTED_AS_NSPK_MASTER //nspk master
        || BT_eCSBStatus.nspk_status == BT_CSB_STATUS_CONNECTED_AS_NSPK_SLAVE) //nspk slave
    {
        BT_SetStereoModeAudioChannel( ch );
    }
}

/*-----------------------------------------------------------------------------*/
BT_MSPK_AUDIO_CHANNEL BTMSPK_GetStereoModeAudioChannel( void )
{
    return BT_eCSBStatus.nspkAudioChannel;
}

/*-----------------------------------------------------------------------------*/
