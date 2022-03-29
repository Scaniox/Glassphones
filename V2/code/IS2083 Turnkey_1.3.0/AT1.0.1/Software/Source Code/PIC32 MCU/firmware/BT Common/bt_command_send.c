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
#include "bt_command_send.h"
#include "bt_command_decode.h"
#include "bt_data.h"
#ifdef _OTA_SUPPORT
#include "bt_OTA_DFU.h"
#include "LED.h"
#endif

enum {
    ACK_STS_OK,
    ACK_DISALLOWED,
    ACK_COMMAND_UNKNOW,
    ACK_PARA_ERROR,
    ACK_BTM_BUSY,
    ACK_OUT_OF_MEMORY,
};  //Command ACK status

static struct {
    uint8_t SendingCmdNum;
    struct{
        uint16_t startBufPt;
        uint16_t endBufPt;
        uint16_t cmdSize;
        uint8_t cmdID;
        CMD_PROCESSING_STATUS cmdStatus;
    } SendingCmdArray[QUEQUED_CMD_MAX];
} BT_SendingCmd;


static uint8_t          UR_TxBuf[UR_TX_BUF_SIZE];
static uint16_t         UR_TxBufHead;
static uint16_t         UR_TxBufTail;
static uint16_t         UR_TxBufTail2;
static uint16_t         UR_TxBufEnd;
typedef enum {
	TXRX_BUF_EMPTY,
	TXRX_BUF_OK,
	TXRX_BUF_FULL
} TX_BUF_STATUS;
static TX_BUF_STATUS  UR_TxBufStatus;

static struct {
    uint8_t SendingAckNum;
    uint8_t AckData[6];
    uint8_t AckEventID[QUEQUED_ACK_MAX];
    uint8_t head;
    uint8_t tail;
    uint8_t txIndex;
    struct {
        uint8_t AckDataSendingFlag      : 1;
        uint8_t lock                    : 1;
    };
} BT_SendingAck;

typedef enum {
    BT_CMD_SEND_STATE_IDLE = 0,         //no data in the queue, MFB is low
    BT_CMD_SEND_MFB_HIGH_WAITING,       //set MFB to high, and wait for 2ms
    BT_CMD_SEND_DATA_SENDING,           //UART interface is working
    BT_CMD_SEND_ACK_WAITING,        //new...waiting for ack
    BT_CMD_SEND_ACK_ERROR,
    BT_CMD_SEND_ACK_OK,
} BT_CMD_SEND_STATE;
BT_CMD_SEND_STATE BT_CMD_SendState;
uint16_t BT_CommandSendTimer;
#ifdef _OTA_SUPPORT
bool flg_enteredOTA = false;
#endif
static bool StartRegisterNewCommand(uint16_t start_index, uint16_t cmd_size, uint8_t cmd_id);
static bool EndRegisterNewCommand(uint16_t end_index);
static bool RemoveFirstCommand(void);
/*======================================*/
/*  function implemention  */
/*======================================*/
void BT_GiveUpThisCommand( void )
{
    RemoveFirstCommand();
}

/*------------------------------------------------------------*/
static bool copyDataToBufferAndRegisterCommand(uint8_t* data, uint16_t size)
{
    bool buf_result = true;
    uint8_t ur_tx_buf_status_save = UR_TxBufStatus;
    uint16_t ur_tx_buf_head_save = UR_TxBufHead;

    if(UR_TxBufStatus !=  TXRX_BUF_FULL)
    {
        if(!StartRegisterNewCommand(UR_TxBufHead, size, data[3]))
        {
            return false;
        }
        
        while(size--)
        {
            UR_TxBuf[UR_TxBufHead++] = *data++;

            if(UR_TxBufHead >= UR_TX_BUF_SIZE)
                UR_TxBufHead = 0;

            if(UR_TxBufHead ==  UR_TxBufTail)
            {
                if(size)
                {
                    buf_result = false;
                    UR_TxBufStatus = ur_tx_buf_status_save;		//restore in this case
                    UR_TxBufHead = ur_tx_buf_head_save;                 //restore in this case
                }
                else
                {
                    UR_TxBufStatus =  TXRX_BUF_FULL;            //test this code
                }
                break;
            }
            else
            {
                UR_TxBufStatus = TXRX_BUF_OK;
            }
        }

        if(buf_result)
        {
            EndRegisterNewCommand(UR_TxBufHead);
        }
    }
    else
    {
        buf_result = false;
    }
    return buf_result;
}

/*------------------------------------------------------------*/
static bool copyDataToBuffer(uint8_t* data, uint16_t size)
{
    bool buf_result = true;
    uint8_t ur_tx_buf_status_save = UR_TxBufStatus;
    uint16_t ur_tx_buf_head_save = UR_TxBufHead;

    if(UR_TxBufStatus !=  TXRX_BUF_FULL)
    {
        while(size--)
        {
            UR_TxBuf[UR_TxBufHead++] = *data++;

            if(UR_TxBufHead >= UR_TX_BUF_SIZE)
                UR_TxBufHead = 0;

            if(UR_TxBufHead ==  UR_TxBufTail)
            {
                if(size)
                {
                    buf_result = false;
                    UR_TxBufStatus = ur_tx_buf_status_save;		//restore in this case
                    UR_TxBufHead = ur_tx_buf_head_save;                 //restore in this case
                }
                else
                {
                    UR_TxBufStatus =  TXRX_BUF_FULL;            //test this code
                }
                break;
            }
            else
            {
                UR_TxBufStatus = TXRX_BUF_OK;
            }
        }
    }
    else
    {
        buf_result = false;
    }
    return buf_result;
}

/*------------------------------------------------------------*/
static uint8_t calculateChecksum(uint8_t* startByte, uint8_t* endByte)
{
    uint8_t checksum = 0;
    while(startByte <= endByte)
    {
        checksum += *startByte;
        startByte++;
    }
    checksum = ~checksum + 1;
    return checksum;
}

/*------------------------------------------------------------*/
static uint8_t continueChecksum(uint8_t checksum, uint8_t* startByte, uint16_t length)
{
    while(length)
    {
        checksum += *startByte++;
        length--;
    }
    return checksum;
}

/*------------------------------------------------------------*/
uint8_t BT_IsCommandSendTaskIdle( void )
{
    if(BT_CMD_SendState == BT_CMD_SEND_STATE_IDLE)
        return true;
    else
        return false;
}
/*------------------------------------------------------------*/
void BT_SendBytesAsCompleteCommand(uint8_t* command, uint8_t command_length)
{
    copyDataToBufferAndRegisterCommand(command, command_length);
}

/*------------------------------------------------------------*/
void BT_SendBytesAsOneCommandWithRedoChecksum(uint8_t* command, uint8_t command_length)
{
    command[command_length-1] = calculateChecksum(&command[1], &command[command_length-2]);
    copyDataToBufferAndRegisterCommand(command, command_length);
}

#ifdef _CODE_FOR_APP
/*------------------------------------------------------------*/
//void BT_Send_EQCmd(uint8_t* eqData,uint8_t size)
void BT_SendBytesAsEQCommandWithRedoChecksum(uint8_t* eqData, uint8_t size) //special use for a whole EQ command delivering
{
	if(size >= 90)
    {
        eqData[89] = calculateChecksum(&eqData[2], &eqData[88]);
        copyDataToBufferAndRegisterCommand(eqData, 90);
    }
}
#endif
/*------------------------------------------------------------*/
void BT_SendUARTCommand(uint8_t uart_Cmd[],int len)
{
    uint8_t UartCmd[40];
    int i;
    uint16_t checksum = 0,cmdLen;

    cmdLen = len + 4;
    UartCmd[0] = 0xAA;
    UartCmd[1] = (len & 0xff00) >> 8;
    UartCmd[2] = len & 0xff;
    checksum = UartCmd[1] + UartCmd[2];
    for(i=0;i<len;i++)
    {
        UartCmd[i+3] = uart_Cmd[i];
        checksum += UartCmd[i+3];
    }
    UartCmd[i+3] = ~(checksum)+1;
    copyDataToBufferAndRegisterCommand(UartCmd,cmdLen);
}

/*------------------------------------------------------------*/
void BT_MMI_ActionCommand(uint8_t MMI_ActionCode, uint8_t link_index)
{
    uint8_t command[8];
    command[0] = 0xAA;      //header byte 0
    command[1] = 0x00;      //header byte 1
    command[2] = 0x03;      //length
    command[3] = MMI_CMD;      //command ID
    command[4] = link_index;      //link_index
    command[5] = MMI_ActionCode;
    command[6] = calculateChecksum(&command[2], &command[5]);
    copyDataToBufferAndRegisterCommand(&command[0], 7);
}

/*------------------------------------------------------------*/
void BT_MusicControlCommand(uint8_t CtrlCode, uint8_t link_index)
{
    uint8_t command[8];
    command[0] = 0xAA;      //header byte 0
    command[1] = 0x00;      //header byte 1
    command[2] = 0x03;      //length
    command[3] = MUSIC_CONTROL;      //command ID
    command[4] = link_index;      //link_index
    command[5] = CtrlCode;
    command[6] = calculateChecksum(&command[2], &command[5]);
    copyDataToBufferAndRegisterCommand(&command[0], 7);
}

/*------------------------------------------------------------*/
void BT_SendAckToEvent(uint8_t ack_event)
{
    if(BT_SendingAck.SendingAckNum < QUEQUED_ACK_MAX)
    {
        BT_SendingAck.SendingAckNum ++;
        BT_SendingAck.AckEventID[BT_SendingAck.head++] = ack_event;
        if(BT_SendingAck.head >= QUEQUED_ACK_MAX)
            BT_SendingAck.head = 0;
    }
}

/*------------------------------------------------------------*/
void BT_ReadFWVersion( void )
{
    uint8_t command[6];
    command[0] = 0xAA;
    command[1] = 0x00;
    command[2] = 0x02;
    command[3] = GET_BTM_VERSION;
    command[4] = 0x01;
    command[5] = calculateChecksum(&command[2], &command[4]);
    copyDataToBufferAndRegisterCommand(&command[0], 6);
}

/*------------------------------------------------------------*/
void BT_ReadUARTVersion( void )
{
    uint8_t command[6];
    command[0] = 0xAA;
    command[1] = 0x00;
    command[2] = 0x02;
    command[3] = GET_BTM_VERSION;
    command[4] = 0x00;
    command[5] = calculateChecksum(&command[2], &command[4]);
    copyDataToBufferAndRegisterCommand(&command[0], 6);
}

/*------------------------------------------------------------*/
void BT_ReadBTMLinkModeCommand( void )
{
    uint8_t command[6];
    command[0] = 0xAA;
    command[1] = 0x00;
    command[2] = 0x02;
    command[3] = READ_LINK_MODE;
    command[4] = 0;         //dummy byte
    command[5] = calculateChecksum(&command[2], &command[4]);
    copyDataToBufferAndRegisterCommand(&command[0], 6);
}

/*------------------------------------------------------------*/
void BT_ReadDeviceAddressCommand(void)
{
    uint8_t command[6];
    command[0] = 0xAA;                      //header byte 0
    command[1] = 0x00;                      //header byte 1
    command[2] = 0x02;                      //length
    command[3] = READ_LOCAL_BD_ADDR;         //command ID
    command[4] = 0x00;                      //dummy byte
    command[5] = calculateChecksum(&command[2], &command[4]);
    copyDataToBufferAndRegisterCommand(&command[0], 6);
}

/*------------------------------------------------------------*/
void BT_ReadNSpkStatus(void)
{
    uint8_t command[6];
    command[0] = 0xAA;                      //header byte 0
    command[1] = 0x00;                      //header byte 1
    command[2] = 0x02;                      //length
    command[3] = READ_NSPK_LINK_STATUS;    //command ID
    command[4] = 0x00;                      //dummy byte
    command[5] = calculateChecksum(&command[2], &command[4]);
    copyDataToBufferAndRegisterCommand(&command[0], 6);

}

/*------------------------------------------------------------*/
void BT_ReadDeviceNameCommand(void)
{
    uint8_t command[6];
    command[0] = 0xAA;                      //header byte 0
    command[1] = 0x00;                      //header byte 1
    command[2] = 0x02;                      //length
    command[3] = READ_LOCAL_DEVICE_NAME;    //command ID
    command[4] = 0x00;                      //dummy byte
    command[5] = calculateChecksum(&command[2], &command[4]);
    copyDataToBufferAndRegisterCommand(&command[0], 6);

}

/*------------------------------------------------------------*/
void BT_GetPairRecordCommand(void)
{
    uint8_t command[6];
    command[0] = 0xAA;                      //header byte 0
    command[1] = 0x00;                      //header byte 1
    command[2] = 0x02;                      //length
    command[3] = READ_PAIRING_RECORD;         //command ID
    command[4] = 0x00;                      //dummy byte
    command[5] = calculateChecksum(&command[2], &command[4]);
    copyDataToBufferAndRegisterCommand(&command[0], 6);
}

/*------------------------------------------------------------*/
void BT_LinkBackToLastDevice(void)
{
    uint8_t command[6];
    command[0] = 0xAA;                      //header byte 0
    command[1] = 0x00;                      //header byte 1
    command[2] = 0x02;                      //length
    command[3] = PROFILE_LINK_BACK;         //command ID
    command[4] = 0x00;                      //0x00: last device, 0x01: last HFP device, 0x02: last A2DP device
    command[5] = calculateChecksum(&command[2], &command[4]);
    copyDataToBufferAndRegisterCommand(&command[0], 6);
}

/*------------------------------------------------------------*/
void BT_LinkBackToDeviceByBTAddress(uint8_t* address)
{
    uint8_t command[14];
    command[0] = 0xAA;                      //header byte 0
    command[1] = 0x00;                      //header byte 1
    command[2] = 10;                      //length
    command[3] = PROFILE_LINK_BACK;         //command ID
    command[4] = 0x05;              //0x05: link back to device with specified address
    command[5] = 0x00;
    command[6] = 0x07;
    command[7] = *address++;        //byte 0
    command[8] = *address++;        //byte 1
    command[9] = *address++;        //byte 2
    command[10] = *address++;        //byte 3
    command[11] = *address++;        //byte 4
    command[12] = *address++;        //byte 5
    command[13] = calculateChecksum(&command[2], &command[12]);
    copyDataToBufferAndRegisterCommand(&command[0], 14);
}

/*------------------------------------------------------------*/
void BT_LinkBackToDeviceA2DPByBTAddress(uint8_t* address)
{
    uint8_t command[14];
    command[0] = 0xAA;                      //header byte 0
    command[1] = 0x00;                      //header byte 1
    command[2] = 10;                      //length
    command[3] = PROFILE_LINK_BACK;         //command ID
    command[4] = 0x05;              //0x05: link back to device with specified address
    command[5] = 0x00;
    command[6] = 0x04;
    command[7] = *address++;        //byte 0
    command[8] = *address++;        //byte 1
    command[9] = *address++;        //byte 2
    command[10] = *address++;        //byte 3
    command[11] = *address++;        //byte 4
    command[12] = *address++;        //byte 5
    command[13] = calculateChecksum(&command[2], &command[12]);
    copyDataToBufferAndRegisterCommand(&command[0], 14);
}

/*------------------------------------------------------------*/
void BT_DisconnectAllProfile(void)
{
    uint8_t command[6];
    command[0] = 0xAA;                      //header byte 0
    command[1] = 0x00;                      //header byte 1
    command[2] = 0x02;                      //length
    command[3] = DISCONNECT;                //command ID
    command[4] = 0x0f;                      //event to ack
    command[5] = calculateChecksum(&command[2], &command[4]);
    copyDataToBufferAndRegisterCommand(&command[0], 6);
}
void BT_DisconnectAllProfileExceptSPP(void)
{
    uint8_t command[6];
    command[0] = 0xAA;                      //header byte 0
    command[1] = 0x00;                      //header byte 1
    command[2] = 0x02;                      //length
    command[3] = DISCONNECT;                //command ID
    command[4] = 0x07;                      //event to ack
    command[5] = calculateChecksum(&command[2], &command[4]);
    copyDataToBufferAndRegisterCommand(&command[0], 6);
}

/*------------------------------------------------------------*/
void BT_DisconnectSPPProfile(void)
{
    uint8_t command[6];
#ifdef _OTA_SUPPORT
    if( flg_enteredOTA == true)
        return;
#endif
    command[0] = 0xAA;                      //header byte 0
    command[1] = 0x00;                      //header byte 1
    command[2] = 0x02;                      //length
    command[3] = DISCONNECT;                //command ID
    command[4] = 0x08;                      //event to ack
    command[5] = calculateChecksum(&command[2], &command[4]);
    copyDataToBufferAndRegisterCommand(&command[0], 6);
}

/*------------------------------------------------------------*/
void BT_DisconnectHFPProfile(void)
{
    uint8_t command[6];
    command[0] = 0xAA;                      //header byte 0
    command[1] = 0x00;                      //header byte 1
    command[2] = 0x02;                      //length
    command[3] = DISCONNECT;                //command ID
    command[4] = 0x02;                      //event to ack
    command[5] = calculateChecksum(&command[2], &command[4]);
    copyDataToBufferAndRegisterCommand(&command[0], 6);
}

/*------------------------------------------------------------*/
void BT_DisconnectA2DPProfile(void)
{
    uint8_t command[6];
    command[0] = 0xAA;                      //header byte 0
    command[1] = 0x00;                      //header byte 1
    command[2] = 0x02;                      //length
    command[3] = DISCONNECT;                //command ID
    command[4] = 0x04;                      //event to ack
    command[5] = calculateChecksum(&command[2], &command[4]);
    copyDataToBufferAndRegisterCommand(&command[0], 6);
}
/*------------------------------------------------------------*/
#ifdef _OTA_SUPPORT
void BT_EnterOTA(void)
{
    uint8_t command[8];
    //1. support SPP, iAP only
    command[0] = 0xAA;                      //header byte 0
    command[1] = 0x00;                      //header byte 1
    command[2] = 0x03;                      //length
    command[3] = SET_BTM_PARA;              //command ID
    command[4] = 0x04;                      //Set supported profile
    command[5] = 0x60;                      //SPP and iAP only
    command[6] = calculateChecksum(&command[1], &command[5]);
    copyDataToBufferAndRegisterCommand(&command[0], 7);

    //2. exit pairing, if any
    if( BTAPP_GetParingStatus() )
    {
	    command[0] = 0xAA;						//header byte 0
	    command[1] = 0x00;						//header byte 1
	    command[2] = 0x03;						//length
	    command[3] = MMI_CMD;				    //command ID
	    command[4] = 0x00;						//Set supported profile
	    command[5] = 0x6B;						//Exit pairing mode
	    command[6] = calculateChecksum(&command[1], &command[5]);
	    copyDataToBufferAndRegisterCommand(&command[0], 7);
        
        //TURN OFF the pairing LED
        Set_LED_Style(LED_1, LED_OFF, 500, 500);
	}
    //3. force btm into non-connectable mode but keeping current connection
    command[0] = 0xAA;						//header byte 0
	command[1] = 0x00;						//header byte 1
	command[2] = 0x03;						//length
	command[3] = BTM_UTILITY_FUNCTION;		//command ID
	command[4] = 0x03;						//BTM mode setting.
	command[5] = 0x00;						//force BTM into non-connectable mode
	command[6] = calculateChecksum(&command[1], &command[5]);
	copyDataToBufferAndRegisterCommand(&command[0], 7);
    //4. disable BLE adv
    command[0] = 0xAA;						//header byte 0
	command[1] = 0x00;						//header byte 1
	command[2] = 0x03;						//length
	command[3] = SET_BTM_PARA;		        //command ID
	command[4] = 0x02;						//BTM mode setting.
	command[5] = 0x00;						//BTM standby mode disable & disable BLE adv
	command[6] = calculateChecksum(&command[1], &command[5]);
	copyDataToBufferAndRegisterCommand(&command[0], 7);
    //5. disconnect hfp, if any
    if( BTMHFP_GetHFPLinkStatus( BTMHFP_GetDatabaseIndex() ) )
        BT_DisconnectHFPProfile();
    //6. disconnect A2DP, if any
    if( BTMA2DP_getA2DPLinkStatus(BTMA2DP_getActiveDatabaseIndex()) )
        BT_DisconnectA2DPProfile();

    flg_enteredOTA = true;
}
void BT_ExitOTA(void)
{
    uint8_t command[8];

    if( flg_enteredOTA == false)
        return;
    
    //1. support all profiles
    command[0] = 0xAA;                      //header byte 0
    command[1] = 0x00;                      //header byte 1
    command[2] = 0x03;                      //length
    command[3] = SET_BTM_PARA;              //command ID
    command[4] = 0x04;                      //Set supported profile
    command[5] = 0x7F;                      //all profile
    command[6] = calculateChecksum(&command[1], &command[5]);
    copyDataToBufferAndRegisterCommand(&command[0], 7);
    //3. force btm into connectable mode
    command[0] = 0xAA;						//header byte 0
	command[1] = 0x00;						//header byte 1
	command[2] = 0x03;						//length
	command[3] = BTM_UTILITY_FUNCTION;		//command ID
	command[4] = 0x03;						//BTM mode setting.
	command[5] = 0x01;						//force BTM into connectable mode
	command[6] = calculateChecksum(&command[1], &command[5]);
	copyDataToBufferAndRegisterCommand(&command[0], 7);
    //4. enable BLE adv
    command[0] = 0xAA;						//header byte 0
	command[1] = 0x00;						//header byte 1
	command[2] = 0x03;						//length
	command[3] = SET_BTM_PARA;		        //command ID
	command[4] = 0x02;						//BTM mode setting.
	command[5] = 0x01;						//BTM standby mode eanble & enable BLE adv
	command[6] = calculateChecksum(&command[1], &command[5]);
	copyDataToBufferAndRegisterCommand(&command[0], 7);

	flg_enteredOTA = false;

    //?force the FSM to exit
	ota_dfu_state = OTA_ERROR;
}
#endif

/*------------------------------------------------------------*/
void BT_SetOverallGain(uint8_t gain1, uint8_t gain2, uint8_t gain3, uint8_t link_index)
{
    uint8_t command[11];
    command[0] = 0xAA;                      //header byte 0
    command[1] = 0x00;                      //header byte 1
    command[2] = 0x07; //lengthcommand[2] = 0x07;                    //length
    command[3] = SET_OVERALL_GAIN;                //command ID
    command[4] = link_index;                      //link index
    command[5] = 0x00;                      //mask bits
    command[6] = 0x05;                      //type
    command[7] = gain1 & 0x7f;
    command[8] = gain2 & 0x7f;
    command[9] = gain3 & 0x7f;
    command[10] = calculateChecksum(&command[2], &command[9]);
    copyDataToBufferAndRegisterCommand(&command[0], 11);
}

/*------------------------------------------------------------*/
void BT_updateA2DPGain(uint8_t gain, uint8_t link_index)
{
    uint8_t command[11];
    command[0] = 0xAA;                      //header byte 0
    command[1] = 0x00;                      //header byte 1
    command[2] = 0x07; //lengthcommand[2] = 0x07;                    //length
    command[3] = SET_OVERALL_GAIN;                //command ID
    command[4] = link_index;                      //link index
    command[5] = 0x01;                      //mask bits
    command[6] = 0x04;                      //type
    command[7] = gain & 0x7f;
    command[8] = 0;
    command[9] = 0;
    command[10] = calculateChecksum(&command[2], &command[9]);
    copyDataToBufferAndRegisterCommand(&command[0], 11);
}

/*------------------------------------------------------------*/
void BT_updateHFPGain(uint8_t gain, uint8_t link_index)
{
    uint8_t command[11];
    command[0] = 0xAA;                      //header byte 0
    command[1] = 0x00;                      //header byte 1
    command[2] = 0x07;                    //length
    command[3] = SET_OVERALL_GAIN;                //command ID
    command[4] = link_index;                      //link index
    command[5] = 0x02;                      //mask bits
    command[6] = 0x03;                      //type
    command[7] = 0;
    command[8] = gain & 0x0f;
    command[9] = 0;
    command[10] = calculateChecksum(&command[2], &command[9]);
    copyDataToBufferAndRegisterCommand(&command[0], 11);
}

/*------------------------------------------------------------*/
void BT_updateLineInGain(uint8_t gain, uint8_t link_index)
{
    uint8_t command[11];
    command[0] = 0xAA;                      //header byte 0
    command[1] = 0x00;                      //header byte 1
    command[2] = 0x07;                    //length
    command[3] = SET_OVERALL_GAIN;                //command ID
    command[4] = link_index;                      //link index
    command[5] = 0x04;                      //mask bits
    command[6] = 0x03;                      //type
    command[7] = 0;
    command[8] = 0;
    command[9] = gain & 0x0f;
    command[10] = calculateChecksum(&command[2], &command[9]);
    copyDataToBufferAndRegisterCommand(&command[0], 11);
}

/*------------------------------------------------------------*/
void BT_SendSPPData(uint8_t* addr, uint16_t size, uint8_t link_index)
{
    uint8_t command[11];
    uint8_t checksum = 0;
    uint16_t cmd_length = size + 7;
    command[0] = 0xAA;                      //header byte 0
    command[1] = (uint8_t)(cmd_length>>8);                 //header byte 1
    command[2] = (uint8_t)(cmd_length&0xff);                      //length
    command[3] = SEND_SPP_DATA;             //command ID
    command[4] = link_index;                      //link_index, set to 0
    command[5] = 0x00;          //single packet format
    //total_length: 2byte
    command[6] = (uint8_t)(size>>8);
    command[7]= (uint8_t)(size&0xff);
    //payload_length: 2byte
    command[8] = (uint8_t)(size>>8);
    command[9] = (uint8_t)(size&0xff);
    if(!StartRegisterNewCommand(UR_TxBufHead, cmd_length+4, SEND_SPP_DATA))
        return;
    copyDataToBuffer(&command[0], 10);
    checksum = continueChecksum(checksum, &command[1], 9);
    copyDataToBuffer(addr, size);
    checksum = continueChecksum(checksum, addr, size);
    checksum = ~checksum + 1;
    copyDataToBuffer(&checksum, 1);
    EndRegisterNewCommand(UR_TxBufHead);
}

/*------------------------------------------------------------*/
void BT_LoopBackSPPData(uint8_t* addr, uint16_t total_command_size)
{
    uint8_t command[11];
    uint8_t checksum = 0;
    uint16_t cmd_length = total_command_size+1;
    command[0] = 0xAA;                                  //header byte 0
    command[1] = (uint8_t)(cmd_length>>8);                 //header byte 1(length high byte)
    command[2] = (uint8_t)(cmd_length&0xff);                      //length(length low byte)
    command[3] = SEND_SPP_DATA;             //command ID
    if(!StartRegisterNewCommand(UR_TxBufHead, cmd_length+4, SEND_SPP_DATA))
        return;
    copyDataToBuffer(&command[0], 4);
    checksum = continueChecksum(checksum, &command[1], 3);
    //total_command_size -= 1;
    copyDataToBuffer(addr, total_command_size);
    checksum = continueChecksum(checksum, addr, total_command_size);
    checksum = ~checksum + 1;
    copyDataToBuffer(&checksum, 1);
    EndRegisterNewCommand(UR_TxBufHead);
}

/*------------------------------------------------------------*/
void BT_SendSPPAllData(uint8_t* addr, uint16_t size, uint8_t link_index, uint8_t all_data_checksum)
{
    uint8_t command[13];
    uint8_t checksum = 0;
    uint16_t total_data_size = size + 4;
    uint16_t cmd_length = total_data_size + 7;
    command[0] = 0xAA;                      //header byte 0
    command[1] = (uint8_t)(cmd_length>>8);                 //header byte 1
    command[2] = (uint8_t)(cmd_length&0xff);                      //length
    command[3] = SEND_SPP_DATA;             //command ID
    command[4] = link_index;                      //link_index, set to 0
    command[5] = 0x00;          //single packet format
    //total_length: 2byte
    command[6] = (uint8_t)(total_data_size>>8);
    command[7]= (uint8_t)(total_data_size&0xff);
    //payload_length: 2byte
    command[8] = (uint8_t)(total_data_size>>8);
    command[9] = (uint8_t)(total_data_size&0xff);
    command[10] = 0xAA;
    command[11] = 0x00;
    command[12] = size;
    if(!StartRegisterNewCommand(UR_TxBufHead, cmd_length+4, SEND_SPP_DATA))
        return;
    copyDataToBuffer(&command[0], 13);
    checksum = continueChecksum(checksum, &command[1], 12);
    copyDataToBuffer(addr, size);
    checksum = continueChecksum(checksum, addr, size);
    copyDataToBuffer(&all_data_checksum, 1);
    command[0] = all_data_checksum;
    checksum = continueChecksum(checksum, &command[0], 1);
    checksum = ~checksum + 1;
    copyDataToBuffer(&checksum, 1);
    EndRegisterNewCommand(UR_TxBufHead);
}

/*------------------------------------------------------------*/
void BT_SetupBTMGPIO( void )
{
    uint8_t command[20];
    command[0] = 0xAA;                      //header byte 0
    command[1] = 0x00;                      //header byte 1
    command[2] = 13;                        //length
    command[3] = GPIO_CTRL;                //command ID
    command[4] = 0xFF;                      //IO_Ctrl_Mask_P0,
    command[5] = 0xDF;                      //IO_Ctrl_Mask_P1,
    command[6] = 0xFF;                      //IO_Ctrl_Mask_P2,
    command[7] = 0xBF;                      //IO_Ctrl_Mask_P3,
    command[8] = 0x00;                      //IO_Setting_P0,
    command[9] = 0x00;                      //IO_Setting_P1,
    command[10] = 0x00;                     //IO_Setting_P2,
    command[11] = 0x00;                     //IO_Setting_P3,
    command[12] = 0x00;                     //Output_Value_P0,
    command[13] = 0x00;                     //Output_Value_P1,
    command[14] = 0x00;                     //Output_Value_P2,
    command[15] = 0x00;                     //Output_Value_P3,
    command[16] = calculateChecksum(&command[2], &command[15]);
    copyDataToBufferAndRegisterCommand(&command[0], 17);
}

/*------------------------------------------------------------*/
void BT_EnterLineInMode(uint8_t disable0_enable1, uint8_t analog0_I2S1)
{
    uint8_t command[10];
    command[0] = 0xAA;                      //header byte 0
    command[1] = 0x00;                      //header byte 1
    command[2] = 3;                        //length
    command[3] = BTM_UTILITY_FUNCTION;                //command ID
    command[4] = 1;                         //utility_function_type=0x01
    if(analog0_I2S1)
    {
        if(disable0_enable1)
            command[5] = 3;
        else
            command[5] = 2;
    }
    else
    {
        if(disable0_enable1)
            command[5] = 1;
        else
            command[5] = 0;
    }
    command[6] = calculateChecksum(&command[2], &command[5]);
    copyDataToBufferAndRegisterCommand(&command[0], 7);
}

/*------------------------------------------------------------*/

void BT_SetStereoModeAudioChannel(uint8_t audio_channel)
{
    uint8_t command[10];
    command[0] = 0xAA;                      //header byte 0
    command[1] = 0x00;                      //header byte 1
    command[2] = 3;                        //length
    command[3] = BTM_UTILITY_FUNCTION;                //command ID
    command[4] = 0x0C;                         //utility_function_type
    command[5] = audio_channel;
    command[6] = calculateChecksum(&command[2], &command[5]);
    copyDataToBufferAndRegisterCommand(&command[0], 7);
}

/*------------------------------------------------------------*/
void BT_SetRXBufferSize( void )
{
    uint8_t command[10];
    command[0] = 0xAA;                      //header byte 0
    command[1] = 0x00;                      //header byte 1
    command[2] = 3;                        //length
    command[3] = BT_MCU_UART_RX_BUFF_SIZE;                //command ID
    command[4] = (uint8_t)((BT_CMD_SIZE_MAX)>>8);
    command[5] = (uint8_t)(BT_CMD_SIZE_MAX&0x00FF);
    command[6] = calculateChecksum(&command[2], &command[5]);
    copyDataToBufferAndRegisterCommand(&command[0], 7);
}

/*------------------------------------------------------------*/
void BT_ProfileLinkBack(uint8_t linked_profile, uint8_t link_index)
{
    uint8_t command[10];
    command[0] = 0xAA;                      //header byte 0
    command[1] = 0x00;                      //header byte 1
    command[2] = 3;                        //length
    command[3] = ADDITIONAL_PROFILE_LINK_SETUP;                //command ID
    command[4] = link_index;
    command[5] = linked_profile;
    command[6] = calculateChecksum(&command[2], &command[5]);
    copyDataToBufferAndRegisterCommand(&command[0], 7);
}

/*------------------------------------------------------------*/
void BT_Vendor_SendCommand(uint8_t* data, uint8_t size)     //Vendor command for general usage
{
	uint8_t command[19], i;
	command[0] = 0xAA;	 		//header byte 0
	command[1] = 0x00;	 		//header byte 1
	command[2] = 4 + size;	 	//length
	command[3] = 0x2A;			//command ID
	command[4] = 0x03;	   		//broadcast to all slaves
	command[5] = 0x00;			// vendor data length
	command[6] = size;			// vendor data length
	for(i=0; i <size; i++)
		*((command+7)+i) = *(data+i);

	command[7+size] = calculateChecksum(&command[2], &command[7+size-1]);
	copyDataToBufferAndRegisterCommand(&command[0], 7+size+1);

}

#ifdef _CODE_FOR_APP
/*------------------------------------------------------------*/
//void BT_Vendor_SendVol(uint8_t vol)      //Vendor command for APP usage
//{
//	uint8_t command[10];
//	command[0] = 0x01;      //0x01: A2DP volume sync to slave
//	command[1] = vol;
//	BT_Vendor_SendCommand(command, 2);          //send from general usage Vendor command function
//}

/*------------------------------------------------------------*/
void BT_Vendor_EQCmd(uint8_t* eqData, uint8_t sequence, uint8_t size)      //Vendor command for APP usage
{
	uint8_t command[17], i;
	command[0] = 0xAA;	 		//header byte 0
	command[1] = 0x00;	 		//header byte 1
	command[2] = 4 + size;	 	//length
	command[3] = 0x2A;			//command ID
	command[4] = 0x03;	   		//broadcast to all slaves
	command[5] = 0x00;			// vendor data length
	command[6] = size;			// vendor data length
	command[7] = sequence | 0x80;		// sequence number with 0x80
	for(i=0; i <size-1; i++)
		command[i+8] = eqData[(sequence*(VENDOR_CMD_SIZE-1))+i];

	command[7+(size-1)+1] = calculateChecksum(&command[2], &command[7+(size-1)]);
	copyDataToBufferAndRegisterCommand(&command[0], 7+(size-1)+2);

}

/*------------------------------------------------------------*/
void BT_SendAppsAck(uint8_t cmd_id, uint8_t status)         //special data for APP usage, not for general use
{
	uint8_t command [10];
	command[0] = 0xAA;
	command[1] = 0x00;
	command[2] = 0x03;
	command[3] = 0x00;
	command[4] = cmd_id;
	command[5] = status;
	command[6] = calculateChecksum(&command[2], &command[5]);
	BT_SendSPPData(command, 7, BTMDATA_GetSPPiAPChannelIndex());
}

/*------------------------------------------------------------*/
void BT_SendAppsPowerStatus(uint8_t status)         //special data for APP usage, not for general use
{
	uint8_t command [10];
	command[0] = 0xAA;
	command[1] = 0x00;
	command[2] = 0x02;
	command[3] = 0x01;
	command[4] = status;
	command[5] = calculateChecksum(&command[2], &command[4]);
	BT_SendSPPData(command, 6, BTMDATA_GetSPPiAPChannelIndex());                      //send from general SPP command
}

/*------------------------------------------------------------*/
void BT_SendAppBTMStatus(uint8_t status)                //special data for APP usage, not for general use
{
	uint8_t command [10];
	command[0] = 0xAA;
	command[1] = 0x00;
	command[2] = 0x02;
	command[3] = 0x01;
	command[4] = status;
	command[5] = calculateChecksum(&command[2], &command[4]);
	BT_SendSPPData(command, 6, BTMDATA_GetSPPiAPChannelIndex());
	
}

#endif

/*------------------------------------------------------------*/
void BT_Read_Vendor_EEPROM(uint8_t offset, uint8_t length)
{
    uint8_t command[10];
    command[0] = 0xAA;                      //header byte 0
    command[1] = 0x00;                      //header byte 1
    command[2] = 3;                        //length
    command[3] = READ_VENDOR_EEPROM;                //command ID
    command[4] = offset;
    command[5] = length;
    command[6] = calculateChecksum(&command[2], &command[5]);
    copyDataToBufferAndRegisterCommand(&command[0], 7);
}

/*------------------------------------------------------------*/
void BT_Write_Vendor_EEPROM(uint8_t offset, uint8_t length, uint8_t* data)
{
    uint8_t command[50], i;
    if(length > 0x20)
        return;
    command[0] = 0xAA;
    command[1] = 0x00;
    command[2] = 4+length;
    command[3] = BTM_UTILITY_FUNCTION;
    command[4] = 0x09;
    command[5] = offset;
    command[6] = length;
    for(i = 0; i < length; i++)
        command[7+i] = *data++;
    command[7+length] = calculateChecksum(&command[2], &command[6+length]);
    copyDataToBufferAndRegisterCommand(&command[0], 8+length);
}

/*------------------------------------------------------------*/
void BLE_EnableAdvertising(bool enable)
{
    uint8_t command[7];
    uint8_t chksum;

    command[0] = 0xAA;      //header byte 0
    command[1] = 0x00;      //header byte 1
    command[2] = 0x03;      //length
    command[3] = LE_SIGNALING;      //command ID
    command[4] = 0x01;      //subCommand 0x01: Enable advertising or disable advertising
    command[5] = enable;
    chksum = command[2] + command[3] + command[4] + command[5];
    chksum = ~chksum + 1;
    command[6] = chksum;
    copyDataToBufferAndRegisterCommand(&command[0], 7);
}

/*------------------------------------------------------------*/
void BLE_SetAdvertisingType(uint8_t advType)
{
    uint8_t command[7];
    uint8_t chksum;

    command[0] = 0xAA;      //header byte 0
    command[1] = 0x00;      //header byte 1
    command[2] = 0x03;      //length
    command[3] = LE_SIGNALING;      //command ID
    command[4] = 0x04;      //subCommand 0x04: set advertising type
    command[5] = advType;
    chksum = command[2] + command[3] + command[4] + command[5];
    chksum = ~chksum + 1;
    command[6] = chksum;
    copyDataToBufferAndRegisterCommand(&command[0], 7);
}

/*------------------------------------------------------------*/
void BLE_SetAdvertisingData(uint8_t* data, uint8_t size)
{
    uint8_t command[40];
    uint8_t chksum;
    uint8_t i;

    if(size > 31)
        size = 31;
    
    command[0] = 0xAA;      //header byte 0
    command[1] = 0x00;      //header byte 1
    command[2] = 3+size;      //length

    command[3] = LE_SIGNALING;      //command ID
    command[4] = 0x05;              //subCommand 0x06: set response data
    command[5] = 0x00;
	
    for(i=0; i<size; i++)
        command[6+i] = *data++;
	
	chksum = 0;
	for(i=2; i<(6+size); i++)
		chksum += command[i];
	chksum = ~chksum + 1;

	command[6+size] = chksum;

    copyDataToBufferAndRegisterCommand(&command[0], 7+size);
}

/*------------------------------------------------------------*/
void BLE_SetScanResponseData(uint8_t* data, uint8_t size)
{
    uint8_t command[40];
    uint8_t chksum;
    uint8_t i;

    if(size > 31)
        size = 31;
    
    command[0] = 0xAA;      //header byte 0
    command[1] = 0x00;      //header byte 1
    command[2] = 3+size;      //length

    command[3] = LE_SIGNALING;      //command ID
    command[4] = 0x06;              //subCommand 0x06: set response data
    command[5] = 0x00;
	
    for(i=0; i<size; i++)
        command[6+i] = *data++;
	
	chksum = 0;
	for(i=2; i<(6+size); i++)
		chksum += command[i];
	chksum = ~chksum + 1;

	command[6+size] = chksum;

    copyDataToBufferAndRegisterCommand(&command[0], 7+size);    
}
/*------------------------------------------------------------*/
void BLE_SetConnParam(uint16_t min_int, uint16_t max_int, 
                           uint16_t latency, uint16_t supper_to){
  /* 
     *        UART EVENT packet format
     *     - SYNC : 1byte, 0xAA
     *     - LEN:    2bytes, big endian
     *     - OP:      1byte
     *     - DATA:   varable payload
     *     - CRC8: CRC(SYNC,LEN,OP,DATA)
     */  
    uint8_t command[40];
    uint8_t chksum;
    uint8_t i;
    
    command[0] = 0xAA;      //header byte 0
    command[1] = 0x00;      //header byte 1
    command[2] = 0x0A;      //length

    command[3] = LE_SIGNALING;      //command ID
    command[4] = 2;                 //update parameter
    command[5] = (uint8_t)(min_int>>8);//0;
    command[6] = (uint8_t)(min_int&0xFF);//0x08;//min interval
    command[7] = (uint8_t)(max_int>>8);//0;
    command[8] = (uint8_t)(max_int&0xFF);//0x10;//max interval 
    command[9]  = (uint8_t)(latency>>8);//0;
    command[10] = (uint8_t)(latency&0xFF);
    command[11] = (uint8_t)(supper_to>>8);//0x01;
    command[12] = (uint8_t)(supper_to&0xFF);//0xF4;

    chksum = 0;
	for(i=2; i<13; i++)
		chksum += command[i];
	chksum = ~chksum + 1;
	command[13] = chksum;

    copyDataToBufferAndRegisterCommand(&command[0], 14);
}

/*------------------------------------------------------------*/
void BT_SoundVersion(uint8_t* data, uint8_t size )
{
    uint8_t command[20], i;

    if(size > 13)
        return;
    
    command[0] = 0xAA;      //header byte 0
    command[1] = 0x00;      //header byte 1
    command[2] = size+3;      //length
    command[3] = BTM_UTILITY_FUNCTION;      //command ID
    command[4] = 0x07;      
    command[5] = size;
    
    for(i = 0; i < size; i++)
    {
        command[6+i] = *data++;
    }
    
    command[6+size] = calculateChecksum(&command[2], &command[5+size]);
    copyDataToBufferAndRegisterCommand(&command[0], 7+size);
}

/*------------------------------------------------------------*/
void BT_ReadFeatureListCommand(void)
{
    uint8_t command[6];
    command[0] = 0xAA;                      //header byte 0
    command[1] = 0x00;                      //header byte 1
    command[2] = 0x02;                      //length
    command[3] = READ_FEATURE_LIST;    //command ID
    command[4] = 0x00;                      //dummy byte
    command[5] = calculateChecksum(&command[2], &command[4]);
    copyDataToBufferAndRegisterCommand(&command[0], 6);
}
/*------------------------------------------------------------*/
void BT_EnterInquiryMode( void )
{
	uint8_t cmd[] = {AUDIO_TRANS_CMD,
					 AT_DO_INQUIRY, 
					 INQUIRY_TIME, 
					 INQUIRY_DEVICES_NUM,
					 INQUIRY_FILTER_COD,
					 INQUIRY_REPORT_NONE,
					 0};					
	BT_SendUARTCommand(cmd, sizeof(cmd));
}
/*------------------------------------------------------------*/
void BT_CancelInquiryMode( void )
{
    uint8_t cmd[] = {AUDIO_TRANS_CMD,
					 AT_CANCEL_INQUIRY};
	BT_SendUARTCommand(cmd, sizeof(cmd));
}
/*------------------------------------------------------------*/
void BT_BlockTxA2DPStream(bool enable)
{
    uint8_t cmd[] = {AUDIO_TRANS_CMD,
					 AT_BLOCK_A2DP_STREAM, (enable ? 1 : 0)};
	BT_SendUARTCommand(cmd, sizeof(cmd));
}
/*------------------------------------------------------------*/
void BT_Toggle_AT_Mode()
{
    uint8_t cmd[] = {AUDIO_TRANS_CMD, 
					 AT_APP_MODE, 
					 0x00};
	cmd[2] = (BTAPP_GetATMode() == AT_TX) ?
				 AT_RX :
				 AT_TX ;
	
	// BM83 will send back the change event to change BTAPP_AT_Mode
    BT_SendUARTCommand(cmd,sizeof(cmd));
}
/*------------------------------------------------------------*/
void BT_Toggle_TX_Source()
{
    uint8_t cmd[] = {AUDIO_TRANS_CMD, 
					 AT_TX_SOURCE, 
					 0x00};

	cmd[2] = (BTAPP_GetTxSource() == TX_SOURCE_AUX) ?
			 TX_SOURCE_I2S :
			 TX_SOURCE_AUX ;
	// BM83 will send back the change event to change BTAPP_AT_Source
    BT_SendUARTCommand(cmd,sizeof(cmd));
}
/*------------------------------------------------------------*/
void BT_Toggle_Tx_SamplingRate()
{
    uint8_t cmd[] = {AUDIO_TRANS_CMD, 
					 AT_TX_I2S_SAMPLING, 
					 0x00};

	cmd[2] = (BTAPP_GetTxSamplingRate() == TX_SAMPLING_RATE_48KHZ) ?
			 TX_SAMPLING_RATE_44_1KHZ :
			 TX_SAMPLING_RATE_48KHZ ;
	// BM83 will send back the change event to change BTAPP_AT_Source
    BT_SendUARTCommand(cmd,sizeof(cmd));
}
/*------------------------------------------------------------*/
void BT_Connect_Device(uint8_t* macAddr)
{
    int i;
	// "0xff 0xff 0xff 0xff 0xff 0xff" is to store the target BT address
    uint8_t cmd[] = {PROFILE_LINK_BACK, 
    				 0x07, 
    				 0x00, 
    				 0x04, 
    				 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};

	for(i=0;i<6;i++)
		cmd[i+4] = macAddr[i];

    BT_SendUARTCommand(cmd,sizeof(cmd));
}
/*------------------------------------------------------------*/
void BT_ReadATMode( void )
{
    uint8_t command[6];
    command[0] = 0xAA;
    command[1] = 0x00;
    command[2] = 0x02;
    command[3] = AUDIO_TRANS_CMD;
    command[4] = AT_READ_APP_MODE;
    command[5] = calculateChecksum(&command[2], &command[4]);
    copyDataToBufferAndRegisterCommand(&command[0], 6);
}
/*------------------------------------------------------------*/
void BT_ReadTxSource( void )
{
    uint8_t command[6];
    command[0] = 0xAA;
    command[1] = 0x00;
    command[2] = 0x02;
    command[3] = AUDIO_TRANS_CMD;
    command[4] = AT_READ_TX_SOURCE;
    command[5] = calculateChecksum(&command[2], &command[4]);
    copyDataToBufferAndRegisterCommand(&command[0], 6);
}
/*------------------------------------------------------------*/
void BT_ReadTxSamplingRate( void )
{
    uint8_t command[6];
    command[0] = 0xAA;
    command[1] = 0x00;
    command[2] = 0x02;
    command[3] = AUDIO_TRANS_CMD;
    command[4] = AT_READ_TX_SAMPLING_RATE;
    command[5] = calculateChecksum(&command[2], &command[4]);
    copyDataToBufferAndRegisterCommand(&command[0], 6);
}
/*------------------------------------------------------------*/
void BT_CommandSendInit( void )
{
    UR_TxBufHead = 0;
    UR_TxBufTail = 0;
    UR_TxBufStatus = TXRX_BUF_EMPTY;
    BT_SendingCmd.SendingCmdNum = 0;
    BT_SendingAck.SendingAckNum = 0;
    BT_SendingAck.head = 0;
    BT_SendingAck.tail = 0;
    BT_SendingAck.AckDataSendingFlag = false;
    BT_SendingAck.lock = false;
    BT_SendingAck.AckData[0] = 0xAA;
    BT_SendingAck.AckData[1] = 0x00;
    BT_SendingAck.AckData[2] = 0x02;
    BT_SendingAck.AckData[3] = MCU_SEND_EVENT_ACK;
    BT_SendingAck.AckData[4] = 0xFF;        //Event ID
    BT_SendingAck.AckData[5] = 0xFF;        //Checksum
}

/*------------------------------------------------------------*/
void BT_CommandSendTask( void )
{
    switch(BT_CMD_SendState)
    {
        case BT_CMD_SEND_STATE_IDLE:
            if(BT_SendingCmd.SendingCmdNum || BT_SendingAck.SendingAckNum)
            {
                BM6X_MFB_SetHigh();
                BT_CommandSendTimer = 3;      //wait 2 - 3ms
                BT_CMD_SendState = BT_CMD_SEND_MFB_HIGH_WAITING;
            }
            break;
            
        case BT_CMD_SEND_MFB_HIGH_WAITING:
            if(!BT_CommandSendTimer)
            {
                if(BT_SendingAck.SendingAckNum)     //sending ack has priority
                {
                    BT_SendingAck.AckDataSendingFlag =true;
                    BT_SendingAck.txIndex = 0;
                    BT_SendingAck.AckData[4] = BT_SendingAck.AckEventID[BT_SendingAck.tail++];
                    if(BT_SendingAck.tail >= QUEQUED_ACK_MAX)
                        BT_SendingAck.tail = 0;
                    BT_SendingAck.SendingAckNum --;
                    BT_SendingAck.AckData[5] = calculateChecksum(&BT_SendingAck.AckData[2], &BT_SendingAck.AckData[4]);
                    UART_TransferFirstByte();
                    BT_CMD_SendState = BT_CMD_SEND_DATA_SENDING;
                }
                else if(BT_SendingCmd.SendingCmdNum)
                {
                    BT_SendingAck.AckDataSendingFlag =false;
                    UART_TransferFirstByte();
                    BT_SendingCmd.SendingCmdArray[0].cmdStatus = IN_SENDING;
                    BT_CMD_SendState = BT_CMD_SEND_DATA_SENDING;
                }
                else
                {
                    BT_CMD_SendState = BT_CMD_SEND_ACK_OK;      //exceptional case
                }
            }
            break;

        case BT_CMD_SEND_DATA_SENDING:
            //do nothing, UART interrupt will handle
            break;

        case BT_CMD_SEND_ACK_WAITING:       //new
            if( BT_SendingAck.lock )    //ack is in sending, wait
                break;
            if( !BT_CommandSendTimer )
            {
                BTAPP_EventHandler(BT_EVENT_CMD_SENT_NO_ACK, &(BT_SendingCmd.SendingCmdArray[0].cmdID), 1 );        //send event to user application layer with command id, and event type
                BT_SendingCmd.SendingCmdArray[0].cmdStatus = ERROR_NO_ACK;
                BT_CommandSendTimer = INTERVAL_AFTER_CMD_ACK_NG;
                BT_CMD_SendState = BT_CMD_SEND_ACK_ERROR;
            }
            else        //using the waiting time to send ACK
            {
                if(BT_SendingAck.SendingAckNum)     //sending ack has priority
                {
                    BT_SendingAck.lock = true;
                    BT_SendingAck.AckDataSendingFlag =true;
                    BT_SendingAck.txIndex = 0;
                    BT_SendingAck.AckData[4] = BT_SendingAck.AckEventID[BT_SendingAck.tail++];
                    if(BT_SendingAck.tail >= QUEQUED_ACK_MAX)
                        BT_SendingAck.tail = 0;
                    BT_SendingAck.SendingAckNum --;
                    BT_SendingAck.AckData[5] = calculateChecksum(&BT_SendingAck.AckData[2], &BT_SendingAck.AckData[4]);
                    UART_TransferFirstByte();
                }
            }
            break;
        
        case BT_CMD_SEND_ACK_ERROR:
            if (!BT_CommandSendTimer) {
                if (BT_SendingCmd.SendingCmdNum) {
                    BT_SendingAck.AckDataSendingFlag = false;
                    UART_TransferFirstByte();
                    BT_SendingCmd.SendingCmdArray[0].cmdStatus = IN_SENDING;
                    BT_CMD_SendState = BT_CMD_SEND_DATA_SENDING; //re-sending last command or sending next command
                } else {
                    BM6X_MFB_SetLow();
                    BT_CMD_SendState = BT_CMD_SEND_STATE_IDLE;
                }
            }
            break;
       
        case BT_CMD_SEND_ACK_OK:
            if (!BT_CommandSendTimer) {
                if(!BT_SendingAck.AckDataSendingFlag){
                    RemoveFirstCommand();
                }
                if(BT_SendingAck.SendingAckNum)     //sending ack has priority
                {
                    BT_SendingAck.AckDataSendingFlag =true;
                    BT_SendingAck.txIndex = 0;
                    BT_SendingAck.AckData[4] = BT_SendingAck.AckEventID[BT_SendingAck.tail++];
                    if(BT_SendingAck.tail >= QUEQUED_ACK_MAX)
                        BT_SendingAck.tail = 0;
                    BT_SendingAck.SendingAckNum --;
                    BT_SendingAck.AckData[5] = calculateChecksum(&BT_SendingAck.AckData[2], &BT_SendingAck.AckData[4]);
                    UART_TransferFirstByte();
                    BT_CMD_SendState = BT_CMD_SEND_DATA_SENDING;
                }
                else if(BT_SendingCmd.SendingCmdNum)
                {
                    BT_SendingAck.AckDataSendingFlag = false;
                    UART_TransferFirstByte();
                    BT_SendingCmd.SendingCmdArray[0].cmdStatus = IN_SENDING;
                    BT_CMD_SendState = BT_CMD_SEND_DATA_SENDING;  
                }
                else
                {
                    BM6X_MFB_SetLow();
                    BT_CMD_SendState = BT_CMD_SEND_STATE_IDLE;
                }
            }
            break;
            
        default:
            break;
    }
}

/*------------------------------------------------------------*/
void BT_UpdateAckStatusWhenReceived(uint8_t command_id, uint8_t ack_status)
{
    uint8_t temp[2];
    if( BT_CMD_SendState == BT_CMD_SEND_ACK_WAITING )
    {
        if(ack_status == ACK_STS_OK)
        {
            BTAPP_EventHandler(BT_EVENT_CMD_SENT_ACK_OK, &command_id, 1 );        //send event to user application layer with command id, and event type
            if(command_id == BT_SendingCmd.SendingCmdArray[0].cmdID)
                BT_SendingCmd.SendingCmdArray[0].cmdStatus = STS_OK;
            BT_CommandSendTimer = INTERVAL_AFTER_CMD_ACK_OK;
            BT_CMD_SendState = BT_CMD_SEND_ACK_OK;
            
        }
        else
        {
            temp[0] = command_id;
            temp[1] = ack_status;
            BTAPP_EventHandler(BT_EVENT_CMD_SENT_ACK_ERROR, temp, 2 );        //para: high byte is ack error type, low byte is command id
            if(command_id == BT_SendingCmd.SendingCmdArray[0].cmdID)
                BT_SendingCmd.SendingCmdArray[0].cmdStatus = ack_status;
            BT_CommandSendTimer = INTERVAL_AFTER_CMD_ACK_NG;
            BT_CMD_SendState = BT_CMD_SEND_ACK_ERROR;
        }
    }
}

/*------------------------------------------------------------*/
void BT_CommandSend1MS_event(void)
{
    if( BT_CommandSendTimer/*BT_CommandStartMFBWaitTimer*/)
    {
        -- BT_CommandSendTimer/*BT_CommandStartMFBWaitTimer*/;
    }
}

/*------------------------------------------------------------*/
void UART_TransferFirstByte( void )
{
    uint8_t data;
    if(!BT_SendingAck.AckDataSendingFlag)
    {
        UR_TxBufTail2 = BT_SendingCmd.SendingCmdArray[0].startBufPt;
        UR_TxBufEnd = BT_SendingCmd.SendingCmdArray[0].endBufPt;
#ifdef BT_UART_TX_BUFFER_MODEL
        data = UR_TxBuf[UR_TxBufTail2++];
        if(UR_TxBufTail2 >= UR_TX_BUF_SIZE)
            UR_TxBufTail2 = 0;
#endif
#ifdef BT_UART_TX_BYTE_MODEL
        bt_issueUartTransfer();
#endif          
    }
    else
    {
#ifdef BT_UART_TX_BUFFER_MODEL        
        data = BT_SendingAck.AckData[BT_SendingAck.txIndex++];
#endif
#ifdef BT_UART_TX_BYTE_MODEL
        bt_issueUartTransfer();
#endif          
    }
#ifdef BT_UART_TX_BUFFER_MODEL    
    UART_WriteOneByte(data);
#endif
}


/*------------------------------------------------------------*/
#ifdef BT_UART_TX_BYTE_MODEL
void BT_CommandSend_SendByte( void )
#endif
#ifdef BT_UART_TX_BUFFER_MODEL
void UART_TransferNextByte( void )
#endif
{
    uint8_t data;
    if(!BT_SendingAck.AckDataSendingFlag)
    {
        if (UR_TxBufTail2 == UR_TxBufEnd) {
            #if defined (__XC32__) 
            bt_disableUartTransferIntr();
            #endif
            if (BT_CMD_SendState == BT_CMD_SEND_DATA_SENDING) {
				if (BT_SendingCmd.SendingCmdArray[0].cmdID != MCU_SEND_EVENT_ACK 
				) {
                    BT_CommandSendTimer = ACK_TIME_OUT_MS;
                    BT_CMD_SendState = BT_CMD_SEND_ACK_WAITING;
                } 
				else //just sent is ACK_TO_EVENT command
                {
                    BT_CommandSendTimer = INTERVAL_AFTER_CMD_ACK_OK;
                    BT_SendingCmd.SendingCmdArray[0].cmdStatus = STS_OK;
                    BT_CMD_SendState = BT_CMD_SEND_ACK_OK;
                }
            }
        } else {
            data = UR_TxBuf[UR_TxBufTail2++];
            if (UR_TxBufTail2 >= UR_TX_BUF_SIZE)
                UR_TxBufTail2 = 0;
            UART_WriteOneByte(data);
        }
    }
    else
    {
        if(BT_SendingAck.txIndex == 6)
        {
            #if defined (__XC32__) 
            bt_disableUartTransferIntr();
            #endif
            if (BT_CMD_SendState == BT_CMD_SEND_DATA_SENDING)
            {
                BT_CommandSendTimer = INTERVAL_AFTER_CMD_ACK_OK;
                BT_CMD_SendState = BT_CMD_SEND_ACK_OK;
            }
            else if((BT_CMD_SendState == BT_CMD_SEND_ACK_WAITING) && BT_SendingAck.lock)
            {
                BT_SendingAck.lock = false;
            }
        }
        else
        {
            data = BT_SendingAck.AckData[BT_SendingAck.txIndex++];
            UART_WriteOneByte(data);
        }
    }
}

/*------------------------------------------------------------*/
static bool StartRegisterNewCommand(uint16_t start_index, uint16_t cmd_size, uint8_t cmd_id)
{
    if(!cmd_size)
        return false;
    
    if(BT_SendingCmd.SendingCmdNum < QUEQUED_CMD_MAX)
    {
        BT_SendingCmd.SendingCmdArray[BT_SendingCmd.SendingCmdNum].startBufPt = start_index;
        BT_SendingCmd.SendingCmdArray[BT_SendingCmd.SendingCmdNum].cmdSize = cmd_size;
        BT_SendingCmd.SendingCmdArray[BT_SendingCmd.SendingCmdNum].cmdID = cmd_id;
        if(cmd_id!=0x1f)
            Nop();
        return true;
    }
    else
    {
        return false;
    }
}

/*------------------------------------------------------------*/
static bool EndRegisterNewCommand(uint16_t end_index)
{
    if(BT_SendingCmd.SendingCmdNum < QUEQUED_CMD_MAX)
    {
        BT_SendingCmd.SendingCmdArray[BT_SendingCmd.SendingCmdNum].endBufPt = end_index;
        BT_SendingCmd.SendingCmdArray[BT_SendingCmd.SendingCmdNum].cmdStatus = IN_QUEUE;
        BT_SendingCmd.SendingCmdNum++;
    }
    return true;
}

/*------------------------------------------------------------*/
static bool RemoveFirstCommand(void)//index starting from 0
{
    uint8_t i;
    if(!BT_SendingCmd.SendingCmdNum)
        return false;            //parameter error
    
    if(BT_SendingCmd.SendingCmdNum == 1)
    {
        BT_SendingCmd.SendingCmdNum--;
        UR_TxBufTail = UR_TxBufTail2;
        if (UR_TxBufHead == UR_TxBufTail)
            UR_TxBufStatus = TXRX_BUF_EMPTY;
        else
            UR_TxBufStatus = TXRX_BUF_OK;
        return true;
    }
    
    for(i = 0; i < BT_SendingCmd.SendingCmdNum - 1; i++)
    {
        //copy next command info to previous one
        BT_SendingCmd.SendingCmdArray[i].cmdSize = BT_SendingCmd.SendingCmdArray[i + 1].cmdSize;
        BT_SendingCmd.SendingCmdArray[i].cmdStatus = BT_SendingCmd.SendingCmdArray[i + 1].cmdStatus;
        BT_SendingCmd.SendingCmdArray[i].endBufPt = BT_SendingCmd.SendingCmdArray[i + 1].endBufPt;
        BT_SendingCmd.SendingCmdArray[i].startBufPt = BT_SendingCmd.SendingCmdArray[i + 1].startBufPt;
        BT_SendingCmd.SendingCmdArray[i].cmdID = BT_SendingCmd.SendingCmdArray[i + 1].cmdID;
    }
    BT_SendingCmd.SendingCmdNum--;
    UR_TxBufTail = UR_TxBufTail2;
    if (UR_TxBufHead == UR_TxBufTail)
        UR_TxBufStatus = TXRX_BUF_EMPTY;
    else
        UR_TxBufStatus = TXRX_BUF_OK;
    return true;
}

/*------------------------------------------------------------*/


