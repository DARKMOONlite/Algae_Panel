#include <Arduino.h>
#include <SoftwareSerial.h>

// Define connections to sensor
int pinRX = 15; // WHITE/GREEN CABLE - 4TH CABLE (Vcc, GND, TX (YELLOW), RX (WHITE))
int pinTX = 14; // YELLOW/BLUE CABLE - 3RD CABLE (Vcc, GND, TX (YELLOW), RX (WHITE))


SoftwareSerial USSerial(pinRX, pinTX);
unsigned char data[4]={};
float distance = 0.0;

void setup(){
    Serial.begin(9600);
    USSerial.begin(9600);
}


void loop(){
    do{
     delay(4);

     for(int i=0;i<4;i++)
     {
       data[i]=USSerial.read();
     }
  }while(USSerial.read()==0xff);

  USSerial.flush();

  if(data[0]==0xff)
    {
      int sum;
      sum=(data[0]+data[1]+data[2])&0x00FF;
      if(sum==data[3])
      {
        distance=(data[1]<<8)+data[2];
        if(distance>30)
          {
           Serial.print("distance=");
           Serial.print(distance/10);
           Serial.println("cm");
          }else 
             {
               Serial.println("Below the lower limit");
             }
      }
      else
      {
        Serial.println(data[3]);
        Serial.println(sum);
      }
     }
     else
     {
      Serial.println(data[0]);
     }
     delay(100);
}