float currentSensorReading[3][4];

#include "motorDriver.h"
#include "INA219Driver.h"

#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
#include "lcdScreens.h"

#define buttonL 7
#define buttonUp 6
#define buttonDown 5
#define buttonR 4

int menuState = 0;
int powerMenuCursor = 0;

int refreshRate = 200;
int lastMillis = 0;


void setup() {
  Serial.begin(9600);
  Serial.println("Boot Start");

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
  if (menuState == 0) {
    if (!digitalRead(buttonDown)) {
      menuState = 1;
      while (!digitalRead(buttonDown)) {
      }
    }
  } else if (menuState == 1) {
    if (!digitalRead(buttonDown)) {
      menuState = 2;
      while (!digitalRead(buttonDown)) {
      }
    }
  } else if (menuState == 2) {
    if (!digitalRead(buttonDown)) {
      menuState = 3;
      while (!digitalRead(buttonDown)) {
      }
    }
  } else if (menuState == 3) {
    if (!digitalRead(buttonDown)) {
      menuState = 4;
      while (!digitalRead(buttonDown)) {
      }
    }
  } else if (menuState == 4) {
    Serial.println("Menu 4");
    if (!digitalRead(buttonDown)) {
      menuState = 5;
      while (!digitalRead(buttonDown)) {
      }
    }
  } else if (menuState == 5) {
    if (!digitalRead(buttonUp)) {
      if (powerMenuCursor == 2) {
        powerMenuCursor = 0;
      } else {
        powerMenuCursor++;
      }
      while (!digitalRead(buttonUp)) {
      }
    }
    if (!digitalRead(buttonDown)) {
      menuState = 0;
      while (!digitalRead(buttonDown)) {
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
        displayMenu2();
        break;
      case 3:
        displayMenu3();
        break;
      case 4:
        displaySonarTest(12, 25, 31);
        break;
      case 5:
        INA219Read();
        displayCurrentTest(powerMenuCursor, currentSensorReading);
        break;
    }
  }
}
