//Notas porque eu nunca consigo incluir aquele bagulho de pitches.h
const int NOTE_C7 = 2093;//tá dando erro com define... vai entender...
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
const int NOTE_G7 = 3136; //Esse tá assim porque tava dando erro
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
//agora os pinos
#define l1 7
#define l2 8
#define l3 9
#define l4 10
#define l5 12
#define sb 13
#define btn1 2
#define btn2 3
//funções
void play_soft_kitty(void);
void play_do_re_mi(void);
void apaga_led(void);
void setup() {
  pinMode(l1,OUTPUT);
  pinMode(l2,OUTPUT);
  pinMode(l3,OUTPUT);
  pinMode(l4,OUTPUT);
  pinMode(l5,OUTPUT);
  pinMode(sb,OUTPUT);
  pinMode(btn1,INPUT);
  pinMode(btn2,INPUT);
 // Serial.begin(9600); Vou deixar esse comando aqui porque é o que eu uso quando alguma coisa dá errado...
}
int bs1,bs2;//button state. Declarei aqui em cima pra não ficar ocupando espaço toda vez que entra no void loop.
void loop() {
 bs1 = digitalRead(btn1);
 bs2 = digitalRead(btn2);
 if(bs1==1){
  play_do_re_mi();
 }
 else if (bs2==1){
  play_soft_kitty();
 }
 else{
  noTone(sb);
 }
}
void play_soft_kitty(void){
  //25 - tamanho dos vetores
  int soft_kitty_notes[] = {NOTE_A7, NOTE_FS7, NOTE_FS7, NOTE_G7,NOTE_E7,NOTE_E7, NOTE_D7,NOTE_E7,NOTE_FS7,NOTE_G7,NOTE_A7,0,
  NOTE_A7,NOTE_A7,NOTE_FS7,NOTE_FS7,NOTE_G7,NOTE_G7,NOTE_E7,NOTE_E7,NOTE_D7,0,NOTE_E7,0,NOTE_D7};
  int soft_kitty_duration[] = {700,400,400,700,400,400,400,400,400,400,400,200,
  400,400,400,600,400,400,400,600,600,100,600,100,600};//Tenha certeza que os dois vetores tem o mesmo tamanho. 
  int c=0,toca; 
    for(c=0;c<25;c++){//Tem que ser o for porque não encontrei uma condição de parada pra usar o while então preciso saber o tamanho
    toca = soft_kitty_notes[c];
    tone(sb,toca,soft_kitty_duration[c]);//o sound buzzer toca a nota por tanto tempo, acende a luz que tem que acenter
    if(toca == NOTE_D7){
      digitalWrite(l1,HIGH);
    }
    else if(toca==NOTE_E7){
      digitalWrite(l2,HIGH);
    }
    else if(toca==NOTE_FS7){
      digitalWrite(l3,HIGH);
    }
    else if(toca==NOTE_G7){
      digitalWrite(l4,HIGH);
    }
    else if(toca==NOTE_A7){
      digitalWrite(l5,HIGH);
    }
    delay(soft_kitty_duration[c]);//pausa pra gente entender o som que o sound buzzer emite e ver o led
    apaga_led();//desliga tudo que é led pra acender depois.
    }
  } 
void apaga_led(void){
digitalWrite(l1,LOW);
digitalWrite(l2,LOW);
digitalWrite(l3,LOW);
digitalWrite(l4,LOW);
digitalWrite(l5,LOW);
}
void play_do_re_mi(void){
  //32
  int do_re_mi_notes[] = {NOTE_C7, NOTE_D7, NOTE_E7, NOTE_F7,0,NOTE_F7,NOTE_F7,0,
  NOTE_C7,NOTE_D7,NOTE_C7,NOTE_D7,0,NOTE_D7,NOTE_D7,0,
  NOTE_C7,NOTE_G7,NOTE_F7,NOTE_E7,0,NOTE_E7,NOTE_E7,0,
  NOTE_C7,NOTE_D7,NOTE_E7,NOTE_F7,0,NOTE_F7,NOTE_F7,0};
  int do_re_mi_duration[] = {400,400,400,400,200,300,300,200,
  400,400,400,400,200,300,300,200,
  400,400,400,400,200,300,300,200,
  400,400,400,400,200,300,300,200};//Tenha certeza que os dois vetores tem o mesmo tamanho. 
  int c,toca; 
   for(c=0;c<32;c++){//Tem que ser o for porque não encontrei uma condição de parada pra usar o while então preciso saber o tamanho
   toca = do_re_mi_notes[c];
   tone(sb,toca,do_re_mi_duration[c]);//o sound buzzer toca a nota por tanto tempo, acende a luz que tem que acenter
    if(toca == NOTE_C7){
      digitalWrite(l1,HIGH);
    }
    else if(toca==NOTE_D7){
      digitalWrite(l2,HIGH);
    }
    else if(toca==NOTE_E7){
      digitalWrite(l3,HIGH);
    }
    else if(toca==NOTE_F7){
      digitalWrite(l4,HIGH);
    }
    else if(toca==NOTE_G7){
      digitalWrite(l5,HIGH);
    }
    delay(do_re_mi_duration[c]);//pausa pra gente entender o som que o sound buzzer emite e ver o led
    apaga_led();//desliga tudo que é led pra acender depois.
  
  }
}
