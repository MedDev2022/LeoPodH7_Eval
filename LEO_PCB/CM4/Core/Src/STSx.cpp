// STS4x.cpp
#include "STS4x.h"
#include "stm32h7xx_hal.h"
#include <cmath>

#define CMD_SOFT_RESET       0x30A2
#define CMD_READ_TEMPERATURE 0xFD

STS4x::STS4x(I2C_HandleTypeDef* i2cHandle, uint8_t address)
    : _hi2c(i2cHandle), _address(address << 1) {}

bool STS4x::init() {
    return softReset();
}

bool STS4x::softReset() {
    return writeCommand(CMD_SOFT_RESET);
}

bool STS4x::readTemperature(float& tempC) {
    if (!writeCommand(CMD_READ_TEMPERATURE)) return false;

    uint8_t buffer[3] = {0};
    HAL_Delay(2); // wait at least 1.5ms

    if (!readData(buffer, 3)) return false;

    uint16_t rawTemp = (buffer[0] << 8) | buffer[1];

    // Convert per STS4x datasheet: temp = -45 + 175 * raw / 65535
    tempC = -45.0f + 175.0f * (float)rawTemp / 65535.0f;
    return true;
}

bool STS4x::writeCommand(uint16_t cmd) {
    uint8_t data[2] = { static_cast<uint8_t>(cmd >> 8), static_cast<uint8_t>(cmd & 0xFF) };
    return HAL_I2C_Master_Transmit(_hi2c, _address, data, 2, HAL_MAX_DELAY) == HAL_OK;
}

bool STS4x::readData(uint8_t* buffer, uint16_t size) {
    return HAL_I2C_Master_Receive(_hi2c, _address, buffer, size, HAL_MAX_DELAY) == HAL_OK;
}
