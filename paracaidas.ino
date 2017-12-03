#include<Servo.h>
int led13=13;
int estado=0;

Servo servo1;

void setup(){
  Serial.begin(9600);
  pinMode(led13,OUTPUT);
  servo1.attach(9);
  servo1.write(0);
 
}

void loop(){
 digitalWrite(13,LOW);

 if(Serial.available()>0){
 estado = Serial.read();
 }
  despegue(estado);
 
}
void despegue(int x){
    if (x =='a'){
     Serial.write(x);
     digitalWrite(13,HIGH);
     servo1.write(180);
    }
}
