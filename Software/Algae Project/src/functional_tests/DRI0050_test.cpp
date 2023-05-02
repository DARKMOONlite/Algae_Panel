#include <Arduino.h>
#include <DRI0050.h>


const int DRItx = 12;
const int DRIrx = 13;
unsigned int DutyCycle = 50;
DRI0050 Pump;

void setup(){
Pump.setPwmDuty(100);
Pump.setPwmFreq(10);
Serial.begin(9600);
}


void loop(){
    
while (Serial.available()) 
  {
    switch( (char)Serial.read())
    {
      case 'w':
        DutyCycle +=10;
        if(DutyCycle>=100){DutyCycle=100;}
        Serial.print("Duty Cycle Increased to :");
        Serial.println(DutyCycle);
        break;
      case 's':
      
        DutyCycle -=10;
        if(DutyCycle<0){DutyCycle=0;}
        break;

    }
    Serial.print("Duty Cycle :");
    Serial.println(DutyCycle);
  }

}