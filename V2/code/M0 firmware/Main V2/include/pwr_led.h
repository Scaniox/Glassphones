/*******************************************************************************
 *         File: Glassphones\V2\code\M0 firmware\Main V2\include\pwr_led.h
 *       Author: Alexander Mills (Scaniox#7130)
 *      License:
 *         Date: 06/11/22
 *  Description: power led HAL header
 ******************************************************************************/

/* headers */
#include "module_common.h"

/* data types */
class Pwr_led {
    Mod_State state = Mod_State::UNINITIALISED;

    public:
        Pwr_led();
        void setup();
        void loop();
        Mod_State get_state();
        Act_rply set_brightness(int b); // b: 0-255
        Act_rply get_brightness(int b); // b: 0-255
        int get_temp();
};