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
  
  tft.setCursor(0, 0);
  tft.setTextColor(ST7735_YELLOW);
  tft.setTextWrap(true);
  tft.print("Blablablablablablablablabla");
}

void loop() {
  // put your main code here, to run repeatedly:
  String str = "";
  float temp = 0.0;
  if(vw_have_message)
  {
    if(vw_get_message(buf,&buflen)){
      int i;
      memcpy(&temp, buf, buflen);
      Serial.print(temp);
      }
      Serial.println(" ");
    }
  
  
  tft.fillScreen(ST7735_BLACK);
  tft.setCursor(0, 30);
  tft.setTextColor(ST7735_YELLOW);
  tft.setTextWrap(true);
  tft.println("Temperature : ");
  tft.println("");
  tft.print(temp);
  tft.print(" C");
  delay(2000);
}
