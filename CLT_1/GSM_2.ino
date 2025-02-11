#define LED1 3 // Pino do LED 1
#define LED2 4 // Pino do LED 2
#define LED3 5 // Pino do LED 3

#define BOTAO1 6 // Pino do Botão 1
#define BOTAO2 7 // Pino do Botão 2

void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  
  pinMode(BOTAO1, INPUT);
  pinMode(BOTAO2, INPUT);
}

void loop() {
  // Leitura dos botões
  bool estadoBotao1 = digitalRead(BOTAO1);
  bool estadoBotao2 = digitalRead(BOTAO2);

  // Lógica para acender LEDs
  if (estadoBotao1 && !estadoBotao2) {
    digitalWrite(LED1, HIGH); // LED 1 acende
  } else {
    digitalWrite(LED1, LOW);
  }

  if (!estadoBotao1 && !estadoBotao2) {
    digitalWrite(LED2, HIGH); // LED 2 acende
  } else {
    digitalWrite(LED2, LOW);
  }

  if (!estadoBotao1 && estadoBotao2) {
    digitalWrite(LED3, HIGH); // LED 3 acende
  } else {
    digitalWrite(LED3, LOW);
  }
}
