/* Solução do desafio 2 da Isa, do livro "Sai do LEGO, e não sei para onde vou: Base Programação"*/

#include <LiquidCrystal.h>

// Pinos do LCD conectados ao Arduino
const int rs = 3, en = 4, d4 = A2, d5 = A3, d6 = A4, d7 = A5;

// Inicializando o objeto LCD
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  // Configurando o número de colunas e linhas do LCD
  lcd.begin(16, 2);

  // Escrevendo uma mensagem inicial
  lcd.setCursor(0, 0);  // Define o cursor na primeira linha, primeira coluna
  lcd.print("Bem-vindo!"); // Mensagem estática
}

void loop() {
  // Contador dinâmico
  static int contador = 0;

  // Define o cursor na segunda linha
  lcd.setCursor(0, 1);
  
  // Apaga qualquer texto anterior para evitar sobreposição
  lcd.print("                "); // Espaços para limpar a linha
  
  // Mostra o valor atualizado do contador
  lcd.setCursor(0, 1); // Move o cursor de volta para o início da linha
  lcd.print("Contagem: ");
  lcd.print(contador);
  
  // Incrementa o contador
  contador++;
  
  // Aguarda 1 segundo
  delay(1000);
}
