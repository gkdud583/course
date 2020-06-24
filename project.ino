#include<Servo.h>

Servo servo1;
Servo servo2;
int servopin1=10;
int servopin2=11;
int echo = 13;
int trig = 12;
int buzzerpin=5;
int ledpin=7;
int pirpin=2;

int j=180;


void setup(){
  
  Serial.begin(9600);
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  pinMode(ledpin,OUTPUT);
  pinMode(pirpin,INPUT);
  pinMode(buzzerpin,OUTPUT);
 
  pinMode(servopin1,OUTPUT);
  

  pinMode(servopin2,OUTPUT);
 

  
}

void loop(){
  
  
    if(digitalRead(pirpin))
   {
    Serial.println("piron");
    
     servo1.attach(servopin1);
     servo2.attach(servopin2);
      servo1.write(135);
       servo2.write(20);
       delay(200);
       servo1.write(20);
       servo2.write(135);
       delay(200);
     
     servo1.detach();
     servo2.detach();
  
      
      delay(3000); // 3초 delay 줘서 인체감지 모듈 중복 인식해도 서보모터는 한번만 돌리도록 함 그래도 문제 해결안되면 시간을 길게 주면 o 

      
   }     
     
   
 
  digitalWrite(trig,LOW);
  delayMicroseconds(3);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);

  unsigned long duration = pulseIn(echo,HIGH);
 
  float distance = ( (float)(340*duration) / 10000) / 2;


   Serial.println(distance);
  if(distance <= 13){
   
    
  digitalWrite(ledpin,LOW);
  noTone(buzzerpin);

  }
  else{
    digitalWrite(ledpin,HIGH);
    tone(buzzerpin,1000); //1KHz소리신호
    delay(1000);
    noTone(buzzerpin);
    delay(1000);
  }
  
 
}
