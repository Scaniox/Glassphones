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
#ifndef BT_DATA_H
#define BT_DATA_H
#include <stdbool.h>
#include <stdint.h>
#include "bt_general_event_define.h"

typedef struct {
    uint8_t SPPLinkStatus           : 1;
    uint8_t iAPLinkStatus           : 1;
    uint8_t targetSPPiAPDatabaseIndex   : 2;
    uint8_t currentSPPiAPDatabaseIndex  : 2;
    uint8_t reserved                    : 2;
} SPP_IAP_LINK_STATUS;

typedef enum {
    BLE_CONN_STANDBY = 0,
    BLE_CONN_ADV,
    BLE_CONN_SCAN,
    BLE_CONN_CONNECTED
} BLE_CONNECTION_STATUS;

typedef struct {
    BLE_CONNECTION_STATUS BLE_ConnectionStatus;
    union {
        uint8_t serviceValue;
        struct {
            uint8_t transparentServiceActive        : 1;
            uint8_t ANCSActive                      : 1;
        } bits;
    } BLE_GATTServiceStatus;
} BLE_LINK_STATUS;

typedef union {
    uint8_t value;
    struct {
    uint8_t SPPiAP_ChIndex           : 2;
    uint8_t BLE_Ch                   : 1;
    uint8_t RFCOMM_Index             : 3;
    uint8_t iAP_SessionIndex         : 2;
    }   bits;
} DATA_PACKET_HEADER;

typedef struct {
    DATA_PACKET_HEADER  packetHeader;
    uint8_t packetType;
    uint16_t totalPayloadLength;
    uint16_t currentPayloadLength;
    uint8_t *currentPayloadData;
} DATA_PACKET_INFO;


void BTMDATA_EventHandler( BT_DATA_EVENTS event, uint8_t* paras, uint16_t size );
void BTMDATA_Handler( uint8_t* data, uint16_t size );
bool BTMDATA_GATT_AttributeHandler(uint8_t attributeIndex, uint8_t* attributeData, uint8_t attributeDataLength);
void BTMDATA_Init( void );
bool BTMDATA_SendData(uint8_t* addr, uint32_t size);
bool BTMDATA_SendOneByte(uint8_t byte);
uint8_t BTMDATA_GetSPPiAPActiveDatabaseIndex( void );
uint8_t BTMDATA_GetSPPiAPChannelIndex( void );
bool BTMDATA_isSPPorIAPConnected( void );
bool BTMDATA_isBLEConnected( void );
bool BTMDATA_isBLETransparentServiceConnected( void );
bool BTMDATA_isBLEANCSServiceConnected( void );

#ifdef _SPP_LINK_BREAK_IN
typedef enum {
    SPP_LINK_CONNECTION_TASK_IDLE,
    SPP_LINK_CONNECTION_TASK_DISCONNECTION_START,
    SPP_LINK_CONNECTION_TASK_DISCONNECTION_WAIT,
    SPP_LINK_CONNECTION_TASK_CONNECTION1_START,
    SPP_LINK_CONNECTION_TASK_CONNECTION1_WAIT,
    SPP_LINK_CONNECTION_TASK_CONNECTION2_START,
} SPP_CONNECTION_TASK_STATE;

typedef struct {
    bool request;
    SPP_CONNECTION_TASK_STATE state;
} SPP_LINK_CONNECTION_STATE;

void BTMDATA_SPPLinkChangeStart( uint8_t targetDatabaseIndex);
void BTMDATA_SPPLinkChangeTask(void);
#endif

#ifdef _CODE_FOR_APP
void addComandWaitingForACK( uint8_t cmd_id );
bool checkCommandWaitingForACK( uint8_t cmd_id, uint8_t ack_status ) ;
void AppsReportLineInStatus( void );
#endif


#ifdef BT_DATA_C
/* private */

#else
/* public */

#endif

#endif      //BT_DATA_H
