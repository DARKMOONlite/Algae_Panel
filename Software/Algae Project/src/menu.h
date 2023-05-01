#ifndef MENU_H
#define MENU_H
#include <SimpleMenu.h>
#include <LiquidCrystal.h>
#include <Arduino.h>
#include <global_variables.h>





    //-----------------------------     Menu Functions  ----------------------------------
void display(SimpleMenu *_menu);

void displayValue(SimpleMenu *_menu);

/**
 * @brief Stores all EEPROM Variables into EEPROM
 * 
 */
void Store();
/**
 * @brief Retrieves the last stored values from eeprom, effective soft reset back to last store call
 * 
 */
void Reset_Soft();
/**
 * @brief Hard reset. resets variables back to their original values but does not effect EEPROM.
 * 
 */
void Reset_Hard();


void Pump_Manual_On();

void Pump_Manual_Off();

#endif