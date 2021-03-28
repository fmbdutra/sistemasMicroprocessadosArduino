/*
Experiência 1

Implementar um Sketch que acenda e apague o LED a cada 500ms.

Usando:
1 LED vermelho 5mm
1 resistor 220Ohms
Fios jumpers;
1 protoboard
Arduino UNO 
*/

// Define pino do LED 
int pinoLed = 2;

void setup()
{
  //Define tipo de ligação do pinoLed (2)
  pinMode(pinoLed, OUTPUT);
}

void loop()
{
  //Definindo modo de escrita no pinoLed(2) para ligar
  digitalWrite(pinoLed, HIGH);
  delay(500); // aguarda 500 millisecondos
  
 //Definindo modo de escrita no pinoLed(2) para desligar
  digitalWrite(pinoLed, LOW);
  delay(500); // aguarda for 500 millisecondos
  
}
