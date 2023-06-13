#ifndef SEN0311_H
#define SEN0311_H
#include <Arduino.h>
#include <SoftwareSerial.h>

// Class for the waterproof ULTRASONIC SENSOR - A02YYUW (DFRobot Sen-0311)
class SEN0311{

public:
  // Constructor
  SEN0311(int rx, int tx):
  USSerial(rx,tx)
  {
    USSerial.begin(9600);
  }

/*
  Description:
  This function reads data from the Ultrasonic Sensor Serial, checks if it is valid,
  and then returns the data as a distance in centimetres given it is valid.
*/
float get_dist()
{
  // While the Ultrasonic Sensor Serial is ready to be read, read the first four
  // data points and store in the 'data' array.
  do
  {
    delay(4);

    for(int i=0;i<4;i++)
    {
      data[i]=USSerial.read();
    }
  } while(USSerial.read()==0xff);

  // Flush the Serial, as is standard after reading so the next reading
  // is not affected from this readings results.
  USSerial.flush();

  // If the first data point is valid:
  if(data[0]==0xff)
  {
    // Sum the first three data points, bitwise AND to convert to Hex Checksum
    int sum;
    sum=(data[0]+data[1]+data[2])&0x00FF;

    // If the calculated Checksum is Valid:
    if(sum==data[3])
    {
      // Get the distance value from the data collected (in mm)
      distance=(data[1]<<8)+data[2];

      // If the distance is >30mm (valid operational range), return distance in cm
      if(distance>30)
      {
        // Return distance in centimetres (currently in millimetres, so divide by 10)
        return(distance/10);
      }
      else 
      {
        // If the distance is below 30mm, it is below the lower limit of the sensor, so
        // return 0mm as the distance.
        Serial.println("Below the lower limit");
        return(0);
      }
    }
    // In a circumstance where the first three data entries do not equal the checksum,
    // return an error designated by '-1'.
    else {Serial.println("ERROR"); return(-1);}
  }   
}

private:
  // Variable declaration used within class
  SoftwareSerial USSerial;
  unsigned char data[4]={};
  double distance = 0.0;
};


#endif