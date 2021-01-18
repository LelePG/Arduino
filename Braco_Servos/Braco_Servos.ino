/*
   Projeto básico de um braço mecânico com dois servos motores e um módulo de Joystick. Os motores são chamados de ombro e de cotovelo, e cada um
   é coordenado por um dos eixos do módulo de Joystick. Para ativar o sistema, é preciso organizar um sensor LDR, com um LED ativado em cima deste
   sensor, de modo que sua leitura seja sempre 1. Quando este sensor for coberto, o controle do joystick é e as posições pré definicas são
   habilitadas. Por enquanto, este é o maior ponto que pode dar erro. O braço tem suas posições pré-definidas, que são ativadas através de botões.
  
   Letícia Pegoraro Garcez 2021
*/
#include<Servo.h>

//eixos do joystick
#define eixoX A0
#define eixoY A1
//sensor
#define ldr 6
#define led 5
//botoes
#define btn1 4
#define btn2 3
//motores
#define motorCotovelo 8
#define motorOmbro 9
//Objetos servos
Servo cotovelo;
Servo ombro;

void setup() {
  //eixos
  pinMode (eixoX, INPUT);
  pinMode (eixoY, INPUT);
  //liga
  pinMode (ldr, INPUT);
  pinMode(led, OUTPUT);
  digitalWrite(led, HIGH);
  //botoes
  pinMode(btn1, INPUT);
  pinMode(btn2, INPUT);
  //Inicialização dos servos
  cotovelo.attach(motorCotovelo);
  ombro.attach(motorOmbro);
  Serial.begin(9600);
}

int movimentoCotovelo, movimentoOmbro;

void loop() {
 // Serial.println(digitalRead(ldr));

  if (!digitalRead(ldr)) {
    if (digitalRead(btn1)) {
      cotovelo.write(155);
      delay(1000);
    }
    else if (digitalRead(btn2)) {
      cotovelo.write(50);
      ombro.write(180);
      delay(1000);
    }
    else {
      movimentoCotovelo = map(analogRead(eixoX), 0, 1023, 0, 180);//Faz o map do potenciômetro para os 180 graus do servo
      movimentoOmbro = map(analogRead(eixoY), 0, 1023, 0, 180);
      cotovelo.write(movimentoCotovelo);
      ombro.write(movimentoOmbro);
      delay(300);
    }
  }

}
