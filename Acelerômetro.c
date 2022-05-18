#include <MPU9250_asukiaaa.h>  //Incluindo Biblioteca específica pro sensor

MPU9250_asukiaaa mySensor;

float aX, aY, aZ, aSqrt;  // Declarando variáveis referentes ao ambiente tridimensional

void setup() {
  Serial.begin(115200);  // Iniciando o Monitor Serial com taxa de transmissão de 115200
  while(!Serial);
  Serial.println("Iniciado"); //Mensagem pra mostrar que foi iniciado
  
  Wire.begin();  
  mySensor.setWire(&Wire);
  mySensor.beginAccel(); // Iniciando a seção do Acelerômetro no sensor (ISOLADO)
}

void loop() {
  mySensor.accelUpdate();  //Atualização da captação de dados
  
  aX = mySensor.accelX(); //Eixo X
  aY = mySensor.accelY(); //Eixo Y
  aZ = mySensor.accelZ(); // Eixo Z 
  aSqrt = mySensor.accelSqrt(); // Ac. Angular 

  Serial.println("accelX: " + String(aX)); //Printando dados
  Serial.println("accelY: " + String(aY));
  Serial.println("accelZ: " + String(aZ));
  Serial.println("accelSqrt: " + String(aSqrt));
}