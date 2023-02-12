/*******************************************************************************
 *         File: V2\code\M0 firmware\Main V2\src\main.cpp
 *       Author: Alexander Mills (Scaniox#7130)
 *      License: 
 *         Date: 
 *  Description: 
 ******************************************************************************/
#include "main.h"

Sys sys;
Pwr_led pwr_led;
RGB rgb;
Serial_IO ser_io;
//IS2020 is2020(&Serial1);
VS1053 vs1053;
Menu_sys menu_sys;

void setup() {
    Serial1.begin(115200);

    sys.setup();
    ser_io.setup();
    pwr_led.setup();
    rgb.setup();
    //modules.is2020 = IS2020(&Serial1);
    vs1053.setup();
    menu_sys.setup();
}

void loop() {
    sys.loop();
    pwr_led.loop();
    rgb.loop();
    ser_io.loop();
    vs1053.loop();
    menu_sys.loop();
}

