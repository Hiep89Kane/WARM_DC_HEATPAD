################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/BLUETOOTH/BLE_HC05.c 

OBJS += \
./Core/Src/BLUETOOTH/BLE_HC05.o 

C_DEPS += \
./Core/Src/BLUETOOTH/BLE_HC05.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/BLUETOOTH/%.o Core/Src/BLUETOOTH/%.su: ../Core/Src/BLUETOOTH/%.c Core/Src/BLUETOOTH/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F030x8 -c -I../Core/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -I../Drivers/CMSIS/Include -I../Core/Src/COMMON -I../Core/Src/RS232LL -I../Core/Src/PUTCHAR -I../Core/Src/INTERRUPT -I"D:/1_NGUYEN_VAN_HIEP/25_STM32CubeIDE_Workspace/0_2H1T_Library" -I../Core/Src/DEBUG_V -I../Core/Src/FLASH -I../Core/Src/BLUETOOTH -I../Core/Src/HEATPAD -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-BLUETOOTH

clean-Core-2f-Src-2f-BLUETOOTH:
	-$(RM) ./Core/Src/BLUETOOTH/BLE_HC05.d ./Core/Src/BLUETOOTH/BLE_HC05.o ./Core/Src/BLUETOOTH/BLE_HC05.su

.PHONY: clean-Core-2f-Src-2f-BLUETOOTH

