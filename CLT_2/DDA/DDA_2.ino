#include <Servo.h>

Servo meuServo; // Cria o objeto do servo

int pinoPotenciometro = A1;
int pinoLDR = A2;
int pinoTCRT = A0;

int ledBrilho = 10;
int ledLDR = 11;
int pinoServo = 9;

void setup() {
  meuServo.attach(pinoServo); // Conecta o servo ao pino
  pinMode(ledBrilho, OUTPUT);
  pinMode(ledLDR, OUTPUT);
  pinMode(pinoTCRT, INPUT);
  Serial.begin(9600);
}

void loop() {
  // Controle do LED pelo Potenciômetro
  int valorPot = analogRead(pinoPotenciometro);
  int brilho = map(valorPot, 0, 1023, 0, 255); // Mapeia o valor para brilho
  analogWrite(ledBrilho, brilho);

  // Controle do Servo pelo TCRT5000
  int valorTCRT = analogRead(pinoTCRT);
  if (valorTCRT > 500) { // Ajuste o valor conforme o sensor
    meuServo.write(90); // Gira o servo para 90°
  } else {
    meuServo.write(0); // Retorna o servo para 0°
  }

  // Controle do LED pelo LDR
  int valorLDR = analogRead(pinoLDR);
  int brilhoLDR = map(valorLDR, 0, 1023, 255, 0); // Inverte a escala
  analogWrite(ledLDR, brilhoLDR);

  // Monitoramento no Serial
  Serial.print("Potenciometro: ");
  Serial.print(valorPot);
  Serial.print(" | TCRT: ");
  Serial.print(valorTCRT);
  Serial.print(" | LDR: ");
  Serial.println(valorLDR);

  delay(100);
}
