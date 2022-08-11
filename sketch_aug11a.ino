#include "DHT.h"
#define DHTPIN 2
#define DHTTYPE DHT11
int sensorHumedad = A0;
int waterPump = 13;


DHT dht(DHTPIN,DHTTYPE);
void setup() {
  Serial.begin(9600);
  dht.begin();
  pinMode(waterPump,OUTPUT);
}

void loop() {
  delay(2000);
 //Humedad ambiente
  float humidityA = dht.readHumidity();
  // Temperatura ambiente
  float temperature = dht.readTemperature();
  //Humedad del suelo
  int humidityS = analogRead(sensorHumedad);
 
  // Compueba error de lectura
  if (isnan(humidityA) || isnan(temperature)) {
    Serial.println("No hay datos");
    return;
  }

  //Activa bomba de agua según humedad del suelo
 if(humidityS>500)
 digitalWrite(waterPump,HIGH);
 else
digitalWrite(waterPump,LOW);


//Datos de sensores ,humedad-temperatura ambiente y humedad del suelo; 
  Serial.print("Humedad: ");
  Serial.print(humidityA);
  Serial.print(" %\t");
  Serial.print("Temperatura: ");
  Serial.print(temperature);
   Serial.print(" %\t");
  Serial.print("Humedad del suelo: ");
  Serial.print(humidityS);
  Serial.println(" %\t");
 


}
