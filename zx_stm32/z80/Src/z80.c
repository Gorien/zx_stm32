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
#include "ay_3_891x.h"

uint16_t vector_nmi;
uint8_t INT_SCR;
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
	noise=(RNG->DR)&0x00ff;
	if(INT_SCR&&INT_mask)
	{
			INT_SCR=DISABLE;
			HAL_GPIO_TogglePin(green_LED_GPIO_Port, green_LED_Pin);
			halt=DISABLE;
			if(IM)
			{
				IFF1=0;
				IFF2=0;
				vector_nmi=(I*256)+255;
				vector_nmi=(memory[vector_nmi+1]<<8)|memory[vector_nmi];
				RST(vector_nmi);
				return(19);
			}
			else
			{
				IFF1=0;
				IFF2=0;
				RST(0x38);
				return(13);
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
	switch (port)
	{
		case 0x7ffe:
		case 0xbffe:
		case 0xdffe:
		case 0xeffe:
		case 0xf7fe:
		case 0xfbfe:
		case 0xfdfe:
		case 0xfefe:
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
			input=(GPIOA->IDR&0x1f)|((GPIOB->IDR&0x01)<<6);
			break;
		case 0xfffd:
			input=ay_3_891x[ay_3_891x_reg];
			break;
		default:
			input=0xff;
			break;
	}
	return input;
}

void out(uint16_t port, uint8_t value)
{
	switch (port)
	{
		case 0xbffd:
			ay_3_891x[ay_3_891x_reg]=value;
			(*ay_3_891x_fc [ay_3_891x_reg])(value);
			break;
		case 0xfffd:
			ay_3_891x_reg=value&0xf;
			break;
		default:
			if ((port&0xff)==0x00fe)
			{
				border=color[value&0x07];//D[0-2] border color
				if (value&0x08)//PA7 out to rec.
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
			break;
	}
}
