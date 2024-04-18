# robotMower_TM24
Robot lawn mower project for school.

# Notes
Some notes including the lessons we learned and the mistakes we found in our work can be found under [<b>*/Notes*</b>](/Notes.md)\
This contains some important information for anyone who wants to expand this project, **Please read this document**.

# Features
A list of features can be found under [<b>*/Features*</b>](/Features.md)

# Schematics, PCB
Schematics, along with footprints, can be found under [<b>*/Schematics*</b>](/Schematics).
These are designed in Fusion 360/Eagle, original Fusion/eagle Schematic, board and library files can be found under [***/Schematics/RoborMower_TM24/***](/Schematics/RoborMower_TM24/)

# Code
Code can be found under [***/Code***](/Code).
The final code for the ESP32 can be found under [***/Code/Final_V1.0***](/Code/Final_V1.0.0/).
The final code for the Attiny that read the HC-SR04 sensor can be fount under [***/Code/Test Sketches/ATtiny84_I2C-Slave-Ultrasonic_Test/***](/Code/Test%20Sketches/ATtiny84_I2C-Slave-Ultrasonic_Test/).

# Harware
A list of used components and modules will be made when the design is finalized.

# I²C Adress List
|Part|Address|
|----|-------|
|Current Sensor, Motor L|01000000 = 0x40|
|Current Sensor, Motor R|01000001 = 0x41|
|Current Sensor, Bat in|01000010 = 0x42|
|Current Sensor, 5V|01000011 = 0x43|
|Current Sensor, 3V3|01000100 = 0x44|
|Attiny, Ultrasone Sensors|00001000 = 0x8|
