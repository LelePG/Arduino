/*
 * Rotaciona uma Servo Motor de acordo com o botão apertado. Um deles rotaciona para a esquerda, o outro, para a direita.
 * Pra fazer o servo se mecher, é preciso alterar a angulação, lembrando que há um limite para o que o hardware consegue fazer, portanto é importante adicionar os delays. A ângulação máxima é 180º.
 * Existem funções para a calcular o valor do angulo a ser escrito de acordo com o botão apertado, e funções para agarantir que o angulo de encontra no intervalo de [0,180].
 * Comunicação Serial pode ser habilitada para debug.
 * 
 * Letícia Pegoraro Garcez 2020
*/


#include<Servo.h>

//DEFINIÇÃO DOS PINOS
#define motor 8 //O pino o motor é conectado.
#define P_esq  6 //botão para girar para a esquerds
#define P_dir 5 //botão para girar para a direita

//DEFINIÇÃO DO OBJETO SERVO
Servo s; //Criar um objeto do tipo Servo, ou seja, o motor

//VARIAVEL GLOBAL PRA GUARDA O ÂNGULO
int angulo = 0; //ângulo atual do servo

//CABEÇALHOS DAS FUNÇÕES
int moveServo(int angulo, int esq, int dir , int modifica); //Avalia pra que lado o motor deve se mover e retorna o valor do ângulo. A quantidade de unidades de movimento é passada como parâmetro 'modifica'
bool anguloValido(int angulo); //Verifica se o ângulo está dentro dos valores validos
int corrigeAngulo(int angulo); //Corrige o ângulo caso ele esteja fora do escopo

void setup() {
  s.attach(motor); //conecto o pino do motor ao objeto Servo, então o que vai comandar meu servo é o pino motor.
  s.write(0);//Escreve a posição em ângulos, zero para dar início
  pinMode(P_esq, INPUT);
  pinMode(P_dir, INPUT);
  //Serial.begin(9600);//pra debug

}
void loop() {
  angulo = moveServo(angulo, digitalRead(P_esq), digitalRead(P_dir), 2); //altera o ângulo
  if (anguloValido(angulo)) {
    s.write(angulo);//gira
    delay(25);//delay 
  }
  else {
    angulo = corrigeAngulo(angulo);
  }
  //Serial.println(angulo);//debug

}


//FUNÇÕES
int moveServo(int angulo, int esq, int dir , int modifica) {
  if (dir) {
    angulo += modifica;
  }
  else if (esq) {
    angulo -= modifica;
  }
  return angulo;
}

int corrigeAngulo(int angulo) {
  if (angulo < 0) {
    return 0; //Como corrige ângulo sempre vai ser direcionada ao próprio ângulo, esse valor já vai ser atribuido a varivável
  }
  if (angulo > 180) {
    return 180;
  }
}

bool anguloValido(int angulo) {
  if (angulo >= 0 && angulo <= 180) {
    return true;
  }
  return false;
}
