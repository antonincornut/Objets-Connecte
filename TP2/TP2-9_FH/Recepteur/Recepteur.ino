#include <VirtualWire.h>

uint8_t buf[255];
uint8_t buflen = 255;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Attente reception");
  vw_setup(2000);
  vw_rx_start();
}

void loop() {
  // put your main code here, to run repeatedly:
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
