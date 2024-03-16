// inclui biblioteca do servomotor
#include <Servo.h> 

// define pinos dos servos
#define pinGirar 2
#define pinEsticar 3
#define pinSubir 4
#define pinGarra 5

// define as portas dos potenciometros
#define potGirar A0
#define potEsticar A1
#define potSubir A2
#define potGarra A3

// nomeia os servos
Servo girar, esticar, subir, garra;

// cria as variáveis dos ângulos de cada motor
int angGirar, angEsticar, angSubir, angGarra;

void setup() {
  // atribui pinos dos servos
  girar.attach(pinGirar);
  esticar.attach(pinEsticar);
  subir.attach(pinSubir);
  garra.attach(pinGarra);
}

void loop(){
  // leitura dos potenciometros
  angGirar = map(analogRead(potGirar), 0, 1023, 30, 160); // Angulo para girar
  angEsticar = map(analogRead(potEsticar), 0, 1023, 60, 100); // Angulo para esticar
  angSubir = map(analogRead(potSubir), 0, 1023, 40, 180);  // Angulo para subir
  angGarra = map(analogRead(potGarra), 0, 1023, 20, 118); // Angulo da garra

  // posicionamento dos potenciometros 
  girar.write(angGirar);
  esticar.write(angEsticar);
  subir.write(angSubir);
  garra.write(angGarra);

  // tempo de espera para recomeçar
  delay(100);
}
