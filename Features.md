# robotMower_TM24
Robot lawn mower project for school.

# Possible Components

|Component|Feature|Digital IO|Analog IO|Multiply|
|---------|-------|----------|---------|--------|
|HC-SR04 Ultra Sonic|Collision Avoidance|2|0|3|
|Bumper Microswitch|Collision Detection|1|0|2|
|LCD|Interface|2 I2C|0|1|
|Control buttons|Interface|1|0|4|
|Voltage Meter/resistors|Battery Percentage Readout|0|1|1|
|Blades motor|Grass Cutting|3|0|1
|Motor Driver|Driving|6|0|1|
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

# Current Features
- [x] Internal 5V Regulation
- [x] Internal 3V3 Regulation
- [x] Current, Voltage, Wattage sensing Battery power
- [x] Current, Voltage, Wattage sensing 5V power
- [x] Current, Voltage, Wattage sensing 3V3 power
- [x] Custom PCB
- [x] Easily Controllable Interface (lcd/oled etc)
- [x] Main Power switch
- [x] USB-connector for programming & monitoring (USB-B / USB-C)
- [x] JST
- [x] Seperate boards - connected via [5v,3v3,I²C]bus
  - MCU
  - Power
  - Sensors

# Possible Features
- [ ] Driving
- [ ] Grass Cutting
- [ ] Power cutoff relay to take away power to motors / emergency stop button (in case of rogue robot event) 
- [ ] Current Measuring for wheels
- [ ] Current Measuring for Blade
- [ ] Collision Avoidance
- [ ] Collision Detection
- [ ] Rain Detection
- [ ] Time Control
- [ ] Small Formfactor
- [ ] Power supply -> 3S/4S LiPo pack ?
- [ ] Battery Charging
- [ ] Battery Percentage Readout
- [ ] Extra I-O for expansions
- [ ] Tilt sensor/switches 
- [ ] Custom H-bridge
- [ ] SD-card slot
- [ ] Temperature sensors for motors (expansion)
- [ ] Temperature sensors for motor drivers (expansion)
- [ ] GPS (u-blox module) (expansion)
- [ ] Perimeter wire (expansion)
