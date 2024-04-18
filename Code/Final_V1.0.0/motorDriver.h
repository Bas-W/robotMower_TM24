#define hbridgeENA 35
#define hbridgeIN1 36
#define hbridgeIN2 37

#define hbridgeENB 39
#define hbridgeIN3 40
#define hbridgeIN4 41

void motorSetup() {
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
}

void motorControl(int motorSelect, bool driveDirection, int speed) {
  if (motorSelect == 0) {
    if (speed == 0) {
      digitalWrite(hbridgeENA, 0);
      digitalWrite(hbridgeIN1, 0);
      digitalWrite(hbridgeIN2, 0);
    } else {
      analogWrite(hbridgeENA, speed);
      digitalWrite(hbridgeIN1, driveDirection);
      digitalWrite(hbridgeIN2, !driveDirection);
    }
  } else if (motorSelect == 1) {
    if (speed == 0) {
      digitalWrite(hbridgeENB, 0);
      digitalWrite(hbridgeIN3, 0);
      digitalWrite(hbridgeIN4, 0);
    } else {
      analogWrite(hbridgeENB, speed);
      digitalWrite(hbridgeIN3, driveDirection);
      digitalWrite(hbridgeIN4, !driveDirection);
    }
  }
}

void motorTestControl() {
  if ((millis() - lastMotorMillis) > motorSwitchRate) {
    lastMotorMillis = millis();
    if (motorLoopCounter < 5) {
      Serial.print("Motor loop counter: ");
      Serial.println(motorLoopCounter);
      switch (motorLoopCounter) {
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
      motorLoopCounter++;
    } else {
      motorLoopCounter = 0;
    }
  }
}
