/*******************************************************************************
 *         File: Glassphones\V2\code\M0 firmware\Main V2\include\menu.h
 *       Author: Alexander Mills (Scaniox#7130)
 *      License:
 *         Date: 06/11/22
 *  Description: menu system that follows the slider 
 ******************************************************************************/

/* headers */
#include "module_common.h"

/* types */
typedef struct {
    uint8_t start_pos;
    uint8_t end_pos;
    uint32_t start_time;
    uint32_t end_time;
} Tap_t;


enum Menu_Screen {
    SYSTEM,
    VOL_MUX,
    HOME,
    AUDIO_PLAYBACK,
    START_CALL,
    INCOMMING_CALL,
    IN_CALL,
};


class Menu_sys {
    public:
    Mod_State state;
    Menu_Screen menu_stack[3];
    bool in_call;

    Menu_sys();
    void tick();
};

