#include<Wire.h>
#include<SPI.h>
#include <Adafruit_BMP280.h>
#include <Adafruit_Sensor.h>

//VARIABLES GLOBALES:
int16_t valores_n; //valores sin refinar

unsigned long pasado = 0; //es el tiempo inicial, tambien en milisengundos
int ahora;//es un contador que cuenta los milisegundos pasados
int tiempo_muestreo = 1;

float altura_actual = 0;  //Es la altura que mide el sensor en un instante k
float altura_ref = 0; //se hace una medicion y se pone como valor negativo, de tal manera que la diferencia entre los futuros datos
                      // y la altura actual sea la correcta, si no se mueve se mantiene en cero


//VARIABLES NO USADAS (TEMPORAL):
/*float altura_pasada=0;
  float altura_max = 0;
 */
float presion=560; //la presion local, bogota esta fucking arriba
Adafruit_BMP280 bme;//I2C


void setup(){
  Serial.begin(9600);//Es lo que inicia el BMP280
  if(!bme.begin()){
    Serial.println("error");
  }//fin de la iniciacion del sensor
  
  delay(100);//una pequeña espera para darle tiempo de iniciar
  altura_ref=bme.readAltitude(presion);//la diferencia para que el valor inicial sea cero
}



void loop(){
  Serial.begin(9600);//Es lo que inicia el BMP280
  if(!bme.begin()){
    Serial.print("error");
    while(!bme.begin());
  }//fin de la iniciacion del sensor


  ahora = millis();//es un contador que cuenta los milisegundos pasados
  
  int cambio_tiempo = ahora - pasado;
  if(cambio_tiempo>=tiempo_muestreo){
    Serial.println(cambio_tiempo); 
    pasado = ahora;
   
  }analizar_altura();

    /*if(altura>altura_max){
    altura_max=altura;
    } 
    if (altura-altura_pasada<=-0.2){
      delay(40);
      analizar_altura();
      if(altura-altura_pasada<=-0.5){
          delay(40);
          analizar_altura();
          if(altura-altura_pasada<=-0.8){
              //servo1.write(180); 
              }
      }
   }*/

  
    Serial.println(altura_actual);
    delay(200);
}

void analizar_altura(){
   altura_actual= bme.readAltitude(presion)-altura_ref;
}
