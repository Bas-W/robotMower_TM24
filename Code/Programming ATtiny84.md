# How to Program the ATtiny84

[example](https://www.instructables.com/Arduino-Uno-to-Program-ATTINY84-Arduino-V-185/)

## Setup
Additional boards: http://drazzy.com/package_drazzy.com_index.json
Upload the ArduinoISP sketch from the example sketches to the Uno.

## Connections to UNO
|ATtiny84|UNO|
|--------|---|
|5V|5V|
|GND|GND|
|Pin4|Pin10|
|Pin7|Pin11|
|Pin8|Pin12|
|Pin9|Pin13|

Connect UNO RESET pin to GND via 10uF Elec Cap.

## Programming ATtiny84
Board: ATtiny84
B.O.D.: Disable
LTO: Disable
Pin Mapping: Counter Clockwise
Chip: ATtiny84
Clock: 8MHz Internal
Bootloader: Burn Bootloader
Programmer: Arduino as ISP

To program the attiny you have to use *Upload Using Programmer* or shortcut *Ctrl + Shift + U* otherwise the preselected programmer won't be used.