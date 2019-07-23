
/*
   Alguns exemplos usando LED RGB, usando LEDS com catodo comum (ligar no gnd) ou anodo comum (ligar no vcc). Importante lembrar que esses tipos de LED funcionam com lógica complementar.
   As funções colorir usam três botões e um potenciômetro para alterar as cores do LED.
   As funções semáforo implementam um semáforo com as cores vermelho, amarelo e azul, sem componentes adicionais.
   As funções setColor colorem o led conforme o código rgb inserido, sem componentes adicionais. Códigos podem ser encontrados, por exemplo, em https://www.w3schools.com/colors/colors_picker.asp
   As funções playDoReMi usam um soundBuzzer e a biblioteca Pitches.h, e tocam a música dó ré mi fá.
   Usar a função para o tipo errado de LED resulta em cores erradas, já que ambos funcionam com lógica complementar.

   Letícia Pegoraro Garcez 2019
*/
#include <Pitches.h>

#define red 3
#define green 2
#define blue 1

#define btnRed 8
#define btnGreen 9
#define btnBlue 10

#define potenciometer A1
#define soundBuzzer 6

void colorirAnodoComum(void);
void colorirCatodoComum(void);
void semaforoAnodoComum(void);
void semaforoCatodoComum(void);
void setColorAnodoComum(int redQ, int greenQ, int blueQ);
void setColorCatodoComum(int redQ, int greenQ, int blueQ);
void playDoReMiAnodoComum(void);

void setup() {
  pinMode(btnRed, INPUT);
  pinMode(btnGreen, INPUT);
  pinMode(btnBlue, INPUT);
  pinMode(potenciometer, INPUT);
  pinMode(soundBuzzer, OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
}

int potenciometerRead;

void loop() {
  playDoReMiCatodoComum();

}

void playDoReMiAnodoComum(void) {
  //32 - tamanho dos dois vetores Garantir que os dois vetores tenham o mesmo tamanho.
  int do_re_mi_notes[] = {NOTE_C7, NOTE_D7, NOTE_E7, NOTE_F7, 0, NOTE_F7, NOTE_F7, 0,
                          NOTE_C7, NOTE_D7, NOTE_C7, NOTE_D7, 0, NOTE_D7, NOTE_D7, 0,
                          NOTE_C7, NOTE_G7, NOTE_F7, NOTE_E7, 0, NOTE_E7, NOTE_E7, 0,
                          NOTE_C7, NOTE_D7, NOTE_E7, NOTE_F7, 0, NOTE_F7, NOTE_F7, 0
                         };
  int do_re_mi_duration[] = {400, 400, 400, 400, 200, 300, 300, 200,
                             400, 400, 400, 400, 200, 300, 300, 200,
                             400, 400, 400, 400, 200, 300, 300, 200,
                             400, 400, 400, 400, 200, 300, 300, 200
                            };
  int c, toca;
  for (c = 0; c < 32; c++) {
    toca = do_re_mi_notes[c];
    tone(soundBuzzer, toca, do_re_mi_duration[c]);
    switch (toca) {
      case NOTE_C7:
        setColorAnodoComum(51, 51, 255);
        break;
      case NOTE_D7:
        setColorAnodoComum(0, 204, 0);
        break;
      case NOTE_E7:
        setColorAnodoComum(255, 51, 0);
        break;
      case NOTE_F7:
        setColorAnodoComum(255, 204, 0);
        break;
      case NOTE_G7:
        setColorAnodoComum(153, 255, 153);
        break;
    }
    delay(do_re_mi_duration[c]);//pausa pra entender o som que o sound buzzer emite e ver o led
    setColorAnodoComum(0, 0, 0);

  }
}

void playDoReMiCatodoComum(void) {
  //32 - tamanho dos dois vetores Garantir que os dois vetores tenham o mesmo tamanho.
  int do_re_mi_notes[] = {NOTE_C7, NOTE_D7, NOTE_E7, NOTE_F7, 0, NOTE_F7, NOTE_F7, 0,
                          NOTE_C7, NOTE_D7, NOTE_C7, NOTE_D7, 0, NOTE_D7, NOTE_D7, 0,
                          NOTE_C7, NOTE_G7, NOTE_F7, NOTE_E7, 0, NOTE_E7, NOTE_E7, 0,
                          NOTE_C7, NOTE_D7, NOTE_E7, NOTE_F7, 0, NOTE_F7, NOTE_F7, 0
                         };
  int do_re_mi_duration[] = {400, 400, 400, 400, 200, 300, 300, 200,
                             400, 400, 400, 400, 200, 300, 300, 200,
                             400, 400, 400, 400, 200, 300, 300, 200,
                             400, 400, 400, 400, 200, 300, 300, 200
                            };
  int c, toca;
  for (c = 0; c < 32; c++) {
    toca = do_re_mi_notes[c];
    tone(soundBuzzer, toca, do_re_mi_duration[c]);
    switch (toca) {
      case NOTE_C7:
        setColorCatodoComum(51, 51, 255);
        break;
      case NOTE_D7:
        setColorCatodoComum(0, 204, 0);
        break;
      case NOTE_E7:
        setColorCatodoComum(255, 51, 0);
        break;
      case NOTE_F7:
        setColorCatodoComum(255, 204, 0);
        break;
      case NOTE_G7:
        setColorCatodoComum(153, 255, 153);
        break;
    }
    delay(do_re_mi_duration[c]);//pausa pra entender o som que o sound buzzer emite e ver o led
    setColorCatodoComum(0, 0, 0);
  }
}

void setColorCatodoComum(int redQ, int greenQ, int blueQ) {
  analogWrite(red, redQ);
  analogWrite(green, greenQ);
  analogWrite(blue, blueQ);
}

void setColorAnodoComum(int redQ, int greenQ, int blueQ) {
  analogWrite(red, 255 - redQ);
  analogWrite(green, 255 - greenQ);
  analogWrite(blue, 255 - blueQ);
}

void semaforoAnodoComum(void) {
  //Vermelho
  digitalWrite(red, LOW);
  digitalWrite(green, HIGH);
  digitalWrite(blue, HIGH);
  delay(1500);
  //Amarelo
  analogWrite(red, 0);
  analogWrite(green, 0);
  analogWrite(blue, 178);
  delay(600);
  //verde
  digitalWrite(red, HIGH);
  digitalWrite(green, LOW);
  digitalWrite(blue, HIGH);
  delay(1500);
  //Amarelo
  analogWrite(red, 0);
  analogWrite(green, 0);
  analogWrite(blue, 178);
  delay(600);
}

void semaforoCatodoComum(void) {
  //Vermelho
  digitalWrite(red, HIGH);
  digitalWrite(green, LOW);
  digitalWrite(blue, LOW);
  delay(1500);
  //Amarelo
  analogWrite(red, 255);
  analogWrite(green, 255);
  analogWrite(blue, 77);
  delay(600);
  //verde
  digitalWrite(red, LOW);
  digitalWrite(green, HIGH);
  digitalWrite(blue, LOW);
  delay(1500);
  //Amarelo
  analogWrite(red, 255);
  analogWrite(green, 255);
  analogWrite(blue, 77);
  delay(600);
}

void colorirAnodoComum(void) {
  potenciometerRead = map(analogRead(potenciometer), 0, 1023, 0, 255);
  if (digitalRead(btnRed)) {
    analogWrite(red, 255 - potenciometerRead);
    potenciometerRead = map(analogRead(potenciometer), 0, 1023, 0, 255);
  }
  else if (digitalRead(btnGreen)) {
    analogWrite(green, 255 - potenciometerRead);
    potenciometerRead = map(analogRead(potenciometer), 0, 1023, 0, 255);
  }
  else if (digitalRead(btnBlue)) {
    analogWrite(blue, 255 - potenciometerRead);
    potenciometerRead = map(analogRead(potenciometer), 0, 1023, 0, 255);
  }
}

void colorirCatodoComum(void) {
  potenciometerRead = map(analogRead(potenciometer), 0, 1023, 0, 255);
  if (digitalRead(btnRed)) {
    analogWrite(red, potenciometerRead);
    potenciometerRead = map(analogRead(potenciometer), 0, 1023, 0, 255);
  }
  else if (digitalRead(btnGreen)) {
    analogWrite(green, potenciometerRead);
    potenciometerRead = map(analogRead(potenciometer), 0, 1023, 0, 255);
  }
  else if (digitalRead(btnBlue)) {
    analogWrite(blue, potenciometerRead);
    potenciometerRead = map(analogRead(potenciometer), 0, 1023, 0, 255);
  }
}
