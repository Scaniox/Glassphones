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
#include "timer.h"
#include "key.h"
#include "bt_app.h"
#ifdef _LIGHTING_CTRL
#include "lighting_ctrl.h"
#endif
#include "bt_command_send.h"
#include "bt_command_decode.h"
#include "sta369bwdsp_handler.h"
#include "bt_line_in.h"
#include "led.h"

void Timer_1ms(void)
{
    BTAPP_Timer1MS_event();
    BT_CommandSend1MS_event();
    KEY_Timer1MS_event();
    DSP_Timer1MS_event();
    AnalogAudioDetect_Timer1MS_event();
    KeyHandlers_Timer1MS_event();
    LED_timer_1ms();
}

void Timer_312_5us(void)
{
#ifdef _LIGHTING_CTRL
    LightingCtrl_Process();
#endif
}
