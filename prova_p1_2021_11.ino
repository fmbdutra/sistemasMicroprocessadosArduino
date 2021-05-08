/***************************************************************************
* Prova P1 - 2021_1															*
*																			*
*	1 – Desenvolva um programa que a partir da leitura de uma entrada 		*
*	Analógica (Potenciômetro) gerencie os 4 LEDs Vermelhos da seguinte		*
*	maneira:																*
*		POT = 0 	- LED_VM_LD1, LED_VM_LD2, LED_VM_LD3 e LED_VM_LD4(OFF)	*
*		POT = 1023	- LED_VM_LD1, LED_VM_LD2, LED_VM_LD3 e LED_VM_LD4(ON)	*
*		POT entre 0 e 1023	os LEDs devem ligar de maneira proporcional e	*
*		crescente ao valor lido.
															*
*																			*
*	2 – A partir de dois botões, controle o acionamento dos 4 LEDs Verdes	*
*	que	devem funcionar como um contador “BCD”. Um terceiro botão deverá    *
*   resetar o contador quando pressionado. 									*
*																			*
*	Descrição de um contador BCD.    										*
*		Contagem = 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 1, .....)				*
*																			*
*	3 – Utilizando um sensor LDR (Resistor Dependente de Luz, ou em Inglês  *
*	– Light-Dependent Resistor), ligar um LED sempre que a luminosidade     *
*	estiver	menor que 30% do seu valor máximo (307 níveis do A/D). 			*
*	Apresentar no monitor serial os valores	lidos do sensor e o estado	 	*
*	do LED (ON ou OFF).														*
*																			*
*																			*
*****************************************************************************/

//***************************************************************************
//Define Constantes Utilizadas no Sketch

//***************************************************************************
//QUESTÃO 1
//***************************************************************************
//Define o Pino 13 como LED Vermelho L4
#define LED_VM_LD4 13
//Define o Pino 12 como LED Vermelho L3
#define LED_VM_LD3 12
//Define o Pino 11 como LED Vermelho L2
#define LED_VM_LD2 11
//Define o Pino 10 como LED Vermelho L1
#define LED_VM_LD1 10

//Define o Pino A4 como POT
#define POT A0


// Variaveis utilizadas na questao 1
//


//***************************************************************************
unsigned int leitura_potenciomentro = 0; //leitura do potenciometro 
unsigned int leitura_anterior_potenciometro = 0; //grava leitura anterior para comparacao


//***************************************************************************

//***************************************************************************
//QUESTÃO 2
//***************************************************************************
//Define o Pino 9 como LED Verde L4
#define LED_VR_LD4 9
//Define o Pino 8 como LED Verde L3
#define LED_VR_LD3 8
//Define o Pino 7 como LED Verde L2
#define LED_VR_LD2 7
//Define o Pino 6 como LED Verde L1
#define LED_VR_LD1 6

//Chaves de UP, DOWM e RST do Contador BCD
//Define o Pino 5 como Chave UP
#define CH_UP 5
//Define o Pino 4 como Chave DOWN
#define CH_DOWN 4
//Define o Pino 3 como Chave RST
#define CH_RST 3

// Variaveis utilizadas na questao 2
//

int botaoIncremental;
int botaoDecremental;
int botaoReset;
unsigned int contadorBinario;

//***************************************************************************


//***************************************************************************
//QUESTÃO 3
//***************************************************************************
//Pino de Leitura do LDR
//Define o Pino A5 como LDR
#define LDR A5

//LED de Alarme para indicar o acionamento da iluminação
#define LED_ALARME	2

// Variaveis utilizadas na questao 3
//

//***************************************************************************


//***************************************************************************
/*Função que serah executada somente uma unica vez no inicio*/
//***************************************************************************
void setup()
{

  //Define a velocidade de comunicacao da serial do monitor serial
  Serial.begin(9600); 
  
  //**************************************
  //LEDS questao 1
  pinMode(LED_VM_LD1, OUTPUT);
  pinMode(LED_VM_LD2, OUTPUT);
  pinMode(LED_VM_LD3, OUTPUT);
  pinMode(LED_VM_LD4, OUTPUT);
  
  leitura_anterior_potenciometro = leitura_potenciomentro;
  
  //***********************************
  //LEDS e bototes questao 2
  pinMode(LED_VR_LD1, OUTPUT);
  pinMode(LED_VR_LD2, OUTPUT);
  pinMode(LED_VR_LD3, OUTPUT);
  pinMode(LED_VR_LD4, OUTPUT);
  
  pinMode(CH_UP, INPUT);
  pinMode(CH_UP, INPUT);
  pinMode(CH_RST, INPUT);

}
//***************************************************************************


//***************************************************************************
/*Função que serah executada indefinidamente*/
//***************************************************************************
void loop() 
{
//***************************************************************************
//Questao 1
//***************************************************************************
   leitura_potenciomentro = analogRead(POT); //leitura valor potenciometro
  
  //
  if(leitura_anterior_potenciometro != leitura_potenciomentro){ 
    Serial.print("VALOR POTENCIMETRO: ");
    Serial.println(leitura_potenciomentro);  
 
 //LEDS DESLIGADOS
  if(leitura_potenciomentro > 0 && leitura_potenciomentro < 200){
	  digitalWrite(LED_VM_LD1, LOW);
	  digitalWrite(LED_VM_LD2, LOW);
	  digitalWrite(LED_VM_LD3, LOW);
	  digitalWrite(LED_VM_LD4, LOW);
	  
  //ACENDER PRIMEIRO LED
  } else if (leitura_potenciomentro > 200 && leitura_potenciomentro < 400){
	  digitalWrite(LED_VM_LD1, HIGH);
	  digitalWrite(LED_VM_LD2, LOW);
	  digitalWrite(LED_VM_LD3, LOW);
	  digitalWrite(LED_VM_LD4, LOW);
	  
  //ACENDE PRIMEIRO, SEGUNDO LEDS
  }else if (leitura_potenciomentro > 400 && leitura_potenciomentro < 600){
	  digitalWrite(LED_VM_LD1, HIGH);
	  digitalWrite(LED_VM_LD2, HIGH);
	  digitalWrite(LED_VM_LD3, LOW);
	  digitalWrite(LED_VM_LD4, LOW);
	  
  //ACENDE PRIMEIRO, SEGUNDO E TERCEIRO LED
  } else if (leitura_potenciomentro > 600 && leitura_potenciomentro < 800){
	  digitalWrite(LED_VM_LD1, HIGH);
	  digitalWrite(LED_VM_LD2, HIGH);
	  digitalWrite(LED_VM_LD3, HIGH);
	  digitalWrite(LED_VM_LD4, LOW);
	  
  //ACENDE TODOS OS LEDS
  } else if (leitura_potenciomentro > 800 && leitura_potenciomentro < 1023){
	  digitalWrite(LED_VM_LD1, HIGH);
	  digitalWrite(LED_VM_LD2, HIGH);
	  digitalWrite(LED_VM_LD3, HIGH);
	  digitalWrite(LED_VM_LD4, HIGH);
  }
  

    //SETAR VALOR LIDO PARA QUANDO MUDAR, ENTRAR NO IF
    //(CASO NAO TER ISSO E O IF, LERA INFINITO)
  	leitura_anterior_potenciometro = leitura_potenciomentro;    
  }  
  
//***************************************************************************  

  
//***************************************************************************
//Questao 2
//***************************************************************************
  botaoIncremental = digitalRead(CH_UP);
  delay(50);
  botaoDecremental = digitalRead(CH_DOWN);
  delay(50);
  botaoReset = digitalRead(CH_RST);
  
  if(botaoReset == 1){
	botaoIncremental = 0;
	botaoDecremental = 0;
	contadorBinario = 0;	
  }else if(botaoIncremental == 1){
	contadorBinario++; //Incrementa contador binario
	botaoDecremental = 0; //Coloca estado da variavel do botao incrementador para 0
  } else if (botaoDecremental == 1){
	if(contadorBinario > 0) contadorBinario--;
	botaoIncremental = 0; //Coloca estado da variavel do botao descrementador para 0
  }
  
  if(contadorBinario > 9) { //Se conta
	contadorBinario = 0; 
  }
  
  if (contadorBinario == 0) {
    digitalWrite(LED_VR_LD1, LOW);
    digitalWrite(LED_VR_LD2, LOW);
	digitalWrite(LED_VR_LD3, LOW);
    digitalWrite(LED_VR_LD4, LOW);
  }
  //Caso for 1 bit, acender apenas LED da esquerda
  else if (contadorBinario == 1) {
    digitalWrite(LED_VR_LD1, LOW);
    digitalWrite(LED_VR_LD2, LOW);
	digitalWrite(LED_VR_LD3, LOW);
    digitalWrite(LED_VR_LD4, HIGH);
  }
  //Caso for 2 bits
  else if (contadorBinario == 2) {
    digitalWrite(LED_VR_LD1, LOW);
    digitalWrite(LED_VR_LD2, LOW);
	digitalWrite(LED_VR_LD3, HIGH);
    digitalWrite(LED_VR_LD4, LOW);
  }
  //Caso for 3 bits
  else if (contadorBinario == 3) {
    digitalWrite(LED_VR_LD1, LOW);
    digitalWrite(LED_VR_LD2, LOW);
	digitalWrite(LED_VR_LD3, HIGH);
    digitalWrite(LED_VR_LD4, HIGH);
  }
  
  //Caso for 4 bits
  else if (contadorBinario == 4) {
    digitalWrite(LED_VR_LD1, LOW);
    digitalWrite(LED_VR_LD2, HIGH);
	digitalWrite(LED_VR_LD3, LOW);
    digitalWrite(LED_VR_LD4, LOW);
  }
  
  //Caso for 5 bits
  else if (contadorBinario == 5) {
    digitalWrite(LED_VR_LD1, LOW);
    digitalWrite(LED_VR_LD2, HIGH);
	digitalWrite(LED_VR_LD3, LOW);
    digitalWrite(LED_VR_LD4, HIGH);
  }
  
  //Caso for 6  bits
  else if (contadorBinario == 6) {
    digitalWrite(LED_VR_LD1, LOW);
    digitalWrite(LED_VR_LD2, HIGH);
	digitalWrite(LED_VR_LD3, HIGH);
    digitalWrite(LED_VR_LD4, LOW);
  }
  
  //Caso for 7 bits
  else if (contadorBinario == 7) {
    digitalWrite(LED_VR_LD1, LOW);
    digitalWrite(LED_VR_LD2, HIGH);
	digitalWrite(LED_VR_LD3, HIGH);
    digitalWrite(LED_VR_LD4, HIGH);
  }
 
  //Caso for 8 bits
  else if (contadorBinario ==  8) {
    digitalWrite(LED_VR_LD1, HIGH);
    digitalWrite(LED_VR_LD2, LOW);
	digitalWrite(LED_VR_LD3, LOW);
    digitalWrite(LED_VR_LD4, LOW);
  }

  //Caso for 9 bits
  else if (contadorBinario == 9) {
    digitalWrite(LED_VR_LD1, HIGH);
    digitalWrite(LED_VR_LD2, LOW);
	digitalWrite(LED_VR_LD3, LOW);
    digitalWrite(LED_VR_LD4, HIGH);
  }
  
    delay(100);

//***************************************************************************    


//***************************************************************************
//Questao 3
//***************************************************************************
  
//***************************************************************************  
}
