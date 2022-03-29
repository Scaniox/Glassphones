#include <Arduino.h>
#include <Adafruit_Freetouch.h>

class Slider
{
    public:
    Adafruit_FreeTouch sensors[6] = {Adafruit_FreeTouch(A0, OVERSAMPLE_4, RESISTOR_50K, FREQ_MODE_NONE),
                                    Adafruit_FreeTouch(A1, OVERSAMPLE_4, RESISTOR_50K, FREQ_MODE_NONE),
                                    Adafruit_FreeTouch(A2, OVERSAMPLE_4, RESISTOR_50K, FREQ_MODE_NONE),
                                    Adafruit_FreeTouch(A3, OVERSAMPLE_4, RESISTOR_50K, FREQ_MODE_NONE),
                                    Adafruit_FreeTouch(A4, OVERSAMPLE_4, RESISTOR_50K, FREQ_MODE_NONE),
                                    Adafruit_FreeTouch(A5, OVERSAMPLE_4, RESISTOR_50K, FREQ_MODE_NONE)};
    int samples = 4;
    uint16_t cal_values[6];
    void calibrate(int cal_samples);
    uint16_t read_sensor(int sensor_no);
    void dump_raw();
    int get_touch_points(float *points);
};

void Slider::calibrate(int cal_samples)
{   
    for(int sensor_no=0; sensor_no<6; sensor_no++)
    {
        Adafruit_FreeTouch sens = sensors[sensor_no];
        if (!sens.begin())  
            Serial.printf("Failed to begin qt on sensor %i\n", sensor_no);
        else
        {
            delay(50);
            for (int i = 0; i < cal_samples; i++)
                cal_values[sensor_no] += sens.measure();
            cal_values[sensor_no] /= cal_samples;
            Serial.printf("cal value for sensor %i: %i\n", sensor_no, cal_values[sensor_no]);
        }
    }
}

uint16_t Slider::read_sensor(int sensor_no)
{
    uint16_t value = 0;
    for(int s=0; s<samples; s++)
        value += sensors[sensor_no].measure();
    value /= samples;
    uint16_t cal = cal_values[sensor_no];

    if (value - 80 > cal)
    {
        return value - cal - 80;
    }
    else
    {
        return 0;
    }
}

void Slider::dump_raw()
{
    for(int i=0; i<6; i++)
    {
        Serial.printf("%i,", sensors[i].measureRaw());
    }
    Serial.println();
}

int Slider::get_touch_points(float *touch_points)
{
    int points = 0; // total number of touch points
    uint16_t samples[6];
    for(int sensor_no=0; sensor_no<6;sensor_no++)
        samples[sensor_no] = read_sensor(sensor_no);

    for(int sensor_no=0; sensor_no<6; sensor_no++)
    {
        // detect the maximum if this sensor is a maximum
        int left_s = (sensor_no == 0) ? 0 : samples[sensor_no - 1];
        int right_s = (sensor_no == 5) ? 0 : samples[sensor_no + 1];
        int middle_s = samples[sensor_no];

        if(left_s < middle_s && middle_s > right_s)
        {
            // work out the average position between this max sensor and adjacent ones
            int total = left_s + middle_s + right_s;
            float pos = (sensor_no - 1) * (float(left_s) / total) +
                        sensor_no       * (float(middle_s) / total) +
                        (sensor_no + 1) * (float(right_s) / total);

            // append to touch points   
            touch_points[points] = pos;
            points++;
        }
    }
    return points;
}       