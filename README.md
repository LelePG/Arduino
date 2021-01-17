# PROJETOS COM ARDUINO
Cada projeto se encontra em uma pasta separada, com todos os arquivos necessários pra seu funcionamento, incluindo bibliotecas.
Cada `.ino` inclui um comentário detalhado sobre seu funcionamento e algumas especificações a mais.

A maioria dos projetos se limita à compreensão do funcionamento de sensores, bem como a criação de projetos simples de monitoramento. 

##Projetos

###Besourinho
Projeto simples de um robôzinho que anda para a frente, feito com dois servos motores. Imagens das duas versões desenvolvidas do projeto podem ser encontradas na pasta do projeto.

###Braço_Servos
Projeto de um braço mecânico criado com dois servos motores e um módulo de Joystick.

###Iluminações_LED_cube_2X2
Definição de três modos de iluminação para um cubo de LED 2X2. Cada iluminação é definida como uma função, e essa função deve estar dentro do void loop.

###Joystick_Module
Testes de funcionamento do módulo de Joystick com LEDs.

###Led_RGB_Exemplos
Uma série de funções incluindo uma caixa de música utilizando um LED RGB. Inclui funções tanto para LEDs de ânodo comum, como de cátodo comum.

###Seletor_Sensores
Um sistema com LDR, thermistor, sensor de fogo e de chuva. O projeto também tem uma tela de LCD que exibe mensagens e deixa que o usuário escolha quais sensores quer mostrar os valores.

###Sensor_Capacitivo
Projeto de um abajur de toque utilizando sensor de toque capacitivo. Pode ser implementado com um botão.

###Sensor_Chama
Testes básicos para entender o funcionamento do sensor.

###Sensor_chuva
Testes básicos para entender o funcionamento do sensor.

###Sensor_Distância
Projeto de sensor de aproximação usando a bibliotace Ultrassonic, sensor de distância ultrassônico, LEDs e soundbuzzer.

###Sensor_huminade
Testes básicos para entender o funcionamento do sensor.

###Servo_Motor
Projeto com dois botões que rotacionam um servo motor para a direita ou para a esquerda.

###Simon_says
Projeto do jogo gênio(simon says), onde uma sequência de luzes é dada pelo programa e deve ser repetida pelo usuário utilizando botões. 

###Song_box
Projeto de uma caixinha de música que toda dó-re-mi-fá ou soft kitty, dependendo da escolha do usuário. Há um botão para a ativação de cada música. Utiliza a biblioteca Pitches para tocar os sons.

###Teclado_Membarana_4X3
Utiliza um teclado de 12 teclas e a biblioteca keypad para pedir ao usuário uma senha, que deve ser compatível com a senha definida no programa.

###Termometro_7seg
Projeto que utiliza as bibliotecas SevSeg para o display de 7 segmentos e a biblioteca Thermistor para exibir a temperatura no display de 7 segmentos. Utiliza a condição millis para criar intervalos de tempo para que a leitura seja realizada.

###Tranca_Membrana_Servo
Tranca inteligente ativada por uma senha definida pelo usuário no primeiro uso. Utiliza um servo motor e um teclado de membrana de 12 teclas. As bibliotecas são Keypad e Servo.

###Whack-a-Mole-v1
Jogo onde você deve apertar um botão corresponde a um determinado LED em um intervalo de tempo. Possui comunicação com o monitor serial para exibir a pontuação.

###Whack-a-Mole-v2
Jogo de decisão baseada em cores de um LED RGB. Uma cor aleatória é mostrada e uma ação deve ser tomada pelo jogador no módulo de Joystick que é o controle do jogo.

###Whack-a-Mole-v3
Jogo de Whack-a-Mole, mas com movimentação nos módulo de joystick nos eixos X e Y, aperto de botão e sensor LDR. Este projeto também implementa um display LCD para comunicação com o usuário.
