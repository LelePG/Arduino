/*
  Projeto de um abajur de toque utilizando um LED e um sensor de toque capacitivo. O código funciona com uma lógica similar à uma máquina
  de estados, tendo quatro estados: desligado, luzFraca, luzMedia e luzAlta. Quando o sensor é ativado, ocorre o incremento do estado, e
  uma escrita no LED. Este circuito também pode ser implementado com um botão.

  Letícia Pegoraro Garcez 2021

*/

#define sensor 8
#define led 9

void setup() {
  pinMode(sensor, INPUT);
  pinMode(led, OUTPUT);
  //Serial.begin(9600);
}

//estados
bool desligado = true;
bool luzFraca = false;
bool luzMedia = false;
bool luzAlta = false;
//variáveis
bool leituraSensor;
int tempo = 100;

void loop() {
  leituraSensor = digitalRead(8);
  if (leituraSensor) {
    delay(tempo);
    if (desligado) {
      desligado = false;
      luzFraca = true;
      analogWrite(led, 60);
    }
    else if (luzFraca) {
      luzFraca = false;
      luzMedia = true;
      analogWrite(led, 100);
    }
    else if (luzMedia) {
      luzMedia = false;
      luzAlta = true;
      analogWrite(led, 200);
    }
    else if (luzAlta) {
      luzAlta = false;
      desligado = true;
      analogWrite(led, 0);
    }
    delay(tempo);
  }
}
