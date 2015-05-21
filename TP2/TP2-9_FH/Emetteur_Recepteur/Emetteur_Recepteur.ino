#include <VirtualWire.h>

uint8_t buf[VW_MAX_MESSAGE_LEN];
uint8_t buflen = VW_MAX_MESSAGE_LEN;

const char *msg = "Message 2"; // Tableau qui contient notre message

void setup() {
  Serial.begin(9600);
  Serial.println("Attente reception");
  vw_setup(2000);
  vw_rx_start();
}

void loop() {
  
    Serial.print("Envoie..."); // On signale le début de l'envoi
    vw_send((uint8_t *)msg, strlen(msg)); // On envoie le message 
    vw_wait_tx(); // On attend la fin de l'envoi
    Serial.println("Done !"); // On signal la fin de l'envoi
    delay(1000); // Et on attend 1s pour éviter que deux messages se superpose
    
  if(vw_have_message)
  {
    if(vw_get_message(buf,&buflen)){
      int i;
      for(i = 0; i < buflen; i++)
      	Serial.print((char) buf[i]);
      Serial.println(" ");
    }
  }
}
