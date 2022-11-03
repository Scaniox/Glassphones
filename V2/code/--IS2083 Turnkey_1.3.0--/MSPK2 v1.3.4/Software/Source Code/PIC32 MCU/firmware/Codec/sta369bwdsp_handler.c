/*
  Project Name: BM89 EVB                            Module name:sta369bwdsp_handler.c
  Bluetooth Chip: IS1689-151                        Bluetooth UI Version:
  MCU chip: SH79F6488
  Oscillator: IRIC                                  Freq: 12MHz
  Author: Jerry.Chen
  Kick off date: 2014-04-03
  Copyright: 2014 ISSC Technologies Corp.. All Rights Reserved.
*/

#include <xc.h>
#include "bt_hardware_profile.h"
#include "bt_app.h"
#include "sta369bwdsp_handler.h"


#if defined (__XC32__)      //PIC32 harmony based driver
#define DELAY_NUM 500
extern DRV_HANDLE I2C_Handle;
DRV_I2C_BUFFER_HANDLE I2C_bufferHandle = NULL;
#else       //8bit MCC based driver
#define DELAY_NUM 80
I2C_MESSAGE_STATUS i2c_status;
#endif

enum {
    ST_STA369BW_IDLE, 
    ST_STA369BW_START,    
    ST_STA369BW_RESET_LOW_WAIT,
    ST_STA369BW_RESET_HIGH_WAIT,
    ST_STA369BW_INIT_REG,
    ST_STA369BW_WAIT_INIT_REG,
    ST_STA369BW_INIT_EQ_COEF,
    ST_STA369BW_SETUP_VOL,
   // ST_STA369BW_READ_REG, //This state is for Debugging
    ST_STA369BW_RUNNING,
    ST_STA369BW_STARTING_POWER_OFF,
    ST_STA369BW_POWER_OFF_1,
    ST_STA369BW_POWER_OFF_2
};

uint8_t sta369bw_state;

uint8_t ext_dsp_vol;
//#define EXT_DSP_INIT_VOL 10//20
uint8_t   ram_bank_bak;
uint8_t I2C_limitedTimer;
uint16_t DSP_Timer;
#define STADSP_DATA_BUFF_SIZE 20
uint8_t   sta_data_buff[STADSP_DATA_BUFF_SIZE];
//I2C_MESSAGE_STATUS i2c_status;
#if defined (__XC32__)      //PIC32 harmony based driver
#define DSP_I2C_ADDR1 0x38
#else               //MCC I2C driver
#define DSP_I2C_ADDR1 0x38
#endif

const uint8_t STA369_Reg_Init_Table[][2]=
{
		{0x00,0x64},    //  ## Configuration Register A
		{0x01,0x80},    //  ## Configuration Register B
		{0x02,0x9F},    //  ## Configuration Register C
		{0x03,0x45},    //  ## Configuration Register D //HPF Bypass and DSP Bypass
		{0x04,0xC2},    //  ## Configuration Register E
		{0x05,0xD8},    //  ## Configuration Register F // 2 Ch
		{0x06,0x00},    //  ## Master Mute
		{0x07,0x00},    //  ## Master Volume
		{0x08,0x49},    //  ## Channel 1 Volume
		{0x09,0x49},    //  ## Channel 2 Volume
		{0x0A,0x47},    //  ## Channel 3 Volume
		{0x0B,0x00},    //  ## Audio Preset Register 1
		{0x0C,0x20},    //  ## Audio Preset Register 2
		{0x0E,0x10},    //  ## Channel 1 Config
		{0x0F,0x50},    //  ## Channel 2 Config
		{0x10,0xA0},    //  ## Channel 3 Config
		{0x11,0x77},    //  ## Bass and Treble Tone Control
		{0x12,0x11},    //  ## Limiter 1 Attack/Release Rate
		{0x13,0x69},    //  ## Limiter 1 Attack/Release Threshold
		{0x14,0x6A},    //  ## Limiter 2 Attack/Release Rate
		{0x15,0x59},    //  ## Limiter 2 Attack/Release Threshold
		{0x16,0x00},    //  ## Coefficient Address Bits 5..0
		{0x17,0x00},    //  ## Coefficient b1 Data Bits 23..16
		{0x18,0x00},    //  ## Coefficient b1 Data Bits 15..8
		{0x19,0x00},    //  ## Coefficient b1 Data Bits 7..0
		{0x1A,0x00},    //  ## Coefficient b2 Data Bits 23..16
		{0x1B,0x00},    //  ## Coefficient b2 Data Bits 15..8
		{0x1C,0x00},    //  ## Coefficient b2 Data Bits 7..0
		{0x1D,0x00},    //  ## Coefficient a1 Data Bits 23..16
		{0x1E,0x00},    //  ## Coefficient a1 Data Bits 15..8
		{0x1F,0x00},    //  ## Coefficient a1 Data Bits 7..0
		{0x20,0x00},    //  ## Coefficient a2 Data Bits 23..16
		{0x21,0x00},    //  ## Coefficient a2 Data Bits 15..8
		{0x22,0x00},    //  ## Coefficient a2 Data Bits 7..0
		{0x23,0x00},    //  ## Coefficient b0 Data Bits 23..16
		{0x24,0x00},    //  ## Coefficient b0 Data Bits 15..8
		{0x25,0x00},    //  ## Coefficient b0 Data Bits 7..0
		{0x26,0x00},    //  ## Coefficient Write Control
		{0x27,0x1A},    //  ## Max Power Correction Config Msb
		{0x28,0xC0},    //  ## Max Power Correction Config Lsb
		{0x29,0xF3},    //  ## Variable Distortion Compensation Msb
		{0x2A,0x33},    //  ## Variable Distortion Compensation Lsb
		{0x2B,0x00},    //  ## Fault Detect Recovery Bits Msb
		{0x2C,0x0C},    //  ## Fault Detect Recovery Bits Lsb
		{0x2D,0x00},    //  ## Device Status
		{0x31,0x00},    //  ## EQ Coeff and DRC Configuration
		{0x32,0xB8},    //  ## Limiter 1 Ext.Attack Threshold
		{0x33,0xB0},    //  ## Limiter 1 Ext.Release Threshold
		{0x34,0xB5},    //  ## Limiter 2 Ext.Attack Threshold
		{0x35,0xB0},    //  ## Limiter 2 Ext.Release Threshold
		{0x36,0x00},    //  ## Extended Configuraton Register
		{0x37,0x00},    //  ## EQ Soft Volume Config (fade-in)
		{0x38,0x00},    //  ## EQ Soft Volume Config (fade-out)
		{0x39,0x01},    //  ## DRC RMS Filter Coefficient C0 Bits 25..16
		{0x3A,0xEE},    //  ## DRC RMS Filter Coefficient C0 Bits 15..8
		{0x3B,0xFF},    //  ## DRC RMS Filter Coefficient C0 Bits 7..0
		{0x3C,0x7E},    //  ## DRC RMS Filter Coefficient C1 Bits 25..16
		{0x3D,0xC0},    //  ## DRC RMS Filter Coefficient C1 Bits 15..8
		{0x3E,0x26},    //  ## DRC RMS Filter Coefficient C1 Bits 7..0
		{0x3F,0x00},    //  ## Extended Volume Resolution
		{0x48,0x00},    //  ## Noise Shaping
		{0x49,0x00},    //  ## Extended Coef Range 4-1
		{0x4A,0x00},    //  ## Extended Coef Range 7-5
		{0x4B,0x04},    //  ## Miscellaneous 1
		{0x4C,0x00}     //  ## Miscellaneous 2
};

const uint8_t EQ_Coeff_Table[7][15] = 
{
	{0x80,0x59,0x77,0x7e,0xb1,0xF3,0x7F,0xa6,0x89,0x80,0xaf,0xdd,0x40,0x4f,0x17},    // 48KFs, Biquad1, Address: 0x00~0x04 (stability: 0.998904)
	{0x80,0x7c,0x42,0x7f,0x16,0xa3,0x7f,0x83,0xbe,0x80,0xf3,0x91,0x3f,0xfa,0xe6},    // 48KFs, Biquad2, Address: 0x05~0x09 (stability: 0.874438)
	{0x82,0xf9,0x3c,0x7a,0xf8,0x41,0x7d,0x06,0xc4,0x85,0x61,0x4c,0x3f,0xd3,0x39},    // 48KFs, Biquad3, Address: 0x0A~0x0E (stability: 0.960088)
	{0x9c,0x07,0x04,0x5d,0xb7,0xa2,0x63,0xf8,0xfc,0x9d,0x89,0x9d,0x42,0x5f,0x60},    // 48KFs, Biquad4, Address: 0x0F~0x13 (stability: 0.990952)
	{0xdc,0xf3,0x03,0x47,0x9c,0x47,0x23,0x0C,0xfd,0xbe,0xc1,0xc9,0x3c,0xd0,0xf7},    // 48KFs, Biquad5, Address: 0x14~0x18 (stability: 0.579496)
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x00,0x00},    // 48KFs, Biquad6, Address: 0x19~0x1D (stability: 0.928628)
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x00,0x00}     // 48KFs, Biquad7, Address: 0x1E~0x22 (stability: 0.838451)
};

const uint8_t VolTab[MAX_VOL_TAB+1] = {
       0xFF,	//-42    
       0xB4,	//-42
       0xAE,	//-39
       0xA8,	//-36
       0xA2,	//-33
       0x9C,	//-30	   
       0x90,	//-24
       0x84,	//-18
       0x7E,    //-15
       0x74,    //-10
       0x72,    //-9
       0x70,    //-8
       0x6F,    //-7.5
       0x6E,    //-7
       0x6D,    //-6.5
       0x6C,    //-6
       0x6B,    //-5.5
       0x6A,    //-5
       0x69,    //-4.5
       0x68,    //-4
       0x67,    //-3.5
       0x66,    //-3
       0x65,    //-2.5
       0x64,    //-2
       0x63,    //-1.5
       0x62,    //-1
       0x61,    //-0.5
       0x60,    //0
       0x5C,    //+2
       0x54,    //+6
       0x4E,    //+9
};

uint8_t sta369RegSet[77];

/*-----------------------------------------------------------------------------
Function name:
  sta369bwdsp_init
Description:
  This function used to initialize dsp

Notice:
  refer to p168~176 of the firmware manual of yamaha for intialization flow chart
  refer to p29~38 of sta369bwa30 for i2c interface
  refer to p111~ of sta369bwa30 for power on flow chart

Input Parameter:
  None
Return:
  None
*/
static bool DSP_Write(uint16_t dataLen, uint8_t* data)
{
#if defined (__XC32__)    
    DRV_I2C_BUFFER_EVENT result;
    while( !(I2C_bufferHandle == NULL 
            || DRV_I2C_TransferStatusGet(I2C_Handle, I2C_bufferHandle) == DRV_I2C_BUFFER_EVENT_COMPLETE 
            || DRV_I2C_TransferStatusGet(I2C_Handle, I2C_bufferHandle) == DRV_I2C_BUFFER_EVENT_ERROR ) )
    {
    }
    I2C_bufferHandle = DRV_I2C_Transmit(I2C_Handle, DSP_I2C_ADDR1, data, dataLen, NULL);

    I2C_limitedTimer = 10;

    while(I2C_limitedTimer)
    {
        result = DRV_I2C_TransferStatusGet(I2C_Handle, I2C_bufferHandle);
        if(result == DRV_I2C_BUFFER_EVENT_COMPLETE)
        {
            return true;
        }
        else if(result == DRV_I2C_BUFFER_EVENT_ERROR)
        {
            //LED5_TOGGLE();
            return false;
        }
    }
    return false;
#else
    while(I2C_MasterQueueIsFull() == true);

    I2C_MasterWrite(data, dataLen, DSP_I2C_ADDR1, &i2c_status);

    I2C_limitedTimer = 5;
    while(!I2C_IsIdle())
    {
        if(!I2C_limitedTimer)
            return false;
    }    
    return true;
#endif        
}

static bool DSP_Read(uint16_t txDataLen, uint8_t* txData, uint16_t rxDataLen, uint8_t* rxData)
{
#if defined (__XC32__)    
    DRV_I2C_BUFFER_EVENT result;
    while( !(I2C_bufferHandle == NULL 
            || DRV_I2C_TransferStatusGet(I2C_Handle, I2C_bufferHandle) == DRV_I2C_BUFFER_EVENT_COMPLETE 
            || DRV_I2C_TransferStatusGet(I2C_Handle, I2C_bufferHandle) == DRV_I2C_BUFFER_EVENT_ERROR ) )
    {
    }
    I2C_bufferHandle = DRV_I2C_TransmitThenReceive(I2C_Handle, DSP_I2C_ADDR1, txData, txDataLen, rxData, rxDataLen, NULL);

    I2C_limitedTimer = 10;

    while(I2C_limitedTimer)
    {
        result = DRV_I2C_TransferStatusGet(I2C_Handle, I2C_bufferHandle);
        if(result == DRV_I2C_BUFFER_EVENT_COMPLETE)
        {
            return true;
        }
        else if(result == DRV_I2C_BUFFER_EVENT_ERROR)
        {
            //LED5_TOGGLE();
            return false;
        }
    }
    return false;
#endif
}

void DSP_Timer1MS_event(void)
{
    //DSP_Timer++;
    if(DSP_Timer)
        --DSP_Timer;
    if(I2C_limitedTimer)
        --I2C_limitedTimer;
}
void Delay_Some(unsigned int D_Count)
{
    unsigned int i;
    for (i= 0; i< D_Count; i++)
        Nop();
}

void STA369_Reg_Init(void)
{
	uint8_t i,length;
	
	length = (uint8_t)(sizeof(STA369_Reg_Init_Table))/2;
	for(i=0; i<length; i++)
	{
		sta_data_buff[0] = STA369_Reg_Init_Table[i][0];
        sta_data_buff[1] = STA369_Reg_Init_Table[i][1]; 
        
		DSP_Write(2, sta_data_buff);
	}
}

void sta369bw_ReadRegSet(uint8_t regAddr, uint8_t *value)
{
    sta_data_buff[0] = regAddr;
    DSP_Read(1, sta_data_buff, 1, value);
}

void  STA369_Write_Set_Coeff_Fun(uint8_t set_num, uint8_t *pdata)
{	
	sta_data_buff[0] = 0x31;
    sta_data_buff[1] = 0x00;
	DSP_Write(2, sta_data_buff);     //Select the Ram block with register 0x31
	
    sta_data_buff[0] = 0x16;
	sta_data_buff[1]  = (uint8_t)(set_num*5);
	DSP_Write(2, sta_data_buff);     //Write 6-bits address to i2c register 0x16

    sta_data_buff[0] = 0x17;
    memcpy(&sta_data_buff[1], pdata, 15);
	DSP_Write(16,sta_data_buff);

   	sta_data_buff[0] = 0x26;
    sta_data_buff[1] = 0x02;
	DSP_Write(2, sta_data_buff);     //Write 1 to WA bit in i2c address 0x26
}

void STA369_Coef_EQ(void)
{
	uint8_t  str[20];
	uint8_t i;

	for (i=0;i<7;i++)
	{
		STA369_Write_Set_Coeff_Fun(i,(uint8_t *)&EQ_Coeff_Table[i][0]);
	}
}

void sta369bwdsp_init(void)
{
    ext_dsp_vol = EXT_DSP_INIT_VOL;
    sta369bw_state = ST_STA369BW_IDLE;
}

bool is_sta369bwdsp_idle(void)
{
    if(sta369bw_state == ST_STA369BW_IDLE)
        return true;
    else
        return false;
}
bool is_sta369bwdsp_ready(void)
{
    if(sta369bw_state == ST_STA369BW_RUNNING || sta369bw_state == ST_STA369BW_STARTING_POWER_OFF)
        return true;
    else
        return false;
}
void sta369bwdsp_start(void)
{
    ENABLE_DSP_POWER();
    DSP_Timer = 200;
    sta369bw_state = ST_STA369BW_START;
}


void sta369bwdsp_task(void)
{
    switch(sta369bw_state)
    {
        case ST_STA369BW_IDLE:
            break;
            
        case ST_STA369BW_START:
            if(!DSP_Timer)
            {
                DSP_RESET_SetLow();
                DSP_POWER_DN_SetLow();
                DSP_Timer = 15;
                sta369bw_state = ST_STA369BW_RESET_LOW_WAIT;
            }
            break;
            
        case ST_STA369BW_RESET_LOW_WAIT:
            if(!DSP_Timer)
            {
                DSP_RESET_SetHigh();
                DSP_Timer = 5;
                sta369bw_state = ST_STA369BW_RESET_HIGH_WAIT;
            }
            break;
            
        case ST_STA369BW_RESET_HIGH_WAIT:
            if( DSP_Timer )
                break;
            DSP_POWER_DN_SetHigh();

        
        case ST_STA369BW_INIT_REG:
            sta369bw_state = ST_STA369BW_INIT_REG;
            STA369_Reg_Init();
            DSP_Timer = 5;
            sta369bw_state = ST_STA369BW_WAIT_INIT_REG;
            break;
           
        case ST_STA369BW_WAIT_INIT_REG:
            if( DSP_Timer )
                break;                
            
        case ST_STA369BW_INIT_EQ_COEF:
            sta369bw_state = ST_STA369BW_INIT_EQ_COEF;
            STA369_Coef_EQ();
            sta369bw_state = ST_STA369BW_SETUP_VOL;
		
        case ST_STA369BW_SETUP_VOL:
            sta369bw_SoftMuteOff();
            sta369bw_voladj();
            sta369bw_state = ST_STA369BW_RUNNING;
            break;
            
//        case ST_STA369BW_READ_REG: //This state is for debugging
//            sta369bw_ReadRegSet();
//            if(sta369RegSet[0x2d] & 0x80) //Debugging
//                LED5_ON();
//            else
//                LED5_OFF();
//            sta369bw_state = ST_STA369BW_RUNNING;
//            break;
            
        case ST_STA369BW_RUNNING:
            if(BTAPP_GetStatus() == BT_STATUS_OFF)
            {
                DSP_Timer = 5000;       //wait 5 seconds
                sta369bw_state = ST_STA369BW_STARTING_POWER_OFF;
            }
            break;
            
        case ST_STA369BW_STARTING_POWER_OFF:
            if(BTAPP_GetStatus() == BT_STATUS_READY || BTAPP_GetStatus() == BT_STATUS_ON)
            {
                sta369bw_state = ST_STA369BW_RUNNING;
				DSP_Timer = 0;
                break;
            }
            if(!DSP_Timer)
            {
				sta369bw_SoftMute();
                DSP_Timer = 5;
                sta369bw_state = ST_STA369BW_POWER_OFF_1;
            }
            break;
            
        case ST_STA369BW_POWER_OFF_1:
            if(!DSP_Timer)
            {
                DSP_POWER_DN_SetLow();
                DSP_Timer = 5;
                sta369bw_state = ST_STA369BW_POWER_OFF_2;
            }
            break;
            
        case ST_STA369BW_POWER_OFF_2:
            if(!DSP_Timer)
            {
                DSP_RESET_SetLow();
                sta369bw_state = ST_STA369BW_IDLE;
            }
            break;
    }
}


/*-----------------------------------------------------------------------------
Function name:
  sta369bw_audio_interace_setting
Description:
  This function used to enable playback

Notice:
  refer to p168~176 of the firmware manual of yamaha for intialization flow chart
  refer to p29~38 of sta369bwa30 for i2c interface
  refer to p111~ of sta369bwa30 for power on flow chart

Input Parameter:
  None
Return:
  None
*/
//void sta369bw_playback(void)
//{
//  DSP_POWER_DN_SetHigh();//DSP_SLEEP = HIGH;
//  DSP_MUTE_SetHigh();//MUTE_DSP = HIGH;
//  sta369bw_status = true;
//  play_standby = false;
//}


/*-----------------------------------------------------------------------------
Function name:
  sta369bw_stop
Description:
  This function used to stop playbck

Notice:
  refer to p168~176 of the firmware manual of yamaha for intialization flow chart
  refer to p29~38 of sta369bwa30 for i2c interface
  refer to p111~ of sta369bwa30 for power on flow chart

Input Parameter:
  None
Return:
  None
*/
//void sta369bw_stop(void)
//{
//  sta369bw_status = false;
//  play_standby = true;
//}



/*-----------------------------------------------------------------------------
Function name:
  sta369bw_voladj
Description:
  This function used to set sta369bw volume

Notice:
  refer to p168~176 of the firmware manual of yamaha for intialization flow chart
  refer to p29~38 of sta369bwa30 for i2c interface
  refer to p111~ of sta369bwa30 for power on flow chart

Input Parameter:
  None
Return:
  None
*/
void sta369bw_voladj(void)
{
	if (ext_dsp_vol > MAX_VOL_TAB)
	{
        ext_dsp_vol = MAX_VOL_TAB;
		return;
	}

	sta_data_buff[0] = MVOL;
    sta_data_buff[1] = 0; 
    Delay_Some(DELAY_NUM);
    DSP_Write( 2, sta_data_buff );
	
	sta_data_buff[0] = C1VOL;
    sta_data_buff[1] = VolTab[ ext_dsp_vol ];     
    Delay_Some(DELAY_NUM);
    DSP_Write( 2, sta_data_buff );
	
	sta_data_buff[0] = C2VOL;
	sta_data_buff[1] = VolTab[ ext_dsp_vol ];  
    Delay_Some(DELAY_NUM);
    DSP_Write( 2, sta_data_buff );
	
	sta_data_buff[0] = C3VOL;
	sta_data_buff[1] = VolTab[ ext_dsp_vol ];  
    Delay_Some(DELAY_NUM);
    DSP_Write( 2, sta_data_buff );
}

/*-----------------------------------------------------------------------------
Function name:
  sta369bw_QMute
Description:
  This function used to set sta369bw quite mute

Notice:
  refer to p168~176 of the firmware manual of yamaha for intialization flow chart
  refer to p29~38 of sta369bwa30 for i2c interface
  refer to p111~ of sta369bwa30 for power on flow chart

Input Parameter:
  None
Return:
  None
*/
void sta369bw_SoftMuteOff(void)
{
    sta_data_buff[0] = MUTELOC;
    sta_data_buff[1] = MUTE_DEFAULT;
    Delay_Some(DELAY_NUM);
    DSP_Write( 2, sta_data_buff );
}


/*-----------------------------------------------------------------------------
Function name:
  sta369bw_SoftMute
Description:
  This function used to set sta369bw all mute

Notice:
  refer to p168~176 of the firmware manual of yamaha for intialization flow chart
  refer to p29~38 of sta369bwa30 for i2c interface
  refer to p111~ of sta369bwa30 for power on flow chart

Input Parameter:
  None
Return:
  None
*/
void sta369bw_SoftMute(void)
{
	sta_data_buff[0] = MUTELOC;
    sta_data_buff[1] = (MUTE_MMUTE | MUTE_C1MUTE | MUTE_C2MUTE | MUTE_C3MUTE);  //step13-D
    Delay_Some(DELAY_NUM);
    DSP_Write( 2, sta_data_buff );
}

/*-----------------------------------------------------------------------------
Function name:
  sta369bw_DSPStop
Description:
  This function used to stop sta369bw dsp

Notice:
  refer to p168~176 of the firmware manual of yamaha for intialization flow chart
  refer to p29~38 of sta369bwa30 for i2c interface
  refer to p111~ of sta369bwa30 for power on flow chart

Input Parameter:
  None
Return:
  None
*/
void sta369bw_DSPStop(void)
{
    sta_data_buff[0] = CONFF;
    sta_data_buff[1] = CONFF_DEFAULT & (~CONFF_PWDN);  
    Delay_Some(DELAY_NUM);
    DSP_Write( 2, sta_data_buff );
    Delay_Some(DELAY_NUM);
    Delay_Some(DELAY_NUM);
    Delay_Some(DELAY_NUM);
    Delay_Some(DELAY_NUM);
    Delay_Some(DELAY_NUM);
}

/*-----------------------------------------------------------------------------
Function name:
  sta369bw_DSPStart
Description:
  This function used to start sta369bw dsp

Notice:
  refer to p168~176 of the firmware manual of yamaha for intialization flow chart
  refer to p29~38 of sta369bwa30 for i2c interface
  refer to p111~ of sta369bwa30 for power on flow chart

Input Parameter:
  None
Return:
  None
*/
void sta369bw_DSPStart(void)
{
    sta_data_buff[0] = CONFF;
    sta_data_buff[1] = CONFF_DEFAULT | CONFF_EAPD;  
    Delay_Some(DELAY_NUM);
    DSP_Write( 2, sta_data_buff );
    Delay_Some(DELAY_NUM);
    Delay_Some(DELAY_NUM);
    Delay_Some(DELAY_NUM);
    Delay_Some(DELAY_NUM);
    Delay_Some(DELAY_NUM);
}

/*-----------------------------------------------------------------------------
Function name:
  sta369bw_setHighSamplingrateInput
Description:
  This function used to enable DCM bit when input sampling rate is over 50KHZ

Notice:
  refer to p168~176 of the firmware manual of yamaha for intialization flow chart
  refer to p29~38 of sta369bwa30 for i2c interface
  refer to p111~ of sta369bwa30 for power on flow chart

Input Parameter:
  None
Return:
  None
*/
void sta369bw_setHighSamplingrateInput(void)
{
    uint8_t regVal;
    
	sta369bw_ReadRegSet(CONFA, &regVal);
    regVal |= CONFA_HIGHIRMASK;
    sta_data_buff[0] = CONFA;
    sta_data_buff[1] = regVal;
    DSP_Write( 2, sta_data_buff );
}

/*-----------------------------------------------------------------------------
Function name:
  sta369bw_setNormalSamplingrateInput
Description:
  This function used to disable DCM bit when input sampling rate is lower or equal to 50KHZ

Notice:
  refer to p168~176 of the firmware manual of yamaha for intialization flow chart
  refer to p29~38 of sta369bwa30 for i2c interface
  refer to p111~ of sta369bwa30 for power on flow chart

Input Parameter:
  None
Return:
  None
*/
void sta369bw_setNormalSamplingrateInput(void)
{
    uint8_t regVal;
    
	sta369bw_ReadRegSet(CONFA, &regVal);
    regVal &= CONFA_NORMALIRMASK;
    sta_data_buff[0] = CONFA;
    sta_data_buff[1] = regVal;
    DSP_Write( 2, sta_data_buff );
}

/*-----------------------------------------------------------------------------
 *
*/
void sta369bw_vol_up(void)
{
    if(!ext_dsp_vol)
        sta369bw_SoftMuteOff();
    if(ext_dsp_vol < MAX_VOL_TAB)
    {
        ext_dsp_vol++;
        sta369bw_voladj();
    }
}


/*-----------------------------------------------------------------------------
 *
*/
void sta369bw_vol_down(void)
{
    if(ext_dsp_vol > 0)
    {
        ext_dsp_vol --;
        sta369bw_voladj();

        if(!ext_dsp_vol)
        {
            ext_dsp_vol = 0;
            sta369bw_SoftMute();
        }
    }
}

/*-----------------------------------------------------------------------------
 *
*/
void sta369bw_SetVol(uint8_t vol)
{
    if(ext_dsp_vol != vol)
    {
        if(!vol)        //new volume is 0, old volume is non-zero.
            sta369bw_SoftMute();
        else if(!ext_dsp_vol)       //old volume is 0, new volume is non-zero
            sta369bw_SoftMuteOff();
			
        if (vol < MAX_VOL_TAB) 
		{
            ext_dsp_vol = vol;
            sta369bw_voladj();
        }
		else
		{
			ext_dsp_vol = MAX_VOL_TAB;
			sta369bw_voladj();
		}
    }
}
