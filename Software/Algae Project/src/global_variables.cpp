#include <global_variables.h>

    //-----------------------------     Global Variables ---------------------------------------
int Temp1=-1,Temp2=-1;
int SonarDist1=-1, SonarDist2=-1;
Control_State PumpState = Control_State::Off, SolanoidState = Control_State::Off;
    //-----------------------------     Global Objects Declarations  ----------------------------------
LiquidCrystal lcd = LiquidCrystal(LCDRSPin,LCDRWPin,LCDD4Pin,LCDD5Pin,LCDD6Pin,LCDD7Pin);


    //-----------------------------     EEPROM Variable Definitions  ----------------------------------
EEPROM_Manager rom_manager;
EEPROM_Variable dutycycle(50,1,&rom_manager);
EEPROM_Variable autosave(10,2,&rom_manager);



