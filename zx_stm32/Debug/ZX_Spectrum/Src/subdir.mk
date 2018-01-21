################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ZX_Spectrum/Src/ram.c \
../ZX_Spectrum/Src/rom.c \
../ZX_Spectrum/Src/z80.c \
../ZX_Spectrum/Src/z80_opcode_base.c \
../ZX_Spectrum/Src/z80_opcode_cb.c \
../ZX_Spectrum/Src/z80_opcode_dd.c \
../ZX_Spectrum/Src/z80_opcode_ddcb.c \
../ZX_Spectrum/Src/z80_opcode_ed.c \
../ZX_Spectrum/Src/z80_opcode_fd.c \
../ZX_Spectrum/Src/z80_opcode_fdcb.c \
../ZX_Spectrum/Src/z80_reg.c \
../ZX_Spectrum/Src/z80_tables.c 

OBJS += \
./ZX_Spectrum/Src/ram.o \
./ZX_Spectrum/Src/rom.o \
./ZX_Spectrum/Src/z80.o \
./ZX_Spectrum/Src/z80_opcode_base.o \
./ZX_Spectrum/Src/z80_opcode_cb.o \
./ZX_Spectrum/Src/z80_opcode_dd.o \
./ZX_Spectrum/Src/z80_opcode_ddcb.o \
./ZX_Spectrum/Src/z80_opcode_ed.o \
./ZX_Spectrum/Src/z80_opcode_fd.o \
./ZX_Spectrum/Src/z80_opcode_fdcb.o \
./ZX_Spectrum/Src/z80_reg.o \
./ZX_Spectrum/Src/z80_tables.o 

C_DEPS += \
./ZX_Spectrum/Src/ram.d \
./ZX_Spectrum/Src/rom.d \
./ZX_Spectrum/Src/z80.d \
./ZX_Spectrum/Src/z80_opcode_base.d \
./ZX_Spectrum/Src/z80_opcode_cb.d \
./ZX_Spectrum/Src/z80_opcode_dd.d \
./ZX_Spectrum/Src/z80_opcode_ddcb.d \
./ZX_Spectrum/Src/z80_opcode_ed.d \
./ZX_Spectrum/Src/z80_opcode_fd.d \
./ZX_Spectrum/Src/z80_opcode_fdcb.d \
./ZX_Spectrum/Src/z80_reg.d \
./ZX_Spectrum/Src/z80_tables.d 


# Each subdirectory must supply rules for building sources it contributes
ZX_Spectrum/Src/%.o: ../ZX_Spectrum/Src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F407xx -I"C:/Users/Yegor/workspace/zx_stm32/zx_stm32/Inc" -I"C:/Users/Yegor/workspace/zx_stm32/zx_stm32/Drivers/STM32F4xx_HAL_Driver/Inc" -I"C:/Users/Yegor/workspace/zx_stm32/zx_stm32/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy" -I"C:/Users/Yegor/workspace/zx_stm32/zx_stm32/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"C:/Users/Yegor/workspace/zx_stm32/zx_stm32/Drivers/CMSIS/Include" -I"C:/Users/Yegor/workspace/zx_stm32/zx_stm32/ZX_Spectrum" -I"C:/Users/Yegor/workspace/zx_stm32/zx_stm32/ZX_Spectrum/Inc" -I"C:/Users/Yegor/workspace/zx_stm32/zx_stm32/ZX_Spectrum/Src"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


