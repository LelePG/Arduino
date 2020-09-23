/*
   Segunda versão do jogo Whack-a-Mole, utilizando um LED RGB e um controle de módulo Joystick. São 5 cores de ordem, segundo o disposto abaixo:

   Vermelho - Movimentação em X-
   Azul - Movimentação em X+
   Verde - Movimentação em Y-
   Lilás - Movimentação em Y+
   Amarelo - Aperto do botão

   Após a luz acender, a ação deve ser tomada em um intervalo de tempo para a contabilização de pontos. Com três erros, o jogo é perdido, e ganho com 10. Estes valores podem
   ser vistos no monitor Serial ao final do jogo. O tempo para performar a ação é o tempo que o LED fica aceso,e pode ser definido na variável tempo.


   Letícia Pegoraro Garcez 2020
*/

//DEFINIÇÕES
#define ledR A0
#define ledG A1
#define ledB A2

#define eixoX A3
#define eixoY A4
#define botao 7

#define buzzer 8

int cor[5][3] = {{0, 0, 255}, {255, 0, 0}, {25, 200, 56}, {50, 150, 200}, {0, 0, 0} } ; //Cores que o LED pode assumir
int escolha, erros, pontos;
int tempo = 1500; //Tempo em que o LED fica ligado

//CABEÇALHOS DE FUNÇÕES
void setColorLed(int cor[3]);
void play_acerto(void);
void play_erro(void);

void setup() {
  pinMode(ledR, OUTPUT);
  pinMode(ledG, OUTPUT);
  pinMode(ledB, OUTPUT);
  pinMode(buzzer, OUTPUT);

  pinMode(eixoX, INPUT);
  pinMode(eixoY, INPUT);
  pinMode(botao, INPUT);
  Serial.begin(9600);
}

void loop() {
 
  randomSeed(millis());
  escolha = random(4);//Seleciona uma das cores
  setColorLed(cor[escolha]);//aplica essa cor
  delay(tempo);//deixa o LED aceso
  verificaAcao(escolha);//Verifica se a ação correspondente à cor do LED aconteceu, se sim, marca um ponto, senão, marca um erro.
  setColorLed(cor[4]);//desliga o LED
  delay(300);

  if (pontos >= 10) { //Se o jogo é ganhado
    Serial.println("Você venceu!");
    pontos = 0;
    erros = 0;
  }
  else if (erros >= 3) { //Se o jogo foi perdido.
    Serial.println("Você perdeu!");
    pontos = 0;
    erros = 0;
    delay(1500);
  }
  delay(900);
}




//FUNÇÕES
void setColorLed(int cor[3]) {
  analogWrite(ledR, cor[0]);
  analogWrite(ledG, cor[1]);
  analogWrite(ledB, cor[2]);
}

void verificaAcao(int n) {
  if (n == 0 && analogRead(eixoX) < 400) {
    play_acerto();
  }
  else if (n == 1 && analogRead(eixoX) > 500) {
    play_acerto();
  }
  else if (n == 2 && analogRead(eixoY) < 500) {
    play_acerto();
  }
  else if (n == 3 && analogRead(eixoY) > 700) {
    play_acerto();
  }
  else {
    play_erro();
  }
}

void play_acerto(void) {
  tone(buzzer, 1500);
  delay(600);
  noTone(buzzer);
  pontos++;
}

void play_erro(void) {
  tone(buzzer, 1750);
  delay(600);
  noTone(buzzer);
  erros++;
}
