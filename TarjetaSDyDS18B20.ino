#include <SPI.h>
#include <SD.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include <DHT.h>
#include <DHT_U.h>

#define SENSOR 8
int HUMEDAD;

// Pin donde está conectado DQ
const byte pinDatosDQ = 9;
#define SSpin 10


File archivo;
DHT dht(SENSOR, DHT11);
// Instancia a las clases OneWire y DallasTemperature
OneWire oneWireObjeto(pinDatosDQ); 
DallasTemperature sensorDS18B20(&oneWireObjeto); 

void setup() {
  pinMode(2, OUTPUT);
  //Inicamos la comnuicación serie
  Serial.begin(9600);
  // se inicia el bus 1-Wire
  sensorDS18B20.begin();
  dht.begin();
  
  Serial.println("Inicializando tarjeta...");
  if (!SD.begin(SSpin)) { 
    Serial.println("fallo en inicializacion !");
    return;
  }

  Serial.println("Inicializacion correcta");
  archivo = SD.open("datosth.txt", FILE_WRITE);

  if (archivo) {
    for (int i=1; i < 301; i++) {
   // Mandamos comandos para toma de temperatura a los sensores
  Serial.println("Mandando comandos a los sensores");
  sensorDS18B20.requestTemperatures(); // se envía el comando para leer la temperatura
  HUMEDAD = dht.readHumidity();
  
  archivo.print(i);
  archivo.print(",");
  archivo.print(sensorDS18B20.getTempCByIndex(0));
  archivo.print(",");
  archivo.print(sensorDS18B20.getTempCByIndex(1));
  archivo.print(",");
  archivo.println(HUMEDAD);
    
  Serial.println(i);
  Serial.print("temperatura sensor 0: ");
  Serial.println(sensorDS18B20.getTempCByIndex(0));
  Serial.print("temperatura sensor 1: ");
  Serial.println(sensorDS18B20.getTempCByIndex(1));
  Serial.print("Humedad: ");
  Serial.println(HUMEDAD);
  
  delay(1000);  
  }
  archivo.close();
  Serial.println("escritura correcta");
  }else {
    Serial.println("error en apertura de datosth.txt");
    
  }

}

void loop() {
  digitalWrite(2, HIGH);
  delay(1000);
  digitalWrite(2, LOW);
  delay(1000);
}
