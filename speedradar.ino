#define ADCpin A1
#define printDelay 0

#include "AnalogFrequency.h";
#include "U8g2lib.h";
#include "Wire.h";
uint32_t displayTimer=0;
U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);
float speedKM=0.0;
float speedMPH=0.0;
int del=1000;
void setup() {
Serial.begin(115200);

u8g2.begin();
u8g2.setFont(u8g2_font_amstrad_cpc_extended_8u);

setupADC(ADCpin);
}

void loop() {
if(fAvailable() &&millis()-displayTimer> printDelay) {
displayTimer=millis();
uint32_t frequency=getFreq();
speedKM=frequency/19.49;
speedMPH=frequency/31.36; 
Serial.print("kmph");
Serial.print(speedKM);
Serial.print("MPH");
Serial.print(speedMPH);

}
u8g2.clearBuffer();
u8g2.setFont(u8g2_font_profont17_tr);
u8g2.setCursor(50,17);
u8g2.println("speed");
u8g2.setCursor(55,40);
u8g2.println(speedKM);
u8g2.println("kmph");
u8g2.setFont(u8g2_font_open_iconic_app_4x_t);
u8g2.drawGlyph(20,40,72);
u8g2.sendBuffer();
delay(del);
}


  
  
