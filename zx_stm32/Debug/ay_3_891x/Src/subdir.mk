################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ay_3_891x/Src/ay_3_891x.c 

OBJS += \
./ay_3_891x/Src/ay_3_891x.o 

C_DEPS += \
./ay_3_891x/Src/ay_3_891x.d 


# Each subdirectory must supply rules for building sources it contributes
ay_3_891x/Src/%.o: ../ay_3_891x/Src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F407xx -I"C:/Users/Yegor/Documents/GitHub/zx_stm32/zx_stm32/Inc" -I"C:/Users/Yegor/Documents/GitHub/zx_stm32/zx_stm32/ay_3_891x/Inc" -I"C:/Users/Yegor/Documents/GitHub/zx_stm32/zx_stm32/ay_3_891x/Src" -I"C:/Users/Yegor/Documents/GitHub/zx_stm32/zx_stm32/ay_3_891x" -I"C:/Users/Yegor/Documents/GitHub/zx_stm32/zx_stm32/Drivers/STM32F4xx_HAL_Driver/Inc" -I"C:/Users/Yegor/Documents/GitHub/zx_stm32/zx_stm32/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy" -I"C:/Users/Yegor/Documents/GitHub/zx_stm32/zx_stm32/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"C:/Users/Yegor/Documents/GitHub/zx_stm32/zx_stm32/Drivers/CMSIS/Include" -I"C:/Users/Yegor/Documents/GitHub/zx_stm32/zx_stm32/z80" -I"C:/Users/Yegor/Documents/GitHub/zx_stm32/zx_stm32/z80/Inc" -I"C:/Users/Yegor/Documents/GitHub/zx_stm32/zx_stm32/z80/Src" -I"C:/Users/Yegor/Documents/GitHub/zx_stm32/zx_stm32/lcd" -I"C:/Users/Yegor/Documents/GitHub/zx_stm32/zx_stm32/lcd/Inc" -I"C:/Users/Yegor/Documents/GitHub/zx_stm32/zx_stm32/lcd/Src" -I"C:/Users/Yegor/Documents/GitHub/zx_stm32/zx_stm32/zx_spectrum" -I"C:/Users/Yegor/Documents/GitHub/zx_stm32/zx_stm32/zx_spectrum/Inc" -I"C:/Users/Yegor/Documents/GitHub/zx_stm32/zx_stm32/zx_spectrum/Src" -I"C:/Users/Yegor/Documents/GitHub/zx_stm32/zx_stm32/Middlewares/Third_Party/FatFs/src"  -O3 -g -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


