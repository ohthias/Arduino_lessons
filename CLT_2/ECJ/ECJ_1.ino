// Definição da Classe LED
class LED {
  private:
    int pino;         // Pino do LED
    int estado;       // Estado do LED (0: Desligado, 1: Ligado, 2: Piscando)
    unsigned long intervalo; // Intervalo de piscar em milissegundos
    unsigned long ultimaTroca; // Armazena o tempo da última troca

  public:
    // Construtor
    LED(int pinoLED) {
      pino = pinoLED;
      estado = 0; // Começa desligado
      intervalo = 500; // Intervalo padrão de 500ms para piscar
      ultimaTroca = 0;
      pinMode(pino, OUTPUT); // Configura o pino como saída
      digitalWrite(pino, LOW); // Garante que começa desligado
    }

    // Método para ligar o LED
    void ligar() {
      estado = 1;
      digitalWrite(pino, HIGH);
    }

    // Método para desligar o LED
    void desligar() {
      estado = 0;
      digitalWrite(pino, LOW);
    }

    // Método para ativar o modo de piscar
    void piscar(unsigned long novoIntervalo) {
      estado = 2;
      intervalo = novoIntervalo; // Define o novo intervalo de piscar
    }

    // Atualiza o estado do LED (deve ser chamado no loop)
    void atualizar() {
      if (estado == 2) { // Apenas se estiver no modo piscando
        unsigned long tempoAtual = millis();
        if (tempoAtual - ultimaTroca >= intervalo) {
          ultimaTroca = tempoAtual;
          // Alterna entre HIGH e LOW
          digitalWrite(pino, !digitalRead(pino));
        }
      }
    }
};

LED meuLED(9); // Instância da classe LED no pino 9

void setup() {
  Serial.begin(9600);
}

void loop() {
  // Exemplo de uso dos métodos
  meuLED.ligar();      // Liga o LED por 2 segundos
  delay(2000);
  meuLED.desligar();   // Desliga o LED por 1 segundo
  delay(1000);
  meuLED.piscar(300);  // Coloca o LED no modo piscando com 300ms de intervalo

  // Atualiza o estado do LED
  for (int i = 0; i < 10; i++) { // Pisca 10 vezes
    meuLED.atualizar();
    delay(50);
  }

  meuLED.desligar();   // Desliga o LED
  delay(2000);
}
