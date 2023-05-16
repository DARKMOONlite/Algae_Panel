#ifndef DRI0050_H
#define DRI0050_H

#include <Arduino.h>
#include <SoftwareSerial.h>

#define  PWM_ENABLE           0x01
#define  PWM_DISENABLE        0x00
#define  DEV_ADDR             0x32
#define  DUTY_REG_ADDR        0x0006
#define  FREQ_REG_ADDR        0x0007
#define  PWM_EN_REG_ADDR      0x0008

/**
 * @brief Used for controlling the DRI0050 PWM motor driver board
 * https://www.dfrobot.com/product-2429.html
 */
class DRI0050 {
public:
/**
 * @brief Construct a new DRI0050 object
 * 
 * @param tx Serial tx pin
 * @param rx Serial rx pin
 */
    DRI0050(uint8_t tx, uint8_t rx):COMS(rx,tx){
        COMS.begin(9600);
    }


    SoftwareSerial COMS;
private:

    /**
     * @brief determines the CRC of the outgoing msg
     * 
     * @param data pointer to data being sent
     * @param len length of that data
     * @return uint16_t 
     */
    uint16_t CheckCRC(uint8_t *data, uint8_t len){
        uint16_t crc = 0xFFFF;
        for(uint8_t pos = 0; pos < len; pos++){
            crc ^= (uint16_t)data[pos];
            for(uint8_t i = 8; i != 0; i-- ){
            if((crc & 0x0001) != 0){
                crc >>= 1;
                crc ^= 0xA001;
            }else{
                crc >>= 1;
            }
            }
        }
        crc = ((crc & 0x00FF) << 8) | ((crc & 0xFF00) >> 8);
        return crc;
    }
    /**
     * @brief Creates the msg for the DRI0050
     * 
     * @param regAddr the register to edit, check definitions to see options
     * @param value the value to set the register to
     */
    void WriteRegValue(uint16_t regAddr, uint16_t value){
        uint8_t tempData[8];
        uint16_t crc;
        tempData[0] = DEV_ADDR;
        tempData[1] = 0x06;
        tempData[2] = (regAddr >> 8) & 0xFF;
        tempData[3] = regAddr & 0xFF;
        tempData[4] = (value >> 8) & 0xFF;
        tempData[5] =  value & 0xFF;
        crc = CheckCRC(tempData, 6);
        tempData[6] = (crc >> 8) & 0xFF;
        tempData[7] = crc & 0xFF;
        for(uint8_t i = 0 ;i < 8; i++){
            COMS.print((char)tempData[i]);
            
        }
        COMS.flush();
    }

public:
    /**
     * @brief Set the Pwm Duty 
     * 
     * @param duty 0-255 for 0%-100%
     */
     void setPwmDuty(uint8_t duty){
    WriteRegValue(DUTY_REG_ADDR, (uint16_t)duty);
    }
    /**
     * @brief Set the Pwm Freq 
     * 
     * @param freq 0-255, PWM frequency is 12,000,000/(256/(freq+1))
     */
     void setPwmFreq(uint8_t freq){
    WriteRegValue(FREQ_REG_ADDR, (uint16_t)freq);
    }
    /**
     * @brief Set the Pwm Enable register
     * 
     * @param pwmStatus 1 for enable 0 for disable 
     */
    void setPwmEnable(uint8_t pwmStatus){
    WriteRegValue(PWM_EN_REG_ADDR, (uint16_t)pwmStatus);
    }

};




#endif