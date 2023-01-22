/*******************************************************************************
 *         File: V2\code\M0 firmware\Main V2\src\main.cpp
 *       Author: Alexander Mills (Scaniox#7130)
 *      License: 
 *         Date: 
 *  Description: 
 ******************************************************************************/

#include "main.h"

Modules modules;

void setup() {
    modules.menu_sys    = Menu_sys(&modules);
    modules.sys         = Sys(&modules);
    modules.ser_io      = Serial_IO(&modules);
    modules.pwr_led     = Pwr_led(&modules);
    modules.rgb         = RGB(&modules);

    
}

void loop() {
    ser_io.tick();
    menu_sys.tick();
    pwr_led.tick();
}

