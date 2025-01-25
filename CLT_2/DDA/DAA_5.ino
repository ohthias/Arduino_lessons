#include <Servo.h>

// Classe para a Matriz de LEDs
class MatrizLED {
  private:
    int pinos[3][3]; // Matriz de pinos
  public:
    MatrizLED(int matriz[3][3]) {
      for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
          pinos[i][j] = matriz[i][j];
          pinMode(pinos[i][j], OUTPUT);
        }
      }
    }

    void piscarPadrao() {
      // Padrão: acende em diagonal
      for (int i = 0; i < 3; i++) {
        digitalWrite(pinos[i][i], HIGH);
        delay(200);
        digitalWrite(pinos[i][i], LOW);
      }
      // Todos acendem ao mesmo tempo
      for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
          digitalWrite(pinos[i][j], HIGH);
        }
      }
      delay(500);
      for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
          digitalWrite(pinos[i][j], LOW);
        }
      }
    }
};

// Classe para o Buzzer com Melodia
class BuzzerMelodia {
  private:
    int pino;
    int notas[4] = {262, 294, 330, 349}; // Frequências de Dó, Ré, Mi, Fá
  public:
    BuzzerMelodia(int p) {
      pino = p;
      pinMode(pino, OUTPUT);
    }

    void tocarMelodia() {
      for (int i = 0; i < 5; i++) { // Repetir 5 vezes
        for (int j = 0; j < 4; j++) { // Tocar cada nota
          tone(pino, notas[j], 300); // Toca a nota por 300ms
          delay(300);
          noTone(pino);
        }
      }
    }
};

// Classe para o Sensor Ultrassônico
class SensorUltrassonico {
  private:
    int trigger, echo;
  public:
    SensorUltrassonico(int trig, int ech) {
      trigger = trig;
      echo = ech;
      pinMode(trigger, OUTPUT);
      pinMode(echo, INPUT);
    }

    float medirDistancia() {
      digitalWrite(trigger, LOW);
      delayMicroseconds(2);
      digitalWrite(trigger, HIGH);
      delayMicroseconds(10);
      digitalWrite(trigger, LOW);
      long duracao = pulseIn(echo, HIGH);
      return duracao * 0.034 / 2; // Conversão para cm
    }

    void sonar() {
      float distancia = medirDistancia();
      Serial.print("Distância: ");
      Serial.print(distancia);
      Serial.println(" cm");
    }
};

// Componentes
int pinosMatriz[3][3] = {{2, 3, 4}, {5, 6, 7}, {8, 9, 10}};
MatrizLED matrizLED(pinosMatriz);
BuzzerMelodia buzzer(11);
SensorUltrassonico ultrassonico(12, 13);

void setup() {
  Serial.begin(9600);
}

void loop() {
  // Sonar do Ultrassônico
  ultrassonico.sonar();

  // Verifica distância e executa ações
  float distancia = ultrassonico.medirDistancia();
  if (distancia > 0 && distancia < 5) {
    matrizLED.piscarPadrao();
    buzzer.tocarMelodia();
  }

  delay(1000); // Atualiza a cada 1 segundo
}
