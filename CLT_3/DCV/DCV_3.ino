// Definição dos pinos da ponte H
#define IN1 5  
#define IN2 6  
#define ENA 9  // Controle de velocidade (PWM)

void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENA, OUTPUT);
}

void loop() {
  // Gira para um lado
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
    analogWrite(ENA, 200);
  delay(3000);

  // Para o motor
  analogWrite(ENA, 0);
  delay(1000);

  // Gira para o outro lado
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  analogWrite(ENA, 200);
  delay(3000);

  // Para o motor novamente
  analogWrite(ENA, 0);
  delay(1000);
}