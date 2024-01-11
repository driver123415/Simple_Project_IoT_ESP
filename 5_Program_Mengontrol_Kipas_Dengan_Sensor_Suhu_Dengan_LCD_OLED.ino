#include <DallasTemperature.h>
#include <OneWire.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define ONE_WIRE_BUS 12
#define kipas1 D0
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
#define SCREEN_ADDRESS 0x3C

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature DS18B20(&oneWire);
float suhu;

void setup()
{
  pinMode(kipas1, OUTPUT);
  digitalWrite(kipas1, HIGH);
  Serial.begin(9600);
  DS18B20.begin();

  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS))
  {
    Serial.println(F("SSD1306 gagal dialokasikan"));
    while (true)
    {
      Serial.println(F("Periksa koneksi I2C dan restart Arduino"));
      delay(2000); 
    }
  }
  display.display();
  delay(2000);
  display.clearDisplay();
}

void loop()
{
  DS18B20.requestTemperatures();
  suhu = DS18B20.getTempCByIndex(0);

  if (suhu == DEVICE_DISCONNECTED_C)
  {
    Serial.println(F("Sensor DS18B20 tidak terhubung. Periksa koneksi."));
    delay(5000); 
    return;
  }
  Serial.print(F("Suhu "));
  Serial.println(suhu);
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.print(F("Suhu "));
  display.println(suhu);
  display.display();

  if (suhu > 33.00)
  {
    digitalWrite(kipas1, LOW);
  }
  else if (suhu < 30.00)
  {
    digitalWrite(kipas1, HIGH);
  }
  delay(1000);
}
