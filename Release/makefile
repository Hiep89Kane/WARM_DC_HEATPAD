################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Drivers/STM32F0xx_HAL_Driver/Src/subdir.mk
-include Core/Startup/subdir.mk
-include Core/Src/UV_CAPSS/subdir.mk
-include Core/Src/TIMER/subdir.mk
-include Core/Src/RS232LL/subdir.mk
-include Core/Src/OUTPUT_CONTROL/subdir.mk
-include Core/Src/INTERRUPT/subdir.mk
-include Core/Src/INIT/subdir.mk
-include Core/Src/FLASH/subdir.mk
-include Core/Src/DEBUG_V/subdir.mk
-include Core/Src/COMMON/subdir.mk
-include Core/Src/BUTTON/subdir.mk
-include Core/Src/AUTOFILL/subdir.mk
-include Core/Src/subdir.mk
-include subdir.mk
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


BUILD_ARTIFACT_NAME := AF_DualJet_RGB
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX := 
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME).$(BUILD_ARTIFACT_EXTENSION)

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
AF_DualJet_RGB.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
AF_DualJet_RGB.list \

OBJCOPY_BIN += \
AF_DualJet_RGB.bin \


# All Target
all: main-build

# Main-build Target
main-build: AF_DualJet_RGB.elf secondary-outputs

# Tool invocations
AF_DualJet_RGB.elf: $(OBJS) $(USER_OBJS) D:\1_NGUYEN_VAN_HIEP\25_STM32CubeIDE_Workspace\AF_DualJet_RGB\STM32F030C8TX_FLASH.ld makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-gcc -o "AF_DualJet_RGB.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m0 -T"D:\1_NGUYEN_VAN_HIEP\25_STM32CubeIDE_Workspace\AF_DualJet_RGB\STM32F030C8TX_FLASH.ld" --specs=nosys.specs -Wl,-Map="AF_DualJet_RGB.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

AF_DualJet_RGB.list: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "AF_DualJet_RGB.list"
	@echo 'Finished building: $@'
	@echo ' '

AF_DualJet_RGB.bin: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "AF_DualJet_RGB.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_BIN)

fail-specified-linker-script-missing:
	@echo 'Error: Cannot find the specified linker script. Check the linker settings in the build configuration.'
	@exit 2

warn-no-linker-script-specified:
	@echo 'Warning: No linker script specified. Check the linker settings in the build configuration.'

.PHONY: all clean dependents fail-specified-linker-script-missing warn-no-linker-script-specified
.SECONDARY:

-include ../makefile.targets
