# robotMower_TM24
Robot lawn mower project for school.

# Components

|Component|Digital IO|Analog IO|Multiply|
|---------|----------|---------|--------|
|HC-SR04 Ultra Sonic|2|0|3|
|LCD|2 I2C|0|1|
|Voltage Meter|0|1|1|
|Control buttons|1|0|4|
|Motor Driver|4|0|1|
|RTC|2 I2C|0|1|
|QMC5883 Kompas|2 I2C|0|1|
|Bumper Microswitch|1|0|2|
|Blades motor|3|0|1


# Features
- [ ] Driving
- [ ] Collision Avoidance
- [ ] Easily Controllable Interface (lcd/oled etc)
- [ ] Main Power switch
- [ ] Rain Detection
- [ ] Current Measuring for wheels
- [ ] Current Measuring for Blade
- [ ] Internal 5V Regulation
- [ ] Internal 3V3 Regulation
- [ ] Custom PCB
- [ ] Small Formfactor
- [ ] Power cutoff relay to take away power to motors / emergency stop button (in case of rogue robot event) 
- [ ] USB-connector for programming & monitoring (USB-B / USB-C)
- [ ] Temperature sensors for motors (expansion)
- [ ] Temperature sensors for motor drivers (expansion)
- [ ] Power supply -> 3S/4S LiPo pack ?
- [ ] Battery Charging
- [ ] GPS (u-blox module) (expansion)
- [ ] Extra I-O for expansions
- [ ] Screw terminals or JST
- [ ] Tilt sensor/switches 
- [ ] Perimeter wire (expansion)
- [ ] Seperate boards for power, µc, sensors - connected via [5v,3v3,I²C]bus
