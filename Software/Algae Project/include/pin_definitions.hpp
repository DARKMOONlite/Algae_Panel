
#ifndef PIN_DEFINITIONS_H
#define PIN_DEFINITIONS_H
#include <Arduino.h>


// --------------------------       SENSORS     ------------------------------
# define TSensorPin1 12
#define TSensorPin2 13
#define SSensorPin1 A3
#define SSensorPin2 A4
#define SonarEchoPin A2



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