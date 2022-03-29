// include SPI, MP3 and SD libraries
#include <SPI.h>
#include <SD.h>
#include <Adafruit_VS1053.h>

void setup();

void loop();

/// File listing helper
void printDirectory(File dir, int numTabs);
