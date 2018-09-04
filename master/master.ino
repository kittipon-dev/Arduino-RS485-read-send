#include <SoftwareSerial.h>

SoftwareSerial RS485Serial(10, 11); // RX, TX

int byteSend,readA,ref,angulo;

void setup()
{
  Serial.begin(9600);
  pinMode(2, OUTPUT);
  pinMode(A0, INPUT);     
  digitalWrite(2,HIGH); 
  RS485Serial.begin(9600);

}

void loop()
{
  
/*
    if (Serial.available()) {
        digitalWrite(2,HIGH);
        RS485Serial.write(Serial.read());
        delay(10);
        digitalWrite(2, LOW);
    }
*/

    readA=analogRead(A0);
    angulo=map(readA,0,1023,0,180);
    if(angulo!=ref){
    Serial.println(angulo);
    digitalWrite(2,HIGH);  // Enable RS485 Transmit   
    RS485Serial.write(angulo);          // Send byte to Remote Arduino 
    delay(10);
    digitalWrite(2, LOW);  // Disable RS485 Transmit 
    ref=angulo;
    }
    delay(100);
    
    
}
