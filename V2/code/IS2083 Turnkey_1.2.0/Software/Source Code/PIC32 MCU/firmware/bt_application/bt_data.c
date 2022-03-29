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
#define BT_DATA_C
#include "bt_data.h"
#include "bt_app.h"
#include "led.h"    //for debugging
#include "bt_a2dp.h"
#include "bt_hfp.h"
#include "bt_multi_spk.h"
#include "bt_volume.h"
#include "bt_line_in.h"
#include "bt_command_send.h"
#include "bt_command_decode.h"



SPP_IAP_LINK_STATUS SPPiAP_LinkStatus;    
BLE_LINK_STATUS BLE_LinkStatus;

static DATA_PACKET_INFO    dataPacketInfo;
#define BT_SPP_RxFifoSize 200                                       //receive buffer max. size
static uint8_t BT_SPP_RxFifo[BT_SPP_RxFifoSize];                          //receive buffer
static uint32_t BT_SPP_RxFifoHead, BT_SPP_RxFifoTail, BT_SPP_RxCounter;
 //uint32_t BT_SPP_State=0;           //this is test variable, don't need to migrate the code

#ifdef _SPP_LINK_BREAK_IN
SPP_LINK_CONNECTION_STATE SPP_LinkConnectionStatus;
#endif

#ifdef _CODE_FOR_APP
typedef enum
{
	APPS_GET_STATUS,
	APPS_SET_STATUS
}APPS_COMMAND;

typedef enum
{
	APPS_GET_AUXIN_STATUS,		
	APPS_GET_POWER_STATUS,		
	APPS_SET_AUDIO_SRC,
	APPS_SET_INDIV_MMI_ACTION = 0x7A
}APPS_STATUS;

enum {
	APPS_AUX_UNPLUG = 0x80,
	APPS_AUX_PLUG_AUX,
	APPS_AUX_PLUG_A2DP		
};

#endif

#define MOBILE_APP_MCU_PROTOCOL 0xCC
#define INDIV_ACTION_CMD_LENGTH		8		// 4byte MAC address
//#define INDIV_ACTION_CMD_LENGTH		10		// 6byte MAC address
/*-----------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------*/
static void BTMDATA_ClearFIFO( void )
{
    uint16_t i;
    BT_SPP_RxFifoHead = 0;
    BT_SPP_RxFifoTail = 0;
    BT_SPP_RxCounter = 0;
    for(i = 0; i< sizeof(BT_SPP_RxFifo); i++)
        BT_SPP_RxFifo[i] = 0;
}

/*-----------------------------------------------------------------------------*/
static bool BTMDATA_AddBytesToFIFO(uint8_t* data, uint8_t size)        //TRUE: data added ok, FALSE: data added fail, buffer is overflow
{
    uint8_t i;
    for(i=0; i<size; i++)
    {
        if(BT_SPP_RxCounter < BT_SPP_RxFifoSize)
        {
            BT_SPP_RxFifo[BT_SPP_RxFifoTail] = *data++;
            BT_SPP_RxCounter++;
            if(BT_SPP_RxFifoTail < BT_SPP_RxFifoSize-1)
                BT_SPP_RxFifoTail++;
            else
                BT_SPP_RxFifoTail = 0;
        }
        else
        {
            return false;
        }
    }
    return true;
}

/*-----------------------------------------------------------------------------*/
static bool BTMDATA_ReadBytesFromFIFO( uint8_t* data, uint8_t size )
{
    if( BT_SPP_RxCounter < size )
        return false;
    
    while( BT_SPP_RxCounter && size )
    {
        *data++ = BT_SPP_RxFifo[BT_SPP_RxFifoHead];
        BT_SPP_RxCounter--;
        if(BT_SPP_RxFifoHead < BT_SPP_RxFifoSize - 1)
            BT_SPP_RxFifoHead++;
        else
            BT_SPP_RxFifoHead = 0;
        size --;
    }
}

/*-----------------------------------------------------------------------------*/
static bool BTMDATA_CheckFIFOBytesSize( uint8_t* data, uint8_t size )
{
    return BT_SPP_RxCounter;
}

static void BTMDATA_FIFOInit( void )
{
    BT_SPP_RxFifoHead = 0;
    BT_SPP_RxFifoTail = 0;
    BT_SPP_RxCounter = 0;
}

/*-----------------------------------------------------------------------------*/
void BTMDATA_Init( void )
{
    BTMDATA_FIFOInit();
    BLE_LinkStatus.BLE_ConnectionStatus = BLE_CONN_STANDBY;
    BLE_LinkStatus.BLE_GATTServiceStatus.serviceValue = 0;
}

void BTMDATA_EventHandler( BT_DATA_EVENTS event, uint8_t* paras, uint16_t size )
{
    switch( event )
    {
        case LE_STATUS_CHANGED:
            if (paras[0] == 0)// 0x00: LE Status Report
            {
                BLE_LinkStatus.BLE_ConnectionStatus = paras[1];
                BLE_LinkStatus.BLE_GATTServiceStatus.serviceValue = paras[2];
                switch (BLE_LinkStatus.BLE_ConnectionStatus) {
                    case BLE_CONN_STANDBY: //LE standby
                        Set_LED_Style(LED_5, LED_OFF, 500, 500);     //debugging  
#ifdef _BLE_ADV_CTRL_BY_MCU
                        if ( BTAPP_GetStatus() == BT_STATUS_OFF || BTAPP_GetStatus() == BT_STATUS_ON || BTAPP_GetStatus() == BT_STATUS_READY ) 
                        {
//                            if( BTMSPK_GetMSPKStatus() == BT_CSB_STATUS_CONNECTED_AS_NSPK_SLAVE || BTMSPK_GetMSPKStatus() == BT_CSB_STATUS_CONNECTED_AS_BROADCAST_SLAVE )
//                            {
//                                BLE_UpdateAdvType(SCANNABLE_UNDIRECT_ADV); //non-connectable
//                            }
//                            else
//                            {
//                                BLE_UpdateAdvType(CONNECTABLE_UNDIRECT_ADV);
//                            }
                            BLE_UpdateAdvType(CONNECTABLE_UNDIRECT_ADV);
                            BLE_forceUpdate();
                        }
#endif
                        break;
                    case BLE_CONN_ADV: //advertising
                        Set_LED_Style(LED_5, LED_BLINK, 500, 500);     //debugging, 1HZ blink when advertising
                        break;
                    case BLE_CONN_SCAN: //scanning
                        Set_LED_Style(LED_5, LED_BLINK, 100, 900);     //debugging, 1HZ blink when scanning
                        break;
                    case BLE_CONN_CONNECTED: //connected
                        
                        dataPacketInfo.packetHeader.value = 0x04;
#ifdef _CODE_FOR_APP     
                        if(BLE_LinkStatus.BLE_GATTServiceStatus.bits.transparentServiceActive)
                        {
                            Set_LED_Style(LED_5, LED_ON, 500, 500);     //debugging   
                            if(BTMDATA_isBLETransparentServiceConnected())
                                BT_SendAppsPowerStatus(BTAPP_GetStatus() == BT_STATUS_OFF ? 0 : 2);
                        }
                        else
                        {
                            Set_LED_Style(LED_5, LED_BLINK, 100, 100);     //debugging, fast blink when not transparent service connected
                        }
#endif                        
                        break;
                    default:
                        break;
                }
            }
            else
            {
                
            }
            break;
            
        case BT_EVENT_SPP_CONNECTED:
            LED6_ON();          //for debugging
            SPPiAP_LinkStatus.SPPLinkStatus = 1;
            SPPiAP_LinkStatus.currentSPPiAPDatabaseIndex = paras[1] & 0xf;
            dataPacketInfo.packetHeader.value = paras[2];
            BTAPP_EventHandler( BT_EVENT_SPP_LINK_CONNECTED, 0, 0);
            break;
            
        case BT_EVENT_IAP_CONNETED:
            LED7_ON();          //for debugging
            SPPiAP_LinkStatus.iAPLinkStatus = 1;
            SPPiAP_LinkStatus.currentSPPiAPDatabaseIndex = paras[1] & 0xf;
            dataPacketInfo.packetHeader.value = paras[2];
            BTAPP_EventHandler( BT_EVENT_IAP_LINK_CONNETED, 0, 0);
            break;
            
        case BT_EVENT_SPP_IAP_DISCONNECTED:
            LED6_OFF();          //for debugging
            LED7_OFF();          //for debugging
            SPPiAP_LinkStatus.SPPLinkStatus = 0;
            SPPiAP_LinkStatus.iAPLinkStatus = 0;
            BTAPP_EventHandler( BT_EVENT_SPP_IAP_LINK_DISCONNECTED, 0, 0);
            break;
            
    }
            
}
/*-----------------------------------------------------------------------------*/
#ifdef _CODE_FOR_APP
static bool BTMDATA_Fragmented_Pkt_Handler(uint8_t* data, uint8_t size, uint8_t pkt_type)
{
    uint8_t i;
    uint16_t cmd_len;
    if(size > BT_SPP_RxFifoSize)
        return false;
    if (pkt_type == BT_FRAGMENTED_START_PKT)
    {
        BT_SPP_RxCounter = size;
        BT_SPP_RxFifoTail = 0;
        BT_SPP_RxFifoHead = 0;
    }
    else
    {
        //BT_SPP_RxCounter += size;
        BT_SPP_RxCounter += data[2];
    }

    if ((pkt_type == BT_FRAGMENTED_END_PKT) || (pkt_type == BT_FRAGMENTED_CONT_PKT))
    {
        *data++;
        *data++;
        size = *data++;
    }
    
    for(i=0; i<size; i++)
    {
        BT_SPP_RxFifo[BT_SPP_RxFifoTail++] = *data++;
        //BT_SPP_RxCounter++;
    }
    /*if ((pkt_type == BT_FRAGMENTED_START_PKT) || (pkt_type == BT_FRAGMENTED_CONT_PKT))
        BT_SPP_State = 4;       //strat to send these RAW DATA, test function.
    else */if (pkt_type == BT_FRAGMENTED_END_PKT)
    {
        
        cmd_len = BT_SPP_RxCounter - 4;  // minus the first 3 bytes and the checksum byte
        BT_SPP_RxFifo[1] = (cmd_len >> 8) & 0xFF;   
        BT_SPP_RxFifo[2] = cmd_len & 0xFF;
        if(ParsePayloadAsCommand(BT_SPP_RxFifo, BT_SPP_RxCounter))
        {
            //BT_SPP_State = 3;
            BT_SendBytesAsCompleteCommand(BT_SPP_RxFifo, BT_SPP_RxCounter); 
            addComandWaitingForACK( BT_SPP_RxFifo[3]);
        }
        else
        {
            //BT_SPP_State = 1;
            BT_LoopBackSPPData(BT_SPP_RxFifo, BT_SPP_RxCounter);
        }
    }   
    return true;
}

/*-----------------------------------------------------------------------------*/
void AppsReportLineInStatus( void ) 
{
    if(BTMDATA_isBLETransparentServiceConnected())
    {
        if (BTM_LINE_IN_IsPlugged()) {
            BT_SendAppBTMStatus(BTM_LINE_IN_GetLineInStatus() == LINE_IN_INACTIVE ? APPS_AUX_PLUG_A2DP : APPS_AUX_PLUG_AUX);
        } else {
            BT_SendAppBTMStatus(APPS_AUX_UNPLUG);
        }
    }
}

/*-----------------------------------------------------------------------------*/
void AppsCommandDecode(uint8_t* buffer, uint8_t size)
{
    uint8_t individual_data[8];
	switch(buffer[0])
	{
		case APPS_GET_STATUS:
			switch(buffer[1])
			{
				case APPS_GET_AUXIN_STATUS:
                    BT_SendAppsAck(MOBILE_APP_MCU_PROTOCOL, STS_OK);
                    AppsReportLineInStatus();
				break;
				case APPS_GET_POWER_STATUS:
					BT_SendAppsAck(MOBILE_APP_MCU_PROTOCOL, STS_OK);                    
					BT_SendAppsPowerStatus(BTAPP_GetStatus() == BT_STATUS_OFF ? 0 : 2);
				break;
                default:
					BT_SendAppsAck(MOBILE_APP_MCU_PROTOCOL, ERROR_COMMAND_UNKNOW);                    
                    break;
			}
		break;
		case APPS_SET_STATUS:
			switch(buffer[1])
			{
				case APPS_SET_AUDIO_SRC:
					BT_SendAppsAck(MOBILE_APP_MCU_PROTOCOL, STS_OK);                    
                    if(BTM_LINE_IN_IsPlugged())
                    {
                        if(BTM_LINE_IN_GetLineInStatus() == LINE_IN_INACTIVE)
                        {
                            BTMA2DP_PauseStart();
                            BT_EnterLineInMode(1, 0);
                        }
                        else
                        {
                            BT_EnterLineInMode(0, 0);
                            BTMA2DP_PlayStart();
                        }
                    }
				break;
				case APPS_SET_INDIV_MMI_ACTION:
					BT_SendAppsAck(MOBILE_APP_MCU_PROTOCOL, STS_OK);
					if( ( size - 2 ) == INDIV_ACTION_CMD_LENGTH &&  buffer[6] == MMI_CMD )
                    {
                        individual_data[0] = 0xFC;
                        individual_data[1] = buffer[2]; //BD address [0]
                        individual_data[2] = buffer[3]; //BD address [1]
                        individual_data[3] = buffer[4]; //BD address [2]
                        individual_data[4] = buffer[5]; //BD address [3]
                        individual_data[5] = 0;     //reserved for BD address [4]
                        individual_data[6] = 0;     //reserved for BD address [5]
                        individual_data[7] = buffer[8];     //MMI_ACTION value
						BT_Vendor_SendCommand(individual_data ,8);
                    }
				break;
				default:
					BT_SendAppsAck(MOBILE_APP_MCU_PROTOCOL, ERROR_COMMAND_UNKNOW);
				break;		
			}
		break;
        default:
			BT_SendAppsAck(MOBILE_APP_MCU_PROTOCOL, ERROR_COMMAND_UNKNOW);            
        break;
	}

}
#endif

/*-----------------------------------------------------------------------------*/
void BTMDATA_Handler( uint8_t* data, uint16_t size )
{
    dataPacketInfo.packetHeader.value = data[0];
    dataPacketInfo.packetType = data[1];
    dataPacketInfo.totalPayloadLength = (uint16_t)data[2];
    dataPacketInfo.totalPayloadLength <<= 8;
    dataPacketInfo.totalPayloadLength |= (uint16_t)data[3];
    dataPacketInfo.currentPayloadLength = (uint16_t)data[4];
    dataPacketInfo.currentPayloadLength <<= 8;
    dataPacketInfo.currentPayloadLength |= (uint16_t)data[5];
    dataPacketInfo.currentPayloadData = &data[6];

#ifdef _CODE_FOR_APP
    if(BTMDATA_isBLETransparentServiceConnected())  //BLE transparent, consider it is MBA or AWA test
    {
    if( data[9] == MOBILE_APP_MCU_PROTOCOL)
	{	// Todo : need to define protocol for Mobile control MCU
        //BT_SetMultiSpkEQRoute( data[10]);
        AppsCommandDecode( data+10 , data[8] );
        return;
	}
    if( data[9] == MCU_SEND_EVENT_ACK )
	{
        // MCU has been acked the 5506 event before parsing to Mobile Apps.
		// Here MCU block any "event ack" from Mobile Apps.
		return;
	}
    if (data[9] == 0x30) 
    {
        if ( BT_SendMultiSpkEQBytes(&data[11], 84) )
        {
            BT_SendAppsAck(data[9], STS_OK);
            return;
        }
    } 
    else if (data[9] == 0x35) 
    {
        if (data[12] > 0 && data[12] <= 16) 
        {
            BLE_SaveDeviceName(&data[12]);
            BLE_forceUpdate();
        }
    } 
    else if (data[9] == MMI_CMD && data[10] == 0x00) 
    {
        switch (data[11]) 
        {
            case 0x51:
                if (BTAPP_GetStatus() == BT_STATUS_OFF) 
                {
                    BT_SendAppsAck(data[9], STS_OK);
                    BTAPP_TaskReq(BT_REQ_SYSTEM_ON);
                }
                else
                {
                    BT_SendAppsAck(data[9], ERROR_DISALLOWED);
                }
                return;

            case 0x53:
                if (BTAPP_GetStatus() != BT_STATUS_OFF)
                {
                    BT_SendAppsAck(data[9], STS_OK);
                    BTAPP_EventHandler(BT_EVENT_MSPK_BROADCAST_SLAVE_POWER_OFF, 0, 0);
                }
                else
                {
                    BT_SendAppsAck(data[9], ERROR_DISALLOWED);
                }
                return;
            case 0x52:
            case 0x54:
                BT_SendAppsAck(data[9], STS_OK);
                return;

            case 0x30:
				BT_SendAppsAck(data[9], STS_OK);
				BTVOL_VolUp( );						
				return;
                
			case 0x31:
				BT_SendAppsAck(data[9], STS_OK);
				BTVOL_VolDown( );
				return;
        }
    }
    
    //for others, pass payload as an UART command to send to BTM
    if( data[7])
    {
        BTMDATA_Fragmented_Pkt_Handler( dataPacketInfo.currentPayloadData, dataPacketInfo.currentPayloadLength, data[7 ]);
    } 
    else 
    {
        if (ParsePayloadAsCommand(dataPacketInfo.currentPayloadData, dataPacketInfo.currentPayloadLength)) 
        {
            BT_SendBytesAsCompleteCommand( dataPacketInfo.currentPayloadData, dataPacketInfo.currentPayloadLength );   //send payload as a complete command directly
            addComandWaitingForACK( dataPacketInfo.currentPayloadData[3] );
        } 
    }   
    }
    else        //not BLE transparent, consider it is bt_chat app test
    {
        if (ParsePayloadAsCommand(dataPacketInfo.currentPayloadData, dataPacketInfo.currentPayloadLength)) 
        {
            BT_SendBytesAsCompleteCommand( dataPacketInfo.currentPayloadData, dataPacketInfo.currentPayloadLength );   //send payload as a complete command directly
        } 
        else 
        {
            BT_LoopBackSPPData( data, size );
        }
    }
#else
    BTMDATA_AddBytesToFIFO( dataPacketInfo.currentPayloadData, dataPacketInfo.currentPayloadLength );            
#endif	
}

/*-----------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------------------------------------------*/
bool BTMDATA_GATT_AttributeHandler(uint8_t attributeIndex, uint8_t* attributeData, uint8_t attributeDataLength)
{
    switch(attributeIndex)
    {
        case 1:
        case 2:
        default:
            break;
    }
    return true;
}


//void BTMData_1msTimer( void )
//{
//}

/*-----------------------------------------------------------------------------*/
uint8_t BTMDATA_GetSPPiAPActiveDatabaseIndex( void )
{
    return SPPiAP_LinkStatus.currentSPPiAPDatabaseIndex;
}

/*-----------------------------------------------------------------------------*/
uint8_t BTMDATA_GetSPPiAPChannelIndex( void )
{
    return dataPacketInfo.packetHeader.value;
}

/*-----------------------------------------------------------------------------*/
bool BTMDATA_isSPPorIAPConnected( void )
{
    if( SPPiAP_LinkStatus.SPPLinkStatus || SPPiAP_LinkStatus.iAPLinkStatus )
        return true;
    else
        return false;
}

/*-----------------------------------------------------------------------------*/
bool BTMDATA_isBLEConnected(void)
{
	return ( BLE_LinkStatus.BLE_ConnectionStatus == BLE_CONN_CONNECTED) ? 1 :0;
}

/*-----------------------------------------------------------------------------*/
bool BTMDATA_isBLETransparentServiceConnected( void )
{
    if(BLE_LinkStatus.BLE_ConnectionStatus == BLE_CONN_CONNECTED && BLE_LinkStatus.BLE_GATTServiceStatus.bits.transparentServiceActive)
        return true;
    else
        return false;
}

/*-----------------------------------------------------------------------------*/
bool BTMDATA_isBLEANCSServiceConnected( void )
{
    if(BLE_LinkStatus.BLE_ConnectionStatus == BLE_CONN_CONNECTED && BLE_LinkStatus.BLE_GATTServiceStatus.bits.ANCSActive)
        return true;
    else
        return false;    
}

/*-----------------------------------------------------------------------------*/
bool BTMDATA_SendData(uint8_t* addr, uint32_t size)
{
    BT_SendSPPData(addr, (uint16_t)size, dataPacketInfo.packetHeader.value);
    return true;
}

/*-----------------------------------------------------------------------------*/
bool BTMDATA_SendOneByte(uint8_t byte)
{
    BT_SendSPPData(&byte, 1, dataPacketInfo.packetHeader.value);
    return true;
}

#ifdef _SPP_LINK_BREAK_IN
/*------------------------------------------------------------*/
//void BTMDATA_SPPLinkChangeStart(void)
/*------------------------------------------------------------*/
void BTMDATA_SPPLinkChangeStart( uint8_t targetDatabaseIndex)
{
    SPPiAP_LinkStatus.targetSPPiAPDatabaseIndex = targetDatabaseIndex;
    SPP_LinkConnectionStatus.request = true;
    SPP_LinkConnectionStatus.state = SPP_LINK_CONNECTION_TASK_IDLE;
    //BT_SPP_State = 0;       //cancel current SPP tansmission task
}

/*------------------------------------------------------------*/
//void BTMDATA_SPPLinkChangeTask(void)
/*------------------------------------------------------------*/
void BTMDATA_SPPLinkChangeTask(void)
{
    switch(SPP_LinkConnectionStatus.state)
    {
        case SPP_LINK_CONNECTION_TASK_IDLE:
            if(SPP_LinkConnectionStatus.request)
            {
                SPP_LinkConnectionStatus.request = false;
                if( SPPiAP_LinkStatus.SPPLinkStatus || SPPiAP_LinkStatus.iAPLinkStatus )// BT_LinkStatus & BIT_SPP_LINK_STATUS)
                    SPP_LinkConnectionStatus.state = SPP_LINK_CONNECTION_TASK_DISCONNECTION_START;
                else
                    SPP_LinkConnectionStatus.state = SPP_LINK_CONNECTION_TASK_CONNECTION1_START;
            }
            break;
        case SPP_LINK_CONNECTION_TASK_DISCONNECTION_START:
            BT_DisconnectSPPProfile();
            SPP_LinkConnectionStatus.state = SPP_LINK_CONNECTION_TASK_DISCONNECTION_WAIT;
            break;
        case SPP_LINK_CONNECTION_TASK_DISCONNECTION_WAIT:
            if( SPPiAP_LinkStatus.SPPLinkStatus || SPPiAP_LinkStatus.iAPLinkStatus )//(BT_LinkStatus & BIT_SPP_LINK_STATUS)
                break;
            else
                SPP_LinkConnectionStatus.state = SPP_LINK_CONNECTION_TASK_CONNECTION1_START;
            break;
        case SPP_LINK_CONNECTION_TASK_CONNECTION1_START:
            //BT_ProfileLinkBack ( 0x02, BTSPP_linkingIndex);       //SPP profile link back
            BT_ProfileLinkBack ( 0x02, SPPiAP_LinkStatus.targetSPPiAPDatabaseIndex);       //SPP profile link back
            SPP_LinkConnectionStatus.state = SPP_LINK_CONNECTION_TASK_CONNECTION1_WAIT;
            break;
        case SPP_LINK_CONNECTION_TASK_CONNECTION1_WAIT:
            if(SPPiAP_LinkStatus.SPPLinkStatus || SPPiAP_LinkStatus.iAPLinkStatus)//BT_LinkStatus & BIT_SPP_LINK_STATUS)
            {
                SPP_LinkConnectionStatus.state = SPP_LINK_CONNECTION_TASK_CONNECTION2_START;
            }
            break;
        case SPP_LINK_CONNECTION_TASK_CONNECTION2_START:
            //BT_ProfileLinkBack ( 0x02, BTSPP_linkingIndex);           //SPP profile link back
            BT_ProfileLinkBack ( 0x02, SPPiAP_LinkStatus.targetSPPiAPDatabaseIndex);           //SPP profile link back
            SPP_LinkConnectionStatus.state = SPP_LINK_CONNECTION_TASK_IDLE;
            break;
        default:
            break;
    }
}
#endif

#ifdef _CODE_FOR_APP
#define APP_CMD_FOR_ACK_MAX 10
static struct {
    uint8_t NumCommandForACK;
    uint8_t CommandForACK[APP_CMD_FOR_ACK_MAX];
} APPCommandWaitingForACK;

void addComandWaitingForACK( uint8_t cmd_id ) //call by data handler
{
    if( APPCommandWaitingForACK.NumCommandForACK < APP_CMD_FOR_ACK_MAX)
    {
        APPCommandWaitingForACK.CommandForACK[APPCommandWaitingForACK.NumCommandForACK++] = cmd_id;
    }
}

bool checkCommandWaitingForACK( uint8_t cmd_id, uint8_t ack_status )  // call by bt_command_decode
{
    uint8_t i;
    if(APPCommandWaitingForACK.NumCommandForACK && (cmd_id == APPCommandWaitingForACK.CommandForACK[0]) )
    {
        if(APPCommandWaitingForACK.NumCommandForACK == 1)
        {
            APPCommandWaitingForACK.NumCommandForACK = 0;
        }
        else
        {
            for(i=0; i<(APPCommandWaitingForACK.NumCommandForACK-1); i++)
            {
                APPCommandWaitingForACK.CommandForACK[i] = APPCommandWaitingForACK.CommandForACK[i+1];
            }
            APPCommandWaitingForACK.NumCommandForACK--;
        }
        return true;
    }
    else
    {
        return false;
    }
}
#endif

