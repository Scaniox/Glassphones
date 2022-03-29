/*****************************************************************************
                     Microchip Technology Incorporated

    FileName:        key.c
    Dependencies:    See Includes Section
    Processor:       PIC24, PIC32

Copyright � 2009-2013 Microchip Technology Inc.  All rights reserved.

Microchip licenses to you the right to use, modify, copy and distribute
Software only when embedded on a Microchip microcontroller or digital signal
controller that is integrated into your product or third party product
(pursuant to the sublicense terms in the accompanying license agreement).

You should refer to the license agreement accompanying this Software for
additional information regarding your rights and obligations.

SOFTWARE AND DOCUMENTATION ARE PROVIDED ?AS IS? WITHOUT WARRANTY OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF
MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE.
IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR OBLIGATED UNDER
CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR
OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES
INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE OR
CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PROCUREMENT OF
SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES
(INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.

******************************************************************************/
#include <xc.h>
#define KEY_C
#include "key.h"
#include "key_handler.h"
#include "bt_hardware_profile.h"
////////////////////////////////////////////////////////////////////////////////
#define KEY_NUMBER_OF 8

const uint8_t keyInitMap[KEY_NUMBER_OF] =
{
    KEY_ID_PLAY_PAUSE,
    KEY_ID_PAIRING,
    KEY_ID_FUNC1,   //for stereo mode group
    KEY_ID_FUNC2,   //for concert mode group
    KEY_ID_FWD,
    KEY_ID_REV,
    KEY_ID_VOL_UP,
    KEY_ID_VOL_DN,
};

const uint8_t keyInitMapMode[KEY_NUMBER_OF] =
{
    KEY_MODE_TREBLE_ACTION ,  //PLAY_PAUSE
    KEY_MODE_TREBLE_ACTION2 ,  //PAIRING
    KEY_MODE_DUAL_ACTION ,  //FUNC1(for stereo mode group)
    KEY_MODE_TREBLE_ACTION ,  //FUNC2(for concert mode group)
    KEY_MODE_DUAL_ACTION ,  //REV
    KEY_MODE_DUAL_ACTION ,  //FWD
    KEY_MODE_TREBLE_ACTION , //KEY_MODE_AUTOREPEAT ,   //VOL UP
    KEY_MODE_TREBLE_ACTION , //KEY_MODE_AUTOREPEAT ,   //VOL DN
};

KEY_STATE keyState[KEY_NUMBER_OF];
uint8_t keyTimer = 0;

//static void KEY_Process ( KEY_STATE *key, uint16_t time );
////////////////////////////////////////////////////////////////////////////////

void KEY_Initialize ( void )
{
    uint8_t i;
    for(i = 0; i< KEY_NUMBER_OF; i++)
    {
        keyState[i].id = keyInitMap[i];
        keyState[i].mode = keyInitMapMode[i];
        keyState[i].state = 0;
        keyState[i].time = 0;
    }
}

////////////////////////////////////////////////////////////////////////////////
uint16_t SYSTEM_GetKeys ( void )
{
    uint16_t state = 0;
    
    if(KEY0_STATUS_GET())
        state = 0x0001;
    if(KEY1_STATUS_GET())
        state |= 0x0002;
    if(KEY2_STATUS_GET())
        state |= 0x0004;
    if(KEY3_STATUS_GET())
        state |= 0x0008;
    if(KEY4_STATUS_GET())
        state |= 0x0010;
    if(KEY5_STATUS_GET())
        state |= 0x0020;
    if(KEY6_STATUS_GET())
        state |= 0x0040;
    if(KEY7_STATUS_GET())
        state |= 0x0080;
    
    state ^= 0b0000000011111111;

    return  ( state );
}
////////////////////////////////////////////////////////////////////////////////

void KEY_Timer1MS_event(void)
{
    if(keyTimer)
        --keyTimer;
}

void KEY_Task ( void )
{
    uint8_t i;
    uint16_t state;

    if(keyTimer)
        return;
    keyTimer = KEY_TASK_PERIOD;

    state = SYSTEM_GetKeys ();

    for ( i = 0; i < KEY_NUMBER_OF; i ++ )
    {
        keyState[i].state = state & 1;
        state >>= 1;
        KEY_Process ( &keyState[i], KEY_TASK_PERIOD );
    }
}

////////////////////////////////////////////////////////////////////////////////

void KEY_Process ( KEY_STATE *key, uint16_t time )
{
    if ( key->mode == KEY_MODE_DISABLED )
    {
        return;
    }

    if ( key->state == true )
    {
        if(key->time < 60000)
            key->time += time;
    }
    else
    {
        if( key->time_last_off < 60000 )
            key->time_last_off += time;
    }

    switch ( key->mode )
    {
        case KEY_MODE_CONTINUOUS:
            if ( key->state == true )
            {
                KEY_Handler ( key->id, KEY_EVENT_PRIMARY );     //send button every KEY_TASK_PERIOD ms
                key->last_action = KEY_EVENT_PRIMARY;
            }
            
            if (( key->time != 0 ) && ( key->state == false ))      //when key is released
            {
                key->time_last_off = 0;
            }
            break;

        case KEY_MODE_AUTOREPEAT:
            if (( key->time != 0 )
            && ( key->time < KEY_AUTOREPEAT_DELAY )
            && ( key->state == false ))
            {
                KEY_Handler ( key->id, KEY_EVENT_PRIMARY );     //for repeating button, send once if pressing time is short
                key->last_action = KEY_EVENT_PRIMARY;
            }
            else if (( key->time > KEY_AUTOREPEAT_DELAY + KEY_AUTOREPEAT_RATE ) && ( key->state == true ))
            {
                KEY_Handler ( key->id, KEY_EVENT_PRIMARY );     //for repeating button, send button repeatly
                key->time -= KEY_AUTOREPEAT_RATE;
                key->last_action = KEY_EVENT_PRIMARY;
            }
            
            if (( key->time != 0 ) && ( key->state == false ))      //when key is released
            {
                key->time_last_off = 0;
            }
            break;
            
        case KEY_MODE_SINGLE_ACTION:
            if (( key->time != 0 ) && ( key->state == false ))
            {
                KEY_Handler ( key->id, KEY_EVENT_PRIMARY );     //send button only once for every button pressing action, send button out at KEY_TASK_PERIOD ms
                key->last_action = KEY_EVENT_PRIMARY;
            }
            
            if (( key->time != 0 ) && ( key->state == false ))      //when key is released
            {
                key->time_last_off = 0;
            }
            break;

        case KEY_MODE_DUAL_ACTION:
            if (( key->time != 0 )
            && ( key->time < KEY_SINGLE_ACTION_DELAY )
            && ( key->state == false ))
            {
                KEY_Handler ( key->id, KEY_EVENT_PRIMARY );  //send a short pressing button for once at false edge
                key->last_action = KEY_EVENT_PRIMARY;
            }
            else if (( key->time == KEY_SINGLE_ACTION_DELAY ) && ( key->state == true ))
            {
                KEY_Handler ( key->id, KEY_EVENT_SECONDARY ); //send a long pressing button when button is holding
                key->last_action = KEY_EVENT_SECONDARY;
            }
            else if(( key->time != 0 )
            && ( key->time > KEY_SINGLE_ACTION_DELAY)
            && ( key->state == false ))
            {
                KEY_Handler ( key->id, KEY_EVENT_SECONDARY_RELEASED );
            }
            
            if (( key->time != 0 ) && ( key->state == false ))      //when key is released
            {
                key->time_last_off = 0;
            }
            break;

        case KEY_MODE_TREBLE_ACTION:
            //single click check		
            if( ( key->time == 0 ) 
                    && ( key->state == false )
                    && ( key->time_last_off > KEY_TREBLE_ACTION_OFF_DELAY)
                    && (key->last_action == KEY_EVENT_PRIMARY) )
            {
                KEY_Handler ( key->id, KEY_EVENT_PRIMARY/*KEY_EVENT_SINGLE_CLICK*/ );
                key->last_action = KEY_EVENT_NOT_HANDLE;
            }
            
            if (( key->time != 0 )
            && ( key->time < KEY_SINGLE_ACTION_DELAY )
            && ( key->state == false ))
            {
                //double click check
                if(key->time_last_off <= KEY_TREBLE_ACTION_OFF_DELAY && key->last_action == KEY_EVENT_PRIMARY)
                {
                    KEY_Handler ( key->id, KEY_EVENT_DOUBLE_CLICK );
                    key->last_action = KEY_EVENT_DOUBLE_CLICK;
                }
                else    //button short press check
                {
                    //...KEY_Handler ( key->id, KEY_EVENT_PRIMARY );  //send a short pressing button for once at false edge
                    key->last_action = KEY_EVENT_PRIMARY;
                }
            }
            else if (( key->time == KEY_SINGLE_ACTION_DELAY ) && ( key->state == true ))        //button long press check
            {
                KEY_Handler ( key->id, KEY_EVENT_SECONDARY ); //send a long pressing button when button is holding
                key->last_action = KEY_EVENT_SECONDARY;
            }
            
            if (( key->time != 0 ) && ( key->state == false ))      //when key is released
            {
                key->time_last_off = 0;
            }
            break;

        case KEY_MODE_TREBLE_ACTION2:
            if (( key->time != 0 )
            && ( key->time < KEY_SINGLE_ACTION_DELAY )
            && ( key->state == false ))
            {
                KEY_Handler ( key->id, KEY_EVENT_PRIMARY );  //send a short pressing button for once at false edge
                key->last_action = KEY_EVENT_PRIMARY;
            }
            else if (( key->time == KEY_SINGLE_ACTION_DELAY ) && ( key->state == true ))
            {
                KEY_Handler ( key->id, KEY_EVENT_SECONDARY ); //send a long pressing button when button is holding
                key->last_action = KEY_EVENT_SECONDARY;
            }
            else if(( key->time != 0 )
            && ( key->time == (KEY_SINGLE_ACTION_DELAY + KEY_SECONDARY_HOLD_DELAY) )
            && ( key->state == true ))
            {
                KEY_Handler ( key->id, KEY_EVENT_SECONDARY_HOLD );
                key->last_action = KEY_EVENT_SECONDARY_HOLD;
            }
            
            if (( key->time != 0 ) && ( key->state == false ))      //when key is released
            {
                key->time_last_off = 0;
            }
            break;


            
        default:
            break;
    }

    if(( key->id == KEY_ID_PAIRING )            //hole PIRING button for 6 seconds, to reset EEPROM
            && ( key->time == 6000 )       //6 seconds hold
            && ( key->state == true ))      //hold status
    {
        KEY_Handler ( key->id, KEY_EVENT_LONG_TIME_HOLD );
    }
    
    if ( key->state == false )
    {
        key->time = 0;
    }
}

////////////////////////////////////////////////////////////////////////////////
