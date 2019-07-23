#include <Pitches.h>//biblioteca com os sons
//pinos
#define l1 1//led
#define l2 2//led
#define l3 3//led
#define l4 4//led
#define l5 5//led
#define sb 13//soundBuzzer
#define btn1 7//button
#define btn2 8//button

//funções
void play_soft_kitty(void);
void play_do_re_mi(void);
void apaga_led(void);

void setup() {
  pinMode(l1, OUTPUT);
  pinMode(l2, OUTPUT);
  pinMode(l3, OUTPUT);
  pinMode(l4, OUTPUT);
  pinMode(l5, OUTPUT);
  pinMode(sb, OUTPUT);
  pinMode(btn1, INPUT);
  pinMode(btn2, INPUT);
}

void loop() {
  if (digitalRead(btn1) == HIGH) {//Se o botão 1 é apertado
    play_do_re_mi();
  }
  else if (digitalRead(btn2) == HIGH) {//Se o botão 2 é apertado
    play_soft_kitty();
  }
  else {
    noTone(sb);//garante que o buzzer não vai receber nenhum lixo
  }
}

void play_soft_kitty(void) {
  //25 - tamanho dos vetores. Garantir que os dois vetores tenham o mesmo tamanho.
  int soft_kitty_notes[] = {NOTE_A7, NOTE_FS7, NOTE_FS7, NOTE_G7, NOTE_E7, NOTE_E7, NOTE_D7, NOTE_E7, NOTE_FS7, NOTE_G7, NOTE_A7, 0,
                            NOTE_A7, NOTE_A7, NOTE_FS7, NOTE_FS7, NOTE_G7, NOTE_G7, NOTE_E7, NOTE_E7, NOTE_D7, 0, NOTE_E7, 0, NOTE_D7
                           };
  int soft_kitty_duration[] = {700, 400, 400, 700, 400, 400, 400, 400, 400, 400, 400, 200,
                               400, 400, 400, 600, 400, 400, 400, 600, 600, 100, 600, 100, 600
                              };
  int c = 0, toca;
  for (c = 0; c < 25; c++) { //Percorre os vetores
    toca = soft_kitty_notes[c];
    tone(sb, toca, soft_kitty_duration[c]); //o sound buzzer toca a nota por tanto tempo, acende a luz que tem que acenter
    switch (toca) {
      case NOTE_D7:
        digitalWrite(l1, HIGH);
        break;
      case NOTE_E7:
        digitalWrite(l2, HIGH);
        break;
      case NOTE_FS7:
        digitalWrite(l3, HIGH);
        break;
      case NOTE_G7:
        digitalWrite(l4, HIGH);
        break;
      case NOTE_A7:
        digitalWrite(l5, HIGH);
        break;
    }
    delay(soft_kitty_duration[c]);//pausa pra entender o som que o sound buzzer emite e ver o led
    apaga_led();//desliga todos os leds
  }
}

void apaga_led(void) {
  digitalWrite(l1, LOW);
  digitalWrite(l2, LOW);
  digitalWrite(l3, LOW);
  digitalWrite(l4, LOW);
  digitalWrite(l5, LOW);
}

void play_do_re_mi(void) {
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
    tone(sb, toca, do_re_mi_duration[c]); //o sound buzzer toca a nota por tanto tempo, acende a luz que tem que acender
    switch (toca) {
      case NOTE_C7:
        digitalWrite(l1, HIGH);
        break;
      case NOTE_D7:
        digitalWrite(l2, HIGH);
        break;
      case NOTE_E7:
        digitalWrite(l3, HIGH);
        break;
      case NOTE_F7:
        digitalWrite(l4, HIGH);
        break;
      case NOTE_G7:
        digitalWrite(l5, HIGH);
        break;
    }
    delay(do_re_mi_duration[c]);//pausa pra entender o som que o sound buzzer emite e ver o led
    apaga_led();//desliga todos os leds

  }
}
