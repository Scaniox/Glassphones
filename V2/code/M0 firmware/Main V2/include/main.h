/*******************************************************************************
 *         File: Glassphones/code/M0 firmware/Main V2/include/main.h
 *       Author: Alexander Mills (Scaniox#7130)
 *      License: 
 *         Date: 05/11/22
 *  Description: top level includes
 ******************************************************************************/
/* headers */
#include <Arduino.h>

#include "sys.h"
#include "menu.h"
#include "serial_io.h"

#include "IS2020.h"
#include "vs1053.h"
#include "pwr_led.h"
#include "rgb.h"
#include "slider.h"

/* macros */
#define BAT_LOW_SHUTDOWN 5

/* type declarations */

typedef struct {
    Sys sys;
    Pwr_led pwr_led;
    RGB rgb;
    Serial_IO ser_io;
    IS2020 is2020;
    VS1053 vs1053;
    Menu_sys menu_sys;
} Modules;

/* function declarations */

void setup();
void loop();

