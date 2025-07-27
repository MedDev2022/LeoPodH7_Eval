// stm32_uart_freertos.cpp

#include "main.h"
#include "cmsis_os.h"

#include "Client.hpp"
#include "iRay.hpp"
#include "DayCam.hpp"
#include "LRX20A.hpp"
extern "C" {
#include "FreeRTOS.h"
#include "queue.h"
#include <stdio.h>
#include <string.h>
}

#include "UartEndpoint.hpp"

extern "C" void cpp_app_main(void);
extern "C" void MyTaskFunction(void *argument);  // Forward declaration

// Provide _write syscall for printf redirection
extern "C" int _write(int file, char *ptr, int len) {
    HAL_UART_Transmit(&huart3, (uint8_t*)ptr, len, HAL_MAX_DELAY);
    return len;
}


//Client* clientDevice=nullptr;

extern UART_HandleTypeDef huart3;  // make sure it's defined elsewhere (e.g., main.c/.cpp)
extern UART_HandleTypeDef huart1;  // make sure it's defined elsewhere (e.g., main.c/.cpp)



uint8_t rxByte;



// 🚀 Application entry point called from StartDefaultTask
extern "C" void cpp_app_main(void)
{
    printf("cpp_app_main started\n");

    // Create a new task
    const osThreadAttr_t myTask_attributes = {
        .name = "myTask",
        .stack_size = 512 * 4,  // 2KB stack
        .priority = (osPriority_t) osPriorityNormal,
    };

    osThreadId_t myTaskHandle = osThreadNew(MyTaskFunction, nullptr, &myTask_attributes);
    if (myTaskHandle == nullptr) {
        printf("Failed to create MyTaskFunction\n");
    } else {
        printf("MyTaskFunction created successfully\n");
    }

    // You can return here — or sleep forever if this is the main task
    // osDelay(osWaitForever); // Optional if not returning
}

extern  void MyTaskFunction(void *argument)
{


	DayCam* dayCam = new DayCam(&huart1);
	Client client(&huart3);
//	LRX20A* lrx20A = new LRX20A(&huart1);

//   IRay iRay(&huart1);
	client.Init();
//   iRay.Init();


    client.setDayCam(dayCam);

 //   client.setLRF(lrx20A);

    dayCam->Init();

  //  lrx20A->InitLRX20A();

  //  dayCam->address_command;

    for (;;)
    {
    //    printf("📣 Hello from MyTaskFunction!\r\n");
        HAL_GPIO_TogglePin(MCU_LED_2_GPIO_Port, MCU_LED_2_Pin);  // Optional
        osDelay(1000);  // delay 1 second
    }
}



