/****************************************************************************
**  Name:    IRay Device Driver (inherits UartDevice)                      **
**  Author:  MK Medical Device Solutions Ltd.                             **
**  Website: www.mkmeddev.com                                             **
****************************************************************************/
#include "iRay.hpp"
#include <cstdio>
#include <iostream>
#include <cstring>

IRay::IRay(UART_HandleTypeDef* huart)
    : UartEndpoint(huart) {}

void IRay::Init() {
//    static uint8_t byte;
    if (!StartReceive(&byte_, 1)) {
        printf("❌ StartReceive failed\n");
    }
    else printf("❌ StartReceive success\n");
}

void IRay::SetPalette(const std::string& palette) {
    if (irPalettes.find(palette) != irPalettes.end()) {
        SendCommand(irPalettes[palette].data(), irPalettes[palette].size());
    }
}

void IRay::SetReticlePosition(int x, int y) {
    uint8_t cmd[] = {0xAA, 0x09, 0x01, 0x44, 0x02, 0x05, 0x64, 0x00, 0x64, 0x00, 0xC7, 0xEB, 0xAA};
    cmd[6] = static_cast<uint8_t>(x & 0xFF);
    cmd[7] = static_cast<uint8_t>((x >> 8) & 0xFF);
    cmd[8] = static_cast<uint8_t>(y & 0xFF);
    cmd[9] = static_cast<uint8_t>((y >> 8) & 0xFF);
    SendCommand(cmd, sizeof(cmd));
}

void IRay::GetReticlePosition() {
    uint8_t cmd[] = {0xAA, 0x04, 0x01, 0x44, 0x00, 0xF3, 0xEB, 0xAA};
    SendCommand(cmd, sizeof(cmd));
}

void IRay::ReticleOn() {
    uint8_t cmd[] = {0xAA, 0x05, 0x01, 0x43, 0x02, 0xc1, 0xb6, 0xeb, 0xaa};
    SendCommand(cmd, sizeof(cmd));
}

void IRay::CalibReticleOFF() {
    uint8_t cmd[] = {0xAA, 0x05, 0x01, 0x43, 0x02, 0x40, 0x35, 0xeb, 0xaa};
    SendCommand(cmd, sizeof(cmd));
}

void IRay::ReticleOFF() {
    uint8_t cmd[] = {0xAA, 0x05, 0x01, 0x43, 0x02, 0x00, 0xF5, 0xEB, 0xAA};
    SendCommand(cmd, sizeof(cmd));
}

void IRay::Reticle1() {
    uint8_t color[] = {0xAA, 0x05, 0x01, 0x43, 0x02, 0x80, 0x75, 0xEB, 0xAA};
    SendCommand(color, sizeof(color));
    HAL_Delay(1000);
    uint8_t cmd[] = { 0xAA, 0x05, 0x01, 0x43, 0x02, 0x80, 0x75, 0xEB, 0xAA };
    SendCommand(cmd, sizeof(cmd));
    StartReceive(rxBuffer, 8);

}

void IRay::Reticle2() {
    uint8_t cmd[] = {0xAA, 0x05, 0x01, 0x43, 0x02, 0x81, 0x76, 0xEB, 0xAA};
    SendCommand(cmd, sizeof(cmd));
}

void IRay::Reticle3() {
    uint8_t cmd[] = {0xAA, 0x05, 0x01, 0x43, 0x02, 0x82, 0x77, 0xEB, 0xAA};
    SendCommand(cmd, sizeof(cmd));
}

void IRay::Reticle4() {
    uint8_t cmd[] = {0xAA, 0x05, 0x01, 0x43, 0x02, 0x83, 0x78, 0xEB, 0xAA};
    SendCommand(cmd, sizeof(cmd));
}

void IRay::ReticleSetPosition() {
    uint8_t cmd[] = {0xAA, 0x09, 0x01, 0x44, 0x02, 0x05, 0x64, 0x00, 0x64, 0x00, 0xC7, 0xEB, 0xAA};
    SendCommand(cmd, sizeof(cmd));
}

void IRay::InitializePalettes() {
    irPalettes["WH"] = {0xAA, 0x05, 0x01, 0x42, 0x02, 0x00, 0xF4, 0xEB, 0xAA};
    irPalettes["BH"] = {0xAA, 0x05, 0x01, 0x42, 0x02, 0x01, 0xF5, 0xEB, 0xAA};
    irPalettes["Rainbow"] = {0xAA, 0x05, 0x01, 0x42, 0x02, 0x02, 0xF6, 0xEB, 0xAA};
    irPalettes["BGR"] = {0xAA, 0x05, 0x01, 0x42, 0x02, 0x03, 0xF7, 0xEB, 0xAA};
    irPalettes["BRY"] = {0xAA, 0x05, 0x01, 0x42, 0x02, 0x04, 0xF8, 0xEB, 0xAA};
}

void IRay::onReceiveByte(uint8_t byte) {
    printf("📥 Received byte: 0x%02X\n", byte);
    StartReceive(&byte_, 1);  // Re-arm
}

void IRay::processIncoming() {
    while (!rxQueue_.empty()) {
        uint8_t byte = rxQueue_.front();
        rxQueue_.pop_front();
//        message_.push_back(byte);

        // Example: parse line-terminated message
        if (byte == '\n') {
            printf("Client received: ");
            for (uint8_t c : rxQueue_)
                printf("%c", c);
            printf("\r\n");

            rxQueue_.clear();  // ready for next message
        }
    }
}
