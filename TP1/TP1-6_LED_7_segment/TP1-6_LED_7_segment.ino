//4 : DP
//5 : C
//6 : B
//7 : A
//8 : F
//9 : G
//10 : E
//11 : D

int ledA = 7;
int ledB = 6;
int ledC = 5;
int ledD = 11;
int ledE = 10;
int ledF = 8;
int ledG = 9;
int ledDP = 4;

int decompte = 9;

#define button1 3
volatile int trigger = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  init_Pin();
  print_Number(decompte);
  attachInterrupt(0, detect, FALLING); 
}

void loop() {
  // put your main code here, to run repeatedly:
  if (trigger != 0){
    decompte--;
    print_Number(decompte);
    if (decompte == 0)
      decompte = 10;
    trigger = 0; 
  }
  delay(400);
}

void detect(){
  noInterrupts();
  if (digitalRead(button1) == 1){
    trigger = 1;
  }
}

void print_Number(int num){
  switch (num){
    case 0 : {
      digitalWrite(ledA, HIGH);
      digitalWrite(ledB, HIGH);
      digitalWrite(ledC, HIGH);
      digitalWrite(ledD, HIGH);
      digitalWrite(ledE, HIGH);
      digitalWrite(ledF, HIGH);
      digitalWrite(ledG, LOW);
      digitalWrite(ledDP, LOW);
      break;
    }
    case 1 : {
      digitalWrite(ledA, LOW);
      digitalWrite(ledB, HIGH);
      digitalWrite(ledC, HIGH);
      digitalWrite(ledD, LOW);
      digitalWrite(ledE, LOW);
      digitalWrite(ledF, LOW);
      digitalWrite(ledG, LOW);
      digitalWrite(ledDP, LOW);
      break;
    }
    case 2 : {
      digitalWrite(ledA, HIGH);
      digitalWrite(ledB, HIGH);
      digitalWrite(ledC, LOW);
      digitalWrite(ledD, HIGH);
      digitalWrite(ledE, HIGH);
      digitalWrite(ledF, LOW);
      digitalWrite(ledG, HIGH);
      digitalWrite(ledDP, LOW);
      break;
    }
    case 3 : {
      digitalWrite(ledA, HIGH);
      digitalWrite(ledB, HIGH);
      digitalWrite(ledC, HIGH);
      digitalWrite(ledD, HIGH);
      digitalWrite(ledE, LOW);
      digitalWrite(ledF, LOW);
      digitalWrite(ledG, HIGH);
      digitalWrite(ledDP, LOW);
      break;
    }
    case 4 : {
      digitalWrite(ledA, LOW);
      digitalWrite(ledB, HIGH);
      digitalWrite(ledC, HIGH);
      digitalWrite(ledD, LOW);
      digitalWrite(ledE, LOW);
      digitalWrite(ledF, HIGH);
      digitalWrite(ledG, HIGH);
      digitalWrite(ledDP, LOW);
      break;
    }
    case 5 : {
      digitalWrite(ledA, HIGH);
      digitalWrite(ledB, LOW);
      digitalWrite(ledC, HIGH);
      digitalWrite(ledD, HIGH);
      digitalWrite(ledE, LOW);
      digitalWrite(ledF, HIGH);
      digitalWrite(ledG, HIGH);
      digitalWrite(ledDP, LOW);
      break;
    }
    case 6 : {
      digitalWrite(ledA, HIGH);
      digitalWrite(ledB, LOW);
      digitalWrite(ledC, HIGH);
      digitalWrite(ledD, HIGH);
      digitalWrite(ledE, HIGH);
      digitalWrite(ledF, HIGH);
      digitalWrite(ledG, HIGH);
      digitalWrite(ledDP, HIGH);
      break;
    }
    case 7 : {
      digitalWrite(ledA, HIGH);
      digitalWrite(ledB, HIGH);
      digitalWrite(ledC, HIGH);
      digitalWrite(ledD, LOW);
      digitalWrite(ledE, LOW);
      digitalWrite(ledF, LOW);
      digitalWrite(ledG, LOW);
      digitalWrite(ledDP, LOW);
      break;
    }
    case 8 : {
      digitalWrite(ledA, HIGH);
      digitalWrite(ledB, HIGH);
      digitalWrite(ledC, HIGH);
      digitalWrite(ledD, HIGH);
      digitalWrite(ledE, HIGH);
      digitalWrite(ledF, HIGH);
      digitalWrite(ledG, HIGH);
      digitalWrite(ledDP, LOW);
      break;
    }
    case 9 : {
      digitalWrite(ledA, HIGH);
      digitalWrite(ledB, HIGH);
      digitalWrite(ledC, HIGH);
      digitalWrite(ledD, HIGH);
      digitalWrite(ledE, LOW);
      digitalWrite(ledF, HIGH);
      digitalWrite(ledG, HIGH);
      digitalWrite(ledDP, HIGH);
      break;
    }
  } 
}

void init_Pin(){
  pinMode(button1, INPUT);
  digitalWrite(button1, HIGH);
  pinMode(ledDP, OUTPUT);
  pinMode(ledA, OUTPUT);
  pinMode(ledB, OUTPUT);
  pinMode(ledC, OUTPUT);
  pinMode(ledD, OUTPUT);
  pinMode(ledE, OUTPUT);
  pinMode(ledF, OUTPUT);
  pinMode(ledG, OUTPUT);
}
