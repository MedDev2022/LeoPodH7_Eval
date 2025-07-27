#include "Client.hpp"
#include <cstdio>
#include "task.h"
#include "DayCam.hpp"  // Include the actual DayCam class
#include "LRX20A.hpp"

Client::Client(UART_HandleTypeDef* huart)
    : UartEndpoint(huart) {}

void Client::Init() {
//    static uint8_t byte;
    if (!StartReceive(&byte_, 1)) {
        printf("❌ StartReceive failed\n");
    }
    else printf("❌ StartReceive success\n");
}

//void Client::onReceiveByte(uint8_t byte) {
//    printf("📥 Received byte: 0x%02X\n", byte);
//    StartReceive(&byte_, 1);  // Re-arm
//}

void Client::onReceiveByte(uint8_t byte) {
    const TickType_t now = xTaskGetTickCount();

    // Start of new message
    if (!receiving_) {
        if (byte == 0xAA) { // Assume HEADER
            buffer_[0] = byte;
            bufferIndex_ = 1;
            firstByteTick_ = now;
            receiving_ = true;
        }
        return;
    }

    // Timeout check
    if ((now - firstByteTick_) > pdMS_TO_TICKS(500)) {
        resetReception();  // Clear buffer, reset flags
        printf("Timeout/r/n");
        return;
    }

    // Accumulate byte
    if (bufferIndex_ < sizeof(buffer_)) {
        buffer_[bufferIndex_++] = byte;
    } else {
        resetReception();
        return;
    }

    // Wait until we have at least length
    if (bufferIndex_ == 6) {
        expectedLength_ = 6 + buffer_[5] + 2; // 6 header+meta + payload + CRC+FOOTER
    }

    if (bufferIndex_ >= 6 && bufferIndex_ == expectedLength_) {
        if (buffer_[expectedLength_-1] == 0x55) { // FOOTER
            if (verifyCRC(buffer_, expectedLength_)) {
                parseAndProcess(buffer_, expectedLength_);
            }
        }
        resetReception();
    }
}

void Client::resetReception() {
    bufferIndex_ = 0;
    receiving_ = false;
    firstByteTick_ = 0;
}

//void Client::processIncoming() {
//
//	enum class State { WAIT_HEADER, WAIT_PAYLOAD };
//	State state = State::WAIT_HEADER;
//
//    while (!rxQueue_.empty()) {
//        uint8_t byte = rxQueue_.front();
//
//        if (byte == 0x55)
//        {
//        	uint16_t j = 0;
//        	for (uint16_t i = rxQueue_.size(); i < 0 ; i--)
//        	rxMsg[j] = rxQueue_.front();
//        	rxQueue_.pop_front();
//        	j++;
//
//        }
//
//                // Example: parse line-terminated message
//                if (byte == '\n') {
//                    printf("Client received: ");
//                    for (uint8_t c : rxMsg)
//                        printf("%c", c);
//                    printf("\r\n");
//
////        rxQueue_.pop_front();
////        message_.push_back(byte);
////
////        // Example: parse line-terminated message
////        if (byte == '\n') {
////            printf("Client received: ");
////            for (uint8_t c : message_)
////                printf("%c", c);
////            printf("\r\n");
////
////            message_.clear();  // ready for next message
//        }
//    }
//}

void Client::processIncoming() {
    // Example logic (depending on your architecture)
    while (!rxQueue_.empty()) {
        auto msg = rxQueue_.front();
        rxQueue_.pop_front();
        parseAndProcess(reinterpret_cast<uint8_t*>(&msg), sizeof(comm::Message));
    }
}

void Client::parseAndProcess(uint8_t* msg, size_t len) {
    uint8_t srcID = msg[1];
    uint8_t destID = msg[2];
    uint8_t opCode = msg[3];
    uint8_t addr   = msg[4];
    uint8_t length = msg[5];
    uint8_t* payload = &msg[6];

    // You can now switch based on opCode, etc.
    switch (opCode) {
        case 0x01:
        	//dayCam_->SendCommand(dayCam_->zoom_teleVar, sizeof(dayCam_->zoom_teleVar));
        	if (payload != nullptr)
        		dayCam_->handleZoomIn(payload, length);
            break;
        case 0x02:
        	if (payload != nullptr)
        		dayCam_->handleZoomOut(payload, length);
            break;
        case 0x03:
        	if (payload != nullptr){
        	    uint16_t position = (static_cast<uint16_t>(payload[0]) << 8) | payload[1];
        	    dayCam_->handleZoom2Position(position);
        	}
            break;
        case 0x04:
        	dayCam_->handleZoomStop();
			break;
        case 0x05:
        	//dayCam_->SendCommand(dayCam_->zoom_teleVar, sizeof(dayCam_->zoom_teleVar));
        	if (payload != nullptr)
        		dayCam_->handleFocusNear(payload, length);
            break;
        case 0x06:
        	if (payload != nullptr)
        		dayCam_->handleFocusFar(payload, length);
            break;
        case 0x07:
        	if (payload != nullptr){
        	    uint16_t position = (static_cast<uint16_t>(payload[0]) << 8) | payload[1];
        	    dayCam_->handleFocus2Position(position);
        	}
            break;
        case 0x08:
        	dayCam_->handleFocusStop();
			break;


        case 0x51: //LRF Disable
        	//lrx20A_->RangesDataCommand();
			break;
        case 0x52: //LRF Enable
        	//lrx20A_->RangesDataCommand();
			break;
        case 0x53: //LRF Enable Fire
        	lrx20A_->RangesDataCommand();
			break;
        case 0x54: //LRF Set lower limit
        	lrx20A_->SetMinimumRangeCommand();
			break;
        case 0x55: //LRF Set upper limit
        	lrx20A_->SetMaximumRangeCommand();
			break;


        default:
            break;
    }
}

bool Client::verifyCRC(uint8_t* msg, size_t len) {
    if (len < 3) return false;  // Must have at least header + CRC + footer

    uint8_t crc = 0x00;  // or 0xFF depending on your protocol
    for (size_t i = 1; i < len - 2; ++i) { // exclude CRC and footer
        crc ^= msg[i];

    }

    uint8_t receivedCRC = msg[len - 2];
    return crc == receivedCRC;
}

void Client::setDayCam(DayCam* cam) {
    dayCam_ = cam;
}

void Client::setLRF(LRX20A* lrf) {
    lrx20A_ = lrf;
}

