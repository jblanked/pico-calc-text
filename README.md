# pico-calc-text
This is a simple Arduino IDE library to read the keyboard input from the Pico Calc. It utilizes the keyboard and southbridge libraries from Blair Leduc's [picocalc-text-starter](https://github.com/BlairLeduc/picocalc-text-starter).

## Install
1. Install the Arduino IDE from https://www.arduino.cc/en/software.
2. Download this repository as a .zip file: https://github.com/jblanked/pico-calc-text/archive/refs/heads/master.zip
3. Open up the .zip and double-click the pico-calc-text.ino file to open it up in Arduino IDE.
4. Open the Arduino IDE you downloaded earlier, go to Preferences/Settings, and add the following URL to the `Additional Boards Manager URLs` field: `https://github.com/earlephilhower/arduino-pico/releases/download/4.6.0/package_rp2040_index.json`. Click `OK`.
5. In `Boards Manager`, search for `rp2040` and install the `Raspberry Pi Pico/RP2040/RP2350` package.
6. Hold the `BOOT` button on your Pico  while connecting your USB data cable.
7. Select the serial port to which your Pico is connected and choose your specific Pico type (e.g., `Raspberry Pi Pico`) as your board.
8. In `Tools` menu, change the `Flash Size` to `2MB (Sketch: 1984KB, FS: 64KB)` (or `4MB (Sketch: 4032KB, FS: 64KB)` if compiling for a Raspberry Pi Pico 2 or 2W device) and `CPU Speed` to `200MHz`. 
9. Finally, click `Sketch` in the menu, then select `Upload`. After it's done, disconnect the USB-C cable and power on your Pico Calc.
10. Open up the `Serial Monitor` within Arduino IDE and connect your Pico Calc via USB-C again.
11. Select the serial port to which your Pico is connected and choose your specific Pico type (e.g., `Raspberry Pi Pico`) as your board.
12. Begin typing on your Pico Calc. The input will be displayed within the `Serial Monitor` section. 
