#include <global_variables.h>

    //-----------------------------     Pin Definitions  ----------------------------------
const int xinput = A0, yinput = A1;
const int Button = 8;
const int TSensorPin1 = 12, TSensorPin2 = 13;
const int SSensorPin1 = A3, SSensorPin2 = A4,SonarEchoPin = A2;
const int PumpTxPin = 9, PumpRxPin = 10;
    //-----------------------------     Global Variables ---------------------------------------
int Temp1=-1,Temp2=-1;
int SonarDist1=-1, SonarDist2=-1;
    //-----------------------------     Global Objects Declarations  ----------------------------------
LiquidCrystal lcd = LiquidCrystal(2,3,4,5,6,7);


    //-----------------------------     EEPROM Variable Definitions  ----------------------------------
EEPROM_Manager rom_manager;
EEPROM_Variable dutycycle(50,1,&rom_manager);
EEPROM_Variable autosave(10,2,&rom_manager);



