/*******************************************************************************
 *         File: V2\code\M0 firmware\Main V2\src\pwr_led.cpp
 *       Author: Alexander Mills (Scaniox#7130)
 *      License: 
 *         Date: 12/02/23
 *  Description: 
 ******************************************************************************/
/* headers */
#include "pwr_led.h"

/* member function definitions */
Pwr_led::Pwr_led(int p_led_pwm_out, int p_temp_sense) :
    p_led_pwm_out(p_led_pwm_out),
    p_temp_sense(p_temp_sense) {}
    
void Pwr_led::setup() {}
void Pwr_led::loop() {}
