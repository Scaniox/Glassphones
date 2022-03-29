#include <main.h>

Adafruit_FreeTouch qt_1 = Adafruit_FreeTouch(A0, OVERSAMPLE_4, RESISTOR_50K, FREQ_MODE_NONE);
Adafruit_FreeTouch qt_2 = Adafruit_FreeTouch(A1, OVERSAMPLE_4, RESISTOR_50K, FREQ_MODE_NONE);
Adafruit_FreeTouch qt_3 = Adafruit_FreeTouch(A2, OVERSAMPLE_4, RESISTOR_50K, FREQ_MODE_NONE);
Adafruit_FreeTouch qt_4 = Adafruit_FreeTouch(A3, OVERSAMPLE_4, RESISTOR_50K, FREQ_MODE_NONE);
Adafruit_FreeTouch qt_5 = Adafruit_FreeTouch(A4, OVERSAMPLE_4, RESISTOR_50K, FREQ_MODE_NONE);
Adafruit_FreeTouch qt_6 = Adafruit_FreeTouch(A5, OVERSAMPLE_4, RESISTOR_50K, FREQ_MODE_NONE);


void setup() {
  Serial.begin(115200);
  
  while (!Serial);
  Serial.println("FreeTouch test");
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);

  calibrate();
}


void loop() {
  int counter, result = 0;
  
  // DIY
  // Serial.println("\n*************************************");

  counter = millis();
  result = processed_sample(1); 
  Serial.print(""); Serial.print(result);
  // Serial.print(" (");  Serial.print(millis() - counter); Serial.println(" ms)");

  counter = millis();
  result = processed_sample(2); 
  Serial.print(","); Serial.print(result);
  // Serial.print(" (");  Serial.print(millis() - counter); Serial.println(" ms)");

  counter = millis();
  result = processed_sample(3); 
  Serial.print(","); Serial.print(result);
  // Serial.print(" (");  Serial.print(millis() - counter); Serial.println(" ms)");
  
  counter = millis();
  result = processed_sample(4); 
  Serial.print(","); Serial.print(result);
  // Serial.print(" (");  Serial.print(millis() - counter); Serial.println(" ms)");

  counter = millis();
  result = processed_sample(5);
  Serial.print(",");
  Serial.print(result);
  // Serial.print(" (");  Serial.print(millis() - counter); Serial.println(" ms)");

  counter = millis();
  result = processed_sample(6);
  Serial.print(",");
  Serial.println(result);
  // Serial.print(" (");  Serial.print(millis() - counter); Serial.println(" ms)");

  //delay(20);
}


void calibrate(){
  if (! qt_1.begin())  
    Serial.println("Failed to begin qt on pin A0");
  else{
    delay(50);
    for (int i = 0; i < cal_samples; i++)
      qt_1_base += qt_1.measure();
    qt_1_base /= cal_samples;
  }
    
  if (! qt_2.begin())  
    Serial.println("Failed to begin qt on pin A1");
  else{
    delay(50);
    for (int i = 0; i < cal_samples; i++)
      qt_2_base += qt_2.measure();
    qt_2_base /= cal_samples;
  }

  if (! qt_3.begin())
    Serial.println("Failed to begin qt on pin A2");
  else{
    delay(50);
    for (int i = 0; i < cal_samples; i++)
      qt_3_base += qt_3.measure();
    qt_3_base /= cal_samples;
  }

  if (! qt_4.begin())  
    Serial.println("Failed to begin qt on pin A3");
  else{
    delay(50);
    for (int i = 0; i < cal_samples; i++)
      qt_4_base += qt_4.measure();
    qt_4_base /= cal_samples;
  }

  if (!qt_5.begin())
    Serial.println("Failed to begin qt on pin A4");
  else{
    delay(50);
    for (int i = 0; i < cal_samples; i++)
      qt_5_base += qt_5.measure();
    qt_5_base /= cal_samples;
  }

  if (!qt_6.begin())
    Serial.println("Failed to begin qt on pin A5");
  else{
    delay(50);
    for (int i = 0; i < cal_samples; i++)
      qt_6_base += qt_6.measure();
    qt_6_base /= cal_samples;
  }
}

uint16_t processed_sample(int qt_no){
  uint16_t val, base;

  switch (qt_no){
    case 1:
      val = qt_1.measure();
      base = qt_1_base;
      break;
    case 2:
      val = qt_2.measure();
      base = qt_2_base;
      break;
    case 3:
      val = qt_3.measure();
      base = qt_3_base;
      break;
    case 4:
      val = qt_4.measure();
      base = qt_4_base;
      break;
    case 5:
      val = qt_5.measure();
      base = qt_5_base;
      break;
    case 6:
      val = qt_6.measure();
      base = qt_6_base;
      break;
    default:
      return 0;
  }

  if (val - 100 > base){
    return val - base - 100;
  }
  else{
    return 0;
  }
}