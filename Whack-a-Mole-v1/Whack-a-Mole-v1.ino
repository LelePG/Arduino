/*Whack-a-Mole-v1

   O jogo é consistido por 4 LEDs e 4 botões. Um dos LEDs é aceso de maneira randômica, e o botão correspondente à este LED deve ser apertado em um determinado período de tempo, ou o jogo é perdido.
   A velocidade em que os LEDs ficam acesos e o tempo para apertar o botão diminuiem gradualmente, o tempo para apertar o botão em função de um incremento de contador que aumenta entre as rodadas, e
   o tempo de exibição do LED segundo um decremento de 30 ms.
   Para ganhar o jogo, é necessário fazer 20 pontos, e a pontuação final do jogo pode ser vista no monitor Serial, tanto em caso de vitória como de derrota, sons também são aplicados em caso de vitória e derrota.

   Letícia Pegoraro Garcez 2020
*/


int botoes[4] = {7, 6, 5, 4}; //Pinos onde estão ligados os botões
int led[4] = {8, 9, 10, 11}; //pinos onde estão ligados os LEDS
int sb = 2; //soundBuzzer
int c;//Variável contador
float contador_tempo;//tempo para a pessoa acertar o LED que foi aceso
int tempo_maximo = 300; //Parâmetro de tempo máximo
int espera_led = 1000;//Tempo de espera do LED aceso
int escolha;//Escolhe o LED a ser aceso
int pontos;
float incremento = 0.5;//Aumento gradual da tempo_maximo


void reinicia_jogo(void);

void setup() {
  for (c = 0; c < 4; c++) {
    pinMode(led[c], OUTPUT);
    pinMode(botoes[c], INPUT);
  }
  pinMode(sb, OUTPUT);

  Serial.begin(9600);
}



void loop() {
  contador_tempo = 0.0;
  incremento += 0.3;
  noTone(sb);
  randomSeed(millis());
  escolha = random(4);
  digitalWrite(led[escolha], HIGH);
  delay(espera_led);
  digitalWrite(led[escolha], LOW);
  do {
    contador_tempo += incremento;
    delay(10);
    //Serial.print(contador_tempo);//debug
    //Serial.println(incremento);//debug
  } while (contador_tempo < tempo_maximo && !digitalRead(botoes[escolha]));

  if (pontos == 20) { //vitória
    Serial.print("GANHOU! Pontos - ");
    Serial.println(pontos);
    tone(sb, 1047);
    delay(400);
    tone(sb, 1175);
    delay(600);
    tone(sb, 1319);
    delay(800);
    noTone(sb);
    reinicia_jogo();
  }

  if (contador_tempo < tempo_maximo) { //continua o jogo
    pontos++;
    espera_led -= 30;
    delay(100);
  }
  else {
    Serial.print("Você perdeu! Pontos - ");
    Serial.println(pontos);
    tone(sb, 2029);
    delay(1000);
    noTone(sb);
    reinicia_jogo();
  }
}


void reinicia_jogo(void) {
  for (c = 0; c < 4; c++) {
    digitalWrite(led[c], HIGH);
    Serial.println();
    delay(50);
  }

  delay(300);

  for (c = 0; c < 4; c++) {
    digitalWrite(led[c], LOW);
    Serial.println();
    delay(50);
  }

  delay(3500);
  pontos = 0;
  incremento = 0.5;
  espera_led = 1000;
}
