/* Code ini saya ambil dari salah satu channel youtube
 *  
 */

#include <Servo.h>
const int trigPin = 9; // pin trig pada ultrasonik ke pin 9 arduino
const int echoPin = 10; // pin echo pada ultrasonik ke pin 10 arduino
long duration;
int distance;

Servo myServo;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
  myServo.attach(8); // pin servo ke pin 8 arduino
}

void loop() {
  for(int i=0;i<=180;i++){  
    myServo.write(i);
    delay(10);
    distance = calculateDistance();
    
    Serial.print(i);
    Serial.print(",");
    Serial.print(distance);
    Serial.print(".");
  }
  
  for(int i=180;i>0;i--){  
    myServo.write(i);
    delay(10);
    distance = calculateDistance();
    Serial.print(i);
    Serial.print(",");
    Serial.print(distance);
    Serial.print(".");
  }
}

int calculateDistance(){ 
  
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance= duration*0.034/2;
  return distance;
}
