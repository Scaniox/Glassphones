/*******************************************************************************
 System Interrupts File

  File Name:
    system_interrupt.c

  Summary:
    Raw ISR definitions.

  Description:
    This file contains a definitions of the raw ISRs required to support the
    interrupt sub-system.

  Summary:
    This file contains source code for the interrupt vector functions in the
    system.

  Description:
    This file contains source code for the interrupt vector functions in the
    system.  It implements the system and part specific vector "stub" functions
    from which the individual "Tasks" functions are called for any modules
    executing interrupt-driven in the MPLAB Harmony system.

  Remarks:
    This file requires access to the systemObjects global data structure that
    contains the object handles to all MPLAB Harmony module objects executing
    interrupt-driven in the system.  These handles are passed into the individual
    module "Tasks" functions to identify the instance of the module to maintain.
 *******************************************************************************/

// DOM-IGNORE-BEGIN
/*******************************************************************************
Copyright (c) 2011-2014 released Microchip Technology Inc.  All rights reserved.

Microchip licenses to you the right to use, modify, copy and distribute
Software only when embedded on a Microchip microcontroller or digital signal
controller that is integrated into your product or third party product
(pursuant to the sublicense terms in the accompanying license agreement).

You should refer to the license agreement accompanying this Software for
additional information regarding your rights and obligations.

SOFTWARE AND DOCUMENTATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF
MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE.
IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR OBLIGATED UNDER
CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR
OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES
INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE OR
CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PROCUREMENT OF
SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES
(INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.
 *******************************************************************************/
// DOM-IGNORE-END

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include <xc.h>
#include <sys/attribs.h>
#include "app.h"
#include "system_definitions.h"
#include "bt_hardware_profile.h"
#include "bt_command_send.h"
#include "bt_command_decode.h"

// *****************************************************************************
// *****************************************************************************
// Section: System Interrupt Vector Functions
// *****************************************************************************
// *****************************************************************************

    
void __ISR(_TIMER_1_VECTOR, ipl2AUTO) IntHandlerDrvTmrInstance0(void)
{
    PLIB_INT_SourceFlagClear(INT_ID_0,INT_SOURCE_TIMER_1);
    Timer_1ms();
}
    
void __ISR(_TIMER_2_VECTOR, ipl3AUTO) IntHandlerDrvTmrInstance1(void)
{
    PLIB_INT_SourceFlagClear(INT_ID_0,INT_SOURCE_TIMER_2);
    Timer_312_5us();
}
 void __ISR(_UART_1_VECTOR, ipl4AUTO) _IntHandlerDrvUsartInstance0(void)
{
    if(SYS_INT_SourceStatusGet(INT_SOURCE_USART_1_TRANSMIT) && SYS_INT_SourceIsEnabled(INT_SOURCE_USART_1_TRANSMIT) )
    {
        /* Disable the interrupt, to avoid calling ISR continuously*/
        SYS_INT_SourceDisable(INT_SOURCE_USART_1_TRANSMIT);
        BT_UART_TX_ISR();
        /* Clear up the interrupt flag */
        SYS_INT_SourceStatusClear(INT_SOURCE_USART_1_TRANSMIT);
    }
    if(SYS_INT_SourceStatusGet(INT_SOURCE_USART_1_RECEIVE))
    {
        BT_UART_RX_ISR();
        /* Clear up the interrupt flag */
        SYS_INT_SourceStatusClear(INT_SOURCE_USART_1_RECEIVE);
    }
    //DRV_USART_TasksTransmit(sysObj.drvUsart0);
    //DRV_USART_TasksReceive(sysObj.drvUsart0);
    DRV_USART_TasksError(sysObj.drvUsart0);
}
 

 

 

 

 

 

 
 

void __ISR(_I2C_1_VECTOR, ipl1AUTO) _IntHandlerDrvI2CInstance0(void)
{
	DRV_I2C0_Tasks();
 
}
         
 
   
  
   
   
   
  
 

  
  
  
  
/*******************************************************************************
 End of File
*/

