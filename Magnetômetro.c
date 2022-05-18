#include <MPU9250_asukiaaa.h> //Incluindo Biblioteca específica pro sensor

MPU9250_asukiaaa mySensor;

float mDirection;

uint16_t mX, mY, mZ;  //ver q porra é essa

void setup() {
  Serial.begin(115200);  // Iniciando o Monitor Serial com taxa de transmissão de 115200
  while(!Serial);
  Serial.println("Iniciado"); //Mensagem pra mostrar que foi iniciado
  
  Wire.begin();
  mySensor.setWire(&Wire);
  mySensor.beginMag();  //Iniciando a seção do magnetômetro 
}

void loop() {
  mySensor.magUpdate(); //Atualização da captação de dados do Magnetômetro 
  
  mX = mySensor.magX(); //Eixo X 
  mY = mySensor.magY(); //Eixo Y
  mZ = mySensor.magZ(); //Eixo Z
  mDirection = mySensor.magHorizDirection();

  Serial.println("magX: " + String(mX));
  Serial.println("magY: " + String(mX));
  Serial.println("magZ: " + String(mX));
  Serial.println("Direção Horizontal: " + String(mX));
}