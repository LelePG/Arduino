
/*
   Projeto simples de um robôzinho que anda para frente. O código em si é bem simples, com uma ângulação variante entre dois Servo motores.
   O complicado, é montar os dois motores, e mais ainda conseguir montar perninhas para o robôzinho de maneira que elas fiquem
   firmes, sem se desgastarem. Imagens podem ser vistas na pasta do projeto. A segunda versão conta com um botão de liga e desliga e um LED
   que indica se o robô está ou não ligado. O LED e a chave de liga/desliga são implementados em hardware. O software lida somente com a
   movimentação dos motores.
   
   Letícia Pegoraro Garcez 2021
*/

//IMPORTAÇÃO DE BIBLIOTECAS
#include <Servo.h>

//Pinos de definição dos motores
#define atras 8
#define frente 9

//Criação dos objertos Servo
Servo pataAtras;
Servo pataFrente;

void setup(){
  pinMode(atras, OUTPUT);
  pinMode(frente, OUTPUT);

  pataAtras.attach(atras);
  pataFrente.attach(frente);

  //Coloca os dois motores na posição de 90 graus, para o usuário poder arrumar as pazinhas dos servos na posição correta.
  pataAtras.write(90);
  pataFrente.write(90);

  delay(3000);//tempo pra arrumar os servos

}

//Variáveis
int angulo1 = 60; //ângulo de movimentação 1
int angulo2 = 105; //ângulo de movimentação 2
int espera1 = 100; 
int espera2 = 400; //tempo de espera entre cada passo

void loop() {
  pataFrente.write(angulo1-10);
  delay(espera1);
  pataAtras.write(angulo2);
  delay(espera2);
  
  pataFrente.write(angulo2+10);
  delay(espera1);
  pataAtras.write(angulo1);
  delay(espera2);

}
