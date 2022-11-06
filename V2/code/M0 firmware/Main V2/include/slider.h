/*******************************************************************************
 *         File: Glassphones\V2\code\M0 firmware\Main V2\include\slider.h
 *       Author: Alexander Mills (Scaniox#7130)
 *      License:
 *         Date: 06/11/22
 *  Description: mpr121 1d capacitive touch slider HAL header
 ******************************************************************************/
#define ELEMENTS 12
#define MPR121_IRQ 3

/* headers */
#include "module_common.h"
#include "Adafruit_MPR121.h"

/* types */
class Slider{
    public:
    Mod_State state = UNINITIALISED;
    Adafruit_MPR121 cap = Adafruit_MPR121();
    int samples = 4;
    uint16_t cal_values[ELEMENTS];

    Act_rply init();
    Act_rply tick();
    Act_rply calibrate(int cal_samples);
    uint16_t read_sensor(int sensor_no);
    void dump_raw();
    void dump_cal();
    int get_touch_points(float *points);
};