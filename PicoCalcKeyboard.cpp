#include "PicoCalcKeyboard.h"

// Constructor
    PicoCalcKeyboard::PicoCalcKeyboard()
    {
        keyboard_init(onKeyAvailableCallback);
    }

    // Static callback function for C interface
    void PicoCalcKeyboard::onKeyAvailableCallback()
    {
        // This callback is called when a key becomes available
        // You can add custom handling here if needed
    }

    // Check if a key is available (non-blocking)
    bool PicoCalcKeyboard::available()
    {
        return keyboard_key_available();
    }

    // Read a key (blocking - waits for key if none available)
    char PicoCalcKeyboard::read()
    {
        return keyboard_get_key();
    }

    // Read a key (non-blocking - returns 0 if no key available)
    char PicoCalcKeyboard::readNonBlocking()
    {
        if (keyboard_key_available())
        {
            return keyboard_get_key();
        }
        return 0; // No key available
    }
