// Definir os pinos dos LEDs
int led1 = 2;
int led2 = 3;
int led3 = 4;
int botao = 5;  // Pino do botão
int modo = 0;   // Modo inicial (sequencial)

// Variável para ler o estado do botão
int estadoBotao = 0;
int ultimoEstadoBotao = 0;  // Para detectar transições do botão

void setup() {
  // Inicializar os pinos dos LEDs e botão como saída/entrada
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(botao, INPUT);

  Serial.begin(9600);  // Para mostrar o modo no monitor serial
}

void loop() {
  // Ler o estado atual do botão
  estadoBotao = digitalRead(botao);

  // Detectar transição do botão (pressionamento)
  if (estadoBotao == HIGH && ultimoEstadoBotao == LOW) {
    modo = (modo + 1) % 2;  // Alternar entre os modos
    Serial.println(modo == 0 ? "Modo Sequencial" : "Modo Aleatório");
    delay(200);  // Debounce (prevenir leituras múltiplas)
  }
  ultimoEstadoBotao = estadoBotao;

  if (modo == 0) {
    // Modo Sequencial: LEDs piscam em sequência
    acenderLEDSequencial();
  } else {
    // Modo Aleatório: LEDs piscam aleatoriamente
 acenderLEDRandomico();
 }
}

// Função para acender LEDs em sequência (já feita antes)
void acenderLEDSequencial() {
 for (int i = 1; i <= 3; i++) {
 if (i == 1) {
 digitalWrite(led1, HIGH);
 digitalWrite(led2, LOW);
 digitalWrite(led3, LOW);
 } else if (i == 2) {
 digitalWrite(led1, LOW);
 digitalWrite(led2, HIGH);
 digitalWrite(led3, LOW);
 } else if (i == 3) {
 digitalWrite(led1, LOW);
 digitalWrite(led2, LOW);
 digitalWrite(led3, HIGH);
 }
 delay(1000); // Pausa de 1 segundo
 }
}

// Função para acender LEDs aleatoriamente
void acenderLEDRandomico() {
 int ledAleatorio = random(2, 5); // Seleciona um LED aleatório (2, 3 ou 4)

 digitalWrite(led1, ledAleatorio == 2 ? HIGH : LOW);
 digitalWrite(led2, ledAleatorio == 3 ? HIGH : LOW);
 digitalWrite(led3, ledAleatorio == 4 ? HIGH : LOW);

 delay(500); // Pausa de 0.5 segundo entre as mudanças
}