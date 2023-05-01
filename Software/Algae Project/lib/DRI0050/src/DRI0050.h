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

class DRI0050 {
public:
    DRI0050(uint8_t tx, uint8_t rx):COMS(rx,tx){}


    SoftwareSerial COMS;
private:

    static uint16_t CheckCRC(uint8_t *data, uint8_t len){
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

    static void WriteRegValue(uint16_t regAddr, uint16_t value){
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
        Serial.print((char)tempData[i]);
    }
    Serial.flush();
    }

public:

    static void setPwmDuty(uint8_t duty){
    WriteRegValue(DUTY_REG_ADDR, (uint16_t)duty);
    }

    static void setPwmFreq(uint8_t freq){
    WriteRegValue(FREQ_REG_ADDR, (uint16_t)freq);
    }

    static void setPwmEnable(uint8_t pwmStatus){
    WriteRegValue(PWM_EN_REG_ADDR, (uint16_t)pwmStatus);
    }

};




#endif