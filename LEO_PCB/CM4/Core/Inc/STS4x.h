// STS4x.h
#pragma once

#include "stm32h7xx_hal.h"  // Make sure this matches your actual device HAL
#include <cstdint>
class STS4x {
public:
    explicit STS4x(I2C_HandleTypeDef* i2cHandle, uint8_t address = 0x44);
    bool init();
    bool readTemperature(float& tempC);
    bool softReset();

private:
    I2C_HandleTypeDef* _hi2c;
    uint8_t _address;

    bool writeCommand(uint16_t cmd);
    bool readData(uint8_t* buffer, uint16_t size);
};