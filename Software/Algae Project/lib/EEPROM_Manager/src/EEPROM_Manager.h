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
        EEPROM_Variable(int _Variable)
        :default_var(_Variable)
        {
            var = _Variable;
            

        }
        /**
         * @brief Constructs a variable to be stored in EEPROM to persist between resets
         * 
         * @param _Variable starting value of variable
         * @param _EE_Loc location in EEPROM to store int variable (4 bytes). arduino uno has 1024 bytes of EEPROM so this variable is between 0 & 255
         * @param _Manager pointer to manager that will check if EE_LOC is already taken by another variable/ aids in function calls 
         */
        EEPROM_Variable(int _Variable,uint8_t _EE_Loc,EEPROM_Manager* _Manager);
        /**
         * @brief Stores Value to EEPROM, should be called by the user, because EEPROM only has 100,000 writes
         * 
         */
        void Store();

        /**
         * @brief Retrieves Value from EEPROM, should be done on startup.
         * 
         */
        void Retrieve();

        /**
         * @brief sets the variable var to the default var
         * 
         */
        void Reset();

        /**
         * @brief integer variable in question
         * 
         */
        int var;
        
    private:
        /**
         * @brief Location of this variable in EEPROM
         * 
         */
        uint16_t EEPROM_LOC=-1;
        /**
         * @brief var is set to this in the case of a hard reset call.
         * 
         */
        const int default_var;
};


class EEPROM_Manager : private std::vector<EEPROM_Variable*> {

    public:
        EEPROM_Manager();
        /**
         * @brief Calls the Store function of all managed EEPROM variables
         * 
         */
        void Store();
        /**
         * @brief Calls the retrieve function of all managed EEPROM variables
         * 
         */
        void Retrieve();
        /**
         * @brief Calls the Reset function of all managed EEPROM variables
         * 
         */
        void Reset();
        /**
         * @brief Adds an EEPROM variable to the manage list
         * 
         * @param variable pointer to object to access function calls
         * @param EEPROM_LOC requested location of EEPROM
         * @return true if its available
         * @return false if its not available 
         */
        bool Add(EEPROM_Variable* variable,uint8_t EEPROM_LOC);


        void print_errors();

        

        uint8_t EEPROM_MAP;
        
        std::vector<uint8_t> double_error;
        std::vector<uint8_t> overflow_error;
};



#endif