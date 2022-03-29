#include <Arduino.h>
#include <FastLED.h>
#include <slider.h>

#define NUM_LEDS 60
#define DATA_PIN 20


CRGB leds[NUM_LEDS];
int count = 0;
bool on = true;

Slider slider1;

void setup()
{
  Serial.begin(115200);
  while (!Serial)
  {
    delay(1);
  }
  Serial.println("innit");
  slider1.calibrate(10);

  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
}

void loop()
{
  // leds[count++] = (on) ? CRGB::White : CRGB::Black;
  // FastLED.show();

  // if(count == NUM_LEDS)
  // {
  //   count = 0;
  //   on = !on;
  // }

  // delay(100);
  
  // zero all leds
  FastLED.clear();

  // get touch points
  float points[3];
  int point_count = slider1.get_touch_points(points);

  // set lights
  for(int point_i=0; point_i<point_count; point_i++)
  {
    int pos = points[point_i] * NUM_LEDS / 5;
    leds[pos] = CHSV(point_i * 84, 255,255);
  }
  FastLED.show();
}