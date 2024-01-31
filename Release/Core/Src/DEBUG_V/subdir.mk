################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/DEBUG_V/debug_v.c \
../Core/Src/DEBUG_V/printf.c 

OBJS += \
./Core/Src/DEBUG_V/debug_v.o \
./Core/Src/DEBUG_V/printf.o 

C_DEPS += \
./Core/Src/DEBUG_V/debug_v.d \
./Core/Src/DEBUG_V/printf.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/DEBUG_V/debug_v.o: ../Core/Src/DEBUG_V/debug_v.c Core/Src/DEBUG_V/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -DUSE_HAL_DRIVER -DSTM32F030x8 -c -I../Core/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -I../Drivers/CMSIS/Include -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/DEBUG_V/debug_v.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Core/Src/DEBUG_V/printf.o: ../Core/Src/DEBUG_V/printf.c Core/Src/DEBUG_V/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -DUSE_HAL_DRIVER -DSTM32F030x8 -c -I../Core/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -I../Drivers/CMSIS/Include -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/DEBUG_V/printf.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

