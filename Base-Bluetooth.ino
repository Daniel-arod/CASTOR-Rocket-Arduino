int led13=13;
int estado=0;

void setup(){
  Serial.begin(9600);
  pinMode(led13,OUTPUT);
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
}

void loop(){
 digitalWrite(2,LOW);
 digitalWrite(3,LOW);
 digitalWrite(13,LOW);

 if(Serial.available()>0){
 estado = Serial.read();
 }
 if (estado =='a'){
   Serial.write(estado);
   digitalWrite(led13,HIGH);
   digitalWrite(2,HIGH);
   digitalWrite(3,LOW);
   delay(5000);
   digitalWrite(2,LOW);
   digitalWrite(3,LOW);
   delay(1000);
   digitalWrite(2,LOW);
   digitalWrite(3,HIGH);
   delay(5000);
   digitalWrite(2,LOW);
   digitalWrite(3,LOW);
  }
if(estado=='b'){
   digitalWrite(led13,LOW);
   Serial.write(estado);
  }
} 
