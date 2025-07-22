#pragma once

#include "keyboard.h"

class PicoCalcKeyboard
{
private:
    static void onKeyAvailableCallback(); // Static callback function for C interface
public:
    PicoCalcKeyboard();
    bool available();       // Check if a key is available (non-blocking)
    char read();            // Read a key (blocking - waits for key if none available)
    char readNonBlocking(); // Read a key (non-blocking - returns 0 if no key available)
};