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

#include "z80_memory.c"
#include "z80_registers.c"
#include "z80_table.c"

#include "z80_opcodes_base.c"
#include "z80_opcodes_cb.c"
#include "z80_opcodes_dd.c"
#include "z80_opcodes_ed.c"
#include "z80_opcodes_fd.c"
#include "z80_opcodes_ddcb.c"
#include "z80_opcodes_fdcb.c"

uint8_t pa;
uint8_t o;
uint16_t vector_nmi;
uint8_t IRQ_Z80;
uint8_t screen_IRQ;

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


uint16_t i;

uint8_t z80_run(void)
{
	if (IFF1==0)
	{
		IRQ_Z80=0;
	}

	if (IRQ_Z80==1)
	{
		if (screen_IRQ==1)
		{
			switch(IM)
			{
			case(0):
					IFF1=0;
					IFF2=0;
					RST(0x38);
					halt=0;
					break;
			case(1):
					IFF1=0;
					IFF2=0;
					RST(0x38);
					halt=0;
					break;
			case(2):
					IFF1=0;
					IFF2=0;
					vector_nmi=((I*256)+255);
					vector_nmi=READ_WORD(vector_nmi);
					RST(vector_nmi);
					halt=0;
					break;
			default:
				break;
			}

			if (IM==0)
			{
				IFF1=0;
				IFF2=0;
				RST(0x38);
				halt=0;
			}
			else if (IM==1)
			{
				IFF1=0;
				IFF2=0;
				RST(0x38);
				halt=0;
			}
			else if (IM==2)
			{
				IFF1=0;
				IFF2=0;
				vector_nmi=((I*256)+255);
				vector_nmi=READ_WORD(vector_nmi);
				RST(vector_nmi);
				halt=0;
			}
		}
	}

	if (IFF1==1)
	{
		IRQ_Z80=1;
	}

	if (halt==0)
	{

		opcode=NEXT_BYTE;
		R++;

		switch(opcode)
		{
		case(0xCB):
				opcode=NEXT_BYTE;
				(*opcode_cb[opcode])();
				R++;
				m_cycle+=4;
				break;
		case(0xED):
				opcode=NEXT_BYTE;
				(*opcode_ed[opcode])();
				R++;
				m_cycle+=4;
				break;
		case(0xDD):
				opcode=NEXT_BYTE;
				m_cycle+=4;
				R++;
				if (opcode==0xCB)
				{
					d.u=NEXT_BYTE;
					opcode=NEXT_BYTE;
					(*opcode_ddcb[opcode])();
				}
				else
				{
					(*opcode_dd[opcode])();
				}
				break;
		case(0xFD):
				opcode=NEXT_BYTE;
				m_cycle+=4;
				R++;
				if (opcode==0xCB)
				{
					d.u=NEXT_BYTE;
					opcode=NEXT_BYTE;
					(*opcode_fdcb[opcode])();
				}
				else
				{
					(*opcode_fd[opcode])();
				}
				break;
		default:
			(*opcode_base[opcode])();
			break;
		}
	}
	return m_cycle;
}


void poke(uint16_t addr, uint8_t value)
{
	if (addr<0x4000)
	{
	}
	else
	{
		memory[addr]=value;
	}
}

uint8_t peek(uint16_t addr)
{
	return memory[addr];
}

void poke16(uint16_t addr, uint16_t value)
{
	poke(addr, value);
	poke(addr+1, value>>8);
}

uint16_t peek16(uint16_t addr)
{
	return ((peek(addr+1)<<8)|peek(addr));
}

uint8_t in(uint16_t port)
{
	uint8_t input;
	if ((port&0x00FF)==0xFE)//port 0xFE
	{
		//GPIOC->ODR&=0x00FF;
		//GPIOC->ODR|=port&0xFF00;

		for (pa=0; pa<20; pa++)
		{
			o++;
		}
		//input=(GPIOA->IDR&0x1F);

		//if ((ADC1->DR)>4)
		//{
			//input|=0x40;
		//}
			return (input);
	}
	else
	{
		return (0xff);
	}

}

void out(uint16_t port, uint8_t value)
{
	if ((port&0xFF)==0x00FE)//port 0xFE
	{
		//border=color [value&0x07];//D[0-2]цвет бордюра

		if (value&0x08)//PC1 выход на магнитофон
		{
			//GPIOC->BSRRL=GPIO_BSRR_BS_1;
		}
		else
		{
			//GPIOC->BSRRH=GPIO_BSRR_BS_1;
		}

		if (value&0x10)//PC0 выход на динамик
		{
			//GPIOC->BSRRL=GPIO_BSRR_BS_0;
		}
		else
		{
			//GPIOC->BSRRH=GPIO_BSRR_BS_0;
		}
	}
}
