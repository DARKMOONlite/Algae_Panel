
#include <rtos_tasks.h>


    //-----------------------------     RTOS Variable Definitions  ----------------------------------

SemaphoreHandle_t xSerialSemaphore;
  
  



bool setup_rtos_tasks(){

  Serial.println("Creating UI Task");
  if(xTaskCreate(
    TaskUI,
    "UI",
    128,
    NULL,
    2,
    NULL
  )!=pdPASS){
    return(false);
  }
  
  //  if(xTaskCreate(
  //   TaskReadSensor,
  //   "ReadSensor",
  //   128,
  //   NULL,
  //   2,
  //   NULL
  // )!=pdPASS){
  //   return(false);
  // }
  // if(xTaskCreate(
  //   TaskPWM,
  //   "WritePWM",
  //   128,
  //   NULL,
  //   3,
  //   NULL
  // )!=pdPASS){
  //   return(false);
  // }
  //   if(xTaskCreate(
  //   TaskSD,
  //   "WriteSD",
  //   128,
  //   NULL,
  //   1,
  //   NULL
  // )!=pdPASS){
  //   return(false);
  // }


return(true);
}

//     //-----------------------------     RTOS Task Definition  ----------------------------------


// void TaskReadSensor(void *pvParameters){
// //run setup, this is done once

//   // DS18B20 TempSensor1(TSensorPin1);
//   // DS18B20 TempSensor2(TSensorPin2);
//   // NewPing Sonar1(SSensorPin1,SonarEchoPin,400);
//   // NewPing Sonar2(SSensorPin2,SonarEchoPin,400);

//   while(1){ // add stuff here to add it to the task
//     // if(xSemaphoreTake(xSerialSemaphore,(TickType_t) 5)==pdTRUE){ // this checks if we can get the mutex semaphore
//     //   Serial.write("Task: Sensor\n");
//     //   Temp1 = (int)TempSensor1.readTempC();
//     //   Temp2 = (int)TempSensor2.readTempC();
//     //   SonarDist1 = Sonar1.ping_cm();
//     //   SonarDist2 = Sonar2.ping_cm();
      
//     //   xSemaphoreGive(xSerialSemaphore);
//     // }
//     // vTaskDelay(1);
//   }
//   }





// void TaskControl(void *pvParameters){
// //run setup here this is done once
//   DRI0050 PumpController(PumpTxPin,PumpRxPin);
//   PumpController.setPwmFreq(10);
//   PumpController.setPwmDuty(0);

//   while(1){// add stuff here to add it to the task
    
//     if(xSemaphoreTake(xSerialSemaphore,(TickType_t) 5)==pdTRUE){ // this checks if we can get the mutex semaphore
//       Serial.write("Task: Control\n");
//       if(PumpState==Control_State::Off){  // if the pumpstate is off then turn off the pump pwm controller
//         PumpController.setPwmEnable(PWM_DISENABLE);
//       }
//       if(PumpState==Control_State::Manual){ // if the state is set to manual, 
//         PumpController.setPwmDuty(dutycycle.var);
//         PumpController.setPwmEnable(PWM_ENABLE);
//       }
//       if(PumpState==Control_State::Automatic){

//       }
      
//       xSemaphoreGive(xSerialSemaphore);
//     }
//     vTaskDelay(1);
//   }
//   }



void TaskUI(void *pvParameters){
//run setup, this is done once
  Serial.print("Setting Up TaskUI");
  Joystick_State prev_pos = Centre; 
  // // make the pushbutton's pin an input:
  // pinMode(Button, INPUT_PULLUP);
  // pinMode(xinput,INPUT);
  // pinMode(yinput,INPUT);

  lcd.begin(16,2);
  TopMenu.begin(display,displayValue);
  int xPosition = 0, yPosition = 0, buttonState = 0;

  while(1){ // add stuff here to add it to the task
    if(xSemaphoreTake(xSerialSemaphore,(TickType_t) 5)==pdTRUE){ // this checks if we can get the mutex semaphore
      Serial.write("Task: UI\n");
      // xPosition = analogRead(xinput)-1024/2;
      // yPosition = analogRead(yinput)-1024/2;
      // buttonState = digitalRead(Button);
      // if((abs(xPosition)>256||abs(yPosition)>256)){// create deadzone to minimise false positive inputs
      //   if(prev_pos==Centre){ // requires the joystick to be returned to centre before reading again.
      //     if(abs(xPosition)>abs(yPosition)){ // remove diagonal functionality
            
      //       if(xPosition>0){
      //         prev_pos=Joystick_State::Up;
      //         TopMenu.up();
      //       }
      //       else{
      //         prev_pos=Joystick_State::Down;
      //         TopMenu.down();
      //       }
      //     }
      //     else{
      //       if(yPosition>0){
      //         prev_pos=Joystick_State::Up;
      //         TopMenu.select();
      //       }
      //       else{
      //         prev_pos=Joystick_State::Down;
      //         TopMenu.back();
      //       }
      //     }
      //   }
      // }
      // else{
      //   prev_pos=Centre;
      // }
      xSemaphoreGive(xSerialSemaphore);
    }
    Serial.println("test2");
    vTaskDelay(1);
  }
  }
  



// void Automatic_Control(){
  
// }
  