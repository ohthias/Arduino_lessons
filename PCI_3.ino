/* Solução do Projeto 3 da Isa, do Livro "Sai do LEGO, e não sei para onde vou: Base Programação"*/

#include <Servo.h> // Inclui a biblioteca Servo para controlar o servo motor

// Definição dos pinos
const int potPin = A0;    // Pino do potenciômetro
Servo meuServo;           // Cria o objeto servo

void setup() {
  meuServo.attach(9);    // O pino 9 controla o servo
  Serial.begin(9600);    // Inicializa a comunicação serial para depuração
}

void loop() {
  int potValue = analogRead(potPin); // Lê o valor do potenciômetro (0-1023)

  // Mapeia o valor do potenciômetro para o intervalo de 0 a 180 (para o servo)
  int servoPos = map(potValue, 0, 1023, 0, 180);

  // Move o servo para a posição calculada
  meuServo.write(servoPos);

  // Exibe a posição do servo no monitor serial
  Serial.print("Potenciômetro: ");
  Serial.print(potValue);
  Serial.print(" -> Posição do Servo: ");
  Serial.println(servoPos);

  delay(15); // Atraso para suavizar o movimento do servo
}
