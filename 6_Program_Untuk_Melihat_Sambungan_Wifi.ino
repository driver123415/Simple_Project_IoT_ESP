#include <ESP8266WiFi.h>            
#include <WiFiClientSecure.h> 

const char* ssid     = "ChangeThisToYourWifiUsername";    //Isikan username wifi yang akan digunakan untuk terhubung ke internet
const char* password = "ChangeThisToYourWifiPassword";    //Isikan password wifi yang digunakan

int wifiStatus; 
     
void setup() {
      
Serial.begin(115200);
delay(200);
    
   
Serial.println();
Serial.println();
Serial.print("Terkoneksi dengan Wifi : ");
Serial.println(ssid);
WiFi.begin(ssid, password);
      
while (WiFi.status() != WL_CONNECTED) {
  delay(500);
  Serial.print(".");
  }     
}   
     
void loop() {
  wifiStatus = WiFi.status();
  if(wifiStatus == WL_CONNECTED){
    Serial.println("");
    Serial.println("ESP8266 sudah terkonesi dg Wifi!");  
    Serial.println("IP address esp8266 : ");
    Serial.println(WiFi.localIP());  
    }
    else{
      Serial.println("");
      Serial.println("WiFi tdk terkoneksi");
      }
      
    delay(1000); 
}
