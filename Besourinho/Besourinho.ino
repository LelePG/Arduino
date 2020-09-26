
/*
   Projeto simples de um robôzinho que anda para frente. O código em si é bem simples, com uma ângulação variante entre dois Servo motores.
   O complicado, é montar os dois motores, e mais ainda conseguir montar perninhas para o robôzinho de maneira que elas fiquem
   firmes, sem se desgastarem. Imagens podem ser vistas na pasta do projeto.

   Letícia Pegoraro Garcez 2020
*/

//IMPORTAÇÃO DE BIBLIOTECAS
#include <Servo.h>


//LEDs para indicar o estado
#define atras 8
#define frente 9

Servo pata_de_tras;//cria um objeto Servo
Servo pata_da_frente;//cria um objeto Servo
void setup()
{
  pinMode(atras, OUTPUT);
  pinMode(frente, OUTPUT);

  pata_de_tras.attach(atras);
  pata_da_frente.attach(frente);

  //Coloca os dois motores na posição de 90 graus, e o ângulo aumenta e diminui a partir dessa posição
  pata_de_tras.write(90);
  pata_da_frente.write(90);

  delay(3000);//tempo pra arrumar os servos

}

//Variáveis
int move1 = 60;
int move2 = 105;
int espera = 600; //tempo de espera entre cada passo

void loop() {

  pata_da_frente.write(move1);
  pata_de_tras.write(move2);
  delay(espera);
  
  pata_da_frente.write(move2);
  pata_de_tras.write(move1);
  delay(espera);

}
