/*
 * Projeto simples para entender a leitura de tags RFID utilizando o sensor de RFID. Possui duas funções, uma para imprimir no monitor serial
 * a udi do cartão, e uma função para ver se a tag é igual a um valor pré-definido.
 * 
 * Letícia Pegoraro Garcez 2021
 */
#include <SPI.h>
#include <MFRC522.h>

MFRC522 leitor(10, 9); //Declaração de um objeto MFRC522

void imprimeSerial(void);
bool verificaIgualdade(String codigoAcesso);

void setup() {
  SPI.begin();
  leitor.PCD_Init();
  Serial.begin(9600);
}

void loop() {
  if (leitor.PICC_IsNewCardPresent()) { //Se eu tenho um cartão no leitor
    //imprimeSerial();
    if(verificaIgualdade("C63C332B")){
      Serial.println("Acesso concedido");
    }else{
      Serial.println("Acesso negado");
    }
    delay(500);
  }

}

void imprimeSerial(void) {
  leitor.PICC_ReadCardSerial();//leia o serial do cartão
  Serial.print("O UID do cartão é: ");
  for (int c = 0; c < leitor.uid.size; c++) {//O uid, identificação do cartão é armazenado em um vetor dentro do objeto MFRC522.
    Serial.print(leitor.uid.uidByte[c], HEX);//Aqui cada byte da udi do cartão é exibido no formato Hexadecimal
  }
  Serial.println();
}

bool verificaIgualdade(String codigoAcesso){
    leitor.PICC_ReadCardSerial();//leia o serial do cartão
    String codigoCartao = "";
     for (int c = 0; c < leitor.uid.size; c++) {//O uid, identificação do cartão é armazenado em um vetor dentro do objeto MFRC522.
    codigoCartao.concat(String(leitor.uid.uidByte[c], HEX));//Aqui cada byte da udi do cartão é exibido no formato Hexadecimal
  }
 // Serial.println(codigo);
 codigoCartao.toUpperCase();
 if(codigoAcesso == codigoCartao){
  return true;
 }
  return false;
}
