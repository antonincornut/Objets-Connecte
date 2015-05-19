
int ledPinRed = 7;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPinRed, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(ledPinRed, HIGH);
  delay(11);
  digitalWrite(ledPinRed, LOW);
  delay(11);
}

