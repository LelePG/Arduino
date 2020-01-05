/*
   Testes básicos com um sensor de chuva. A leitura digital se divide em 1, caso não seja detectado chuva, e zero caso sim. O pino analógico diz respeito a quantidade de gotas na quantiade de chuva,
   e pode ser utilizado para medir a quantidade de chuva, classificando-a com a função map. Uma vez detectada a chuva, um led é aceso e o soundbuzzer é ativado.
   Uma função que mostra as leituras pode ser ativada. É um extremamente similar ao sensor de chama, tanto que refiz os testes com praticamente o mesmo código.

   Letícia Pegoraro Garcez 2020
*/


//DEFINIÇÕES
#define analogico A0
#define digital 5 
#define led 4 
#define buzzer 8

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
  leitura  =  digitalRead(digital);
  if (leitura) {
    digitalWrite(led, HIGH);
    tone(buzzer, 80);
  }
  else {
    digitalWrite(led, LOW);
    noTone(buzzer);
  }
  delay(100);//Delay de performance

}

//FUNÇÕES
void informacoes(void) {
  Serial.begin(9600);
  Serial.print("Digital - ");
  Serial.print(digitalRead(digital));
  Serial.print(" Analogico - ");
  Serial.println(analogRead(analogico));
  delay(50);
}
