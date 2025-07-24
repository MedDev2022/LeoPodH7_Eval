################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/krinm/STM32Cube/Repository/STM32Cube_FW_H7_V1.12.1/Utilities/ResourcesManager/res_mgr.c 

C_DEPS += \
./Utilities/res_mgr.d 

OBJS += \
./Utilities/res_mgr.o 


# Each subdirectory must supply rules for building sources it contributes
Utilities/res_mgr.o: C:/Users/krinm/STM32Cube/Repository/STM32Cube_FW_H7_V1.12.1/Utilities/ResourcesManager/res_mgr.c Utilities/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DCORE_CM7 -DUSE_HAL_DRIVER -DSTM32H755xx -DUSE_PWR_DIRECT_SMPS_SUPPLY -c -I../Core/Inc -I../../Common/Inc -IC:/Users/krinm/STM32Cube/Repository/STM32Cube_FW_H7_V1.12.1/Drivers/STM32H7xx_HAL_Driver/Inc -IC:/Users/krinm/STM32Cube/Repository/STM32Cube_FW_H7_V1.12.1/Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -IC:/Users/krinm/STM32Cube/Repository/STM32Cube_FW_H7_V1.12.1/Utilities/ResourcesManager -IC:/Users/krinm/STM32Cube/Repository/STM32Cube_FW_H7_V1.12.1/Drivers/CMSIS/Device/ST/STM32H7xx/Include -IC:/Users/krinm/STM32Cube/Repository/STM32Cube_FW_H7_V1.12.1/Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Utilities

clean-Utilities:
	-$(RM) ./Utilities/res_mgr.cyclo ./Utilities/res_mgr.d ./Utilities/res_mgr.o ./Utilities/res_mgr.su

.PHONY: clean-Utilities

