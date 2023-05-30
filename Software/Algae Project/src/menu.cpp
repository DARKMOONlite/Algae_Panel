
#include <menu.h>


    //-----------------------------     Menu Structure ----------------------------------

  SimpleMenu ManualPumpSettings[2]={
    SimpleMenu("Duty Cycle",&manual_dutycycle.var,0,25),
    SimpleMenu("Manual On",[](){return(Pump_Ctrl(1));})
  };

    SimpleMenu Pump_Menu[3] = {
    SimpleMenu("Off",[](){return(Pump_Ctrl(0));}),
    SimpleMenu("Manual:",2,ManualPumpSettings),
    SimpleMenu("Automatic On",[](){return(Pump_Ctrl(2));}),
  };


  SimpleMenu DepthMenu[2] = {
    SimpleMenu("Panel Depth",&SonarDist1), //! Change these variables to the calculated depths of each
    SimpleMenu("Resevoir Depth",&SonarDist2)
  };
  SimpleMenu TempMenu[2]={
    SimpleMenu("Panel Temp",&Temp1),
    SimpleMenu("Resevoir Temp",&Temp2)
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
  SimpleMenu SD_Menu[2]={
    SimpleMenu("autosave period",&autosave.var,0,60),
    SimpleMenu("manual save!",[](){})
  };


  SimpleMenu Menu[5] = {
    SimpleMenu("Save Settings:",3,Save_Menu),
    SimpleMenu("Solanoid:",2,Solanoid_Menu),
    SimpleMenu("Pump Controls:",3,Pump_Menu),
    SimpleMenu("Sensors:",2,Sensor_Menu),
    SimpleMenu("SD Menu",2,SD_Menu)
    
    

  };
  SimpleMenu TopMenu(5,Menu);




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