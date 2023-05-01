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

/**
 * @brief Turns the pump on without any control. useful for filling the panel
 * 
 */
void Pump_Manual_On();
/**
 * @brief Turns the pump off
 * 
 */
void Pump_Off();
/**
 * @brief Sets the pump to controlled mode, operation is adjustable by changing the related function
 * 
 */
void Pump_Automatic_On();
/**
 * @brief Opens the Solanouid
 * 
 */
void Solanoid_Open();
/**
 * @brief Closes the Solanoid
 * 
 */
void Solanoid_Closed();



#endif