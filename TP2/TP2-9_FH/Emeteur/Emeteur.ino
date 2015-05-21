#include <VirtualWire.h> // On inclus la librairie VirtualWire
 
const char *msg = "Txt send"; // Tableau qui contient notre message
                                             
void setup()
{
    Serial.begin(9600); // Initialisation du port série pour avoir un retour sur le serial monitor
    Serial.println("Début communication"); // Petit message pour tester que l'interface sérial se lance bien
                                             
    vw_setup(2000);     // initialisation de la librairie VirtualWire à 2000 bauds
}
                                             
void loop()
{
    Serial.print("Envoie..."); // On signale le début de l'envoi
    vw_send((uint8_t *)msg, strlen(msg)); // On envoie le message 
    vw_wait_tx(); // On attend la fin de l'envoi
    Serial.println("Done !"); // On signal la fin de l'envoi
    delay(1000); // Et on attend 1s pour éviter que deux messages se superpose
}
