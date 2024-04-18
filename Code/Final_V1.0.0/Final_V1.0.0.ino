String leftValue;
String middleValue;
String rightValue;

bool testFlag = false;

int currentMillis = 0;
int lastObjectMillis = 0;

#define delayMS 500

#include <Wire.h>

float currentSensorReading[3][4];

#include "INA219Driver.h"

#include <LiquidCrystal_I2C.h>

int motorLoopCounter = 0;
bool motorTest = false;
int lastMotorMillis = 0;
int motorSwitchRate = 2000;

#include "objectDetection.h"

LiquidCrystal_I2C lcd(0x27, 16, 2);
#include "lcdScreens.h"

#define buttonR 7
#define buttonUp 6
#define buttonDown 5
#define buttonL 4

int menuState = 0;
int powerMenuCursor = 0;

int refreshRate = 200;
int lastMillis = 0;

#include "motorDriver.h"

void setup() {
  Serial.begin(9600);
  Serial.println("Boot Start");

  Wire.begin(9, 8);

  lcd.init();
  lcd.backlight();

  pinMode(buttonL, INPUT_PULLUP);
  pinMode(buttonUp, INPUT_PULLUP);
  pinMode(buttonDown, INPUT_PULLUP);
  pinMode(buttonR, INPUT_PULLUP);

  motorSetup();
  INA219Setup();

  Serial.println("Boot End");
}

void loop() {
  if (motorTest) {
    motorTestControl();
  } else {
    motorControl(0, 0, 0);
    motorControl(1, 0, 0);
    motorLoopCounter = 0;
  }

  if (menuState == 0) {
    if (!digitalRead(buttonDown)) {
      menuState = 1;
      while (!digitalRead(buttonDown)) {
      }
    } else if (!digitalRead(buttonUp)) {
      menuState = 3;
      while (!digitalRead(buttonUp)) {
      }
    }
  } else if (menuState == 1) {
    if (!digitalRead(buttonR)) {
      motorTest = !motorTest;
      while (!digitalRead(buttonR)) {
      }
    }
    if (!digitalRead(buttonDown)) {
      menuState = 2;
      while (!digitalRead(buttonDown)) {
      }
    } else if (!digitalRead(buttonUp)) {
      menuState = 0;
      while (!digitalRead(buttonUp)) {
      }
    }
  } else if (menuState == 2) {
    if (!digitalRead(buttonDown)) {
      menuState = 3;
      while (!digitalRead(buttonDown)) {
      }
    } else if (!digitalRead(buttonUp)) {
      menuState = 1;
      while (!digitalRead(buttonUp)) {
      }
    }
  } else if (menuState == 3) {
    if (!digitalRead(buttonR)) {
      if (powerMenuCursor == 2) {
        powerMenuCursor = 0;
      } else {
        powerMenuCursor++;
      }
      while (!digitalRead(buttonR)) {
      }
    } else if (!digitalRead(buttonL)) {
      if (powerMenuCursor == 0) {
        powerMenuCursor = 2;
      } else {
        powerMenuCursor--;
      }
      while (!digitalRead(buttonL)) {
      }
    }
    if (!digitalRead(buttonDown)) {
      menuState = 0;
      while (!digitalRead(buttonDown)) {
      }
    } else if (!digitalRead(buttonUp)) {
      menuState = 2;
      while (!digitalRead(buttonUp)) {
      }
    }
  }

  if ((millis() - lastMillis) > refreshRate) {
    lastMillis = millis();
    switch (menuState) {
      case 0:
        displayHomescreen();
        break;
      case 1:
        displayMenu1();
        break;
      case 2:
        displaySonarTest("", "", "");
        break;
      case 3:
        INA219Read();
        displayCurrentTest(powerMenuCursor, currentSensorReading);
        break;
    }
  }
}
