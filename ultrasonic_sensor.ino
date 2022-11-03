#include <Servo.h>
Servo servo;
  int limit = 10;


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
  //ultrasonic sensor
  digitalWrite(5,LOW);
  delayMicroseconds(2);
  digitalWrite(5,HIGH);
  delayMicroseconds(10);
  int interval = pulseIn(4,HIGH);

int distance = interval * 0.0343/2;
Serial.println(interval);
Serial.println("distance = ");
Serial.println(distance);

//servo and positioning
int pos = 0;
servo.write(0);

if(distance>limit){
  do{
    front();
  }while(distance>limit);
  
}else if(distance<limit){

  do{

    back();
    servo.write(90);
  }while(distance<limit);
}
    if(distance>limit){
      do{
        left();
        delay(2000);
        front();
      }while(distance>limit);
    }else if(distance<limit){
      do{
        servo.write(180);
      }while(distance<limit);
    }
        if(distance>limit){
          do{
            right();
            delay(2000);
            front();
          }while(distance>limit);
        }else if(distance<limit){
          do{
            back();
            delay(4000);
            right();
            delay(2000);
            front();
          }while(distance<limit);
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


 
