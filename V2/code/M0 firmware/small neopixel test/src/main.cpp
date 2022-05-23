#include <Arduino.h>
#include <FastLED.h>
#include <slider.h>

#define NUM_LEDS 12
#define DATA_PIN 2


CRGB leds[NUM_LEDS];
int count = 0;
CRGB colour = CRGB::White;
int colour_index = 0;

Slider slider1;

void setup()
{
  Serial.begin(115200);
  while (!Serial)
  {
    delay(1);
  }
  Serial.println("innit");
  //slider1.calibrate(10);

  //power leds
  pinMode(11, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(DATA_PIN, OUTPUT);
  digitalWrite(11, LOW);

  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
}

void loop()
{
  leds[count++] = colour;
  FastLED.show();

  if(count == NUM_LEDS)
  {
    count = 0;

    digitalWrite(13, colour_index % 2);
    
    colour_index++;
    switch (colour_index)
    {
    case 8:
      colour_index = 0;
    case 0:
      colour = CRGB::Red;
      break;
    case 2:
      colour = CRGB::Green;
      break;
    case 4:
      colour = CRGB::Blue;
      break;
    case 6:
      colour = CRGB::White;
      break;
    
    default:
      colour = CRGB::Black;
      break;
    }
    
  }

  delay(100);
  
  // zero all leds
  // FastLED.clear();

  // // get touch points
  // float points[3];
  // int point_count = slider1.get_touch_points(points);

  // // set lights
  // for(int point_i=0; point_i<point_count; point_i++)
  // {
  //   int pos = points[point_i] * NUM_LEDS / 7;
  //   leds[pos] = CHSV(point_i * 84, 255,255);
  // }
  // FastLED.show();
}