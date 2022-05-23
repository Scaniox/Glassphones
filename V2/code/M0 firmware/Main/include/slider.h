#define elements 12

class Slider
{
public:
    Adafruit_MPR121 cap = Adafruit_MPR121();
    int samples = 4;
    uint16_t cal_values[elements];

    bool calibrate(int cal_samples);
    uint16_t read_sensor(int sensor_no);
    void dump_raw();
    void dump_cal();
    int get_touch_points(float *points);
};