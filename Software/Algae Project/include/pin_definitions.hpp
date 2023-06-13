/**
 * @file pin_definitions.hpp
 * @author Sebastian Schroder
 * @brief Use this document to define all Pins used in the main code in the menu.cpp file inside the Menu_IR_Input function
 * @version 0.1
 * @date 2023-06-02
 * 
 * @copyright Copyright (c) 2023
 *  
 */

#ifndef PIN_DEFINITIONS_H
#define PIN_DEFINITIONS_H
#include <Arduino.h>






// --------------------------       SENSORS     ------------------------------
# define TSensorPin1 12
#define TSensorPin2 13
#define SonarTXPin 6    // Prev A3 : YELLOW CABLE - 3RD CABLE
#define SonarRXPin 7    // Prev A2 : WHITE CABLE - 4TH CABLE



//------------------------------        CONTROL     --------------------------------
#define PumpTxPin 9
#define PumpRxPin 10

#define SolanoidPin1 22
#define SolanoidPin2 24 // emergency pin for use with the pump until the pwm motor controller board arrives 


//------------------------------        UI      ------------------------------

#define IRRXPin 11


// ----------------------------     DEPRECATED      ---------------------------------
// #define xinput  A0
// #define yinput = A1
// #define Button = 8

#endif