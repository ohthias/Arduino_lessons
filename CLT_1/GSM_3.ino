// Definição de Pinos
const int trigPin = 9;
const int echoPin = 8;
const int ledRed = 3;
const int ledYellow = 4;
const int ledGreen = 5;
const int button1 = 6;
const int button2 = 7;

// Variáveis
long duration;
int distance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledRed, OUTPUT);
  pinMode(ledYellow, OUTPUT);
  pinMode(ledGreen, OUTPUT);
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  
  Serial.begin(9600);
}

void loop() {
  // Leitura dos botões
  bool isButton1Pressed = digitalRead(button1);
  bool isButton2Pressed = digitalRead(button2);

  // Modo 1: Medição do Sensor Ultrassônico
  if (isButton1Pressed) {
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    duration = pulseIn(echoPin, HIGH);
    distance = duration * 0.034 / 2;

    if (distance < 10) {
      digitalWrite(ledRed, HIGH);
      digitalWrite(ledYellow, LOW);
      digitalWrite(ledGreen, LOW);
    } else if (distance < 20) {
      digitalWrite(ledRed, LOW);
      digitalWrite(ledYellow, HIGH);
      digitalWrite(ledGreen, LOW);
    } else {
      digitalWrite(ledRed, LOW);
      digitalWrite(ledYellow, LOW);
      digitalWrite(ledGreen, HIGH);
    }
  }
  // Modo 2: LED Vermelho Piscando
  else if (isButton2Pressed) {
    digitalWrite(ledRed, HIGH);
    digitalWrite(ledYellow, LOW);
    digitalWrite(ledGreen, LOW);
    delay(500);
    digitalWrite(ledRed, LOW);
    delay(500);
  }
  // Modo 3: Todos os LEDs apagados
  else {
    digitalWrite(ledRed, LOW);
    digitalWrite(ledYellow, LOW);
    digitalWrite(ledGreen, LOW);
  }
}
