#include <rtos_tasks.h>
#include <Arduino.h>


void setup() {
  
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Starting Up");
  while(!Serial){;}
  if(xSerialSemaphore == NULL){
    xSerialSemaphore = xSemaphoreCreateMutex();
    if(xSerialSemaphore != NULL){
      xSemaphoreGive(xSerialSemaphore);
    }
  }
  _delay_ms(100);

  if(!setup_rtos_tasks()){
    Serial.println("RTOS Task failed to start");
  }
  else{
    Serial.println("All tasks Created Successfully");
  }


}

void loop() {//! do not put anything here, task scheduler will take over

  }