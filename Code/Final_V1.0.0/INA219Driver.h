#include <INA.h>

const uint32_t SHUNT_MICRO_OHM{
    6000}; ///< Shunt resistance in Micro-Ohm, e.g. 100000 is 0.1 Ohm
const uint16_t MAXIMUM_AMPS{
    2};                  ///< Max expected amps, clamped from 1A to a max of 1022A
uint8_t devicesFound{0}; ///< Number of INAs found
INA_Class INA;           ///< INA class instantiation to use EEPROM

void INA219Setup() {
  Serial.print("\n\nDisplay INA Readings V1.0.8\n");
  Serial.print(" - Searching & Initializing INA devices\n");

  devicesFound = INA.begin(MAXIMUM_AMPS, SHUNT_MICRO_OHM); // Expected max Amp & shunt resistance
  while (devicesFound == 0)
  {
    Serial.println(F("No INA device found, retrying in 10 seconds..."));
    delay(10000);                                            // Wait 10 seconds before retrying
    devicesFound = INA.begin(MAXIMUM_AMPS, SHUNT_MICRO_OHM); // Expected max Amp & shunt resistance
  }                                                          // while no devices detected

  Serial.print(F(" - Detected "));
  Serial.print(devicesFound);
  Serial.println(F(" INA devices on the I2C bus"));

  INA.reset(0);
  INA.reset(1);
  INA.reset(2);

  INA.begin(5, 6000, 0);
  INA.begin(MAXIMUM_AMPS, 40000, 1);
  INA.begin(MAXIMUM_AMPS, 40000, 2);

  INA.setBusConversion(8500);             // Maximum conversion time 8.244ms
  INA.setShuntConversion(8500);           // Maximum conversion time 8.244ms
  INA.setAveraging(1024);                 // Average each reading n-times
  INA.setMode(INA_MODE_CONTINUOUS_BOTH);  // Bus/shunt measured continuously
  INA.alertOnBusOverVoltage(true, 12000); // Trigger alert if over 12V on bus
}

void INA219Read() {
  for (uint8_t i = 0; i < devicesFound; i++) // Loop through all devices
  {
    currentSensorReading[i][0] = float(INA.getBusMilliVolts(i) / 1000.0);   
    currentSensorReading[i][1] = float(INA.getShuntMicroVolts(i) / 1000.0); 
    currentSensorReading[i][2] = float(INA.getBusMicroAmps(i) / 1000.0);  
    currentSensorReading[i][3] = float(INA.getBusMicroWatts(i) / 1000000.0); 

    Serial.print(i);
    Serial.print("|");
    Serial.print(currentSensorReading[i][0]);
    Serial.print("|");
    Serial.print(currentSensorReading[i][1]);
    Serial.print("|");
    Serial.print(currentSensorReading[i][2]);
    Serial.print("|");
    Serial.println(currentSensorReading[i][3]);

  }
}