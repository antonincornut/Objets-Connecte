int SER_Pin = 8;
int RCLK_Pin = 9;
int SRCLK_Pin = 10;

int ledA = 7;
int ledB = 6;
int ledC = 5;
int ledD = 4;
int ledE = 3;
int ledF = 2;
int ledG = 1;

#define number_of_74h 1
#define numberOfRegisterPins number_of_74h * 8

boolean registers[numberOfRegisterPins];

void setup() {
  pinMode(SER_Pin, OUTPUT);
  pinMode(RCLK_Pin, OUTPUT);
  pinMode(SRCLK_Pin, OUTPUT);
  clearRegisters();
  writeRegisters();
}

void clearRegisters(){
  for (int i = numberOfRegisterPins - 1; i >= 0; i--) {
    registers[i] = LOW; 
  }
}

void writeRegisters(){
  digitalWrite(RCLK_Pin, LOW);
  for (int i =  numberOfRegisterPins - 1; i >= 0; i--) {
    digitalWrite(SRCLK_Pin, LOW);
    int val = registers[i];
    digitalWrite(SER_Pin, val);
    digitalWrite(SRCLK_Pin, HIGH);
  } 
  digitalWrite(RCLK_Pin, HIGH);
}

void setRegisterPin(int index, int value){
  registers[index] = value; 
}


void print_Number(int num){
  switch (num){
    case 0 : {
      setRegisterPin(ledA, HIGH);
      setRegisterPin(ledB, HIGH);
      setRegisterPin(ledC, HIGH);
      setRegisterPin(ledD, HIGH);
      setRegisterPin(ledE, HIGH);
      setRegisterPin(ledF, HIGH);
      setRegisterPin(ledG, LOW);
      break;
    }
    case 1 : {
      setRegisterPin(ledA, LOW);
      setRegisterPin(ledB, HIGH);
      setRegisterPin(ledC, HIGH);
      setRegisterPin(ledD, LOW);
      setRegisterPin(ledE, LOW);
      setRegisterPin(ledF, LOW);
      setRegisterPin(ledG, LOW);
      break;
    }
    case 2 : {
      setRegisterPin(ledA, HIGH);
      setRegisterPin(ledB, HIGH);
      setRegisterPin(ledC, LOW);
      setRegisterPin(ledD, HIGH);
      setRegisterPin(ledE, HIGH);
      setRegisterPin(ledF, LOW);
      setRegisterPin(ledG, HIGH);
      break;
    }
    case 3 : {
      setRegisterPin(ledA, HIGH);
      setRegisterPin(ledB, HIGH);
      setRegisterPin(ledC, HIGH);
      setRegisterPin(ledD, HIGH);
      setRegisterPin(ledE, LOW);
      setRegisterPin(ledF, LOW);
      setRegisterPin(ledG, HIGH);
      break;
    }
    case 4 : {
      setRegisterPin(ledA, LOW);
      setRegisterPin(ledB, HIGH);
      setRegisterPin(ledC, HIGH);
      setRegisterPin(ledD, LOW);
      setRegisterPin(ledE, LOW);
      setRegisterPin(ledF, HIGH);
      setRegisterPin(ledG, HIGH);
      break;
    }
    case 5 : {
      setRegisterPin(ledA, HIGH);
      setRegisterPin(ledB, LOW);
      setRegisterPin(ledC, HIGH);
      setRegisterPin(ledD, HIGH);
      setRegisterPin(ledE, LOW);
      setRegisterPin(ledF, HIGH);
      setRegisterPin(ledG, HIGH);
      break;
    }
    case 6 : {
      setRegisterPin(ledA, HIGH);
      setRegisterPin(ledB, LOW);
      setRegisterPin(ledC, HIGH);
      setRegisterPin(ledD, HIGH);
      setRegisterPin(ledE, HIGH);
      setRegisterPin(ledF, HIGH);
      setRegisterPin(ledG, HIGH);
      break;
    }
    case 7 : {
      setRegisterPin(ledA, HIGH);
      setRegisterPin(ledB, HIGH);
      setRegisterPin(ledC, HIGH);
      setRegisterPin(ledD, LOW);
      setRegisterPin(ledE, LOW);
      setRegisterPin(ledF, LOW);
      setRegisterPin(ledG, LOW);
      break;
    }
    case 8 : {
      setRegisterPin(ledA, HIGH);
      setRegisterPin(ledB, HIGH);
      setRegisterPin(ledC, HIGH);
      setRegisterPin(ledD, HIGH);
      setRegisterPin(ledE, HIGH);
      setRegisterPin(ledF, HIGH);
      setRegisterPin(ledG, HIGH);
      break;
    }
    case 9 : {
      setRegisterPin(ledA, HIGH);
      setRegisterPin(ledB, HIGH);
      setRegisterPin(ledC, HIGH);
      setRegisterPin(ledD, HIGH);
      setRegisterPin(ledE, LOW);
      setRegisterPin(ledF, HIGH);
      setRegisterPin(ledG, HIGH);
      break;
    }
  } 
  writeRegisters();
}

void loop() {
  int randNumber = random(0, 10);
  print_Number(randNumber);
  delay(2000);
}
