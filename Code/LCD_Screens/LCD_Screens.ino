#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Serial.begin(9600);
  Serial.println("Boot Start");

  lcd.init();
  lcd.backlight();

  Serial.println("Boot End");

}

void loop() {
  Serial.println("Home Screen");
  displayHomescreen();
  delay(10000);

  Serial.println("Menu 1");
  displayMenu1();
  delay(10000);

  Serial.println("Menu 2");
  displayMenu2();
  delay(10000);

  Serial.println("Menu 3");
  displayMenu3();
  delay(10000);

  Serial.println("Sonar Test");
  displaySonarTest(15, 22, 56);
  delay(10000);

  Serial.println("Button Test");
  displayButtonTest(1, 1, 0 ,1);
  delay(10000);

  Serial.println("Engine Test L F");
  displayEngineTestLeftForward();
  delay(10000);

  Serial.println("Engine Test L R");
  displayEngineTestLeftReverse();
  delay(10000);

  Serial.println("Engine Test R F");
  displayEngineTestRightForward();
  delay(10000);

  Serial.println("Engine Test R R");
  displayEngineTestRightReverse();
  delay(10000);

  Serial.println("Engine Test 2 F");
  displayEngineTestForward();
  delay(10000);

  Serial.println("Engine Test 2 R");
  displayEngineTestReverse();
  delay(10000);

  Serial.println("Current Test");
  displayCurrentTest(3.43);
  delay(10000);

}

void displayHomescreen() {
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("RobotMower");
  lcd.setCursor(0,1);
  lcd.print("V1.0.0");
}

void displayMenu1() {
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Sonar Test");
  lcd.setCursor(0,1);
  lcd.print("Button Test");
}

void displayMenu2() {
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Button Test");
  lcd.setCursor(0,1);
  lcd.print("Engine Test");
}

void displayMenu3() {
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Engine Test");
  lcd.setCursor(0,1);
  lcd.print("Current Test");
}

void displayCurrentTest(float currentBat) {
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Current Test");
  lcd.setCursor(0,1);
  lcd.print("Bat: ");
  lcd.setCursor(5, 1);
  lcd.print(currentBat);
}

void displayEngineTestLeftForward() {
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Engine Test");
  lcd.setCursor(0,1);
  lcd.print("Left Motor F");
}

void displayEngineTestLeftReverse() {
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Engine Test");
  lcd.setCursor(0,1);
  lcd.print("Left Motor R");
}

void displayEngineTestRightForward() {
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Engine Test");
  lcd.setCursor(0,1);
  lcd.print("Right Motor F");
}

void displayEngineTestRightReverse() {
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Engine Test");
  lcd.setCursor(0,1);
  lcd.print("Right Motor R");
}

void displayEngineTestForward() {
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Engine Test");
  lcd.setCursor(0,1);
  lcd.print("2 Motor F");
}

void displayEngineTestReverse() {
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Engine Test");
  lcd.setCursor(0,1);
  lcd.print("2 Motor R");
}

void displaySonarTest(int lValue, int mValue, int rValue) {
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("  L    M    R  ");
  lcd.setCursor(2,1);
  lcd.print(lValue);
  lcd.setCursor(7, 1);
  lcd.print(mValue);
  lcd.setCursor(12, 1);
  lcd.print(rValue);
}

void displayButtonTest(bool button1Value, bool button2Value, bool button3Value, bool button4Value) {
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("  1    2    3    4");
  lcd.setCursor(2,1);
  lcd.print(button1Value);
  lcd.setCursor(7, 1);
  lcd.print(button2Value);
  lcd.setCursor(12, 1);
  lcd.print(button3Value);
  lcd.setCursor(14, 1);
  lcd.print(button4Value);
}