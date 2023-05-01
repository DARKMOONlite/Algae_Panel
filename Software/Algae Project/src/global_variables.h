#ifndef GLOBAL_VARIABLES_H
#define GLOBAL_VARIABLES_H
#include <Arduino.h>
#include <LiquidCrystal.h>
#include <SimpleMenu.h>
#include <ArduinoSTL.h>
#include <EEPROM_Manager.h>

    //-----------------------------     Pin Declarations  ----------------------------------
extern const int xinput, yinput;
extern const int Button;
extern const int TSensorPin1, TSensorPin2;
extern const int SSensorPin1, SSensorPin2,SonarEchoPin;
extern const int PumpTxPin, PumpRxPin;
    //-----------------------------     Global Variables ---------------------------------------
extern int Temp1,Temp2;
extern int SonarDist1, SonarDist2;




    //-----------------------------     Global Objects Declarations  ----------------------------------
extern LiquidCrystal lcd;
extern SimpleMenu TopMenu;
    //-----------------------------     EEPROM Variable Declarations  ----------------------------------


extern EEPROM_Manager rom_manager;

extern EEPROM_Variable dutycycle ;
extern EEPROM_Variable autosave ;


    //-----------------------------     Other Stuff  ----------------------------------
enum Joystick_State{
  Up = 1,
  Down = 2,
  left =-1,
  right = -2,
  Centre = 0
};
enum Control_State{
    Off=0,
    Manual = 1,
    Automatic=2
};


#endif