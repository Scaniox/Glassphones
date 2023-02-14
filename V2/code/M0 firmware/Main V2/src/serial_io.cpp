/*******************************************************************************
 *         File: V2\code\M0 firmware\Main V2\src\serial_io.cpp
 *       Author: Alexander Mills (Scaniox#7130)
 *      License:
 *         Date: 22/01/23
 *  Description:
 ******************************************************************************/
/* headers */
#include "serial_io.h"
#include "tests.h"


/* member function definitions */
Serial_IO::Serial_IO(Serial_ serial) : 
    serial(serial) {}

void Serial_IO::setup() {
    serial.begin(115200);
}

void Serial_IO::loop() {
    parse_RX();
}

void Serial_IO::parse_RX() {
    String c = "";
    if (Serial.available() > 0) 
        c = serial.readStringUntil('\n');

    switch(debug) {
        case DISSABLED:
            if (c.equals("test")) {
                debug = MENU;
                serial.printf("\nTest menu:\n");
                serial.printf("options: | exit | rgb | cap touch | mpr121 write | slider ");
                serial.printf("| slider rgb | vs1053 | pwr led | ser bridge\n");
            }
            break;
        case MENU:
            if (c.equals("exit")) {
                debug = DISSABLED;
                serial.printf("exiting test mode\n");
                // reset the system
            }

            else if (c.equals("rgb"))           debug = RGB;
            else if (c.equals("cap touch"))     debug = CAP;
            else if (c.equals("mpr121 write"))  debug = MPR_WRITE;
            else if (c.equals("slider"))        debug = SLIDER;
            else if (c.equals("slider rgb"))    debug = SLIDER_RGB;
            else if (c.equals("vs1053"))        debug = VS1053;
            else if (c.equals("pwr led"))       debug = PWR_LED;
            else if (c.equals("ser bridge"))    debug = BM83_SER_BRIDGE;

            else {
                char cbuf[100];
                c.toCharArray(cbuf, 100);

                serial.printf("\nunrecognised command: '%s'\n", cbuf);
                serial.printf("options: | exit | rgb | cap touch | mpr121 write | slider ");
                serial.printf("| slider rgb | vs1053 | pwr led | ser bridge\n");
            }
            break;
        case RGB:
            RGB_test(serial);
            break;
        case CAP:
            cap_touch_test(serial);
            break;
        case MPR_WRITE:
            mpr121_write_test(serial);
            break;
        case SLIDER:
            RGB_test(serial);
            break;
        case SLIDER_RGB:
            slider_RGB_test(serial);
            break;
        case VS1053:
            vs1053_test(serial);
            break;
        case PWR_LED:
            PWR_LED_test(serial);
            break;
        case BM83_SER_BRIDGE:
            BM83_serial_bridge(serial);
            break;
    }
}