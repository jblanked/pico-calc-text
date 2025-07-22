#pragma once

#include "keyboard.h"

class PicoCalcKeyboard
{
private:
    bool initialized;

    // Static callback function for C interface
    static void onKeyAvailableCallback();

    // Static instance pointer for callback
    static PicoCalcKeyboard *instance;

public:
    // Constructor
    PicoCalcKeyboard();

    // Destructor
    ~PicoCalcKeyboard();

    // Initialize the keyboard (can be called in constructor or separately)
    void begin();

    // Check if a key is available (non-blocking)
    bool available();

    // Read a key (blocking - waits for key if none available)
    char read();

    // Read a key (non-blocking - returns 0 if no key available)
    char readNonBlocking();

    // Check if keyboard is initialized
    bool isInitialized() const;
};
