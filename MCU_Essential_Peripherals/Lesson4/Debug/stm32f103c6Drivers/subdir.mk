################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../stm32f103c6Drivers/stm32f103c6_EXTI_Driver.c \
../stm32f103c6Drivers/stm32f103c6_GPIO_Driver.c 

OBJS += \
./stm32f103c6Drivers/stm32f103c6_EXTI_Driver.o \
./stm32f103c6Drivers/stm32f103c6_GPIO_Driver.o 

C_DEPS += \
./stm32f103c6Drivers/stm32f103c6_EXTI_Driver.d \
./stm32f103c6Drivers/stm32f103c6_GPIO_Driver.d 


# Each subdirectory must supply rules for building sources it contributes
stm32f103c6Drivers/%.o stm32f103c6Drivers/%.su stm32f103c6Drivers/%.cyclo: ../stm32f103c6Drivers/%.c stm32f103c6Drivers/subdir.mk
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -c -I../Inc -I"C:/Users/mm/STM32CubeIDE/Embedded/Drivers/stm32f103c6Drivers/inc" -I"C:/Users/mm/STM32CubeIDE/Embedded/Drivers/HAL/includes" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-stm32f103c6Drivers

clean-stm32f103c6Drivers:
	-$(RM) ./stm32f103c6Drivers/stm32f103c6_EXTI_Driver.cyclo ./stm32f103c6Drivers/stm32f103c6_EXTI_Driver.d ./stm32f103c6Drivers/stm32f103c6_EXTI_Driver.o ./stm32f103c6Drivers/stm32f103c6_EXTI_Driver.su ./stm32f103c6Drivers/stm32f103c6_GPIO_Driver.cyclo ./stm32f103c6Drivers/stm32f103c6_GPIO_Driver.d ./stm32f103c6Drivers/stm32f103c6_GPIO_Driver.o ./stm32f103c6Drivers/stm32f103c6_GPIO_Driver.su

.PHONY: clean-stm32f103c6Drivers

