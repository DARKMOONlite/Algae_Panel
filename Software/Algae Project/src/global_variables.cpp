#include <global_variables.h>

    //-----------------------------     Global Variables ---------------------------------------
int Temp1[Cyclic_Array_Size],Temp2[Cyclic_Array_Size];
int SonarDist1[Cyclic_Array_Size], IRDist2[Cyclic_Array_Size];
uint8_t Cyclic_Array_Index=0;
int Temp1Average=0, Temp2Average=0, SonarAverage=0, IRAverage=0;



Control_State PumpState = Control_State::Off, SolanoidState = Control_State::Off;
Control_State prevPumpState = Control_State::Off, prevSolanoidState = Control_State::Off;
    //-----------------------------     Global Objects Declarations  ----------------------------------
LiquidCrystal lcd = LiquidCrystal(LCDRSPin,LCDEPin,LCDD4Pin,LCDD5Pin,LCDD6Pin,LCDD7Pin);


    //-----------------------------     EEPROM Variable Definitions  ----------------------------------
EEPROM_Manager rom_manager;
EEPROM_Variable manual_dutycycle(25,1,&rom_manager);
EEPROM_Variable autosave(10,2,&rom_manager);

uint32_t lastStateUpdate=0, lastLCDUpdate=0, lastSensorUpdate=0;

