#include <Servo.h>

Servo myservo;

void setup() 
{
  Serial.begin(9600);
  pinMode(3, OUTPUT);
  myservo.attach(2);
  
  digitalWrite(3,LOW);  // Disable RS485 Transmit      

}

int dataservo;
void loop()
{
  if (Serial.available()) 
  {
    dataservo = Serial.read(); 
    myservo.write(dataservo);
  }
  delay(100);
}

