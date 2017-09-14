#include<Wire.h>
#include<SPI.h>
#include <Adafruit_BMP280.h>
#include <Adafruit_Sensor.h>

float altura,altura_ref,altura_max,altura_minima;
float presion=560; //la presion local, bogota esta fucking arriba
Adafruit_BMP280 bme;//I2C

void setup(){
  Serial.begin(9600);
  if(!bme.begin()){
    Serial.print("error");
  }
  delay (500);
  altura_ref=bme.readAltitude(presion);
  altura=0;
  altura_max=0;
  altura_minima=0;
}

void loop(){
    Serial.begin(9600);
  if(!bme.begin()){
    Serial.print("error");
    while(!bme.begin());
  }
  altura= bme.readAltitude(presion)-altura_ref;
    if(altura>=altura_max){
    altura_max=altura;
  }
  if(altura<=altura_minima){
    altura_minima=altura;
  }
  Serial.print("\n");
  Serial.print("altura : ");
  Serial.print(altura);

  delay(500);
}
