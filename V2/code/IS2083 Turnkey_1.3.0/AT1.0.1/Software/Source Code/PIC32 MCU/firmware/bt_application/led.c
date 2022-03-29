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
#include "led.h"
#include "bt_hardware_profile.h"

struct {
    uint16_t LED_timer;
    uint16_t LED_on_period;
    uint16_t LED_off_period;
    LED_ACTION LED_action;
} LED[LED_INDEX_MAX];

static void LED_process( uint16_t index );

void LED_init(void)
{
    uint16_t i;
    for(i = 0; i< LED_INDEX_MAX; i++)
    {
        LED[i].LED_action = LED_NOT_CTRL;
        LED[i].LED_timer = 100;
        LED[i].LED_on_period = 100;
        LED[i].LED_off_period = 100;
    }
}

void LED_timer_1ms(void)
{
    uint16_t i;
    for(i = 0; i< LED_INDEX_MAX; i++)
    {
        --LED[i].LED_timer;
        if(!LED[i].LED_timer)
        {
            LED_process(i);
        }
    }
}

void LED_process( uint16_t index )
{
    if(index < LED_INDEX_MAX)
    {
        if(LED[index].LED_action == LED_NOT_CTRL)
        {
            
        }
        else if(LED[index].LED_action == LED_ON)
        {
            switch(index)
            {
                case LED_0:
                    LED0_ON();
                    break;
                case LED_1:
                    LED1_ON();
                    break;
                case LED_2:
                    LED2_ON();
                    break;
                case LED_3:
                    LED3_ON();
                    break;
                case LED_4:
                    LED4_ON();
                    break;
                case LED_5:
                    LED5_ON();
                    break;
                case LED_6:
                    LED6_ON();
                    break;
                case LED_7:
                    LED7_ON();
                    break;
                default:
                    break;
            }
            LED[index].LED_timer = 500;
        }
        else if(LED[index].LED_action == LED_OFF)
        {
            switch(index)
            {
                case LED_0:
                    LED0_OFF();
                    break;
                case LED_1:
                    LED1_OFF();
                    break;
                case LED_2:
                    LED2_OFF();
                    break;
                case LED_3:
                    LED3_OFF();
                    break;
                case LED_4:
                    LED4_OFF();
                    break;
                case LED_5:
                    LED5_OFF();
                    break;
                case LED_6:
                    LED6_OFF();
                    break;
                case LED_7:
                    LED7_OFF();
                    break;
                default:
                    break;
            }
            LED[index].LED_timer = 500;
        }
        else
        {
            switch(index)
            {
                case LED_0:
                    LED0_TOGGLE();
                    if(LED0_STATUS_GET())
                        LED[index].LED_timer = LED[index].LED_off_period;
                    else
                        LED[index].LED_timer = LED[index].LED_on_period;
                    break;
                case LED_1:
                    LED1_TOGGLE();
                    if(LED1_STATUS_GET())
                        LED[index].LED_timer = LED[index].LED_off_period;
                    else
                        LED[index].LED_timer = LED[index].LED_on_period;
                    break;
                case LED_2:
                    LED2_TOGGLE();
                    if(LED2_STATUS_GET())
                        LED[index].LED_timer = LED[index].LED_off_period;
                    else
                        LED[index].LED_timer = LED[index].LED_on_period;
                    break;
                case LED_3:
                    LED3_TOGGLE();
                    if(LED3_STATUS_GET())
                        LED[index].LED_timer = LED[index].LED_off_period;
                    else
                        LED[index].LED_timer = LED[index].LED_on_period;
                    break;
                case LED_4:
                    LED4_TOGGLE();
                    if(LED4_STATUS_GET())
                        LED[index].LED_timer = LED[index].LED_off_period;
                    else
                        LED[index].LED_timer = LED[index].LED_on_period;
                    break;
                case LED_5:
                    LED5_TOGGLE();
                    if(LED5_STATUS_GET())
                        LED[index].LED_timer = LED[index].LED_off_period;
                    else
                        LED[index].LED_timer = LED[index].LED_on_period;
                    break;
                case LED_6:
                    LED6_TOGGLE();
                    if(LED6_STATUS_GET())
                        LED[index].LED_timer = LED[index].LED_off_period;
                    else
                        LED[index].LED_timer = LED[index].LED_on_period;
                    break;
                case LED_7:
                    LED7_TOGGLE();
                    if(LED7_STATUS_GET())
                        LED[index].LED_timer = LED[index].LED_off_period;
                    else
                        LED[index].LED_timer = LED[index].LED_on_period;
                    break;
                default:
                    break;
            }
        }
    }
}

void Set_LED_Style(LED_INDEX index, LED_ACTION action, uint16_t LED_on_period_1ms, uint16_t LED_off_period_1ms)
{
    LED[index].LED_action = action;
    LED[index].LED_on_period = LED_on_period_1ms;
    LED[index].LED_off_period = LED_off_period_1ms;
    if(action == LED_BLINK)
    {
        switch(index)
        {
            case LED_0:
                LED0_OFF();
                break;
            case LED_1:
                LED1_OFF();
                break;
            case LED_2:
                LED2_OFF();
                break;
            case LED_3:
                LED3_OFF();
                break;
            case LED_4:
                LED4_OFF();
                break;
            case LED_5:
                LED5_OFF();
                break;
            case LED_6:
                LED6_OFF();
                break;
            case LED_7:
                LED7_OFF();
                break;
        }
    }
    LED_process(index);
}

