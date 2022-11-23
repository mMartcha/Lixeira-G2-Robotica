#include <Servo.h>
Servo servo;     
int trigPin = 5;    
int echoPin = 6;   
int servoPin = A0;
long duracao, distancia, average;   
long aver[3];  


void setup() {       
    Serial.begin(9600);
    servo.attach(servoPin);  
    pinMode(trigPin, OUTPUT);  
    pinMode(echoPin, INPUT);  
    servo.write(0);        
    delay(100);
    servo.detach(); 
} 

void measure() {  
  digitalWrite(10,HIGH);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(15);
  digitalWrite(trigPin, LOW);
  pinMode(echoPin, INPUT);
  duracao = pulseIn(echoPin, HIGH);
  distancia = (duracao/2) / 29.1;   
}
void loop() { 
  for (int i=0;i<=2;i++) {   
    measure();               
   aver[i]=distancia;            
    delay(10);             
  }
 distancia=(aver[0]+aver[1]+aver[2])/3;    

if ( distancia < 35 ) {
 servo.attach(servoPin);
 delay(1);
 servo.write(0);  
 delay(10000);       
 servo.write(65);    
 delay(10000);
 servo.write(0);
 delay(1);
 servo.detach();      
}
Serial.println(distancia);
} 