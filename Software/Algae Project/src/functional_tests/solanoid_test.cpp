#include <Arduino.h>



#define Solanoid_Pin 3


void setup(){
pinMode(Solanoid_Pin,OUTPUT);
Serial.begin(9600);
}


void loop(){
while (Serial.available()) 
  {
    switch( (char)Serial.read())
    {
      case 'w':
        Serial.print("Opening Solanoid Valve \n");
        digitalWrite(Solanoid_Pin,HIGH);
        break;
      case 's':
        Serial.print("Closing Solanoid Valve \n");
        digitalWrite(Solanoid_Pin,LOW);


      
        
        break;

    }

  }
}