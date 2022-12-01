void front(){
  digitalWrite(5,HIGH);
  digitalWrite(6,LOW);
  digitalWrite(9,HIGH);
  digitalWrite(10,LOW);
}


void back(){
  digitalWrite(5,LOW);
  digitalWrite(6,HIGH);
  digitalWrite(9,LOW);
  digitalWrite(10,HIGH);
}

void Stop(){
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
  digitalWrite(9,LOW);
  digitalWrite(10,LOW);
}

void right(){
  digitalWrite(5,LOW);
  digitalWrite(6,HIGH);
  digitalWrite(9,HIGH);
  digitalWrite(10,LOW);
}

void left(){
  digitalWrite(5,HIGH);
  digitalWrite(6,LOW);
  digitalWrite(9,LOW);
  digitalWrite(10,HIGH);
}


void setup() {
  Serial.begin(9600);
pinMode(3,INPUT);
pinMode(4,OUTPUT);
pinMode(5,OUTPUT);
pinMode(6,OUTPUT);
pinMode(9,OUTPUT);
pinMode(10,OUTPUT);
}

void loop() {
  digitalWrite(4,LOW);
  delayMicroseconds(12);
  digitalWrite(4,HIGH);
  delayMicroseconds(2);
  double t = pulseIn(3,HIGH);
  long dist = t*0.0294/2;



  if (Serial.read() == 1){
    right();
    delay(10000);
    Serial.println("right");
    }
    
    else if(Serial.read() == 2){
      left();
      delay(2000);
      if(dist > 10){
        front();
      }else{Stop();}
    }
  

  
}



