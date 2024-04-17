#include <Wire.h>

bool testFlag = false;

int currentMillis = 0;
int lastMillis = 0;

#define delayMS 500

void setup() {
  Wire.begin(9, 8);    // join i2c bus (address optional for master)
  Serial.begin(9600);  // start serial for output
  Serial.println("Boot Start");

  currentMillis = millis();
  Serial.println("Boot End");
}

void loop() {
  currentMillis = millis();

  if (currentMillis - lastMillis >= delayMS) {
    lastMillis = currentMillis;
    Wire.requestFrom(8, 11);  // request 11 bytes from slave device #8
    Serial.println("Message Sent");
  }

  char buffer[11];
  int i = 0;
  while (Wire.available()) {  // slave may send less than requested
    buffer[i] = Wire.read();  // receive a byte as character
    Serial.print(buffer[i]);
    i++;

    testFlag = true;
  }

  if (testFlag) {
    Serial.println("");
    Serial.print("Buffer: ");
    Serial.println(buffer);

    String leftValue;
    String middleValue;
    String rightValue;


    for (int r = 0; r < 3; r++) {
      leftValue += buffer[r];
    }

    for (int r = 4; r < 7; r++) {
      middleValue += buffer[r];
    }

    for (int r = 8; r < 11; r++) {
      rightValue += buffer[r];
    }

    Serial.print("Left Value: ");
    Serial.println(leftValue);
    Serial.print("Middle Value: ");
    Serial.println(middleValue);
    Serial.print("Right Value: ");
    Serial.println(rightValue);
    testFlag = false;
  }
}
