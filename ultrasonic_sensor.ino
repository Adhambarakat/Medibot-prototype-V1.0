#include <Servo.h>
Servo servo;

void setup(){
  Serial.begin(9600);
  pinMode(4, INPUT);
  pinMode(5, OUTPUT);
  pinMode(3, OUTPUT); //right high
  pinMode(9, OUTPUT); //right low
  pinMode(10, OUTPUT); //left high 
  pinMode(11, OUTPUT); //left low
  servo.attach(6);

  

}


void loop(){
  front();
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

int pos = 0;
for(pos = 0;  pos <= 180;  pos++){
  servo.write(pos);
  delay(10);

}
for(pos = 180;  pos >= 0; pos--){
  servo.write(pos);
  delay(10);
  Serial.println(pos);

}

if(pos = 90 && distance <= 5){
Serial.println("obstacleFront");
back();
delay(50);
right();
delay(50);
front();
}

if(pos <= 90 && distance <= 5){
  Serial.println("obstacleRight");
  left();
  delay(50);
  front();
}
if(pos >= 90 && distance <= 5){
  Serial.println("obstacleLeft");
  right();
  delay(50);
  front();
}



  

}

void front(){
  digitalWrite(3, HIGH);
  digitalWrite(9, LOW);
  digitalWrite(10, HIGH);
  digitalWrite(11,LOW);
}
void back(){
  digitalWrite(3, LOW);
  digitalWrite(9, HIGH);
  digitalWrite(10, LOW);
  digitalWrite(11, HIGH);
}

void right(){
  digitalWrite(3, LOW);
  digitalWrite(9, HIGH);
  digitalWrite(10, HIGH);
  digitalWrite(11, LOW); 
}

void left(){
  digitalWrite(3, HIGH);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, HIGH);
}


 
