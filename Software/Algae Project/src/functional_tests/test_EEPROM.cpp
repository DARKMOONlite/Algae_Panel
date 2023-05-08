#include <Arduino.h>
#include <EEPROM_Manager.h>

#define variable1 100
#define variable2 200
EEPROM_Manager manager;
EEPROM_Variable var2(variable2,2,&manager);
EEPROM_Variable var1(variable1,1,&manager);
int hextest = 0x2244;
void setup(){
    Serial.begin(9600);
    // // EEPROM.update(10,11);
    // Serial.print(EEPROM.read(10));
    Serial.print("1: storing variable: ");
    Serial.println(variable1);
    var1.Store();
    Serial.print("2: retrieved variable: ");
    Serial.println(var1.Retrieve());

    Serial.print("3: changed variable: ");
    var1.var = 50;
    Serial.println(var1.Retrieve());

    var1.var=50;
    var1.Store();
    Serial.print("4: changed stored EEPROM variable: ");
    Serial.println(var1.Retrieve());

    Serial.print("5: reset variable back to default: ");
    var1.Reset();
    
    Serial.println(var1.var);
    
    Serial.println("\n Testing Manager \n");

    
    

// int var;
//     for(size_t i =0;i<sizeof(int);i++){
//         uint8_t test = *((uint8_t*)(&hextest)+i);
//         Serial.print(i);
//         Serial.print(": ");
//         Serial.println(test,HEX);
        
//         var |= (test<<8*(i));
        
//     }
//     Serial.print(var,HEX);
}

void loop(){
    
}