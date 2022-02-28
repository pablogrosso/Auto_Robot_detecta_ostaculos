/*Pinout de los motores y sentidos de giro
 * ver Excel tambien.

Motor Izq    IN1 IN2    Motor Der  IN3 IN4
Detenido      0   0       Detenido  0   0
avanza        0   1       avanza    0   1
retrocede     1   0       retrocede 1   0
Detenido      1   1       Detenido  1   1

                                      IN1 IN2 IN3 IN4
Giro Derecha    Avanza Izquierdo       0   1   -   -
                Retroceder Derecho     -   -   1   0
Gira Izquierda  Retrocede Izquierdo    1   0   -   -
                Avanza Derecho         -   -   0   1

                IN1 IN2 IN3 IN4
Giro Derecha     0   1   1   0
Giro Izquierda   1   0   0   1

*/
