#include <OneWire.h>
#include <LiquidCrystal.h>

#define DS18B20 0x28     // Adresse 1-Wire du DS18B20
#define BROCHE_ONEWIRE 12 // Broche utilisée pour le bus 1-Wire
 
OneWire ds(BROCHE_ONEWIRE); // Création de l'objet OneWire ds
 
// Fonction récupérant la température depuis le DS18B20
// Retourne true si tout va bien, ou false en cas d'erreur
boolean getTemperature(float *temp){
  byte data[9], addr[8];
  // data : Données lues depuis le scratchpad
  // addr : adresse du module 1-Wire détecté
 
  if (!ds.search(addr)) { // Recherche un module 1-Wire
    ds.reset_search();    // Réinitialise la recherche de module
    return false;         // Retourne une erreur
  }
   
  if (OneWire::crc8(addr, 7) != addr[7]) // Vérifie que l'adresse a été correctement reçue
    return false;                        // Si le message est corrompu on retourne une erreur
 
  if (addr[0] != DS18B20) // Vérifie qu'il s'agit bien d'un DS18B20
    return false;         // Si ce n'est pas le cas on retourne une erreur
 
  ds.reset();             // On reset le bus 1-Wire
  ds.select(addr);        // On sélectionne le DS18B20
   
  ds.write(0x44, 1);      // On lance une prise de mesure de température
  delay(800);             // Et on attend la fin de la mesure
   
  ds.reset();             // On reset le bus 1-Wire
  ds.select(addr);        // On sélectionne le DS18B20
  ds.write(0xBE);         // On envoie une demande de lecture du scratchpad
 
  for (byte i = 0; i < 9; i++) // On lit le scratchpad
    data[i] = ds.read();       // Et on stock les octets reçus
   
  // Calcul de la température en degré Celsius
  *temp = ((data[1] << 8) | data[0]) * 0.0625; 
   
  // Pas d'erreur
  return true;
}

LiquidCrystal lcd(11,10,9,8,7,6,5,4,3,2);

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16,2);
  lcd.write("Coucou!!! ");
  lcd.write(" - Voici la temperature actuelle : ");
  //pinMode(12, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  float temp;
   
  // Lit la température ambiante à ~1Hz
  if(getTemperature(&temp)) {
    Serial.print("Temperature : ");
    Serial.print((uint8_t)temp);
    //Serial.write(176); // caractère °
    Serial.write('C');
    Serial.println();
    
    char outstr[15];
    dtostrf(temp,7, 0, outstr);
    
    lcd.clear();
    lcd.setCursor(15, 0);
    lcd.write("=> ");
    lcd.write(outstr);
    lcd.write(" C ");
    for (int positionCounter = 0; positionCounter < 13; positionCounter++) {
      // scroll one position left:
      lcd.scrollDisplayLeft(); 
      // wait a bit:
      delay(500);
    }
  }
}
