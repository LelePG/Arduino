/*
    Termômetro usando um termistor ntc e um display de 7 segmentos de 4 digitos (anodo comum). Foi usada uma biblioteca para controlar o thermistor (Thermistor.h) e outra para
    controlar o display de 7 segmentos (SevSeg.h , https://github.com/DeanIsMe/SevSeg para mais informações sobre a biblioteca). O display de 4 digitos pode ser re-configurado
    para simular dois displays de 2 digitos, ou 4 displays de 1 digito, alterando valores nas variáveis de controle do objeto.
    Optei pelo uso da função millis() ai invés de delay().
    O intervalo de atualização da temperatura é 1s.

   Letícia Pegoraro Garcez 2019

*/

#include <SevSeg.h>
#include <Thermistor.h>
//VALOR DO INTERVALO COM QUE VOU VERIFICAR O TERMISTOR
#define INTERVALO 1000//1 segundos
//VARIÁVEIS
Thermistor sensorTemperatura(A0);//o objeto thermistor é criado passando o pino referente ao thermistor
SevSeg display4dig; //Declarando o objeto que vai controlar o display
unsigned long millisInicio, millisAtual;
float leituraTemperatura;

void setup() {
  //CONFIGURAÇÕES DO DISPLAY
  byte numDigits = 4; //quantidade de digitos dos display
  byte digitPins[] = {2, 3, 4, 5};//pinos onde estão conectados D1,D2,D3 e D4, respectivamente
  byte segmentPins[] = {7, 8, 9, 10, 11, 12, 13, 6}; //É um vetor de 8 posições. As 7 primeiras correspondem aos pinos A,B,C,D,E e F e a oitava posição (opcional) corresponde ao ponto decimal.
  display4dig.begin(COMMON_ANODE, numDigits, digitPins, segmentPins);//Método que inicia o objeto com as configurações setadas acima.

  //VARIÁVEIS
  Serial.begin(9600);
  millisInicio = 0;
}

void loop() {
  millisAtual = millis();
  if (millisAtual - millisInicio >= INTERVALO) { //Se já tiver decorrido o tempo do intervalo
    leituraTemperatura = sensorTemperatura.getTemp();
    Serial.print(leituraTemperatura);
    Serial.println("ºC");
    display4dig.setNumber(leituraTemperatura, 1); //O segundo parâmetro é em qual posição do ponto decimal
    millisInicio = millisAtual;//Altera o valor que será verificado na condição do if
  }
  display4dig.refreshDisplay();//Atualiza o display
}
