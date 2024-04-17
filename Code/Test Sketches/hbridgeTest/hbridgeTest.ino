#define hbridgeENA 23
#define hbridgeENB 22
#define hbridgeIN1 21
#define hbridgeIN2 19
#define hbridgeIN3 18
#define hbridgeIN4 17

void setup()
{
  // put your setup code here, to run once:

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

  motorControl(0, 1, 255);
  motorControl(1, 1, 255);
  delay(1000);
  motorControl(0, 1, 100);
  motorControl(1, 1, 100);
  delay(1000);
  motorControl(0, 0, 255);
  motorControl(1, 0, 255);
  delay(1000);
  motorControl(0, 0, 100);
  motorControl(1, 0, 100);
  delay(1000);
  motorControl(0, 0, 0);
  motorControl(1, 0, 0);
  delay(1000);
}
