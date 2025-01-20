#include <Servo.h>  // Inclui a biblioteca Servo

// Definindo os pinos
const int trigPin = 9;
const int echoPin = 8;
const int servoPin = 3;
const int led1 = 4;
const int led2 = 5;
const int led3 = 6;

Servo meuServo;  // Cria o objeto para controlar o servo

int cicloContador = 0;  // Contador para controlar quantas vezes o servo gira

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  meuServo.attach(servoPin); // Conecta o servo ao pino 6

 Serial.begin(9600); // Inicia a comunicação serial para debugar
}

void loop() {
 // Medir a distância usando o sensor ultrassônico
 long duracao = pulseIn(trigPin, HIGH);
 long distancia = (duracao / 2) / 29.1; // Distância em centímetros

 // Exibir a distância no monitor serial (opcional para testes)
 Serial.print("Distancia: ");
 Serial.println(distancia);

 // Se a distância for menor que 20cm (indicando que uma pessoa está perto)
 if (distancia < 20) {
 // Aciona o movimento do servo e acende o LED
 meuServo.write(90); // Move o servo para 90 graus
 digitalWrite(led1, HIGH); // Acende o primeiro LED
 delay(2000); // Espera 2 segundos para observar o LED aceso

 meuServo.write(0); // Volta o servo para a posição original
 delay(1000); // Espera 1 segundo antes de repetir

 digitalWrite(led1, LOW); // Apaga o primeiro LED
 cicloContador++; // Aumenta o contador de ciclos

 // Quando o contador chegar à 5, acende o próximo LED
 if (cicloContador == 5) {
 digitalWrite(led2, HIGH); // Acende o segundo LED
 }
 
 // Quando o contador chegar à 10, acende o terceiro LED
 if (cicloContador == 10) {
 digitalWrite(led3, HIGH); // Acende o terceiro LED
  }
 }