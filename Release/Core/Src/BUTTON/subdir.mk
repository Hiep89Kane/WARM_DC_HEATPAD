################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/BUTTON/SW_interface.c 

OBJS += \
./Core/Src/BUTTON/SW_interface.o 

C_DEPS += \
./Core/Src/BUTTON/SW_interface.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/BUTTON/SW_interface.o: ../Core/Src/BUTTON/SW_interface.c Core/Src/BUTTON/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -DUSE_HAL_DRIVER -DSTM32F030x8 -c -I../Core/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -I../Drivers/CMSIS/Include -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/BUTTON/SW_interface.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

