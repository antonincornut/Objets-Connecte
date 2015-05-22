#include <OneWire.h> // Inclusion de la librairie OneWire
#include <VirtualWire.h>

uint8_t buf[VW_MAX_MESSAGE_LEN];
uint8_t buflen = VW_MAX_MESSAGE_LEN;
 
#define DS18B20 0x28     // Adresse 1-Wire du DS18B20
#define BROCHE_ONEWIRE 7 // Broche utilisée pour le bus 1-Wire

int photocellPin = 0; // the cell and 10K pulldown are connected to a0
int photocellReading; // the analog reading from the analog resistor divider

void setup(void) {
  Serial.begin(9600); // Initialisation du port série
  vw_setup(2000);
}

void loop(void) {
  
  int lumino;
  photocellReading = analogRead(photocellPin);
  Serial.print("Analog reading = ");
  Serial.print(photocellReading);
  if (photocellReading < 10) {
    Serial.println(" - Noir");
    lumino = 0;
  } else if (photocellReading < 200) {
    Serial.println(" - Sombre");
    lumino = 1;
  } else if (photocellReading < 500) {
    Serial.println(" - Lumiere");
    lumino = 2;
  } else if (photocellReading < 800) {
    Serial.println(" - Lumineux");
    lumino = 3;
  } else {
    Serial.println(" - Tres lumineux");
    lumino = 4;
  }
  
  char bufInt[2];
  memcpy(bufInt, &lumino, 2);
  char id = 'L';
  char dir = 'R';   
  char bufLumino[sizeof(lumino)+4];
  bufLumino[0] = dir;
  bufLumino[1] = id;
  for (int i = 2; i < 4; i++){
    bufLumino[i] = bufInt[i-2];
  }
  
  vw_send((uint8_t *)bufLumino, 4);
  vw_wait_tx();
  Serial.println("Done !");
  delay(3000);
}
