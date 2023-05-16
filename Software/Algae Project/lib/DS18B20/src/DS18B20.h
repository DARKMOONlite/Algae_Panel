#ifndef _DS18B20_H_
#define _DS18B20_H_


#include "DallasTemperature.h"
#include "OneWire.h"

/**
 * @brief Class for managing the DS18B20 Temperature sensor
 * https://core-electronics.com.au/waterproof-ds18b20-digital-temperature-sensor.html
 */
class DS18B20 // : public DallasTemperature //- uncomment for inheritance
{
    public:
    /**
     * @brief Construct a new DS18B20 object
     * 
     * @param pin One Wire pin connection
     */
        DS18B20(const int pin);
        // These two function connect to the sensor over one wire communication and gets the current temperature in degrees celsius and fahrenheit
        /**
         * @brief return temperature in C
         * 
         * @return float 
         */
        float readTempC();
        /**
         * @brief return temperature in C
         * 
         * @return float 
         */
        float readTempF();
          
    private:    
        // Create OneWire bus object
        OneWire oneWire;

        // Create Temperature sensor object
        DallasTemperature sensor;
                
        // pin connected to sensor
        const int m_pin;

       

};

#endif //_DS18B20_H_
