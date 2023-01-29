/*******************************************************************************
 *         File: Glassphones\V2\code\M0 firmware\Main V2\include\rgb.h
 *       Author: Alexander Mills (Scaniox#7130)
 *      License:
 *         Date: 06/11/22
 *  Description: 12 indicator led HAL header
 ******************************************************************************/
/* headers */
#include "module_common.h"

/* macros */
#define NUM_LEDS 12
#define P_RGB_DAT 2
#define P_RGB_EN 11

/* types */
class RGB {
    Mod_State state = Mod_State::UNINITIALISED;
    bool enabled = false;

    public:
    void init(Modules *m);
    void tick();
    Mod_State get_state();
    Act_rply enable(bool en); // power on or off
    Act_rply set_pattern(int *pattern);
    Act_rply get_pattern(int *pattern);
};