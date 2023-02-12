/*******************************************************************************
 *         File: Glassphones\V2\code\M0 firmware\Main V2\include\module_common.h
 *       Author: Alexander Mills (Scaniox#7130)
 *      License:
 *         Date: 05/11/22
 *  Description: bottom level header common between all of the system modules
 ******************************************************************************/
/* headers */
#pragma once
#include <Arduino.h>
#include <stdint.h>
using namespace std;


/* types */
enum Mod_State {/* current state of a module */
    UNINITIALISED,
    INITIALISED,
    WARNING,
    CRITICAL /* system restart */
};

enum Act_rply{/* action replys - given by a function that performs an action */
    DONE,
    FAILED
};

