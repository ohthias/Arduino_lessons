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
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, 150); // Define velocidade média (0-255)
  
  delay(2000); // Motor ligado por 2 segundos

  analogWrite(ENA, 0); // Motor desligado
  delay(2000);
}