#ifndef SEN0311_H
#define SEN0311_H
#include <Arduino.h>
#include <SoftwareSerial.h>


class SEN0311{
public:
SEN0311(int tx, int rx):
USSerial(tx,rx){
USSerial.begin(9600);
}


float get_dist(){
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
           return(distance);
          }else 
             {
               Serial.println("Below the lower limit");
               return(0);
             }
      }else {Serial.println("ERROR"); return(-1);}
     }
    
}

private:

SoftwareSerial USSerial;
unsigned char data[4]={};
double distance;
};


#endif