
#include <menu.h>


    //-----------------------------     Menu Structure ----------------------------------



  //   SimpleMenu Pump_Menu[3] = {
  //   SimpleMenu("Off",Pump_Off),
  //   SimpleMenu("Manual On",Pump_Manual_On),
  //   SimpleMenu("Automatic On",Pump_Manual_On),
  // };

  // SimpleMenu Solanoid_Menu[2]={
  //   SimpleMenu("Panel Temp",&Temp1),
  //   SimpleMenu("Resevoir Temp",&Temp2)
  // };


  SimpleMenu DepthMenu[2] = {
    SimpleMenu("Panel Depth",&SonarDist1), //! Change these variables to the calculated depths of each
    SimpleMenu("Resevoir Depth",&SonarDist2)
  };
  SimpleMenu TempMenu[2]={
    SimpleMenu("Panel Temp",&Temp1),
    SimpleMenu("Resevoir Temp",&Temp2)
  };
  
  SimpleMenu Sensor_Menu[2]={
    SimpleMenu("Temperature",2,TempMenu),
    SimpleMenu("Depth",2,DepthMenu)
  };
    SimpleMenu Solanoid_Menu[2]={
    SimpleMenu("Open",Solanoid_Open),
    SimpleMenu("Close",Solanoid_Closed)
  };
  SimpleMenu Save_Menu[3]={
    SimpleMenu("Save Settings",[](){return(rom_manager.Store());}),
    SimpleMenu("Soft Reset",[](){return(rom_manager.Retrieve());}),
    SimpleMenu("Hard Reset",[](){return(rom_manager.Reset());})
  };


  SimpleMenu Menu[3] = {
    SimpleMenu("Save Settings",3,Save_Menu),
        SimpleMenu("Solanoid",2,Solanoid_Menu),
        //     SimpleMenu("Solanoid",2,Solanoid_Menu),
    // SimpleMenu("Solanoid",2,Solanoid_Menu),
    // SimpleMenu("Pump Controls",3,Pump_Menu),
    
    SimpleMenu("Sensors",2,Sensor_Menu)
    
    

  };
  SimpleMenu TopMenu(3,Menu);




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


void Store(){

}

void Reset_Soft(){
  
}
void Reset_Hard(){

}

void Pump_Manual_On(){PumpState=Control_State::Manual;}

void Pump_Off(){PumpState=Control_State::Off;}

void Pump_Automatic_On(){PumpState=Control_State::Automatic;}

void Solanoid_Open(){
  // SolanoidState=Control_State::Manual;
  }

void Solanoid_Closed(){
  // SolanoidState=Control_State::Off;
  }