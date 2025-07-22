#include "PicoCalcKeyboard.h"

// Static member initialization
PicoCalcKeyboard *PicoCalcKeyboard::instance = nullptr;

// Constructor
PicoCalcKeyboard::PicoCalcKeyboard() : initialized(false)
{
    // Set the static instance pointer for callback
    instance = this;
}

// Destructor
PicoCalcKeyboard::~PicoCalcKeyboard()
{
    // Clean up if needed
    instance = nullptr;
}

// Static callback function for C interface
void PicoCalcKeyboard::onKeyAvailableCallback()
{
    // This callback is called when a key becomes available
    // You can add custom handling here if needed
}

// Initialize the keyboard
void PicoCalcKeyboard::begin()
{
    if (!initialized)
    {
        keyboard_init(onKeyAvailableCallback);
        initialized = true;
    }
}

// Check if a key is available (non-blocking)
bool PicoCalcKeyboard::available()
{
    if (!initialized)
    {
        return false;
    }
    return keyboard_key_available();
}

// Read a key (blocking - waits for key if none available)
char PicoCalcKeyboard::read()
{
    if (!initialized)
    {
        begin(); // Auto-initialize if not done
    }
    return keyboard_get_key();
}

// Read a key (non-blocking - returns 0 if no key available)
char PicoCalcKeyboard::readNonBlocking()
{
    if (!initialized)
    {
        return 0;
    }

    if (keyboard_key_available())
    {
        return keyboard_get_key();
    }
    return 0; // No key available
}

// Check if keyboard is initialized
bool PicoCalcKeyboard::isInitialized() const
{
    return initialized;
}
