/*
   Exemplo simples da utilização de um módulo Joystick com LEDs. Cada eixo coordenado é lido por um potenciômetro, e cada um dos potenciômetros está relacionado
   a um dos LEDs, para controlar seu brilho. O botão do joystick, quando pressionado, faz com que os dois LEDs fiquem piscando. Uma função para mostrar as leituras de cada parte
   pode ser habilitada. Na porta correspondente a leitura do botão, deve ser escrito HIGH para o funcionamento correto da mesma.
   Comunicação Serial pode ser habilitada para debug.

   Letícia Pegoraro Garcez 2020
*/

//DEFINIÇÕES
#define ledVermelho 10
#define ledAmarelo 9
#define eixoX A0
#define eixoY A1
#define botao 5

//CABEÇALHOS DE FUNÇÕES
void informacoes(void);
void pisca(void);

void setup() {
  pinMode(ledVermelho, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
  pinMode(eixoX, INPUT);
  pinMode(eixoY, INPUT);
  pinMode(botao, INPUT);
  digitalWrite(botao, HIGH);//inicializa o estado de leitura como HIGH
}

void loop() {
  //informacoes(); //estados das variáveis
  analogWrite(ledVermelho, map(analogRead(eixoX), 0, 1023, 0, 255));//escrita no LED vermelho
  analogWrite(ledAmarelo, map(analogRead(eixoY), 0, 1023, 0, 255)); //escrita no LED amarelo
  while (digitalRead(botao) == LOW ) {//Se o botão for pressionado, os LEDs piscam
    pisca();
  }
  delay (100);//delay de funcionamento
}


//FUNÇÕES
void informacoes(void) {
  Serial.begin(9600);
  Serial.print("x-> ");
  Serial.print(analogRead(eixoX));
  Serial.print("  y-> ");
  Serial.print(analogRead(eixoY));
  Serial.print("  btn-> ");
  Serial.println(digitalRead(botao));
}

void pisca(void) {
  digitalWrite(ledVermelho, HIGH);
  digitalWrite(ledAmarelo, HIGH);
  delay(50);
  digitalWrite(ledVermelho, LOW);
  digitalWrite(ledAmarelo, LOW);
  delay(50);
}
