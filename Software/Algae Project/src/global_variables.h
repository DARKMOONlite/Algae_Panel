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
/**
 * @brief Cyclic_Array Size;
 * 
 */
const int Cyclic_Array_Size = 10;
/**
 * @brief Current Index of Arrays
 * 
 */
extern uint8_t Cyclic_Array_Index;
/**
 * @brief Array of last \var Cyclic_Array_Size values, used for getting rolling average
 * 
 */
extern int Temp1[Cyclic_Array_Size],Temp2[Cyclic_Array_Size],SonarDist1[Cyclic_Array_Size], IRDist2[Cyclic_Array_Size];

/**
 * @brief Current Rolling Average of value
 * 
 */
extern int Temp1Average, Temp2Average, SonarAverage, IRAverage;


extern Control_State PumpState, SolanoidState, prevPumpState, prevSolanoidState;


extern uint32_t lastStateUpdate, lastLCDUpdate, lastSensorUpdate;




    //-----------------------------     Global Objects Declarations  ----------------------------------
extern LiquidCrystal lcd;

    //-----------------------------     EEPROM Variable Declarations  ----------------------------------


extern EEPROM_Manager rom_manager;
extern EEPROM_Variable manual_dutycycle ;
extern EEPROM_Variable autosave ;


    //-----------------------------     Other Stuff  ----------------------------------

#define STATE_RATE 2000
#define SENSOR_RATE 500
#define LCD_RATE 500


#endif