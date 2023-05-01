
#include <menu.h>


    //-----------------------------     Menu Structure ----------------------------------

  SimpleMenu Manual_Pump_menu[2]={
    SimpleMenu("On",Pump_Manual_On),
    SimpleMenu("Off",Pump_Manual_Off),
    // SimpleMenu("Duty Cycle"),
    // SimpleMenu("Duration")
  };
    SimpleMenu Automatic_Pump_menu[2]={
    SimpleMenu("On",Pump_Manual_On),
    SimpleMenu("Off",Pump_Manual_Off)

  };


    SimpleMenu Pump_Menu[2] = {
    SimpleMenu("Manual Control",2,Manual_Pump_menu),
    SimpleMenu("Auto Control",2,Automatic_Pump_menu)
  };

  SimpleMenu TempMenu[2]={
    SimpleMenu("Panel Temp",&Temp1),
    SimpleMenu("Resevoir Temp",&Temp2)
  };
  SimpleMenu DepthMenu[2] = {
    SimpleMenu("Panel Depth",&SonarDist1), //! Change these variables to the calculated depths of each
    SimpleMenu("Resevoir Depth",&SonarDist2)
  };

  SimpleMenu Sensor_Menu[2]={
    SimpleMenu("Temperature",2,TempMenu),
    SimpleMenu("Depth",2,DepthMenu)
  };
  


  SimpleMenu Menu[2] = {
    SimpleMenu("Pump Controls",2,Pump_Menu),
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