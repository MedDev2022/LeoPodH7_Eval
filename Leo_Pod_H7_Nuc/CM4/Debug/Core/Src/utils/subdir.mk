################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Core/Src/utils/Utils.cpp 

C_SRCS += \
../Core/Src/utils/dict.c 

C_DEPS += \
./Core/Src/utils/dict.d 

OBJS += \
./Core/Src/utils/Utils.o \
./Core/Src/utils/dict.o 

CPP_DEPS += \
./Core/Src/utils/Utils.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/utils/%.o Core/Src/utils/%.su Core/Src/utils/%.cyclo: ../Core/Src/utils/%.cpp Core/Src/utils/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DDEBUG -DCORE_CM4 -DUSE_HAL_DRIVER -DSTM32H755xx -DUSE_PWR_DIRECT_SMPS_SUPPLY -c -I../Core/Inc -I../../Common/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../../Middlewares/Third_Party/FreeRTOS/Source/include -I../../Drivers/CMSIS/Include -I../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../../Utilities/ResourcesManager -I../../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/Src/utils/%.o Core/Src/utils/%.su Core/Src/utils/%.cyclo: ../Core/Src/utils/%.c Core/Src/utils/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DCORE_CM4 -DUSE_HAL_DRIVER -DSTM32H755xx -DUSE_PWR_DIRECT_SMPS_SUPPLY -c -I../Core/Inc -I../../Common/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../../Utilities/ResourcesManager -I"C:/Users/krinm/git/LEO_H7_Eval/Leo_Pod_H7_Nuc/CM4/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2" -I"C:/Users/krinm/git/LEO_H7_Eval/Leo_Pod_H7_Nuc/CM4/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F" -I"C:/Users/krinm/git/LEO_H7_Eval/Leo_Pod_H7_Nuc/CM4/Middlewares/Third_Party/FreeRTOS/Source/include" -I"C:/Users/krinm/git/LEO_H7_Eval/Leo_Pod_H7_Nuc/CM4/Drivers/CMSIS/Include" -I"C:/Users/krinm/git/LEO_H7_Eval/Leo_Pod_H7_Nuc/CM4/Drivers/CMSIS/Device/ST/STM32H7xx/Include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-utils

clean-Core-2f-Src-2f-utils:
	-$(RM) ./Core/Src/utils/Utils.cyclo ./Core/Src/utils/Utils.d ./Core/Src/utils/Utils.o ./Core/Src/utils/Utils.su ./Core/Src/utils/dict.cyclo ./Core/Src/utils/dict.d ./Core/Src/utils/dict.o ./Core/Src/utils/dict.su

.PHONY: clean-Core-2f-Src-2f-utils

