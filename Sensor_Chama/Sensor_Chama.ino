/*
   Testes básicos com um sensor de chama. A leitura digital se divide em 1, caso não seja detectado fogo, e zero caso sim. O pino analógico diz respeito a temperatura no termoresistor,
   mas também pode ser mapeado usando map para classificar a distância da chama. Uma vez detectada a chama, um led é aceso e o soundbuzzer é ativado. Uma função que mostra as leituras pode ser
   ativada. É um sensor relativamente fácil de usar.

   Letícia Pegoraro Garcez 2020
*/


//DEFINIÇÕES
#define analogico A0
#define digital 7
#define led 8
#define buzzer 10

//CABEÇALHO DAS FUNÇÕES
void informacoes(void);

void setup() {
  pinMode(analogico, INPUT);
  pinMode(digital, INPUT);
  pinMode(led, OUTPUT);
  pinMode(buzzer, OUTPUT);
}

int leitura;//Variável auxiliar

void loop() {
  //informacoes();
  leitura = !digitalRead(digital);//se detectar fogo, a leitura é zero, caso contrário, é um. Para facilitar a lógica do código, a variável já lê o valor invertido
  if (leitura) {
    tone(buzzer, 80);
  }
  else {
    noTone(buzzer);
  }
  digitalWrite(led, leitura);
  delay(50);//delay de performance

}

//FUNÇÕES
void informacoes(void) {
  Serial.begin(9600);
  Serial.print("Digital - ");
  Serial.print(digitalRead(digital));
  Serial.print(" Analogico - ");
  Serial.println(analogRead(analogico));
}
