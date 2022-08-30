/*
  Project Name: BM8x EVB                            Module name:sta369bwdsp_handler.c
  Bluetooth Chip: IS208x	                        Bluetooth UI Version:
  MCU chip: BT5511
  Oscillator:                                   	Freq: 
  Author: Niranjan Bharadwaj K R
  Kick off date: 2018-04-04
  Copyright: 2018 Microchip Technologies Corp.. All Rights Reserved.
*/

#ifndef _STA369BWDSP_HANDLER_H_
#define _STA369BWDSP_HANDLER_H_
#include <stdbool.h>
#include <stdint.h>

//#define GET_ARRAY_LEN(array)  ( sizeof(array)/sizeof (array[0] ) )


/*---------------------------------------------------------
  General Constant Define
*/


//STA369BW register define
#define CONFA                                       0x00                
#define CONFD                                       0x03                
#define CONFE                                       0x04
#define CONFF                                       0x05                
#define MUTELOC                                     0x06
#define MVOL                                        0x07                
#define C1VOL                                       0x08
#define C2VOL                                       0x09                
#define C3VOL                                       0x0A                
#define APRE                                        0x0C
#define C1CFG                                       0x0E                
#define C2CFG                                       0x0F                

#define CONFA_IRMASK                                0x18
#define CONFA_NORMALIRMASK                          0xE7
#define CONFA_HIGHIRMASK                            0x08

//Register contents, refer to STA369BWA30
#define CONFD_DEFAULT                               0x40
#define CONFD_DSPB			                        0x04
#define CONFD_PSL			                        0x08

#define CONFE_DEFAULT                               0xC2
#define CONFE_SVE_INV		                        0x7F

#define CONFF_DEFAULT                               0x5C
#define CONFF_EAPD			                        0x80
#define CONFF_PWDN			                        0x40

#define MUTE_DEFAULT								0x00
#define MUTE_MMUTE									0x01
#define MUTE_C1MUTE									0x02
#define MUTE_C2MUTE									0x04
#define MUTE_C3MUTE									0x08

#define APRE_100HZ                                  0x20

#define C1CFG_DEFAULT                               0x00
#define CxCFG_TCB		                            0x01                
#define CxCFG_EQBP		                            0x02

#define STA369BW_QMUTE_WAIT_TIMER                     30                  //unit:1ms
#define STA369BW_DSP_STOP_WAIT_TIMER                  10                  //unit:1ms

/*---------------------------------------------------------
  Function Define
*/




/*-----------------------------------------------------------------------------
  This function used to initialize dsp
*/
void sta369bwdsp_init(void);
void sta369bwdsp_task(void);
bool is_sta369bwdsp_idle(void);
bool is_sta369bwdsp_ready(void);
void sta369bwdsp_start(void);


/*-----------------------------------------------------------------------------
  This function used to enable playback
*/
//void sta369bw_playback(void);


/*-----------------------------------------------------------------------------
  This function used to stop playbck
*/
//void sta369bw_stop(void);
/*-----------------------------------------------------------------------------
  This function used to start playbck
*/
void sta369bw_DSPStart(void);
/*-----------------------------------------------------------------------------
  This function used to support input sampling rate > 50KHZ
*/
void sta369bw_setHighSamplingrateInput(void);
/*-----------------------------------------------------------------------------
  This function used to support input sampling rate <= 50KHZ
*/
void sta369bw_setNormalSamplingrateInput(void);
void sta369bw_voladj(void);
void sta369bw_vol_up(void);
void sta369bw_vol_down(void);
void sta369bw_DSPStop(void);
void sta369bw_SetVol(uint8_t vol);
void sta369bw_SoftMute(void);
void sta369bw_SoftMuteOff(void);
void DSP_Timer1MS_event(void);
//void mute_on_test(void);
//void mute_off_test(void);

#define EXT_DSP_INIT_VOL 15
#define	MAX_VOL_TAB      30

#endif      //_DSP_HANDLER_H_
