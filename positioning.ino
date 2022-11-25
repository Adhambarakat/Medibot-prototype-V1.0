#include <heartRate.h>
#include <MAX30105.h>
#include <spo2_algorithm.h>
#include <Wire.h>
MAX30105 sensor;
int beats[10];
float beat = 0;
int avgbpm = 0;
int i = 0;
int arrayindex =0; 
int x =0;
int val; //value recieved from the pi
#define front_right 3;
#define back_right 6;
#define front_left 9;
#define back_left 10;

void setup() {
  Serial.begin(9600);
  Serial.begin(115200);
  sensor.begin(Wire , I2C_SPEED_FAST);
  sensor.setup();
  sensor.enableDIETEMPRDY();
}

void loop() {
   digitalWrite(5,LOW);
  delayMicroseconds(2);
  digitalWrite(5,HIGH);
  delayMicroseconds(10);
  int interval = pulseIn(4,HIGH);

int distance = interval * 0.0343/2;
Serial.println(interval);
Serial.println("distance = ");
Serial.println(distance);
delay(2000);

int val = Serial.read();  

if(val = 1){
 digitalWrite(3, HIGH);
 digitalWrite(6, LOW);
 digitalWrite(9, LOW);
 digitalWrite(10, HIGH);
 delay(); // not measured yet

}
else if(val = 2){
     digitalWrite(3, LOW);
     digitalWrite(6, HIGH);
     digitalWrite(9, HIGH);
     digitalWrite(10, LOW);
     delay(); //not measured yet
     digitalWrite(3,HIGH);
     digitalWrite(6,LOW);
     digitalWrite(9,HIGH);
     digitalWrite(10,LOW);
     


}

}
