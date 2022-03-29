#include <main.h>

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
}

void loop()
{

  // slider1.dump_raw();

  // for(int sensor_no=0; sensor_no<6; sensor_no++){
  //   Serial.printf("%i,", slider1.read_sensor(sensor_no));
  // }
  // Serial.println();
  float points[6];
  int point_count = slider1.get_touch_points(points); 
  for(int i=0; i<3; i++)
  {
    if(i < point_count)
    {
      Serial.print(points[i], 2);
    }
    else{
      Serial.print("0");
    }
    Serial.print(",");
  }
  Serial.println();
}


