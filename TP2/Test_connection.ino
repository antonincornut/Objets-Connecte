unsigned long time;

void setup() {
  Serial.begin(9600);
  while (!Serial) {
    Serial.println("Error with serial, not sending...");
  }
  Serial.println("Init done, start sending time!");
}

void loop() {
  if(Serial.available()){
    time = millis();
    Serial.println(time);
    delay(500);
  }
  else {
    Serial.println("Pas de reponse...");
  } 
}
