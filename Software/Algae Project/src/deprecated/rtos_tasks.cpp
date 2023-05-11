




// void TaskUIJoystick(void *pvParameters){
// //run setup, this is done once
//   Serial.print("Setting Up TaskUI");
//   // Joystick_State prev_pos = Centre; 
//   // // make the pushbutton's pin an input:
//   pinMode(Button, INPUT_PULLUP);
//   pinMode(xinput,INPUT);
//   pinMode(yinput,INPUT);

//   lcd.begin(16,2);
//   TopMenu.begin(display,displayValue);
//   int xPosition = 0, yPosition = 0, buttonState = 0;

//   while(1){ // add stuff here to add it to the task
//     if(xSemaphoreTake(xSerialSemaphore,(TickType_t) 5)==pdTRUE){ // this checks if we can get the mutex semaphore
//       Serial.write("Task: UI\n");
//       xPosition = analogRead(xinput)-1024/2;
//       yPosition = analogRead(yinput)-1024/2;
//       buttonState = digitalRead(Button);
//       if((abs(xPosition)>256||abs(yPosition)>256)){// create deadzone to minimise false positive inputs
//         if(prev_pos==Centre){ // requires the joystick to be returned to centre before reading again.
//           if(abs(xPosition)>abs(yPosition)){ // remove diagonal functionality
            
//             if(xPosition>0){
//               prev_pos=Joystick_State::Up;
//               TopMenu.up();
//             }
//             else{
//               prev_pos=Joystick_State::Down;
//               TopMenu.down();
//             }
//           }
//           else{
//             if(yPosition>0){
//               prev_pos=Joystick_State::Up;
//               TopMenu.select();
//             }
//             else{
//               prev_pos=Joystick_State::Down;
//               TopMenu.back();
//             }
//           }
//         }
//       }
//       else{
//         prev_pos=Centre;
//       }
//       xSemaphoreGive(xSerialSemaphore);
//     }
//     Serial.println("test2");
//     vTaskDelay(1);
//   }
//   }
  