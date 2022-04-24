#include <Arduino.h>
#include <FastLED.h>

#define NUM_LEDS 75
#define DATA_PIN 2


CRGB leds[NUM_LEDS];
int count = 0;
bool on = true;

void setup()
{
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
}

void loop()
{
  leds[count++] = (on) ? CRGB(0x4f4f4f) : CRGB::Black;
  FastLED.show();

  if(count == NUM_LEDS)
  {
    count = 0;
    on = !on;
  }

  delay(100);
  
}