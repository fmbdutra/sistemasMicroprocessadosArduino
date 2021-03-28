/*
  Experiência 2 - Parte 1

  Implementar um Sketch que controle duas saídas
  digitais da seguinte maneira:

  A – Quando a saída 1 estiver ligada a saída 2
  deve estar desligada.

  B – Quando a saída 2 estiver ligada a saída 1
  deve estar desligada.

  C – A saída 1 deve permanecer ligada por 600 ms
  e permanecer
  desligada durante 400 ms.

  D – A saída 2 deve permanecer ligada durante 400 ms
  e
  permanecer desligada durante 600 ms.

  E – Repetir a execução acima com os tempos de ligado
  e desligado
  das saídas 1 e 2 invertidos.

*/

/*
  Saídas ligadas conforme sequência:
  jumper - resistor 220hms - LED - GND Arduino,
  tudo em uma protoboard
*/

//Dando nomes aos pinos de saída
int pinoSaida1 = 12;
int pinoSaida2 = 11;


void setup()
{
  //Definindo os pinos como saída (OUTPUT)
  pinMode(pinoSaida1, OUTPUT);
  pinMode(pinoSaida2, OUTPUT);
}

void loop() { //A até D
  digitalWrite(pinoSaida1, HIGH); //Liga saída 1
  digitalWrite(pinoSaida2, LOW); //desliga saída 2
  delay(600); // Permanece essas definições acima por 600 milisegundos

  digitalWrite(pinoSaida1, LOW); //Desliga saída 1
  digitalWrite(pinoSaida2, HIGH); //liga saída 2
  delay(400); //Permanece essas definições acima por 400 milisegundos.

}

/*

void loop(){ //E
  digitalWrite(pinoSaida1, HIGH); //Liga saída 1
  digitalWrite(pinoSaida2, LOW); //desliga saída 2
  delay(400); // Permanece essas definições acima por 400 milisegundos

  digitalWrite(pinoSaida1, LOW); //Desliga saída 1
  digitalWrite(pinoSaida2, HIGH); //liga saída 2
  delay(600); //Permanece essas definições acima por 600 milisegundos.
}
*/
