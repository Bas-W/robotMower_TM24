#include <INA.h>

#define hbridgeENA 23
#define hbridgeENB 19
#define hbridgeIN1 18
#define hbridgeIN2 5
#define hbridgeIN3 17
#define hbridgeIN4 16

int n = 0; // for counting loops

const uint32_t SERIAL_SPEED{
    115200}; ///< Use fast serial speed
const uint32_t SHUNT_MICRO_OHM{
    6000}; ///< Shunt resistance in Micro-Ohm, e.g. 100000 is 0.1 Ohm
const uint16_t MAXIMUM_AMPS{
    2};                  ///< Max expected amps, clamped from 1A to a max of 1022A
uint8_t devicesFound{0}; ///< Number of INAs found
INA_Class INA;           ///< INA class instantiation to use EEPROM

void setup()
{
  // put your setup code here, to run once:

  Serial.begin(SERIAL_SPEED);

  pinMode(hbridgeENA, OUTPUT);
  pinMode(hbridgeENB, OUTPUT);
  pinMode(hbridgeIN1, OUTPUT);
  pinMode(hbridgeIN2, OUTPUT);
  pinMode(hbridgeIN3, OUTPUT);
  pinMode(hbridgeIN4, OUTPUT);

  digitalWrite(hbridgeENA, 0);
  digitalWrite(hbridgeENB, 0);
  digitalWrite(hbridgeIN1, 0);
  digitalWrite(hbridgeIN2, 0);
  digitalWrite(hbridgeIN3, 0);
  digitalWrite(hbridgeIN4, 0);

  Serial.print("\n\nDisplay INA Readings V1.0.8\n");
  Serial.print(" - Searching & Initializing INA devices\n");
  /************************************************************************************************
  ** The INA.begin call initializes the device(s) found with an expected ±1 Amps maximum current **
  ** and for a 0.1Ohm resistor, and since no specific device is given as the 3rd parameter all   **
  ** devices are initially set to these values.                                                  **
  ************************************************************************************************/
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

void motorControl(int motorSelect, bool driveDirection, int speed)
{
  if (motorSelect == 0)
  {
    if (speed == 0)
    {
      digitalWrite(hbridgeENA, 0);
      digitalWrite(hbridgeIN1, 0);
      digitalWrite(hbridgeIN2, 0);
    }
    else
    {
      analogWrite(hbridgeENA, speed);
      digitalWrite(hbridgeIN1, driveDirection);
      digitalWrite(hbridgeIN2, !driveDirection);
    }
  }
  else if (motorSelect == 1)
  {
    if (speed == 0)
    {
      digitalWrite(hbridgeENB, 0);
      digitalWrite(hbridgeIN3, 0);
      digitalWrite(hbridgeIN4, 0);
    }
    else
    {
      analogWrite(hbridgeENB, speed);
      digitalWrite(hbridgeIN3, driveDirection);
      digitalWrite(hbridgeIN4, !driveDirection);
    }
  }
}

void loop()
{
  // put your main code here, to run repeatedly:
  if (n < 5)
  {
    switch (n)
    {
    case 0:
      motorControl(0, 1, 255);
      motorControl(1, 1, 255);
      break;
    case 1:
      motorControl(0, 1, 100);
      motorControl(1, 1, 100);
      break;
    case 2:
      motorControl(0, 0, 255);
      motorControl(1, 0, 255);
      break;
    case 3:
      motorControl(0, 0, 100);
      motorControl(1, 0, 100);
      break;
    case 4:
      motorControl(0, 0, 0);
      motorControl(1, 0, 0);
      break;
    }
    n++;
  }
  else
  {
    n = 0;
  }

  static uint16_t loopCounter = 0;                                     // Count the number of iterations
  static char sprintfBuffer[100];                                      // Buffer to format output
  static char busChar[8], shuntChar[10], busMAChar[10], busMWChar[10]; // Output buffers

  Serial.print(F("Nr Adr Type   Bus      Shunt       Bus         Bus\n"));
  Serial.print(F("== === ====== ======== =========== =========== ===========\n"));
  for (uint8_t i = 0; i < devicesFound; i++) // Loop through all devices
  {
    dtostrf(INA.getBusMilliVolts(i) / 1000.0, 7, 4, busChar);     // Convert floating point to char
    dtostrf(INA.getShuntMicroVolts(i) / 1000.0, 9, 4, shuntChar); // Convert floating point to char
    dtostrf(INA.getBusMicroAmps(i) / 1000.0, 9, 4, busMAChar);    // Convert floating point to char
    dtostrf(INA.getBusMicroWatts(i) / 1000.0, 9, 4, busMWChar);   // Convert floating point to char
    sprintf(sprintfBuffer, "%2d %3d %s %sV %smV %smA %smW\n", i + 1, INA.getDeviceAddress(i),
            INA.getDeviceName(i), busChar, shuntChar, busMAChar, busMWChar);
    Serial.print(sprintfBuffer);
  } // for-next each INA device loop
  Serial.println();
  delay(1000); // Wait 1 seconds before next reading
  Serial.print(F("Loop iteration "));
  Serial.print(++loopCounter);
  Serial.print(F("\n\n"));
}
