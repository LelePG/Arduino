/*
   Sistema de monitoramento de distância utilizando um sensor ultrassônico hc-sr04 , leds para indicar o nível de aproximação e um soundbuzzer.
   Para o controle do sensor é utilizada a biblioteca Ultrassonic.h https://github.com/evsystems/ultrasonic/blob/master/Ultrasonic.h para declarar o objeto ultrassonic SENSOR e apartir dele obter as informações
   necessárias para o algoritmo. Para obter a distância, é preciso primeiro obter o tempo que o sinal enviado pelo trigger leva até o objeto e de volta, e após isso, converter esse valor usando o método
   convert do objeto ultrassonic.
   Comunicação Serial pode ser habilitada para debug.

   Letícia Pegoraro Garcez 2020
*/
#include <Ultrasonic.h> //Inclui a biblioteca Ultrasonic.h

//DEFINIÇÕES DE VARIVÁVEIS
#define trigg  7 // Definição do pino digital 5 para o sinal de trigger
#define echo 8 // Definição do pino digital 6 para o sinal echo
#define ledVermelho 9
#define ledAmarelo 10
#define ledVerde 11
#define buzzer 2

//DEFINIÇÃO DO OBJETO ULTRASSONIC
Ultrasonic sensor(trigg, echo); //Inicializa o sensor nos pinos definidos

//CABEÇALHOS DE FUNÇÕES
void estadoVermelho(void);
void estadoAmarelo(void);
void estadoVerde(void);

void setup()
{
  pinMode(ledVermelho, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
  pinMode(ledVerde, OUTPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600); //debug
}

//VARIÁVEIS
long tempoMicro;//Varivável para guardar o tempo que leva para o sinal ir do trigger, bater no obstáculo e voltar, é dado em microssegundos.
float distancia;//Variável que vai guardar a distância até o corpo

void loop()
{
  tempoMicro = sensor.timing(); //o tempo é igual a leitura do tempo que o sinal enviado leva para retornar
  distancia = sensor.convert(tempoMicro, Ultrasonic :: CM); // O objeto ultrassonic faz a conversão do tempo do sinal para a distância, no caso, cm.
  Serial.println(distancia); //debug
  if (distancia >= 200) { //se não há nada em 200 unidades, sinal ok
    estadoVerde();
  }
  else if (distancia > 50) { //se há alguma coisa num raio de 200 unidades a 50 unidades, sinal de alterta
    estadoAmarelo();
  }
  else if (distancia <= 50) { //se há alguma coisa em um raio menor ou igual a 50 unidades, sinal de perigo
    estadoVermelho();
  }
  delay(500);
}

//FUNÇÕES
void estadoVerde(void) {
  digitalWrite(ledVerde, HIGH); //acende o led verde
  //e desliga todo o resto que não vai ser usado
  digitalWrite(ledVermelho, LOW);
  digitalWrite(ledAmarelo, LOW);
  noTone(buzzer);
}

void estadoAmarelo(void) {
  digitalWrite(ledAmarelo, HIGH); //acende o led amarelo
  //e desliga todo o resto que não vai ser usado
  digitalWrite(ledVermelho, LOW);
  digitalWrite(ledVerde, LOW);
  noTone(buzzer);
}

void estadoVermelho(void) {
  digitalWrite(ledVermelho, HIGH); //acende o led vermelho
  tone(buzzer, 100);//toca o soundbuzzer com frequência 100
  //e desliga todo o resto que não vai ser usado
  digitalWrite(ledAmarelo, LOW);
  digitalWrite(ledVerde, LOW);

}
