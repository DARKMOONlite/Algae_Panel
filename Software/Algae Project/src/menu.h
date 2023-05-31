#ifndef MENU_H
#define MENU_H
#include <SimpleMenu.h>
#include <LiquidCrystal_I2C.h>
#include <Arduino.h>
#include <global_variables.h>



extern SimpleMenu TopMenu;


    //-----------------------------     Menu Functions  ----------------------------------
/**
 * @brief required simplemenu function, DO NOT EDIT
 * 
 * @param _menu 
 */
void display(SimpleMenu *_menu);
/**
 * @brief required simplemenu function, DO NOT EDIT
 * 
 * @param _menu 
 */
void displayValue(SimpleMenu *_menu);
/**
 * @brief set the control state of the solanoid
 * 
 * @param _state 
 */
void Pump_Ctrl(int _state);

/**
 * @brief Set the control state of the solanoid
 * 
 * @param _state 
 */
void Solanoid_Ctrl(int _state);

/**
 * @brief Allows for the menu to accept IR input
 * 
 * @param _input command received from IR receiver
 * @return uint16_t same as input, unless command unknown then return 0
 */
uint16_t Menu_IR_Input(uint16_t _input);

/**
 * @brief Allows for the menu to take serial input
 * 
 * @param _input command received from Serial
 * @return uint16_t same as input, unless command unknown then return 0
 */
int Menu_Serial_Input(int _input);

float Average_Array(int* Array, int Size);


#endif