#include <main.h>

bool serial_started = false;
bool dbg = false;
Slider slider;

void setup() {
  Serial.begin(115200);

  Wire.setClock(400000);

}

void loop() {
    ser_update();
}


void ser_update(){
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
      else if(c.equals("RGB")) RGB_test();
      else if(c.equals("Cap Touch")) cap_touch_test();
      else if(c.equals("Slider")) slider_test();
      else if(c.equals("Slider RGB")) slider_RGB_test();
      else if(c.equals("vs1053")) vs1053_test();
      else if(c.equals("PWR LED")) PWR_LED_test();
      else{
        char cbuf[100];
        c.toCharArray(cbuf, 100);

        Serial.printf("\nunrecognised command: '%s'\n", cbuf);
        Serial.printf("options: | exit | RGB | Cap Touch | Slider | Slider RGB | vs1053 | PWR LED\n");
      }
    }

    else if(c.equals("test")){
      dbg = true;
      Serial.printf("\nTest menu:\n");
      Serial.printf("options: | exit | RGB | Cap Touch | Slider | Slider RGB | vs1053 | PWR LED\n");
    }
  }
}