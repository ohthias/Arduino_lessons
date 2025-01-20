// Definições dos pinos
#define TRIG_PIN 9
#define ECHO_PIN 10
#define LED1 3
#define LED2 4
#define LED3 5

void setup() {
  // Configurando os pinos do LED como saída
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);

  // Configurando os pinos do sensor como entrada/saída
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  // Iniciando a comunicação serial para depuração
  Serial.begin(9600);
}

void loop() {
  // Enviando o pulso para o sensor ultrassônico
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // Recebendo o tempo de resposta
  long duration = pulseIn(ECHO_PIN, HIGH);

  // Calculando a distância em cm
  float distance = duration * 0.034 / 2;

  // Exibindo a distância no monitor serial
  Serial.print("Distância: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Controlando os LEDs com base na distância
  if (distance < 5) {
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, HIGH);
    digitalWrite(LED3, HIGH);
  } else if (distance < 10) {
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, HIGH);
    digitalWrite(LED3, LOW);
  } else if (distance < 20) {
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);
  } else {
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);
  }

  // Pequena pausa para estabilizar o loop
  delay(100);
}
