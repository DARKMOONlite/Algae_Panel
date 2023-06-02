#ifndef EEPROM_MANAGER_H
#define EEPROM_MANAGER_H

#include <Arduino.h>
#include <EEPROM.h>
#include <ArduinoSTL.h>
class EEPROM_Manager;
/**
 * @brief Class for for saving and editing to EEPROM
 * 
 */
class EEPROM_Variable {
    public:
    /**
     * @brief DEPRECATED, does not use a manager, should not be used.
     * 
     * @param _Variable 
     */
        EEPROM_Variable(int _Variable)
        :default_var(_Variable)
        {
            var = _Variable;
        }
        EEPROM_Variable(int _Variable,uint8_t _EE_Loc,EEPROM_Manager* _Manager);
        void Store();
        int Retrieve();
        void Reset();
    private:
        uint16_t EEPROM_LOC=-1;
        const int default_var;
};

/**
 * @brief Allows for simple management of multiple EEPROM variable objects
 * 
 */
class EEPROM_Manager{
    public:
        EEPROM_Manager();
        void Store();
        void Retrieve();
        void Reset();
        bool Add(EEPROM_Variable* variable,uint8_t EEPROM_LOC);
        void print_errors();
    private:
        uint8_t EEPROM_MAP;
        std::vector<uint8_t> double_error;
        std::vector<uint8_t> overflow_error;
        std::vector<EEPROM_Variable*> EEPROM_Vector;
};



#endif