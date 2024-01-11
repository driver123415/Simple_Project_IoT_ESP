#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <DallasTemperature.h>
#include <OneWire.h>         

#define SCREEN_WIDTH 128 
#define SCREEN_HEIGHT 64 
#define ONE_WIRE_BUS 12
#define OLED_RESET     -1 
#define SCREEN_ADDRESS 0x3C
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature DS18B20(&oneWire);
float temp;

void setup()
{
  Serial.begin(9600);
  DS18B20.begin();
  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); 
  }
}
void loop() {
  DS18B20.requestTemperatures();
  temp = DS18B20.getTempCByIndex(0);
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0,28);
  display.println(temp);
  display.display();
  delay(1000);
  display.clearDisplay();
}
