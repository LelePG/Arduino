
/*
   Este projeto simula uma tranca ativada por senha. No primeiro uso, o usuário define uma senha com uma quantidade de dígitos
   definidos na variável TAMANHO. Quando o código é uplodiado, no primeiro uso, o usuário seta a senha.
   Para abrir a tranca, é preciso digitar a senha enquanto um LED que indica que está pronto para a senha ser inserida.
   Um LED e um buzzer são ativados caso a senha esteja incorreta, e novas tentativas podem ser feitas uma vez que o LED que
   indica que a senha pode ser digitada está acesa. Uma vez aberta, a tranca é fechada teclando "*" ou "#" no teclado de membrana.
   Depois de trancar a caixa, a luz de "pronto" é acesa e a senha já pode ser digitada novamente.
   
   O teclado é definido como um objeto da classe keypad-> Keypad(makeKeymap(matriz de teclas), posições dos pinos linha, posições dos pinos coluna, numero de linhas, numero de colunas), sendo que
   numero de linhas e colunas deve ser declarado como const int e os vetores onde se encontram as posições dos pinos devem ser declarados como byte.
   A biblioteca se encontra na pasta do projeto. O Servo utiliza a biblioteca Servo padrão.

   Letícia Pegoraro Garcez 2020
*/

//IMPORTAÇÃO DE BIBLIOTECAS
#include <Keypad.h>
#include <Servo.h>

#define TAMANHO 3//tamanho da senha. O código usa c<TAMANHO, por isso tamanho tem que ser um número menor do que o desejado.

//linhas e colunas devem ser declaradas como const int
const int linhas =  4;
const int colunas = 3;

//LEDs para indicar o estado
#define led_pronto 4
#define led_errado 3
#define motor 13
#define buzzer 2

//DEFINIÇÃO DAS VARIVÁVEIS RELATIVAS AO HARDWARE DO TELCADO


char teclas[linhas][colunas] = { {'1', '2', '3'},//representação do teclado
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'*', '0', '#'}
};

//os vetores dos pinos relacionados aos terminais devem ser do tipo byte
byte pinosL[linhas] = {6, 7, 8, 9}; // vetor que guarda os pinos referentes aos terminais 1-4 do teclado, que correspondem as linhas
byte pinosC[colunas] = {10, 11, 12}; // vetor que guarda os pinos referentes aos terminais 5-7 do teclado, que correspondem as colunas

//DEFINIÇÃO DA VARIÁVEL SENHA
char senha[TAMANHO];//senha definida no primeiro uso
char senhaInput[TAMANHO];//senha digitada pelo usuario

//CABEÇALHOS DAS FUNÇÕES

char leTeclado(void);//lê um character digitado
bool verificaSenha(char* s);//confere se a senha está correta
void aguardaTrancamento(void);//espera o comando pra caixa ser fechada novamente

Keypad teclado = Keypad(makeKeymap(teclas), pinosL, pinosC, linhas, colunas);//Definição e inicialização do teclado
Servo s;//cria um objeto Servo

void setup()
{
  pinMode(led_pronto, OUTPUT);
  pinMode(led_errado, OUTPUT);
  pinMode(motor, OUTPUT);
  pinMode(buzzer, OUTPUT);


  Serial.begin(9600);

  s.attach(motor);//Assossia o objeto servo s ao pino do motor
  s.write(0);
  //Inicialização do primeiro uso, acendendo os dois leds

  digitalWrite(led_pronto, HIGH);
  digitalWrite(led_errado, HIGH);

  for (int c = 0; c < TAMANHO; c++) { // Lê a senha
    senha[c] = leTeclado();
  }

Serial.print(senha);
  delay(1000);//espera
  digitalWrite(led_pronto, LOW);
  digitalWrite(led_errado, LOW);
  delay(2000);//tempo antes de liberar as adivinhações de senha.
  s.write(90);

}


void loop() {
  digitalWrite(led_pronto, HIGH); // Indico que  esá pronto pra leitura

  for (int c = 0; c < TAMANHO; c++) { // Lê a senha digitada pelo usuario
    senhaInput[c] = leTeclado();
  }
  Serial.print(senhaInput);
  Serial.print("     ");
  Serial.println(senha);

  if (verificaSenha(senhaInput)) {//Se a senha está correta
    s.write(0);
    digitalWrite(led_pronto, LOW);
    digitalWrite(led_errado, LOW);
    aguardaTrancamento();
  } else {//senão...
    digitalWrite(led_pronto, LOW);
    digitalWrite(led_errado,HIGH);
    tone(buzzer, 2500);
    delay(700);
    noTone(buzzer);
    digitalWrite(led_errado,LOW);
  }



}

//FUNÇÕES
char leTeclado(void) {
  char entrada;
  do {
    entrada = teclado.getKey();
  } while (!entrada); //não prossegue sem algo ser digitado
  // Serial.println(entrada);
  return entrada;//e quando algo é digitado, retorna.
}

bool verificaSenha(char* s) {
  for (int c = 0; c < TAMANHO; c++) {//senha incorreta
    if (s[c] != senha[c]) {
      return false;
    }
  }
  return true;//se não foram encontrados erros na senha, ela é correta
}

void aguardaTrancamento(void) { //As teclas "*" ou "#" devem ser apertadas pra fechar a caixa.
  do {
    delay(10);
  } while (leTeclado() != '*' && leTeclado() != '#');
      s.write(90);

  }
