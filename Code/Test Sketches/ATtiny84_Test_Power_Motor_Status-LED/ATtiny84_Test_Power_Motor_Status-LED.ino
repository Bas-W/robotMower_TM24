#define statusLED A5

bool ledState = false;

void setup() {
  Serial.begin(115200);
  Serial.println("Start Boot");

  pinMode(statusLED, OUTPUT);

  digitalWrite(statusLED, LOW);

  Serial.println("End Boot");

}

void loop() {
  Serial.println("Begin Digital Status led Sequence");

  digitalWrite(statusLED, HIGH);
  delay(5000);
  digitalWrite(statusLED, LOW);


  Serial.println("Begin Analog/PWM Status led Sequence");

  analogWrite(statusLED, 10);
  delay(250);
  analogWrite(statusLED, 20);
  delay(250);
  analogWrite(statusLED, 40);
  delay(250);
  analogWrite(statusLED, 80);
  delay(250);
  analogWrite(statusLED, 120);
  delay(250);
  analogWrite(statusLED, 160);
  delay(250);
  analogWrite(statusLED, 200);
  delay(250);
  analogWrite(statusLED, 255);
  delay(250);
  analogWrite(statusLED, 0);
  delay(1500);

}
