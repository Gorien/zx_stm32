/*
 *
 *	Author: Beloussov Yegor
 *	Created on: january 2018
 *
 *	The program emulating the work of the processor z80
 *
 */


#include "stm32f4xx_hal.h"
#include "z80.h"
#include "z80_macros.h"
#include "zx.h"

uint16_t vector_nmi;
uint8_t INT;
uint8_t INT_mask;
uint16_t color [8]={0x0000,0x000F,0x7800,0x780F,0x03E0,0x03EF,0x7BE0,0x7BEF};

#include "z80_memory.c"
#include "z80_registers.c"
#include "z80_table.c"

#include "z80_opcodes_ddcb.c"
#include "z80_opcodes_fdcb.c"
#include "z80_opcodes_cb.c"
#include "z80_opcodes_dd.c"
#include "z80_opcodes_ed.c"
#include "z80_opcodes_fd.c"
#include "z80_opcodes_base.c"



void z80_reset(void)
{
	AF=0;
	BC=0;
	DE=0;
	HL=0;
	IX=0;
	IY=0;
	SP=0;
	PC=0;
	IFF1=IFF2=0;
	IM=0;
	MEMPTR=0;
	return;
}



uint8_t z80_run(void)
{
	if(INT&&INT_mask)
	{
			halt=DISABLE;
			if(IM)
			{
				IFF1=0;
				IFF2=0;
				vector_nmi=(I*256)+255;
				vector_nmi=(memory[vector_nmi+1]<<8)|memory[vector_nmi];
				RST(vector_nmi);
			}
			else
			{
				IFF1=0;
				IFF2=0;
				RST(0x38);
			}
	}
	INT_mask=IFF1;
	opcode=memory[PC];
	PC+=1;
	R++;
	return (*opcode_base[opcode])();
}


uint8_t in(uint16_t port)
{
	uint8_t input;
	if ((port&0x00ff)==0xfe)//port 0xfe
	{
		GPIOB->ODR&=0x00ff;
		GPIOB->ODR|=port&0xff00;

		HAL_GPIO_TogglePin(orange_LED_GPIO_Port, orange_LED_Pin);
		HAL_GPIO_TogglePin(orange_LED_GPIO_Port, orange_LED_Pin);
		HAL_GPIO_TogglePin(orange_LED_GPIO_Port, orange_LED_Pin);
		HAL_GPIO_TogglePin(orange_LED_GPIO_Port, orange_LED_Pin);
		HAL_GPIO_TogglePin(orange_LED_GPIO_Port, orange_LED_Pin);
		HAL_GPIO_TogglePin(orange_LED_GPIO_Port, orange_LED_Pin);
		HAL_GPIO_TogglePin(orange_LED_GPIO_Port, orange_LED_Pin);
		HAL_GPIO_TogglePin(orange_LED_GPIO_Port, orange_LED_Pin);
		HAL_GPIO_TogglePin(orange_LED_GPIO_Port, orange_LED_Pin);
		HAL_GPIO_TogglePin(orange_LED_GPIO_Port, orange_LED_Pin);
		HAL_GPIO_TogglePin(orange_LED_GPIO_Port, orange_LED_Pin);
		HAL_GPIO_TogglePin(orange_LED_GPIO_Port, orange_LED_Pin);
		HAL_GPIO_TogglePin(orange_LED_GPIO_Port, orange_LED_Pin);
		HAL_GPIO_TogglePin(orange_LED_GPIO_Port, orange_LED_Pin);
		HAL_GPIO_TogglePin(orange_LED_GPIO_Port, orange_LED_Pin);
		HAL_GPIO_TogglePin(orange_LED_GPIO_Port, orange_LED_Pin);

		input=(GPIOA->IDR&0x1f);

		if ((ADC1->DR)>2)
		{
			input|=0x40;//input from rec.
		}
		return (input);
	}
	else
	{
		return (0xff);
	}
}

void out(uint16_t port, uint8_t value)
{
	if ((port&0xFF)==0x00fe)//port 0xFE
	{
		border=color[value&0x07];//D[0-2] border color

		if (value&0x08)//PA6 out to rec.
		{
			GPIOA->BSRR=GPIO_PIN_7;
		}
		else
		{
			GPIOA->BSRR=(uint32_t)GPIO_PIN_7 << 16U;
		}

		if (value&0x10)//PA5 out speaker
		{
			GPIOA->BSRR=GPIO_PIN_5;
		}
		else
		{
			GPIOA->BSRR=(uint32_t)GPIO_PIN_5 << 16U;
		}
	}
}
