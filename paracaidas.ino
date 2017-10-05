#include<Servo.h>
#include<Wire.h>
#include<SPI.h>
#include <Adafruit_BMP280.h>
#include <Adafruit_Sensor.h>

Servo servo1;
float altura = 0  ,altura_ref = 0,altura_max = 0,altura_minima = 0;
float presion=560; //la presion local, bogota esta fucking arriba
Adafruit_BMP280 bme;//I2C
String visual  ;
String texto = " / ";

void setup(){
  pinMode(13,OUTPUT);
  servo1.attach(9);
  servo1.write(0);
  Serial.begin(9600);
  if(!bme.begin()){
    Serial.println("error");
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
    if(altura>altura_max){
    altura_max=altura;
  }
   if (altura_max<=(altura+1)){
    servo1.write(90);
    digitalWrite(13,HIGH);
   }

  visual = altura + texto + altura_max;  
   Serial.println(visual);
  delay(500);
}
