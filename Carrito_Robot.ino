#include <Servo.h>
//#include <MotorDriver.h>

Servo myservo;  // create servo object to control a servo

//int volatile velocidad;
int IN1 = 7;                  //Motor 1 retroceso
int IN2 = 8;                  //Motor 1 avanza
int IN3 = 13;                 //Motor 2 retroceso
int IN4 = 12;                 //Motor 2 avanza
int ENA = 6;                  //PWM Arduino UNO - EN1 en puente H L293D - Motor izquierdo
int ENB = 5;                  //PWM Arduino UNO - EN2 en puente H L293D - Motor derecho
int SR04Trig = 9;             // Arduino UNO
int SR04Eco = 10;             // Arduino UNO
int visualDerecha;            // Variable para guardar distancia a objetos a la derecha
int visualIzquierda;          // Variable para guardar distancia a objetos a la izquierda
int DistObst;                 // Distancia al objeto devuelta por la funcion de medicion
int distObstMax = 30;         // Defino la distancia maxima para definir cambio de sentido
int distObstMin = 2;          // Defino la distancia minima para el cambio de sentido
int velocidadGiro = 110;
int velocidadAvance = 220;
int tiempoDeGiro = 300;       //Milisegundos
//char giro = 'R';
//int pos = 90;                 // Variable para guardar la posicion del servo (grados)

void setup() {

  myservo.attach(2);  // Conecto el servo en el pin 02

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(SR04Trig, OUTPUT);
  pinMode(SR04Eco, INPUT);

  Serial.begin(9600);
  
  delay(5000); //genero una pausa luego de encenderlo

}

void loop() {
  
  DistObst = CalcularDistancia();
   
  if (DistObst <= distObstMax && DistObst >= distObstMin) {
     frenar();
     delay(250);
     retroceder(velocidadAvance);
     delay(300);
     frenar();
      myservo.write(30);                      // Posiciono el servo 30º a la derecha
      delay(300);
        visualDerecha = CalcularDistancia();  // Guardo en la variable la distancia al objeto de la derecha
        Serial.print(" Derecha: ");
        Serial.println( visualDerecha);
        delay(1000);
      myservo.write(150);                       // Posiciono el servo a 150º a la izquierda
      delay(300);
        visualIzquierda = CalcularDistancia();  // Guardo en la variable la distancia al objeto de la izquierda
        Serial.print(" Izquierda: ");
        Serial.println( visualIzquierda);
      delay(1000);

      myservo.write(90);                        // Vuelvo a centrar el sensor al frente

      if (visualIzquierda > visualDerecha){     // Si tengo mas lugar a la izq entonces giro a la izquierda
        frenar();
        Serial.println(" Giro a la izquierda... ");
        girarIzquierda(velocidadGiro);
      }

      if (visualIzquierda < visualDerecha){     // Si tengo mas lugar a la der entonces giro a la derecha
        frenar();
        Serial.println(" Giro a la derecha... ");
        girarDerecha(velocidadGiro);
      }
     
    delay(tiempoDeGiro);
    frenar();
    delay(300); 
    
  }
  else {
    avanzar(velocidadAvance);
  }
  
}
