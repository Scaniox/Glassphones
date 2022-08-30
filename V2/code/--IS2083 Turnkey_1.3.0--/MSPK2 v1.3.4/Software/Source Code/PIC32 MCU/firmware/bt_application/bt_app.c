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
#include "bt_app.h"
#include "bt_data.h"
#include "bt_command_send.h"
#include "bt_command_decode.h"
#include "bt_volume.h"
#include "bt_multi_spk.h"
#include "bt_line_in.h"
#include "bt_a2dp.h"
#include "bt_hfp.h"
#include "timer.h"
#include "sta369bwdsp_handler.h"
#include "led.h"

//===============================================
//  VARIABLES CLAIM
//===============================================
BTAPP_TASK_STATE BTAPP_TaskState;
BTAPPRUNNING_TASK_STATE BTAppRunning_TaskState;
uint8_t BTAPP_TaskRequest;
BTAPP_STATUS BTAPP_Status;        // BM64 internal system status
BT_PORTS BTAPP_Ports;
uint16_t BTAPP_timer1ms;
uint8_t timeout_flag = 0;
//uint16_t DSP_UnmuteTimer1ms; 

#ifdef _BLE_ADV_CTRL_BY_MCU
#define BLE_DEVNAME_MAX_LEN    29
BLE_ADV_TYPE BLE_advType;
uint8_t BT_deviceName[BLE_DEVNAME_MAX_LEN + 1];
uint8_t BT_MasterAddr[6];
uint8_t BT_groupstatus;
uint8_t BT_groupLinkEvent;
uint8_t BT_btmState, BT_btmStateTemp;
uint8_t BT_bleAdvFeature = 1;
#endif

#ifdef _CODE_FOR_APP
#define DSP_EQ_SIZE    84
#define DSP_EQ_SEND_INTERVAL   100		   //  100ms
#define BTEQ_MAX_INDEX		   11		   // 84bytes + 1-seq each packet ==> 84/8 = 11 packets
uint16_t BTEQ_timer1ms;
 enum {
	 MULTI_SPK_EQ_ALL = 0,
	 MULTI_SPK_EQ_MASTER,
	 MULTI_SPK_EQ_SLAVE,
 } multiSpk_eq_route;
uint8_t BTEQ_SendIndex;
uint8_t BTEQ_RecIndex;
uint8_t dspEQ[DSP_EQ_SIZE+6];
#endif

 /*-----------------------------------------------------------------------------*/
/**/
/*-----------------------------------------------------------------------------*/
///////////////////////////////////////////////////////////////////////////////
 //=======================================================================
//  FUNCTION IMPLEMENTION
//========================================================================

//================================================
// Init
//================================================
void BTAPP_Init( void )
{
    Set_LED_Style(LED_2, LED_OFF, 500, 500);
    Set_LED_Style(LED_3, LED_OFF, 500, 500);
    
    BTAPP_TaskState = BT_STATE_INITIALIZE_START;
    
    BTAPP_Status.status = BT_SYSTEM_POWER_OFF;
    BTMSPK_Init();
    BTMA2DP_Init();
    BTMHFP_Init();
    BTM_LINE_IN_Init();
    
    BT_CommandDecodeInit();
    BT_CommandSendInit();
    BTVOL_Init();
    BTMDATA_Init();
    
    BTAPP_Ports.PORT_1.value = 0;
    BTAPP_Ports.PORT_2.value = 0;
    BTAPP_Ports.PORT_3.value = 0;
    BTAPP_Ports.PORT_4.value = 0;
#ifdef _CODE_FOR_APP    
	BTEQ_timer1ms = 0;
	BTEQ_SendIndex = BTEQ_MAX_INDEX+1;	// assum it finish the packet sending
	BTEQ_RecIndex = 0;		// expect to see first packet
#endif
}

//================================================
// Task
//================================================
void BTAPP_Task(void) {
    switch (BTAPP_TaskState) {
        case BT_STATE_INITIALIZE_START:
            BTAPP_timer1ms = 500;           //wait external circuit to get stable power
            BTAPP_TaskState = BT_STATE_INIT_MFB_HIGH;
            break;

        case BT_STATE_INIT_MFB_HIGH:
            if (!BTAPP_timer1ms) {
                BTAPP_timer1ms = 20;
                BM6X_MFB_SetHigh();
                BTAPP_TaskState = BT_STATE_INIT_RESET_HIGH;
            }
            break;

        case BT_STATE_INIT_RESET_HIGH:
            if (!BTAPP_timer1ms) {
                BM6X_RESET_SetHigh();
                BT_CommandDecodeInit();
                BTAPP_timer1ms = 500; //wait 500ms
                BTAPP_TaskState = BT_STATE_INIT_RESET_HIGH_WAIT;
            }
            break;

        case BT_STATE_INIT_RESET_HIGH_WAIT:
            if (!BTAPP_timer1ms) //check 500ms times up
            {
                BTAPP_TaskState = BT_STATE_INIT_COMMAND_START;
            }
            break;

        case BT_STATE_INIT_COMMAND_START:
            if(BTAPP_Status.status == BT_SYSTEM_POWER_OFF){
                if(BT_IsCommandSendTaskIdle()){
                    BT_SetRXBufferSize();
                    BT_ReadFWVersion();
                    BT_ReadUARTVersion();
                    BT_ReadDeviceAddressCommand();
                    BT_ReadFeatureListCommand();    //new added for MBA
                    BT_ReadDeviceNameCommand();
                    BTAPP_TaskState = BT_STATE_INIT_READ_DEVICE_NAME_WAIT;
                    BTAPP_timer1ms = 2000;      //set 2000ms time out
                }
            }
            break;

        case BT_STATE_INIT_READ_DEVICE_NAME_WAIT:
            if(!BTAPP_timer1ms)
            {
                BTAPP_timer1ms = 1000;
                BT_ReadDeviceNameCommand();        //retry
            }
            break;

        case BT_STATE_INIT_BLE_ADV_START:
#ifdef _BLE_ADV_CTRL_BY_MCU            
            BLE_UpdateAdvType(CONNECTABLE_UNDIRECT_ADV);
            BLE_forceUpdate();
#endif            
            BTAPP_TaskState = BT_STATE_INIT_BLE_ADV_WAIT;
		 	BTAPP_timer1ms = 1000;
         break;
         
		case BT_STATE_INIT_BLE_ADV_WAIT:
			if( !BTAPP_timer1ms )
			{
				BTAPP_TaskState = BT_STATE_POWER_OFF;
			}
		break;
        
        case BT_STATE_POWER_ON_START:
            if(is_sta369bwdsp_idle())
            {
                sta369bwdsp_start();
            }
            BTAPP_TaskState = BT_STATE_POWER_DSP_WAIT;
            break;
            
        case BT_STATE_POWER_DSP_WAIT:    
            if(!is_sta369bwdsp_ready())
                return;
            if ( BT_IsCommandSendTaskIdle() )
            {
                BT_MMI_ActionCommand(POWERON_BUTTON_PRESS, 0); //POWER ON button pressed command
                BT_MMI_ActionCommand(POWERON_BUTTON_RELEASE, 0); //POWER ON button released command
                BTAPP_TaskState = BT_STATE_POWER_ON;//BT_STATE_POWER_ON_BUTTON_PRESSED;
                break;
            }
            if (BTAPP_TaskRequest == BT_REQ_SYSTEM_OFF)
            {
                BTAPP_TaskState = BT_STATE_POWER_OFF;
                BTAPP_TaskRequest = BT_REQ_NONE; //clear request
            }
            break;

        case BT_STATE_POWER_ON:
#ifdef _BLE_ADV_CTRL_BY_MCU             
			BLE_UpdateAdvType(CONNECTABLE_UNDIRECT_ADV);
            //BLE_forceUpdate();
            BTVOL_InitVolMode();
            BT_ReadNSpkStatus();        //this command issues 0x33 event, and 0x33 event will issue BLE_forceUpdate()
#else
            BTVOL_InitVolMode();
#endif            
            //BTAPP_timer1ms = 100;
			BTAPP_TaskState = BT_STATE_READ_PAIR_RECORD;//BT_STATE_BLE_ADV_WAIT;		
            break;

        case BT_STATE_BLE_ADV_WAIT:
            //if( !BTAPP_timer1ms )
            //{
                BTAPP_TaskState = BT_STATE_READ_PAIR_RECORD;//BT_STATE_VOL_SYNC;
            //}
            break;

        //case BT_STATE_VOL_SYNC:
        //    if(BT_IsCommandSendTaskIdle()) {
        //        BTVOL_InitVolMode();
        //        BTAPP_TaskState = BT_STATE_READ_PAIR_RECORD;
        //    }
        //    break;

        case BT_STATE_READ_PAIR_RECORD:
            if(BT_IsCommandSendTaskIdle()){
                BT_GetPairRecordCommand();
                BTAPP_TaskState = BT_STATE_READ_PAIR_RECORD_WAIT;
                BTAPP_timer1ms = 1000; //set 1000 time out
            }
            break;

        case BT_STATE_READ_PAIR_RECORD_WAIT:
            if (!BTAPP_timer1ms) {              //time out
                BTAPP_Status.pairedRecordNumber = 0;
                BT_GetPairRecordCommand();
                BTAPP_timer1ms = 1000; //set time out
            }
            break;

        case BT_STATE_READ_LINKED_MODE:
            if(BT_IsCommandSendTaskIdle()) {
#ifdef _UNSUPPORT_3A_EVENT
                BTAPP_Status.lastMSPKSlaveCounter = 0;
                BTMSPK_BackToLastGroupMode();
                Set_LED_Style(LED_1, LED_BLINK, 500, 500); //1HZ for linkback process
                BTAPP_TaskState = BT_STATE_READ_LINKED_MODE_WAIT;
                BTAPP_timer1ms = 400;          //set 1 seconds for time out waiting
#else
                BTAPP_Status.lastMSPKSlaveCounter = 0;
                BT_ReadBTMLinkModeCommand();
                Set_LED_Style(LED_1, LED_BLINK, 500, 500); //1HZ for linkback process
                BTAPP_TaskState = BT_STATE_READ_LINKED_MODE_WAIT;
                BTAPP_timer1ms = 1000;          //set 1 seconds for time out waiting
#endif
            }
            break;

        case BT_STATE_READ_LINKED_MODE_WAIT:
            if(!BTAPP_timer1ms)         //time out
            {              
                if(BTAPP_Status.pairedRecordNumber != 0)
                {
                    BT_LinkBackToLastDevice();
                    BTAPP_TaskState = BT_STATE_BT_RUNNING;//BT_STATE_LINKBACK_TO_LAST_DEVICE;
                }
                else
                {
                    BT_MMI_ActionCommand(ANY_MODE_ENTERING_PAIRING, 0);
                    BTAPP_TaskState = BT_STATE_BT_RUNNING;
                }              
            }
            break;

        case BT_STATE_LINKBACK_START:
            if(BT_IsCommandSendTaskIdle())
            {
                switch(BTAPP_Status.lastLinkedMode)
                {
                    case 0:     //single mode
                    case 1:     //multi point
                        if(BTAPP_Status.pairedRecordNumber != 0)
                        {
                            BT_LinkBackToLastDevice();
                            //BTAPP_TaskState = BT_STATE_LINKBACK_TO_LAST_DEVICE;
                            BTAPP_TaskState = BT_STATE_BT_RUNNING;
                        }
                        else
                        {
                            BT_MMI_ActionCommand(ANY_MODE_ENTERING_PAIRING, 0);
                            //BT_LinkbackStatus = BT_PAIRING_START;
                            BTAPP_TaskState = BT_STATE_BT_RUNNING;
                        }
                        break;
                    case 2:     //NSPK master
                    case 3:     //NSPK slave
                    case 4:     //broadcast master
                    case 5:     //broadcast slave
                        BTMSPK_BackToLastGroupMode();
                        BTAPP_TaskState = BT_STATE_BT_RUNNING;
                        //BTAPP_Status.groupLinkingBack = true;
                        break;
                        /*
                    case 2:     //NSPK master
                        BTMSPK_TriggerStereoModeMaster();
                        BTAPP_TaskState = BT_STATE_BT_RUNNING;
                        break;
                    case 3:     //NSPK slave
                        BTMSPK_TriggerStereoModeSlave();
                        BTAPP_TaskState = BT_STATE_BT_RUNNING;
                        break;
                    case 4:     //broadcast master
                        BTMSPK_TriggerConcertModeMaster();
                        BTAPP_TaskState = BT_STATE_BT_RUNNING;
                        break;
                    case 5:     //broadcast slave
                        BTMSPK_TriggerConcertModeSlave();
                        BTAPP_TaskState = BT_STATE_BT_RUNNING;
                        break;*/
                }
            }
            break;
        case BT_STATE_BT_RUNNING:
            if(BTAPP_TaskRequest == BT_REQ_SYSTEM_OFF)
                BTAPP_TaskState =  BT_STATE_POWER_OFF_START;
            BTAPP_TaskRequest = BT_REQ_NONE;

            if (BTAPP_TaskState == BT_STATE_BT_RUNNING)
            {
                if (BTAppRunning_TaskState == BT_RUNNING_STATE_IDLE)
                {
                }
                else if (BTAppRunning_TaskState == BT_RUNNING_STATE_MUTE)
                {
                    if (!BTAPP_timer1ms)
                    {
                        BTVOL_ChangeVolMode(BTVOL_GetVolMode(), false);
                        BTAppRunning_TaskState = BT_RUNNING_STATE_IDLE;
                    }
                }
                
            }
            break;

        case BT_STATE_POWER_OFF_START:
            BTAPP_TaskRequest = BT_REQ_NONE; //clear request
            if(BT_IsCommandSendTaskIdle()){
                if( (BTMSPK_GetMSPKStatus() == BT_CSB_STATUS_CONNECTED_AS_NSPK_MASTER)              //NSPK master
                        || (BTMSPK_GetMSPKStatus() == BT_CSB_STATUS_CONNECTED_AS_NSPK_SLAVE)        //NSPK slave
                        || (BTMSPK_GetMSPKStatus() == BT_CSB_STATUS_CONNECTED_AS_BROADCAST_MASTER)  //Broadcast master
                        || (BTMSPK_GetMSPKStatus() == BT_CSB_STATUS_BROADCAST_MASTER_CONNECTING )   //Broadcast master
                        || (BTMSPK_GetMSPKStatus() == BT_CSB_STATUS_CONNECTED_AS_BROADCAST_SLAVE) )    
                {
                    BT_MMI_ActionCommand(POWER_OFF_ALL_SPK, 0 );
                    BTAPP_TaskState = BT_STATE_POWER_OFF_WAIT_NSPK_EVENT;
                    BTAPP_timer1ms = 500;
                    timeout_flag = 0; //Clear Timeout flag
                }
                else
                {
                    BT_MMI_ActionCommand(POWEROFF_BUTTON_PRESS, 0 );
                    BT_MMI_ActionCommand(POWEROFF_BUTTON_RELEASE, 0 );
                    BTAPP_TaskState = BT_STATE_POWER_OFF_WAIT;
                }
            }
            break;
        
        case BT_STATE_POWER_OFF_WAIT_NSPK_EVENT:
            if (!BTAPP_timer1ms) {
                BT_MMI_ActionCommand(POWER_OFF_ALL_SPK, 0 );
                BTAPP_timer1ms = 500;
                if(timeout_flag++ >= 60)
                { 
                    BTAPP_TaskState = BT_STATE_POWER_OFF_START_NSPK;  //Concert/Stereo master failed to respond; go for power off
                }
            }
            break;
            
        case BT_STATE_POWER_OFF_START_NSPK:
            if(BT_IsCommandSendTaskIdle()){
                BT_MMI_ActionCommand(POWEROFF_BUTTON_PRESS, 0 );
                BT_MMI_ActionCommand(POWEROFF_BUTTON_RELEASE, 0 );
                BTAPP_TaskState = BT_STATE_POWER_OFF_WAIT;
            }
            break;

        case BT_STATE_POWER_OFF_WAIT:
            if( BTAPP_Status.status == BT_SYSTEM_POWER_OFF )
            {
                BTM_LINE_IN_Init();
                BTVOL_Init();
                BTAPP_TaskState = BT_STATE_POWER_OFF;
            }
            break;

        case BT_STATE_POWER_OFF:
            if (BTAPP_TaskRequest != BT_REQ_NONE) {
                if (BTAPP_TaskRequest == BT_REQ_SYSTEM_ON) {
                    BTAPP_TaskState = BT_STATE_POWER_ON_START;
                    BTAPP_TaskRequest = BT_REQ_NONE; //clear request
                }
            }
            break;

        default:
            break;

    }

    if (BTAPP_TaskState >= BT_STATE_INIT_COMMAND_START) {
        BT_CommandDecodeMain();
        BT_CommandSendTask();
#ifdef _CODE_FOR_APP        
		BT_SendEQBytes();       //sequencialy send EQ bytes received from APP to slave
#endif
    }
}

//================================================
//BT status checking
//================================================
uint8_t BTAPP_GetStatus(void)
{
    if(BTAPP_TaskState == BT_STATE_POWER_OFF)
        return BT_STATUS_OFF;
    else if(BTAPP_TaskState >= BT_STATE_POWER_ON && BTAPP_TaskState < BT_STATE_BT_RUNNING)
        return BT_STATUS_ON;
    else if(BTAPP_TaskState == BT_STATE_BT_RUNNING)
        return BT_STATUS_READY;
    else
        return BT_STATUS_NONE;
}

//================================================
// BT Event Handler
//================================================
void BTAPP_EventHandler(BT_APP_EVENTS event, uint8_t* paras, uint16_t size )
{
	uint8_t i=0;
    uint8_t nspk_link_status, nspk_link_event;
#ifdef _SUPPORT_SIMPLE_33_EVENT
    uint8_t send_master_address[7];
#endif    
    switch(event)
    {
        case BT_EVENT_CMD_SENT_ACK_OK:
            break;
            
        case BT_EVENT_CMD_SENT_ACK_ERROR:
            BT_GiveUpThisCommand();
            break;
            
        case BT_EVENT_CMD_SENT_NO_ACK:
            if(*paras == 0x04 || *paras == 0x02)        //MMI_ACTION or MUSIC_CTRL
                BT_GiveUpThisCommand();
            break;
            
        case BT_EVENT_NSPK_VENDOR_CMD:
#ifdef _CODE_FOR_APP    
		if( (paras[0x03] & 0xf0) == 0x80 )      //Vendor EQ handle
		{
			// Vendor EQ commands
			paras[0x03] -= 0x80;
			if(paras[0x03] == 0x00)
			{
				for(i=0; i<DSP_EQ_SIZE; i++)
					dspEQ[i] = 0;
	
				dspEQ[0] = 0xAA;	 //header byte 0
				dspEQ[1] = 0x00;	 //header byte 1
				dspEQ[2] = 84+2;	 //length
				dspEQ[3] = 0x30;		//command ID
				dspEQ[4] = 0x13;	   //link_index, set to 0
	
				BTEQ_RecIndex = 0;
			}
			else if(paras[0x03] >= BTEQ_MAX_INDEX)
			{
				// Seq out range, do nothing.
				//break;
			}
			
			if(paras[0x03] == BTEQ_RecIndex)
			{
				if(paras[2] == 9)
				{
					for(i=0; i<8;i++)
						dspEQ[5 + (BTEQ_RecIndex * (VENDOR_CMD_SIZE-1)) + i] = paras[4 +i]; 
				}
				else 
				{
					for(i=0; i<4;i++)
						dspEQ[5 + (BTEQ_RecIndex * (VENDOR_CMD_SIZE-1)) + i] = paras[4 +i]; 
				}	
				BTEQ_RecIndex++;
				if(BTEQ_RecIndex == BTEQ_MAX_INDEX)
				{
					BTEQ_RecIndex = 0;
					// the EQ data completed
					BT_SendBytesAsEQCommandWithRedoChecksum(dspEQ, 90);				
				}			
			}
			else
			{
				// Get the wrong seq-packet.
				// Ignore all the packet until see the first packet.
				
			}
			return;
		}
		else        //other Vendor events handle
		{
            switch( paras[0x03] )
            {
                //case 1:
                case 0xFE:      //vol sync to slave
                    //BTVOL_EventHandler(BT_EVENT_AVRCP_ABS_VOLUME_CHANGED, &paras[3], 2 );
                    BTVOL_GotSyncVolFromMasterByVendorCmd(paras[4], paras[5]);
                    break;
                case 0xFD:
#ifdef _SUPPORT_SIMPLE_33_EVENT
    #ifdef _BLE_ADV_CTRL_BY_MCU                            
			BLE_SaveMasterAddr( &paras[4] );
            BLE_advUpdateGroupStatus(SPEAKER_nSPK_SLAVE);
            BLE_UpdateAdvType(SCANNABLE_UNDIRECT_ADV); //non-connectable
            BTMSPK_GetNSPKLinksStatusAndEvent( &nspk_link_status, &nspk_link_event );
            BLE_advUpdateLinkStatus(nspk_link_event);
            BLE_forceUpdate();
    #endif 
#endif
                    break;
                case 0xFC:
                    if( BTAPP_Status.BDAddr[0] == paras[4] 
                            && BTAPP_Status.BDAddr[1] == paras[5]
                            && BTAPP_Status.BDAddr[2] == paras[6]
                            && BTAPP_Status.BDAddr[3] == paras[7] )
                    {
                        BT_MMI_ActionCommand(paras[10], 0);
                    }
                    break;
                default:
                    break;
            }
		} 
#endif            
            break;
            
        case BT_EVENT_MSPK_STANDBY:
            Set_LED_Style(LED_2, LED_OFF, 500, 500);
            Set_LED_Style(LED_3, LED_OFF, 500, 500);
            //if( BTAPP_Status.status == BT_SYSTEM_STANDBY && BTAPP_Status.groupLinkingBack == true)
            //{
            //    BTAPP_Status.groupLinkingBack = false;
            //    BT_LinkBackToLastDevice();
            //}
#ifdef _BLE_ADV_CTRL_BY_MCU                    
			BLE_UpdateAdvType(CONNECTABLE_UNDIRECT_ADV);
			BLE_advUpdateGroupStatus(SPEAKER_SINGLE);	
            BTMSPK_GetNSPKLinksStatusAndEvent( &nspk_link_status, &nspk_link_event );
            BLE_advUpdateLinkStatus(nspk_link_event);
            BLE_forceUpdate();
#endif              
            break;
        case BT_EVENT_MSPK_CONNECTING:
            Set_LED_Style(LED_2, LED_BLINK, 500, 500);
            Set_LED_Style(LED_3, LED_BLINK, 500, 500);
#ifdef _UNSUPPORT_3A_EVENT   
            if( BTAPP_TaskState == BT_STATE_READ_LINKED_MODE )
            {
                BTAPP_TaskState = BT_STATE_BT_RUNNING;
            }
#endif
#ifdef _BLE_ADV_CTRL_BY_MCU
			//BLE_advUpdateGroupStatus(SPEAKER_CONNECTING);       //EA app
            BLE_advUpdateGroupStatus(SPEAKER_SINGLE);               //v1.16 app
			BLE_UpdateAdvType(CONNECTABLE_UNDIRECT_ADV);
            BTMSPK_GetNSPKLinksStatusAndEvent( &nspk_link_status, &nspk_link_event );
            BLE_advUpdateLinkStatus(nspk_link_event);
            BLE_forceUpdate();
#endif            
            break;
        case BT_EVENT_MSPK_CONNECTED_AS_NSPK_MASTER:
            //Set_LED_Style(LED_2, LED_ON, 500, 500);   //BT_EVENT_MSPK_SYNC_AUDIO_CHANNEL will set LED2&3 in NSPK mode
            //Set_LED_Style(LED_3, LED_ON, 500, 500);
#ifdef _BLE_ADV_CTRL_BY_MCU
            BLE_advUpdateGroupStatus(SPEAKER_nSPK_MASTER);
			BLE_UpdateAdvType(CONNECTABLE_UNDIRECT_ADV);
            BTMSPK_GetNSPKLinksStatusAndEvent( &nspk_link_status, &nspk_link_event );
            BLE_advUpdateLinkStatus(nspk_link_event);
            BLE_forceUpdate();
#endif
#ifdef _SUPPORT_SIMPLE_33_EVENT
            //send master address to slave, only for stereo mode, not needed for concert mode
            send_master_address[0] = 0xFD;
            send_master_address[1] = BTAPP_Status.BDAddr[0];
            send_master_address[2] = BTAPP_Status.BDAddr[1];
            send_master_address[3] = BTAPP_Status.BDAddr[2];
            send_master_address[4] = BTAPP_Status.BDAddr[3];
            send_master_address[5] = BTAPP_Status.BDAddr[4];
            send_master_address[6] = BTAPP_Status.BDAddr[5];
            BT_Vendor_SendCommand(send_master_address, 7);
#endif
            break;
        case BT_EVENT_MSPK_CONNECTED_AS_NSPK_SLAVE:
            //Set_LED_Style(LED_2, LED_ON, 500, 500);   //BT_EVENT_MSPK_SYNC_AUDIO_CHANNEL will set LED2&3 in NSPK mode
            //Set_LED_Style(LED_3, LED_ON, 500, 500);
            Set_LED_Style(LED_1, LED_OFF, 500, 500);            //turn off BT LED when slave role is confirmed
#ifndef _SUPPORT_SIMPLE_33_EVENT        //undefine this macro for MSPK, define it for 104 ROM
#ifdef _BLE_ADV_CTRL_BY_MCU                            
			BLE_SaveMasterAddr( BTMSPK_GetMasterBDAddress() );
            BLE_advUpdateGroupStatus(SPEAKER_nSPK_SLAVE);
            BLE_UpdateAdvType(CONNECTABLE_UNDIRECT_ADV); //connectable
            BTMSPK_GetNSPKLinksStatusAndEvent( &nspk_link_status, &nspk_link_event );
            BLE_advUpdateLinkStatus(nspk_link_event);
            BLE_forceUpdate();
#endif
#endif
            break;
        case BT_EVENT_MSPK_CONNECTED_AS_BROADCAST_MASTER:
            Set_LED_Style(LED_2, LED_ON, 500, 500);
            Set_LED_Style(LED_3, LED_ON, 500, 500);
#ifdef _BLE_ADV_CTRL_BY_MCU
            BLE_advUpdateGroupStatus(SPEAKER_BROADCAST_MASTER_ADDING);
			BLE_UpdateAdvType(CONNECTABLE_UNDIRECT_ADV);
            BTMSPK_GetNSPKLinksStatusAndEvent( &nspk_link_status, &nspk_link_event );
            BLE_advUpdateLinkStatus(nspk_link_event);
            BLE_forceUpdate();
#endif            
            break;
        case BT_EVENT_MSPK_CONNECTED_AS_BROADCAST_SLAVE:
            Set_LED_Style(LED_2, LED_ON, 500, 500);
            Set_LED_Style(LED_3, LED_ON, 500, 500);
            Set_LED_Style(LED_1, LED_OFF, 500, 500);            //turn off BT LED when slave role is confirmed
#ifdef _BLE_ADV_CTRL_BY_MCU
			BLE_SaveMasterAddr( BTMSPK_GetMasterBDAddress() );
            BLE_advUpdateGroupStatus(SPEAKER_BROADCAST_SLAVE);
            BLE_UpdateAdvType(CONNECTABLE_UNDIRECT_ADV); //connectable
            BTMSPK_GetNSPKLinksStatusAndEvent( &nspk_link_status, &nspk_link_event );
            BLE_advUpdateLinkStatus(nspk_link_event);
            BLE_forceUpdate();
#endif              
            break;
        case BT_EVENT_MSPK_BROADCAST_MASTER_CONNECTING_MORE:
            Set_LED_Style(LED_3, LED_BLINK, 500, 500);
#ifdef _BLE_ADV_CTRL_BY_MCU         //v1.16 app
            BLE_advUpdateGroupStatus(SPEAKER_BROADCAST_MASTER_ADDING);
			BLE_UpdateAdvType(CONNECTABLE_UNDIRECT_ADV);
            BTMSPK_GetNSPKLinksStatusAndEvent( &nspk_link_status, &nspk_link_event );
            BLE_advUpdateLinkStatus(nspk_link_event);
            BLE_forceUpdate();
#endif             
            break;
        case BT_EVENT_MSPK_BROADCAST_MASTER_CONNECTING_END:
            Set_LED_Style(LED_2, LED_ON, 500, 500);
            Set_LED_Style(LED_3, LED_ON, 500, 500);
            //if( BTAPP_Status.status == BT_SYSTEM_STANDBY && BTAPP_Status.groupLinkingBack == true)
            //{
            //    BTAPP_Status.groupLinkingBack = false;
            //    BT_LinkBackToLastDevice();
            //}
#ifdef _BLE_ADV_CTRL_BY_MCU         //v1.16 app
            BLE_advUpdateGroupStatus(SPEAKER_BROADCAST_MASTER_ADDING);
			BLE_UpdateAdvType(CONNECTABLE_UNDIRECT_ADV);
            BTMSPK_GetNSPKLinksStatusAndEvent( &nspk_link_status, &nspk_link_event );
            BLE_advUpdateLinkStatus(nspk_link_event);
            BLE_forceUpdate();
#endif             
            break;
        case BT_EVENT_MSPK_BROADCAST_SLAVE_POWER_OFF:
            BTAPP_TaskState =  BT_STATE_POWER_OFF_START;
            break;
        case BT_EVENT_MSPK_SYNC_AUDIO_CHANNEL:
            if(*paras == 0x01)      //L+L
            {
                Set_LED_Style(LED_2, LED_ON, 500, 500);
                Set_LED_Style(LED_3, LED_OFF, 500, 500);
            }
            else if(*paras == 0x02)     //R+R
            {
                Set_LED_Style(LED_2, LED_OFF, 500, 500);
                Set_LED_Style(LED_3, LED_ON, 500, 500);
            }
            else
            {
                Set_LED_Style(LED_2, LED_ON, 500, 500);
                Set_LED_Style(LED_3, LED_ON, 500, 500);
            }
            break;

        case BT_EVENT_HFP_LINK_CONNECTED:
            BTAPP_Status.status = BT_SYSTEM_CONNECTED;
#ifdef _BLE_ADV_CTRL_BY_MCU         //v1.16 app            
            if(BLE_advUpdateBTMState(BLE_BTM_CONN_HF,true))
                BLE_forceUpdate();
#endif
            break;
        case BT_EVENT_HFP_LINK_DISCONNECTED:
#ifdef _BLE_ADV_CTRL_BY_MCU         //v1.16 app            
            if(BLE_advUpdateBTMState(BLE_BTM_CONN_HF,false))
                BLE_forceUpdate();
#endif            
            break;
        case BT_EVENT_SPP_LINK_CONNECTED:
#ifdef _BLE_ADV_CTRL_BY_MCU         //v1.16 app            
            if(BLE_advUpdateBTMState(BLE_BTM_CONN_SPP_IAP,true))
                BLE_forceUpdate();
#endif            
            break;
        case BT_EVENT_IAP_LINK_CONNETED:
#ifdef _BLE_ADV_CTRL_BY_MCU         //v1.16 app            
            if(BLE_advUpdateBTMState(BLE_BTM_CONN_SPP_IAP,true))
                BLE_forceUpdate();
#endif            
            break;
        case BT_EVENT_SPP_IAP_LINK_DISCONNECTED:
#ifdef _BLE_ADV_CTRL_BY_MCU         //v1.16 app            
            if(BLE_advUpdateBTMState(BLE_BTM_CONN_SPP_IAP,false))
                BLE_forceUpdate();
#endif            
            break;
        case BT_EVENT_A2DP_LINK_CONNECTED:
        case BT_EVENT_A2DP_LINK_CHANGED:
            BTAPP_Status.status = BT_SYSTEM_CONNECTED;
            Set_LED_Style(LED_1, LED_ON, 500, 500);
#ifdef _BLE_ADV_CTRL_BY_MCU         //v1.16 app            
            if(BLE_advUpdateBTMState(BLE_BTM_CONN_A2DP,true))
                BLE_forceUpdate();
#endif             
            break;
        case BT_EVENT_A2DP_LINK_DISCONNECTED:
#ifdef _BLE_ADV_CTRL_BY_MCU         //v1.16 app            
            if(BLE_advUpdateBTMState(BLE_BTM_CONN_A2DP,false))
                BLE_forceUpdate();
#endif            
            break;
            
        case BT_EVENT_SYS_POWER_ON:
            BTAPP_Status.status = BT_SYSTEM_POWER_ON;
            Set_LED_Style(LED_0, LED_ON, 500, 500);
#ifdef _BLE_ADV_CTRL_BY_MCU         //v1.16 app            
            if(BLE_advUpdateBTMState(BLE_BTM_STBY,true))
                BLE_forceUpdate();
#endif            
            break;
        case BT_EVENT_SYS_POWER_OFF:
            BTAPP_Status.status = BT_SYSTEM_POWER_OFF;
            Set_LED_Style(LED_1, LED_OFF, 500, 500);
            Set_LED_Style(LED_0, LED_OFF, 500, 500);
            Set_LED_Style(LED_2, LED_OFF, 500, 500);    //MSPK link lost indicator
            Set_LED_Style(LED_3, LED_OFF, 500, 500);    //MSPK link lost indicator
#ifdef _BLE_ADV_CTRL_BY_MCU         //v1.16 app            
            if(BLE_advUpdateBTMState(BLE_BTM_OFF,true))
                BLE_forceUpdate();
#endif            
            break;
        case BT_EVENT_SYS_STANDBY:
            BTAPP_Status.status = BT_SYSTEM_STANDBY;
            Set_LED_Style(LED_1, LED_OFF, 500, 500);
#ifdef _BLE_ADV_CTRL_BY_MCU         //v1.16 app            
            if(BLE_advUpdateBTMState(BLE_BTM_STBY,true))
                BLE_forceUpdate();
#endif            
            break;

        case BT_EVENT_SYS_PAIRING_START:
            BTAPP_Status.status = BT_SYSTEM_PAIRING;
            Set_LED_Style(LED_1, LED_BLINK, 100, 100);
#ifdef _BLE_ADV_CTRL_BY_MCU         //v1.16 app            
            if(BLE_advUpdateBTMState(BLE_BTM_PAIR,true))
                BLE_forceUpdate();
#endif            
            break;
        case BT_EVENT_SYS_PAIRING_OK:
            break;
        case BT_EVENT_SYS_PAIRING_FAILED:
            Set_LED_Style(LED_1, LED_OFF, 500, 500);
#ifdef _BLE_ADV_CTRL_BY_MCU         //v1.16 app            
            if(BLE_advUpdateBTMState(BLE_BTM_STBY,true))
                BLE_forceUpdate();
#endif             
            break;

        case BT_EVENT_LINKBACK_SUCCESS:
            break;

        case BT_EVENT_LINKBACK_FAILED:
            Set_LED_Style(LED_1, LED_OFF, 500, 500);
            break;

       case BT_EVENT_BD_ADDR_RECEIVED:
           BTAPP_Status.BDAddr[0] = *paras++;
           BTAPP_Status.BDAddr[1] = *paras++;
           BTAPP_Status.BDAddr[2] = *paras++;
           BTAPP_Status.BDAddr[3] = *paras++;
           BTAPP_Status.BDAddr[4] = *paras++;
           BTAPP_Status.BDAddr[5] = *paras;
            break; 
            
	   case BT_EVENT_NAME_RECEIVED:
#ifdef _BLE_ADV_CTRL_BY_MCU           
           BLE_SaveDeviceName(paras);
#endif           
			if(BTAPP_TaskState == BT_STATE_INIT_READ_DEVICE_NAME_WAIT)
			{
				BTAPP_timer1ms = 0;
				BTAPP_TaskState = BT_STATE_INIT_BLE_ADV_START;
			}
			break;

        case BT_EVENT_PAIR_RECORD_RECEIVED:
            BTAPP_Status.pairedRecordNumber = *paras;
            if(BTAPP_TaskState == BT_STATE_READ_PAIR_RECORD_WAIT)
            {
                BTAPP_TaskState = BT_STATE_READ_LINKED_MODE;
            }
            break;

        case BT_EVENT_LINK_MODE_RECEIVED:
            BTAPP_Status.lastLinkedMode = *paras++;
            if(BTAPP_Status.lastLinkedMode == 2 || BTAPP_Status.lastLinkedMode == 4)        //NSPK master, Broadcast master
            {
                BTAPP_Status.lastMSPKSlaveCounter = *paras;
            }
            if(BTAPP_TaskState == BT_STATE_READ_LINKED_MODE_WAIT)
            {
                BTAPP_timer1ms = 0; //clear time out timer
                BTAPP_TaskState = BT_STATE_LINKBACK_START;
            }
            break;

        case BT_EVENT_A2DP_BREAK_IN:
            BTAPP_timer1ms = 500;
            BTAppRunning_TaskState = BT_RUNNING_STATE_MUTE;
            break;

        case BT_EVENT_MSPK__SYNC_POWER_OFF:
            BTAPP_TaskState = BT_STATE_POWER_OFF_START_NSPK;
            break;

        case BT_EVENT_PORT_INPUT_CHANGED:
            break;
            
        case BT_EVENT_BTM_VERSION:
            if(paras[0] == 0x01)        //1: FW version
            {
                BTAPP_Status.FWVer[0] = paras[1];
                BTAPP_Status.FWVer[1] = paras[2];
            }
            else                        //0: UART version
            {
                BTAPP_Status.UARTVer[0] = paras[1];
                BTAPP_Status.UARTVer[1] = paras[2];
            }
            break;
        
        case BT_EVENT_BATTERY_LEVEL:
            BTAPP_Status.batteryStatus = paras[0];      //save battery status
            BTAPP_Status.batteryLevel = paras[1];       //save battery level
            break;
        
        case BT_EVENT_FEATURE_LIST_RECEIVED:
#ifdef _BLE_ADV_CTRL_BY_MCU
            BLE_SaveFeatureList(paras[0]);
#endif
            break;
        
        case BT_EVENT_BTM_INITIALIZED:
            if(BTAPP_TaskState > BT_STATE_INIT_READ_DEVICE_NAME_WAIT)
                BTAPP_Init();
            break;
        
        case BT_EVENT_REPORT_TYPE_CODEC:
            if(paras[1] == BT_A2DP)
            {
                if(BTVOL_GetVolMode() == A2DP_VOL_MODE)
                    BTVOL_ChangeVolMode(A2DP_VOL_MODE, false);
                else
                {
                    sta369bw_SetVol(1);
                    BTVOL_SetVolMode(A2DP_VOL_MODE);
                    BTAPP_EventHandler( BT_EVENT_A2DP_BREAK_IN, 0, 0);
                }
            }
            else if(paras[1] == BT_HFP)
            {
                BTVOL_ChangeVolMode(HFP_VOL_MODE, false);
            }
            else if(paras[1] == BT_LINE_IN)
            {
                if(BTVOL_GetVolMode() == LINE_IN_VOL_MODE)
                    BTVOL_ChangeVolMode(LINE_IN_VOL_MODE, false);
                else
                {
                    sta369bw_SetVol(1);
                    BTVOL_SetVolMode(LINE_IN_VOL_MODE);
                    BTAPP_EventHandler( BT_EVENT_A2DP_BREAK_IN, 0, 0);
                }
            }
            break;
            
        default:
            break;
    }
}

//================================================
// BT Task Request
//================================================
void BTAPP_TaskReq(uint8_t request)
{
    BTAPP_TaskRequest = request;
}

//================================================
//1ms Timer
//================================================
void BTAPP_Timer1MS_event( void )
{
    if(BTAPP_timer1ms)
        --BTAPP_timer1ms;
	//if(DSP_UnmuteTimer1ms)
    //{
    //    --DSP_UnmuteTimer1ms;
    //    if(!DSP_UnmuteTimer1ms)
    //    {
    //        DSP_MUTE_SetHigh(); 
    //    }
    //}
#ifdef _CODE_FOR_APP    
    if(BTEQ_timer1ms)
		--BTEQ_timer1ms;
#endif    
}

/*-----------------------------------------------------------------------------*/
//EXTERNAL API interface(for UI)
/*-----------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------*/
void BTAPP_EnterBTPairingMode( void )
{
    if(BTAPP_TaskState == BT_STATE_BT_RUNNING)
    {
        if(BTAPP_Status.status != BT_SYSTEM_PAIRING)
        {
            Set_LED_Style(LED_1, LED_BLINK, 500, 500);      //1HZ before pairing starting
            BT_MMI_ActionCommand(ANY_MODE_ENTERING_PAIRING, 0);
        }
    }
}

/*-----------------------------------------------------------------------------*/
void BTAPP_ResetEEPROMtoDefault( void )
{
    BT_MMI_ActionCommand ( RESET_EEPROM_SETTING, 0);
}


/*-----------------------------------------------------------------------------*/
uint8_t* BT_GetLocalBDAddress( void )
{
    return &BTAPP_Status.BDAddr[0];
}

/*-----------------------------------------------------------------------------*/
uint8_t* Get_BTM_FWVersion( void )      //returned data is 2 bytes, refer to command set
{
    return &BTAPP_Status.FWVer[0];
}

/*-----------------------------------------------------------------------------*/
uint8_t* Get_BTM_UARTVersion( void )    //returned data is 2 bytes, refer to command set
{
    return &BTAPP_Status.UARTVer[0];
}

/*-----------------------------------------------------------------------------*/
void BTAPP_SoundVersion( void )
{
    uint8_t ver[9];
    //MCU version
    ver[0] = MCU_MAJOR_VERSION;
    ver[1] = MCU_MINOR_VERSION;
    ver[2] = MCU_SUB_VERSION;
    //BTM version
    ver[3] = BTAPP_Status.FWVer[0];
    ver[4] = BTAPP_Status.FWVer[1]>>4;
    ver[5] = BTAPP_Status.FWVer[1]&0x0f;
    BT_SoundVersion(ver, 6);
}

/*-----------------------------------------------------------------------------*/
#ifdef _CODE_FOR_APP
void BT_SendEQBytes(void)
{
	if(BTEQ_SendIndex == (BTEQ_MAX_INDEX+1) ||  BTEQ_timer1ms !=0)
	{
		return;
	}
	else if(BTEQ_SendIndex == BTEQ_MAX_INDEX)
	{
		BT_SendBytesAsEQCommandWithRedoChecksum(dspEQ, 90);
		BTEQ_SendIndex++;
	}
	else
	{
		BT_Vendor_EQCmd(dspEQ+5, BTEQ_SendIndex,(BTEQ_SendIndex == (BTEQ_MAX_INDEX - 1)) ? (DSP_EQ_SIZE % (VENDOR_CMD_SIZE-1))+1 : VENDOR_CMD_SIZE);
		BTEQ_SendIndex++;
		if(BTEQ_SendIndex == BTEQ_MAX_INDEX)
		{
			if(multiSpk_eq_route == MULTI_SPK_EQ_SLAVE)
				BTEQ_SendIndex = BTEQ_MAX_INDEX+1;
			else
				BTEQ_timer1ms = DSP_EQ_SEND_INTERVAL;
		}
		else
			BTEQ_timer1ms = DSP_EQ_SEND_INTERVAL;
		
	}
}

void BT_SetMultiSpkEQRoute(uint8_t route)
{
	multiSpk_eq_route = route;
}

bool BT_SendMultiSpkEQBytes(uint8_t* data, uint8_t size)
{
    uint8_t i;
    //uint16_t cmd_len;
	uint8_t *ptr = dspEQ;
	
    if((BTMSPK_GetMSPKStatus() == BT_CSB_STATUS_STANDBY ||
    	BTMSPK_GetMSPKStatus() == BT_CSB_STATUS_CONNECTING ||
    	BTMSPK_GetMSPKStatus() == BT_CSB_STATUS_CONNECTED_AS_NSPK_SLAVE ||
    	BTMSPK_GetMSPKStatus() == BT_CSB_STATUS_CONNECTED_AS_BROADCAST_SLAVE) ||
	   (multiSpk_eq_route == MULTI_SPK_EQ_MASTER))
        return false;

	*(ptr++) = 0xaa;
	*(ptr++) = 0x00;
	*(ptr++) = 84+2;
	*(ptr++) = 0x30;
	*(ptr++) = 0x13;

    for(i=0; i<size; i++)
    {
        *(ptr++) = *(data++);
    }
	BTEQ_SendIndex = 0;
	BTEQ_timer1ms = DSP_EQ_SEND_INTERVAL;  //send later to avoid master eq corrupt
    return true;
}
#endif

#ifdef _BLE_ADV_CTRL_BY_MCU
/*------------------------------------------------------------*/
void BLE_SaveMasterAddr(uint8_t * address)
{
	uint8_t i;
	for(i=0;i<6;i++)
        BT_MasterAddr[i] = address[i];
	//	BT_MasterAddr[i] = address[5-i];
	//BT_MasterAddr[0] = 255 - BT_MasterAddr[0];		
}

/*------------------------------------------------------------*/
void BLE_SaveFeatureList( uint8_t feature )
{
    BT_bleAdvFeature = feature;
}

/*------------------------------------------------------------*/
void BLE_SaveDeviceName(uint8_t* address)
{
    uint8_t i;
	uint8_t len = 0;
	if(*address >= BLE_DEVNAME_MAX_LEN){
        len = BLE_DEVNAME_MAX_LEN;
        *address = BLE_DEVNAME_MAX_LEN;
    }
    else{
        len = (uint8_t)*address;
    }
	
    for(i=0; i<=len; i++){
        BT_deviceName[i] = *address++;
    }
}

/*------------------------------------------------------------*/
void BLE_advUpdateGroupStatus(BLE_CSB_CONNECTION_STATE group_status)
{
    if(BT_groupstatus != group_status)
    {
		BT_groupstatus = group_status;
    }
}

/*------------------------------------------------------------*/
void BLE_advUpdateLinkStatus(BLE_CSB_STATE group_event)
{
	if(group_event >LINK_CONNECTED && group_event <LINK_MORE_SLAVES)
		return;
	
    if(BT_groupLinkEvent != group_event)
    {
		BT_groupLinkEvent = group_event;
    }
}

/*------------------------------------------------------------*/
bool BLE_advUpdateBTMState(BLE_BTM_STATE btm_state, bool state)
{
    uint8_t temp;
       if(btm_state >= BLE_BTM_CONN_HF)
        {
           if(state)
             BT_btmStateTemp = (BT_btmStateTemp & 0xF8) | (1 << btm_state);
           else
             BT_btmStateTemp = (BT_btmStateTemp & 0xF8) & ~(1 << btm_state);
           
            temp = BT_btmStateTemp >> 3;
            if(temp == 0x1) 
                BT_btmState = BLE_BTM_CONN_HF;
            else if (temp == 0x2)
                BT_btmState = BLE_BTM_CONN_A2DP;
            else if (temp == 0x4)
                BT_btmState = BLE_BTM_CONN_SPP_IAP;
            else if (temp != 0)
                BT_btmState = BLE_BTM_CONN_ALL;
            else
                BT_btmState = BT_btmStateTemp;
        }
        else
        {
            BT_btmState = BT_btmStateTemp = btm_state;
        }
        return true; 
}

/*------------------------------------------------------------*/
void BLE_UpdateAdvType(BLE_ADV_TYPE type)
{
    BLE_advType = type;
    if(type == CONNECTABLE_UNDIRECT_ADV)    //debugging code
        LED4_ON();          //debugging code
    else                    //debugging code
        LED4_OFF();          //debugging code
}

/*------------------------------------------------------------*/
void BLE_SetAdvData(void)
{
    uint8_t advertisingData[31];
	uint8_t* ptr = advertisingData;
    
	// AD type : Flag
	*ptr++ = 0x02;
	*ptr++ = 0x01;
	*ptr++ = 0x1A;

	// AD type : Service Data
	*ptr++ = 20;//15;       //20 for category 1
	*ptr++ = 0x16;
	*ptr++ = 0xDA;
	*ptr++ = 0xFE;
	*ptr++ = (1 << 4) | (BTAPP_Status.batteryLevel & 0x0f);
    *ptr++ = BT_btmState;
	*ptr++ = BT_groupstatus;
	*ptr++ = BT_groupLinkEvent;
    *ptr++ = BTAPP_Status.BDAddr[0];
    *ptr++ = BTAPP_Status.BDAddr[1];
    *ptr++ = BTAPP_Status.BDAddr[2];
    *ptr++ = BTAPP_Status.BDAddr[3];
    *ptr++ = BTAPP_Status.BDAddr[4];    //new added for category 1
    *ptr++ = BTAPP_Status.BDAddr[5];    //new added for category 1
	if(BT_groupstatus == SPEAKER_SINGLE)	
	{
        *ptr++ = 0;
        *ptr++ = 0;
        *ptr++ = 0;
        *ptr++ = 0;
        *ptr++ = 0;     //new added for category 1
        *ptr++ = 0;     //new added for category 1
	}
	else if((BT_groupstatus == SPEAKER_nSPK_MASTER) ||
			(BT_groupstatus == SPEAKER_BROADCAST_MASTER_ADDING)||
			(BT_groupstatus == SPEAKER_BROADCAST_MASTER))
	{
        *ptr++ = BTAPP_Status.BDAddr[0];
        *ptr++ = BTAPP_Status.BDAddr[1];
        *ptr++ = BTAPP_Status.BDAddr[2];
        *ptr++ = BTAPP_Status.BDAddr[3];
        *ptr++ = BTAPP_Status.BDAddr[4];    //new added for category 1
        *ptr++ = BTAPP_Status.BDAddr[5];    //new added for category 1
	}
	else if((BT_groupstatus == SPEAKER_nSPK_SLAVE) ||
			(BT_groupstatus == SPEAKER_BROADCAST_SLAVE))	
	{
        *ptr++ = BT_MasterAddr[0];
        *ptr++ = BT_MasterAddr[1];
        *ptr++ = BT_MasterAddr[2];
        *ptr++ = BT_MasterAddr[3];
        *ptr++ = BT_MasterAddr[4];  //new added for category 1
        *ptr++ = BT_MasterAddr[5];  //new added for category 1
	}
    *ptr++ = BT_bleAdvFeature;      //new added for category 1
    BLE_SetAdvertisingData(advertisingData, 24);    
}

/*------------------------------------------------------------*/
void BLE_SetScanRspData(void)
{
    uint8_t advertisingData[31];
    uint8_t i;
	uint8_t* ptr = advertisingData;
    
	*ptr++ = 1+BT_deviceName[0];
	*ptr++ = 0x09;     //Complete Local Name
	for(i=0; i< BT_deviceName[0]; i++)
		*ptr++ = BT_deviceName[1+i];
    BLE_SetScanResponseData(advertisingData, 2+BT_deviceName[0]);    
}

/*------------------------------------------------------------*/
void BLE_forceUpdate(void)
{
    BLE_EnableAdvertising(false);
    BLE_SetAdvData();
    BLE_SetScanRspData();
    BLE_SetAdvertisingType(BLE_advType);
    BLE_EnableAdvertising(true);
}
#endif
