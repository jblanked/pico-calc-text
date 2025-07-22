#include "PicoCalcKeyboard.h"

// Create keyboard instance
PicoCalcKeyboard keyboard;

void readline(char *buffer, size_t size)
{
    size_t index = 0;
    while (true)
    {
        // Wait for a key from the PicoCalc keyboard using the C++ class
        char ch = keyboard.read();

        if (ch == 0x04) // Ctrl+D to debug
        {
            Serial.println("Entering debug mode...\n");
            __breakpoint();
        }
        else if (ch == '\n' || ch == '\r')
        {
            Serial.print(ch); // Echo the character to serial
            Serial.println();
            break; // End of line
        }
        else if ((ch == 0x08 || ch == 0x7F) && index > 0) // Backspace or Delete
        {
            index--;
            buffer[index] = '\0';  // Remove last character
            Serial.print("\b \b"); // Erase the last character
        }
        else if (ch >= 0x20 && ch < 0x7F && index < size - 1) // Printable characters
        {
            buffer[index++] = ch;
            Serial.print(ch); // Echo the character to serial
        }
    }
    buffer[index] = '\0'; // Null-terminate the string
}

void setup()
{
    Serial.begin();
    delay(5000);
    Serial.println("PicoCalc Keyboard C++ Library Test");

    // Initialize the keyboard using the C++ class
    keyboard.begin();

    Serial.println("Keyboard initialized!");
}

void loop()
{
    char buffer[40];

    Serial.println("\033c\033[1m Hello from the PicoCalc C++ Keyboard Library!\033[0m\n");
    Serial.println("      Simple C++ wrapper for PicoCalc keyboard\n\n");
    Serial.println("Type something and press Enter...\n");

    // Demonstrate async checking
    Serial.println("Waiting for input...");
    while (!keyboard.available())
    {
        // Do other work here while waiting for keys
        delay(10);
    }
    Serial.println("Key detected!");

    // A very simple REPL using the C++ class
    Serial.println("Ready for input:");
    while (true)
    {
        readline(buffer, sizeof(buffer));
        if (strlen(buffer) == 0)
        {
            continue; // Skip empty input
        }

        Serial.print("You typed: ");
        Serial.println(buffer);

        if (strcmp(buffer, "quit") == 0)
        {
            Serial.println("Goodbye!");
            delay(2000);
            break;
        }
    }
}
