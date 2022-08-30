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
#include "timer.h"
//#include "bt_ble_adv.h"
#include "bt_command_decode.h"
#include "bt_command_send.h"

#include "bt_volume.h"
#include "bt_multi_spk.h"
#include "bt_a2dp.h"
#include "bt_hfp.h"
#include "bt_line_in.h"



//command decode state machine
typedef enum {
	RX_DECODE_CMD_SYNC_AA,
	RX_DECODE_CMD_LENGTH_00,
	RX_DECODE_CMD_LENGTH,
	RX_DECODE_CMD_DATA,
	RX_DECODE_CMD_CHECKSUM
} RX_DECODE_MODE;

//event ID
enum            
{
  ACK = 0x00,
  DEVICE_STATE = 0x01,
  CALL_STATUS = 0x02,
  CALL_ID = 0x03,
  SMS_INDICATION = 0x04,
  MISS_CALL_INDICATION = 0x05,
  PHONE_MAX_BATTERY_LEVEL = 0x06,
  PHONE_BATTERY_LEVEL = 0x07,
  PHONE_ROAMING_STATUS = 0x08,
  PHONE_MAX_SIGNAL_STRENGTH = 0x09,
  PHONE_SIGNAL_STRENGTH = 0x0A,
  PHONE_SERVICE_STATUS = 0x0B,
  BATTERY_LEVEL = 0x0C,
  CHARGER_STATUS = 0x0D,
  RESET_TO_DEFAULT = 0x0E,
  VOLUME_LEVEL = 0x0F,
  EQ_MODE = 0x10,
  MISS_CALL_HISTORY = 0x11,
  RECEIVED_CALL_HISTORY = 0x12,
  DIALED_CALL_HISTORY = 0x13,
  COMBINE_CALL_HISTORY = 0x14,
  PHONE_BOOK = 0x15,
  ACCESS_FINISH = 0x16,
  REMOTE_DEVICE_NAME = 0x17,
  BTM_VERSION = 0x18,
  CALL_LIST_REPORT = 0x19,
  AVRCP_SPEC_RSP = 0x1A,
  BTM_UTILITY_REQ = 0x1B,
  VENDOR_AT_CMD_RSP = 0x1C,
  UNKNOW_AT_RESULT = 0x1D,
  REPORT_LINK_STATUS = 0x1E,
  REPORT_PAIRING_RECORD = 0x1F,
  REPORT_LOCAL_BD_ADDR = 0x20,
  REPORT_LOCAL_DEVICE_NAME = 0x21,
  REPORT_SPP_DATA = 0x22,
  REPORT_LINK_BACK_STATUS = 0x23,
  RINGTONE_FINISH_INDICATION = 0x24,
  USER_CONFIRM_SSP_REQ = 0x25,
  REPORT_AVRCP_VOL_CTRL = 0x26,
  REPORT_INPUT_SIGNAL_LEVEL = 0x27,
  REPORT_IAP_INFO = 0x28,
  REPORT_AVRCP_ABS_VOL_CTRL = 0x29,
  REPORT_VOICE_PROMPT_STATUS = 0x2A,
  REPORT_MAP_DATA = 0x2B,
  SECURITY_BONDLING_RES = 0x2C,
  REPORT_TYPE_CODEC = 0x2D,
  REPORT_TYPE_BTM_SETTING = 0x2E,
  REPORT_MCU_UPDATE_REPLY = 0x2F,
  REPORT_BTM_INITIAL_STATUS = 0x30,
  REPORT_LE_EVENT = 0x32,
  REPORT_nSPK_STATUS = 0x33,
  REPORT_nSPK_VENDOR_EVENT = 0x34,
  REPORT_VENDOR_EEPROM = 0x37,
  REPORT_CUSTOMER_GATT_ATTRIBUTE_DATA = 0x39,
  REPORT_LINK_MODE = 0x3A,
  REPORT_nSPK_EXCHANGE_LINK_INFO = 0x3D,
  REPORT_BT_CLK = 0x3F,
  REPORT_FEATURE_LIST = 0x40
};

//command decode: BTM status
enum
{
  BT_OFF = 0x00,
  BT_DISCOVERABLE = 0x01,
  BT_ON = 0x02,
  BT_PAIRING_COMPLETE = 0x03,
  BT_PAIRING_FAIL = 0x04,
  BT_HFP_CONNECTED = 0x05,
  BT_A2DP_CONNECTED = 0x06,
  BT_HFP_DISCONNECTED = 0x07,
  BT_A2DP_DISCONNECTED = 0x08,
  BT_SCO_CONNECTED = 0x09,
  BT_SCO_DISCONNECTED = 0x0A,
  BT_ARVCP_CONNECTED = 0x0B,
  BT_AVRCP_DISCONNECTED = 0x0C,
  BT_SPP_CONNECTED = 0x0D,
  BT_SPP_DISCONNECTED = 0x0E,
  BT_STANDBY = 0x0F,
  BT_iAP_CONNECTED = 0x10,
  BT_ACL_DISCONNECTED = 0x11,
  BT_MAP_CONNECTED = 0x12,
  BT_MAP_FORBIDDEN = 0x13,
  BT_MAP_DISCONNECTED = 0x14,
  BT_ACL_CONNECTED = 0x15,
  BT_SPP_REJECTED = 0x16
};

//Command decode: BTM_Utility_Req
enum
{
    BTM_CONTROL_AMP = 0x00,
    BTM_REPORT_LINE_IN_STATUS = 0x01,
    BTM_NOTIFY_HANDLE_BTM = 0x02,
    BTM_NOTIFY_EEPROM_UPDATE_FINISH = 0x03,
    BTM_REPORT_CODEC_STATUS = 0x04,
    NSPK_SYNC_POWER_OFF = 0x05,
    NSPK_SYNC_VOLUME_CTRL = 0x06,
    NSPK_SYNC_INTERNAL_GAIN = 0x07,
    NSPK_SYNC_A2DP_ABS_VOL = 0x08,
    NSPK_SYNC_CURRENT_CHANNEL_SETTING = 0x09,
    NSPK_NOTIFY_POWER_SYNCED = 0x0A,
    NSPK_NOTIFY_COMMAND_SUCCESS = 0x0B,
    NSPK_NOTIFY_COMMAND_FAIL = 0x0C,
    NSPK_NOTIFY_SLAVE_STATUS_CHANGED = 0x0D,
    NSPK_RESERVED = 0x0E,
    NSPK_NOTIFY_ADD_THIRD_SPEAKER = 0x0F
};

/*======================*/
/*  external variables  */
/*======================*/
uint8_t  BT_CmdDecodedFlag;
uint8_t  BT_CmdBuffer[BT_CMD_SIZE_MAX	];

/*======================================*/
/*  internal variables          */
/*======================================*/
static RX_DECODE_MODE  BT_CmdDecodeState;
static uint16_t  BT_CmdDecodeCmdLength;
static uint8_t  BT_CmdDecodeChecksum;			
static uint16_t  BT_CmdDecodeDataCnt;                    //temporary variable in decoding
static unsigned short BT_CmdBufferPt;                    //

typedef enum {
	TXRX_BUF_EMPTY,
	TXRX_BUF_OK,
	TXRX_BUF_FULL
} RX_BUF_STATUS;
#ifdef BT_UART_RX_BYTE_MODEL

static uint8_t  UR_RxBuf[UR_RX_BUF_SIZE];
static uint16_t UR_RxBufHead;
static uint16_t UR_RxBufTail;
static RX_BUF_STATUS UR_RxBufStatus;
#endif

bool ParsePayloadAsCommand(uint8_t* command, uint8_t length);

/*======================================*/
/*  function implemention       */
/*======================================*/
void BT_CommandDecodeInit(void)
{
    BT_CmdDecodedFlag = 0;
    BT_CmdDecodeState = RX_DECODE_CMD_SYNC_AA;
#ifdef BT_UART_RX_BYTE_MODEL
    UR_RxBufHead = 0;
    UR_RxBufTail = 0;
    UR_RxBufStatus = TXRX_BUF_EMPTY;
#else//BUFFER_MODEL
    while(eusartRxCount)
    {
        EUSART_Read();
    }
#endif
    
}

/*-----------------------------------------------------------------------------*/
void BT_CommandDecodeMain(void)
{
	BT_CommandHandler();
	if(BT_CmdDecodedFlag)
	{
            BT_CommandDecode();
            BT_CmdDecodedFlag = 0;
	}
}

/*-----------------------------------------------------------------------------*/
#ifndef BT_UART_RX_BYTE_MODEL//BUFFER MODEL
extern volatile uint8_t eusartRxCount;
#endif

uint16_t BT_GetUartDataFromBuf(uint8_t *buff, uint16_t sz)
{
//if in OTA phase, read back from BT_CmdBuffer[BT_CMD_SIZE_MAX]
//if in DFU phase, read back from UR_RxBuf[UR_RxBufTail++]
    uint8_t current_byte, i = 0;
#ifdef BT_UART_RX_BYTE_MODEL
    while(UR_RxBufTail != UR_RxBufHead && i<sz ) {
        current_byte = UR_RxBuf[UR_RxBufTail++];
            if(UR_RxBufTail >= UR_RX_BUF_SIZE)
                UR_RxBufTail = 0;
            UR_RxBufStatus = TXRX_BUF_OK;
#else//BUFFER MODEL
    while (eusartRxCount && i<sz ) {
        current_byte = EUSART_Read();
#endif
        buff[i++] = current_byte;
    }
    return i;
}

void BT_CommandHandler(void) {
    uint8_t current_byte;
#ifdef BT_UART_RX_BYTE_MODEL
    while(UR_RxBufTail != UR_RxBufHead) {
        current_byte = UR_RxBuf[UR_RxBufTail++];
            if(UR_RxBufTail >= UR_RX_BUF_SIZE)
                UR_RxBufTail = 0;
            UR_RxBufStatus = TXRX_BUF_OK;
#else//BUFFER MODEL
    while (eusartRxCount) {
        current_byte = EUSART_Read();
#endif

        switch (BT_CmdDecodeState) {
            case RX_DECODE_CMD_SYNC_AA:
                if (current_byte == 0xaa)
                    BT_CmdDecodeState = RX_DECODE_CMD_LENGTH_00;
                break;

            case RX_DECODE_CMD_LENGTH_00:
                BT_CmdDecodeCmdLength = (uint16_t)current_byte;
                BT_CmdDecodeCmdLength <<= 8;
                BT_CmdDecodeChecksum = current_byte; //checksum calculation start!
                BT_CmdDecodedFlag = 0; //command receive flag clear
                BT_CmdBufferPt = 0; //buffer reset for command parameter
                BT_CmdDecodeState = RX_DECODE_CMD_LENGTH;
                break;

            case RX_DECODE_CMD_LENGTH:
                BT_CmdDecodeCmdLength += (uint16_t)current_byte;
                BT_CmdDecodeChecksum += current_byte; //checksum calculation start!
                BT_CmdDecodeDataCnt = BT_CmdDecodeCmdLength;//current_byte; //save bytes number, use to check where is command end
                BT_CmdDecodeState = RX_DECODE_CMD_DATA; //next state
                break;

            case RX_DECODE_CMD_DATA:
                BT_CmdDecodeChecksum += current_byte;
                BT_CmdDecodeDataCnt--;
                BT_CmdBuffer[BT_CmdBufferPt++] = current_byte;
                if (BT_CmdDecodeDataCnt == 0) //no data remained?
                    BT_CmdDecodeState = RX_DECODE_CMD_CHECKSUM; //yes, next mode: checksum
                break;

            case RX_DECODE_CMD_CHECKSUM:
                if ((uint8_t) (BT_CmdDecodeChecksum + current_byte) == 0) {
                    BT_CmdDecodedFlag = 1;
                } else {
                }
                BT_CmdDecodeState = RX_DECODE_CMD_SYNC_AA;
                break;
            default:
                break;
        }

        if (BT_CmdDecodedFlag) {
            break;
        }
    }
}

/*-----------------------------------------------------------------------------*/
#ifdef _CODE_FOR_APP
static bool filterEventForwardToDemoApp( uint8_t event_id )
{
    bool ret = true;
    switch(event_id)
    {
        case CALL_STATUS:       // = 0x02
        case CALL_ID:           // = 0x03
        case SMS_INDICATION:        // = 0x04
        case MISS_CALL_INDICATION:  // = 0x05
        case PHONE_MAX_BATTERY_LEVEL:   // = 0x06
        case PHONE_BATTERY_LEVEL:       // = 0x07
        case PHONE_ROAMING_STATUS:      // = 0x08
        case PHONE_MAX_SIGNAL_STRENGTH: // = 0x09
        case PHONE_SIGNAL_STRENGTH:     // = 0x0A
        case PHONE_SERVICE_STATUS:      // = 0x0B
        case BATTERY_LEVEL:         // = 0x0C
        case CHARGER_STATUS:        // = 0x0D
        case RESET_TO_DEFAULT:      // = 0x0E
        case VOLUME_LEVEL:          // = 0x0F
        case BTM_UTILITY_REQ:       // = 0x1B,
        case REPORT_PAIRING_RECORD: // = 0x1F,
        case REPORT_SPP_DATA:       // = 0x22,
        case REPORT_LINK_BACK_STATUS:   // = 0x23,
        case RINGTONE_FINISH_INDICATION:    // = 0x24,
        case USER_CONFIRM_SSP_REQ:      // = 0x25,
        case REPORT_AVRCP_VOL_CTRL:     // = 0x26,
        case REPORT_INPUT_SIGNAL_LEVEL: // = 0x27,
        case REPORT_IAP_INFO:           // = 0x28,
        case REPORT_AVRCP_ABS_VOL_CTRL: // = 0x29,
        case REPORT_VOICE_PROMPT_STATUS:    // = 0x2A,
        case REPORT_MAP_DATA:       // = 0x2B,
        case SECURITY_BONDLING_RES: // = 0x2C,
        case REPORT_TYPE_CODEC:     //= 0x2D,
        case REPORT_TYPE_BTM_SETTING:   // = 0x2E,
        case REPORT_MCU_UPDATE_REPLY:   // = 0x2F,
        case REPORT_BTM_INITIAL_STATUS: // = 0x30,
        case REPORT_LE_EVENT:       // = 0x32,
        case REPORT_nSPK_VENDOR_EVENT:  // = 0x34,
        case REPORT_CUSTOMER_GATT_ATTRIBUTE_DATA:   // = 0x39,
        case REPORT_nSPK_EXCHANGE_LINK_INFO:    // = 0x3D,
        case REPORT_BT_CLK:     // = 0x3F,
            ret = false;
            break;
        default:
            break;
    }
    return ret;
}   
#endif

/*-----------------------------------------------------------------------------*/
void BT_CommandDecode( void )
{
    uint16_t para;

    // Send Ack to 5506 for the report event
    if (BT_CmdBuffer[0] != ACK)
    {
        BT_SendAckToEvent(BT_CmdBuffer[0]);     //send ACK to this event
    }
    
#ifdef _CODE_FOR_APP
    //pass some of events from BTM to APPS
    if(BT_CmdBuffer[0] != REPORT_SPP_DATA)
    {
		//if((BT_CmdBuffer[0] == ACK && cmdInfo != CMD_INFO_APPS) ||
		//	(BT_CmdBuffer[0] == ACK && BT_CmdBuffer[1] == SEND_SPP_DATA))
		//;
        if(BT_CmdBuffer[0] == ACK)
        {
            if(BT_CmdBuffer[1] == SEND_SPP_DATA)
            {
                
            }
            else if(checkCommandWaitingForACK(BT_CmdBuffer[1], BT_CmdBuffer[2]))
            {
                if(BTMDATA_isBLETransparentServiceConnected())
                    BT_SendSPPAllData(BT_CmdBuffer, (uint16_t)BT_CmdDecodeCmdLength, BTMDATA_GetSPPiAPChannelIndex(), (0-BT_CmdDecodeChecksum));
            }
        }
		else
		{
            if(filterEventForwardToDemoApp( BT_CmdBuffer[0] ))
            {
                if(BTMDATA_isBLETransparentServiceConnected())
                    BT_SendSPPAllData(BT_CmdBuffer, (uint16_t)BT_CmdDecodeCmdLength, BTMDATA_GetSPPiAPChannelIndex(), (0-BT_CmdDecodeChecksum));
            }
		}
    }
#endif
    
    switch(BT_CmdBuffer[0])
    {
        case ACK:
            BT_UpdateAckStatusWhenReceived(BT_CmdBuffer[1],BT_CmdBuffer[2]);
            break;
            
        case DEVICE_STATE:
            
            switch(BT_CmdBuffer[1])
            {
                //power on, power off, standby etc.
                case BT_OFF:        //power off state
                    BTAPP_EventHandler( BT_EVENT_SYS_POWER_OFF, 0, 0 );
                    break;
                case BT_ON:         //power on state
                    BTAPP_EventHandler( BT_EVENT_SYS_POWER_ON, 0, 0 );
                    break;
                case BT_STANDBY:     //standby state
                    BTAPP_EventHandler(BT_EVENT_SYS_STANDBY, 0, 0 );
                    break;
                case BT_DISCOVERABLE:       //pairing state
                    BTAPP_EventHandler(BT_EVENT_SYS_PAIRING_START, 0, 0 );
                    break;
                case BT_PAIRING_COMPLETE:       //pairing ok
                    BTAPP_EventHandler(BT_EVENT_SYS_PAIRING_OK, 0, 0 );
                    break;
                case BT_PAIRING_FAIL:           //pairing failed
                    BTAPP_EventHandler(BT_EVENT_SYS_PAIRING_FAILED, 0, 0 );
                    break;

                    //HFP
                case BT_HFP_CONNECTED:
                    BTMHFP_EventHandler( BT_EVENT_HFP_CONNECTED, &BT_CmdBuffer[1], BT_CmdDecodeCmdLength - 1 );
                    break;
                case BT_HFP_DISCONNECTED:
                    BTMHFP_EventHandler( BT_EVENT_HFP_DISCONNECTED, &BT_CmdBuffer[1], BT_CmdDecodeCmdLength - 1 );
                    break;
                    
                    //spp,iap etc
                case BT_SPP_CONNECTED:
                    BTMDATA_EventHandler( BT_EVENT_SPP_CONNECTED, &BT_CmdBuffer[1], BT_CmdDecodeCmdLength - 1 );
                    break;
                case BT_iAP_CONNECTED:
                    BTMDATA_EventHandler( BT_EVENT_IAP_CONNETED, &BT_CmdBuffer[1], BT_CmdDecodeCmdLength - 1 );
                    break;
                case BT_SPP_DISCONNECTED:
                    BTMDATA_EventHandler( BT_EVENT_SPP_IAP_DISCONNECTED, &BT_CmdBuffer[1], BT_CmdDecodeCmdLength - 1 );
                    break;
                case BT_SPP_REJECTED:
                    BTMDATA_EventHandler( BT_EVENT_SPP_IAP_REJECTED, &BT_CmdBuffer[1], BT_CmdDecodeCmdLength - 1 );
                    break;
                    
                    //a2dp etc
                case BT_A2DP_CONNECTED:
                    BTMA2DP_EventHandler( BT_EVENT_A2DP_CONNECTED, &BT_CmdBuffer[1], BT_CmdDecodeCmdLength - 1 );
                    break;
                case BT_A2DP_DISCONNECTED:
                    BTMA2DP_EventHandler(BT_EVENT_A2DP_DISCONNECTED, &BT_CmdBuffer[1], BT_CmdDecodeCmdLength - 1 );
                    break;

                    //avrcp etc
                case BT_ARVCP_CONNECTED:
                    BTMA2DP_EventHandler( BT_EVENT_AVRCP_CONNECTED, &BT_CmdBuffer[1], BT_CmdDecodeCmdLength - 1 );
                    break;
                case BT_AVRCP_DISCONNECTED:
                    BTMA2DP_EventHandler( BT_EVENT_AVRCP_DISCONNECTED, &BT_CmdBuffer[1], BT_CmdDecodeCmdLength - 1 );
                    break;
            }
            break;

        case BTM_UTILITY_REQ:
            
            switch(BT_CmdBuffer[1])
            {
                case BTM_CONTROL_AMP:
                    break;
                case BTM_REPORT_LINE_IN_STATUS:
                    BTM_LINE_IN_EventHandler( BT_EVENT_LINE_IN_STATUS, &BT_CmdBuffer[1], BT_CmdDecodeCmdLength - 1 );
                    break;
                case BTM_NOTIFY_HANDLE_BTM:
                    break;
                case BTM_NOTIFY_EEPROM_UPDATE_FINISH:
                    break;
                case BTM_REPORT_CODEC_STATUS:
                    BTMA2DP_EventHandler( BT_EVENT_A2DP_STATUS, &BT_CmdBuffer[1], BT_CmdDecodeCmdLength - 1 );
                    break;
                case NSPK_SYNC_POWER_OFF:
                    BTAPP_EventHandler(BT_EVENT_MSPK__SYNC_POWER_OFF,0, 0 );
                    break;
                case NSPK_SYNC_VOLUME_CTRL:
                    BTVOL_EventHandler( NSPK_EVENT_SYNC_VOL_CTRL, &BT_CmdBuffer[1], BT_CmdDecodeCmdLength - 1 );
                    break;
                case NSPK_SYNC_INTERNAL_GAIN:
                    BTVOL_EventHandler( NSPK_EVENT_SYNC_INTERNAL_GAIN, &BT_CmdBuffer[1], BT_CmdDecodeCmdLength - 1 );
                    break;
                case NSPK_SYNC_A2DP_ABS_VOL:
                    BTVOL_EventHandler( NSPK_EVENT_SYNC_ABS_VOL, &BT_CmdBuffer[1], BT_CmdDecodeCmdLength - 1 );
                    break;
                case NSPK_SYNC_CURRENT_CHANNEL_SETTING:
                    BTMSPK_EventHandler(BT_EVENT_NSPK_AUDIO_CHANNEL, &BT_CmdBuffer[1], BT_CmdDecodeCmdLength - 1 );
                    break;
                case NSPK_NOTIFY_POWER_SYNCED:
                    break;
                case NSPK_NOTIFY_COMMAND_SUCCESS:
                    break;
                case NSPK_NOTIFY_COMMAND_FAIL:
                    break;
                case NSPK_NOTIFY_SLAVE_STATUS_CHANGED:
                    break;
                case NSPK_NOTIFY_ADD_THIRD_SPEAKER:
                    BTMSPK_EventHandler( NSPK_EVENT_ADD_SPEAKER3, &BT_CmdBuffer[1], BT_CmdDecodeCmdLength - 1 );
                    break;
            }
            break;
        
        case CALL_STATUS:
            BTMHFP_EventHandler( BT_EVENT_CALL_STATUS_CHANGED, &BT_CmdBuffer[1], BT_CmdDecodeCmdLength - 1 );
            break;
            
        case REPORT_nSPK_STATUS:
            BTMSPK_EventHandler( BT_EVENT_NSPK_STATUS, &BT_CmdBuffer[1], BT_CmdDecodeCmdLength - 1 );
            break;
        
        case REPORT_nSPK_EXCHANGE_LINK_INFO:        //new added for exchange customer model information
            BTAPP_EventHandler( BT_EVENT_EXCHANGE_CUSTOMER_INFO, &BT_CmdBuffer[1], BT_CmdDecodeCmdLength - 1 );
            break;
            
        case REPORT_LINK_BACK_STATUS:
            
            if(BT_CmdBuffer[1] == 0 )       //ACL link-back
            {
                if(BT_CmdBuffer[2] == 0xFF)     //00 FF: ACL failed
                {
                    BTAPP_EventHandler(BT_EVENT_LINKBACK_FAILED, 0, 0 );
                }
                else
                {
                    BTAPP_EventHandler(BT_EVENT_LINKBACK_SUCCESS, 0, 0 );
                }
            }
            else
            {
                
            }
            break;
        
        case REPORT_LOCAL_BD_ADDR:            
            BTAPP_EventHandler(BT_EVENT_BD_ADDR_RECEIVED, &BT_CmdBuffer[1], BT_CmdDecodeCmdLength - 1 );
            break;
		case REPORT_LOCAL_DEVICE_NAME:
            BTAPP_EventHandler(BT_EVENT_NAME_RECEIVED, &BT_CmdBuffer[1], BT_CmdDecodeCmdLength - 1 );
			break;
        case REPORT_PAIRING_RECORD:
            BTAPP_EventHandler(BT_EVENT_PAIR_RECORD_RECEIVED, &BT_CmdBuffer[1], BT_CmdDecodeCmdLength - 1 );
            break;

        case VOLUME_LEVEL:              //0x0f command: HFP Gain Level
            BTVOL_EventHandler( BT_EVENT_HFP_VOLUME_CHANGED, &BT_CmdBuffer[1], BT_CmdDecodeCmdLength - 1 );
            break;
            
        case REPORT_AVRCP_VOL_CTRL:     //0x26 command
            BTVOL_EventHandler( BT_EVENT_AVRCP_VOLUME_CTRL, &BT_CmdBuffer[1], BT_CmdDecodeCmdLength - 1 );
            break;
            
        case REPORT_AVRCP_ABS_VOL_CTRL: //0x29 command
            BTVOL_EventHandler( BT_EVENT_AVRCP_ABS_VOLUME_CHANGED, &BT_CmdBuffer[1], BT_CmdDecodeCmdLength - 1 );
            break;

        case REPORT_TYPE_CODEC:
            BTMA2DP_EventHandler( BT_EVENT_SAMPLINGRATE_CHANGED, &BT_CmdBuffer[1], BT_CmdDecodeCmdLength - 1 );
            BTAPP_EventHandler(BT_EVENT_REPORT_TYPE_CODEC, &BT_CmdBuffer[1], BT_CmdDecodeCmdLength - 1 );
            break;
            
        case AVRCP_SPEC_RSP:
            BTMA2DP_EventHandler( BT_EVENT_PLAYBACK_STATUS_CHANGED, &BT_CmdBuffer[1], BT_CmdDecodeCmdLength - 1 );
            break;
                        
        case REPORT_SPP_DATA:
            BTMDATA_Handler( &BT_CmdBuffer[1], BT_CmdDecodeCmdLength - 1 );
            break;
        
        case REPORT_CUSTOMER_GATT_ATTRIBUTE_DATA:
            BTMDATA_GATT_AttributeHandler(BT_CmdBuffer[3], &BT_CmdBuffer[4], BT_CmdDecodeCmdLength-4);
            break;
            
        case REPORT_LINK_MODE:
            BTAPP_EventHandler(BT_EVENT_LINK_MODE_RECEIVED, &BT_CmdBuffer[1], BT_CmdDecodeCmdLength - 1 );
            break;

        case REPORT_LE_EVENT:
            BTMDATA_EventHandler( LE_STATUS_CHANGED, &BT_CmdBuffer[1], BT_CmdDecodeCmdLength - 1 );
            break;
        
        case REPORT_INPUT_SIGNAL_LEVEL:
            BTAPP_EventHandler(BT_EVENT_PORT_INPUT_CHANGED, &BT_CmdBuffer[1], BT_CmdDecodeCmdLength - 1 );
            break;
            
        case REPORT_nSPK_VENDOR_EVENT:
			BTAPP_EventHandler(BT_EVENT_NSPK_VENDOR_CMD, &BT_CmdBuffer[1], BT_CmdDecodeCmdLength - 1 );			
			break;        
            
        case REPORT_BT_CLK:
            BTAPP_EventHandler(BT_EVENT_CLK_REPORTED, &BT_CmdBuffer[1], BT_CmdDecodeCmdLength - 1 );
            break;
        
        case REPORT_VENDOR_EEPROM:
            BTAPP_EventHandler(BT_EVENT_READ_EEPROM_OK, &BT_CmdBuffer[1], BT_CmdDecodeCmdLength-1 );
            break;
        
        case BTM_VERSION:
            BTAPP_EventHandler(BT_EVENT_BTM_VERSION, &BT_CmdBuffer[1], BT_CmdDecodeCmdLength-1 );
            break;
        
        case BATTERY_LEVEL:
            BTAPP_EventHandler(BT_EVENT_BATTERY_LEVEL, &BT_CmdBuffer[1], BT_CmdDecodeCmdLength-1 );
            break;
        
        case REPORT_FEATURE_LIST:
            BTAPP_EventHandler(BT_EVENT_FEATURE_LIST_RECEIVED, &BT_CmdBuffer[1], BT_CmdDecodeCmdLength-1 );
            break;
        
        case REPORT_BTM_INITIAL_STATUS:
            BTAPP_EventHandler(BT_EVENT_BTM_INITIALIZED, &BT_CmdBuffer[1], BT_CmdDecodeCmdLength-1 );
            break;
            
        default:
            //BT_SendAckToEvent(BT_CmdBuffer[0]);     //send ACK to this event
            break;
    }
}

/*-----------------------------------------------------------------------------*/
#ifdef BT_UART_RX_BYTE_MODEL
extern DRV_HANDLE UART_Handle;
void BT_CommandDecode_AddByteToBuffer()
{
    if(UR_RxBufStatus != TXRX_BUF_FULL)
    {
        UR_RxBuf[UR_RxBufHead++] = DRV_USART_ReadByte( UART_Handle );//DRV_USART0_ReadByte();
	if(UR_RxBufHead >= UR_RX_BUF_SIZE)
            UR_RxBufHead = 0;
	if( UR_RxBufHead == UR_RxBufTail )
            UR_RxBufStatus = TXRX_BUF_FULL;
    }
}
#endif

/*-----------------------------------------------------------------------------*/
bool ParsePayloadAsCommand(uint8_t* command, uint8_t length)
{
    bool parse_result = true;
    bool parse_ended = false;
    RX_DECODE_MODE parse_state = RX_DECODE_CMD_SYNC_AA;
    uint8_t parse_checksum;
    uint16_t parse_data_len;
    uint8_t current_byte;

    while (length) {
        current_byte = *command++;
        length --;

        switch (parse_state) {
            case RX_DECODE_CMD_SYNC_AA:
                if (current_byte == 0xaa)
                    parse_state = RX_DECODE_CMD_LENGTH_00;
                else
                    parse_result = false;           //sync byte is not correct
                break;

            case RX_DECODE_CMD_LENGTH_00:
                 parse_data_len = (uint16_t)current_byte; 
                 parse_checksum = current_byte;     //checksum calculation start!
                 parse_state = RX_DECODE_CMD_LENGTH;
                //if (current_byte == 0x00)
                //    parse_state = RX_DECODE_CMD_LENGTH;
                //else
                //    parse_result = false;           //second byte is not correct
                break;

            case RX_DECODE_CMD_LENGTH:
                parse_checksum += current_byte; //checksum calculation start!
                parse_data_len += (uint16_t)current_byte; //save bytes number, use to check where is command end
                if( (parse_data_len+1) == length )
                    parse_state = RX_DECODE_CMD_DATA; //next state
                else
                    parse_result = false;           //length is not correct
                break;

            case RX_DECODE_CMD_DATA:
                parse_checksum += current_byte;
                parse_data_len--;
                if (parse_data_len == 0)                   //no data remained?
                    parse_state = RX_DECODE_CMD_CHECKSUM; //yes, next mode: checksum
                break;

            case RX_DECODE_CMD_CHECKSUM:
                if ((uint8_t)(parse_checksum + current_byte) == 0) {
                    parse_ended = true;
                } else {
                    parse_result = false;           //checksum is not correct
                }
                break;
            default:
                break;
        }

        if (parse_ended) {
            break;          //command parse is ended
        }
        if(parse_result == false) {
            break;          //command parse is terminated because error is found
        }
    }
    return parse_result;
}
