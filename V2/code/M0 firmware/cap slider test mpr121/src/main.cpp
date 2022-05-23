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

  if(!slider1.calibrate(10))
  {
    Serial.println("innit error");
  }
  slider1.dump_cal();
  slider1.dump_raw();

}

void loop()
{
  delay(50);
  float points[3];
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


