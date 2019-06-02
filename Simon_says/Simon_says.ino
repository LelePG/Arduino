//entradas
#define l1 2
#define l2 3
#define l3 4
#define l4 5 
#define b1 8
#define b2 9
#define b3 10
#define b4 11
#define sb 7
//sounds for each led and one for the wrong function.
#define sl1 1047
#define sl2 1175
#define sl3 1319
#define sl4 1397
#define swrong 2093
int used_pos = 0;//Variável pra contar as posições que eu tenho no vetor.
int seq[50];//vetor de 50 posições pra armazenar os valores referentes a cada posição.
void setup() {
  pinMode(l1,OUTPUT);
  pinMode(l2,OUTPUT);
  pinMode(l3,OUTPUT);
  pinMode(l4,OUTPUT);
  pinMode(b1,INPUT);
  pinMode(b2,INPUT);
  pinMode(b3,INPUT);
  pinMode(b4,INPUT);
  pinMode(sb,OUTPUT);
}

void adiciona (void);
void pisca_led(int led);
void play_sequencia(void);
void confere(void);
void wrong(void);

void loop() {
  adiciona();//Insere a sequência
  delay(700);
  confere();//Confere a sequência. Com uma pausa pra não ficar muito corrido.
  delay(800);
}

void adiciona(void){
  randomSeed(millis());//Esse comando aqui torna as coisas realmente random.
  if(used_pos!=0){//Se eu já tiver coisa no vetor, reproduzo o que está no vetor
    play_sequencia();
  }
  seq[used_pos] = random(1,5);//Gera um random entre 1 e 4, ai é só associar ao pino;
  pisca_led(seq[used_pos]);
  used_pos++;//Incrementa o contador de posições usadas que eu tenho.
 
}
void pisca_led (int led){//Os valores 1,2,3,4 são associados ás saídas. Essa função acende o led e toca o som correspondente ao número no vetor.
  if (led == 1){
    digitalWrite(l1,HIGH);
    tone(sb,sl1);
    delay(500);
    noTone(sb);
    digitalWrite(l1,LOW);
  }
  else if(led ==2){
    digitalWrite(l2,HIGH);
    tone(sb,sl2);
    delay(500);
    digitalWrite(l2,LOW);
    noTone(sb);
  }
  else if(led==3){
    digitalWrite(l3,HIGH);
    tone(sb,sl3);
    delay(500);
    digitalWrite(l3,LOW);
    noTone(sb);
  }
  else if(led==4){
    digitalWrite(l4,HIGH);
    tone(sb,sl4);
    delay(500);
    noTone(sb);
    digitalWrite(l4,LOW);
  }
}
void play_sequencia(void){ //sem muito o que explicar aqui.
  int contador;
  for(contador=0;contador<used_pos;contador++){
    pisca_led(seq[contador]);
    delay(500);
  }
}
void confere(void){//Dá pra melhorar, mas assim tá fucnionando razoávelmente bem.
  int pressed=0,contador=0,x;
    while(contador<used_pos){//Enquanto eu não tiver feito todos os elementos da sequência ele continua esperando.
      x = seq[contador];//isso é só porque eu ia ter que escrever seq[contador] demais.
      if ((digitalRead(b1)==1 && x==1) || (digitalRead(b2)==1 && x==2) || (digitalRead(b3)==1 && x==3) || (digitalRead(b4)==1 && x==4)){
        //Basicamente se eu aperto o botão correspondente a posição certa que tá no vetor, ele fica esperando a entrada da próxima posição. Ele só acende o led do botão que eu apertei se eu acertei
        pisca_led(x);
        contador++;
      }
      else if ((digitalRead(b1)==1 && x!=1) || (digitalRead(b2)==1 && x!=2) || (digitalRead(b3)==1 && x!=3) || (digitalRead(b4)==1 && x!=4)){
        wrong();//SE eu apertei o botão diferente do que ele estava esperando ele roda a função de finalizar o jogo. Nessa função ele zera o c, então quando volta pra cá,
        //Sai automaticamente do loop e volta pro programa principal, então começa adicionando tudo do zero.
      }
    }
}

void wrong (void){
  digitalWrite(l1,HIGH);
  digitalWrite(l2,HIGH);
  digitalWrite(l3,HIGH);
  digitalWrite(l4,HIGH);
  tone(sb,swrong);
  delay(1500);//Deixa as leds e o som ligados um pouquinho depois desliga tudo
  noTone(sb);
  digitalWrite(l1,LOW);
  digitalWrite(l2,LOW);
  digitalWrite(l3,LOW);
  digitalWrite(l4,LOW);
  for(int contador = 0;contador<used_pos;contador++){//Isso aqui zera o meu vetor. Não que eu precisasse, porque ele pode ir só sobreescrevendo, mas eu quis.
    seq[contador]=0;
  }
  used_pos = 0;//Posições usadas no vetor:0.Ai vai.
}
