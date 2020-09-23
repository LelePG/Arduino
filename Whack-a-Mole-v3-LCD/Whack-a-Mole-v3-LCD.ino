/*
   Terceira versão do jogo Whack-a-Mole, utilizando um botão, um sensor LDR, um módulo Joystick, e uma tela LCD.
   Na tela são exibidas as ações a serem tomadas:
   
   -Sentido de movimentação do módulo de joystick (X+,X-,Y+,Y-);
   -Apertar o botão;
   -Tapar o sensor LDR;

   A ação deve ser tomada segundo o tempo definido na variável MAX_ESPERA. A tela também exibe a contagem de erros e pontos, sendo necessários
   10 acertos para ganhar e 3 erros para perder. Após o fim do jogo, uma mensagem é exibida dizendo se você ganhou ou perdeu, e o jogo entra em standby
   esperando que o usuário aperte um botão para reiniciar. A verificação da ação do usuário ocorre com uma função, onde são comparadas as ações ao
   número das strings que ditam as ações dentro da matriz frases. Apesar de a tela LCD funcionar com apenas 16 caracteres, na declaração das strings,
   17 precisam ser levados em conta, já que o caracter de fim de frase é contabilizado como parte do tamanho da string.


   Letícia Pegoraro Garcez 2020
*/


#include<LiquidCrystal.h>

LiquidCrystal lcd (2, 3, 4, 5, 6, 7);//declaração do objeto lcd da classe LyquidCrystal

//PINOS
#define LDR A2
#define botao 8
#define eixoX A0
#define eixoY A1

//Tempo de espera para as respostas/ações
#define MAX_ESPERA 2000

//Funções
void pontuacao();
bool verificaAcao(int n);
void reinicia_jogo(void);


//Variáveis
int escolha, pontos, erros, tempo = MAX_ESPERA;
//Matrix com as ordens a serem dispostas pra cada possibilidade. Embora a tela seja de 16, a matriz precisa de 17 colunas pra aceitar o /0 do final de cada linha
char frases[6][17] = {{"Aperte o botao"}, {"Tape o LDR"}, {"X para mais"}, {"X para menos"}, {"Y para mais"}, {"Y para menos"}};

void setup() {
  //Inputs
  pinMode(LDR, INPUT);
  pinMode(botao, INPUT);
  pinMode(eixoX, INPUT);
  pinMode(eixoY, INPUT);

  //Definição do LCD
  lcd.begin(16, 2);
  lcd.clear();//tira todo "ruido" da tela
}


void loop() {
  randomSeed(millis());//Deixa a randomSeed no tempo atual de execução do jogo
  escolha = random(6);//Seleciona uma das ações a serem tomadas
  
  lcd.print(frases[escolha]);//Mostra essa ação na tela
  pontuacao();//Exibe a pontuação
  delay(tempo); //Tempo pra ação ser tomada
  
  if (verificaAcao(escolha)) { //Se a ação correspondente foi tomada, os pontos são atualizados.
    pontos++;
  }
  else { //Se não, atualiza os erros.
    erros++;
  }
  
  delay(700); //Tempo que o texto (pontos + ação) são tomados
  lcd.clear(); //limpa a tela

  tempo -= 50; //Atualiza o tempo de resposta
  
  if (pontos == 10) { //Se tem pontos suficientes pra ganhar
    lcd.print("Voce venceu!");
    pontuacao();//atualiza a pontuação
    reinicia_jogo();
  }
  else if (erros == 3) { //Se tem erros o suficiente pra perder
    lcd.print("Voce perdeu!");
    pontuacao();//atualiza a pontuação
    reinicia_jogo();
  }
}


void reinicia_jogo(void) {
  delay(1500);//Tempo pra pontuação e mensagem de ganhou/perdeu ficar exibida na tela
  lcd.clear();//limpa a tela
  
  lcd.print("Aperte o botao");//exibe mensagem de reiniciar
  lcd.setCursor(0, 1);
  lcd.print("para reiniciar");
  
  do {
    delay(10);
  } while (!digitalRead(botao));//enquanto o botão não é apertado, o jogo não segue porque fica parado nesse loop infinito

  //reseta as variáveis para o novo jogo
  tempo = MAX_ESPERA;
  pontos = 0;
  erros = 0;
  lcd.home();//coloca o cursor no lugar certo
  lcd.clear();//limpa a tela
  delay(2000);//tempo para reiniciar o jogo
}

bool verificaAcao(int n) {//Confere se a ação tomada corresponde à exibida na tela.
  if (n == 0 && digitalRead(botao)) {
    return true;
  }
  else if (n == 1 && analogRead(LDR) < 100) {
    return true;
  }
  else if (n == 2 && analogRead(eixoX) > 500) {//X+
    return true;
  }
  else if (n == 3 && analogRead(eixoX) < 400) {//X-
    return true;
  }
  else if (n == 4 && analogRead(eixoY) > 600) {//Y+
    return true;
  }
  else if (n == 5 && analogRead(eixoY) < 500) {//Y-
    return true;
  }
  else {//Se nenhum dos pares numero && ação estiver correto, retorna um erro
    return false;
  }
}

void pontuacao() {//exibe a pontuação
  lcd.setCursor(12, 1);//move o cursos pra essa posição
  lcd.print("P:");
  lcd.print(pontos);

  lcd.setCursor(8, 1);//move o cursor pra essa posição
  lcd.print("E:");
  lcd.print(erros);

  lcd.home();//retorna o cursor pro inicio da tela
}
