/*******************************************************************************
 *         File: Glassphones\V2\code\M0 firmware\Main V2\include\module_common.h
 *       Author: Alexander Mills (Scaniox#7130)
 *      License:
 *         Date: 05/11/22
 *  Description: bottom level header common between all of the system modules
 ******************************************************************************/


enum Module_States {
    UNINITIALISED,
    INITIALISED,
    INIT_WARNING,
    INIT_CRITICAL
};