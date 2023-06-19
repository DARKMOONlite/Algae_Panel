// Include the Software Serial library
#include <SoftwareSerial.h>
#include <Wire.h> // Library for I2C communication
#include <Arduino.h>
#include <stdlib.h>

// Define connections to sensor
int pinRX = 15; // WHITE CABLE - 4TH CABLE (Vcc, GND, TX (YELLOW), RX (WHITE))
int pinTX = 14; // YELLOW CABLE - 3RD CABLE (Vcc, GND, TX (YELLOW), RX (WHITE))

// Array to store incoming serial data
unsigned char data_buffer[4] = {0};

// Integer to store distance
int distance = 0;

// Variable to hold checksum
unsigned char CS;

// Object to represent software serial port
SoftwareSerial mySerial(pinRX, pinTX);

void setup() {
  // Set up serial monitor
  Serial.begin(9600);
  // Set up software serial port
  mySerial.begin(9600);
  Wire.begin();
}

void loop() 
{
  // Run if data available
  if (mySerial.available() > 0) 
  {
    delay(4);

    // Check for packet header character 0xff
    if(mySerial.read() == 0xff) 
    {
      // Insert header into array
      data_buffer[0] = 0xff;
      // Read remaining 3 characters of data and insert into array
      for (int i = 1; i < 4; i++) 
      {
        data_buffer[i] = mySerial.read();
      }

      //Compute checksum
      CS = data_buffer[0] + data_buffer[1] + data_buffer[2];
      // If checksum is valid compose distance from data
      if (data_buffer[3] == CS) 
      {
        distance = (data_buffer[1] << 8) + data_buffer[2];
        
        // Convert to cm
        int distanceCM = distance/10;
        // Get value to one decimal point (unecessary)
        // char distanceBuffer[6];
        // dtostrf(distanceCM, 5, 1, distanceBuffer);

        // Print to serial monitor
        Serial.print("Distance: ");
        Serial.print(distanceCM);
        Serial.println(" cm");
      }
      else
      {
        Serial.println("ERROR CHECKSUM");
      }
    }
    else
    {
        Serial.println("ERROR PACKET HEADER");
    }
  }
  else
  {
    Serial.println("NO CONNECTION SERIAL ERROR");
  }
}