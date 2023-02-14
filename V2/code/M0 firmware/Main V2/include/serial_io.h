/*******************************************************************************
 *         File: V2\code\M0 firmware\Main V2\include\serial_io.h
 *       Author: Alexander Mills (Scaniox#7130)
 *      License: 
 *         Date: 22/01/23
 *  Description: handles serial communications
 ******************************************************************************/
#include "module_common.h"



class Serial_IO {
    Serial_ serial;
    Mod_State state = Mod_State::UNINITIALISED;
    bool connected = false;
    enum {DISSABLED, RGB, CAP, MPR_WRITE, SLIDER, SLIDER_RGB,
          VS1053, PWR_LED, BM83_SER_BRIDGE, MENU
    } debug = DISSABLED;
    

    public:
        Serial_IO(Serial_ serial);
        void setup();
        void loop();
        Mod_State get_state();
        Act_rply send_msg(String msg);
        void parse_RX();
};

