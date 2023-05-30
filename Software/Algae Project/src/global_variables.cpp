#include <global_variables.h>

    //-----------------------------     Global Variables ---------------------------------------
int Temp1=-1,Temp2=-1;
int SonarDist1=-1, SonarDist2=-1;
Control_State PumpState = Control_State::Off, SolanoidState = Control_State::Off;
Control_State prevPumpState = Control_State::Off, prevSolanoidState = Control_State::Off;
    //-----------------------------     Global Objects Declarations  ----------------------------------
LiquidCrystal lcd = LiquidCrystal(LCDRSPin,LCDEPin,LCDD4Pin,LCDD5Pin,LCDD6Pin,LCDD7Pin);


    //-----------------------------     EEPROM Variable Definitions  ----------------------------------
EEPROM_Manager rom_manager;
EEPROM_Variable manual_dutycycle(25,1,&rom_manager);
EEPROM_Variable autosave(10,2,&rom_manager);

uint32_t lastStateUpdate=0, lastLCDUpdate=0, lastSensorUpdate=0;

