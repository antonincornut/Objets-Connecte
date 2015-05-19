void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(A0, INPUT);
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int potentio = analogRead(A0);
  potentio = potentio / 4;
  int potentioForLed1 = 255 - potentio;
  int potentioForLed2 = 255 - potentioForLed1;
  analogWrite(6, potentioForLed1);
  analogWrite(5, potentioForLed2);
}
