#include "Adafruit_FreeTouch.h"

const uint16_t cal_samples = 10;

uint16_t qt_1_base = 0;
uint16_t qt_2_base = 0;
uint16_t qt_3_base = 0;
uint16_t qt_4_base = 0;
uint16_t qt_5_base = 0;
uint16_t qt_6_base = 0;

uint16_t processed_sample(int qt_no);

void calibrate();