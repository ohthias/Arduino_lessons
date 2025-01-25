#include <Servo.h>

// Classe para o Sensor Ultrassônico
class SensorUltrassonico {
  private:
    int triggerPin, echoPin;

  public:
    // Construtor para inicializar os pinos
    SensorUltrassonico(int trig, int echo) {
      triggerPin = trig;
      echoPin = echo;
      pinMode(triggerPin, OUTPUT);
      pinMode(echoPin, INPUT);
    }

    // Método para medir a distância
    float medirDistancia() {
      digitalWrite(triggerPin, LOW);
      delayMicroseconds(2);
      digitalWrite(triggerPin, HIGH);
      delayMicroseconds(10);
      digitalWrite(triggerPin, LOW);

      long duracao = pulseIn(echoPin, HIGH);
      float distancia = duracao * 0.034 / 2; // Conversão para cm
      return distancia;
    }
};

// Configuração dos componentes
SensorUltrassonico ultrassonico(9, 10); // Trigger no pino 9, Echo no pino 10
Servo servo; // Cria o objeto do Servo
int servoPin = 6;

void setup() {
  Serial.begin(9600);
  servo.attach(servoPin); // Conecta o servo ao pino 6
  servo.write(0);         // Inicia o servo na posição 0
}

void loop() {
  float distancia = ultrassonico.medirDistancia(); // Mede a distância
  Serial.print("Distância: ");
  Serial.print(distancia);
  Serial.println(" cm");

  // Converte a distância (0-50 cm) para ângulos do servo (0-180 graus)
  int angulo = map(distancia, 0, 50, 0, 180);
  angulo = constrain(angulo, 0, 180); // Garante que o valor fique entre 0 e 180

  // Move o servo para o ângulo correspondente
  servo.write(angulo);

  delay(100); // Pequeno atraso para suavizar o movimento
}
