#include <VirtualWire.h>

uint8_t buf[VW_MAX_MESSAGE_LEN];
uint8_t buflen = VW_MAX_MESSAGE_LEN;

void setup() {
  Serial.begin(9600);
  
  vw_setup(2000);
  vw_rx_start();
}

void loop() {
  String str = "";
  float temp;
  int lumino;
  char sensor [2];
  if(vw_have_message)
  {
    if(vw_get_message(buf,&buflen)){      
      int i;
      
      char tmp = (char) buf[0];
      char sensor = (char) buf[1];
     
      char bufFloat[4];
      Serial.print("=>");
      Serial.println(sensor);
      Serial.println("--");
      
      if(tmp == 'R'){
        if(sensor == 'T'){
          for(i = 2; i < buflen; i++){
            bufFloat[i-2] = (char)buf[i];
          }
          memcpy(&temp, bufFloat, 4);
          Serial.print(temp);
          
        }
        
        if(sensor == 'L'){
          for(i = 2; i < buflen; i++){
            bufFloat[i-2] = (char)buf[i];
          }
          memcpy(&lumino, bufFloat, 2);
          Serial.print(lumino);
        }
        
        char bufForScreen[buflen];
        for(i = 0; i < buflen; i++){
          bufForScreen[i] = (char)buf[i];
        }
        bufForScreen[0] = 'E';
        
        vw_send((uint8_t *)bufForScreen, buflen); 
        vw_wait_tx(); 
        Serial.println("Done !");
      }
    }
  }

  delay(1000);
}
