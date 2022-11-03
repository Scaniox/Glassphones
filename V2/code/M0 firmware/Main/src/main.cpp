#include <main.h>

bool serial_started = false;
bool dbg = false;
Slider slider;

void setup() 
{
  Serial.begin(115200);

  Wire.setClock(400000);
}

void loop()
{
    ser_update();
}


void ser_update()
{
  if (Serial && serial_started == false)
  {
    serial_started = true;
    Serial.printf("connection INNIT\n");
    Serial.printf("system uptime: %ims\n", millis());
  }

  if (Serial.available() > 0)
  {
    String c = Serial.readStringUntil('\n');
    if(dbg)
    {
      if(c.equals("exit"))
      {
        dbg = false;
        Serial.printf("exiting test mode\n");
      }
      else if(c.equals("rgb")) RGB_test();
      else if(c.equals("cap touch")) cap_touch_test();
      else if(c.equals("mpr121 write")) mpr121_write_test();
      else if(c.equals("slider")) slider_test();
      else if(c.equals("slider rgb")) slider_RGB_test();
      else if(c.equals("vs1053")) vs1053_test();
      else if(c.equals("pwr led")) PWR_LED_test();
      else if(c.equals("ser bridge")) BM83_serial_bridge();
      else{
        char cbuf[100];
        c.toCharArray(cbuf, 100);

        Serial.printf("\nunrecognised command: '%s'\n", cbuf);
        Serial.printf("options: | exit | rgb | cap touch | mpr121 write | slider ");
        Serial.printf("| slider rgb | vs1053 | pwr led | ser bridge\n");
      }
    }

    else if(c.equals("test"))
    {
      dbg = true;
      Serial.printf("\nTest menu:\n");
      Serial.printf("options: | exit | rgb | cap touch | mpr121 write | slider ");
      Serial.printf("| slider rgb | vs1053 | pwr led | ser bridge\n");
    }
  }
}