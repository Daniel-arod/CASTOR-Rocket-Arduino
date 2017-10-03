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
  despegue(estado);
}
void despegue(int x){
    if (x =='a'){
     Serial.write(x);
     digitalWrite(led13,HIGH);//se prende el led, dando señal de que funciona
     digitalWrite(2,HIGH);//motor
     digitalWrite(3,LOW);//motor
     delay(2500);//tiempo que se ejecuta, 2.5 segundos
     digitalWrite(2,LOW);//se detiene el motor
     digitalWrite(3,LOW);
     delay(2500);//tiempo que se ejecuta, 2.5 segundos
     digitalWrite(2,LOW);//motor gira en sentido inverso
     digitalWrite(3,HIGH);
     delay(2500);//tiempo que se ejecuta, 2.5 segundos
     digitalWrite(2,LOW);//se apaga
     digitalWrite(3,LOW);
     x=0;//x se vuelve cero para evita que se vuelva a ejecutar
    }
}
