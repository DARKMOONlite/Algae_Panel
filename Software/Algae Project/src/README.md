## How to use the provided systems


## Simple Menu
Simple Menu has an [attached git repository](https://github.com/tinkersprojects/LCD-Simple-Menu-Library), view this for general inforamtion reguarding how to use.

### Tips and Tricks:
 - the simple menu library requires a function callback and thus the function provided must be static and have no input arguments, to use functions that don't meet these requirements, wrap them inside a lambda function

 ```c++
    SimpleMenu("Automatic On",[](){return(Pump_Ctrl(2));})
 ```


 ## EEPROM MANAGER

to use this you will want to have 1 EEPROM Manager that controls which memory spaces are allocated to which variables.
```c++
EEPROM_Manager rom_manager;
```
then pass a pointer to that manager to each variable, providing to that variable a default variable, and a memory location
```c++
EEPROM_Variable manual_dutycycle(100,1,&rom_manager);
```
- e.g. default variable 100 in memory location 1

look at the EEPROM_Manager.h file on how to save, store and retrieve values from EEPROM


 
