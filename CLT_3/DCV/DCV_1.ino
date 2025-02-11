// Definição dos pinos
#define IN1 7
#define IN2 8
#define ENA 5  // Pino PWM

void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENA, OUTPUT);
}

void loop() {
  // Motor gira para frente
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, 150); // Velocidade média (0 a 255)
  delay(3000); // Mantém por 3 segundos

  // Para o motor
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  delay(1000);

  // Motor gira para trás
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  analogWrite(ENA, 150); // Velocidade média
  delay(3000);

  // Para o motor novamente
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  delay(1000);
}