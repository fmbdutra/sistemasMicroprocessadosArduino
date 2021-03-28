/*
  Experiência 3 - 2
  Implementar um programa que controle dois LEDs
  a partir de duas
  chaves ligadas a duas entradas digitais da
  seguinte maneira:

  Os dois LEDs devem funcionar como um indicador
  binário iniciando
  em 00 (os dois LEDs apagados) até
  11 (os dois LEDs ligados).
  A – Cada vez que a chave 1 for pressionada o
  indicador binário
  incrementa um valor.
  B – Cada vez que a chave 2 for pressionada o
  indicador binário
  decrementa um valor.
  C – Se a chave 1 e chave 2 forem pressionadas
  ao mesmo tempo,
  o indicador binário resetará.
  D – Se o indicador binário já estiver
  resetado e a chave 1 e chave 2
  forem pressionadas ao mesmo tempo, o indicador binário
  deverá setar os LEDs (11).

*/

int tamanhoBinario = 0;
int estadoBotaoA;
int estadoBotaoB;


void setup()
{
  pinMode(12, OUTPUT); //Pino LED A
  pinMode(10, OUTPUT); //Pino LED B
  pinMode(2, INPUT); //Pino Incrementador
  pinMode(4, INPUT); //Pino Decrementador

  //Apenas para verificar se os 2 botões foram pressionados ao mesmo tempo
  pinMode(13, OUTPUT); //Pino LED Placa

  //Inicializa monitor serial com 9600 bits por segundo
  Serial.begin(9600);
}



void loop()
{

  estadoBotaoA = digitalRead(2);
  delay(200);
  estadoBotaoB = digitalRead(4);
  delay(200);



  /*
    Dois botões pressionados ao mesmo tempo e valor
    igual a 0 - LEDs desligados (D)
  */
  if (tamanhoBinario == 0 &&
      (estadoBotaoA == HIGH && estadoBotaoB == HIGH)) {

    //Aqui para ver se foi os 2 pressionados ligar, o LED da placa
    digitalWrite(13, HIGH);
    digitalWrite(10, HIGH);
    digitalWrite(12, HIGH);
    delay(1000);
    digitalWrite(13, LOW);


    Serial.println("Indicador já resetado"); //Imprime no monitor
    delay(2000); //Para não ir muito rápido e já ir para a parte C do exercício
    acendeLeds(tamanhoBinario);

  }

  /*
    Dois botões pressionados ao mesmo tempo e valor
    maior que 0 - LEDs acesos (C)
  */
  else if (tamanhoBinario != 0 &&
           (estadoBotaoA == HIGH && estadoBotaoB == HIGH)
          ) {
    tamanhoBinario = 0;
    //Aqui para ver se foi os 2 pressionados ligar, o LED da placa
    digitalWrite(13, HIGH);
    digitalWrite(10, LOW);
    digitalWrite(12, LOW);
    delay(1000);
    digitalWrite(13, LOW);

    Serial.println("Indicador resetado"); //Imprime no monitor
    delay(2000); //Para não ir muito rápido e já ir para a parte D do exercício
    acendeLeds(tamanhoBinario);

  }


  /*
    Se botão 2 for pressionado e o 4 não for,
    incrementar o contador binário (A)
  */
  else if (estadoBotaoA == HIGH && estadoBotaoB == LOW) {
    Serial.println("Incrementa"); //Imprime no monitor

    //Abaixo, verifica para não incrementar para maior que 3
    if (tamanhoBinario < 3) {
      tamanhoBinario = tamanhoBinario + 1;
      delay(500); //Delay de 500 milisegundos para esperar
      acendeLeds(tamanhoBinario);
    }


  }
  /*
    Se botão 4 for pressionado e o 2 não for,
    descrementar o contador binário (B)
  */
  else if (estadoBotaoB == HIGH && estadoBotaoA == LOW) {
    //Abaixo, verifica para não decrementar para menos de 0
    Serial.println("Decrementa"); //Imprime no monitor
    if (tamanhoBinario > 0) {
      tamanhoBinario = tamanhoBinario - 1;
      delay(500); //Delay de 500 milisegundos para esperar
      acendeLeds(tamanhoBinario);
    }
  }
}

void acendeLeds(int tamanoBinario) {
  //Caso for 0 bit, apagar os 2 LEDS
  if (tamanhoBinario == 0) {
    Serial.println("0 BIT");
    digitalWrite(12, LOW);
    digitalWrite(10, LOW);
  }
  //Caso for 1 bit, acender apenas LED da esquerda
  else if (tamanhoBinario == 1) {
    Serial.println("1 BIT");
    digitalWrite(10, HIGH);
    digitalWrite(12, LOW);
  }
  //Caso for 1 bits, acender apenas LED da direita
  else if (tamanhoBinario == 2) {
    Serial.println("2 BIT");
    digitalWrite(10, LOW);
    digitalWrite(12, HIGH);
  }
  //Caso for 3 bits, acender os 2 LEDs
  else if (tamanhoBinario >= 3) {
    Serial.println("3 BIT");
    digitalWrite(10, HIGH);
    digitalWrite(12, HIGH);
  }

}
