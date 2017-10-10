#include<Servo.h>
#include<Wire.h>
#include<SPI.h>
#include <Adafruit_BMP280.h>
#include <Adafruit_Sensor.h>

Servo servo1;
float altura = 0  ,altura_ref = 0,altura_max = 0,altura_minima = 0,altura_pasada=0,apogeo=0;

float presion=560; //la presion local, bogota esta fucking arriba
Adafruit_BMP280 bme;//I2C
String visual  ;
String texto = " / ";
byte led_amarillo=4;
void setup(){
  pinMode(led_amarillo,OUTPUT);
  Serial.begin(9600);
  if(!bme.begin()){
    Serial.println("error");
  }
  
  servo1.attach(9);
  servo1.write(20);

  delay (500);
  altura_ref=bme.readAltitude(presion);
}

void loop(){
    Serial.begin(9600);
    if(!bme.begin()){
       Serial.print("error");
       while(!bme.begin());
  }
    analizar_altura();
    if(altura>altura_max){
    altura_max=altura;
    } 
    if (altura-altura_pasada<=-0.5){
      delay(150);
      analizar_altura();
      if(altura-altura_pasada<=-1){
          delay(150);
          analizar_altura();
          if(altura-altura_pasada<=-1.5){
              
              digitalWrite(led_amarillo,HIGH);  
              }
      }
   }

    visual = altura + texto + altura_max;  
    Serial.println(visual);
    delay(500);
}

void analizar_altura(){
   altura= bme.readAltitude(presion)-altura_ref;
}

