################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Core/Src/Client.cpp \
../Core/Src/DayCam.cpp \
../Core/Src/LRX20A.cpp \
../Core/Src/LeoPodManager.cpp \
../Core/Src/TempSens.cpp \
../Core/Src/UartEndpoint.cpp \
../Core/Src/comm.cpp \
../Core/Src/iRay.cpp \
../Core/Src/stm32_uart_freertos.cpp 

C_SRCS += \
../Core/Src/freertos.c \
../Core/Src/main.c \
../Core/Src/resmgr_utility.c \
../Core/Src/stm32h7xx_hal_msp.c \
../Core/Src/stm32h7xx_it.c \
../Core/Src/syscalls.c \
../Core/Src/sysmem.c 

C_DEPS += \
./Core/Src/freertos.d \
./Core/Src/main.d \
./Core/Src/resmgr_utility.d \
./Core/Src/stm32h7xx_hal_msp.d \
./Core/Src/stm32h7xx_it.d \
./Core/Src/syscalls.d \
./Core/Src/sysmem.d 

OBJS += \
./Core/Src/Client.o \
./Core/Src/DayCam.o \
./Core/Src/LRX20A.o \
./Core/Src/LeoPodManager.o \
./Core/Src/TempSens.o \
./Core/Src/UartEndpoint.o \
./Core/Src/comm.o \
./Core/Src/freertos.o \
./Core/Src/iRay.o \
./Core/Src/main.o \
./Core/Src/resmgr_utility.o \
./Core/Src/stm32_uart_freertos.o \
./Core/Src/stm32h7xx_hal_msp.o \
./Core/Src/stm32h7xx_it.o \
./Core/Src/syscalls.o \
./Core/Src/sysmem.o 

CPP_DEPS += \
./Core/Src/Client.d \
./Core/Src/DayCam.d \
./Core/Src/LRX20A.d \
./Core/Src/LeoPodManager.d \
./Core/Src/TempSens.d \
./Core/Src/UartEndpoint.d \
./Core/Src/comm.d \
./Core/Src/iRay.d \
./Core/Src/stm32_uart_freertos.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/%.o Core/Src/%.su Core/Src/%.cyclo: ../Core/Src/%.cpp Core/Src/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DDEBUG -DCORE_CM4 -DUSE_HAL_DRIVER -DSTM32H755xx -DUSE_PWR_DIRECT_SMPS_SUPPLY -c -I../Core/Inc -I../../Common/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../../Utilities/ResourcesManager -I"C:/Users/krinm/git/LeoPodH7_Eval/Leo_Pod_H7_Nuc/CM4/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2" -I"C:/Users/krinm/git/LeoPodH7_Eval/Leo_Pod_H7_Nuc/CM4/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F" -I"C:/Users/krinm/git/LeoPodH7_Eval/Leo_Pod_H7_Nuc/CM4/Middlewares/Third_Party/FreeRTOS/Source/include" -I"C:/Users/krinm/git/LeoPodH7_Eval/Leo_Pod_H7_Nuc/CM4/Drivers/CMSIS/Include" -I"C:/Users/krinm/git/LeoPodH7_Eval/Leo_Pod_H7_Nuc/CM4/Drivers/CMSIS/Device/ST/STM32H7xx/Include" -IC:/Users/krinm/STM32Cube/Repository/STM32Cube_FW_H7_V1.12.1/Drivers/STM32H7xx_HAL_Driver/Inc -IC:/Users/krinm/STM32Cube/Repository/STM32Cube_FW_H7_V1.12.1/Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -IC:/Users/krinm/STM32Cube/Repository/STM32Cube_FW_H7_V1.12.1/Utilities/ResourcesManager -IC:/Users/krinm/STM32Cube/Repository/STM32Cube_FW_H7_V1.12.1/Drivers/CMSIS/Device/ST/STM32H7xx/Include -IC:/Users/krinm/STM32Cube/Repository/STM32Cube_FW_H7_V1.12.1/Drivers/CMSIS/Include -IC:/Users/krinm/STM32Cube/Repository/STM32Cube_FW_H7_V1.12.1/Middlewares/Third_Party/FreeRTOS/Source/include -IC:/Users/krinm/STM32Cube/Repository/STM32Cube_FW_H7_V1.12.1/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -IC:/Users/krinm/STM32Cube/Repository/STM32Cube_FW_H7_V1.12.1/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/Src/%.o Core/Src/%.su Core/Src/%.cyclo: ../Core/Src/%.c Core/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DCORE_CM4 -DUSE_HAL_DRIVER -DSTM32H755xx -DUSE_PWR_DIRECT_SMPS_SUPPLY -c -I../Core/Inc -I../../Common/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../../Utilities/ResourcesManager -I"C:/Users/krinm/git/LeoPodH7_Eval/Leo_Pod_H7_Nuc/CM4/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2" -I"C:/Users/krinm/git/LeoPodH7_Eval/Leo_Pod_H7_Nuc/CM4/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F" -I"C:/Users/krinm/git/LeoPodH7_Eval/Leo_Pod_H7_Nuc/CM4/Middlewares/Third_Party/FreeRTOS/Source/include" -I"C:/Users/krinm/git/LeoPodH7_Eval/Leo_Pod_H7_Nuc/CM4/Drivers/CMSIS/Include" -I"C:/Users/krinm/git/LeoPodH7_Eval/Leo_Pod_H7_Nuc/CM4/Drivers/CMSIS/Device/ST/STM32H7xx/Include" -IC:/Users/krinm/STM32Cube/Repository/STM32Cube_FW_H7_V1.12.1/Drivers/STM32H7xx_HAL_Driver/Inc -IC:/Users/krinm/STM32Cube/Repository/STM32Cube_FW_H7_V1.12.1/Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -IC:/Users/krinm/STM32Cube/Repository/STM32Cube_FW_H7_V1.12.1/Utilities/ResourcesManager -IC:/Users/krinm/STM32Cube/Repository/STM32Cube_FW_H7_V1.12.1/Drivers/CMSIS/Device/ST/STM32H7xx/Include -IC:/Users/krinm/STM32Cube/Repository/STM32Cube_FW_H7_V1.12.1/Drivers/CMSIS/Include -IC:/Users/krinm/STM32Cube/Repository/STM32Cube_FW_H7_V1.12.1/Middlewares/Third_Party/FreeRTOS/Source/include -IC:/Users/krinm/STM32Cube/Repository/STM32Cube_FW_H7_V1.12.1/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -IC:/Users/krinm/STM32Cube/Repository/STM32Cube_FW_H7_V1.12.1/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -O0 -ffunction-sections -fdata-sections -Wall -fdebug-prefix-map="C:/Users/krinm/git/LeoPodH7_Eval"=. -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src

clean-Core-2f-Src:
	-$(RM) ./Core/Src/Client.cyclo ./Core/Src/Client.d ./Core/Src/Client.o ./Core/Src/Client.su ./Core/Src/DayCam.cyclo ./Core/Src/DayCam.d ./Core/Src/DayCam.o ./Core/Src/DayCam.su ./Core/Src/LRX20A.cyclo ./Core/Src/LRX20A.d ./Core/Src/LRX20A.o ./Core/Src/LRX20A.su ./Core/Src/LeoPodManager.cyclo ./Core/Src/LeoPodManager.d ./Core/Src/LeoPodManager.o ./Core/Src/LeoPodManager.su ./Core/Src/TempSens.cyclo ./Core/Src/TempSens.d ./Core/Src/TempSens.o ./Core/Src/TempSens.su ./Core/Src/UartEndpoint.cyclo ./Core/Src/UartEndpoint.d ./Core/Src/UartEndpoint.o ./Core/Src/UartEndpoint.su ./Core/Src/comm.cyclo ./Core/Src/comm.d ./Core/Src/comm.o ./Core/Src/comm.su ./Core/Src/freertos.cyclo ./Core/Src/freertos.d ./Core/Src/freertos.o ./Core/Src/freertos.su ./Core/Src/iRay.cyclo ./Core/Src/iRay.d ./Core/Src/iRay.o ./Core/Src/iRay.su ./Core/Src/main.cyclo ./Core/Src/main.d ./Core/Src/main.o ./Core/Src/main.su ./Core/Src/resmgr_utility.cyclo ./Core/Src/resmgr_utility.d ./Core/Src/resmgr_utility.o ./Core/Src/resmgr_utility.su ./Core/Src/stm32_uart_freertos.cyclo ./Core/Src/stm32_uart_freertos.d ./Core/Src/stm32_uart_freertos.o ./Core/Src/stm32_uart_freertos.su ./Core/Src/stm32h7xx_hal_msp.cyclo ./Core/Src/stm32h7xx_hal_msp.d ./Core/Src/stm32h7xx_hal_msp.o ./Core/Src/stm32h7xx_hal_msp.su ./Core/Src/stm32h7xx_it.cyclo ./Core/Src/stm32h7xx_it.d ./Core/Src/stm32h7xx_it.o ./Core/Src/stm32h7xx_it.su ./Core/Src/syscalls.cyclo ./Core/Src/syscalls.d ./Core/Src/syscalls.o ./Core/Src/syscalls.su ./Core/Src/sysmem.cyclo ./Core/Src/sysmem.d ./Core/Src/sysmem.o ./Core/Src/sysmem.su

.PHONY: clean-Core-2f-Src

