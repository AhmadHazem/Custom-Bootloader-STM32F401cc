################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/APP/Bootloader/Bootloader_program.c 

OBJS += \
./Src/APP/Bootloader/Bootloader_program.o 

C_DEPS += \
./Src/APP/Bootloader/Bootloader_program.d 


# Each subdirectory must supply rules for building sources it contributes
Src/APP/Bootloader/%.o Src/APP/Bootloader/%.su Src/APP/Bootloader/%.cyclo: ../Src/APP/Bootloader/%.c Src/APP/Bootloader/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F4 -DSTM32F401RCTx -c -I../Inc -I"D:/Embedded/ARM/Workspaces/BL/Inc/MCAL/RCC" -I"D:/Embedded/ARM/Workspaces/BL/Inc/Lib" -I"D:/Embedded/ARM/Workspaces/BL/Inc/MCAL/FLS" -I"D:/Embedded/ARM/Workspaces/BL/Inc/MCAL/GPIO" -I"D:/Embedded/ARM/Workspaces/BL/Inc/MCAL/NVIC" -I"D:/Embedded/ARM/Workspaces/BL/Inc/MCAL/UART" -I"D:/Embedded/ARM/Workspaces/BL/Inc/Services/UARTTP" -I"D:/Embedded/ARM/Workspaces/BL/Inc/APP/Bootloader" -I"D:/Embedded/ARM/Workspaces/BL/Inc/MCAL/SYSTICK" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src-2f-APP-2f-Bootloader

clean-Src-2f-APP-2f-Bootloader:
	-$(RM) ./Src/APP/Bootloader/Bootloader_program.cyclo ./Src/APP/Bootloader/Bootloader_program.d ./Src/APP/Bootloader/Bootloader_program.o ./Src/APP/Bootloader/Bootloader_program.su

.PHONY: clean-Src-2f-APP-2f-Bootloader

