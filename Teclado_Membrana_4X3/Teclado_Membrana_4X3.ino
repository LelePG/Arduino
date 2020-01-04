
/*
 * Leitor de senhas utilizando um teclado de membrana 12 teclas e a biblioteca keypad.h.
 * O teclado é definido como um objeto da classe keypad-> Keypad(makeKeymap(matriz de teclas), posições dos pinos linha, posições dos pinos coluna, numero de linhas, numero de colunas), sendo que 
 * numero de linhas e colunas deve ser declarado como const int e os vetores onde se encontram as posições dos pinos devem ser declarados como byte.
 * Uma senha de 5 digitos está previamente definida e é requerida ao usuário. A senha deve conter apenas números, e após ser digitada pode ser exibida ou verificada, para saber se está correta ou não.
 * A opção de digitar outra senha sempre está disponível ao término da digitação da atual. O tamanho da senha pode ser alterado a definição de tamanho e o conteúdo da constance senha.
 * 
 * 
 * Letícia Pegoraro Garcez 2020
*/

//IMPORTAÇÃO DE BIBLIOTECAS
#include <Keypad.h>

//DEFINIÇÃO DAS VARIVÁVEIS RELATIVAS AO HARDWARE DO TELCADO
#define tamanho 5
//linhas e colunas devem ser declaradas como const int
const int linhas =  4;
const int colunas = 3;

char teclas[linhas][colunas] = { {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'*', '0', '#'}
};
//os vetores dos pinos relacionados aos terminais devem ser do tipo byte
byte pinosL[linhas] = {4, 5, 6, 7}; // vetor que guarda os pinos referentes aos terminais 1-4 do teclado, que correspondem as linhas
byte pinosC[colunas] = {8, 9, 10}; // vetor que guarda os pinos referentes aos terminais 5-7 do teclado, que correspondem as colunas

//DEFINIÇÃO DE UM OBJETO TECLADO DA BIBLIOTECA
Keypad teclado = Keypad(makeKeymap(teclas), pinosL, pinosC, linhas, colunas);

//DEFINIÇÃO DA SENHA
const char senha[tamanho] = {'1', '2', '3', '4', '5'}; //senha a ser digitada

//CABEÇALHOS DAS FUNÇÕES
void menu(void);
char leTeclado(void);
void leiaSenha(char* s, int limite);//recebe o endereço onde a senha deve ser guardada e o tamanho
void imprimeSenha(char* s);//recebe a senha que deve ser impressa
void verificaSenha(char* s);//recebe a senha que deve ser impressa

void setup()
{
  Serial.begin(9600);//exibição de mensagens e debug
}

char leitura;//varivável auxiliar do programa principal
char senhaInput[5];//senha digitada

void loop()
{
  menu();
  leiaSenha(senhaInput, tamanho); //onde a senha deve ser guardada e seu tamanho
  Serial.println("Senha digitada com sucesso");
  //imprimeSenha(senhaInput);//A leitura da senha está correta

  //INTERPRETA OPÇÃO DE VALIDAÇÃO
  do { //involve condição de restarting
    Serial.println("Digite '*' para confirmar, '#' para exibir a senha digitada e '0' para digitar outra senha.");//mensagem informativa
    leitura = leTeclado();
    if (leitura == '*') {//opção de verificação da senha
      verificaSenha(senhaInput);
    }
    else if (leitura == '#') {//opção de impressão
      imprimeSenha(senhaInput);
    }
    else if (leitura != '0') { //caso não seja nenhuma das acima ou zero, que finaliza o programa, é uma opção inválida
      Serial.println("Opção de verificação inválida");

    }
  } while (leitura != '0');//zero finaliza esta execução
  Serial.println("RESTARTING");//Reinicia

}

//FUNÇÕES
void menu(void) {
  Serial.print("Digite sua senha de ");
  Serial.print(tamanho);
  Serial.println(" dígitos.");
  Serial.println("Digite '*' para confirmar e '#' para exibir a senha digitada");
}

void imprimeSenha(char* s) {
  for (int c = 0; c < 5; c++) {
    Serial.print(s[c]);
    Serial.print(" ");
  }
  Serial.println();
}

char leTeclado(void) {
  char entrada;
  do {
    entrada = teclado.getKey();
  } while (!entrada); //não prossegue sem algo ser digitado
  // Serial.println(entrada);
  return entrada;//e quando algo é digitado, retorna.
}

void verificaSenha(char* s) {
  for (int c = 0; c < 5; c++) {
    if (s[c] != senha[c]) {
      Serial.println("SENHA INCORRETA");
      return;
    }
  }
  Serial.println("SENHA CORRETA");
}

void leiaSenha(char* s, int limite) {
  int contador = 0;
  for (contador; contador < limite; contador++) {
    s[contador] = leTeclado();
    Serial.println("Digito digitado"); // algo foi lido
    if (s[contador] == '*' || s[contador] == '#') { //se algum dos caracteres foi digitado como parte da senha
      Serial.println("Senha não foi digitada corretamente. Tente novamente.");
      contador = -1; //reinicia o loop. Quando voltar lá pra cima, o contador vai ser incrementado, então deve ser setado pra -1
    }
  }
}
