/*
   Projeto simples com leitor RFID e LED RBG de cátodo comum. É necessário várias tags de RFID, e de acordo com a tag aproximada
   do leitor, uma cor é setada no LED RGB. O código verifica se um cartão foi aproximado, se sim, ele verifica qual dos cartões
   foi adicionado, e ativa a cor correspondente ao cartão.

   Letícia Pegoraro Garcez 2021
*/

#include <MFRC522.h>
#include <SPI.h>

#define red 7
#define green 6
#define blue 5

MFRC522 leitor (10, 9);


void setup() {
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
  SPI.begin();
  leitor.PCD_Init();
  Serial.begin(9600);

}

void loop() {
  if (leitor.PICC_IsNewCardPresent()) {
    switch (descobrirCartao()) {
      case 1:
        setColorCatodoComum(255, 140, 0);
        break;
      case 2:
        setColorCatodoComum(0, 191, 255);
        break;
      case 3:
        setColorCatodoComum(0, 250, 154);
        break;
      case 4:
        setColorCatodoComum(0, 100, 0);
        break;
      case 5:
        setColorCatodoComum(220, 20, 60);
        break;
      default:
        setColorCatodoComum(0, 0, 0);
        break;
    }
   // delay(500);
  }
}


void setColorCatodoComum(int redQ, int greenQ, int blueQ) {
  analogWrite(red, redQ);
  analogWrite(green, greenQ);
  analogWrite(blue, blueQ);
}

int descobrirCartao() {
  leitor.PICC_ReadCardSerial();
  String cartaoColocado = "";
  for (int c = 0; c < leitor.uid.size; c++) {
    cartaoColocado.concat(String(leitor.uid.uidByte[c], HEX));
  }
  cartaoColocado.toUpperCase();
  Serial.println(cartaoColocado);
  if (cartaoColocado == "C63C332B") {
    return 1;
  }
  else if (cartaoColocado == "59EA6DC2") {
    return 2;
  }
  else if (cartaoColocado == "415919A2E591F") {
    return 3;
  }
  else if (cartaoColocado == "C6B35B6F"){
    return 4;
  }
  else if(cartaoColocado == "FC7BDA22"){
    return 5;
  }
  else{
    return 0;
  }
}
