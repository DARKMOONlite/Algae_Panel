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
        EEPROM_Variable(int _Variable):default_var(_Variable)
        {var = _Variable;}
        /**
         * @brief Construct a new eeprom variable object
         * 
         * @param _Variable Default variable 
         * @param _EE_Loc memory location, ensure it does not clash with other variables
         * @param _Manager pointerr to EEPROM manager
         */
        EEPROM_Variable(int _Variable,uint8_t _EE_Loc,EEPROM_Manager* _Manager);
        /**
         * @brief Stores variable in EEPROM
         * 
         */
        void Store();
        /**
         * @brief Retrieves Variable from EEPROM
         * 
         * @return int 
         */
        int Retrieve();
        /**
         * @brief Resets variable back to its default, provided in the constructor
         * 
         */
        void Reset();

        int var=0;
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
        /**
         * @brief Stores all managed variables into EEPROM
         * 
         */
        void Store();
        /**
         * @brief Retrieves all managed variables from EEPROM
         * 
         */
        void Retrieve();
        /**
         * @brief Resets all variables back to their default
         * 
         */
        void Reset();
        /**
         * @brief Adds a variable to the EEPROM manager, this is done automatically in the EEPROM Variable constructor
         * 
         * @param variable 
         * @param EEPROM_LOC 
         * @return true 
         * @return false 
         */
        bool Add(EEPROM_Variable* variable,uint8_t EEPROM_LOC);
        /**
         * @brief Prints out to serial if any errors occured
         * 
         */
        void print_errors();
    private:
    /**
     * @brief Map of used memory locations
     * 
     */
        uint8_t EEPROM_MAP;
        /**
         * @brief Errors stored in arrays 
         * 
         */
        std::vector<uint8_t> double_error;
        std::vector<uint8_t> overflow_error;
        /**
         * @brief memory locations of all managed variables
         * 
         */
        std::vector<EEPROM_Variable*> EEPROM_Vector;
};



#endif