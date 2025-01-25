#include <Servo.h>

Servo servo1;  // Servo para o ambiente 1
Servo servo2;  // Servo para o ambiente 2

// Sensores LDR
const int LDR1 = A0;
const int LDR2 = A1;

// Servos
const int SERVO1_PIN = 9;
const int SERVO2_PIN = 10;

// Variáveis para leitura
int leitura1, leitura2;
int matriz[2][2];

// Intervalo de monitoramento
unsigned long tempoAnterior = 0;
const unsigned long intervalo = 60000; // 1 minuto

void setup() {
  Serial.begin(9600);
  
  // Configuração dos servos
  servo1.attach(SERVO1_PIN);
  servo2.attach(SERVO2_PIN);
 
 // Inicializa os servos na posição inicial
 servo1.write(0);
 servo2.write(0);
 
 // Configura os pinos dos LDR
 pinMode(LDR1, INPUT);
 pinMode(LDR2, INPUT);
 
 Serial.println("Sistema de monitoramento iniciado.");
}

void loop() {
 // Checar se o intervalo de tempo foi atingido
 unsigned long tempoAtual = millis();
 if (tempoAtual - tempoAnterior >= intervalo) {
 tempoAnterior = tempoAtual;

 // Obter leituras dos sensores
 leitura1 = analogRead(LDR1);
 leitura2 = analogRead(LDR2);

 // Atualizar a matriz com os valores lidos
 matriz[0][0] = leitura1;
 matriz[0][1] = leitura2;
 matriz[1][0] = leitura1 / 2; // Exemplo de cálculo adicional
 matriz[1][1] = leitura2 / 2; // Exemplo de cálculo adicional

 // Exibir a matriz
 Serial.println("Nova Matriz de Leitura:");
 for (int i = 0; i < 2; i++) {
 for (int j = 0; j < 2; j++) {
 Serial.print(matriz[i][j]);
 Serial.print("\t");
 }
 Serial.println();
 }

 // Verificar se os valores estão abaixo do limite
 if (leitura1 < 50 || leitura2 < 50) {
 Serial.println("Luminosidade baixa detectada! Acionando os servos...");
 // Acionar os servos
 servo1.write(90); // Girar para fechar a cortina
 servo2.write(90);
 delay(2000); // Tempo para o movimento dos servos
 
 // Voltar à posição inicial
 servo1.write(0);
 servo2.write(0);

 // Aguardar antes de reiniciar
 Serial.println("Reiniciando monitoramento em 10 segundos...");
 delay(10000); // Aguarde 10 segundos antes de reiniciar
 }
 }
}