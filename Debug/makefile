################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Drivers/STM32F0xx_HAL_Driver/Src/subdir.mk
-include Core/Startup/subdir.mk
-include Core/Src/LCD_i2c/subdir.mk
-include Core/Src/INTERRUPT/subdir.mk
-include Core/Src/HEATPAD/subdir.mk
-include Core/Src/FLASH/subdir.mk
-include Core/Src/COMMON/subdir.mk
-include Core/Src/subdir.mk
-include 0_2H1T_Library/timeVirtural/subdir.mk
-include 0_2H1T_Library/retryFunction/subdir.mk
-include 0_2H1T_Library/output/subdir.mk
-include 0_2H1T_Library/kalman/subdir.mk
-include 0_2H1T_Library/fifo/subdir.mk
-include 0_2H1T_Library/button/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := WARM_DC_HEATPAD
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
WARM_DC_HEATPAD.elf \

MAP_FILES += \
WARM_DC_HEATPAD.map \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
WARM_DC_HEATPAD.list \

OBJCOPY_HEX += \
WARM_DC_HEATPAD.hex \

OBJCOPY_BIN += \
WARM_DC_HEATPAD.bin \


# All Target
all: main-build

# Main-build Target
main-build: WARM_DC_HEATPAD.elf secondary-outputs

# Tool invocations
WARM_DC_HEATPAD.elf WARM_DC_HEATPAD.map: $(OBJS) $(USER_OBJS) D:\1_NGUYEN_VAN_HIEP\25_STM32CubeIDE_Workspace\WARM_DC_HEATPAD\STM32F030C8TX_FLASH.ld makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-gcc -o "WARM_DC_HEATPAD.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m0 -T"D:\1_NGUYEN_VAN_HIEP\25_STM32CubeIDE_Workspace\WARM_DC_HEATPAD\STM32F030C8TX_FLASH.ld" --specs=nosys.specs -Wl,-Map="WARM_DC_HEATPAD.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

WARM_DC_HEATPAD.list: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "WARM_DC_HEATPAD.list"
	@echo 'Finished building: $@'
	@echo ' '

WARM_DC_HEATPAD.hex: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objcopy  -O ihex $(EXECUTABLES) "WARM_DC_HEATPAD.hex"
	@echo 'Finished building: $@'
	@echo ' '

WARM_DC_HEATPAD.bin: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "WARM_DC_HEATPAD.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) WARM_DC_HEATPAD.bin WARM_DC_HEATPAD.elf WARM_DC_HEATPAD.hex WARM_DC_HEATPAD.list WARM_DC_HEATPAD.map default.size.stdout
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_HEX) $(OBJCOPY_BIN)

fail-specified-linker-script-missing:
	@echo 'Error: Cannot find the specified linker script. Check the linker settings in the build configuration.'
	@exit 2

warn-no-linker-script-specified:
	@echo 'Warning: No linker script specified. Check the linker settings in the build configuration.'

.PHONY: all clean dependents main-build fail-specified-linker-script-missing warn-no-linker-script-specified

-include ../makefile.targets
