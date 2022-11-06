/*******************************************************************************
 *         File: Glassphones\V2\code\M0 firmware\Main V2\include\sys.h
 *       Author: Alexander Mills (Scaniox#7130)
 *      License: 
 *         Date: 06/11/22
 *  Description: general system io header
 ******************************************************************************/
/* headers */
#include "module_common.h"

/* types */
class Sys{
    public:
    Mod_State state = UNINITIALISED;

    int get_bat_level(); /* 0-255 */
    bool get_charge_state();
    Act_rply set_dbg_led(bool on);
}
