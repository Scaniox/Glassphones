#include <Arduino.h>
#include <Adafruit_MPR121.h>

class Slider
{
    public:
    Adafruit_MPR121 cap = Adafruit_MPR121();
    int samples = 4;
    uint16_t cal_values[12];
    bool calibrate(int cal_samples);
    uint16_t read_sensor(int sensor_no);
    void dump_raw();
    void dump_cal();
    int get_touch_points(float *points);
};

bool Slider::calibrate(int cal_samples)
{   
    if(!cap.begin()) return false;
    
    delay(50);
    for(int sensor_no=0; sensor_no<12; sensor_no++)
    {
        // for (int i = 0; i < cal_samples; i++)
        //     cal_values[sensor_no] += cap.filteredData(i);
        // cal_values[sensor_no] /= cal_samples;
        cal_values[sensor_no] = cap.baselineData(sensor_no);
        Serial.printf("cal value for sensor %i: %i\n", sensor_no, cal_values[sensor_no]);
    }

    return true;
}

uint16_t Slider::read_sensor(int sensor_no)
{
    if (cal_values[sensor_no] -1  > cap.filteredData(sensor_no))
    {
        return cal_values[sensor_no] - cap.filteredData(sensor_no);
    }
    else
    {
        return 0;
    }
}

void Slider::dump_raw()
{
    for(int i=0; i<12; i++)
    {
        Serial.printf("%i,", cap.filteredData(i));
    }
    Serial.println();
}

void Slider::dump_cal()
{
    for(int i=0; i<12; i++)
    {
        Serial.printf("%i,", read_sensor(i));
    }
    Serial.println();
}


int Slider::get_touch_points(float *touch_points)
{
    int points = 0; // total number of touch points
    uint16_t samples[12];
    for(int sensor_no=0; sensor_no<12;sensor_no++)
        samples[sensor_no] = read_sensor(sensor_no);

    for(int sensor_no=0; sensor_no<12; sensor_no++)
    {
        // detect the maximum if this sensor is a maximum
        int left_s = (sensor_no == 0) ? 0 : samples[sensor_no - 1];
        int right_s = (sensor_no == 11) ? 0 : samples[sensor_no + 1];
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