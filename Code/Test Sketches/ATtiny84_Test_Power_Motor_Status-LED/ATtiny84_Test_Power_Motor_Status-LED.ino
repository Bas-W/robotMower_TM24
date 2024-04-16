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
  delay(1000);
  digitalWrite(statusLED, LOW);
  delay(1000);

  Serial.println("Begin Analog/PWM Status led Sequence");
  
  analogWrite(statusLED, 127);
  delay(1500);
  analogWrite(statusLED, 255);
  delay(1500);

}
