#include <Servo.h>

// Classe base para componentes digitais (LED, Buzzer)
class ComponenteDigital {
  protected:
    int pino;
  public:
    ComponenteDigital(int p) {
      pino = p;
      pinMode(pino, OUTPUT);
    }
    void ligar() {
      digitalWrite(pino, HIGH);
    }
    void desligar() {
      digitalWrite(pino, LOW);
    }
};

// Classe para o LED
class LED : public ComponenteDigital {
  public:
    LED(int p) : ComponenteDigital(p) {}
};

// Classe para o Buzzer
class Buzzer : public ComponenteDigital {
  public:
    Buzzer(int p) : ComponenteDigital(p) {}
};

// Classe para o Servo Motor
class ServoMotor {
  private:
    Servo servo;
    int pino;
  public:
    ServoMotor(int p) {
      pino = p;
      servo.attach(pino);
    }
    void girar(int angulo) {
      servo.write(angulo);
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
};

// Classe para o Sensor LDR
class SensorLDR {
  private:
    int pino;
  public:
    SensorLDR(int p) {
      pino = p;
    }
    int lerLuminosidade() {
      return analogRead(pino);
    }
};

// Instanciando os componentes
LED led(9);
Buzzer buzzer(10);
ServoMotor servo(11);
SensorUltrassonico ultrassonico(7, 8); // Trigger no pino 7 e Echo no pino 8
SensorLDR ldr(A0);

void setup() {
  Serial.begin(9600);
  servo.girar(0); // Inicializa o servo na posição 0°
}

void loop() {
  // Lê a luminosidade do LDR
  int luminosidade = ldr.lerLuminosidade();
  Serial.print("Luminosidade: ");
  Serial.println(luminosidade);

  if (luminosidade < 50) {
    led.ligar();
  } else {
    led.desligar();
  }

  // Mede a distância do ultrassônico
  float distancia = ultrassonico.medirDistancia();
  Serial.print("Distância: ");
  Serial.println(distancia);

  if (distancia > 0 && distancia < 10) {
    buzzer.ligar();
    servo.girar(90);
    delay(2000); // Espera 2 segundos
    servo.girar(0);
    buzzer.desligar();
  }

  delay(500); // Atualiza o loop a cada 500ms
}