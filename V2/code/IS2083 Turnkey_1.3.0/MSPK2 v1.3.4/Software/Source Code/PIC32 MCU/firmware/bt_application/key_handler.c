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
#include <xc.h>
#include "bt_hardware_profile.h"

#define KEY_HANDLER_C
 #include "key_handler.h"
#include "key.h"
#include "bt_app.h"
#include "led.h"
#include "sta369bwdsp_handler.h"

#include "bt_volume.h"
#include "bt_a2dp.h"
#include "bt_hfp.h"
#include "bt_multi_spk.h"


void KEY_Handler ( uint8_t key, uint8_t event )
{
    
    switch ( key )
    {
        case KEY_ID_PLAY_PAUSE:
            if( event == KEY_EVENT_PRIMARY )
            {
                if(BTAPP_GetStatus() == BT_STATUS_OFF)
                {
                    BTAPP_TaskReq(BT_REQ_SYSTEM_ON);        //power on when power off
                }
                else if(BTAPP_GetStatus() == BT_STATUS_READY)
                {
                    switch(BTMHFP_GetCallStatus())
                    {
                        case BT_CALL_IDLE:
                            BTMA2DP_PlayPauseToggle();                  //toggle play/pause when no calling event   
                            break;
                        case BT_VOICE_DIAL:
                            BTMHFP_CancelVoiceDial();                   //cancel voice dialing when voice dialing
                            break;
                        case BT_CALL_INCOMMING:
                            BTMHFP_AcceptCall();                        //accept call when call is incoming
                            break;
                        case BT_CALL_OUTGOING:
                        case BT_CALLING:
                            BTMHFP_EndCall();                           //end call when calling
                            break;
                        case BT_CALLING_WAITING:
                            BTMHFP_AcceptWaitingCall();                 //accept the waiting call, but will also end current active all.
                            break;
                        case BT_CALLING_SWITCH_CALL:
                            BTMHFP_SwitchToHoldCall();                  //switch between the active call and hold call
                            break;
                        case BT_CALLING_HOLD:
                            BTMHFP_RejectWaitingCallOrReleaseHoldCall();    //end the hold call
                            break;
                        default:
                            break;
                    }
                }
            }
            else if(event == KEY_EVENT_SECONDARY)
            {
                if(BTAPP_GetStatus() == BT_STATUS_OFF)
                {
                    BTAPP_TaskReq(BT_REQ_SYSTEM_ON);
                }
                else if(BTAPP_GetStatus() == BT_STATUS_READY)
                {
                    switch(BTMHFP_GetCallStatus())
                    {
                        case BT_CALL_IDLE:
                            BTMHFP_VoiceDial();                  // voice dial   
                            break;
                        case BT_VOICE_DIAL:
                            BTMHFP_CancelVoiceDial();                   //cancel voice dialing when voice dialing
                            break;
                        case BT_CALL_INCOMMING:
                            BTMHFP_RejectCall();                        //accept call when call is incoming
                            break;
                        case BT_CALL_OUTGOING:
                            BTMHFP_EndCall();                               //end call when calling
                            break;
                        case BT_CALLING:
                            BTMHFP_TransferCall();                          //switch voice between headset and phone
                            break;
                        case BT_CALLING_WAITING:
                            BTMHFP_RejectWaitingCallOrReleaseHoldCall();    //reject the waiting incoming call
                            break;
                        case BT_CALLING_HOLD:
                            BTMHFP_RejectWaitingCallOrReleaseHoldCall();    //end the hold call
                            break;
                        default:
                            break;
                    }
                }
            }
            else if( event == KEY_EVENT_DOUBLE_CLICK )
            {
                if(BTAPP_GetStatus() == BT_STATUS_OFF)
                {
                    BTAPP_TaskReq(BT_REQ_SYSTEM_ON);
                }
                else if(BTAPP_GetStatus() == BT_STATUS_READY)
                {
                    switch(BTMHFP_GetCallStatus())
                    {
                        case BT_CALL_IDLE:
                            BTMHFP_DialLastNumber();                        //redail the last number
                            break;
                        case BT_CALL_OUTGOING:
                            BTMHFP_EndCall();                               //end call when calling
                            break;
                        default:
                            break;
                    }
                }
            }
            break;
            
        case KEY_ID_PAIRING:
            if( event == KEY_EVENT_PRIMARY )
            {
                if(BTAPP_GetStatus() == BT_STATUS_OFF)
                {
                    BTAPP_TaskReq(BT_REQ_SYSTEM_ON);
                }
                else if(BTAPP_GetStatus() == BT_STATUS_READY || BTAPP_GetStatus() == BT_STATUS_ON)
                {
                    BTAPP_TaskReq(BT_REQ_SYSTEM_OFF);
                    Set_LED_Style(LED_0, LED_OFF, 500, 500);
                    Set_LED_Style(LED_1, LED_OFF, 500, 500);
                    Set_LED_Style(LED_2, LED_OFF, 500, 500);
                    Set_LED_Style(LED_3, LED_OFF, 500, 500);
                }
            }
            else if( event == KEY_EVENT_SECONDARY )
            {
                if(BTAPP_GetStatus() == BT_STATUS_OFF)
                {
                    BTAPP_TaskReq(BT_REQ_SYSTEM_ON);
                }
                else if(BTAPP_GetStatus() == BT_STATUS_READY)
                {
                    if( BTMHFP_GetCallStatus() == BT_CALL_IDLE 
                            && BTMSPK_GetMSPKStatus() != BT_CSB_STATUS_CONNECTED_AS_NSPK_SLAVE
                            && BTMSPK_GetMSPKStatus() != BT_CSB_STATUS_CONNECTED_AS_BROADCAST_SLAVE )
                        BTAPP_EnterBTPairingMode();
                }
            }
            else if( event == KEY_EVENT_DOUBLE_CLICK )
            {
                if(BTAPP_GetStatus() == BT_STATUS_OFF)
                {
                    BTAPP_TaskReq(BT_REQ_SYSTEM_ON);
                }
                else if(BTAPP_GetStatus() == BT_STATUS_READY)
                {
                    BTAPP_SoundVersion();     //not support this function in 104 ROM
                }
            }
            else if( event == KEY_EVENT_LONG_TIME_HOLD )
            {
                BTAPP_ResetEEPROMtoDefault();
            }
            break;
            
        case KEY_ID_FUNC1:
//            if( event == KEY_EVENT_PRIMARY )
//            {
//                if(BTAPP_GetStatus() == BT_STATUS_READY)
//                {
//                    BTMSPK_StereoModeSwitchAudioChannel();
//                }
//            }
//            else if( event == KEY_EVENT_SECONDARY )
//            {
//                if(BTAPP_GetStatus() == BT_STATUS_READY)
//                {
//                    switch( BTMSPK_GetMSPKStatus() )
//                    {
//                        case BT_CSB_STATUS_STANDBY:
//                            BTMSPK_CreatStereoMode();
//                            break;
//                        case BT_CSB_STATUS_CONNECTING:
//                            BTMSPK_CancelGroupCreation();
//                            break;
//                        case BT_CSB_STATUS_CONNECTED_AS_NSPK_MASTER:
//                        case BT_CSB_STATUS_CONNECTED_AS_NSPK_SLAVE:
//                            BTMSPK_CancelGroup();
//                            break;
//                        case BT_CSB_STATUS_NSPK_MASTER_CONNECTING:
//                            BTMSPK_CancelGroupCreation();
//                            break;
//                        case BT_CSB_STATUS_CONNECTED_AS_BROADCAST_MASTER:
//                        case BT_CSB_STATUS_CONNECTED_AS_BROADCAST_SLAVE:
//                        case BT_CSB_STATUS_BROADCAST_MASTER_CONNECTING:
//                            BTMSPK_CreatStereoMode(); //according to Andre request, enter NSPK mode from broadcast mode directly.
//                            break;
//                    }
//                }
//            }
            break;
            
        case KEY_ID_FUNC2:
            if( event == KEY_EVENT_PRIMARY )
            {
                if(BTAPP_GetStatus() == BT_STATUS_READY)
                {
                    BTMSPK_GroupSpeakerSoundSync();
                }
            }
//            else if( event == KEY_EVENT_SECONDARY )
//            {
//                if(BTAPP_GetStatus() == BT_STATUS_READY)
//                {
//                    switch (BTMSPK_GetMSPKStatus()) 
//                    {
//                        case BT_CSB_STATUS_STANDBY:
//                            BTMSPK_CreatConcertMode();
//                            break;
//                        case BT_CSB_STATUS_CONNECTING:
//                            BTMSPK_CancelGroupCreation();
//                            break;
//                        case BT_CSB_STATUS_CONNECTED_AS_NSPK_MASTER:
//                        case BT_CSB_STATUS_CONNECTED_AS_NSPK_SLAVE:
//                        case BT_CSB_STATUS_NSPK_MASTER_CONNECTING:
//                            BTMSPK_CreatConcertMode(); //according to Andre request, enter NSPK mode from broadcast mode directly.
//                            break;
//                        case BT_CSB_STATUS_CONNECTED_AS_BROADCAST_MASTER:
//                        case BT_CSB_STATUS_CONNECTED_AS_BROADCAST_SLAVE:
//                            BTMSPK_CancelGroup();
//                            break;
//                        case BT_CSB_STATUS_BROADCAST_MASTER_CONNECTING:
//                            BTMSPK_CancelGroupCreation();
//                            break;
//                    }
//                }
//            }
//            else if( event == KEY_EVENT_DOUBLE_CLICK )
//            {
//                if(BTAPP_GetStatus() == BT_STATUS_READY)
//                {
//                    BTMSPK_AddMoreSpeaker();
//                }
//            }
            break;
        
        case KEY_ID_FWD:
            if(event == KEY_EVENT_PRIMARY)
            {
                if(BTAPP_GetStatus() == BT_STATUS_READY)
                    BTMA2DP_PlayNext();
            }
            else if(event == KEY_EVENT_SECONDARY)
            {
                if(BTAPP_GetStatus() == BT_STATUS_READY)
                    BTMA2DP_StartFastForward();
            }
            else if(event == KEY_EVENT_SECONDARY_RELEASED)
            {
                if(BTAPP_GetStatus() == BT_STATUS_READY)
                {
                    BTMA2DP_CancelForwardOrRewind();
                }
            }
            break;
            
        case KEY_ID_REV:
            if(event == KEY_EVENT_PRIMARY)
            {
                if(BTAPP_GetStatus() == BT_STATUS_READY)
                    BTMA2DP_PlayPrevious();
            }
            else if(event == KEY_EVENT_SECONDARY)
            {
                if(BTAPP_GetStatus() == BT_STATUS_READY)
                    BTMA2DP_StartFastRewind();
            }
            else if(event == KEY_EVENT_SECONDARY_RELEASED)
            {
                if(BTAPP_GetStatus() == BT_STATUS_READY)
                {
                    BTMA2DP_CancelForwardOrRewind();
                }
            }
            break;
            
        case KEY_ID_VOL_UP:
            if(event == KEY_EVENT_PRIMARY)
            {
                if(BTAPP_GetStatus() == BT_STATUS_READY)
                    BTVOL_VolUp();//BTAPP_VolUp();
                else
                    sta369bw_vol_up();
            }
            else if( event == KEY_EVENT_SECONDARY )
            {
                if(BTAPP_GetStatus() == BT_STATUS_READY)
                {
                    switch (BTMSPK_GetMSPKStatus()) 
                    {
                        case BT_CSB_STATUS_STANDBY:
                            BTMSPK_CreatConcertMode();
                            break;
                        case BT_CSB_STATUS_CONNECTING:
                            BTMSPK_CancelGroupCreation();
                            break;
                        case BT_CSB_STATUS_CONNECTED_AS_NSPK_MASTER:
                        case BT_CSB_STATUS_CONNECTED_AS_NSPK_SLAVE:
                        case BT_CSB_STATUS_NSPK_MASTER_CONNECTING:
                            BTMSPK_CreatConcertMode(); //according to Andre request, enter NSPK mode from broadcast mode directly.
                            break;
                        case BT_CSB_STATUS_CONNECTED_AS_BROADCAST_MASTER:
                        case BT_CSB_STATUS_CONNECTED_AS_BROADCAST_SLAVE:
                            BTMSPK_CancelGroup();
                            break;
                        case BT_CSB_STATUS_BROADCAST_MASTER_CONNECTING:
                            BTMSPK_CancelGroupCreation();
                            break;
                    }
                }
            }
            else if( event == KEY_EVENT_DOUBLE_CLICK )
            {
                if(BTAPP_GetStatus() == BT_STATUS_READY)
                {
                    BTMSPK_AddMoreSpeaker();
                }
            }
            break;
            
        case KEY_ID_VOL_DN:
            if(event == KEY_EVENT_PRIMARY)
            {
                if(BTAPP_GetStatus() == BT_STATUS_READY)
                    BTVOL_VolDown();//BTAPP_VolDown();
                else
                    sta369bw_vol_down();
            }
            else if( event == KEY_EVENT_DOUBLE_CLICK )
            {
                if(BTAPP_GetStatus() == BT_STATUS_READY)
                {
                    BTMSPK_StereoModeSwitchAudioChannel();
                }
            }
            else if( event == KEY_EVENT_SECONDARY )
            {
                if(BTAPP_GetStatus() == BT_STATUS_READY)
                {
                    switch( BTMSPK_GetMSPKStatus() )
                    {
                        case BT_CSB_STATUS_STANDBY:
                            BTMSPK_CreatStereoMode();
                            break;
                        case BT_CSB_STATUS_CONNECTING:
                            BTMSPK_CancelGroupCreation();
                            break;
                        case BT_CSB_STATUS_CONNECTED_AS_NSPK_MASTER:
                        case BT_CSB_STATUS_CONNECTED_AS_NSPK_SLAVE:
                            BTMSPK_CancelGroup();
                            break;
                        case BT_CSB_STATUS_NSPK_MASTER_CONNECTING:
                            BTMSPK_CancelGroupCreation();
                            break;
                        case BT_CSB_STATUS_CONNECTED_AS_BROADCAST_MASTER:
                        case BT_CSB_STATUS_CONNECTED_AS_BROADCAST_SLAVE:
                        case BT_CSB_STATUS_BROADCAST_MASTER_CONNECTING:
                            BTMSPK_CreatStereoMode(); //according to Andre request, enter NSPK mode from broadcast mode directly.
                            break;
                    }
                }
            }
            break;
            
    }
}

void KeyHandlers_Timer1MS_event()
{
}
