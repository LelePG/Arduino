/*Iluminações de um cubo de LED 2X2

   Foram criadas três funções de iluminação para um cubo de LED 2X2. Para selecionar a iluminação, só colocar a função escolhida dentro do void loop
   Os LEDs devem estar ligados em pinos analógicos para garantir a compatibilidade com todas as funções. O tamanho do vetor que guarda
   a quantidade de LEDs da primeira camada é definido pela constante TAMANHO, e a constante TEMPO define o intervalo entre os "blinks" das iluminações.
   O cubo de LED é estruturado com duas camadas sobrepostas, de modo que a iluminação pode ser feita utilizando apenas uma camada do cubo,
   já que a segunda apenas imita a primeira. 

   Letícia Pegoraro Garcez 2020
*/
#define TAMANHO 4
#define TEMPO 300

int leds[TAMANHO] = {A0, A1, A2, A3};

void aleatorio (void);//iluminação 1
void fade(void);//iluminação 2
void diagonal(void);//iluminação 3

void setup() {
  for (int c = 0; c < TAMANHO; c++) {
    pinMode(leds[c], OUTPUT);
  }

}

void loop() {
  diagonal();
}

void aleatorio(void) {
  randomSeed(millis());//A seed do random vira o tempo atual de execução, o que faz com que as sequencias possam ser diferentes
  digitalWrite(leds[random(0, TAMANHO)], random(0, 2));
  delay(TEMPO);

}

void fade(void) {
  for (int i = 0; i < TAMANHO; i++) {
    for (int c = 0; c < 255; c += 10) {
      analogWrite(leds[i], c);
      delay(TEMPO);
    }
  }
  for (int i = 0; i < TAMANHO; i++) {
    for (int c = 255; c > 0; c -= 10) {
      analogWrite(leds[i], c);
      delay(TEMPO);
    }
  }
}

void diagonal(void) {
  digitalWrite(leds[0], HIGH);
  digitalWrite(leds[1], LOW);
  digitalWrite(leds[2], HIGH);
  digitalWrite(leds[3], LOW);
  delay(TEMPO);
  digitalWrite(leds[0], LOW);
  digitalWrite(leds[1], HIGH);
  digitalWrite(leds[2], LOW);
  digitalWrite(leds[3], HIGH);
  delay(TEMPO);
}
