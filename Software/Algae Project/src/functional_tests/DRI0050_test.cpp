#include <Arduino.h>
#include <DRI0050.h>


const int DRItx = 50;
const int DRIrx = 51;
unsigned int DutyCycle = 100;
DRI0050 Pump(DRItx,DRIrx);
bool ON = false;
void setup(){
Pump.setPwmDuty(255);
delay(50);
Pump.setPwmFreq(10);
delay(50);
Pump.setPwmEnable(PWM_ENABLE);
delay(50);
Serial.begin(9600);
Serial.print("Waiting for Input");
pinMode(LED_BUILTIN,OUTPUT);
}


void loop(){
    delay(10000);
    ON=!ON;
    digitalWrite(LED_BUILTIN,ON);
    Pump.setPwmEnable(ON);
// while (Serial.available()) 
//   {
//     switch( (char)Serial.read())
//     {
//       case 'w':
//         DutyCycle +=10;
//         if(DutyCycle>=250){DutyCycle=250;}
//         break;
//       case 's':
      
//         DutyCycle -=10;
//         if(DutyCycle<0){DutyCycle=0;}
//         break;
//         case 'x':
//         ON = !ON;
//         Serial.print("Pump Turned :");
//         Serial.println(ON);
//         if(ON){
//           Pump.setPwmEnable(PWM_ENABLE);
//         }
//         else{
//           Pump.setPwmEnable(PWM_DISENABLE);
//         }
       

//     }
//     Pump.setPwmDuty(DutyCycle);
//     Serial.print("Duty Cycle :");
//     Serial.println(DutyCycle);
//   }
  
}