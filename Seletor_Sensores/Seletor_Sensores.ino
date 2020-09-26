/*
   Seletor de sensores
   Inicialmente 4 sensores são ligados no programa, um sensor LDR, um thermistor, um sensor de fogo e um sensor de chama (ambos conectados apenas com o pino digital).
   A dinâmica deste projeto se baseia em selecionar quais sensores devem ser mostrados na tela LCD que funciona como saída de dados. Para fazer essa escolha, são usados dois botões,
   representando SIM e NÂO. Pressionar os dois ao mesmo tempo, abre o menu de seleção dos sensores.

   Após o upload do algoritmo, o menu deve ser aberto pressionando os botões SIM e NÂO até a mensagem "INICIANDO" aparecer na tela. Uma vez que esta mensagem apareça, os botões devem 
   ser soltos, e pressionados de acordo com a resposta de exibição ao sensor mostrado na tela LCD. Depois de selecionados, as leituras dos sensores serão exibidas continuamente,
   e podem ser redefinidas entrando novamente no menu e escolhendo os sensores para mostrar novamente.

   obs: Com a atual programação, ficam livres 4 portas analógicas e 4 portas digitais.

   Letícia Pegoraro Garcez 2020
*/


#include<LiquidCrystal.h>
#include<Thermistor.h>

LiquidCrystal lcd (8, 9, 10, 11, 12, 13); //declaração do objeto lcd da classe LyquidCrystal

//PINOS DOS SENSORES
#define LDR A0
#define botaoSim 6
#define botaoNao 7
#define fogo 5
#define chuva 4

Thermistor ther(A1);//declaração do thermistor associado ao pino A1

//Variáveis de controle de display
bool mostraLDR, mostraTher, mostraFogo, mostraChuva;

//Cabeçalhos das funções
void menu (void);
bool esperaResposta(void);
void limpaTela(void);
void mostraDetalhes(void);


void setup() {
  //Inputs
  pinMode(LDR, INPUT);
  pinMode(botaoSim, INPUT);
  pinMode(botaoNao, INPUT);
  pinMode(fogo, INPUT);
  pinMode(chuva, INPUT);

  //Definição do LCD
  lcd.begin(16, 2);
  lcd.clear();//tira todo "ruido" da tela
  lcd.print("ABRA O MENU");

  while (!digitalRead(botaoSim) ||  !digitalRead(botaoNao)) {//espera até o comando pro menu
    delay(10);
  }
  lcd.clear();
  menu(); //executa o menu
}

void loop() {
  while (!digitalRead(botaoSim) && !digitalRead(botaoNao)) {//quando os dois botões são abertados, sai desse loop e exibe o menu
    mostraDetalhes();//exibe os detalhes dos sensores
  }
  menu();
}



void menu (void) {//Esses delays são necessários pra "limpar" o retorno da função esperaResposta e ela poder restartar
  lcd.print("INICIANDO");
  delay(1000);
  limpaTela();
  //LDR
  lcd.print("Quer mostrar o");
  lcd.setCursor(0, 1);
  lcd.print("LDR?");
  mostraLDR = esperaResposta();
  limpaTela();
  //Thermistor
  lcd.print("Quer mostrar a");
  lcd.setCursor(0, 1);
  lcd.print("temperatura?");
  mostraTher = esperaResposta();
  limpaTela();
  //Sensor de chama
  lcd.print("Quer mostrar o");
  lcd.setCursor(0, 1);
  lcd.print("fogo?");
  mostraFogo = esperaResposta();
  limpaTela();
  //sensor de chuva
  lcd.print("Quer mostrar a");
  lcd.setCursor(0, 1);
  lcd.print("chuva?");
  mostraChuva = esperaResposta();
  limpaTela();
  //finalização
  lcd.print("Contabilizando....");
  limpaTela();
}

bool esperaResposta(void) {
  while (true) {//caso eu não aperte nenhum botão, o loop segue
    if (digitalRead(botaoSim)) {//se eu apertar o botão correspondente ao sim, sai da função
      lcd.print(" SIM");
      delay(300);
      return true;
    }
    if (digitalRead(botaoNao)) {//se eu apertar o botão correspontende ao não, sai da função
      lcd.print(" NAO");
      delay(300);
      return false;
    }
    delay(10);//se nenhum botão foi apertado, segue.
  }
}

void limpaTela(void) {
  delay(300);
  lcd.clear();
  lcd.home();
}
void mostraDetalhes(void) {
  int tempoEntreInfos = 450;//preciso levar em conta o tempo que existe na função que limpa a tela, então o tempo que devo inserir aqui é t-300;
  if (mostraLDR) {
    lcd.print("LUMINOSIDADE - ");//ok
    lcd.setCursor(0, 1);
    lcd.print(analogRead(LDR));
    delay(tempoEntreInfos);
    limpaTela();
  }
  if (mostraTher) {
    lcd.print("TEMPERATURA - ");//ok OBS: O resistor conectado no thermistor tem que ser de 10k.
    lcd.setCursor(0, 1);
    lcd.print(ther.getTemp());
    delay(tempoEntreInfos);
    limpaTela();
  }
  if (mostraFogo) {
    if (digitalRead(fogo)) { //leitura 1 significa que não tem fogo
      lcd.print("SEM FOGO");
    }
    else {
      lcd.print("OLHA O FOGO");
    }
    delay(tempoEntreInfos);
    limpaTela();
  }
  if (mostraChuva) {
    if (digitalRead(chuva)) { //leitura 1 significa que não há chuva
      lcd.print("SEM CHUVA");
    }
    else {
      lcd.print("OLHA A CHUVA");
    }
    delay(tempoEntreInfos);
    limpaTela();
  }

}
