/*
   Projeto de uma tranca inteligente que abre e fecha com a aproximação de um cartão RFID e um servo motor. O projeto também implementa
   um LED para mortrar quando a tranca está aberta e um soundbuzzer para indicar se um cartão errado foi aproximado do sensor.

   Letícia Pegoraro Garcez 2021
*/

#include<MFRC522.h>
#include<SPI.h>
#include <Servo.h>

#define motor 7
#define led 6
#define buzzer 5

MFRC522 leitor (10, 9);
Servo tranca;

void setup() {
  tranca.attach(motor);
  tranca.write(0);
  SPI.begin();
  leitor.PCD_Init();
  pinMode(led, OUTPUT);
  //inicialização dos atuadores
  noTone(buzzer);
  digitalWrite(led, LOW);
  Serial.begin(9600);//debug

}

bool aberto = false;

void loop() {

  while (!leitor.PICC_IsNewCardPresent()) {
    delay(20);
  }

  if (cartaoCorreto() && aberto) {
    aberto = false;
    tranca.write(0);
    digitalWrite(led, LOW);
  }
  else if (cartaoCorreto() && !aberto) {
    aberto = true;
    tranca.write(90);
    digitalWrite(led, HIGH);
  }
  else {
    tone(buzzer, 1800);
    delay(600);
    noTone(buzzer);
   // Serial.println("A");
  }
  delay(400);

}

bool cartaoCorreto() {
  String codigoCorreto = "C63C332B";//Alterar esta variável para o uid do cartão
  String codigoCartao = "";

  leitor.PICC_ReadCardSerial();

  for (int c = 0; c < leitor.uid.size; c++) {
    codigoCartao.concat(String(leitor.uid.uidByte[c], HEX));
  }

  codigoCartao.toUpperCase();
  //Serial.println(codigoCartao);

  if (codigoCartao == codigoCorreto) {
    return true;
  }

  return false;
}
