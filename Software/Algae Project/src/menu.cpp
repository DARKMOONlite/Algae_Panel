/**
 * @file menu.cpp
 * @author Sebastian Schroder
 * @brief Defines the menu system, can be easily edited to add new functions and variables
 * @version 0.1
 * @date 2023-06-02
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <menu.h>


    //-----------------------------     Menu Structure ----------------------------------

  SimpleMenu ManualPumpSettings[2]={
    SimpleMenu("On!",[](){return(Pump_Ctrl(1));}),
    SimpleMenu("Duty Cycle",&manual_dutycycle.var,0,100)
    
  };

    SimpleMenu Pump_Menu[3] = {
    SimpleMenu("Off",[](){return(Pump_Ctrl(0));}),
    SimpleMenu("Manual:",2,ManualPumpSettings),
    SimpleMenu("Automatic On",[](){return(Pump_Ctrl(2));}),
  };


  SimpleMenu DepthMenu[2] = {
    SimpleMenu("Panel Depth",&IRAverage), 
    SimpleMenu("Resevoir Depth",&SonarAverage)
  };
  SimpleMenu TempMenu[2]={
    SimpleMenu("Panel Temp",&Temp1Average),
    SimpleMenu("Resevoir Temp",&Temp2Average)
  };
  
  SimpleMenu Sensor_Menu[2]={
    SimpleMenu("Temperature:",2,TempMenu),
    SimpleMenu("Depth:",2,DepthMenu)
  };
    SimpleMenu Solanoid_Menu[2]={
    SimpleMenu("Open",[](){return(Solanoid_Ctrl(1));}),
    SimpleMenu("Close",[](){return(Solanoid_Ctrl(0));})
  };
  SimpleMenu Save_Menu[3]={
    SimpleMenu("Save!",[](){return(rom_manager.Store());}),
    SimpleMenu("Soft Reset!",[](){return(rom_manager.Retrieve());}),
    SimpleMenu("Hard Reset!",[](){return(rom_manager.Reset());})
  };

  SimpleMenu Menu[4] = {
    SimpleMenu("Solenoid:",2,Solanoid_Menu),
    SimpleMenu("Pump Controls:",3,Pump_Menu),
    SimpleMenu("Sensors:",2,Sensor_Menu),
    SimpleMenu("Save Settings:",3,Save_Menu)
  };

  SimpleMenu TopMenu(4,Menu);




    //-----------------------------     Menu Functions  ----------------------------------


void display(SimpleMenu *_menu){
    lcd.clear();
    lcd.print(">");
    lcd.print(_menu->name);

    SimpleMenu *next = TopMenu.next();
    if(next != NULL){
        lcd.setCursor(1,1);
        lcd.print(next->name);
  }
}

void displayValue(SimpleMenu *_menu)
{
  lcd.clear();
  lcd.print(_menu->name);
  lcd.setCursor(0,1);
  lcd.print(_menu->getValue());
}


void Pump_Ctrl(int _state){PumpState=Control_State(_state);}

void Solanoid_Ctrl(int _state){SolanoidState = Control_State(_state);}

uint16_t Menu_IR_Input(uint16_t _input){
  Serial.print("IR Input Received: ");
  Serial.println(_input);
  switch (_input)
  {
  case IRREMOTE_UP:
    TopMenu.up();
    break;
    case IRREMOTE_DOWN:
    TopMenu.down();
    break;
    case IRREMOTE_LEFT:
    TopMenu.back();
    break;
    case IRREMOTE_RIGHT:
    TopMenu.select();
    break;
  default:
  
  return(-1);

  }
  return(_input);
}

int Menu_Serial_Input(int _input){
  Serial.print("Serial Input Received: ");
  Serial.println(_input);
  switch (_input)
    {
    case 'w':
      TopMenu.up();
      break;
    case 's':
      TopMenu.down();
      break;
      case 'a':
      TopMenu.back();
      break;
      case 'd':
      case ' ':
      TopMenu.select();
      break;
    default:
      return(-1);
    }
  return(_input);
}


float Average_Array(int* Array, int Size){
    float sum = 0;
    for(int i=0; i<Size;i++){
        sum+=Array[i];
    }
    return(sum/Size);
}



