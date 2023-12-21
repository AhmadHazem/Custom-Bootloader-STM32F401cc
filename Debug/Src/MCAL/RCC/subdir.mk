################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/MCAL/RCC/RCC_program.c \
../Src/MCAL/RCC/RCC_utilities.c 

OBJS += \
./Src/MCAL/RCC/RCC_program.o \
./Src/MCAL/RCC/RCC_utilities.o 

C_DEPS += \
./Src/MCAL/RCC/RCC_program.d \
./Src/MCAL/RCC/RCC_utilities.d 


# Each subdirectory must supply rules for building sources it contributes
Src/MCAL/RCC/%.o Src/MCAL/RCC/%.su Src/MCAL/RCC/%.cyclo: ../Src/MCAL/RCC/%.c Src/MCAL/RCC/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F4 -DSTM32F401RCTx -c -I../Inc -I"D:/Embedded/ARM/Workspaces/BL/Inc/MCAL/RCC" -I"D:/Embedded/ARM/Workspaces/BL/Inc/Lib" -I"D:/Embedded/ARM/Workspaces/BL/Inc/MCAL/FLS" -I"D:/Embedded/ARM/Workspaces/BL/Inc/MCAL/GPIO" -I"D:/Embedded/ARM/Workspaces/BL/Inc/MCAL/NVIC" -I"D:/Embedded/ARM/Workspaces/BL/Inc/MCAL/UART" -I"D:/Embedded/ARM/Workspaces/BL/Inc/Services/UARTTP" -I"D:/Embedded/ARM/Workspaces/BL/Inc/APP/Bootloader" -I"D:/Embedded/ARM/Workspaces/BL/Inc/MCAL/SYSTICK" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src-2f-MCAL-2f-RCC

clean-Src-2f-MCAL-2f-RCC:
	-$(RM) ./Src/MCAL/RCC/RCC_program.cyclo ./Src/MCAL/RCC/RCC_program.d ./Src/MCAL/RCC/RCC_program.o ./Src/MCAL/RCC/RCC_program.su ./Src/MCAL/RCC/RCC_utilities.cyclo ./Src/MCAL/RCC/RCC_utilities.d ./Src/MCAL/RCC/RCC_utilities.o ./Src/MCAL/RCC/RCC_utilities.su

.PHONY: clean-Src-2f-MCAL-2f-RCC

