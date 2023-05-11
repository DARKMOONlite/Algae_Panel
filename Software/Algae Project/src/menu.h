#ifndef MENU_H
#define MENU_H
#include <SimpleMenu.h>
#include <LiquidCrystal.h>
#include <Arduino.h>
#include <global_variables.h>



extern SimpleMenu TopMenu;


    //-----------------------------     Menu Functions  ----------------------------------
void display(SimpleMenu *_menu);

void displayValue(SimpleMenu *_menu);

void Pump_Ctrl(int _state);

void Solanoid_Ctrl(int _state);


uint16_t Menu_IR_Input(uint16_t _input);

int Menu_Serial_Input(int _input);


#endif