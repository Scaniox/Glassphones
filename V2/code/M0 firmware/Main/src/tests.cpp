#include <main.h>

void RGB_test()
{
    Serial.printf("RGB test pattern enabled\n");

    int count = 0;
    uint32_t colour = 0x00FF0000;
    int colour_index = 0;

    // power leds
    pinMode(P_RGB_EN, OUTPUT);
    pinMode(13, OUTPUT);
    pinMode(P_RGB_DAT, OUTPUT);
    digitalWrite(P_RGB_EN, LOW);

    Adafruit_NeoPixel strip(NUM_LEDS, P_RGB_DAT);
    strip.begin();
    strip.show();

    while (true)
    {
        if (Serial.available())
        {
            // clear LEDs
            digitalWrite(13, LOW);
            strip.fill(0);
            strip.show();
            
            Serial.printf("RGB test pattern dissabled\n");
            Serial.flush();
            return;
        }

        // set LED to next colour
        strip.setPixelColor(count++, colour);
        strip.show();

        Serial.printf("%i\n", count);
        // move on to next colour
        if (count == NUM_LEDS)
        {
            count = 0;

            digitalWrite(13, colour_index % 2);

            colour_index++;
            switch (colour_index)
            {
            case 8:
                colour_index = 0;
            case 0:
                colour = strip.Color(255,0,0);
                break;
            case 2:
                colour = strip.Color(0,255,0);
                break;
            case 4:
                colour = strip.Color(0,0,255);
                break;
            case 6:
                colour = strip.Color(255,255,255);
                break;

            default:
                colour = strip.Color(0,0,0);
                break;
            }
        }

    delay(100);
    }

}


void cap_touch_test()
{
    Serial.printf("Cap Touch test:\n");

    pinMode(13, OUTPUT);

    // set up slider
    if (!slider.calibrate(10))
    {
        Serial.println("slider init error\n");
        return;
    }
    Serial.printf("calibration successful\n");

    int loop_count = 0;
    while (true)
    {
        loop_count++;
        digitalWrite(13, loop_count % 2);
        //Serial.printf("loop %i start\n", loop_count);

        // deal with serial input
        if (Serial.available())
        {
            digitalWrite(13, LOW);

            Serial.printf("slider test dissabled\n");
            Serial.flush();
            return;
        }

        // dump raw measurements
        slider.dump_raw();

        delay(50);
    }
}

void slider_test()
{
    Serial.printf("slider test: ");

    // set up slider
    if (!slider.calibrate(10))
    {
        Serial.println("slider init error");
        return;
    }

    int loop_count = 0;
    while (true)
    {
        loop_count++;

        // deal with serial input
        if (Serial.available())
        {
            Serial.printf("slider test dissabled\n");
            Serial.flush();
            return;
        }

        // print sensor values
        float points[3];
        int point_count = slider.get_touch_points(points);

        Serial.printf("measurement taken\n");

        for (int i = 0; i < 3; i++)
        {
            if (i < point_count)
            {
                Serial.print(points[i], 2);
            }
            else
            {
                Serial.print("0");
            }
            Serial.print(",");
        }
        Serial.println();

        delay(50);
    }
}

void slider_RGB_test()
{
    Serial.printf("slider RGB test: ");
}

void vs1053_test()
{
    Serial.printf("vs1053 test");
}

void PWR_LED_test()
{
    Serial.printf("PWR LED test: ");
}