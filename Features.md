# robotMower_TM24
Robot lawn mower project for school.

# Components

|Component|Feature|Digital IO|Analog IO|Multiply|
|---------|-------|----------|---------|--------|
|HC-SR04 Ultra Sonic|Collision Avoidance|2|0|3|
|Bumper Microswitch|Collision Detection|1|0|2|
|LCD|Interface|2 I2C|0|1|
|Control buttons|Interface|1|0|4|
|Voltage Meter/resistors|Battery Percentage Readout|0|1|1|
|Blades motor|Grass Cutting|3|0|1
|Motor Driver|Driving|4|0|1|
|RTC|Time Control|2 I2C|0|1|
|QMC5883 Kompas||2 I2C|0|1|
|Rocker Switch|Main Power Switch|0|0|1|
|Relay|Emergency Stop/Power Cutoff|2|0|1|
|Axial sensor|Tilt Sensor|x|x|1|
|LM1117 T5.0 LDO|5V Regulation|0|0|1|
|LM1117 T3.3 LDO|3V Regulation|0|0|1|
|Water Sensor|Rain Detection|0|1|1|
|ATtiny84|Breakout µControllers|2 I2C|0|2|
|USB-B|USB-Port|2|0|1|

# Features
- [ ] Driving
- [ ] Grass Cutting
- [ ] Collision Avoidance
- [ ] Collision Detection
- [ ] Easily Controllable Interface (lcd/oled etc)
- [ ] Main Power switch
- [ ] Rain Detection
- [x] Current Measuring for wheels
- [x] Current Measuring for Blade
- [x] Internal 5V Regulation
- [x] Internal 3V3 Regulation
- [ ] Time Control
- [x] Custom PCB
- [ ] Small Formfactor
- [x] Power cutoff relay to take away power to motors / emergency stop button (in case of rogue robot event) 
- [x] USB-connector for programming & monitoring (USB-B / USB-C)
- [ ] Temperature sensors for motors (expansion)
- [ ] Temperature sensors for motor drivers (expansion)
- [ ] Power supply -> 3S/4S LiPo pack ?
- [ ] Battery Charging
- [ ] Battery Percentage Readout
- [ ] GPS (u-blox module) (expansion)
- [ ] Extra I-O for expansions
- [x] Screw terminals or JST
- [ ] Tilt sensor/switches 
- [ ] Perimeter wire (expansion)
- [x] Seperate boards - connected via [5v,3v3,I²C]bus
  - MCU
  - Power
  - Sensors
  - Motor driver
- [ ] Custom H-bridge
- [ ] SD-card slot
