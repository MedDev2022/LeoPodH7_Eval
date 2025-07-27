################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/krinm/git/LeoPodH7_Eval/Leo_Pod_H7_Nuc/Utilities/ResourcesManager/res_mgr.c 

C_DEPS += \
./Utilities/res_mgr.d 

OBJS += \
./Utilities/res_mgr.o 


# Each subdirectory must supply rules for building sources it contributes
Utilities/res_mgr.o: C:/Users/krinm/git/LeoPodH7_Eval/Leo_Pod_H7_Nuc/Utilities/ResourcesManager/res_mgr.c Utilities/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DCORE_CM4 -DUSE_HAL_DRIVER -DSTM32H755xx -DUSE_PWR_DIRECT_SMPS_SUPPLY -c -I../Core/Inc -I../../Common/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../../Utilities/ResourcesManager -I"C:/Users/krinm/git/LeoPodH7_Eval/Leo_Pod_H7_Nuc/CM4/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2" -I"C:/Users/krinm/git/LeoPodH7_Eval/Leo_Pod_H7_Nuc/CM4/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F" -I"C:/Users/krinm/git/LeoPodH7_Eval/Leo_Pod_H7_Nuc/CM4/Middlewares/Third_Party/FreeRTOS/Source/include" -I"C:/Users/krinm/git/LeoPodH7_Eval/Leo_Pod_H7_Nuc/CM4/Drivers/CMSIS/Include" -I"C:/Users/krinm/git/LeoPodH7_Eval/Leo_Pod_H7_Nuc/CM4/Drivers/CMSIS/Device/ST/STM32H7xx/Include" -I../../Middlewares/Third_Party/FreeRTOS/Source/include -I../../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fdebug-prefix-map="C:/Users/krinm/git/LeoPodH7_Eval"=. -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Utilities

clean-Utilities:
	-$(RM) ./Utilities/res_mgr.cyclo ./Utilities/res_mgr.d ./Utilities/res_mgr.o ./Utilities/res_mgr.su

.PHONY: clean-Utilities

