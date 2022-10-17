#include "MAX30105.h"

MAX30105 sensor;


void setup() {
 Serial.begin(9600);
 sensor.begin(Wire, I2C_SPEED_FAST);
 
  

 sensor.setup();
 sensor.enableDIETEMPRDY();

}

void loop() {
  float temperature = sensor.readTemperature();
  Serial.println(temperature+3);
  

}
