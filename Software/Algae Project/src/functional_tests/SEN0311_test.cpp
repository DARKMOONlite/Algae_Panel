
#include <Arduino.h>
#include <SoftwareSerial.h>



SoftwareSerial USSerial(11,10);
unsigned char data[4]={};
float distance;

void setup(){
    Serial.begin(9600);
    USSerial.begin(9600);



    


}


void loop(){
    do{
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
      }else Serial.println("ERROR");
     }
     delay(100);
}



