#include <Arduino.h>



#define Solanoid_Pin 3


void setup(){
pinMode(Solanoid_Pin,OUTPUT);
}


void loop(){
while (Serial.available()) 
  {
    switch( (char)Serial.read())
    {
      case 'w':
        an
        break;
      case 's':
      
        
        break;

    }

  }
}