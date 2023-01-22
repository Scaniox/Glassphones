/*******************************************************************************
 *         File: V2\code\M0 firmware\Main V2\include\serial_io.h
 *       Author: Alexander Mills (Scaniox#7130)
 *      License: 
 *         Date: 22/01/23
 *  Description: handles serial communications
 ******************************************************************************/
#include "module_common.h"


class Serial_IO {
    public:
    Mod_State state = Mod_State::UNINITIALISED;
    bool connected = false;
    bool debug = false;

    Serial_IO();
    void tick();
    Act_rply send_msg(String msg);
    void read_msg();
};