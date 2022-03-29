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
#include "bt_hardware_profile.h"

bool UartTxIntrStatus;

void bt_issueUartTransfer( void )
{
    SYS_INT_SourceEnable(INT_SOURCE_USART_1_TRANSMIT);
    UartTxIntrStatus = true;
}

/*void bt_enableUartTransferIntr( void )
{
    SYS_INT_SourceEnable(INT_SOURCE_USART_1_TRANSMIT);
    UartTxIntrStatus = true;
    
}*/

void bt_disableUartTransferIntr( void )
{
    SYS_INT_SourceDisable(INT_SOURCE_USART_1_TRANSMIT);//USART0_TransmitterIntrDisable();
    UartTxIntrStatus = false;
}

void bt_temporaryDisableUartTransferIntr( void )
{
    SYS_INT_SourceDisable(INT_SOURCE_USART_1_TRANSMIT);
}

void bt_restoreUartTransferIntr( void )
{
    if(UartTxIntrStatus)
        SYS_INT_SourceEnable(INT_SOURCE_USART_1_TRANSMIT);
}

extern DRV_HANDLE UART_Handle;
void HM_UART_WriteOneByte(uint8_t byte)
{
    DRV_USART_WriteByte(UART_Handle, byte);
}