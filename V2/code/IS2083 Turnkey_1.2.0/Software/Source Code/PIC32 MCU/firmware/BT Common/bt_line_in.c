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
#include "bt_line_in.h"
#include "bt_hfp.h"
#include "bt_volume.h"
#include "bt_a2dp.h"
#include "bt_command_send.h"
#include "bt_app.h"
#include "led.h"

enum
{
	AUDIO_A2DP = 0,
	AUDIO_AUXIN,		
};

#define BTM_PORT_READ_INTERNAL_MS       500
#define PORT_DETECT_INTERVAL_MS        50
#define ANG_POSITIVE_VALIDATE_CNT       3
#define ANG_LOSS_VALIDATE_TIME_CNT      3
static uint16_t    ang_audio_detect_cnt = 0;
static uint8_t     ang_audio_detect_input;
static uint8_t     audio_selected = AUDIO_A2DP;
static uint8_t     auxin_plugged = 0;
static uint16_t    lineInTimer1ms;
bool        lineInCmdSendReq = false;
BT_LINE_IN_STATUS LineInStatus;
#ifdef _CODE_FOR_APP
void AppsReportLineInStatus( void );
#endif
/*-----------------------------------------------------------------------------*/
static void AnalogAudioDetect(void)
{
    uint8_t current_ang_input = LINE_IN_DETECT_STATUS_GET();

    if(current_ang_input != ang_audio_detect_input)
    {
        ang_audio_detect_cnt = 0;
        ang_audio_detect_input = current_ang_input;
    }
    else
    {
        if(ang_audio_detect_cnt <= 60000)
            ang_audio_detect_cnt ++;
    }

    if(auxin_plugged == 0) //current is BT selected
    {
        if(!ang_audio_detect_input && (ang_audio_detect_cnt > ANG_POSITIVE_VALIDATE_CNT))
        {
            auxin_plugged = 1;
			lineInCmdSendReq = true;    //BTAPP_LineInEvent(1);
        }
    }
    else        //current is AUX selected
    {
        if(ang_audio_detect_input && (ang_audio_detect_cnt > ANG_LOSS_VALIDATE_TIME_CNT))
        {
            auxin_plugged = 0;
            lineInCmdSendReq = true;    //BTAPP_LineInEvent(0);
        }
    }
}

/*-----------------------------------------------------------------------------*/
void AnalogAudioDetectInit(void)
{
    lineInTimer1ms = 10;
    audio_selected = 0;
    ang_audio_detect_input = 0;     //depend on circuit...
}

/*-----------------------------------------------------------------------------*/
void AnalogAudioDetectTask(void)
{
#ifdef _NO_EVENT_WHEN_LINE_IN_OUT    
    uint8_t temp[2];
    temp[0] = 0;
    temp[1] = LINE_IN_INACTIVE;
#endif
    if(lineInTimer1ms == 0)
    {
        AnalogAudioDetect();
        lineInTimer1ms = PORT_DETECT_INTERVAL_MS;
    }
    if (BTAPP_GetStatus() == BT_STATUS_ON || BTAPP_GetStatus() == BT_STATUS_READY) {
        if ( lineInCmdSendReq ) 
		{
            lineInCmdSendReq = false;
            audio_selected = auxin_plugged ? AUDIO_AUXIN : AUDIO_A2DP;		
            if( audio_selected == AUDIO_AUXIN )
            {
                BTMA2DP_PauseStart();//BT_MusicControlCommand(6, BT_linkIndex);
                BT_EnterLineInMode(1, 0);
            }
		    else
            {
                BT_EnterLineInMode(0, 0);
		        BTMA2DP_PlayStart();//BT_MusicControlCommand(5, BT_linkIndex);
               
#ifdef _NO_EVENT_WHEN_LINE_IN_OUT //patch when BTM has bug that not reporting line out event
                BTM_LINE_IN_EventHandler(BT_EVENT_LINE_IN_STATUS, &temp, 2);        //MCU issue this event, because BTM always forget to report this event            
#endif                
            }
       }
    }
}

/*-----------------------------------------------------------------------------*/
void AnalogAudioDetect_Timer1MS_event()
{
    if(lineInTimer1ms)
        -- lineInTimer1ms;
}

/*-----------------------------------------------------------------------------*/
void BTM_LINE_IN_EventHandler( BT_LINE_IN_EVENTS event, uint8_t* paras, uint16_t size )
{
    switch( event )
    {
        case BT_EVENT_LINE_IN_STATUS:
            LineInStatus = paras[1];
            if(LineInStatus != LINE_IN_INACTIVE)
            {
				if(BTMHFP_GetCallStatus() == BT_CALL_IDLE)       //not in SCO mode
                {
                    Set_LED_Style(LED_0, LED_BLINK, 500, 500);          //1HZ blinking indicating LINE IN mode.
				}
            }
            else
            {
				if(BTMHFP_GetCallStatus() != BT_CALL_IDLE)           //if it is SCO mode, back to SCO(this is not possible but safe for code)
                {
                    BTVOL_ChangeVolMode(HFP_VOL_MODE, false);
                }
                Set_LED_Style(LED_0, LED_ON, 500, 500); //restore power indication
            }
#ifdef _CODE_FOR_APP
            AppsReportLineInStatus();
#endif
            break;
            
        default:
            break;
    }
}

/*-----------------------------------------------------------------------------*/
BT_LINE_IN_STATUS BTM_LINE_IN_GetLineInStatus( void )
{
#if 1       //because BTM has bug at reporting LINE IN status, so not use this variable LineInStatus
    return LineInStatus;
#else
    if( audio_selected == AUDIO_AUXIN )
        return LINE_IN_ACTIVE;
    else
        return LINE_IN_INACTIVE;
#endif
}
   
/*-----------------------------------------------------------------------------*/
bool BTM_LINE_IN_IsPlugged( void )
{
    return auxin_plugged;
}

/*-----------------------------------------------------------------------------*/
void BTM_LINE_IN_Init( void )
{
    LineInStatus = LINE_IN_INACTIVE;
    audio_selected = AUDIO_A2DP;
    auxin_plugged = 0;
}

/*-----------------------------------------------------------------------------*/

