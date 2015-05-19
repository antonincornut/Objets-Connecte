#define inter 2 
#define button1 3
#define button2 4
#define led1 9
#define led2 10

volatile unsigned long button_time = 0;
int debounce = 50;

volatile int trigger = 0;
int total = 0;
int inta = 0;
int intb = 0;

void setup() {
  // put your setup code here, to run once:
  initPins();
  Serial.begin(9600);
  attachInterrupt(0, detect, FALLING);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (trigger != 0){
    total++;
    if (trigger == 1){
      inta++;
      digitalWrite(led1, HIGH);
      digitalWrite(led2, LOW);
    }
    if (trigger == 2){
      intb++;
      digitalWrite(led2, HIGH);
      digitalWrite(led1, LOW); 
    }
    trigger = 0; 
  }
  Serial.println(inta);
  Serial.println("-");
  Serial.println(intb);
  Serial.println("---");
  Serial.println(total);
  Serial.println("===");
  delay(500);
}

void detect(){
  if (digitalRead(button1) == 1){
    trigger = 1;
  }
  if (digitalRead(button2) == 1){
    trigger = 2;
  } 
}

void initPins(){
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(inter, INPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  digitalWrite(button1, HIGH);
  digitalWrite(button2, HIGH);
  digitalWrite(inter, HIGH); 
  digitalWrite(led1, LOW); 
  digitalWrite(led2, LOW); 
}
