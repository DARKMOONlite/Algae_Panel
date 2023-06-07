#include <Arduino.h>
#include <DS18B20.h>


DS18B20 TempSensor(4);


void setup(){
Serial.begin(9600);
}

void loop(){
Serial.print("Temp: ");
Serial.println(TempSensor.readTempC());
}