#include <Arduino.h>
#include <IS2020.h>
#include <Adafruit_MPR121.h>
//#include <FastLED.h>
#include <Adafruit_NeoPixel.h>

#include <slider.h>
#include <pins.h>
#include <tests.h>

extern bool serial_started;
extern bool dbg;
extern Slider slider;

void setup();
void loop();
void ser_update();