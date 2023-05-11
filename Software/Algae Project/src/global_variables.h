#ifndef GLOBAL_VARIABLES_H
#define GLOBAL_VARIABLES_H
#include <LiquidCrystal.h>
#include <ArduinoSTL.h>
#include <EEPROM_Manager.h>
#include <menu.h>
#include <NewPing.h>
#include <DRI0050.h>
#include <SoftwareSerial.h>
#include <DS18B20.h>
#include <pin_definitions.hpp>
#include <AlgaePanelRemote.hpp>
// -------------------------------      ENUM    --------------------------------------
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






    //-----------------------------     Global Variables ---------------------------------------
extern int Temp1,Temp2;
extern int SonarDist1, SonarDist2;

extern Control_State PumpState, SolanoidState, prevPumpState, prevSolanoidState;




    //-----------------------------     Global Objects Declarations  ----------------------------------
extern LiquidCrystal lcd;

    //-----------------------------     EEPROM Variable Declarations  ----------------------------------


extern EEPROM_Manager rom_manager;

extern EEPROM_Variable dutycycle ;
extern EEPROM_Variable autosave ;


    //-----------------------------     Other Stuff  ----------------------------------


#endif