/*******************************************************************************
 *         File: V2\code\M0 firmware\Main V2\src\main.cpp
 *       Author: Alexander Mills (Scaniox#7130)
 *      License: 
 *         Date: 
 *  Description: 
 ******************************************************************************/
#include "main.h"
using namespace std;

typedef struct {
    Sys sys;
    Pwr_led pwr_led;
    RGB rgb;
    Serial_IO ser_io;
    IS2020 is2020;
    VS1053 vs1053;
    Menu_sys menu_sys;
} Modules;

Modules modules;

void setup() {
    modules.sys.init(&modules);
    modules.ser_io.init(&modules);
    modules.pwr_led.init(&modules);
    modules.rgb.init(&modules);
    modules.is2020 = IS2020(&Serial1);
    modules.vs1053.init(&modules);
    modules.menu_sys.init(&modules);
    
}

void loop() {
    modules.sys.tick();
    modules.pwr_led.tick();
    modules.rgb.tick();
    modules.ser_io.tick();
    modules.vs1053.tick();
    modules.menu_sys.tick();
}

