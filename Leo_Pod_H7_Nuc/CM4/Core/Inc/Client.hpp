#pragma once
#include "UartEndpoint.hpp"
#include <deque>
#include "comm.hpp"
#include "FreeRTOS.h"


class DayCam;
class LRX20A;

enum class RxState {
    Idle,
	Ready,
    Receiving,
    Stopped
};

class Client : public UartEndpoint {
public:
    explicit Client(UART_HandleTypeDef* huart);
    void Init();
    void onReceiveByte(uint8_t byte) override;
    void setDayCam(DayCam* cam);
    void setLRF(LRX20A* lrf);
    void resetReception();
    bool receiving_ = false;

private:
    uint8_t byte_;
    std::deque<uint8_t> message_;  // buffer for current message
    comm::Message rxMsg;
    uint8_t buffer_[256];
    size_t bufferIndex_ = 0;
    TickType_t firstByteTick_ = 0;

    size_t expectedLength_ = 0;
    DayCam* dayCam_ = nullptr;
    LRX20A* lrx20A_ = nullptr;
    RxState rxState_ = RxState::Idle;

protected:

    void parseAndProcess(uint8_t* msg, size_t len);
    void processIncoming() override;
    bool verifyCRC(uint8_t* msg, size_t len);


};



