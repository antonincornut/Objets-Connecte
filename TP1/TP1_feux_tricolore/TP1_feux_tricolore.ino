int ledPinRed = 7;
int ledPinOrange = 6;
int ledPinGreen = 5;

int ledPinRed2 = 2;
int ledPinOrange2 = 3;
int ledPinGreen2 = 4;

void setup() {
  pinMode(ledPinRed, OUTPUT);
  pinMode(ledPinOrange, OUTPUT);
  pinMode(ledPinGreen, OUTPUT);
  
  pinMode(ledPinRed2, OUTPUT);
  pinMode(ledPinOrange2, OUTPUT);
  pinMode(ledPinGreen2, OUTPUT);
}

void setRedLight(){
  digitalWrite(ledPinRed, HIGH);
  digitalWrite(ledPinRed2, LOW);
  digitalWrite(ledPinGreen2, HIGH);
  delay(2000);
  digitalWrite(ledPinGreen2, LOW);
  digitalWrite(ledPinOrange2, HIGH);
  delay(1000);
  digitalWrite(ledPinOrange2, LOW);
  digitalWrite(ledPinRed2, HIGH);
  digitalWrite(ledPinRed, LOW);
  digitalWrite(ledPinGreen, HIGH);
  delay(2000);
  digitalWrite(ledPinOrange, HIGH);
  digitalWrite(ledPinGreen, LOW);
  delay(1000);
  digitalWrite(ledPinOrange, LOW);
}

void loop() {
  setRedLight();
}


