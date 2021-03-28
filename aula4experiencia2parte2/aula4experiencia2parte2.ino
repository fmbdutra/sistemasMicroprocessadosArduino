/*
Experiência 2 - Parte 2

Implementar um Sketch que controle três saídas 
digitais da seguinte
maneira:

A – Quando a saída 1 estiver ligada as 
saídas 2 e 3 devem estar
desligadas.

B – Quando a saída 2 estiver ligada as 
saídas 1 e 3 devem estar
desligadas.

C – Quando a saída 3 estiver ligada as 
saídas 1 e 2 devem estar
desligadas.

D – Intervalo de tempo de cada saída ligada 
igual 300 ms.

E – Repetir a execução acima com um intervalo de 
tempo de 100 ms.

*/

/*
Usado ligação de saída - resistor 220ohms - LED - GND 
no protoboard em todas as saídas;
*/

//Dando nomes aos pinos de saída
int pinoSaida1 = 12;
int pinoSaida2 = 11;
int pinoSaida3 = 10;


void setup()
{
  //Definindo os pinos como saída (OUTPUT)
  pinMode(pinoSaida1, OUTPUT);
  pinMode(pinoSaida2, OUTPUT);
  pinMode(pinoSaida3, OUTPUT);

}

void loop(){ //A até D
  digitalWrite(pinoSaida1, HIGH); //Liga saída 1
  digitalWrite(pinoSaida2, LOW); //Desliga saída 2
  digitalWrite(pinoSaida3, LOW); //Desliga saída 3

  delay(300);// Permanece estados acima por 300 milisegundos
  //***********************
  digitalWrite(pinoSaida1, LOW); //Desliga saída 1
  digitalWrite(pinoSaida3, LOW); //Desliga saída 3
  digitalWrite(pinoSaida2, HIGH); //liga saída 2

  delay(300);// Permanece estados acima por 300 milisegundos
  //*****************************
    
  digitalWrite(pinoSaida1, LOW); //Desliga saída 1
  digitalWrite(pinoSaida2, LOW); //Desliga saída 2
  digitalWrite(pinoSaida3, HIGH); //liga saída 3

  delay(300);// Permanece estados acima por 300 milisegundos   
}

/*
void loop(){ //Parte E

  digitalWrite(pinoSaida1, HIGH); //Liga saída 1
  digitalWrite(pinoSaida2, LOW); //Desliga saída 2
  digitalWrite(pinoSaida3, LOW); //Desliga saída 3

  delay(100); // Permanece estados acima por 100 milisegundos
  //***********************
  digitalWrite(pinoSaida1, LOW); //Desliga saída 1
  digitalWrite(pinoSaida3, LOW); //Desliga saída 3
  digitalWrite(pinoSaida2, HIGH); //liga saída 2

  delay(100);// Permanece estados acima por 100 milisegundos
  //*****************************
    
  digitalWrite(pinoSaida1, LOW); //Desliga saída 1
  digitalWrite(pinoSaida2, LOW); //Desliga saída 2
  digitalWrite(pinoSaida3, HIGH); //liga saída 3

  delay(100);// Permanece estados acima por 100 milisegundos 
}
*/
