#include <MPU9250_asukiaaa.h> // Inlcuindo Biblioteca específica 

MPU9250_asukiaaa mySensor;

float gX, gY, gZ; // Declarando variáveis referentes ao espaço tridimensional do Giroscópios

void setup() {
  
  Serial.begin(115200);  // Iniciando o Monitor Serial com taxa de transmissão de 115200
  while(!Serial);
  Serial.println("Iniciado"); //Mensagem pra mostrar que foi iniciado
  
  Wire.begin();
  mySensor.setWire(&Wire);
  mySensor.beginGyro();
}

void loop() {
  mySensor.gyroUpdate();  //Atualização da captação de dados
  
  gX = mySensor.gyroX();  //Eixo X
  gY = mySensor.gyroY();  //Eixo Y
  gZ = mySensor.gyroZ();  // Eixo Z 

  Serial.println("gyroX: " + String(gX)); // Printando dados
  Serial.println("gyroY: " + String(gY));
  Serial.println("gyroZ: " + String(gZ));
}