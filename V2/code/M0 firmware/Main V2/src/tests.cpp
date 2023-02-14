#include "tests.h"
#include "module_common.h"

void RGB_test(Serial_ serial)
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


void cap_touch_test(Serial_ serial)
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
        //digitalWrite(13, loop_count % 2);
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

        // write mpr121's irq to led
        digitalWrite(13, digitalRead(P_CAP_IRQ));

        delay(50);
    }
}

void mpr121_write_test(Serial_ serial)
{
    // reset and initialise
    slider.calibrate(10);

    // reset again to clear regs set in init
    slider.cap.writeRegister(MPR121_SOFTRESET, 0x63);

    // dump regs
    Serial.printf("regs before write:\n");
    for (uint8_t i = 0; i < 0x7F; i++)
    {
        Serial.print("$");
        Serial.print(i, HEX);
        int v = slider.cap.readRegister8(i);
        Serial.printf(": 0x%x : %i\n", v, v);
    }
    
    delay(10);

    // write 200 to 0x04 register
    slider.cap.writeRegister(0x41, 12);

    delay(10);

    // dump regs
    Serial.printf("regs after write:\n");
    for (uint8_t i = 0; i < 0x7F; i++)
    {
        Serial.print("$");
        Serial.print(i, HEX);
        int v = slider.cap.readRegister8(i);
        Serial.printf(": 0x%x : %i\n", v, v);
    }
}

void slider_test(Serial_ serial)
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
        float points[5];
        int point_count = slider.get_touch_points(points);

        Serial.printf("measurement taken\n");

        for (int i = 0; i < 5; i++)
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

void slider_RGB_test(Serial_ serial)
{
    Serial.printf("slider RGB test: \n");

    // set up slider
    if (!slider.calibrate(10))
    {
        Serial.println("slider init error");
        return;
    }

    // set up rgb
    Adafruit_NeoPixel strip(NUM_LEDS, P_RGB_DAT);
    strip.begin();
    strip.show();

    // power leds
    pinMode(P_RGB_EN, OUTPUT);
    pinMode(P_RGB_DAT, OUTPUT);
    digitalWrite(P_RGB_EN, LOW);

    int loop_count = 0;
    while (true)
    {
        loop_count++;
        
        // clear lights
        strip.fill(0);

        // deal with serial input
        if (Serial.available())
        {
            strip.show();

            Serial.printf("slider rgb test dissabled\n");
            Serial.flush();
            return;
        }

        // get points
        float points[5];
        int point_count = slider.get_touch_points(points);

        // set lights
        for(int point_i = 0; point_i < point_count; point_i++)
        {
          int pos = int(points[point_i]);
          strip.setPixelColor(pos, strip.ColorHSV(point_i * (65536/5), 255,255));
        }
        strip.show();

        for (int i = 0; i < point_count; i++)
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
        
        if (points > 0)
        {
            Serial.println();
        }

        delay(50);
    }
}

void vs1053_test(Serial_ serial)
{
    Serial.printf("vs1053 test");
}

void PWR_LED_test(Serial_ serial)
{
    Serial.printf("PWR LED test: ");
}

void BM83_serial_bridge(Serial_ serial)
{
    Serial.printf("Serial bridge enabled, type 'mcu_serial_bridge_exit' to exit\n");

    // setup serial
    Serial1.begin(115200);
    // rolling 24 (incl null) char buffer
    char in_buff[24] = "test  test  test  test ";

    while (true)
    {
        // PC to BM83
        if (Serial.available())
        {
            char c = Serial.read();
            // process input for "mcu_serial_bridge_exit"
            strcpy(in_buff, in_buff+1);
            strncat(in_buff, &c, 1);

            if (strcmp(in_buff, "mcu_serial_bridge_exit\n") == 0)
            {
                Serial.printf("exiting serial bridge mode\n");
                break;
            }

            // copy from PC to BM83
            Serial1.write(c);
        }

        // bm83 to PC
        if(Serial1.available())
        {
            Serial.write(Serial1.read());
        }
    }
    

}