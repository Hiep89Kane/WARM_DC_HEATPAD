################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/MIST/appMist.c \
../Core/Src/MIST/hardwareMist.c \
../Core/Src/MIST/rs232Mist.c 

OBJS += \
./Core/Src/MIST/appMist.o \
./Core/Src/MIST/hardwareMist.o \
./Core/Src/MIST/rs232Mist.o 

C_DEPS += \
./Core/Src/MIST/appMist.d \
./Core/Src/MIST/hardwareMist.d \
./Core/Src/MIST/rs232Mist.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/MIST/%.o Core/Src/MIST/%.su: ../Core/Src/MIST/%.c Core/Src/MIST/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F030x8 -c -I../Core/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -I../Drivers/CMSIS/Include -I../Core/Src/COMMON -I../Core/Src/RS232LL -I../Core/Src/MIST -I../Core/Src/PUTCHAR -I../Core/Src/INTERRUPT -I"D:/1_NGUYEN_VAN_HIEP/25_STM32CubeIDE_Workspace/0_2H1T_Library" -I../Core/Src/DEBUG_V -I../Core/Src/FLASH -I../Core/Src/BLUETOOTH -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-MIST

clean-Core-2f-Src-2f-MIST:
	-$(RM) ./Core/Src/MIST/appMist.d ./Core/Src/MIST/appMist.o ./Core/Src/MIST/appMist.su ./Core/Src/MIST/hardwareMist.d ./Core/Src/MIST/hardwareMist.o ./Core/Src/MIST/hardwareMist.su ./Core/Src/MIST/rs232Mist.d ./Core/Src/MIST/rs232Mist.o ./Core/Src/MIST/rs232Mist.su

.PHONY: clean-Core-2f-Src-2f-MIST

