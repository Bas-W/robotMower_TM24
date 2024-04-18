void objectDetectionRequest() {

  if (millis() - lastObjectMillis >= delayMS) {
    lastObjectMillis = millis();
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

    leftValue = "";
    for (int r = 0; r < 3; r++) {
      leftValue += buffer[r];
    }

    middleValue = "";
    for (int r = 4; r < 7; r++) {
      middleValue += buffer[r];
    }

    rightValue = "";
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