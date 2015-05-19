void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(2, INPUT);
  pinMode(6, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int val = digitalRead(2);
  Serial.println(val);
  if (val == 1){
    digitalWrite(6, HIGH);
    Serial.println("ca rentre");
  }
  else {
    digitalWrite(6, LOW);
  }
  delay(500);
}
