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
    
}

void loop() {
    modules.ser_io.tick();
    modules.menu_sys.tick();
    modules.pwr_led.tick();
}

