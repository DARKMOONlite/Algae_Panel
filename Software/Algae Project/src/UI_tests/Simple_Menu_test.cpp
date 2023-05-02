#include <SimpleMenu.h>
#include <LiquidCrystal.h>

#define LCD_RS 2
#define LCD_EN 3
#define LCD_D4 4
#define LCD_D5 5
#define LCD_D6 6
#define LCD_D7 7

int valueA, valueB, valueC, mainValue=5;
void function();

    SimpleMenu Pump_Menu[3] = {
    SimpleMenu("Off",function),
    SimpleMenu("Manual On",function),
    SimpleMenu("Automatic On",function),
  };

  SimpleMenu Solanoid_Menu[2]={
    SimpleMenu("Panel Temp",&valueC),
    SimpleMenu("Resevoir Temp",&valueA)
  };

  SimpleMenu TempMenu[2]={
    SimpleMenu("Panel Temp",&valueB),
    SimpleMenu("Resevoir Temp",&valueA)
  };
  SimpleMenu DepthMenu[2] = {
    SimpleMenu("Panel Depth",&valueA), //! Change these variables to the calculated depths of each
    SimpleMenu("Resevoir Depth",&valueB)
  };

  SimpleMenu Sensor_Menu[2]={
    SimpleMenu("Temperature",2,TempMenu),
    SimpleMenu("Depth",2,DepthMenu)
  };
  //   SimpleMenu Solanoid_Menu[2]={
  //   SimpleMenu("Open",Solanoid_Open),
  //   SimpleMenu("Close",Solanoid_Closed)
  // };
  SimpleMenu Save_Menu[3]={
    SimpleMenu("Save Settings",[](){return(function());}),
    SimpleMenu("Soft Reset",[](){return(function());}),
    SimpleMenu("Hard Reset",[](){return(function());})
  };


  SimpleMenu Menu[4] = {
    SimpleMenu("Solanoid",2,Sensor_Menu),
    SimpleMenu("Pump Controls",3,Pump_Menu),
    
    SimpleMenu("Sensors",2,Sensor_Menu),
    
    SimpleMenu("Save Settings",3,Save_Menu)

  };
  SimpleMenu IntroMenu[1] = {
    SimpleMenu("Algae Panel",4,Menu)
  };
  SimpleMenu TopMenu(1,IntroMenu);

LiquidCrystal lcd = LiquidCrystal(LCD_RS, LCD_EN, LCD_D4, LCD_D5, LCD_D6, LCD_D7);

void display(SimpleMenu *_menu)
{
  lcd.clear();
  lcd.print(">");
  lcd.print(_menu->name);

  SimpleMenu *next = TopMenu.next();
  if(next != NULL)
  {
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


void setup()
{
  Serial.begin(9600);
  Serial.println("start");
  delay(100);
  
  lcd.begin(16, 2);
  TopMenu.begin(display,displayValue);
}

void loop() 
{
  while (Serial.available()) 
  {
    switch( (char)Serial.read())
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
        TopMenu.select();
        break;
    }
  }
}

void function()
{
  lcd.clear();
  lcd.print("function");
  Serial.print("function");
  delay(3000);
}
