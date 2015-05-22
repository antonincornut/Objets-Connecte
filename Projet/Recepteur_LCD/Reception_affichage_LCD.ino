#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>
#include <SPI.h>
#include <VirtualWire.h>

uint8_t buf[VW_MAX_MESSAGE_LEN];
uint8_t buflen = VW_MAX_MESSAGE_LEN;

#define TFT_CS     6
#define TFT_RST    8 
#define TFT_DC     7
#define TFT_SCLK 4
#define TFT_MOSI 5
Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_MOSI, TFT_SCLK, TFT_RST);


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  vw_setup(2000);
  vw_rx_start();
  
  tft.initR(INITR_BLACKTAB);
  tft.fillScreen(ST7735_BLACK);
}

void loop() {
  // put your main code here, to run repeatedly:
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
      Serial.println(tmp);
      Serial.println("--");
      if(tmp == 'E'){
        tft.fillScreen(ST7735_BLACK); 
        Serial.println("Ecran");
        if(sensor == 'T'){
          Serial.println("Temprature");
          for(i = 2; i < buflen; i++){
            bufFloat[i-2] = (char)buf[i];
          }
          memcpy(&temp, bufFloat, 4);
          Serial.print(temp);
          
          tft.setCursor(0, 30);
          tft.setTextColor(ST7735_YELLOW);
          tft.setTextWrap(true);
          tft.println("Temperature : ");
          tft.println("");
          tft.print(temp);
          tft.print(" C");
        }
        
        if(sensor == 'L'){
          Serial.println("Lumiere");
          for(i = 2; i < buflen; i++){
            bufFloat[i-2] = (char)buf[i];
          }
          memcpy(&lumino, bufFloat, 2);
          Serial.print(lumino);
          
          tft.setCursor(0, 60);
          tft.setTextColor(ST7735_YELLOW);
          tft.setTextWrap(true);
          tft.println("Lumiere : ");
          switch (lumino){
            case 0 : {
              tft.println("Eteint");
              break;
            }
            case 1 : {
              tft.println("Sombre");
              break;
            }
            case 2 : {
              tft.println("Eclaire");
              break;
            } 
            case 3 : {
              tft.println("Lumineux");
              break;
            }
            case 4 : {
              tft.println("Tres lumineux");
              break;
            }
          }
        }
      }
    }
    Serial.println(" ");
  }

  delay(2000);
}
