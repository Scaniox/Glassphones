/*******************************************************************************
 *         File: V2\code\M0 firmware\Main V2\include\vs1053.h
 *       Author: Alexander Mills (Scaniox#7130)
 *      License: 
 *         Date: 22/01/23
 *  Description: 
 ******************************************************************************/
#include "module_common.h"

class VS1053 {
    public:
    Mod_State state = Mod_State::UNINITIALISED;

    VS1053();
    Act_rply tick();
    Act_rply pause();
    Act_rply play();
    Act_rply prev();
    Act_rply next();
    Act_rply set_vol();
    Act_rply start_song();

};