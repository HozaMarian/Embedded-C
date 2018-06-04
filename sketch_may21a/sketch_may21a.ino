#include "dht.h"

dht DHT;

#define DHT11_PIN 7

void setup(){
  Serial.begin(9600);
}

void loop()
{
  int chk = DHT.read11(DHT11_PIN);
  if(DHT.temperature != -999.00){
    Serial.print("Temperature = ");
    Serial.println(DHT.temperature);
    Serial.print("Humidity = ");
    Serial.println(DHT.humidity);
    if(DHT.humidity > 88.00)
      Serial.println("DANGER!!!!");
    
  }
  delay(200);
}
