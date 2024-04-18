void displayHomescreen() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("RobotMower  V1.0");
  lcd.setCursor(0, 1);
  lcd.print("Nick & Bas");
  lcd.setCursor(12, 1);
  lcd.print("2024");
}

void displayMenu1() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Motor Test");
  if (motorTest) {
    lcd.setCursor(14, 0);
    lcd.print("ON");
  } else {
    lcd.setCursor(13, 0);
    lcd.print("OFF");
  }
}

void displayCurrentTest(int sensorIndex, float currentSensorReading[3][4]) {
  lcd.clear();
  lcd.setCursor(0, 0);

  if (sensorIndex == 0) {
    lcd.print("BAT: ");
    lcd.setCursor(5, 0);
  } else if (sensorIndex == 1) {
    lcd.print("5V: ");
    lcd.setCursor(4, 0);
  } else if (sensorIndex == 2) {
    lcd.print("3V3: ");
    lcd.setCursor(5, 0);
  }

  lcd.print(currentSensorReading[sensorIndex][2]);
  lcd.setCursor(14, 0);
  lcd.print("mA");
  lcd.setCursor(3, 1);
  lcd.print(currentSensorReading[sensorIndex][0]);
  lcd.setCursor(8, 1);
  lcd.print("V");
  lcd.setCursor(10, 1);
  lcd.print(currentSensorReading[sensorIndex][3]);
  lcd.setCursor(15, 1);
  lcd.print("W");
}

void displaySonarTest(String lValue, String mValue, String rValue) {
  objectDetectionRequest();
  lValue = leftValue;
  mValue = middleValue;
  rValue = rightValue;
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("  L    M    R  ");
  lcd.setCursor(2, 1);
  lcd.print(lValue);
  lcd.setCursor(7, 1);
  lcd.print(mValue);
  lcd.setCursor(12, 1);
  lcd.print(rValue);
}

void displayButtonTest(bool button1Value, bool button2Value, bool button3Value, bool button4Value) {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("  1    2    3    4");
  lcd.setCursor(2, 1);
  lcd.print(button1Value);
  lcd.setCursor(7, 1);
  lcd.print(button2Value);
  lcd.setCursor(12, 1);
  lcd.print(button3Value);
  lcd.setCursor(14, 1);
  lcd.print(button4Value);
}