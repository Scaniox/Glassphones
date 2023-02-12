/*******************************************************************************
 *         File: V2\code\M0 firmware\Main V2\src\rgb.cpp
 *       Author: Alexander Mills (Scaniox#7130)
 *      License: 
 *         Date: 12/02/23
 *  Description: 
 ******************************************************************************/
/* headers */
#include "rgb.h"

/* member function definitions */
RGB::RGB(int n_leds, int p_rgb_dat, int p_rgb_en):
    n_leds(n_leds),
    p_rgb_dat(p_rgb_dat),
    p_rgb_en(p_rgb_en) {}
    
void RGB::setup() {}
void RGB::loop() {}
