/*******************************************************************************
 *         File: V2\code\M0 firmware\Main V2\src\serial_io.cpp
 *       Author: Alexander Mills (Scaniox#7130)
 *      License:
 *         Date: 22/01/23
 *  Description:
 ******************************************************************************/
#include "serial_io.h"

Serial_IO::Serial_IO() {
    Serial.begin(115200);
}

void Serial_IO::read_msg() {
    if (connected) {
        if (Serial.available() > 0) {
            String c = Serial.readStringUntil('\n');
            if (debug) {
                if (c.equals("exit")) {
                    debug = false;
                    Serial.printf("exiting test mode\n");
                    // reset the system
                }
                // else if (c.equals("rgb")) RGB_test();
                // else if (c.equals("cap touch")) cap_touch_test();
                // else if (c.equals("mpr121 write")) mpr121_write_test();
                // else if (c.equals("slider")) slider_test();
                // else if (c.equals("slider rgb")) slider_RGB_test();
                // else if (c.equals("vs1053")) vs1053_test();
                // else if (c.equals("pwr led")) PWR_LED_test();
                // else if (c.equals("ser bridge")) BM83_serial_bridge();
                else {
                    char cbuf[100];
                    c.toCharArray(cbuf, 100);

                    Serial.printf("\nunrecognised command: '%s'\n", cbuf);
                    Serial.printf("options: | exit | rgb | cap touch | mpr121 write | slider ");
                    Serial.printf("| slider rgb | vs1053 | pwr led | ser bridge\n");
                }
            }

            else if (c.equals("test")) {
                debug = true;
                Serial.printf("\nTest menu:\n");
                Serial.printf("options: | exit | rgb | cap touch | mpr121 write | slider ");
                Serial.printf("| slider rgb | vs1053 | pwr led | ser bridge\n");
            }
        }
    }
}