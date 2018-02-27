################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/bsp_driver_sd.c \
../Src/dma.c \
../Src/fatfs.c \
../Src/fsmc.c \
../Src/gpio.c \
../Src/main.c \
../Src/rng.c \
../Src/sd_diskio.c \
../Src/sdio.c \
../Src/stm32f4xx_hal_msp.c \
../Src/stm32f4xx_it.c \
../Src/system_stm32f4xx.c \
../Src/tim.c 

OBJS += \
./Src/bsp_driver_sd.o \
./Src/dma.o \
./Src/fatfs.o \
./Src/fsmc.o \
./Src/gpio.o \
./Src/main.o \
./Src/rng.o \
./Src/sd_diskio.o \
./Src/sdio.o \
./Src/stm32f4xx_hal_msp.o \
./Src/stm32f4xx_it.o \
./Src/system_stm32f4xx.o \
./Src/tim.o 

C_DEPS += \
./Src/bsp_driver_sd.d \
./Src/dma.d \
./Src/fatfs.d \
./Src/fsmc.d \
./Src/gpio.d \
./Src/main.d \
./Src/rng.d \
./Src/sd_diskio.d \
./Src/sdio.d \
./Src/stm32f4xx_hal_msp.d \
./Src/stm32f4xx_it.d \
./Src/system_stm32f4xx.d \
./Src/tim.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o: ../Src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F407xx -I"C:/Users/Beloussov/Documents/GitHub/zx_stm32/zx_stm32/Inc" -I"C:/Users/Beloussov/Documents/GitHub/zx_stm32/zx_stm32/ay_3_891x/Inc" -I"C:/Users/Beloussov/Documents/GitHub/zx_stm32/zx_stm32/ay_3_891x/Src" -I"C:/Users/Beloussov/Documents/GitHub/zx_stm32/zx_stm32/ay_3_891x" -I"C:/Users/Beloussov/Documents/GitHub/zx_stm32/zx_stm32/Drivers/STM32F4xx_HAL_Driver/Inc" -I"C:/Users/Beloussov/Documents/GitHub/zx_stm32/zx_stm32/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy" -I"C:/Users/Beloussov/Documents/GitHub/zx_stm32/zx_stm32/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"C:/Users/Beloussov/Documents/GitHub/zx_stm32/zx_stm32/Drivers/CMSIS/Include" -I"C:/Users/Beloussov/Documents/GitHub/zx_stm32/zx_stm32/z80" -I"C:/Users/Beloussov/Documents/GitHub/zx_stm32/zx_stm32/z80/Inc" -I"C:/Users/Beloussov/Documents/GitHub/zx_stm32/zx_stm32/z80/Src" -I"C:/Users/Beloussov/Documents/GitHub/zx_stm32/zx_stm32/lcd" -I"C:/Users/Beloussov/Documents/GitHub/zx_stm32/zx_stm32/lcd/Inc" -I"C:/Users/Beloussov/Documents/GitHub/zx_stm32/zx_stm32/lcd/Src" -I"C:/Users/Beloussov/Documents/GitHub/zx_stm32/zx_stm32/zx_spectrum" -I"C:/Users/Beloussov/Documents/GitHub/zx_stm32/zx_stm32/zx_spectrum/Inc" -I"C:/Users/Beloussov/Documents/GitHub/zx_stm32/zx_stm32/zx_spectrum/Src" -I"C:/Users/Beloussov/Documents/GitHub/zx_stm32/zx_stm32/Middlewares/Third_Party/FatFs/src"  -O3 -g -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


