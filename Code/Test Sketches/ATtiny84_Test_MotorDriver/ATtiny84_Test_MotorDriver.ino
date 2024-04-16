#define Q1M1 A0
#define Q2M1 A1
#define Q3M1 A2
#define Q4M1 A3

#define Q1M2 B0
#define Q2M2 B1
#define Q3M2 PB2
#define Q4M2 A7

#define statusLED A5

void setup() {
  // put your setup code here, to run once:
pinMode(Q1M1, OUTPUT);
pinMode(Q2M1, OUTPUT);
pinMode(Q3M1, OUTPUT);
pinMode(Q4M1, OUTPUT);

pinMode(Q1M2, OUTPUT);
pinMode(Q2M2, OUTPUT);
pinMode(Q3M2, OUTPUT);
pinMode(Q4M2, OUTPUT);

pinMode(statusLED, OUTPUT);

digitalWrite(statusLED, HIGH);
}

void Forward(int speed){
  digitalWrite(Q1M1, LOW);
  digitalWrite(Q2M1, LOW);
  digitalWrite(Q3M1, LOW);
  digitalWrite(Q4M1, LOW);

  digitalWrite(Q1M2, LOW);
  digitalWrite(Q2M2, LOW);
  digitalWrite(Q3M2, LOW);
  digitalWrite(Q4M2, LOW);

  digitalWrite(Q1M1, HIGH);
  digitalWrite(Q2M1, LOW);
  digitalWrite(Q3M1, LOW);
  digitalWrite(Q4M1, HIGH);

  digitalWrite(Q1M2, HIGH);
  digitalWrite(Q2M2, LOW);
  digitalWrite(Q3M2, LOW);
  digitalWrite(Q4M2, HIGH);
}

void Backward(int speed){
  digitalWrite(Q1M1, LOW);
  digitalWrite(Q2M1, LOW);
  digitalWrite(Q3M1, LOW);
  digitalWrite(Q4M1, LOW);

  digitalWrite(Q1M2, LOW);
  digitalWrite(Q2M2, LOW);
  digitalWrite(Q3M2, LOW);
  digitalWrite(Q4M2, LOW);

  digitalWrite(Q1M1, LOW);
  digitalWrite(Q2M1, HIGH);
  digitalWrite(Q3M1, HIGH);
  digitalWrite(Q4M1, LOW);

  digitalWrite(Q1M2, LOW);
  digitalWrite(Q2M2, HIGH);
  digitalWrite(Q3M2, HIGH);
  digitalWrite(Q4M2, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
Forward(255);
delay(1000);
Backward(255);
delay(1000);
}
