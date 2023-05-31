#ifndef GLOBAL_VARIABLES_H
#define GLOBAL_VARIABLES_H
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
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
// enum Joystick_State{
//   Up = 1,
//   Down = 2,
//   left =-1,
//   right = -2,
//   Centre = 0
// };
/**
 * @brief Control state for pump and solanoid
 * 
 */
enum Control_State{
    Off=0,
    Manual = 1,
    Automatic=2
};


    //-----------------------------     Global Variables ---------------------------------------
extern int Temp1,Temp2;
extern int SonarDist1, SonarDist2;

extern Control_State PumpState, SolanoidState, prevPumpState, prevSolanoidState;


extern uint32_t lastStateUpdate, lastLCDUpdate, lastSensorUpdate;




    //-----------------------------     Global Objects Declarations  ----------------------------------
extern LiquidCrystal_I2C lcd;

    //-----------------------------     EEPROM Variable Declarations  ----------------------------------


extern EEPROM_Manager rom_manager;

extern EEPROM_Variable manual_dutycycle ;
extern EEPROM_Variable autosave ;


    //-----------------------------     Other Stuff  ----------------------------------

#define STATE_RATE 2000
#define SENSOR_RATE 500
#define LCD_RATE 500
#endif