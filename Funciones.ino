/*
 * Funciones para manejo del motor y medicion de distancias
 *                            Pablo Grosso(2022)
 */
void avanzar(int velocidad){             //Funcion para avanzar con ambos motores
    analogWrite(ENA, velocidad);
    analogWrite(ENB, velocidad);
    digitalWrite(IN1, 0);
    digitalWrite(IN2, 1);
    digitalWrite(IN3, 0);
    digitalWrite(IN4, 1);
}

void retroceder(int velocidad){
    analogWrite(ENA, velocidad);
    analogWrite(ENB, velocidad);
    digitalWrite(IN1, 1);
    digitalWrite(IN2, 0);
    digitalWrite(IN3, 1);
    digitalWrite(IN4, 0);
}

void frenar(){
    digitalWrite(IN1, 0);
    digitalWrite(IN2, 0);
    digitalWrite(IN3, 0);
    digitalWrite(IN4, 0);
}

void girarIzquierda(int velocidad){      //Funcion para girar a la izquierda
    analogWrite(ENA, velocidad);
    analogWrite(ENB, velocidad);
    digitalWrite(IN1, 1);
    digitalWrite(IN2, 0);
    digitalWrite(IN3, 0);
    digitalWrite(IN4, 1);
}

void girarDerecha(int velocidad){        //Funcion para girar a la derecha
    analogWrite(ENA, velocidad);
    analogWrite(ENB, velocidad);
    digitalWrite(IN1, 0);
    digitalWrite(IN2, 1); 
    digitalWrite(IN3, 1);
    digitalWrite(IN4, 0);
}

int CalcularDistancia() {   //Funcion para calcular la distancia. La variable distancia es global (ver como cambiar eso para que devuelva el valor)
  int distancia;
  int duracionEco;
  digitalWrite(SR04Trig, LOW);          // Envia señal a Trigger del ultrasonido
  delayMicroseconds(2);   
  digitalWrite(SR04Trig, HIGH);          // Envia señal a Trigger del ultrasonido
  delayMicroseconds(10);                             // Espera 1 milisegundo
  digitalWrite(SR04Trig, LOW);           // Apaga el trigger (deja de emitir señal)
  duracionEco = pulseIn(SR04Eco, HIGH);  // captura la duración del eco
  distancia = (float (duracionEco)) / 58.2;       // divide para converir en centimetros
  return distancia;
}
