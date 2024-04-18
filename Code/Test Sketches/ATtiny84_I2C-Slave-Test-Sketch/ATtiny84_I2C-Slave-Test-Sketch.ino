#include <Wire.h>

int leftValue;
int middleValue;
int rightValue;

#define leftLed A0
#define rightLed A1

void setup() {
  Wire.begin(8);              // join i2c bus with address #8
  Wire.onRequest(requestEvent);  // register event

  pinMode(leftLed, OUTPUT);
  pinMode(rightLed, OUTPUT);
  digitalWrite(leftLed, HIGH);
}

void loop() {
  leftValue = random(51, 101);
  middleValue = random(10, 51);
  rightValue = random(101, 205);
  delay(100);
}

void requestEvent() {
  digitalWrite(rightLed, HIGH);

  String leftString;
  String middleString;
  String rightString;

  if (leftValue < 100) {
    leftString = "0" + String(leftValue);
  }

  if (middleValue < 100) {
    middleString = "0" + String(middleValue);
  }

  rightString = String(rightValue);

  String message = leftString + "|" + middleString + "|" + rightString;
  Wire.write(message.c_str());  // respond with message of 6 bytes
  digitalWrite(rightLed, LOW);
}
