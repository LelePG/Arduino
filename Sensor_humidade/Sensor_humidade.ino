/*
   Testes básicos com um sensor de humidade. A leitura do pino digital é em nível alto caso não haja humidade, e nível baixo caso uma humidade determinada seja atingida. A sensibilidade do pino digital 
   pode ser calibrada através do potenciômetro no módulo sensor. O pino analógico diz respeito a quantidade de humidade percebida, também iniciando em nível alto (1023), e que diminui segundo a quantidade
   de humidade percebida. O código contém uma função retirada dos exemplos do sensor de chuva e de chama, para calibrar.

   Letícia Pegoraro Garcez 2020
*/


//DEFINIÇÕES
#define analogico A0
#define digital 8 


//CABEÇALHO DAS FUNÇÕES
void informacoes(void);

void setup() {
  pinMode(analogico, INPUT);
  pinMode(digital, INPUT);
  Serial.begin(9600);
  
}

void loop() {
  informacoes();
}

//FUNÇÕES
void informacoes(void) {
  Serial.print("Digital - ");
  Serial.print(digitalRead(digital));
  Serial.print(" Analogico - ");
  Serial.println(analogRead(analogico));
  delay(50);
}
