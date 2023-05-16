

## A list of files has been proided as well as a short description on what they do and why/when you would want to make changes
---


| File | Description |
| --- | ----------- |
| [main.cpp](/Software/Algae%20Project/src/main.cpp) | Contains all running code|
| [menu.hpp/cpp](/Software/Algae%20Project/src/menu.h) | Contains definitions and declarations of menu system, custom functions related to the use of the menu are also placed here, if you want to add/rearrange the menu, it can be done by editing the menu class structure found here|
| [global_variables.h/cpp](/Software/Algae%20Project/src/global_variables.h) | Contains all global variable that need to be accessed from all other files, this includes EEPROM variables which should be defined here|
| [AlgaePanelRemote.hpp](/Software/Algae%20Project/include/AlgaePanelRemote.hpp) | Contains all definitions connected to controlling panel via remote, if you want to change remote, or add custom commands, you can do that by defining them here then using this inside the main switch case inside of main|
| [pin_definitions.hpp](/Software/Algae%20Project/include/pin_definitions.hpp) | Contains all pin defintions, if you want to add new sensors using new pins or change what pins are currently being used, add/modify them here (ensure that new pin has all needed functionality, etc: PWM, Analog In) |



## Libraries, there are 2 types of libraries used, platformIO maintained and User maintained.

- ### PlatformIO libraries can be found by opening the PlatformIO Homepage, then selecting Libraries in the lefthand submenu. 
    - These libraries have their own repositories that can be explored to view tutorials and examples on their use.
- ### Local libraries can be found inside the lib folder, the following is a list of libraries and their uses.

| Name | Description |
| --- | ----------- |
| DRI0050 | Manages the DRI0050 Pump PWM Controller |
| DS18B20 | Taken from Dane's original project, this reads the temperature of a one-wire temperature sensor |
| EEPPROM_Manager | contains an EEPROM_Variable and Manager class that allows for easier read write access to EEPROM memory |
| Simple_Menu | Contains a library that greatly simplifies menu creation and management, allows for variable modification and function calls |
