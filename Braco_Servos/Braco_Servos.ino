/*
   Projeto básico de um braço mecânico com dois servos motores e um módulo de Joystick. Os motores são chamados de ombro e de cotovelo, e cada um
   é coordenado por um dos eixos do módulo de Joystick.
   Projeto ainda não finalizado. Melhorias: adicionar posições preé-definidas, e opção de ligar e desligar o sistema.


   Letícia Pegoraro Garcez 2021
*/
#include<Servo.h>
//eixos do joystick
#define eixoX A0
#define eixoY A1
#define btnJ 7
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
  //botões
  pinMode (btnJ, INPUT);
  //Inicialização dos servos
  cotovelo.attach(motorCotovelo);
  ombro.attach(motorOmbro);
  Serial.begin(9600);
}

int movimentoCotovelo, movimentoOmbro;
int funcionamento = true;// variável que vai dizer se o programa está ligado ou não

void loop() {
  movimentoCotovelo = map(analogRead(eixoX), 0, 1023, 0, 180);
  movimentoOmbro = map(analogRead(eixoY), 0, 1023, 0, 180);
  cotovelo.write(movimentoCotovelo);
  ombro.write(movimentoOmbro);
  delay(150);

}
