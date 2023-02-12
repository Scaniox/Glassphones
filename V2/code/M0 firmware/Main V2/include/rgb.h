/*******************************************************************************
 *         File: Glassphones\V2\code\M0 firmware\Main V2\include\rgb.h
 *       Author: Alexander Mills (Scaniox#7130)
 *      License:
 *         Date: 06/11/22
 *  Description: 12 indicator led HAL header
 ******************************************************************************/
/* headers */
#include "module_common.h"

/* types */
class RGB {
    int n_leds;
    int p_rgb_dat;
    int p_rgb_en;
    Mod_State state = Mod_State::UNINITIALISED;
    bool enabled = false;

    public:
        RGB(int n_leds, int p_rgb_dat, int p_rgb_en);
        void setup();
        void loop();
        Mod_State get_state();
        Act_rply enable(bool en); // power on or off
        Act_rply set_pattern(int *pattern);
        Act_rply get_pattern(int *pattern);
};