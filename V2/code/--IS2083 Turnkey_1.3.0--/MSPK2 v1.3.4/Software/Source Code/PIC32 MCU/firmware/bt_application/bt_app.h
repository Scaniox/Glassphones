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
#ifndef BT_APP_H
#define BT_APP_H

#include <stdbool.h>
#include <stdint.h>
#include "bt_general_event_define.h"

/* Version History */
#define MCU_MAJOR_VERSION 0
#define MCU_MINOR_VERSION 0
#define MCU_SUB_VERSION   1
// r0.01
// 1. initial code


// @ bluetooth task state define
typedef enum {
    BT_STATE_INITIALIZE_START = 0,
    BT_STATE_INIT_MFB_HIGH,
    BT_STATE_INIT_RESET_HIGH,
    BT_STATE_INIT_RESET_HIGH_WAIT,
    BT_STATE_INIT_COMMAND_START,    //send first command
	BT_STATE_INIT_READ_DEVICE_NAME_WAIT,
    BT_STATE_INIT_BLE_ADV_START,
	BT_STATE_INIT_BLE_ADV_WAIT,

    BT_STATE_POWER_ON_START,        //wait 500ms. after 500ms, send SYSTEM_ON and CSB_PAGE command
    BT_STATE_POWER_DSP_WAIT,        //wait DSP is ready
    BT_STATE_POWER_ON,          //system on finished, wait for BT or AUX instruction
    BT_STATE_BLE_ADV_WAIT,
    //BT_STATE_VOL_SYNC,
    BT_STATE_READ_PAIR_RECORD,
    BT_STATE_READ_PAIR_RECORD_WAIT,
    BT_STATE_READ_LINKED_MODE,
    BT_STATE_READ_LINKED_MODE_WAIT,
    BT_STATE_LINKBACK_START,
    BT_STATE_BT_RUNNING,

    BT_STATE_POWER_OFF_START,
    BT_STATE_POWER_OFF_WAIT_NSPK_EVENT,
    BT_STATE_POWER_OFF_START_NSPK,
    BT_STATE_POWER_OFF_WAIT,
    BT_STATE_POWER_OFF
} BTAPP_TASK_STATE;

typedef enum
{
    BT_RUNNING_STATE_IDLE,
    BT_RUNNING_STATE_MUTE
} BTAPPRUNNING_TASK_STATE;

typedef enum
{
    BT_LINE_IN = 2,
    BT_A2DP = 4,
    BT_HFP = 6
} BT_CODEC_TYPE;

void BTAPP_Init( void );
void BTAPP_Task( void );
void BTAPP_Timer1MS_event( void );
enum {
    BT_SINGLE_PKT = 0,
    BT_FRAGMENTED_START_PKT,  
    BT_FRAGMENTED_CONT_PKT, 
    BT_FRAGMENTED_END_PKT,
};
// @ request define
enum {
    BT_REQ_NONE = 0,
    BT_REQ_SYSTEM_ON,   //BM64 power on request(outside application must control RESET and MFB timing, then call this request)
    BT_REQ_SYSTEM_OFF,  //BM64 power off request(after call this, outside application must control RESET and MFB)
};
void BTAPP_TaskReq(uint8_t request);


typedef enum {
    BT_SYSTEM_INIT,         //init
    BT_SYSTEM_POWER_OFF,    //event
    BT_SYSTEM_POWER_ON,     //event
    BT_SYSTEM_STANDBY,      //event
    BT_SYSTEM_CONNECTED,    //event
    BT_SYSTEM_PAIRING,      //event
} BT_SYSTEM_STATUS;
typedef struct {
    BT_SYSTEM_STATUS status;
    uint8_t pairedRecordNumber;      //paired record
    uint8_t lastLinkedMode;              //linked mode
    uint8_t lastMSPKSlaveCounter;       //slave counter for linked mode
    uint8_t batteryStatus;
    uint8_t batteryLevel;
    uint8_t BDAddr[6];          //device address
    uint8_t FWVer[2];           //BTM firmware version
    uint8_t UARTVer[2];         //UART version
    //bool groupLinkingBack;
} BTAPP_STATUS;

typedef struct {
    union {
        uint8_t value;
        struct{
            uint8_t PORT_1_0    : 1;
            uint8_t PORT_1_1    : 1;
            uint8_t PORT_1_2    : 1;
            uint8_t PORT_1_3    : 1;
            uint8_t PORT_1_4    : 1;
            uint8_t PORT_1_5    : 1;
            uint8_t PORT_1_6    : 1;
            uint8_t PORT_1_7    : 1;
        } bits;
    } PORT_1;
    union {
        uint8_t value;
        struct{
            uint8_t PORT_2_0    : 1;
            uint8_t PORT_2_1    : 1;
            uint8_t PORT_2_2    : 1;
            uint8_t PORT_2_3    : 1;
            uint8_t PORT_2_4    : 1;
            uint8_t PORT_2_5    : 1;
            uint8_t PORT_2_6    : 1;
            uint8_t PORT_2_7    : 1;
        } bits;
    } PORT_2;
    union {
        uint8_t value;
        struct{
            uint8_t PORT_3_0    : 1;
            uint8_t PORT_3_1    : 1;
            uint8_t PORT_3_2    : 1;
            uint8_t PORT_3_3    : 1;
            uint8_t PORT_3_4    : 1;
            uint8_t PORT_3_5    : 1;
            uint8_t PORT_3_6    : 1;
            uint8_t PORT_3_7    : 1;
        } bits;
    } PORT_3;
    union {
        uint8_t value;
        struct{
            uint8_t PORT_4_0    : 1;
            uint8_t PORT_4_1    : 1;
            uint8_t PORT_4_2    : 1;
            uint8_t PORT_4_3    : 1;
            uint8_t PORT_4_4    : 1;
            uint8_t PORT_4_5    : 1;
            uint8_t PORT_4_6    : 1;
            uint8_t PORT_4_7    : 1;
        } bits;
    } PORT_4;
} BT_PORTS;


enum {
    BT_STATUS_NONE,
    BT_STATUS_OFF,
    BT_STATUS_ON,
    BT_STATUS_READY
};
uint8_t BTAPP_GetStatus(void);

void BTAPP_EventHandler(BT_APP_EVENTS event, uint8_t* paras, uint16_t size );
void BTAPP_EnterBTPairingMode( void );
void BTAPP_ResetEEPROMtoDefault( void );
uint8_t* BT_GetLocalBDAddress( void );
uint8_t* Get_BTM_FWVersion( void );
uint8_t* Get_BTM_UARTVersion( void );
void BTAPP_SoundVersion( void );

#ifdef _CODE_FOR_APP
void BT_SendEQBytes(void);
bool BT_SendMultiSpkEQBytes(uint8_t* data, uint8_t size);
void BT_SetMultiSpkEQRoute(uint8_t route);
#endif

//void BT_SaveDeviceName(uint8_t* address);

#ifdef _BLE_ADV_CTRL_BY_MCU
typedef enum {
    SPEAKER_SINGLE = 0,
    SPEAKER_nSPK_MASTER = 1,
    SPEAKER_nSPK_SLAVE = 4,
    SPEAKER_BROADCAST_MASTER_ADDING = 5,
    SPEAKER_BROADCAST_SLAVE = 6,
	SPEAKER_BROADCAST_MASTER = 7,
	SPEAKER_CONNECTING = 0xf,   //NC in v1.16 app
} BLE_CSB_CONNECTION_STATE;

typedef enum {
    LINK_STBY = 0,
    LINK_BUSY = 1,
    LINK_CONNECTING = 2,
    LINK_CONNECTED = 3,
	LINK_MORE_SLAVES = 9,
} BLE_CSB_STATE;

typedef enum {
    CONNECTABLE_UNDIRECT_ADV = 0,           //connectable
    CONNECTABLE_RESERVED = 1,
    SCANNABLE_UNDIRECT_ADV = 2,
    NON_CONNECTABLE_UNDIRECT_ADV = 3,       //non-connectable
} BLE_ADV_TYPE;

typedef enum
{
	BLE_BTM_OFF=0,
	BLE_BTM_PAIR,
	BLE_BTM_STBY,
	BLE_BTM_CONN_HF,
	BLE_BTM_CONN_A2DP,
	BLE_BTM_CONN_SPP_IAP,
	BLE_BTM_CONN_ALL
} BLE_BTM_STATE;

void BLE_SaveMasterAddr(uint8_t * address);
void BLE_SaveFeatureList( uint8_t feature );
void BLE_SaveDeviceName(uint8_t* address);
void BLE_UpdateAdvType(BLE_ADV_TYPE type);
void BLE_advUpdateGroupStatus(BLE_CSB_CONNECTION_STATE group_status);
void BLE_advUpdateLinkStatus(BLE_CSB_STATE group_event);
bool BLE_advUpdateBTMState(BLE_BTM_STATE btm_state, bool state);
void BLE_SetAdvData(void);
void BLE_SetScanRspData(void);
void BLE_forceUpdate(void);
#endif

#endif
